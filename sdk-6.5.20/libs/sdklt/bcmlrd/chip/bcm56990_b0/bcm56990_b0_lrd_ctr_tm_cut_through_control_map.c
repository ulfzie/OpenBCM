/*******************************************************************************
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated by fltg from
 *    INTERNAL/fltg/xgs/ctr/bcm56990_b0/bcm56990_b0_CTR_TM_CUT_THROUGH_CONTROL.map.ltl for
 *      bcm56990_b0
 *
 * Tool: $SDK/INTERNAL/fltg/bin/fltg
 *
 * Edits to this file will be lost when it is regenerated.
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 */
#include <bcmlrd/bcmlrd_internal.h>
#include <bcmlrd/chip/bcmlrd_id.h>
#include <bcmlrd/chip/bcm56990_b0/bcm56990_b0_lrd_field_data.h>
#include <bcmlrd/chip/bcm56990_b0/bcm56990_b0_lrd_ltm_intf.h>
#include <bcmlrd/chip/bcm56990_b0/bcm56990_b0_lrd_xfrm_field_desc.h>
#include <bcmdrd/chip/bcm56990_b0_enum.h>
#include "bcmltd/chip/bcmltd_common_enumpool.h"
#include "bcm56990_b0_lrd_enumpool.h"
#include <bcmltd/bcmltd_handler.h>
/* CTR_TM_CUT_THROUGH_CONTROL field init */
static const bcmlrd_field_data_t bcm56990_b0_lrd_ctr_tm_cut_through_control_map_field_data_mmd[] = {
    { /* 0 CTR_TM_CUT_THROUGH_ID */
      .flags = BCMLTD_FIELD_F_KEY,
      .min = &bcm56990_b0_lrd_ifd_u16_0x0,
      .def = &bcm56990_b0_lrd_ifd_u16_0x0,
      .max = &bcm56990_b0_lrd_ifd_u16_0x7,
      .depth = 0,
      .width = 3,
      .edata = NULL,
    },
    { /* 1 BUFFER_POOL */
      .flags = BCMLTD_FIELD_F_KEY,
      .min = &bcm56990_b0_lrd_ifd_u8_0x0,
      .def = &bcm56990_b0_lrd_ifd_u8_0x0,
      .max = &bcm56990_b0_lrd_ifd_u8_0x1,
      .depth = 0,
      .width = 1,
      .edata = NULL,
    },
    { /* 2 ING_PORT_ID_MATCH */
      .flags = 0,
      .min = &bcm56990_b0_lrd_ifd_is_true_0x0,
      .def = &bcm56990_b0_lrd_ifd_is_true_0x0,
      .max = &bcm56990_b0_lrd_ifd_is_true_0x1,
      .depth = 0,
      .width = 1,
      .edata = NULL,
    },
    { /* 3 ING_TM_PIPE_ID_MATCH */
      .flags = 0,
      .min = &bcm56990_b0_lrd_ifd_is_true_0x0,
      .def = &bcm56990_b0_lrd_ifd_is_true_0x0,
      .max = &bcm56990_b0_lrd_ifd_is_true_0x1,
      .depth = 0,
      .width = 1,
      .edata = NULL,
    },
    { /* 4 ING_PORT_ID */
      .flags = 0,
      .min = &bcm56990_b0_lrd_ifd_u16_0x1,
      .def = &bcm56990_b0_lrd_ifd_u16_0x1,
      .max = &bcm56990_b0_lrd_ifd_u16_0x10e,
      .depth = 0,
      .width = 9,
      .edata = NULL,
    },
    { /* 5 EGR_PORT_ID_MATCH */
      .flags = 0,
      .min = &bcm56990_b0_lrd_ifd_is_true_0x0,
      .def = &bcm56990_b0_lrd_ifd_is_true_0x0,
      .max = &bcm56990_b0_lrd_ifd_is_true_0x1,
      .depth = 0,
      .width = 1,
      .edata = NULL,
    },
    { /* 6 EGR_TM_PIPE_ID_MATCH */
      .flags = 0,
      .min = &bcm56990_b0_lrd_ifd_is_true_0x0,
      .def = &bcm56990_b0_lrd_ifd_is_true_0x0,
      .max = &bcm56990_b0_lrd_ifd_is_true_0x1,
      .depth = 0,
      .width = 1,
      .edata = NULL,
    },
    { /* 7 EGR_PORT_ID */
      .flags = 0,
      .min = &bcm56990_b0_lrd_ifd_u16_0x1,
      .def = &bcm56990_b0_lrd_ifd_u16_0x1,
      .max = &bcm56990_b0_lrd_ifd_u16_0x10e,
      .depth = 0,
      .width = 9,
      .edata = NULL,
    },
    { /* 8 TM_Q_ID_MATCH */
      .flags = 0,
      .min = &bcm56990_b0_lrd_ifd_is_true_0x0,
      .def = &bcm56990_b0_lrd_ifd_is_true_0x0,
      .max = &bcm56990_b0_lrd_ifd_is_true_0x1,
      .depth = 0,
      .width = 1,
      .edata = NULL,
    },
    { /* 9 Q_TYPE */
      .flags = BCMLTD_FIELD_F_ENUM,
      .min = &bcm56990_b0_lrd_ifd_u32_0x0,
      .def = &bcm56990_b0_lrd_ifd_u32_0x1,
      .max = &bcm56990_b0_lrd_ifd_u32_0x1,
      .depth = 0,
      .width = 1,
      .edata = BCMLTD_COMMON_CTR_TM_QUEUE_TYPE_T_DATA,
    },
    { /* 10 TM_UC_Q_ID */
      .flags = 0,
      .min = &bcm56990_b0_lrd_ifd_u8_0x0,
      .def = &bcm56990_b0_lrd_ifd_u8_0x0,
      .max = &bcm56990_b0_lrd_ifd_u8_0xb,
      .depth = 0,
      .width = 4,
      .edata = NULL,
    },
    { /* 11 TM_MC_Q_ID */
      .flags = 0,
      .min = &bcm56990_b0_lrd_ifd_u8_0x0,
      .def = &bcm56990_b0_lrd_ifd_u8_0x0,
      .max = &bcm56990_b0_lrd_ifd_u8_0x5,
      .depth = 0,
      .width = 3,
      .edata = NULL,
    },
    { /* 12 PRI_GRP_ID_MATCH */
      .flags = 0,
      .min = &bcm56990_b0_lrd_ifd_is_true_0x0,
      .def = &bcm56990_b0_lrd_ifd_is_true_0x0,
      .max = &bcm56990_b0_lrd_ifd_is_true_0x1,
      .depth = 0,
      .width = 1,
      .edata = NULL,
    },
    { /* 13 TM_PRI_GRP_ID */
      .flags = 0,
      .min = &bcm56990_b0_lrd_ifd_u8_0x0,
      .def = &bcm56990_b0_lrd_ifd_u8_0x0,
      .max = &bcm56990_b0_lrd_ifd_u8_0x7,
      .depth = 0,
      .width = 3,
      .edata = NULL,
    },
};
const bcmlrd_map_field_data_t bcm56990_b0_lrd_ctr_tm_cut_through_control_map_field_data = {
    .fields = 14,
    .field = bcm56990_b0_lrd_ctr_tm_cut_through_control_map_field_data_mmd
};

