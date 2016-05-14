#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <string>
#include <map>
#include <vector>

class Parser
{
public:
    int parseEq(std::string & equation);
    void evalEq();
    void printValues();
private:
    std::vector<std::string> varList;
    std::map< std::string, std::vector<std::string> > eqMap;
    std::map<std::string, int> eqValues;
    bool isExpresion(std::string &key, std::string &val);
    bool isVariable(std::string &val);
    void trimString(std::string &val);
};

#endif // PARSER_H_INCLUDED
