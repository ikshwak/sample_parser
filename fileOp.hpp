#ifndef FILEOP_H_INCLUDED
#define FILEOP_H_INCLUDED

#include <fstream>
#include <vector>

class FileOp
{
public:
    FileOp(char *fileName);
    void getEqFromFile();
    std::string &getNextEq();
    size_t getEqCount();
private:
    char *fNm;
    std::string equation;
    int eqCount = 0;
    std::vector<std::string> eqList;
    std::filebuf  *fileBuf;
    std::ifstream fileHandler;
};

#endif // FILEOP_H_INCLUDED