static const bcmlrd_map_table_attr_t bcm56990_b0_lrd_ctr_tm_cut_through_controlt_attr_entry[] = {
    { /* 0 */
        .key   = BCMLRD_MAP_TABLE_ATTRIBUTE_INSTANCE_MAX_INDEX,
        .value = 1,
    },
    { /* 1 */
        .key   = BCMLRD_MAP_TABLE_ATTRIBUTE_INSTANCE_MIN_INDEX,
        .value = 0,
    },
    { /* 2 */
        .key   = BCMLRD_MAP_TABLE_ATTRIBUTE_INTERACTIVE,
        .value = FALSE,
    },
    { /* 3 */
        .key   = BCMLRD_MAP_TABLE_ATTRIBUTE_TABLE_MAX_INDEX,
        .value = 15,
    },
    { /* 4 */
        .key   = BCMLRD_MAP_TABLE_ATTRIBUTE_TABLE_MIN_INDEX,
        .value = 0,
    },
    { /* 5 */
        .key   = BCMLRD_MAP_TABLE_ATTRIBUTE_TRACK_INDEX_MAX_INDEX,
        .value = 271,
    },
    { /* 6 */
        .key   = BCMLRD_MAP_TABLE_ATTRIBUTE_TRACK_INDEX_MIN_INDEX,
        .value = 0,
    },
};

