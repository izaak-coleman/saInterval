#ifndef C_DATASTRUCTURE_H
#define C_DATASTRUCTURE_H
#include <vector>
#include <string>

class C{
  /* C array from an FM-index. Classically used in conjuction with occ to
   * compute LF-mapping. Functions on C required for constructSAInterval
   * are included as member functions. */
private:
  std::vector<int64_t> c; // The C array.
  std::string alphabet;   // The alphabet that the string, t, is over.

  /* Constructs C array from t, and assigns to c.*/
  void computeC(std::string const& t);

public: 
  /* Calling computeC(), initialises c.*/
  C(std::string const &t, std::string const &a); 

  /* Returns alphabet[b], where c[b] is the largest element in c that is
   * less than or equal to saIdx. */
  char bucketChar(int64_t const saIdx) const;

  /* Returns the number of suffix array (SA) elements occuring in SA 
   * interval [0,saIdx) that represent a suffix begining with the same
   * character as T[SA[saIdx]]. */
  int64_t elementRank(int64_t const saIdx) const;

  /* Performs the classic C(s) operation outlined in FM-index;
   * where s is a character in the set alphabet, return the element
   * C[s] that is associated with that character. */
  int64_t operator() (char const s) const {
    return c[alphabet.find(s)];
  }
};
#endif

