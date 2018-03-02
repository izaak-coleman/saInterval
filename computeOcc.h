#ifndef COMPUTE_OCC
#define COMPUTE_OCC
#include <string>
#include <vector>

std::vector< std::vector<int64_t> > computeOcc(std::string const & bwt, std::string const& alphabet);
void computeOcc(char c, std::string const& bwt, std::vector<int64_t> & occ_row);
#endif
