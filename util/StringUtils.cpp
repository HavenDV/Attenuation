/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StringUtils.cpp
 * Author: llazar
 * 
 * Created on 2016. november 15., 21:22
 */

#include <stdio.h>
#include <string>
#include <fstream>
#include <streambuf>
#include <vector>

#include <sstream>

#include "StringUtils.h"

StringUtils::StringUtils() {
}

StringUtils::StringUtils(const StringUtils& orig) {
}

StringUtils::~StringUtils() {
}

std::string StringUtils::formatNumber(const char* format, double number)
{
    const int buf_length = 64;
    char buffer[buf_length];
    buffer[0] = '\0';
    snprintf(buffer, buf_length, format, number);
    std::string ret(buffer);
    return ret;
}

void StringUtils::readFromFile(const std::string & filename, std::string & outString)
{
    outString.clear();
    std::ifstream t(filename);
    t.seekg(0, std::ios::end);   
    outString.reserve(t.tellg());
    t.seekg(0, std::ios::beg);
    outString.assign((std::istreambuf_iterator<char>(t)),  std::istreambuf_iterator<char>());
}

void StringUtils::replace(std::string& str, std::string& key, std::string& value)
{
    size_t pos = str.find(key);
    if (pos != std::string::npos) {
        str.replace(pos, key.size(), value);
    }
}




