/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Parser.cpp
 * Author: llazar
 * 
 * Created on 2016. november 15., 9:56
 */

#include <memory>
#include <float.h>

#include "Parser.h"
#include "Circle.h"


namespace geom {

Parser::Parser() {
}

Parser::Parser(const Parser& orig) {
}

Parser::~Parser() {
}

void Parser::parseLine(const std::string& line)
{
    std::shared_ptr<Geom2D> pNode;
    std::vector<std::string> tokens;
    tokenizeString(line, " ,\t", tokens);
    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i].compare("CIRCLE") == 0) {
            
            pNode.reset(new Circle());
        }
    }
    
}



bool Parser::isNumber(const double x) 
{
    return (x == x); 
}

bool Parser::isFiniteNumber(double x) 
{
    return (x <= DBL_MAX && x >= -DBL_MAX); 
}

bool Parser::isNumber(const std::string& strnumber) 
{
    bool ret = true;
    try {
        double x = std::stod(strnumber);
    } catch(const std::invalid_argument& ia) {            
        ret = false;
    }
    return ret;
}

void Parser::tokenizeString(const std::string &text, const std::string& delimiters, std::vector<std::string>& tokens, bool delTokens)
{
    size_t pos = 0, lastpos = 0;
    if (delTokens)
        tokens.clear();

    while (true) {
        pos = text.find_first_not_of(delimiters, lastpos);
        if (pos == std::string::npos)
            break;
        lastpos = pos;
        pos = text.find_first_of(delimiters, lastpos);
        if (pos == std::string::npos) {
            if (text.size() - lastpos > 0)
                tokens.push_back(text.substr(lastpos, text.size() - lastpos));
            break;
        }
        tokens.push_back(text.substr(lastpos, pos - lastpos));
        lastpos = pos;
    }
}



}
