/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StringUtils.h
 * Author: llazar
 *
 * Created on 2016. november 15., 21:22
 */

#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <iterator>
#include <sstream>

class StringUtils {
public:
    StringUtils();
    StringUtils(const StringUtils& orig);
    virtual ~StringUtils();
    
    static std::string formatNumber(const char* format, double number);
    static void replace(std::string& str, std::string& key, std::string& value);
    
    
    static void readFromFile(const std::string & filename, std::string & outString);
    
//    template< typename T >
    //static std::string join( const std::vector<T>& values, const std::string& delimiter );
    
private:

};

template< class T >
std::string join( const std::vector<T>& values, const std::string& delimiter )
{
    std::stringstream result;
    std::copy(values.begin(), values.end(), std::ostream_iterator<T>(result, delimiter.c_str()));
    return result.str();
}

#endif /* STRINGUTILS_H */

