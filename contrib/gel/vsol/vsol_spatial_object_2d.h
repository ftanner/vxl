#ifndef _vsol_spatial_object_2d_h_
#define _vsol_spatial_object_2d_h_
//-----------------------------------------------------------------------------
//
// .NAME        vsol_spatial_object_2d - Base class of spatial entities Topology Geometry SpatialGroup
// .LIBRARY     vsol
// .HEADER      vxl  package
// .INCLUDE     vsol/vsol_spatial_object_2d.h
// .FILE        vsol_spatial_object_2d.cxx
//
// .SECTION Description
//   vsol_spatial_object_2d is the base class of all spatial entities: vtol, vsol.
//
// .SECTION Author
//     Patricia A. Vrobel
// .SECTION Modifications
// 2000/05/10 Fran�ois BERTEL  add cast_to_group() because VXL is not compiled
//                             with -frtti :-(
// 2000/05/03 Peter TU         ported
// 1996/12/16 Peter VANROOSE   made destructor protected
// 1995/12/xx JLM
//           Replaced the SpatialGroup pointer by an IUBox bounding volume.
//           See the discussion in SpatialGroup.h for the rationale.
//           The bounding volume is updated according to a timestamp
//           mechanism similar to that used in 3D display. That is,
//           if the vsol_spatial_object_2d is modified it is "touched" to
//           set the timestamp.  Then, any request to bounding information
//           automatically updates the bounding volume if necessary.
//
//-----------------------------------------------------------------------------

class vsol_spatial_object_2d;

//*****************************************************************************
// External declarations for values
//*****************************************************************************
#include <vsol/vsol_spatial_object_2d_sptr.h>

#include <vcl_string.h>
#include <vcl_iostream.h>
#include <vbl/vbl_timestamp.h>
#include <vbl/vbl_ref_count.h>
#include <vsol/vsol_box_2d.h>
#include <vcl_vector.h>
#include <vsol/vsol_group_2d_sptr.h>

class vtol_topology_object_2d;
extern void iu_delete(vsol_spatial_object_2d *);


#ifndef VSOL_SPATIAL_OBJECT_FLAGS_
#define VSOL_SPATIAL_OBJECT_FLAGS_

// system flags
const unsigned int VSOL_UNIONBIT       = 0x80000000;
const unsigned int VSOL_SYSTEM_FLAG1   = 0x01000000;
// user flags
const unsigned int VSOL_FLAG1          = 0x40000000;
const unsigned int VSOL_FLAG2          = 0x20000000;
const unsigned int VSOL_FLAG3          = 0x1000000;
const unsigned int VSOL_FLAG4          = 0x08000000;
const unsigned int VSOL_FLAG5          = 0x04000000;
const unsigned int VSOL_FLAG6          = 0x02000000;

// mask for last three bytes of tag field
const unsigned int VSOL_DEXID_BITS     = 0x00FFFFFF;
const unsigned int VSOL_FLAG_BITS      = 0xFF000000;

#endif