static const bcmlrd_map_attr_t bcm56990_b0_lrd_ctr_tm_cut_through_controlt_attr_group = {
    .attributes = 7,
    .attr = bcm56990_b0_lrd_ctr_tm_cut_through_controlt_attr_entry,
};


const bcmltd_field_desc_t
bcm56990_b0_lrd_bcmltx_mmu_ing_local_port_pipe_idx_src_field_desc_s0[1] = {
    {
        .field_id  = CTR_TM_CUT_THROUGH_CONTROLt_ING_PORT_IDf,
        .field_idx = 0,
        .minbit    = 0,
        .maxbit    = 15,
        .entry_idx = 0,
        .reserved  = 0
    },
};

const bcmltd_field_desc_t
bcm56990_b0_lrd_bcmltx_mmu_ing_local_port_pipe_idx_ctr_tm_cut_through_control_dst_field_desc_d0[2] = {
    {
        .field_id  = SRC_PORT_NUMf,
        .field_idx = 0,
        .minbit    = 0,
        .maxbit    = 4,
        .entry_idx = 0,
        .reserved  = 0,
    },
    {
        .field_id  = SRC_PIPE_NUMf,
        .field_idx = 0,
        .minbit    = 12,
        .maxbit    = 15,
        .entry_idx = 0,
        .reserved  = 0,
    },
};

const bcmltd_field_desc_t
bcm56990_b0_lrd_bcmltx_mmu_local_port_pipe_q_idx_src_field_desc_s0[4] = {
    {
        .field_id  = CTR_TM_CUT_THROUGH_CONTROLt_EGR_PORT_IDf,
        .field_idx = 0,
        .minbit    = 0,
        .maxbit    = 15,
        .entry_idx = 0,
        .reserved  = 0
    },
    {
        .field_id  = CTR_TM_CUT_THROUGH_CONTROLt_Q_TYPEf,
        .field_idx = 0,
        .minbit    = 0,
        .maxbit    = 31,
        .entry_idx = 0,
        .reserved  = 0
    },
    {
        .field_id  = CTR_TM_CUT_THROUGH_CONTROLt_TM_UC_Q_IDf,
        .field_idx = 0,
        .minbit    = 0,
        .maxbit    = 7,
        .entry_idx = 0,
        .reserved  = 0
    },
    {
        .field_id  = CTR_TM_CUT_THROUGH_CONTROLt_TM_MC_Q_IDf,
        .field_idx = 0,
        .minbit    = 0,
        .maxbit    = 7,
        .entry_idx = 0,
        .reserved  = 0
    },
};

const bcmltd_field_desc_t
bcm56990_b0_lrd_bcmltx_mmu_local_port_pipe_q_idx_ctr_tm_cut_through_control_dst_field_desc_d0[3] = {
    {
        .field_id  = DST_PORT_NUMf,
        .field_idx = 0,
        .minbit    = 6,
        .maxbit    = 10,
        .entry_idx = 0,
        .reserved  = 0,
    },
    {
        .field_id  = DST_PIPE_NUMf,
        .field_idx = 0,
        .minbit    = 17,
        .maxbit    = 20,
        .entry_idx = 0,
        .reserved  = 0,
    },
    {
        .field_id  = MMU_Q_NUMf,
        .field_idx = 0,
        .minbit    = 22,
        .maxbit    = 25,
        .entry_idx = 0,
        .reserved  = 0,
    },
};

