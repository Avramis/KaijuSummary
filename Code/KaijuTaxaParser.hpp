//
//  KaijuTaxaParser.hpp
//  KaijuTaxa_V0.0
//
//  Created by Avraam Tapinos on 11/10/2018.
//  Copyright © 2018 Avraam Tapinos. All rights reserved.
//

#ifndef KaijuTaxaParser_hpp
#define KaijuTaxaParser_hpp

#include <stdio.h>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

#include <iostream>
#include "OTU.hpp"
class KaijuTaxaParser{
private:
    void parseLine(std::string lineContents, std::string *taxa, std::string *lineage);
public:
    ~KaijuTaxaParser();
    KaijuTaxaParser();
    KaijuTaxaParser(std::string infile, std::map<std::string, OTU> *taxasummary, int *toread, int *clasread, int *unclaread);
};
#endif /* KaijuTaxaParser_hpp */
