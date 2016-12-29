/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Parser.h
 * Author: llazar
 *
 * Created on 2016. november 15., 9:56
 */

#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

namespace geom {

class Parser {
public:
    Parser();
    Parser(const Parser& orig);
    virtual ~Parser();
    
    void tokenizeString(const std::string &text, const std::string& delimiters, std::vector<std::string>& tokens, bool delTokens = true);
    bool isNumber(const double x);
    bool isFiniteNumber(double x);
    bool isNumber(const std::string& strnumber);

protected:
    void parseLine(const std::string& text);
};

}

#endif /* PARSER_H */