const bcmlrd_field_xfrm_desc_t
bcm56990_b0_lta_bcmltx_mmu_ing_local_port_pipe_idx_xfrm_handler_fwd_s0_d0_x0_desc = {
    .handler_id = BCMLTD_TRANSFORM_BCM56990_B0_LTA_BCMLTX_MMU_ING_LOCAL_PORT_PIPE_IDX_XFRM_HANDLER_FWD_S0_D0_X0_ID,
    .src_fields = 1,
    .src = bcm56990_b0_lrd_bcmltx_mmu_ing_local_port_pipe_idx_src_field_desc_s0,
    .dst_fields = 2,
    .dst = bcm56990_b0_lrd_bcmltx_mmu_ing_local_port_pipe_idx_ctr_tm_cut_through_control_dst_field_desc_d0,
};

const bcmlrd_field_xfrm_desc_t
bcm56990_b0_lta_bcmltx_mmu_ing_local_port_pipe_idx_xfrm_handler_rev_s0_d0_x0_desc = {
    .handler_id = BCMLTD_TRANSFORM_BCM56990_B0_LTA_BCMLTX_MMU_ING_LOCAL_PORT_PIPE_IDX_XFRM_HANDLER_REV_S0_D0_X0_ID,
    .src_fields = 2,
    .src = bcm56990_b0_lrd_bcmltx_mmu_ing_local_port_pipe_idx_ctr_tm_cut_through_control_dst_field_desc_d0,
    .dst_fields = 1,
    .dst = bcm56990_b0_lrd_bcmltx_mmu_ing_local_port_pipe_idx_src_field_desc_s0,
};

const bcmlrd_field_xfrm_desc_t
bcm56990_b0_lta_bcmltx_mmu_local_port_pipe_q_idx_xfrm_handler_fwd_s0_d0_x0_desc = {
    .handler_id = BCMLTD_TRANSFORM_BCM56990_B0_LTA_BCMLTX_MMU_LOCAL_PORT_PIPE_Q_IDX_XFRM_HANDLER_FWD_S0_D0_X0_ID,
    .src_fields = 4,
    .src = bcm56990_b0_lrd_bcmltx_mmu_local_port_pipe_q_idx_src_field_desc_s0,
    .dst_fields = 3,
    .dst = bcm56990_b0_lrd_bcmltx_mmu_local_port_pipe_q_idx_ctr_tm_cut_through_control_dst_field_desc_d0,
};

const bcmlrd_field_xfrm_desc_t
bcm56990_b0_lta_bcmltx_mmu_local_port_pipe_q_idx_xfrm_handler_rev_s0_d0_x0_desc = {
    .handler_id = BCMLTD_TRANSFORM_BCM56990_B0_LTA_BCMLTX_MMU_LOCAL_PORT_PIPE_Q_IDX_XFRM_HANDLER_REV_S0_D0_X0_ID,
    .src_fields = 3,
    .src = bcm56990_b0_lrd_bcmltx_mmu_local_port_pipe_q_idx_ctr_tm_cut_through_control_dst_field_desc_d0,
    .dst_fields = 4,
    .dst = bcm56990_b0_lrd_bcmltx_mmu_local_port_pipe_q_idx_src_field_desc_s0,
};


