#ifndef COMPUTE_SA_ELEMENT_H
#define COMPUTE_SA_ELEMENT_H
#include <string>
#include <vector>
#include "Occ.h"
#include "CDataStructure.h"
int64_t computeSAElement(std::string const& bwt, C const & c, 
        int64_t const dollarPos, char const phi, int64_t const r, 
        Occ const & occ);

std::vector<int64_t> constructSAInterval(std::string const& bwt, C const & c, 
                     Occ const & occ, int64_t const dollarPos, int64_t i,
                     int64_t const j);
#endif

