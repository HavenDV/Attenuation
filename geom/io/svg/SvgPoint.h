/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SvgPoint.h
 * Author: llazar
 *
 * Created on 2016. november 25., 13:27
 */

#ifndef SVGPOINT_H
#define SVGPOINT_H

namespace geom {
namespace io {    
namespace svg { 

class SvgPoint {    
public:
    double x;
    double y;
public:
    SvgPoint(double x = 0, double y = 0) : x(x), y(y) { }
    
    SvgPoint operator+(const SvgPoint &v) const {
        return SvgPoint(x + v.x, y + v.y);
    }

    SvgPoint &operator+=(const SvgPoint &v) {
        x += v.x;
        y += v.y;
        return *this;
    }

    SvgPoint operator-(const SvgPoint &v) const {
        return SvgPoint(x - v.x, y - v.y);
    }

    SvgPoint &operator-=(const SvgPoint &v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }
        
};

}
}
}

#endif /* SVGPOINT_H */

