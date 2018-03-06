#include <string>
#include <iostream>
#include "computeBWT.h"
#include "utils.h"
#include "Occ.h"
#include "CDataStructure.h"

using namespace std;
string const SIGMA = "$ACGT";

int main() {
  string text;
  char in;
  while (cin >> in) text += in;
  cout << text << endl;
  string bwt(computeBWT(text));
  cout << bwt << endl;
  C c(text, SIGMA);
  for (int64_t i = 0; i < text.size(); ++i) {
    cout << c.bucketChar(i) << '\t' << c.elementRank(i) << endl;
  }
  return 0;
}

