#!/bin/bash
 module load compilers/intel/17.0.7

echo '#############################################'
echo '#                                           #'
echo '#      Compiling Kaiju Taxa Summary...      #'
echo '#                   INTEL                   #'
echo '#                                           #'
echo '#############################################'
echo ' '

cwd=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"/Code/"
cd $cwd

icpc -Wall -O3 -std=c++11 -o KaijuSummary *.cpp

mv KaijuSummary ../Exec

echo ' '
echo '#############################################'
echo '#                                           #'
echo '# Compiling Kaiju Taxa Summary completed... #'
echo '#                                           #'
echo '#############################################'
