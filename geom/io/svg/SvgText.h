/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SvgText.h
 * Author: llazar
 *
 * Created on 2016. november 28., 14:21
 */

#ifndef SVGTEXT_H
#define SVGTEXT_H

#include "SvgElement.h"

namespace geom {
namespace io {    
namespace svg { 

class SvgText : public SvgElement
{
private:
    SvgPoint _position;
    std::string _text;
public:
    SvgText(const SvgPoint & p0, const std::string & text0 ) : SvgElement("text"),
        _position(p0), _text(text0)        
    { }
        
    virtual std::string toSvg() const {
        std::stringstream ss;
        ss << elemStart() << attribute("x", _position.x)
            << attribute("y", _position.y)
            << attributes()
            << " >"
            << _text
            << elemEnd();
        return ss.str();
    }
    void offset(SvgPoint const & offset)
    {
        _position.x += offset.x;
        _position.y += offset.y;
    }

};

}
}
}


#endif /* SVGTEXT_H */

