#include <iostream>
#include <string>

#include "fileOp.hpp"
#include "parser.hpp"
#include "constants.hpp"


int main(int argc, char **argv)
{
    if(argc != MAX_PARAMETERS)
    {
        std::cout << "Invalid number of arguments \n";
        return FAILURE;
    }
    else
    {
        if(argv[1] == INVALID_FIE_NAME)
        {
            std::cout << "Invalid file name \n";
            return FAILURE;
        }

        /*Read equations from file and store each equation*/
        FileOp *fp = new FileOp(argv[1]);
        if(fp)
        {
            fp->getEqFromFile();

            int eqCount = (int)(fp->getEqCount());
            Parser *pp = new Parser();
            while(eqCount--)
            {
                int retVal;
                std::string eq = fp->getNextEq();
                /*Parse the equation and validate*/
                retVal = pp->parseEq(eq);
            }
            /*evaluate the equations and store the value*/
            pp->evalEq();
            /*Print the sorted out put of the list of variables used*/
            pp->printValues();
            delete pp;
            delete fp;
        }
    }

    return SUCCESS;
}
