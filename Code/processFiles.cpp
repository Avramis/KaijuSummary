//
//  processFiles.cpp
//  KaijuTaxa_V0.0
//
//  Created by Avraam Tapinos on 11/10/2018.
//  Copyright © 2018 Avraam Tapinos. All rights reserved.
//

#include "processFiles.hpp"
processFiles::~processFiles(){};

processFiles::processFiles(){};

processFiles::processFiles(std::string infile, std::string outfile){
    //KaijuTaxaParser(std::string infile, std::map<std::string, int> *taxasummary, int *toread, int *clasread, int *unclaread);
    std::map<std::string, OTU> taxasummary;
    int toread = 0, clasread = 0, unclaread = 0;
    std::cout << "Process taxonomic calassifications.\n";
    KaijuTaxaParser KP(infile, &taxasummary, &toread, &clasread, &unclaread);
    std::cout << "Processing taxonomic calassifications completed.\n";
    std::cout << "> Genrating summary file.\n";
    generateTaxaReport GTR(outfile, &taxasummary, &toread, &clasread, &unclaread);
    std::cout << "> Summary file completed.\n";
};



