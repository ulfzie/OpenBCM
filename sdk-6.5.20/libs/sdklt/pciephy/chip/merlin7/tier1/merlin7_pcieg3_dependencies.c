/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 * 
 *  This file implements Switch specific Bus access to the PCIE Gen3 PHY.
*/

#include <pciephy/pciephy_acc.h>
#include "common/srds_api_err_code.h"
#include "common/srds_api_types.h"
#include "merlin7_pcieg3_internal.h"
#include "merlin7_pcieg3_common.h"
#include "merlin7_pcieg3_functions.h"
#include "merlin7_pcieg3_dependencies.h"


/** Read a register from the currently selected Serdes IP Lane.
 * @param sa__ is an opaque state vector passed through to device access functions.
 * @param address Address of register to be read
 * @param *val value read out from the register
 * @return Error code generated by read function (returns ERR_CODE_NONE if no errors)
 */
err_code_t merlin7_pcieg3_pmd_rdt_reg(srds_access_t *sa__, uint16_t address, uint16_t *val)
{
    uint32_t phyaddr;
    uint32_t lane = (uint32_t)(merlin7_pcieg3_get_lane(sa__));

    if (!SRDS_BUS_VALIDATE(sa__)) {
        return ERR_CODE_BAD_PTR_OR_INVALID_INPUT;
    }

    phyaddr = address | 1 << 27;
    phyaddr |= (lane & 0x1F) << 16;
    SRDS_BUS_READ(sa__, phyaddr, val);

    return ERR_CODE_NONE;
}

/** Write to a register from the currently selected Serdes IP Lane.
 * @param sa__ is an opaque state vector passed through to device access functions.
 * @param address Address of register to be written
 * @param val Value to be written to the register
 * @return Error code generated by write function (returns ERR_CODE_NONE if no errors)
 */
err_code_t merlin7_pcieg3_pmd_wr_reg(srds_access_t *sa__, uint16_t address, uint16_t val)
{
    uint32_t phyaddr;
    uint32_t lane = (uint32_t)(merlin7_pcieg3_get_lane(sa__));

    if (!SRDS_BUS_VALIDATE(sa__)) {
        return ERR_CODE_BAD_PTR_OR_INVALID_INPUT;
    }

    phyaddr = address | 1 << 27;
    phyaddr |= ((lane & 0x1F) << 16);
    SRDS_BUS_WRITE(sa__, phyaddr, val);

    return ERR_CODE_NONE;
}

/** Masked Register Write to the currently selected Serdes IP core/lane.
 * If using Serdes MDIO controller to access the registers, implement this function using merlin7_pcieg3_pmd_mdio_mwr_reg(..)
 *
 * If NOT using a Serdes MDIO controller or the Serdes PMI Masked write feature, please use the following code to
 * implement this function
 *
 *    merlin7_pcieg3_pmd_wr_reg(addr, ((merlin7_pmd_rd_reg(addr) & ~mask) | (mask & (val << lsb))));
 *
 * @param sa__ is an opaque state vector passed through to device access functions.
 * @param addr Address of register to be written
 * @param mask 16-bit mask indicating the position of the field with bits of 1s
 * @param lsb  LSB of the field
 * @param val  16bit value to be written
 * @return Error code generated by write function (returns ERR_CODE_NONE if no errors)
 */
err_code_t merlin7_pcieg3_pmd_mwr_reg(srds_access_t *sa__, uint16_t addr, uint16_t mask, uint8_t lsb, uint16_t val)
{
    err_code_t error_code;
    uint16_t data;    

    error_code = merlin7_pcieg3_pmd_rdt_reg(sa__, addr, &data);
    if(error_code != ERR_CODE_NONE) 
       return error_code;

    data = (data & ~mask) | (mask & (val << lsb));

    error_code = merlin7_pcieg3_pmd_wr_reg(sa__, addr, data);    

    return error_code; 
}

/** Write to a PRAM location for the currently selected Serdes IP Core.
 *  The address is auto-incrementing, per the PRAM interface specification.
 * @param sa__ is an opaque state vector passed through to device access functions.
 * @param val Value to be written
 * @return Error code generated by write function (returns ERR_CODE_NONE if no errors)
 */
err_code_t merlin7_pcieg3_pmd_wr_pram(srds_access_t *sa__, uint8_t val)
{
    return ERR_CODE_NONE;
}

/** Delay the execution of the code for atleast specified amount of time in nanoseconds.
 * This function is used ONLY for delays less than 1 microsecond, non-zero error code may be returned otherwise.
 * The user can implement this as an empty function if their register access latency exceeds 1 microsecond.
 * @param delay_ns Delay in nanoseconds
 * @return Error code generated by delay function (returns ERR_CODE_NONE if no errors)
 */
err_code_t merlin7_pcieg3_delay_ns(srds_access_t *sa__, uint16_t delay_ns)
{
    uint32_t delay;
    delay = delay_ns / 1000; 
    if(!delay) {
        delay = 1;
    }
    PCIEPHY_UDELAY(delay);
    return 0;
}

