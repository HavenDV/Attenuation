/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SvgFile.cpp
 * Author: llazar
 * 
 * Created on 2016. november 15., 9:13
 */

#include <fstream>

#include "SvgFile.h"

SvgFile::SvgFile() {
}

SvgFile::SvgFile(const SvgFile& orig) {
}

SvgFile::~SvgFile() {
}

void SvgFile::open(const char* __s, std::ios_base::openmode __mode)
{
    m_SvgFile.open(__s, __mode);
}

