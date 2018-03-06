#include <string>
#include "utils.h"

using namespace std;

int64_t termCharIndex(std::string const& bwt, char const t) {
  int64_t i = 0;
  while (i < bwt.size() && bwt[i] != t) ++i;
  return i;
}

