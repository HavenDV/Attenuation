/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ellipse.h
 * Author: llazar
 *
 * Created on 2016. november 18., 23:30
 */

#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Geom2D.h"
#include "CVector2D.h"


namespace geom {

class Ellipse : public Geom2D {
protected:
    CVector2D center;
    double radiusX, radiusY;
public:
    Ellipse(const double x0, const double y0, const double a0, const double b0) : center(x0, y0), radiusX(a0), radiusY(b0) {  }
    Ellipse(const CVector2D& center0, const double a0, const double b0) : center(center0), radiusX(a0), radiusY(b0) { }
    Ellipse(const Ellipse &ellipse) : center(ellipse.center), radiusX(ellipse.radiusX), radiusY(ellipse.radiusY) {}
    virtual ~Ellipse();
    
    CVector2D getCenter() const { return center; }
    
    virtual void translate(const CVector2D &translation) {
        center += translation;
    }
    
    virtual bool containsPoint(const CVector2D &p) const {
        double a = getSemiMajor();
        double b = getSemiMinor();
        double f = a * a - b * b;
        CVector2D f1(center), f2(center);
        if (radiusX >= radiusY) {
            f1.x -= f;
            f2.x += f;
        } else {
            f1.y -= f;
            f2.y += f;
        }
        return ((p - f1).length() + (p - f2).length()) <= 2.0 * a;        
    }
    
    double getSemiMajor() const { return radiusX >= radiusY ? radiusX : radiusY; }
    double getSemiMinor() const { return radiusX < radiusY ? radiusX : radiusY; }
    
    double getRadiusX() const { return radiusX; }
    double getRadiusY() const { return radiusY; }
    
//    virtual std::string toSvg(const float stroke_width = 1.0f, std::string color = "#000000");
    
    virtual std::string toSvg(const std::string & css_class_name = "" ) const;
    
private:
    
    
    
    

};

}

#endif /* ELLIPSE_H */