static const bcmlrd_map_entry_t bcm56990_b0_lrd_ctr_tm_cut_through_controlt_mmu_crb_debug_cnt_config_map_entry[] = {
    { /* 0 */
        .entry_type = BCMLRD_MAP_ENTRY_MAPPED_KEY,
        .desc = {
            .field_id  = BCMLRD_FIELD_INSTANCE,
            .field_idx = 0,
            .minbit    = 0,
            .maxbit    = 0,
            .entry_idx = 0,
            .reserved  = 0
        },
        .u = {
            .mapped = {
                .src = {
                    .field_id = CTR_TM_CUT_THROUGH_CONTROLt_BUFFER_POOLf,
                    .field_idx = 0,
                    .minbit    = 0,
                    .maxbit    = 0,
                    .entry_idx = 0,
                    .reserved  = 0
                }
            }
        },
    },
    { /* 1 */
        .entry_type = BCMLRD_MAP_ENTRY_MAPPED_KEY,
        .desc = {
            .field_id  = BCMLRD_FIELD_INDEX,
            .field_idx = 0,
            .minbit    = 0,
            .maxbit    = 2,
            .entry_idx = 0,
            .reserved  = 0
        },
        .u = {
            .mapped = {
                .src = {
                    .field_id = CTR_TM_CUT_THROUGH_CONTROLt_CTR_TM_CUT_THROUGH_IDf,
                    .field_idx = 0,
                    .minbit    = 0,
                    .maxbit    = 2,
                    .entry_idx = 0,
                    .reserved  = 0
                }
            }
        },
    },
    { /* 2 */
        .entry_type = BCMLRD_MAP_ENTRY_MAPPED_VALUE,
        .desc = {
            .field_id  = SRC_PORT_NUM_MATCH_ENf,
            .field_idx = 0,
            .minbit    = 5,
            .maxbit    = 5,
            .entry_idx = 0,
            .reserved  = 0
        },
        .u = {
            .mapped = {
                .src = {
                    .field_id = CTR_TM_CUT_THROUGH_CONTROLt_ING_PORT_ID_MATCHf,
                    .field_idx = 0,
                    .minbit    = 0,
                    .maxbit    = 0,
                    .entry_idx = 0,
                    .reserved  = 0
                }
            }
        },
    },
    { /* 3 */
        .entry_type = BCMLRD_MAP_ENTRY_MAPPED_VALUE,
        .desc = {
            .field_id  = SRC_PIPE_NUM_MATCH_ENf,
            .field_idx = 0,
            .minbit    = 16,
            .maxbit    = 16,
            .entry_idx = 0,
            .reserved  = 0
        },
        .u = {
            .mapped = {
                .src = {
                    .field_id = CTR_TM_CUT_THROUGH_CONTROLt_ING_TM_PIPE_ID_MATCHf,
                    .field_idx = 0,
                    .minbit    = 0,
                    .maxbit    = 0,
                    .entry_idx = 0,
                    .reserved  = 0
                }
            }
        },
    },
    { /* 4 */
        .entry_type = BCMLRD_MAP_ENTRY_MAPPED_VALUE,
        .desc = {
            .field_id  = DST_PORT_NUM_MATCH_ENf,
            .field_idx = 0,
            .minbit    = 11,
            .maxbit    = 11,
            .entry_idx = 0,
            .reserved  = 0
        },
        .u = {
            .mapped = {
                .src = {
                    .field_id = CTR_TM_CUT_THROUGH_CONTROLt_EGR_PORT_ID_MATCHf,
                    .field_idx = 0,
                    .minbit    = 0,
                    .maxbit    = 0,
                    .entry_idx = 0,
                    .reserved  = 0
                }
            }
        },
    },
    { /* 5 */
        .entry_type = BCMLRD_MAP_ENTRY_MAPPED_VALUE,
        .desc = {
            .field_id  = DST_PIPE_NUM_MATCH_ENf,
            .field_idx = 0,
            .minbit    = 21,
            .maxbit    = 21,
            .entry_idx = 0,
            .reserved  = 0
        },
        .u = {
            .mapped = {
                .src = {
                    .field_id = CTR_TM_CUT_THROUGH_CONTROLt_EGR_TM_PIPE_ID_MATCHf,
                    .field_idx = 0,
                    .minbit    = 0,
                    .maxbit    = 0,
                    .entry_idx = 0,
                    .reserved  = 0
                }
            }
        },
    },
    { /* 6 */
        .entry_type = BCMLRD_MAP_ENTRY_MAPPED_VALUE,
        .desc = {
            .field_id  = MMU_Q_NUM_MATCH_ENf,
            .field_idx = 0,
            .minbit    = 26,
            .maxbit    = 26,
            .entry_idx = 0,
            .reserved  = 0
        },
        .u = {
            .mapped = {
                .src = {
                    .field_id = CTR_TM_CUT_THROUGH_CONTROLt_TM_Q_ID_MATCHf,
                    .field_idx = 0,
                    .minbit    = 0,
                    .maxbit    = 0,
                    .entry_idx = 0,
                    .reserved  = 0
                }
            }
        },
    },
    { /* 7 */
        .entry_type = BCMLRD_MAP_ENTRY_MAPPED_VALUE,
        .desc = {
            .field_id  = PRIORITY_GROUP_MATCH_ENf,
            .field_idx = 0,
            .minbit    = 30,
            .maxbit    = 30,
            .entry_idx = 0,
            .reserved  = 0
        },
        .u = {
            .mapped = {
                .src = {
                    .field_id = CTR_TM_CUT_THROUGH_CONTROLt_PRI_GRP_ID_MATCHf,
                    .field_idx = 0,
                    .minbit    = 0,
                    .maxbit    = 0,
                    .entry_idx = 0,
                    .reserved  = 0
                }
            }
        },
    },
    { /* 8 */
        .entry_type = BCMLRD_MAP_ENTRY_MAPPED_VALUE,
        .desc = {
            .field_id  = PRIORITY_GROUPf,
            .field_idx = 0,
            .minbit    = 27,
            .maxbit    = 29,
            .entry_idx = 0,
            .reserved  = 0
        },
        .u = {
            .mapped = {
                .src = {
                    .field_id = CTR_TM_CUT_THROUGH_CONTROLt_TM_PRI_GRP_IDf,
                    .field_idx = 0,
                    .minbit    = 0,
                    .maxbit    = 2,
                    .entry_idx = 0,
                    .reserved  = 0
                }
            }
        },
    },
    { /* 9 */
        .entry_type = BCMLRD_MAP_ENTRY_FWD_VALUE_FIELD_XFRM_HANDLER,
        .desc = {
            .field_id  = 0,
            .field_idx = 0,
            .minbit    = 0,
            .maxbit    = 0,
            .entry_idx = 0,
            .reserved  = 0
        },
        .u = {
            .xfrm = {
                /* handler: bcm56990_b0_lta_bcmltx_mmu_ing_local_port_pipe_idx_xfrm_handler_fwd_s0_d0_x0 */
                .desc = &bcm56990_b0_lta_bcmltx_mmu_ing_local_port_pipe_idx_xfrm_handler_fwd_s0_d0_x0_desc,
            },
        },
    },
    { /* 10 */
        .entry_type = BCMLRD_MAP_ENTRY_REV_VALUE_FIELD_XFRM_HANDLER,
        .desc = {
            .field_id  = 0,
            .field_idx = 0,
            .minbit    = 0,
            .maxbit    = 0,
            .entry_idx = 0,
            .reserved  = 0
        },
        .u = {
            .xfrm = {
                /* handler: bcm56990_b0_lta_bcmltx_mmu_ing_local_port_pipe_idx_xfrm_handler_rev_s0_d0_x0 */
                .desc = &bcm56990_b0_lta_bcmltx_mmu_ing_local_port_pipe_idx_xfrm_handler_rev_s0_d0_x0_desc,
            },
        },
    },
    { /* 11 */
        .entry_type = BCMLRD_MAP_ENTRY_FWD_VALUE_FIELD_XFRM_HANDLER,
        .desc = {
            .field_id  = 0,
            .field_idx = 0,
            .minbit    = 0,
            .maxbit    = 0,
            .entry_idx = 0,
            .reserved  = 0
        },
        .u = {
            .xfrm = {
                /* handler: bcm56990_b0_lta_bcmltx_mmu_local_port_pipe_q_idx_xfrm_handler_fwd_s0_d0_x0 */
                .desc = &bcm56990_b0_lta_bcmltx_mmu_local_port_pipe_q_idx_xfrm_handler_fwd_s0_d0_x0_desc,
            },
        },
    },
    { /* 12 */
        .entry_type = BCMLRD_MAP_ENTRY_REV_VALUE_FIELD_XFRM_HANDLER,
        .desc = {
            .field_id  = 0,
            .field_idx = 0,
            .minbit    = 0,
            .maxbit    = 0,
            .entry_idx = 0,
            .reserved  = 0
        },
        .u = {
            .xfrm = {
                /* handler: bcm56990_b0_lta_bcmltx_mmu_local_port_pipe_q_idx_xfrm_handler_rev_s0_d0_x0 */
                .desc = &bcm56990_b0_lta_bcmltx_mmu_local_port_pipe_q_idx_xfrm_handler_rev_s0_d0_x0_desc,
            },
        },
    },
};
const bcmlrd_field_selector_t bcm56990_b0_lrd_ctr_tm_cut_through_control_map_select[] = {
    { /* Node:0, Type:ROOT, Q_TYPE */
        .selector_type = BCMLRD_FIELD_SELECTOR_TYPE_ROOT,
        .field_id = CTR_TM_CUT_THROUGH_CONTROLt_Q_TYPEf,
        .group_index = BCMLRD_INVALID_SELECTOR_INDEX,
        .entry_index = BCMLRD_INVALID_SELECTOR_INDEX,
        .selection_parent = BCMLRD_INVALID_SELECTOR_INDEX,
        .group = BCMLRD_INVALID_SELECTOR_INDEX,
        .selector_id = BCMLRD_INVALID_SELECTOR_INDEX,
        .selector_value = BCMLRD_INVALID_SELECTOR_INDEX
    },
    { /* Node:1, Type:FIELD, TM_UC_Q_ID */
        .selector_type = BCMLRD_FIELD_SELECTOR_TYPE_FIELD,
        .field_id = CTR_TM_CUT_THROUGH_CONTROLt_TM_UC_Q_IDf,
        .group_index = BCMLRD_INVALID_SELECTOR_INDEX,
        .entry_index = BCMLRD_INVALID_SELECTOR_INDEX,
        .selection_parent = 0,
        .group = 0,
        .selector_id = CTR_TM_CUT_THROUGH_CONTROLt_Q_TYPEf,
        .selector_value = 0 /* UC_Q */
    },
    { /* Node:2, Type:FIELD, TM_MC_Q_ID */
        .selector_type = BCMLRD_FIELD_SELECTOR_TYPE_FIELD,
        .field_id = CTR_TM_CUT_THROUGH_CONTROLt_TM_MC_Q_IDf,
        .group_index = BCMLRD_INVALID_SELECTOR_INDEX,
        .entry_index = BCMLRD_INVALID_SELECTOR_INDEX,
        .selection_parent = 0,
        .group = 0,
        .selector_id = CTR_TM_CUT_THROUGH_CONTROLt_Q_TYPEf,
        .selector_value = 1 /* MC_Q */
    },
};

