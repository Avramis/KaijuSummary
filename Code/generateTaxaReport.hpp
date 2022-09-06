//
//  generateTaxaReport.hpp
//  KaijuTaxa_V0.0
//
//  Created by Avraam Tapinos on 11/10/2018.
//  Copyright © 2018 Avraam Tapinos. All rights reserved.
//

#ifndef generateTaxaReport_hpp
#define generateTaxaReport_hpp

#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>

#include "OTU.hpp"
class generateTaxaReport{
private:
    static bool compairPairs(const std::pair<int, OTU> lhs , std::pair<int, OTU> rhs);
public:
    ~generateTaxaReport();
    generateTaxaReport();
    generateTaxaReport(std::string outfile, std::map<std::string, OTU> *taxasummary, int *toread, int *clasread, int *unclaread);
};
#endif /* generateTaxaReport_hpp */
