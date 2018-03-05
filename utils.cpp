#include <string>
#include "utils.h"

using namespace std;

int64_t termCharIndex(std::string const& bwt, char const t) {
  int64_t i = 0;
  while (i < bwt.size() && bwt[i] != t) ++i;
  return i;
}

char bucketChar(int64_t const saIdx, vector<int64_t> const & C, string
    const & alphabet) {
  int64_t b = 0;
  while (b < C.size() && saIdx >= C[b]) ++b;
  return alphabet[--b];
}

int64_t elementRank(int64_t const saIdx, vector<int64_t> const & C) {
  int64_t b = 0;
  while (b < C.size() && saIdx >= C[b]) ++b;
  return saIdx - C[--b];
}

int64_t occElement(char const c, int64_t const idx, string const & alphabet,
    vector<vector<int64_t> > const & occ) {
  return occ[alphabet.find(c)][idx];
}

int64_t cElement(char c, std::vector<int64_t> const & C, std::string const & alphabet) {
  return C[alphabet.find(c)];
}

