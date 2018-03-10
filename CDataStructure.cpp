#include <vector>
#include <string>
#include "CDataStructure.h"
using namespace std;

C::C(std::string const & t, std::string const & a) {
  alphabet = a;
  computeC(t);
  sz_t = t.size();
}

void C::computeC(string const & t) {
  vector<int64_t> count(alphabet.length(), 0);
  for(string::const_iterator it = t.cbegin(); it < t.cend(); ++it) {
    ++count[alphabet.find(*it)];
  }
  c = count;
  c[0] = 0;
  for (int64_t i = 1; i < count.size(); ++i) {
    c[i] = count[i-1] + c[i-1];
  }
}

char C::bucketChar(int64_t const saIdx) const {
  int64_t b = 0; // bucket index
  while (b < c.size() && saIdx >= c[b]) ++b;
  return alphabet[--b];
}

int64_t C::elementRank(int64_t const saIdx) const {
  int64_t b = 0; // bucket index
  while (b < c.size() && saIdx >= c[b]) ++b;
  return saIdx - c[--b];
}

int64_t C::bucketSize(char const s) const {
  if(alphabet.find(s) == alphabet.size() -1) {
    return sz_t - c[alphabet.find(s)];
  }
  else {
    return c[alphabet.find(s) + 1] - c[alphabet.find(s)];
  }
}
