#include <string>
#include <vector>
#include "computeOcc.h"
using namespace std;

vector< vector<int64_t> > computeOcc(string const & bwt, string const& alphabet)
{
  vector< vector<int64_t> > occ(alphabet.size(), vector<int64_t>(bwt.size(), 0));
  for (size_t i = 0; i < alphabet.size(); ++i) {
    compute_occ_row(alphabet[i], bwt, occ[i]);
  }
  return occ;
}

void compute_occ_row(char c, string const& bwt, vector<int64_t> & occ_row) {
  int64_t occ = 0;
  for(size_t i = 0; i < bwt.size(); ++i) {
    if (bwt[i] == c) ++occ;
    occ_row[i] = occ;
  }
}