class vsol_spatial_object_2d
  : public vbl_timestamp,
    public vbl_ref_count
{
// Data Members--------------------------------------------------------------
public:

  enum vsol_spatial_object_2d_type
  {
    SPATIAL_NO_TYPE=0,
    TOPOLOGYOBJECT,
    POINT,
    CURVE,
    REGION,
    SPATIALGROUP,
    NUM_SPATIALOBJECT_TYPES
  };
  static char *SpatialTypes[];
  static const float eps;
protected:

  vsol_box_2d *_bounding_box; // bounding volume
  unsigned int _tag; // for the COOL containers.
  int _id;
  static int _tagcount;// global count of all spatial objects.

protected:

// Constructors/Destructors--------------------------------------------------

  //: \brief constructors and destructors

  virtual ~vsol_spatial_object_2d();
  explicit vsol_spatial_object_2d(void);
  vsol_spatial_object_2d(const vsol_spatial_object_2d &other);
  virtual int not_applicable(const vcl_string &message) const;
public:

// Data Access---------------------------------------------------------------
  //: \brief get the spatial type

  virtual vsol_spatial_object_2d::vsol_spatial_object_2d_type
  spatial_type(void) const=0;

  virtual const char *get_name(void) const;

  //---------------------------------------------------------------------------
  //: compute bounding box, do nothing in this case
  //---------------------------------------------------------------------------
  virtual void compute_bounding_box(void);

  //: \brief get bounding box

  virtual vsol_box_2d *get_bounding_box(void);

  //: \brief get set id
  virtual int get_id(void) const
  {
    return _id;
  }
  virtual void set_id(int i)
  {
    _id = i;
  }

  //: \brief protect and unprotect

  virtual void un_protect(void)
  {
    ref_count--;
    iu_delete(this);
  }

  //---------------------------------------------------------------------------
  //: Clone `this': creation of a new object and initialization
  //: See Prototype pattern
  //---------------------------------------------------------------------------
  virtual vsol_spatial_object_2d_sptr clone(void) const=0;
#if 0
  virtual vsol_spatial_object_2d* SpatialCopy() { return (vsol_spatial_object_2d*) NULL; }
#endif
  // Tag Flag and ID methods

  //: \brief  set user flag 1-6
  inline void set_user_flag(unsigned int flag);
  inline unsigned int get_user_flag(unsigned int flag);
  inline void unset_user_flag(unsigned int flag);
  inline void set_tagged_union_flag(void);
  inline unsigned int get_tagged_union_flag(void);
  inline void unset_tagged_union_flag(void);
  inline int get_tag_id(void);
  inline void set_tag_id(int id);

  // inline void    SetFormat(char* f);

  // virtual SpatialGroup *  CastToSpatialGroup()   { return NULL;}
  // virtual SpatialGroup const* CastToSpatialGroup() const { return NULL;}

  //: \brief cast to topology object

  virtual vtol_topology_object_2d* cast_to_topology_object_2d() { return NULL;}

  //virtual GeometryObject* CastToGeometryObject() { return NULL;}
// Data Control--------------------------------------------------------------

public:

  //: \brief  protected destroy
  virtual void protected_destroy(void);

  //: \brief  Geometry Accessors
  virtual vcl_vector<double> *GetLocation(void)
  {
    return 0;
  }
  virtual vcl_vector<double> *GetOrientation(void)
  {
    return 0;
  }
  virtual vcl_vector<double> *GetSize(void)
  {
    return 0;
  }
  virtual vcl_vector<double> *GetScalar(void)
  {
    return 0;
  }

  const vcl_vector<double> *GetLocation(void) const
  {
    return ((vsol_spatial_object_2d *)this)->GetLocation();
  }
  const vcl_vector<double> *GetOrientation(void) const
  {
    return ((vsol_spatial_object_2d *)this)->GetOrientation();
  }
  const vcl_vector<double> *GetSize(void) const
  {
    return ((vsol_spatial_object_2d *)this)->GetSize();
  }
  const vcl_vector<double> *GetScalar(void) const
  {
    return ((vsol_spatial_object_2d *)this)->GetScalar();
  }

  virtual void SetLocation(float,
                           float)
  {
    not_applicable("SetLocation");
  }

  virtual void SetLocation(vcl_vector<double> &)
  {
    not_applicable("SetLocation");
  }

  virtual void SetOrientation(float,
                              float)
  {
    not_applicable("SetOrientation");
  }

  virtual void SetOrientation(vcl_vector<double> &)
  {
    not_applicable("SetOrientation");
  }

  virtual void SetSize(float,
                       float)
  {
    not_applicable("SetSize");
  }

  virtual void SetSize(vcl_vector<double> &)
  {
    not_applicable("SetSize");
  }

  virtual void SetScalar(float,
                         float)
  {
    not_applicable("SetScalar");
  }

  virtual void SetScalar(vcl_vector<double> &)
  {
    not_applicable("SetScalar");
  }

  virtual void UpdateGeometry(void)
  {
    not_applicable("UpdateGeometry");
  }

#if 0 // commented out
  virtual  vcl_vector<double>  *GetCog()  { return NULL; }
  const vcl_vector<double> *GetCog() const  { return ((vsol_spatial_object_2d*)this)->GetCog(); }

  //---- transformations ----------------------------------------------
  virtual bool Transform(CoolTransform const& m);
  virtual CoolTransform GetTransformation() const; // to `standard' object
  virtual bool LinearScale(float sf);   // leaving GetLocation() fixed

  virtual bool Translate();     // moving GetLocation() to (0,0,0)
  virtual bool Rotate();        // moving GetOrientation() to (1,0,0)
  virtual bool Reflect();       // around GetOrientation() over 180 degrees
  virtual bool Shear(float);    // leaving GetOrientation() fixed
#endif

  //: \brief bounding box accessors
  inline void check_update_bounding_box(void);  // Test consistency of bound
  // inline void get_min_location(vcl_vector<double>& min_loc);
  // inline void get_max_location(vcl_vector<double>& max_loc);
  inline float get_min_x(void);
  inline float get_max_x(void);
  inline float get_min_y(void);
  inline float get_max_y(void);
  virtual void set_min_x(float xmin);
  virtual void set_max_x(float xmax);
  virtual void set_min_y(float ymin);
  virtual void set_max_y(float ymax);

  //: \brief operators

  virtual bool operator==(const vsol_spatial_object_2d &obj) const
  {
    return this==&obj;
  }
  bool operator!=(vsol_spatial_object_2d &obj)
  {
    return !(*this==obj);
  }

  //-------------------------------------------------------------------------

  //---------------------------------------------------------------------------
  //: The same behavior than dynamic_cast<>. Needed because VXL is not
  //: compiled with -frtti :-(
  //---------------------------------------------------------------------------
  virtual const vsol_group_2d *cast_to_group(void) const;

  inline virtual void print(vcl_ostream &strm=vcl_cout) const;

  inline virtual void describe(vcl_ostream &strm=vcl_cout, int blanking=0) const;

  friend inline vcl_ostream &operator<<(vcl_ostream &,
                                    const vsol_spatial_object_2d &);
  friend inline vcl_ostream &operator<<(vcl_ostream &,
                                    const vsol_spatial_object_2d *);
};

