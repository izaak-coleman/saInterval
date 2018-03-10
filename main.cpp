#include <string>
#include <iostream>
#include "computeBWT.h"
#include "utils.h"
#include "Occ.h"
#include "CDataStructure.h"
#include "constructSAInterval.h"
#include <fstream>

using namespace std;
string const SIGMA = "$ACGT";

string readFile(string fname) {
  string dump, line;
  ifstream fin(fname);
  while (getline(fin, line)) {
    dump += line;
  } 
  fin.close();
  return dump;
}

int main(int argc, char** argv) {
  string text = readFile(argv[1]);
  cout << text.size() << endl;
  string bwt(computeBWT(text));
  Occ occ(bwt, SIGMA);
  cout << "begin sa construction" << endl;
  C c(text, SIGMA);
  int64_t dollarPos = termCharIndex(bwt, '$');
  vector<int64_t> sa = constructSAInterval(bwt, c, occ, dollarPos, 0,
      text.size());
  //START(divsufSort);
  //vector<int64_t> sa = computeSA(text);
  //COMP(divsufSort);
  //ofstream of("saInterval_sa.txt");
  //for (int64_t i : sa) {
  //  of << i << '\n';
  //}
  //of << endl;
  //of.close();
  //cout << endl;

  //vector<int64_t> div_sa = computeSA(text);
  return 0;
}

