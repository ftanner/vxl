#include "boxm2_vecf_skin.h"
#include <bvrml/bvrml_write.h>
#include <vgl/vgl_intersection.h>
#include <vgl/vgl_box_3d.h>
#include <vgl/vgl_bounding_box.h>
#include <vcl_map.h>

boxm2_vecf_skin::boxm2_vecf_skin(vcl_string const& geometry_file, unsigned nbins): nbins_(nbins),has_appearance_(false){
  vcl_ifstream istr(geometry_file.c_str());
  if(!istr){
    vcl_cout << " invalid path for skin geometry " << geometry_file << '\n';
    return;
  }
  vcl_map<vcl_string, vcl_string> skin_paths;
  vcl_string component, path;
  while(istr >> component >> path)
    skin_paths[component] = path;

  vcl_map<vcl_string, vcl_string>::iterator pit;
  pit = skin_paths.find("skin");
  if(pit == skin_paths.end()){
    vcl_cout << "FATAL - can't find geometry path for skin\n";
    return;
  }
  vcl_ifstream cstr((pit->second).c_str());
  //determine if file contains appearance data, i.e., 4 items per line or 7 items per line, comma separated
  bool has_appearance = false;
  char buf[100];
  if(!cstr.getline(buf,100)){
    vcl_cout << "FATAL - bad input stream for skin geometry\n";
    return;
  }else{
    vcl_string buf_str;
    bool done = false;
    unsigned comma_count = 0;
    for(unsigned i =0; i<100&&!done; ++i){
      char c = buf[i];
      if(c == '\0'||c == '\n'){
        done = true;
        continue;
      }else if(c == ',')
        comma_count++;
    }
    has_appearance_ = comma_count == 3 || comma_count == 6;
    cstr.seekg(0);
    this->read_skin(cstr, comma_count);
  }
}
void boxm2_vecf_skin::read_skin(vcl_istream& cstr, unsigned comma_count){
  double surface_dist_thresh = 1.0;
  if(!has_appearance_){
    cstr >> ptset_;
    index_ = bvgl_grid_index_3d(nbins_, nbins_, nbins_, ptset_, surface_dist_thresh);
  }else{
    vcl_vector<vgl_point_3d<double> > pts;
    vcl_vector<vgl_vector_3d<double> > norms;
    unsigned char c;
    double x, y, z, nx, ny, nz, a;
    if(comma_count == 3){
      while(cstr >> x >> c >> y >> c >> z >> c >> a){
        if(c!=','){
          vcl_cout << "FATAL skin geometry parse error\n";
          return;
        }
        appearance_.push_back(a);
        vgl_point_3d<double> p(x, y, z);
        pts.push_back(p);
      }
      ptset_.set_points(pts);
      index_ = bvgl_grid_index_3d(nbins_, nbins_, nbins_, ptset_, appearance_,surface_dist_thresh);
    }else if(comma_count == 6){
      while(cstr >> x >> c >> y >> c >> z >> c >> nx >> c >> ny >> c >> nz >> c >> a){
        if(c!=','){
          vcl_cout << "FATAL skin geometry parse error\n";
          return;
        }
        appearance_.push_back(a);
        vgl_point_3d<double> p(x, y, z);
        pts.push_back(p);
        vgl_vector_3d<double> n(nx, ny, nz);
        norms.push_back(n);
      }
      ptset_.set_points_with_normals(pts, norms);
      index_ = bvgl_grid_index_3d(nbins_, nbins_, nbins_, ptset_, appearance_, surface_dist_thresh);
    }
  }
}

void boxm2_vecf_skin::display_vrml(vcl_ofstream& ostr) const{
  bvrml_write::write_vrml_header(ostr);
  unsigned n = ptset_.npts();
  unsigned skip = 1;
  if(n>100000)
    skip = 100;
  float r = 3.0f, h = 0.1f;
  for(unsigned i = 0; i<n; i+=skip){
    vgl_point_3d<double> p = ptset_.p(i);
    vgl_vector_3d<double> n;
    if(ptset_.has_normals())
      n = ptset_.n(i);
    else{
      n = vgl_vector_3d<double>(p.x(), p.y(), p.z());
      n/= n.length();
    }
    if(!has_appearance_)
      bvrml_write::write_vrml_cylinder(ostr, p, n, r, h, 0.0f, 1.0f, 0.3f, 1);
    else{
      double a = appearance_[i];
      float grey = static_cast<float>(a/255.0);
      bvrml_write::write_vrml_cylinder(ostr, p, n, r, h, grey, grey, grey, 1);
  }
  }
  ostr.close();
}