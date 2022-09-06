//
//  generateTaxaReport.cpp
//  KaijuTaxa_V0.0
//
//  Created by Avraam Tapinos on 11/10/2018.
//  Copyright © 2018 Avraam Tapinos. All rights reserved.
//

#include "generateTaxaReport.hpp"
bool generateTaxaReport::compairPairs(const std::pair<int, OTU> lhs , std::pair<int, OTU> rhs){
  return lhs.first > rhs.first;
};

generateTaxaReport::~generateTaxaReport(){};

generateTaxaReport::generateTaxaReport(){};

generateTaxaReport::generateTaxaReport(std::string outfile, std::map<std::string, OTU> *taxasummary, int *toread, int *clasread, int *unclaread){
  std::vector<std::pair<int, OTU>> taxaReport;
  std::map<std::string, OTU>::iterator it;
  std::cout << "> Sorting taxonomies (based on number of hits).";
  while(!(*taxasummary).empty()){
    it = (*taxasummary).begin();
    taxaReport.push_back(std::make_pair(it->second.returnCountUP(), it->second));
    (*taxasummary).erase(it->first);
  }
  std::cout<< "> Sorting completed.\n";
  std::sort(taxaReport.begin(), taxaReport.end(), compairPairs);
  std::ofstream fout(outfile);
  fout << "|Reads|\t|Reads/Total Number of Reads|\t|Reads/Classified Number of Reads|\t|taxaID|\t|Species lineage|\n";
  fout << "---------------------------------------------------------------------------------------------------------------------------------------------------\n";
  for (int i = 0; i < (int)taxaReport.size(); i++){
    fout << (taxaReport[i].second.returnCountUP()) << "\t" << (double)(taxaReport[i].second.returnCountUP()) / (double)(*toread) << "\t" << (double)(taxaReport[i].second.returnCountUP()) / (double)(*clasread) << "\t" << taxaReport[i].second.returnTaxaID() << "\t" <<  taxaReport[i].second.returnLineage() << "\n";
  }
  fout << "---------------------------------------------------------------------------------------------------------------------------------------------------\n";
    fout << (*unclaread) << "\t" << ((double)(*unclaread) * 100.0) / (double)(*toread) << "\t" << "-" << "\t" << "-" << "\t" << 0 << "\t" << "cannot be assigned to a species\n";
  fout << "Total number of reads: " << (*toread) << "\n";
  fout << "---------------------------------------------------------------------------------------------------------------------------------------------------\n";
  fout.close();
   //std::vector<std::pair<int, OTU>>().swap(taxaReport);
};

