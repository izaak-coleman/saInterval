#include <vector>
#include <string>
#include "Occ.h"
using namespace std;

Occ::Occ(string const & bwt, string const & a) {
  alphabet = a;
  computeOcc(bwt);
}

void Occ::computeOcc(string const & bwt) {
  vector<vector<int64_t> > o(alphabet.size(), vector<int64_t>(bwt.size(), 0));
  for(int64_t i = 0; i < alphabet.size(); ++i) {
    computeOccColumn(alphabet[i], bwt, o[i]);
  }
  occ = o;
}

void Occ::computeOccColumn(char c, string const & bwt, vector<int64_t> & col) {
  int64_t occ = 0;
  for(size_t i = 0; i < bwt.size(); ++i) {
    if (bwt[i] == c) ++occ;
    occ_row[i] = occ;
  }
}
