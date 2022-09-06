#!/bin/bash
module load compilers/gcc/6.4.0

echo '#############################################'
echo '#                                           #'
echo '#      Compiling Kaiju Taxa Summary...      #'
echo '#                    GCC                    #'
echo '#                                           #'
echo '#############################################'
echo ' '

cwd=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"/Code/"
cd $cwd

g++ -Wall -O3 -std=c++11 -o KaijuSummary *.cpp

mv KaijuSummary ../Exec

echo ' '
echo '#############################################'
echo '#                                           #'
echo '# Compiling Kaiju Taxa Summary completed... #'
echo '#                                           #'
echo '#############################################'

