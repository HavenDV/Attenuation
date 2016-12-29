/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SvgLine.h
 * Author: llazar
 *
 * Created on 2016. november 25., 13:45
 */

#ifndef SVGLINE_H
#define SVGLINE_H

#include "SvgPoint.h"
#include "SvgElement.h"

namespace geom {
namespace io {    
namespace svg { 

class SvgLine : public SvgElement
{
private:
    SvgPoint start_point;
    SvgPoint end_point;
public:
    SvgLine(const SvgPoint & start_point0, const SvgPoint & end_point0 ) : 
        SvgElement("line"),
        start_point(start_point0),
        end_point(end_point0) { }
        
    virtual std::string toSvg() const {
        std::stringstream ss;
        ss << elemStart() << attribute("x1", start_point.x)
            << attribute("y1", start_point.y)
            << attribute("x2", end_point.x)
            << attribute("y2", end_point.y)
            << attributes()
            << emptyElemEnd();
        return ss.str();
    }
    void offset(SvgPoint const & offset)
    {
        start_point.x += offset.x;
        start_point.y += offset.y;

        end_point.x += offset.x;
        end_point.y += offset.y;
    }

};


}
}
}


#endif /* SVGLINE_H */