/** Delay the execution of the code for atleast specified amount of time in microseconds.
 * For longer delays, accuracy is required. When requested delay is > 100ms, the implemented delay is assumed
 * to be < 10% bigger than requested.
 * This function is used ONLY for delays greater than or equal to 1 microsecond.
 * @param delay_us Delay in microseconds
 * @return Error code generated by delay function (returns ERR_CODE_NONE if no errors)
 */
err_code_t merlin7_pcieg3_delay_us(srds_access_t *sa__, uint32_t delay_us)
{
    PCIEPHY_UDELAY(delay_us);
    return 0;
}

/** Delay the execution of the code for atleast specified amount of time in milliseconds.
 * For longer delays, accuracy is required. When requested delay is > 100ms, the implemented delay is assumed
 * to be < 10% bigger than requested.
 * This function is used ONLY for delays greater than or equal to 1 millisecond.
 * @param delay_ms Delay in milliseconds
 * @return Error code generated by delay function (returns ERR_CODE_NONE if no errors)
 */
err_code_t merlin7_pcieg3_delay_ms(srds_access_t *sa__, uint32_t delay_ms)
{
    PCIEPHY_UDELAY(delay_ms * 1000);
    return 0;
}

/** Return the address of current selected Serdes IP Core.
 * @param sa__ is an opaque state vector passed through to device access functions.
 * @return the IP level address of the current core.
 */
uint8_t merlin7_pcieg3_get_core(srds_access_t *sa__)
{
    return 0;
}

/** Return the address of current selected Serdes IP lane.
 * @param sa__ is an opaque state vector passed through to device access functions.
 * @return the IP level address of the current lane. 0 to N-1, for an N lane IP
 */
uint8_t merlin7_pcieg3_get_lane(srds_access_t *sa__)
{
    uint8_t lane_index;

    if(sa__->lane_mask == 0x1) {
        lane_index = 0;
    } else if(sa__->lane_mask == 0x2) {
        lane_index = 1;
    } else if(sa__->lane_mask == 0x4) {
        lane_index = 2;
    } else if(sa__->lane_mask == 0x8) {
        lane_index = 3;
    } else {
        lane_index = 0;
    }
    return (sa__->core + lane_index);
}

/** Set the address of current selected Serdes IP lane.  Used in diagnostic
 * and core-level management functions.
 * @param sa__ is an opaque state vector passed through to device access functions.
 * @param lane_index is the lane index
 * @return Any error code generated during execution; ERR_CODE NONE otherwise.
 */
err_code_t merlin7_pcieg3_set_lane(srds_access_t *sa__, uint8_t lane_index)
{
    
    sa__->core = (lane_index/4); /* Four lanes per core */
    sa__->lane_mask = (1 << (lane_index % 4));

    return ERR_CODE_NONE;
}

/** Return the address of current selected Serdes IP PLL.
 * @param sa__ is an opaque state vector passed through to device access functions.
 * @return the IP level address of the current PLL. 0 to N-1, for an N-PLL IP
 */
uint8_t merlin7_pcieg3_get_pll_idx(srds_access_t *sa__)
{
    return 0;
}

/** Set the address of current selected Serdes IP PLL. Its purpose is to select which
 * PLL's registers is accessed when accessing AMS_PLL_COM, CORE_PLL_COM, & PLL_CAL_COM.
 * This is a selection similar to selecting lane registers.
 * Used in diagnostic and core-level management functions. 
 * @param sa__ is an opaque state vector passed through to device access functions.
 * @param pll_index is the PLL index
 * @return Any error code generated during execution; ERR_CODE NONE otherwise.
 */
err_code_t merlin7_pcieg3_set_pll_idx(srds_access_t *sa__, uint8_t pll_index)
{
    return ERR_CODE_NONE;
}

/** Return the index of current selected Serdes IP micro.
 * NOTE: The micro_idx is selected using same bits as PLL selection in AER or PMI address.
 * @param sa__ is an opaque state vector passed through to device access functions.
 * @return the IP level index of the current micro. 0 to N-1, for an N-micro IP
 */
uint8_t merlin7_pcieg3_get_micro_idx(srds_access_t *sa__)
{
    return 0;
}

/** Set the index of current selected Serdes IP micro. Its purpose is to select which
 * micro's registers is accessed when accessing MICRO_E_COM.This is a selection similar to
 * selecting lane registers.
 * Used in diagnostic and core-level management functions.
 * NOTE: The micro_idx is selected using same bits as PLL selection in AER or PMI address.
 * @param sa__ is an opaque state vector passed through to device access functions.
 * @param micro_index is the micro index
 * @return Any error code generated during execution; ERR_CODE NONE otherwise.
 */
err_code_t merlin7_pcieg3_set_micro_idx(srds_access_t *sa__, uint8_t micro_index)
{
    return ERR_CODE_NONE;
}

#if defined(SERDES_EXTERNAL_INFO_TABLE_EN)
/** Returns address of merlin7_pcieg3 info table stored in upper level software.
 * @param sa__ is an opaque state vector passed through to device access functions.
 */
srds_info_t *merlin7_pcieg3_get_info_table_address(srds_access_t *sa__)
{
    return NULL;
}
#endif