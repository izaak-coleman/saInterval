#ifndef OCC_H
#define OCC_H
#include <vector>
#include <string>

class Occ {
  /* occ array from an FM-index. Classically used in conjunction with C to 
   * compute LF-mapping. Class supports classic occ(c, idx) operation. */
private:
  std::vector<vector<int64_t> > occ; // occ array.
  std::string alphabet;              // Alphabet that string bwt is over.

  /* Constructs occ from bwt, and assigns to this->occ. */
  void computeOcc(std::string const & bwt, std::string const& alphabet);

  /* Helper f() for computeOcc(). */
  void computeOccColumn(char c, std::string const & bwt, std::vector<int64_t> & col);

public:
  /* Calling computeOcc(), initialises occ. */
  Occ(std::string const & bwt, std::string const & a);

  /* Support for occ(c, idx) operation: Where c is a character from the set
   * alphabet, selects the column in occ associated with c and returns the
   * integer at index idx of that column. */
  int64_t operator() (char const c, int64_t const idx) {
    return occ[alphabet.find(c)][idx];
  }
};
#endif
