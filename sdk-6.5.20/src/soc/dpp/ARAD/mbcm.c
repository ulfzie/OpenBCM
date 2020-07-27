/*
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 *
 * File:        mbcm.c
 */

#include <soc/dpp/mbcm.h>
#include <soc/dpp/port_sw_db.h>
#include <soc/dpp/ARAD/arad_drv.h>
#include <soc/dpp/ARAD/arad_api_action_cmd.h>
#include <soc/dpp/ARAD/arad_ingress_traffic_mgmt.h>
#include <soc/dpp/ARAD/arad_api_ingress_packet_queuing.h>
#include <soc/dpp/ARAD/arad_api_end2end_scheduler.h>
#include <soc/dpp/ARAD/arad_api_mgmt.h>
#include <soc/dpp/ARAD/arad_api_ports.h>
#include <soc/dpp/ARAD/arad_ports.h>
#include <soc/dpp/ARAD/arad_api_multicast_fabric.h>
#include <soc/dpp/ARAD/arad_multicast_fabric.h>
#include <soc/dpp/ARAD/arad_tdm.h>
#include <soc/dpp/multicast_imp.h>
#include <soc/dpp/ARAD/arad_multicast_imp.h>
#include <soc/dpp/ARAD/arad_api_fabric.h>
#include <soc/dpp/ARAD/arad_api_ofp_rates.h>
#include <soc/dpp/ARAD/arad_ofp_rates.h>
#include <soc/dpp/ARAD/arad_flow_control.h>
#include <soc/dpp/ARAD/arad_api_cnt.h>
#include <soc/dpp/ARAD/arad_api_diagnostics.h>
#include <soc/dpp/ARAD/arad_api_ingress_scheduler.h>
#include <soc/dpp/ARAD/arad_ingress_scheduler.h>
#include <soc/dpp/ARAD/arad_mgmt.h>
#include <soc/dpp/ARAD/arad_init.h>
#include <soc/dpp/ARAD/arad_fabric.h>
#include <soc/dpp/ARAD/arad_interrupts.h>
#include <soc/dpp/ARAD/arad_cnt.h>
#include <soc/dpp/ARAD/arad_dram.h>
#include <soc/dpp/ARAD/arad_scheduler_device.h>
#include <soc/dpp/ARAD/arad_scheduler_ports.h>
#include <soc/dpp/ARAD/arad_tbl_access.h>
#include <soc/dpp/ARAD/arad_egr_queuing.h>
#include <soc/dpp/ARAD/arad_parser.h>
#include <soc/dpp/PORT/arad_ps_db.h>
#include <soc/dpp/ARAD/arad_egr_prog_editor.h>
#include <soc/dpp/ARAD/arad_cell.h>
#include <soc/dpp/ARAD/NIF/ports_manager.h>
#include <soc/dpp/ARAD/NIF/common_drv.h>
#include <soc/dpp/multicast_imp.h>
#include <soc/dpp/ARAD/ARAD_PP/arad_pp_metering.h>
#include <soc/dpp/ARAD/arad_init.h>



