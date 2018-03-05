#include <vector>
#include <string>
#include "computeBWT.h"
#include "divsufsort64.h"

using namespace std;

string computeBWT(string const& text) {
  string bwt(text.size(), '\0');
  int64_t * sa = new int64_t [text.size()];
  divsufsort64((uint8_t*)const_cast<char*>(text.c_str()), sa, text.size());
  for (size_t i = 0; i < text.size(); ++i) {
    if (sa[i] != 0) {
      bwt[i] = text[sa[i]-1];
    }
    else {
      bwt[i] = text[text.size()-1]; // Term char
    }
  }
  delete [] sa;
  return bwt;
}

