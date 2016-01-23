#include "boxm2_vecf_fat_pocket.h"
#include <vcl_cstdlib.h>
#include <vcl_fstream.h>
boxm2_vecf_fat_pocket::boxm2_vecf_fat_pocket(vcl_string const& geometry_file){

  vcl_ifstream istr(geometry_file.c_str());
  if(!istr){
    vcl_cout << "FATAL! - geometry file path not valid = " << geometry_file << '\n';
    return;
  }
  // construct paths to component scene xml files
  vcl_map<vcl_string, vcl_string> fat_pocket_map;
  vcl_string component, path;
  while(istr >> component >> path)
    fat_pocket_map[component] = path;

  vcl_string base_path, knot_path, param_path;

  vcl_map<vcl_string, vcl_string>::iterator pit;

  pit = fat_pocket_map.find("base_path");
  if(pit == fat_pocket_map.end()){
    vcl_cout << "FATAL - base_path not defined\n";
    return;
  }else
    base_path = pit->second;
  
  pit = fat_pocket_map.find("knot_path");
  if(pit == fat_pocket_map.end()){
    vcl_cout << "FATAL - knot_path not defined\n";
    return;
  }else
    knot_path = base_path + pit->second;
  if(!vul_file::exists(knot_path)){
    vcl_cout << "FATAL - " << knot_path << " does not exist\n";
    return;
  }
  
  pit = fat_pocket_map.find("param_path");
  if(pit == fat_pocket_map.end()){
    vcl_cout << "FATAL - param_path not defined\n";
    return;
  }else
    param_path = base_path + pit->second;
  if(!vul_file::exists(param_path)){
    vcl_cout << "FATAL - " << param_path << " does not exist\n";
    return;
  }
  istr.close();

  vcl_ifstream kistr(knot_path.c_str());
  if(!kistr){
    vcl_cout << "FATAL! - can't open = " << knot_path << '\n';
    return;
  }
  vcl_vector<vgl_point_2d<double> > knots;
  double x, y;
  char c;
  while(kistr >> x >> c >> y){
    if(c != ','){
      vcl_cout << "FATAL! knot file parse error\n";
      return;
    }
    vgl_point_2d<double> knot(x, y);
    knots.push_back(knot);
  }
  kistr.close();
  
  vcl_ifstream pistr(param_path.c_str());
  if(!pistr){
    vcl_cout << "FATAL! - can't open = " << param_path << '\n';
    return;
  }
  pistr >> params_;
  pistr.close();
  undeformed_params_ = params_;
  base_ = bvgl_spline_region_3d<double>(knots, params_.normal_, params_.origin_, params_.tolerance_);
  pocket_ = bvgl_scaled_shape_3d<double>(base_, params_.max_norm_distance_, params_.scale_at_midpt_, params_.scale_at_max_, params_.tolerance_);
}
boxm2_vecf_fat_pocket::boxm2_vecf_fat_pocket(vcl_vector<vgl_point_2d<double> > const& knots):
  base_(bvgl_spline_region_3d<double>(knots, params_.normal_, params_.origin_, params_.tolerance_)){
  pocket_ = bvgl_scaled_shape_3d<double>(base_, params_.max_norm_distance_, params_.scale_at_midpt_, params_.scale_at_max_, params_.tolerance_);
}

bool boxm2_vecf_fat_pocket::inverse_vector_field(vgl_point_3d<double> p, vgl_vector_3d<double> inv_v) const{
  return true;
}
