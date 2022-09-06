//
//  OTU.hpp
//  KaijuSummaryV2
//
//  Created by Avraam Tapinos on 25/06/2019.
//  Copyright © 2019 Avraam Tapinos. All rights reserved.
//

#ifndef OTU_hpp
#define OTU_hpp

#include <stdio.h>
#include <string>

class  OTU{
private:
    std::string taxaid, lineage;
    int readcount = 0;
public:
    ~OTU();
    OTU();
    OTU(std::string taxa, std::string lage);
    
    void countUP();
    void addTaxaI(std::string taxa);
    void addLineage(std::string lage);
    
    int returnCountUP();
    std::string returnTaxaID();
    std::string returnLineage();
};
#endif /* OTU_hpp */
