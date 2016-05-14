#include <iostream>
#include <algorithm>

#include "parser.hpp"
#include "constants.hpp"

int Parser::parseEq(std::string & equation)
{
    std::string LHS;
    std::string RHS;
    std::size_t found = equation.find_first_of(EQUALSTO);
    if(found != std::string::npos)
    {
        LHS = equation.substr(0,found);
        if((isVariable(LHS) == false))
        {
            return FAILURE;
        }
        RHS = equation.substr(found+1);
        if((isExpresion(LHS, RHS) == false))
        {
            return FAILURE;
        }
        varList.push_back(LHS);
    }
    else
    {
        return FAILURE;
    }

    return SUCCESS;
}

bool Parser::isVariable(std::string &LHS)
{
    for (int i=0; i<LHS.length(); ++i)
    {
        int ch = LHS[i];
        if(std::isspace(ch))
        {
            continue;
        }
        if(!(std::isalpha(ch)))
        {
            return false;
        }
    }
    trimString(LHS);
    return true;
}

void Parser::trimString(std::string &Val)
{
    Val.erase( std::remove_if( Val.begin(), Val.end(), ::isspace ), Val.end() );
}

bool Parser::isExpresion(std::string &key, std::string &val)
{
    trimString(val);
    std::vector<std::string> *valList = new std::vector<std::string>();
    std::string temp = val;
    std::string value;
    std::size_t found = temp.find_first_of('+');
    while(found != std::string::npos)
    {
        value = temp.substr(0, found);
        temp = temp.substr(found+1);
        found = temp.find_first_of('+');
        valList->push_back(value);
    }

    valList->push_back(temp);

    eqMap[key] = *valList;
    return true;
}

void Parser::evalEq()
{
    if(!eqMap.empty())
    {
        for(int i = 0; i < varList.size(); i++)
        {
            std::string keyVal = varList[i];
            std::vector<std::string> valList = eqMap[keyVal];
            int count = 0;
            int value = 0;
            while(count < valList.size())
            {
                if(std::isdigit(valList[count][0]))
                {
                    value += std::stoi(valList[count]);
                }
                count++;
            }
            eqValues[keyVal] = value;
        }
        for(int i = 0; i < varList.size(); i++)
        {
            std::string keyVal = varList[i];
            std::vector<std::string> valList = eqMap[keyVal];
            int count = 0;
            int value = eqValues[keyVal];
            while(count < valList.size())
            {
                if(!(std::isdigit(valList[count][0])))
                {
                    value += eqValues[valList[count]];
                    eqValues.erase(keyVal);
                    eqValues[keyVal] = value;
                }
                count++;
            }
        }
    }
}

void Parser::printValues()
{
    /*sort the vector using standard sorting algorithm */

    if(!(varList.empty()))
    {
        std::sort(varList.begin(), varList.end());
    }
    std::cout << "\n*********************************************************************\n";

    if(!(eqValues.empty()))
    {
        for(int i = 0; i < varList.size(); i++)
        {
            std::cout << varList[i] << "=" << eqValues[varList[i]] << "\n";
        }
    }
    std::cout << "\n*********************************************************************\n";
}
