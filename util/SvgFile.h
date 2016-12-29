/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SvgFile.h
 * Author: llazar
 *
 * Created on 2016. november 15., 9:13
 */

#ifndef SVGFILE_H
#define SVGFILE_H

#include <istream>
#include <ostream>

class SvgFile {
protected:
    std::ofstream m_SvgFile;
public:
    SvgFile();
    SvgFile(const SvgFile& orig);
    virtual ~SvgFile();
    
    void open(const char* __s, std::ios_base::openmode __mode = std::ios_base::out | std::ios_base::trunc);
private:

};

#endif /* SVGFILE_H */

