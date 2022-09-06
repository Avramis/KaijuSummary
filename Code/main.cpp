//
//  main.cpp
//  KaijuSummaryV2
//
//  Created by Avraam Tapinos on 25/06/2019.
//  Copyright © 2019 Avraam Tapinos. All rights reserved.
//

#include <iostream>
#include <sys/stat.h>
#include <stdio.h>

#include "processFiles.hpp"
/**/
 int main(int argc, const char * argv[]) {
    std::string infile, outfile;
    std::cout << "Initiate parsing arguments\n";
    int civ = (argc - 1) % 2;
    std::cout << argc << "Arguments have been provided.\n";
    if (civ || argc - 1 == 0) {
        std::cout << "> ERROR: Wrong number of paramaretes provided.\n";
        return 1;
    }
    else{
        for (int i = 1; i < argc; i += 2) {
            std::cout << argv[i] << " argument: " << argv[i+1] <<"\n";
            std::string inarq = argv[i];
            std::transform(inarq.begin(), inarq.end(), inarq.begin(), ::tolower);
            if ((std::string) (inarq) == "-i") {
                struct stat   buffer;
                if ((stat (argv[i + 1] , &buffer)) == -1)
                {
                    std::cout << argv[i + 1] << " cannont be found.";
                    return 1;
                };
                
                infile = argv[i + 1];
            }
            else if ((std::string) (inarq) == "-o") {
                outfile = argv[i + 1];
            }
        }
    }
    std::cout << "> Initiated file processing.\n";
    processFiles PF(infile, outfile);
    std::cout << "> File processing completed.\n";
    return 0;
}
 /**/


/*
 int main(int argc, const char * argv[]) {
     bool office = true;
     std::string username;
     if(office == true){
         username = "avraam";
     }
     else{
         username = "mqbssatj";
     }
     
     std::string indir = "/Users/" + username + "/Dropbox (The University of Manchester)/Xcode/ToFixCode/TaxonToolkitV0.0/Results/";
     std::string outdir = "/Users/" + username + "/Dropbox (The University of Manchester)/Xcode/ToFixCode/TaxonToolkitV0.0/Results/SummaryResults/";
     std::vector<std::string> IDs;
     IDs.push_back("119_B0");
     IDs.push_back("119_C1");
     IDs.push_back("430_B0");

     std::vector<std::string> insuf;
     std::vector<std::string> outsuf;
     
     //insuf.push_back("_Combined_Paired_DNA_dsCDNA_PE_Kaijukaijureport.out");
     //insuf.push_back("_Combined_UnPaired_DNA_dsCDNA_Kaijukaijureport.out");
     //outsuf.push_back("_Combined_Paired_UnPaired_DNA_dsCDNA_Kaiju.summary.out");
     //outsuf.push_back("_Combined_UnPaired__UnPaired_DNA_dsCDNA_Kaiju.summary.out");
     
     insuf.push_back("_Join_Paired_Unpaired_Datakaijureport.out");
     outsuf.push_back("_Join_Paired_Unpaired_Datakaijureport.summary.out");
     
     
 for (int i = 0; i < (int)IDs.size(); i++){
     for (int j = 0; j < (int)insuf.size(); j++){
         std::string infile, outfile;
         infile = indir + IDs[i] + insuf[j];
         outfile = outdir + IDs[i] + outsuf[j];
         std::cout << "|" << infile << "|\n";
         std::cout << "|" << outfile << "|\n";
         processFiles PF(infile, outfile);
     }
 }
 return 0;
 }
*/
