#include <vector>
using namespace std;

std::vector<int64_t> computeSigmaBuckets(std::vector<int64_t> const & C) {
  vector<int64_t> sigma = C;
  sigma[0] = 0;
  for(size_t i = 1; i < C.size(); ++i) {
    sigma[i] = sigma[i-1] + C[i-1];
  }
  return sigma;
}
