#include <iostream>

#include "fileOp.hpp"

FileOp::FileOp(char* filename)
{
    if(filename)
    {
        fNm = filename;
    }
}

void FileOp::getEqFromFile()
{
    std::ifstream fileHandler(fNm, std::ifstream::in);

    while(std::getline(fileHandler, equation))
    {
        eqList.push_back(equation);
    }
}

std::string &FileOp::getNextEq()
{
   if((eqList.size() !=0 ) && (eqCount < eqList.size()))
   {
       return eqList[eqCount++];
   }
}

size_t FileOp::getEqCount()
{
    return eqList.size();
}

