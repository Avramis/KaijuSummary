//
//  KaijuTaxaParser.cpp
//  KaijuTaxa_V0.0
//
//  Created by Avraam Tapinos on 11/10/2018.
//  Copyright © 2018 Avraam Tapinos. All rights reserved.
//

#include "KaijuTaxaParser.hpp"
void KaijuTaxaParser::parseLine(std::string lineContents, std::string *taxa, std::string *lineage){
    size_t fidx = lineContents.find_first_of("\t");
    lineContents = lineContents.substr(fidx+1);
    fidx = lineContents.find_first_of("\t");
    (*taxa) =  lineContents.substr(0, fidx);
    lineContents = lineContents.substr(fidx+1);
    fidx = lineContents.find_last_of("\t");
    (*lineage) = lineContents.substr(fidx+1);
}

KaijuTaxaParser::~KaijuTaxaParser(){};

KaijuTaxaParser::KaijuTaxaParser(){};

KaijuTaxaParser::KaijuTaxaParser(std::string infile, std::map<std::string, OTU> *taxasummary, int *toread, int *clasread, int *unclaread){
    std::ifstream fulltaxafile(infile);
    std::string lineContents = "";
    while(!fulltaxafile.eof()){
        getline(fulltaxafile, lineContents);
        (*toread)++;
        
        if(lineContents.substr(0,1) == "U"){
            (*unclaread)++;
        }
        else if(lineContents.substr(0,1) == "C"){
            (*clasread)++;
            
            std::string taxa, lineage;
            parseLine(lineContents.substr(2), &taxa, &lineage);
            if((*taxasummary).find(taxa) != (*taxasummary).end()){
                (*taxasummary)[taxa].countUP();
            }
            else{
                OTU otu(taxa, lineage);
                (*taxasummary)[taxa] = otu;
            }
        }
        else{
            (*toread)--;
        }
    }
    fulltaxafile.close();
};
