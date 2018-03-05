#include <string>
#include <iostream>
#include "computeC.h"
#include "computeSigmaBuckets.h"
#include "computeBWT.h"
#include "utils.h"
#include "computeSA.h"
#include "computeOcc.h"
#include "constructSAInterval.h"


using namespace std;

int main() {
  string text;
  char c;
  while (cin >> c) text += c;
  cout << text << endl;
  string bwt(computeBWT(text));
  cout << bwt << endl;
  vector<int64_t> C = computeC(text, "$ACGT");
  for (int64_t i : C) {cout << i << endl;}
  vector<vector<int64_t> > occ = computeOcc(bwt, "$ACGT");
  vector<int64_t> sa_div = computeSA(text);
  for (int64_t i : sa_div) {
    cout << text.substr(i) << endl;
  }
  int64_t dollarPos = termCharIndex(bwt, '$');
  vector<int64_t> sa = constructSAInterval(bwt, C, occ, dollarPos, 0,
      text.size());
  for (int64_t i : sa) {
    cout << text.substr(i) << endl;
  }


  return 0;
}

