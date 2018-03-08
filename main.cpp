#include <string>
#include <iostream>
#include "computeBWT.h"
#include "utils.h"
#include "Occ.h"
#include "CDataStructure.h"
#include "constructSAInterval.h"

using namespace std;
string const SIGMA = "$ACGT";

int main() {
  string text;
  char in;
  while (cin >> in) text += in;
  string bwt(computeBWT(text));

  cout << text << endl;
  cout << bwt << endl;

  C c(text, SIGMA);
  Occ occ(bwt, SIGMA);
  int64_t dollarPos = termCharIndex(bwt, '$');
  vector<int64_t> sa = constructSAInterval(bwt, c, occ, dollarPos, 0, text.size());
  for (int64_t i : sa) {
    cout << i << '\t' << text.substr(i) << endl;
  }
  return 0;
}

