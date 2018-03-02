#include "computeC.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int64_t> computeC(string const &text, string const & alphabet) {
  vector<int64_t> C(alphabet.length(), 0);
  for(string::const_iterator it = text.cbegin(); it < text.cend(); ++it) {
    ++C[alphabet.find(*it)];
  }
  return C;
}

