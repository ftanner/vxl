#include "vsol_tetrahedron.h"

//:
//  \file

//*****************************************************************************
// External declarations for implementation
//*****************************************************************************
#include <vcl_cassert.h>
#include <vcl_cmath.h> // for vcl_abs(double)
#include "vsol_point_3d.h"

//***************************************************************************
// Initialization
//***************************************************************************

//---------------------------------------------------------------------------
//: Constructor from its 4 vertices
//---------------------------------------------------------------------------
vsol_tetrahedron::vsol_tetrahedron(const vsol_point_3d_sptr &new_p0,
                                   const vsol_point_3d_sptr &new_p1,
                                   const vsol_point_3d_sptr &new_p2,
                                   const vsol_point_3d_sptr &new_p3)
{
//storage_.reserve(4); // DO NOT DO THIS!  calls unimplemented default constructor of vsol_point_3d; causes memory fault on Alpha
  storage_.push_back(new_p0);
  storage_.push_back(new_p1);
  storage_.push_back(new_p2);
  storage_.push_back(new_p3);
}

//---------------------------------------------------------------------------
// Copy constructor
//---------------------------------------------------------------------------
vsol_tetrahedron::vsol_tetrahedron(const vsol_tetrahedron &other)
  : vsol_polyhedron(other)
{
}

//***************************************************************************
// Access
//***************************************************************************

//---------------------------------------------------------------------------
//: Return the first vertex
//---------------------------------------------------------------------------
vsol_point_3d_sptr vsol_tetrahedron::p0(void) const
{
  return storage_[0];
}

//---------------------------------------------------------------------------
//: Return the second vertex
//---------------------------------------------------------------------------
vsol_point_3d_sptr vsol_tetrahedron::p1(void) const
{
  return storage_[1];
}

//---------------------------------------------------------------------------
//: Return the third vertex
//---------------------------------------------------------------------------
vsol_point_3d_sptr vsol_tetrahedron::p2(void) const
{
  return storage_[2];
}

//---------------------------------------------------------------------------
//: Return the last vertex
//---------------------------------------------------------------------------
vsol_point_3d_sptr vsol_tetrahedron::p3(void) const
{
  return storage_[3];
}

//***************************************************************************
// Comparison
//***************************************************************************

//---------------------------------------------------------------------------
//: Has `this' the same points than `other' in the same order ?
//---------------------------------------------------------------------------
bool vsol_tetrahedron::operator==(const vsol_tetrahedron &other) const
{
  return vsol_polyhedron::operator==(other);
}

bool vsol_tetrahedron::operator==(const vsol_polyhedron &other) const
{
  return vsol_polyhedron::operator==(other);
}

//: spatial object equality

bool vsol_tetrahedron::operator==(const vsol_spatial_object_3d& obj) const
{
  return
   obj.spatial_type() == vsol_spatial_object_3d::VOLUME &&
   ((vsol_volume_3d const&)obj).volume_type() == vsol_volume_3d::POLYHEDRON
  ? *this == (vsol_polyhedron const&) (vsol_volume_3d const&) obj
  : false;
}

//***************************************************************************
// Status report
//***************************************************************************

//---------------------------------------------------------------------------
//: Return the volume of `this'
//---------------------------------------------------------------------------
double vsol_tetrahedron::volume(void) const
{
  double dx01=storage_[0]->x()-storage_[1]->x();
  double dy01=storage_[0]->y()-storage_[1]->y();
  double dz01=storage_[0]->z()-storage_[1]->z();
  double dx12=storage_[1]->x()-storage_[2]->x();
  double dy12=storage_[1]->y()-storage_[2]->y();
  double dz12=storage_[1]->z()-storage_[2]->z();
  double dx23=storage_[2]->x()-storage_[3]->x();
  double dy23=storage_[2]->y()-storage_[3]->y();
  double dz23=storage_[2]->z()-storage_[3]->z();
  return vcl_abs(dx23*(dy01*dz12-dy12*dz01)
                +dy23*(dz01*dx12-dz12*dx01)
                +dz23*(dx01*dy12-dx12*dy01))/6;
}
//***************************************************************************
// Element change
//***************************************************************************

//---------------------------------------------------------------------------
//: Set the first vertex
//---------------------------------------------------------------------------
void vsol_tetrahedron::set_p0(vsol_point_3d_sptr new_p0)
{
  storage_[0]=new_p0;
  touch();
}

//---------------------------------------------------------------------------
//: Set the second vertex
//---------------------------------------------------------------------------
void vsol_tetrahedron::set_p1(vsol_point_3d_sptr new_p1)
{
  storage_[1]=new_p1;
  touch();
}

//---------------------------------------------------------------------------
//: Set the third vertex
//---------------------------------------------------------------------------
void vsol_tetrahedron::set_p2(vsol_point_3d_sptr new_p2)
{
  storage_[2]=new_p2;
  touch();
}

//---------------------------------------------------------------------------
//: Set the last vertex
//---------------------------------------------------------------------------
void vsol_tetrahedron::set_p3(vsol_point_3d_sptr new_p3)
{
  storage_[3]=new_p3;
  touch();
}

//***************************************************************************
// Basic operations
//***************************************************************************

//---------------------------------------------------------------------------
//: Is `p' in `this' ?
//---------------------------------------------------------------------------
bool vsol_tetrahedron::in(vsol_point_3d const& p) const
{
  // TODO
  vcl_cerr << "Warning: vsol_tetrahedron::in() has not been implemented yet\n";
  return true;
}
