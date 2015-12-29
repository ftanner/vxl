#include "boxm2_vecf_composite_face_articulation.h"

boxm2_vecf_composite_face_articulation::boxm2_vecf_composite_face_articulation(){

  //======================= default articulation =====================
  vcl_vector<boxm2_vecf_composite_face_params> default_articulation;
  boxm2_vecf_composite_face_params  params;
  default_articulation.push_back(params);
  params.mandible_params_.jaw_opening_angle_rad_ = 0.05;
  default_articulation.push_back(params);
  params.mandible_params_.jaw_opening_angle_rad_ = 0.1;
  default_articulation.push_back(params);
  params.mandible_params_.jaw_opening_angle_rad_ = 0.15;
  default_articulation.push_back(params);
  params.mandible_params_.jaw_opening_angle_rad_ = 0.2;
  default_articulation.push_back(params);
  params.mandible_params_.jaw_opening_angle_rad_ = 0.25;
  default_articulation.push_back(params);
  params.mandible_params_.jaw_opening_angle_rad_ = 0.2;
  default_articulation.push_back(params);
  params.mandible_params_.jaw_opening_angle_rad_ = 0.15;
  default_articulation.push_back(params);
  params.mandible_params_.jaw_opening_angle_rad_ = 0.1;
  default_articulation.push_back(params);
  play_sequence_map_["default"] = default_articulation;
  this->set_play_sequence("default") ;
}
