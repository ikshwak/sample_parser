=====================================================================
==============SOURCE FILES===========================================
fileOp.cpp and fileOp.hpp -- defines file operations
parser.cpp and parser.hpp -- defines string parsing and evaluation
constants.hpp             -- defines constant values
main.cpp                  -- executes the program
=====================================================================
===============BUILD INSTRUCTIONS====================================
1. copy the sources to a local directory
2. from command shell run the following command.
	>> g++ -std=c++11 main.cpp fileOp.cpp parser.cpp -o output
3. output.exe is generated in the same directory.
=====================================================================
================TESTING==============================================
1. copy the test files to the same directory as the output.exe
2. from command shell run the following command.
	>> output.exe <test file name>
	for example>> output.exe test.txt
=====================================================================
======================OUTPUT FORMAT==================================
the output is printed to the console in the following format.

*********************************************************************
location=16
offset=7
origin=8
random=2
sometest=19

*********************************************************************