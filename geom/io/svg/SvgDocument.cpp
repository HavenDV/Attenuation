/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SvgDocument.cpp
 * Author: llazar
 * 
 * Created on 2016. november 24., 13:50
 */

#include <fstream>
#include <memory>

#include "SvgDocument.h"
#include "../../../util/StringUtils.h"


namespace geom {
namespace io {    
namespace svg { 

SvgDocument::SvgDocument(int width, int height, const std::string & cssfile) 
        : m_Width(width), m_Height(height)
        , m_CssFileName(cssfile) 
{
}


SvgDocument::~SvgDocument() {
    close();
}

void SvgDocument::open(const std::string& filename, std::ios_base::openmode __mode)
{
    m_FileName = filename;
    m_File.open(m_FileName, __mode);
    writeHeader();
}
void SvgDocument::close()
{
    if (m_File.is_open()) {
        writeFooter();    
        m_File.close();
    }
}


void SvgDocument::writeHeader()
{
    m_File << "<?xml version=\"1.0\" standalone=\"no\"?>\n";
    m_File << "<svg xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\"  "
                    << "height=\"" << m_Height << "\" width=\"" << m_Width << "\" style=\"border:1px solid #000000;\">\n";
    
    if (!m_CssFileName.empty()) {
        m_File << "<style type=\"text/css\"><![CDATA[\n";
        std::string css;
        StringUtils::readFromFile(m_CssFileName, css);
        m_File << css;
        m_File << "]]></style>\n\n";
    }
    
    if (m_pGroup.get() != NULL) {
        m_File << m_pGroup->toSvg();
    }
}

void SvgDocument::writeFooter()
{
    if (m_pGroup.get() != NULL) {
        m_File << m_pGroup->closeTag();
    }
    m_File << "</svg>";
}

}
}
}

