#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
int64_t termCharIndex(std::string const& bwt, char const t);

char bucketChar(int64_t const saIdx, std::vector<int64_t> const & buckets, std::string const & alphabet);

int64_t elementRank(int64_t const saIdx, std::vector<int64_t> const & buckets);

int64_t occElement(char const c, int64_t const idx, std::string const & alphabet, 
    std::vector<std::vector<int64_t> > const & occ);

int64_t cElement(char c, std::vector<int64_t> const & C, std::string const &
    alphabet);
#endif
