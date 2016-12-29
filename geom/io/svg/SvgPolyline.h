/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SvgPolyline.h
 * Author: llazar
 *
 * Created on 2016. november 25., 23:16
 */

#ifndef SVGPOLYLINE_H
#define SVGPOLYLINE_H

#include "SvgElement.h"


namespace geom {
namespace io {    
namespace svg { 
 
class SvgPolyline : public SvgElement
{
public:
    SvgPolyline() : SvgElement("polyline")
    { }
    
    SvgPolyline(std::vector<SvgPoint> const & points)
        : SvgElement("polyline"), points(points) { }
    
    SvgPolyline & operator<<(SvgPoint const & point)
    {
        points.push_back(point);
        return *this;
    }
    virtual std::string toSvg(const std::string& css_class_name = "") const  {
        std::stringstream ss;
        ss << elemStart();
        ss << "points=\"";
        for (unsigned i = 0; i < points.size(); ++i)
            ss << points[i].x << "," << points[i].y << " ";
        ss << "\" ";
        ss << attributes();
        ss << emptyElemEnd();
        return ss.str();
    }
    void offset(SvgPoint const & offset)
    {
        for (unsigned i = 0; i < points.size(); ++i) {
            points[i].x += offset.x;
            points[i].y += offset.y;
        }
    }
    std::vector<SvgPoint> points;
};
    
}
}    
}
#endif /* SVGPOLYLINE_H */

