#!/bin/bash

# ______________________________________________________________________________
#                                                        format code with AStyle
pushd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=~/usr/local -DCMAKE_CXX_COMPILER=clang++-3.9
cmake --build . --target Format
if [ $? -ne 0 ]; then exit -1; fi 
popd

# ______________________________________________________________________________
#                                           check file changed and display error
if [[ -n $(git diff) ]]; then
  echo "You must run make format before submitting a pull request"
  echo ""
  git diff
  exit -1
fi
