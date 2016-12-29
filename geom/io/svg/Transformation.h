/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Transformation.h
 * Author: llazar
 *
 * Created on 2016. november 24., 14:29
 */

#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "../../CVector2D.h"
#include <sstream>

namespace geom {
namespace io {    
namespace svg { 
    
class Transformation
{
public:
    Transformation() {}
    virtual ~Transformation() { }
    
    virtual std::string toSvg() const = 0;
    
    //void transform() = 0;
};

class Translation : public Transformation
{
protected:
    CVector2D translate;
public:
    Translation(const double x0, const double y0) : translate(x0, y0) {}
    virtual ~Translation() { }
    
    virtual std::string toSvg() const {
        std::stringstream ss;
        ss << "translate(" << translate.x << ", " << translate.y << ") ";
        return ss.str();
    }
    
};

class Scale : public Transformation
{
protected:
    CVector2D scale;
public:
    Scale(const double x0, const double y0) : scale(x0, y0)  {}
    virtual ~Scale() { }
    
    virtual std::string toSvg() const {
        std::stringstream ss;
        ss << "scale(" << scale.x << ", " << scale.y << ") ";
        return ss.str();
    }
    
};
    
}
}
}


#endif /* TRANSFORMATION_H */

