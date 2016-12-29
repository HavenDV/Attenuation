/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Renderer.h
 * Author: llazar
 *
 * Created on 2016. november 25., 22:37
 */

#ifndef RENDERER_H
#define RENDERER_H

#include "SvgPoint.h"


namespace geom {
namespace io {    
namespace svg { 

class Layout {
public:
    SvgPoint point;    //bottom-left
    SvgPoint range;
public:
    Layout(const double x0, const double y0, const double rx0, const double ry0) : point(x0, y0), range(rx0, ry0) {}
    Layout(const SvgPoint& p0, const SvgPoint& range0) : point(p0), range(range0) {}
    
};

class Renderer
{
protected:
    Layout world;
    Layout viewport;
    
    int margin;
    
    CVector2D scale; 
public: 
    
    Renderer(const Layout& world0, const Layout& viewport0, int margin0) :
        world(world0), viewport(viewport0), margin(margin0),
        scale((viewport.range.x - 2*margin0) / world.range.x, (viewport.range.y - 2*margin0) / world.range.y)
    {
    }
    
    SvgPoint operator()(const SvgPoint& p) const {
        return this->operator ()(p.x, p.y);
    }
        
    SvgPoint operator()(const double x0, const double y0) const {
        SvgPoint point(x0, y0);
        SvgPoint ret(point - world.point);
        ret.x *= scale.x;
        ret.y *= -scale.y;
        ret += viewport.point;
        SvgPoint m(margin, viewport.range.y - margin);
        ret += m;
        return ret;
    }    
    
    Layout getWorld() const {
        return world;
    }

    CVector2D getScale() const {
        return scale;
    }

    
//    double X(double x0) {
//        
//        return (x0 - xmin) * scalex;
//    }
//    
//    double Y(double y0) {
//        return (y0 - ymin) * scaley;
//    }
    
};

}
}
}


#endif /* RENDERER_H */

