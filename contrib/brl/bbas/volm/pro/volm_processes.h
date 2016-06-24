#ifndef volm_processes_h_
#define volm_processes_h_

#include <bprb/bprb_func_process.h>
#include <bprb/bprb_macros.h>

DECLARE_FUNC_CONS(volm_create_satellite_resources_process);
DECLARE_FUNC_CONS(volm_save_satellite_resources_process);
DECLARE_FUNC_CONS(volm_load_satellite_resources_process);
DECLARE_FUNC_CONS(volm_add_satellite_resources_process);
DECLARE_FUNC_CONS(volm_query_satellite_resources_process);
DECLARE_FUNC_CONS(volm_query_satellite_resources_kml_process);
DECLARE_FUNC_CONS(volm_correct_rational_cameras_ransac_process);
DECLARE_FUNC_CONS(volm_pick_nadir_resource_process);
DECLARE_FUNC_CONS(volm_pick_nadir_resource_pair_process);
DECLARE_FUNC_CONS(volm_map_osm_process);
DECLARE_FUNC_CONS(volm_map_osm_onto_image_process);
DECLARE_FUNC_CONS(volm_map_segments_process);
DECLARE_FUNC_CONS(volm_generate_class_map_process);
DECLARE_FUNC_CONS(volm_generate_color_class_map_process);
DECLARE_FUNC_CONS(volm_update_class_map_process);
DECLARE_FUNC_CONS(volm_find_res_pair_process);
DECLARE_FUNC_CONS(volm_find_min_max_height_process);
DECLARE_FUNC_CONS(volm_correct_rational_cameras_ransac_process2);
DECLARE_FUNC_CONS(volm_correct_rational_cameras_ransac_with_intial_process);
DECLARE_FUNC_CONS(volm_get_full_path_process);
DECLARE_FUNC_CONS(volm_find_satellite_pairs_process);
DECLARE_FUNC_CONS(volm_find_satellite_pairs_poly_process);
DECLARE_FUNC_CONS(volm_transfer_geoindex_id_to_str_process);
DECLARE_FUNC_CONS(volm_transfer_geoindex_id_to_str_process2);
DECLARE_FUNC_CONS(volm_generate_height_map_from_ply_process);
DECLARE_FUNC_CONS(volm_refine_bvxm_height_map_process);
DECLARE_FUNC_CONS(volm_project_dem_to_sat_img_process);
DECLARE_FUNC_CONS(volm_upsample_dem_projected_img_process);
DECLARE_FUNC_CONS(volm_generate_height_map_plot_process);
DECLARE_FUNC_CONS(volm_satellite_pair_intersection_process);
DECLARE_FUNC_CONS(volm_combine_height_map_process);
DECLARE_FUNC_CONS(volm_combine_height_map_process2);
DECLARE_FUNC_CONS(volm_combine_height_map_process3);
DECLARE_FUNC_CONS(volm_extract_building_outlines_process);
DECLARE_FUNC_CONS(volm_map_osm_onto_image_process2);
DECLARE_FUNC_CONS(volm_map_osm_onto_image_process3);
DECLARE_FUNC_CONS(volm_registration_error_process);
DECLARE_FUNC_CONS(volm_stereo_height_fix_process);
DECLARE_FUNC_CONS(volm_find_overlapping_sat_resources_process);
DECLARE_FUNC_CONS(volm_find_intersecting_sat_resources_process);
DECLARE_FUNC_CONS(volm_ndsm_generation_process);
DECLARE_FUNC_CONS(volm_dsm_ground_plane_estimation_process);
DECLARE_FUNC_CONS(volm_dsm_ground_plane_estimation_edge_process);
DECLARE_FUNC_CONS(volm_building_layer_extraction_process);
DECLARE_FUNC_CONS(volm_layer_extraction_process);
DECLARE_FUNC_CONS(volm_render_kml_polygon_mask_process);
DECLARE_FUNC_CONS(volm_generate_kml_from_binary_image_process);
DECLARE_FUNC_CONS(volm_downsample_binary_layer_process);
DECLARE_FUNC_CONS(volm_dsm_ground_filter_mgf_process);
DECLARE_FUNC_CONS(volm_detection_rate_roc_process);
#endif
