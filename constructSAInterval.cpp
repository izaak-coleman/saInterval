#include <string>
#include <vector>
#include "constructSAInterval.h"
#include "Occ.h"
#include "CDataStructure.h"
using namespace std;

vector<int64_t> constructSAInterval(string const& bwt, C const & c, Occ const &
    occ,  int64_t const dollarPos, int64_t i, int64_t const j) {
  vector<int64_t> sa(j-i, -1);
  for (; i < j; ++i) {
    char phi = c.bucketChar(i);
    int64_t r = c.elementRank(i);
    sa[i] = computeSAElement(bwt, c, dollarPos, phi, r, occ);
  }
  return sa;
}

int64_t computeSAElement(string const& bwt, C const& c,  int64_t const 
    dollarPos, char const phi, int64_t const r, Occ const & occ) {
  int64_t lfCount{0}, pos{dollarPos};
  int64_t currentRank = occ(bwt[pos], pos) - 1;
  while (bwt[pos] != phi || currentRank != r) {
    pos = c(bwt[pos]) + currentRank;
    ++lfCount;
    currentRank = occ(bwt[pos], pos) - 1;
  }
  return bwt.size() - lfCount - 1;
}

