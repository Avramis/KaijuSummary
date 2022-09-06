//
//  processFiles.hpp
//  KaijuTaxa_V0.0
//
//  Created by Avraam Tapinos on 11/10/2018.
//  Copyright © 2018 Avraam Tapinos. All rights reserved.
//

#ifndef processFiles_hpp
#define processFiles_hpp
#include <iostream>
#include <stdio.h>
#include <string>
#include <map>

#include "KaijuTaxaParser.hpp"
#include "generateTaxaReport.hpp"
#include "OTU.hpp"
class processFiles{
private:
public:
    ~processFiles();
    processFiles();
    processFiles(std::string infile, std::string outfile);
};
#endif /* processFiles_hpp */