// inline member functions

inline void vsol_spatial_object_2d::set_tag_id(int id)
{
  //     ( set the new id bits)  or (save just the flag bits from the _tag)
  _tag = ( (id & VSOL_DEXID_BITS)     |  ( _tag & VSOL_FLAG_BITS ));
}

//: Bounds Accessors:  min_ and max_ are provided as methods on vsol_spatial_object_2d
//                    to be consistent with the previous interface
//                    Additional bounds accessors are available directly
//                    on vsol_box_2d.  - JLM

inline void vsol_spatial_object_2d::check_update_bounding_box(void)  // Test consistency of bound
{
  if(_bounding_box==0)
    {
      _bounding_box = new vsol_box_2d;
      this->compute_bounding_box();
      _bounding_box->touch();
      return;
    }
  if(_bounding_box->older(this))
    { // NOTE: first touch then compute, to avoid infinite loop!! - PVr
      _bounding_box->touch();
      this->compute_bounding_box();
    }
}

inline vsol_box_2d *vsol_spatial_object_2d::get_bounding_box(void)
{
  this->check_update_bounding_box();
  return _bounding_box;
}

//inline void vsol_spatial_object_2d::get_min_location(vcl_vector<double>& min_loc)
//{
//  this->check_update_bounding_box();
//  _bounding_box->get_min_location(min_loc);
//}

