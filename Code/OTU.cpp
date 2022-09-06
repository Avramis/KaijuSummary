//
//  OTU.cpp
//  KaijuSummaryV2
//
//  Created by Avraam Tapinos on 25/06/2019.
//  Copyright © 2019 Avraam Tapinos. All rights reserved.
//

#include "OTU.hpp"
OTU::~OTU(){};
OTU::OTU(){};
OTU::OTU(std::string taxa, std::string lage){
    countUP();
    addTaxaI(taxa);
    addLineage(lage);
};

void OTU::countUP(){
    readcount++;
};

void OTU::addTaxaI(std::string taxa){
    taxaid = taxa;
};

void OTU::addLineage(std::string lage){
    lineage = lage;
};

int OTU::returnCountUP(){
    return readcount;
};

std::string OTU::returnTaxaID(){
    return taxaid;
};

std::string OTU::returnLineage(){
    return lineage;
};
