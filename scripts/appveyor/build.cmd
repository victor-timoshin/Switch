rem ____________________________________________________________________________
rem                                                           generate and build
mkdir build
cd build
cmake -G "%BUILD_OPTION%" .. -DBUILD_SWITCH_TESTS=ON
cmake --build . --config Debug
cd ..