//inline void vsol_spatial_object_2d::get_max_location(vcl_vector<double>& max_loc)
//{
//  this->check_update_bounding_box();
//  _bounding_box->get_max_location(max_loc);
//}

inline float vsol_spatial_object_2d::get_min_x(void)
{
  this->check_update_bounding_box();
  return _bounding_box->get_min_x();
}

inline float vsol_spatial_object_2d::get_max_x(void)
{
  this->check_update_bounding_box();
  return _bounding_box->get_max_x();
}

inline float vsol_spatial_object_2d::get_min_y(void)
{
  this->check_update_bounding_box();
  return _bounding_box->get_min_y();
}

inline float vsol_spatial_object_2d::get_max_y(void)
{
  this->check_update_bounding_box();
  return _bounding_box->get_max_y();
}

inline void vsol_spatial_object_2d::set_min_x(float xmin)
{
  if(!_bounding_box) _bounding_box = new vsol_box_2d;;
  _bounding_box->set_min_x(xmin);
}

inline void vsol_spatial_object_2d::set_max_x(float xmax)
{
  if(!_bounding_box) _bounding_box = new vsol_box_2d;;
  _bounding_box->set_max_x(xmax);
}

inline void vsol_spatial_object_2d::set_min_y(float ymin)
{
  if(!_bounding_box) _bounding_box = new vsol_box_2d;;
  _bounding_box->set_min_y(ymin);
}

inline void vsol_spatial_object_2d::set_max_y(float ymax)
{
  if(!_bounding_box) _bounding_box = new vsol_box_2d;;
  _bounding_box->set_max_y(ymax);
}


//: set a flag for a spatial object, flag can be VSOL_FLAG[1-6]
inline void vsol_spatial_object_2d::set_user_flag(unsigned int flag)
{
  _tag =  (_tag | flag);
}

//: get a flag for a spatial object,
//    flag can be VSOL_FLAG[1-6], return value is one or zero.
inline unsigned int  vsol_spatial_object_2d::get_user_flag(unsigned int flag)
{
  return (_tag & flag) ? 1 : 0;
}

//: set_ a flag for a spatialObject, flag can be VSOL_FLAG[1-6] value is
//    set to zero.
inline void vsol_spatial_object_2d::unset_user_flag(unsigned int flag)
{
  _tag = ( _tag & (~flag) );
}

//: set_ the flag used by TAGGED_UNION.
inline void vsol_spatial_object_2d::set_tagged_union_flag(void)
{
  set_user_flag(VSOL_UNIONBIT);
}

//: get_ the flag used by TAGGED_UNION.
inline unsigned int vsol_spatial_object_2d::get_tagged_union_flag(void)
{
  return get_user_flag(VSOL_UNIONBIT);
}

inline void vsol_spatial_object_2d::unset_tagged_union_flag()
{
  unset_user_flag(VSOL_UNIONBIT);
}

inline int vsol_spatial_object_2d::get_tag_id()
{
  return _tag & VSOL_DEXID_BITS;
}

inline void vsol_spatial_object_2d::print(vcl_ostream &strm) const
{
  describe(strm);
}

inline void vsol_spatial_object_2d::describe(vcl_ostream &strm,
                                             int blanking) const
{
  not_applicable("Describe");
  if (blanking < 0) blanking = 0;
  while (blanking--) strm << ' ';
}


inline vcl_ostream &operator<<(vcl_ostream &strm,
                           const vsol_spatial_object_2d &so)
{
  ((vsol_spatial_object_2d*)&so)->print(strm);
  return strm;
}

inline vcl_ostream &operator<<(vcl_ostream &strm,
                           const vsol_spatial_object_2d *so)
{
  if(so!=0)
    ((vsol_spatial_object_2d*)so)->print(strm);
  else
    strm << " NULL Spatial Object. ";
  return strm;
}

#endif // _vsol_spatial_object_2d_h_
