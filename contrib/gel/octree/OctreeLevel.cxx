// This is gel/octree/OctreeLevel.cxx
#ifdef VCL_NEEDS_PRAGMA_INTERFACE
#pragma implementation
#endif
//:
// \file
// \author
// Author: Geoffrey Cross, Oxford RRG
// Created: 11 May 99
// Modifications:
//   990511 Geoff Initial version.
//
//-----------------------------------------------------------------------------

#include <iostream>
#include "OctreeLevel.h"
#include <vcl_compiler.h>

// Default ctor
OctreeLevel::OctreeLevel( const int d) :
  depth( d),
  size( d<0 ? 0 : (1<<d)),
  color( size, size, size),
  next( VXL_NULLPTR),
  prev( VXL_NULLPTR)
{
  std::cout << "Size = " << size << std::endl;
}


OctreeLevel::OctreeLevel( OctreeLevel *p) :
  depth( p->GetDepth()+1),
  size( 1<<depth),
  color( size, size, size),
  next( VXL_NULLPTR),
  prev( p)
{
  prev->SetNext( this);
  std::cout << "Size = " << size << std::endl;
}

void OctreeLevel::InheritFromAbove()
{
  if (!prev)
    {
      // TODO
    }
  else
    {
      // TODO
    }
}

