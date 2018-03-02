#include <vector>
using namespace std;

std::vector<int64_t> computeSigmaBuckets(std::vector<int64_t> const & C) {
  vector<int64_t> sigma = C;
  for(size_t i = 1; i < C.size(); ++i) {
    sigma[i] = sigma[i-1] + C[i];
  }
  sigma[0] = 0;
  return sigma;
}
