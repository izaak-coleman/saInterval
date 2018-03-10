#include <string>
#include <vector>
#include <algorithm> // std::fill
#include "constructSAInterval.h"
#include "Occ.h"
#include "CDataStructure.h"
#include <iostream>
using namespace std;

static const int64_t EMPTY = -1;

vector<int64_t> constructSAInterval(string const& bwt, C const & c, Occ const &
    occ,  int64_t const dollarPos, int64_t i, int64_t const j) {
  vector<int64_t> sa(j-i, EMPTY);
  char currentBucket = c.bucketChar(i);
  vector<int64_t> memo(c.bucketSize(currentBucket), EMPTY);
  furthestLFMap f(dollarPos, 0);
  for (; i < j; ++i) {
    char phi = c.bucketChar(i);
    int64_t r = c.elementRank(i);
    if (phi != currentBucket) {
      memo.resize(c.bucketSize(phi), EMPTY);
      std::fill(memo.begin(), memo.end(), EMPTY);
      currentBucket = phi;
      f.pos = dollarPos;
      f.lfCount = 0;
    }
    sa[i] = computeSAElement(bwt, c, dollarPos, phi, r, occ, memo, f);
  }
  return sa;
}

int64_t computeSAElement(string const& bwt, C const& c,  int64_t const 
    dollarPos, char const phi, int64_t const r, Occ const & occ,
    vector<int64_t> & memo, furthestLFMap & furthest) {
  if (memo[r] != -1) {
    return memo[r];
  }
  int64_t lfCount{furthest.lfCount}, pos{furthest.pos};
  int64_t currentRank = occ(bwt[pos], pos) - 1;
  while (bwt[pos] != phi || currentRank != r) {
    pos = c(bwt[pos]) + currentRank;
    ++lfCount;
    currentRank = occ(bwt[pos], pos) - 1;
    if (memo[currentRank] == EMPTY && bwt[pos] == phi && currentRank != r){
        memo[currentRank] = bwt.size() - lfCount - 1;
    }
  }
  memo[currentRank] = bwt.size() - lfCount - 1;
  if (lfCount > furthest.lfCount) {
    furthest.pos = pos;
    furthest.lfCount = lfCount;
  }
  return bwt.size() - lfCount - 1;
}

