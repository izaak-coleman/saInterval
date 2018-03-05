#include "computeC.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int64_t> computeC(string const &text, string const & alphabet) {
  vector<int64_t> count(alphabet.length(), 0);
  for(string::const_iterator it = text.cbegin(); it < text.cend(); ++it) {
    ++count[alphabet.find(*it)];
  }
  vector<int64_t> C = count;
  C[0] = 0;
  for (int64_t i = 1; i < count.size(); ++i) {
    C[i] = count[i-1] + C[i-1];
  }
  return C;
}

