// OK, really big hack, if the compiler sees
// bvector, then it causes undefined symbols of the type
// bvec_iterator, so we hide the bvector.h file from the compiler,
// and it does not seem to need it, as it shouldn't since we don't
// want a bvec here!  
#define __SGI_STL_BVECTOR_H
#include <vcl/vcl_algorithm.txx>
#include <vcl/vcl_vector.txx>

VCL_VECTOR_INSTANTIATE(unsigned int);
VCL_FIND_INSTANTIATE(vcl_vector<unsigned>::iterator, unsigned);
VCL_FIND_INSTANTIATE(vcl_vector<unsigned>::const_iterator, unsigned);