CONST mbcm_dpp_functions_t mbcm_arad_driver = {
    arad_action_cmd_snoop_set,
    arad_action_cmd_snoop_get, 
    arad_action_cmd_mirror_set, 
    arad_action_cmd_mirror_get, 
    soc_arad_ports_stop_egq,   
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    arad_cnt_counters_set,
    arad_cnt_channel_to_fifo_mapping_set,
    arad_cnt_channel_to_fifo_mapping_get,
    arad_cnt_dma_unset,
    arad_cnt_dma_set,
    arad_cnt_counters_get,
    arad_cnt_status_get,
    arad_cnt_engine_to_fifo_dma_index,
    arad_cnt_fifo_dma_offset_in_engine,
    arad_cnt_max_we_val_get,
    arad_cnt_algorithmic_read,
    arad_cnt_direct_read,
    arad_cnt_q2cnt_id,
    NULL, 
    arad_cnt_lif_counting_set,
    arad_cnt_lif_counting_get,
    arad_cnt_lif_counting_range_set,
    arad_cnt_lif_counting_range_get,
    NULL, 
    NULL, 
    arad_cnt_epni_statistics_enable,
    arad_cnt_epni_regs_set_unsafe,
    arad_cnt_meter_hdr_compensation_set,
    arad_cnt_meter_hdr_compensation_get,
    arad_diag_last_packet_info_get,  
    NULL,  
    NULL,  
    NULL,  
    arad_egr_q_prio_set,
    arad_egr_q_prio_get,
    arad_egr_q_profile_map_set,
    arad_egr_q_profile_map_get,
    arad_egr_q_cgm_interface_set,
    arad_egr_q_fqp_scheduler_config,
    soc_arad_egr_congestion_statistics_get,
    NULL,  
    NULL,  
    NULL, 
    NULL, 
    arad_port_fabric_clk_freq_init,
    soc_arad_pll_info_get,
    NULL, 
    NULL,  
    NULL,   
    arad_mgmt_ipt_init,
    soc_arad_fabric_stat_init,
    soc_arad_stat_nif_init,
    soc_arad_stat_path_info_get,
    arad_info_config_custom_reg_access,
    soc_arad_mapping_stat_get,
    soc_arad_stat_counter_length_get,
    soc_arad_stat_controlled_counter_enable_get,
    arad_itm_committed_q_size_set,
    arad_itm_committed_q_size_get,
    NULL,     
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    arad_port_pp_port_set, 
    arad_port_pp_port_get,
    arad_port_to_pp_port_map_set, 
    NULL, 
    arad_port_control_low_latency_set,
    arad_port_control_fec_error_detect_set,
    arad_port_control_low_latency_get,
    arad_port_control_fec_error_detect_get, 
    NULL, 
    NULL, 
    NULL,  
    NULL, 
    NULL, 
    NULL, 
    NULL,    
    arad_ports_logical_sys_id_build,
    arad_sys_virtual_port_to_local_port_map_set_unsafe,
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL, 
    arad_tdm_ftmh_set,
    arad_tdm_ftmh_get,
    arad_tdm_opt_size_set,
    arad_tdm_opt_size_get,
    arad_tdm_stand_size_range_set,
    arad_tdm_stand_size_range_get,
    NULL,  
    NULL,  
    arad_tdm_port_packet_crc_set,
    arad_tdm_port_packet_crc_get,
    arad_tdm_direct_routing_set,
    arad_tdm_direct_routing_get,
    arad_tdm_direct_routing_profile_map_set,
    arad_tdm_direct_routing_profile_map_get,
    arad_tdm_ifp_get,
    arad_tdm_ifp_set,
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL, 
    arad_egr_threshold_types_verify, 
    arad_egr_ofp_thresh_type_set,
    arad_egr_ofp_thresh_type_get,
    arad_egr_sched_drop_set,
    arad_egr_sched_drop_get,
    arad_egr_unsched_drop_set,
    arad_egr_unsched_drop_get,
    arad_egr_dev_fc_set,
    arad_egr_dev_fc_get,
    NULL,  
    NULL,  
    arad_egr_ofp_fc_set,
    arad_egr_sched_port_fc_thresh_set,
    arad_egr_sched_q_fc_thresh_set,
    arad_egr_ofp_fc_get,
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    arad_egr_ofp_scheduling_set,
    arad_egr_ofp_scheduling_get,
    NULL,  
    NULL,  
    arad_sch_device_rate_entry_set_unsafe,
    arad_sch_device_rate_entry_get_unsafe,
    NULL, 
    NULL, 
    arad_sch_if_shaper_rate_set,
    arad_sch_if_shaper_rate_get,
    arad_sch_device_if_weight_idx_set,
    arad_sch_device_if_weight_idx_get,
    arad_sch_if_weight_conf_set,
    arad_sch_if_weight_conf_get,
    arad_sch_class_type_params_set, 
    arad_sch_class_type_params_get, 
    arad_sch_class_type_params_table_set, 
    arad_sch_class_type_params_table_get, 
    arad_sch_port_sched_set, 
    arad_sch_port_sched_get, 
    NULL, 
    NULL, 
    arad_sch_slow_max_rates_set, 
    arad_sch_slow_max_rates_get,
    NULL , 
    NULL , 
    arad_sch_aggregate_set, 
    arad_sch_aggregate_group_set, 
    arad_sch_aggregate_get, 
    arad_sch_flow_delete, 
    arad_sch_flow_set, 
    arad_sch_flow_get, 
    arad_sch_flow_status_set,
    arad_sch_flow_ipf_config_mode_set,
    arad_sch_flow_ipf_config_mode_get,
    arad_sch_per1k_info_set, 
    arad_sch_per1k_info_get, 
    arad_sch_flow_to_queue_mapping_set, 
    arad_sch_flow_to_queue_mapping_get, 
    arad_sch_flow_id_verify_unsafe, 
    arad_sch_se_id_verify_unsafe, 
    arad_sch_port_id_verify_unsafe, 
    arad_sch_k_flow_id_verify_unsafe, 
    arad_sch_quartet_id_verify_unsafe, 
    NULL, 
    arad_sch_se2port_tc_id,
    arad_sch_flow2se_id, 
    NULL, 
    arad_sch_port_tc2se_id,
    arad_sch_se2flow_id, 
    arad_sch_se_get_type_by_id,
    arad_sch_e2e_interface_allocate,
    arad_sch_e2e_interface_deallocate,
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    arad_sch_shds_tbl_get_unsafe,
    arad_sch_shds_tbl_set_unsafe,
    arad_fabric_fc_enable_set,
    arad_fabric_fc_enable_get,    
    arad_fabric_fc_shaper_get,
    arad_fabric_fc_shaper_set,
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,   
    arad_fabric_priority_set,
    arad_fabric_priority_get,
    arad_fabric_topology_status_connectivity_get,
    NULL,  
    arad_fabric_aldwp_config,
    NULL, 
    arad_fabric_nof_links_get,
    arad_fabric_gci_enable_set,
    arad_fabric_gci_enable_get,
    arad_fabric_gci_config_set,
    arad_fabric_gci_config_get,
    arad_fabric_gci_backoff_masks_init,
    arad_fabric_llfc_threshold_set,
    arad_fabric_llfc_threshold_get,
    arad_fabric_rci_enable_set,
    arad_fabric_rci_enable_get,
    arad_fabric_rci_config_set,
    arad_fabric_rci_config_get,
    arad_fabric_minimal_links_to_dest_set,
    arad_fabric_minimal_links_to_dest_get,
    NULL, 
    NULL, 
    arad_fabric_link_tx_traffic_disable_set,
    arad_fabric_link_tx_traffic_disable_get,
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    arad_fabric_cpu2cpu_write,
    NULL, 
    arad_fabric_mesh_check,
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL,  
    NULL, 
    NULL,  
    NULL,  
    arad_fabric_cell_cpu_data_get,
    NULL,
    NULL,
    arad_ipq_explicit_mapping_mode_info_set,
    arad_ipq_explicit_mapping_mode_info_get,
    arad_ipq_traffic_class_map_set,
    arad_ipq_traffic_class_map_get,
    arad_ipq_traffic_class_multicast_priority_map_set,
    arad_ipq_traffic_class_multicast_priority_map_get,
    arad_ipq_destination_id_packets_base_queue_id_set,
    arad_ipq_destination_id_packets_base_queue_id_get,
    arad_ipq_queue_interdigitated_mode_set,
    arad_ipq_queue_interdigitated_mode_get,
    arad_ipq_queue_to_flow_mapping_set,
    arad_ipq_queue_to_flow_mapping_get,
    arad_ipq_queue_qrtt_unmap,
    arad_ipq_quartet_reset,
    NULL,  
    arad_ipq_tc_profile_set,
    arad_ipq_tc_profile_get,
    arad_ipq_tc_profile_map_set,
    arad_ipq_tc_profile_map_get,
    arad_ipq_stack_lag_packets_base_queue_id_set,
    arad_ipq_stack_lag_packets_base_queue_id_get,
    arad_ipq_stack_fec_map_stack_lag_set,
    arad_ipq_stack_fec_map_stack_lag_get,
    NULL, 
    NULL, 
    arad_ingress_scheduler_clos_bandwidth_set,
    arad_ingress_scheduler_clos_bandwidth_get,
    arad_ingress_scheduler_mesh_bandwidth_set,
    arad_ingress_scheduler_mesh_bandwidth_get,
    arad_ingress_scheduler_clos_sched_set,
    arad_ingress_scheduler_clos_sched_get,
    arad_ingress_scheduler_mesh_sched_set,
    arad_ingress_scheduler_mesh_sched_get,
    arad_ingress_scheduler_clos_burst_set,
    arad_ingress_scheduler_clos_burst_get,
    arad_ingress_scheduler_mesh_burst_set,
    arad_ingress_scheduler_mesh_burst_get,
    arad_ingress_scheduler_clos_set,
    arad_ingress_scheduler_clos_get,
    NULL, 
    NULL,  
    arad_ingress_scheduler_init,
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    arad_itm_dram_buffs_get,
    soc_ardon_dram_info_verify,
    soc_arad_user_buffer_dram_write,
    soc_arad_user_buffer_dram_read,
    soc_arad_validate_dram_address,
    NULL, 
    soc_arad_cache_table_update_all,
    arad_itm_glob_rcs_fc_set, 
    arad_itm_glob_rcs_fc_get, 
    arad_itm_glob_rcs_drop_set, 
    arad_itm_glob_rcs_drop_get, 
    arad_itm_category_rngs_set, 
    arad_itm_category_rngs_get, 
    arad_itm_admit_test_tmplt_set, 
    arad_itm_admit_test_tmplt_get,
    NULL, 
    NULL, 
    arad_itm_cr_request_set, 
    arad_itm_cr_request_get, 
    arad_itm_cr_discount_set, 
    arad_itm_cr_discount_get, 
    arad_itm_queue_test_tmplt_set, 
    arad_itm_queue_test_tmplt_get, 
    arad_itm_wred_exp_wq_set, 
    arad_itm_wred_exp_wq_get, 
    arad_itm_wred_set, 
    arad_itm_wred_get, 
    arad_itm_tail_drop_set, 
    arad_itm_tail_drop_get, 
    arad_itm_fadt_tail_drop_set,
    arad_itm_fadt_tail_drop_get,   
    arad_itm_cr_wd_set, 
    arad_itm_cr_wd_get, 
    arad_itm_enable_ecn,
    arad_itm_get_ecn_enabled,
    NULL, 
    NULL, 
    arad_itm_vsq_qt_rt_cls_set, 
    arad_itm_vsq_qt_rt_cls_get, 
    arad_itm_vsq_fc_set, 
    arad_itm_vsq_fc_get, 
    arad_itm_vsq_tail_drop_set, 
    arad_itm_vsq_tail_drop_get, 
    arad_itm_vsq_tail_drop_default_get,
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    arad_itm_vsq_wred_gen_set,
    arad_itm_vsq_wred_gen_get,
    arad_itm_vsq_wred_set, 
    arad_itm_vsq_wred_get, 
    arad_itm_vsq_counter_set, 
    arad_itm_vsq_counter_get, 
    arad_itm_vsq_counter_read, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    arad_itm_queue_is_ocb_only_get,
    arad_itm_queue_info_set, 
    arad_itm_queue_info_get, 
    arad_itm_ingress_shape_set, 
    arad_itm_ingress_shape_get, 
    arad_itm_priority_map_tmplt_set, 
    arad_itm_priority_map_tmplt_get, 
    arad_itm_priority_map_tmplt_select_set, 
    arad_itm_priority_map_tmplt_select_get, 
    arad_itm_sys_red_drop_prob_set, 
    arad_itm_sys_red_drop_prob_get, 
    arad_itm_sys_red_queue_size_boundaries_set, 
    arad_itm_sys_red_queue_size_boundaries_get, 
    arad_itm_sys_red_q_based_set, 
    arad_itm_sys_red_q_based_get, 
    arad_itm_sys_red_eg_set, 
    arad_itm_sys_red_eg_get, 
    arad_itm_sys_red_glob_rcs_set, 
    arad_itm_sys_red_glob_rcs_get, 
    arad_itm_vsq_index_global2group, 
    arad_itm_vsq_index_group2global,
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    arad_itm_dyn_total_thresh_set,
    arad_itm_queue_dyn_info_get, 
    arad_iqm_static_tbl_set_unsafe,
    arad_iqm_static_tbl_get_unsafe,
    NULL, 
    NULL, 
    arad_iqm_dynamic_tbl_get_unsafe,
    arad_itm_congestion_statistics_get,
    NULL, 
    arad_ingress_drop_status,
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL,           
    dpp_mult_eg_bitmap_group_range_set,
    dpp_mult_eg_bitmap_group_range_get,
    NULL, 
    NULL, 
    dpp_mult_eg_group_set,
    dpp_mult_eg_group_close,
    NULL, 
    dpp_mult_eg_reps_add,
    NULL, 
    dpp_mult_eg_reps_remove,
    dpp_mult_eg_group_size_get,
    NULL, 
    dpp_mult_eg_get_group,
    NULL, 
    dpp_mult_eg_bitmap_group_create,
    dpp_mult_eg_bitmap_group_update,
    dpp_mult_eg_bitmap_group_close,
    dpp_mult_eg_bitmap_group_port_add, 
    dpp_mult_eg_bitmap_group_port_remove,
    dpp_mult_eg_bitmap_group_bm_add, 
    dpp_mult_eg_bitmap_group_bm_remove,
    dpp_mult_eg_bitmap_group_get,
    dpp_mcds_multicast_init2,
    arad_mult_fabric_traffic_class_to_multicast_cls_map_set,
    arad_mult_fabric_traffic_class_to_multicast_cls_map_get,
    arad_mult_fabric_base_queue_set,
    arad_mult_fabric_base_queue_get,
    arad_mult_fabric_credit_source_set,
    arad_mult_fabric_credit_source_get,
    arad_mult_fabric_enhanced_set,
    arad_mult_fabric_enhanced_get,
    arad_mult_fabric_flow_control_set,
    arad_mult_fabric_flow_control_get,
    NULL,  
    NULL,  
    dpp_mult_does_group_exist_ext,
    dpp_mult_ing_traffic_class_map_set,
    dpp_mult_ing_traffic_class_map_get,
    dpp_mult_ing_group_open,
    dpp_mult_ing_group_update,
    dpp_mult_ing_group_close,
    dpp_mult_ing_destination_add,
    arad_mult_ing_encode_entry,
    dpp_mult_ing_destination_remove,
    dpp_mult_ing_group_size_get,
    NULL, 
    dpp_mult_ing_get_group,
    
    
     
     
     
     
     
    
    
    
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    arad_sys_phys_to_local_port_map_set,
    arad_sys_phys_to_local_port_map_get,
    arad_local_to_sys_phys_port_map_get,
    arad_modport_to_sys_phys_port_map_get,
    arad_port_to_interface_map_set,
    arad_port_to_interface_map_get,
    arad_ports_is_port_lag_member,
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    arad_port_header_type_set,
    arad_port_header_type_get,
    NULL,  
    NULL,  
    NULL,  
    NULL, 
    arad_ports_mirror_to_rcy_port_get,
    NULL,  
    NULL,  
    NULL, 
    NULL, 
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    arad_ports_ftmh_extension_set,
    arad_ports_ftmh_extension_get,
    arad_ports_reference_clock_set,
    arad_ports_port_to_nif_id_get,
    arad_ports_mirrored_channel_and_context_map,
    arad_port_egr_hdr_credit_discount_type_set,
    arad_port_egr_hdr_credit_discount_type_get,
    arad_port_egr_hdr_credit_discount_select_set,
    arad_port_egr_hdr_credit_discount_select_get,
    arad_port_stacking_info_set,
    arad_port_stacking_info_get,
    arad_port_stacking_route_history_bitmap_set,
    arad_port_direct_lb_key_set,
    arad_port_direct_lb_key_get,
    arad_port_direct_lb_key_min_set,
    arad_port_direct_lb_key_max_set,
    arad_port_direct_lb_key_min_get,
    arad_port_direct_lb_key_max_get,
    arad_port_synchronize_lb_key_tables_at_egress,
    arad_port_switch_lb_key_tables,
    arad_port_rx_enable_get,
    arad_port_rx_enable_set,
    NULL,  
    NULL,  
    arad_port_ingr_reassembly_context_get,
    arad_port_rate_egress_pps_set,
    arad_port_rate_egress_pps_get,
    arad_port_protocol_offset_verify,
    arad_port_cable_diag,
    arad_ports_swap_set,
    arad_ports_swap_get,
    arad_ports_pon_tunnel_info_set,
    arad_ports_pon_tunnel_info_get,
    arad_ports_extender_mapping_enable_set,
    arad_ports_extender_mapping_enable_get,
	arad_ports_tm_port_var_set,
	arad_ports_tm_port_var_get,
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL, 
    arad_brdc_fsrd_blk_id_set,
    arad_mgmt_credit_worth_set,  
    arad_mgmt_credit_worth_get,
	arad_plus_mgmt_module_to_credit_worth_map_set,
	arad_plus_mgmt_module_to_credit_worth_map_get,
	arad_plus_mgmt_credit_worth_remote_set,
	arad_plus_mgmt_credit_worth_remote_get,
	arad_plus_mgmt_change_all_faps_credit_worth_unsafe,
	arad_mgmt_all_ctrl_cells_enable_get,
    arad_mgmt_all_ctrl_cells_enable_set,
    arad_force_tdm_bypass_traffic_to_fabric_set,
    arad_force_tdm_bypass_traffic_to_fabric_get,
    arad_mgmt_enable_traffic_set,
    arad_mgmt_enable_traffic_get,
    arad_register_device,
    arad_unregister_device,
    arad_mgmt_system_fap_id_set,
    arad_mgmt_system_fap_id_get_unsafe,
    arad_mgmt_tm_domain_set,
    arad_mgmt_tm_domain_get,
    NULL, 
    NULL, 
    NULL,     
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    NULL,  
    arad_port_loopback_set,
    arad_port_loopback_get,
    arad_nif_synce_clk_sel_port_set, 
    arad_nif_synce_clk_sel_port_get, 
    arad_nif_synce_clk_div_set, 
    arad_nif_synce_clk_div_get, 
    arad_nif_synce_clk_squelch_set,
    arad_nif_synce_clk_squelch_get,
    arad_port_link_up_mac_update,
    arad_flow_and_up_info_get,
    arad_ips_non_empty_queues_info_get,
    arad_itm_pfc_tc_map_set,
    arad_itm_pfc_tc_map_get,
    arad_fc_gen_cal_set,
    arad_fc_gen_cal_get,
    arad_fc_gen_inbnd_set,
    arad_fc_gen_inbnd_get,
    arad_fc_gen_inbnd_glb_hp_set,
    arad_fc_gen_inbnd_glb_hp_get,
    arad_fc_rec_cal_set,
    arad_fc_rec_cal_get,
    arad_fc_pfc_generic_bitmap_set,
    arad_fc_pfc_generic_bitmap_get,
    arad_fc_port_fifo_threshold_set,
    arad_fc_port_fifo_threshold_get,
    arad_egr_dsp_pp_to_base_q_pair_get,
    arad_egr_dsp_pp_to_base_q_pair_set,
    arad_egr_dsp_pp_priorities_mode_get,
    arad_egr_dsp_pp_priorities_mode_set,
    arad_egr_dsp_pp_shaper_mode_set_unsafe,
    arad_egr_queuing_dev_set,
    arad_egr_queuing_dev_get,
    arad_egr_queuing_global_drop_set,
    arad_egr_queuing_global_drop_get,
    arad_egr_queuing_sp_tc_drop_set,
    arad_egr_queuing_sp_tc_drop_get,
    arad_egr_queuing_sch_unsch_drop_set,
    NULL, 
    arad_egr_queuing_sp_reserved_set,
    arad_egr_queuing_sp_reserved_get,
    arad_egr_queuing_global_fc_set,
    arad_egr_queuing_global_fc_get,
    arad_egr_queuing_mc_tc_fc_set,
    arad_egr_queuing_mc_tc_fc_get,
    arad_egr_queuing_mc_cos_map_set,
    arad_egr_queuing_mc_cos_map_get,
    arad_egr_queuing_if_fc_set,
    arad_egr_queuing_if_fc_get,
    arad_egr_queuing_if_fc_uc_max_set,
    arad_egr_queuing_if_fc_uc_set,
    arad_egr_queuing_if_fc_uc_get,
    arad_egr_queuing_if_fc_mc_set,
    arad_egr_queuing_if_fc_mc_get,
    arad_egr_queuing_if_uc_map_set,
    arad_egr_queuing_if_mc_map_set,
    
    
    
    
    arad_egr_queuing_ofp_tcg_set,
    arad_egr_queuing_ofp_tcg_get,
    arad_egr_queuing_tcg_weight_set,
    arad_egr_queuing_tcg_weight_get,
    arad_egr_queuing_is_high_priority_port_get,
    arad_egr_queuing_init_thresholds,
    arad_egr_queuing_egr_interface_alloc,
    arad_egr_queuing_egr_interface_free,
    NULL, 
    NULL, 
    arad_sch_port_tcg_weight_set,
    arad_sch_port_tcg_weight_get,
    soc_pm_frame_max_set,
    soc_pm_frame_max_get,
    arad_mgmt_ocb_voq_eligible_dynamic_set,
    NULL, 
    dpp_mult_cud_to_port_map_set,
    dpp_mult_cud_to_port_map_get,
    soc_arad_nof_interrupts,
    arad_mgmt_nof_block_instances,
    arad_mgmt_temp_pvt_get,
    arad_mgmt_avs_value_get,
    arad_itm_dp_discard_set,
    arad_itm_dp_discard_get,
    arad_plus_itm_alpha_set,
    arad_plus_itm_alpha_get,
    arad_plus_itm_fair_adaptive_tail_drop_enable_set,
    arad_plus_itm_fair_adaptive_tail_drop_enable_get,
    arad_ports_application_mapping_info_set,
    arad_ports_application_mapping_info_get,
    arad_ofp_rates_max_credit_empty_port_set,
    arad_ofp_rates_max_credit_empty_port_get,
    soc_arad_allocate_rcy_port,
    soc_arad_free_tm_port_and_recycle_channel,
    soc_arad_info_config_device_ports,
    soc_arad_is_olp,
    soc_arad_is_oamp,
    soc_arad_validate_fabric_mode,
    soc_arad_prop_fap_device_mode_get,
    soc_arad_deinit,
    soc_arad_attach,
    soc_arad_fc_oob_mode_validate,
    NULL, 
    arad_ofp_rates_port_priority_max_burst_for_fc_queues_set,          
    arad_ofp_rates_port_priority_max_burst_for_empty_queues_set,       
    arad_ofp_rates_port_priority_max_burst_for_fc_queues_get,          
    arad_ofp_rates_port_priority_max_burst_for_empty_queues_get,       
    arad_ofp_rates_sch_single_port_rate_sw_set,                     
    arad_ofp_rates_sch_single_port_rate_hw_set,                     
    arad_ofp_rates_egq_single_port_rate_sw_set,
    arad_ofp_rates_egq_single_port_rate_sw_get_unsafe,
    arad_ofp_rates_egq_single_port_rate_hw_set,                     
    arad_ofp_rates_sch_single_port_rate_hw_get,                           
    arad_ofp_rates_egq_single_port_rate_hw_get,                           
    arad_ofp_rates_single_port_max_burst_set,                          
    arad_ofp_rates_single_port_max_burst_get,                                                  
    arad_ofp_rates_egq_interface_shaper_set,                                                  
    arad_ofp_rates_egq_interface_shaper_get,                           
    arad_ofp_rates_egq_tcg_rate_sw_set,                             
    arad_ofp_rates_egq_tcg_rate_hw_set,                             
    arad_ofp_rates_sch_tcg_rate_set,                                   
    arad_ofp_rates_egq_tcg_rate_hw_get,                                   
    arad_ofp_rates_sch_tcg_rate_get,
    arad_ofp_rates_sch_tcg_shaper_disable,
    arad_ofp_rates_egq_tcg_max_burst_set,                              
    arad_ofp_rates_sch_tcg_max_burst_set,                              
    arad_ofp_rates_egq_tcg_max_burst_get,                              
    arad_ofp_rates_sch_tcg_max_burst_get,                              
    arad_ofp_rates_egq_port_priority_rate_sw_set,                   
    arad_ofp_rates_egq_port_priority_rate_hw_set,                   
    arad_ofp_rates_sch_port_priority_rate_set,                         
    arad_ofp_rates_sch_port_priority_rate_sw_set,
    arad_ofp_rates_sch_port_priority_hw_set,
    arad_ofp_rates_egq_port_priority_rate_hw_get,                         
    arad_ofp_rates_sch_port_priority_rate_get,                         
    arad_ofp_rates_egq_port_priority_max_burst_set,                    
    arad_ofp_rates_sch_port_priority_max_burst_set,                    
    arad_ofp_rates_egq_port_priority_max_burst_get,                    
    arad_ofp_rates_sch_port_priority_max_burst_get,
    arad_ofp_rates_port2chan_cal_get,
    arad_ofp_rates_retrieve_egress_shaper_reg_field_names,
    arad_ofp_rates_egress_shaper_reg_field_read,
    arad_ofp_rates_egress_shaper_reg_field_write,
    arad_egq_scm_chan_arb_id2scm_id,
    NULL, 
    arad_ofp_rates_packet_mode_packet_size_get,
    arad_ofp_rates_egress_shaper_cal_write,
    arad_ofp_rates_egress_shaper_cal_read,
    arad_port2egress_offset,
    arad_ofp_rates_is_channalized,
    arad_sch_cal_tbl_set,
    arad_sch_cal_tbl_get,
    arad_sch_cal_max_size_get,
    soc_port_sw_db_local_to_tm_port_get,
    soc_port_sw_db_local_to_pp_port_get,
    soc_port_sw_db_tm_to_local_port_get,
    soc_port_sw_db_pp_to_local_port_get,
    arad_port_init,
    arad_port_post_init,
    arad_port_deinit,
    arad_port_enable_set,
    arad_port_enable_get,
    arad_port_speed_set,
    arad_port_speed_get,
    arad_port_interface_set,
    arad_port_interface_get,
    arad_port_link_state_get,
    arad_port_is_supported_encap_get,
    arad_egr_q_nif_cal_set_unsafe,
    soc_common_drv_fast_port_set,
    arad_parser_nof_bytes_to_remove_set,
    arad_ps_db_find_free_binding_ps,
    arad_ps_db_release_binding_ps,
    arad_ps_db_alloc_binding_ps_with_id,
    arad_egr_prog_editor_profile_set,
    NULL,
    arad_fc_pfc_mapping_set,
    arad_fc_pfc_mapping_get,
    arad_port_probe,
    soc_pm_port_deinit,
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL,     
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    soc_arad_port_speed_sku_restrictions,
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    arad_port_control_pcs_set,
    arad_port_control_pcs_get,
    arad_link_power_set,
    arad_link_power_get,
    arad_link_control_rx_enable_set,
    arad_link_control_tx_enable_set,
    soc_arad_port_control_tx_nif_enable_set,
    arad_link_control_rx_enable_get,
    arad_link_control_tx_enable_get,
    soc_arad_port_control_tx_nif_enable_get,
    arad_link_control_strip_crc_set,
    arad_link_control_strip_crc_get,
    arad_port_prbs_tx_enable_set,    
    arad_port_prbs_tx_enable_get,       
    arad_port_prbs_rx_enable_set,      
    arad_port_prbs_rx_enable_get,      
    arad_port_prbs_rx_status_get,      
    arad_fabric_prbs_polynomial_set,      
    arad_fabric_prbs_polynomial_get,    
    arad_port_prbs_tx_invert_data_set, 
    arad_port_prbs_tx_invert_data_get,
    soc_pm_pfc_refresh_set,
    soc_pm_pfc_refresh_get,
    soc_pm_local_fault_clear,
    soc_pm_remote_fault_clear,
    soc_pm_pad_size_set,
    soc_pm_pad_size_get,
    arad_port_phy_reset,
    arad_port_phy_control_set,
    arad_port_phy_control_get,
    arad_port_phy_reg_get,
    arad_port_phy_reg_set,
    arad_port_phy_reg_modify,
    soc_pm_mac_sa_set,
    soc_pm_mac_sa_get,
    soc_pm_eee_enable_get,
    arad_port_eee_enable_set,
    soc_pm_eee_tx_idle_time_get,
    soc_pm_eee_tx_idle_time_set,
    soc_pm_eee_tx_wake_time_get,
    soc_pm_eee_tx_wake_time_set,
    soc_pm_eee_link_active_duration_get,
    soc_pm_eee_link_active_duration_set,
    arad_port_eee_statistics_clear,
    arad_port_eee_event_count_symmetric_set,
    arad_port_eee_tx_event_count_get,
    arad_port_eee_tx_duration_get,
    arad_port_eee_rx_event_count_get,
    arad_port_eee_rx_duration_get,
    arad_port_eee_event_count_symmetric_get,
    arad_fc_enables_set,
    arad_fc_enables_get,
    arad_fc_ilkn_mub_channel_set,
    arad_fc_ilkn_mub_channel_get,
    arad_fc_ilkn_mub_gen_cal_set,
    arad_fc_ilkn_mub_gen_cal_get,
    arad_fc_cat_2_tc_hcfc_bitmap_set,
    arad_fc_cat_2_tc_hcfc_bitmap_get,
    arad_fc_glb_hcfc_bitmap_set,
    arad_fc_glb_hcfc_bitmap_get,
    arad_fc_inbnd_mode_set,
    arad_fc_inbnd_mode_get,
    NULL, 
    NULL, 
    arad_fc_init_pfc_mapping,
    arad_fc_ilkn_llfc_set,
    arad_fc_ilkn_llfc_get,
    arad_nif_ipg_set_unsafe,
    arad_nif_ipg_get_unsafe,
    arad_port_link_get,
    NULL, 
    NULL, 
    arad_port_autoneg_set,
    arad_port_autoneg_get,
    arad_port_ability_local_get,
    arad_port_ability_remote_get,
    arad_port_ability_advert_set,
    arad_port_ability_advert_get,
    arad_port_mdix_set,
    arad_port_mdix_get,
    arad_port_mdix_status_get,
    arad_port_duplex_set,
    arad_port_duplex_get,
    arad_port_nif_nof_lanes_get,
    NULL, 
    arad_port_close_path,
    arad_fc_hcfc_watchdog_set,
    arad_fc_hcfc_watchdog_get,
	arad_port_fault_get,
    arad_link_port_fault_get,
    NULL,  
    NULL,  
    arad_ports_logical_sys_id_parse,
    arad_fc_vsq_index_group2global,
    arad_port_cntmaxsize_set,
    arad_port_cntmaxsize_get,
    arad_fc_status_info_get,
    NULL,  
    NULL,  	
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    arad_stat_counter_erpp_offset_set,
    arad_stat_counter_erpp_offset_get,
    NULL, 
    NULL,     
    arad_cnt_crps_iqm_cmd_get,
    _jer_cnt_counter_bmap_mem_by_src_type_get,
    _arad_cnt_do_not_count_field_by_src_type_get,
    arad_cnt_stif_ingress_pp_source_set,
    arad_fc_pfc_generic_bitmap_valid_update,
    arad_fc_pfc_generic_bitmap_used_update,
    NULL,  
    NULL,   	
    NULL,    	
#ifdef PORTMOD_SUPPORT
    NULL,   
#endif
    NULL,   
    NULL,   
    NULL,    
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    soc_arad_nif_sku_restrictions,
    NULL,   
    NULL,    
    NULL,   
    soc_bist_all_arad,
    soc_arad_device_reset,
    arad_fc_cmic_rx_set,
    arad_fc_cmic_rx_get,
    dpp_mult_get_entry,
    NULL, 
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    arad_pp_mtr_ir_val_to_max_rev_exp_optimized_for_bucket_rate,
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
    NULL,        
};