#ifndef boxm2_vecf_fat_pocket_h_
#define boxm2_vecf_fat_pocket_h_
//:
// \file
// \brief  The fat_pocket component of the head
//
// \author J.L. Mundy
// \date   10 Jan 2016
//
#include <vcl_iostream.h>
#include <vcl_string.h>
#include <vcl_vector.h>
#include <vgl/vgl_box_3d.h>
#include <vgl/vgl_pointset_3d.h>
#include <vgl/vgl_point_2d.h>
#include <vgl/vgl_point_3d.h>
#include <bvgl/bvgl_spline_region_3d.h>
#include <bvgl/bvgl_scaled_shape_3d.h>
#include "boxm2_vecf_fat_pocket_params.h"
class boxm2_vecf_fat_pocket{
 public:
  boxm2_vecf_fat_pocket(){}
  boxm2_vecf_fat_pocket(vcl_string const& geometry_file);

  boxm2_vecf_fat_pocket(vcl_vector<vgl_point_2d<double> > const& knots); 


  void set_params(boxm2_vecf_fat_pocket_params const& params){ params_ = params;}

    //: extract points inside the bounding box spanning the planar region and a single point at norm_distance from the plane
  vgl_pointset_3d<double> extract_pocket_pts(vgl_pointset_3d<double> const& ptset, double norm_distance) const;

  vgl_box_3d<double> bounding_box() const{
    return pocket_.bounding_box();}

  bool in(vgl_point_3d<double> const& pt) const{
    return pocket_.in(pt);}
    
  vgl_pointset_3d<double> random_pointset(unsigned n_pts) const{
    return pocket_.random_pointset(n_pts);
  }
  
  // deformation vector field
  bool inverse_vector_field(vgl_point_3d<double> p, vgl_vector_3d<double> inv_v) const;

 private:
  void read_fat_pocket(vcl_istream& istr);
  bvgl_spline_region_3d<double> base_;
  boxm2_vecf_fat_pocket_params undeformed_params_;
  boxm2_vecf_fat_pocket_params params_;
  bvgl_scaled_shape_3d<double> pocket_;
};
vcl_ostream&  operator << (vcl_ostream& s, boxm2_vecf_fat_pocket const& pr);
vcl_istream&  operator >> (vcl_istream& s, boxm2_vecf_fat_pocket& pr);

#endif// boxm2_vecf_fat_pocket