const bcmlrd_field_selector_data_t bcm56990_b0_lrd_ctr_tm_cut_through_control_map_select_data = {
    .num_field_selector = 3,
    .field_selector = bcm56990_b0_lrd_ctr_tm_cut_through_control_map_select,
};

static const bcmlrd_map_group_t bcm56990_b0_lrd_ctr_tm_cut_through_control_map_group[] = {
    {
        .dest = {
            .kind = BCMLRD_MAP_PHYSICAL,
            .id = MMU_CRB_DEBUG_CNT_CONFIGr,
        },
        .entries = 13,
        .entry = bcm56990_b0_lrd_ctr_tm_cut_through_controlt_mmu_crb_debug_cnt_config_map_entry
    },
};
const bcmlrd_map_t bcm56990_b0_lrd_ctr_tm_cut_through_control_map = {
    .src_id = CTR_TM_CUT_THROUGH_CONTROLt,
    .field_data = &bcm56990_b0_lrd_ctr_tm_cut_through_control_map_field_data,
    .groups = 1,
    .group  = bcm56990_b0_lrd_ctr_tm_cut_through_control_map_group,
    .table_attr = &bcm56990_b0_lrd_ctr_tm_cut_through_controlt_attr_group,
    .entry_ops = BCMLRD_MAP_TABLE_ENTRY_OPERATION_LOOKUP | BCMLRD_MAP_TABLE_ENTRY_OPERATION_TRAVERSE | BCMLRD_MAP_TABLE_ENTRY_OPERATION_INSERT | BCMLRD_MAP_TABLE_ENTRY_OPERATION_UPDATE | BCMLRD_MAP_TABLE_ENTRY_OPERATION_DELETE,
    .sel = &bcm56990_b0_lrd_ctr_tm_cut_through_control_map_select_data,
};