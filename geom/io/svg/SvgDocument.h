/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SvgDocument.h
 * Author: llazar
 *
 * Created on 2016. november 24., 13:50
 */

#ifndef SVGDOCUMENT_H
#define SVGDOCUMENT_H

#include <string>

#include "Transformation.h"
//#include "../../CVector2D.h"
#include <vector>
#include <fstream>

namespace geom {
namespace io {    
namespace svg { 
    


class SvgGroup
{
protected:
    std::vector<std::shared_ptr<Transformation> > m_Transformations;
    std::shared_ptr<SvgGroup> m_pGroup;
    
public:
    SvgGroup() { }
    
    void addTransformation(Transformation * ptr) {
        std::shared_ptr<Transformation> sptr(ptr);
        m_Transformations.push_back(sptr);
    }
    
    virtual std::string toSvg(const std::string& css_class_name = "") const {
        std::stringstream ss;
        ss << "<g id=\"renderer\" ";
        if (!m_Transformations.empty()) {
            ss << "transform=\"";
            for (const std::shared_ptr<Transformation> & tr : m_Transformations ) {
                ss << tr->toSvg();
            }
            ss << "\"";
        }
        ss << ">\n";
        return ss.str();
    }
    
    virtual std::string closeTag() const {
        return "</g>\n";
    }
};
    
class SvgDocument {
protected:
    std::string m_FileName;
    std::string m_CssFileName;
    
    int m_Width;
    int m_Height;
    
    std::shared_ptr<SvgGroup> m_pGroup;
    
    std::ofstream m_File;
public:
    SvgDocument() { }
    SvgDocument(int width, int height, const std::string & cssfile = "");
    virtual ~SvgDocument();
    
    void open(const std::string& filename, std::ios_base::openmode __mode = std::ios_base::out | std::ios_base::trunc);
    void close();
    
    std::shared_ptr<SvgGroup> createGroup() {
        if (m_pGroup.get() == NULL) {
            m_pGroup.reset(new SvgGroup);
        }
        return m_pGroup;
    }
    
    SvgDocument& operator<<(const std::string & str)
    { 
        m_File << str;
        return *this;
    }
    
    int getHeight() const {
        return m_Height;
    }

    void setHeight(int Height) {
        m_Height = Height;
    }

    int getWidth() const {
        return m_Width;
    }

    void setWidth(int Width) {
        m_Width = Width;
    }

    void setCssFileName(const std::string& CssFileName) {
        m_CssFileName = CssFileName;
    }

    
protected:
    void writeHeader();
    void writeFooter();
};

}
}
}

#endif /* SVGDOCUMENT_H */

