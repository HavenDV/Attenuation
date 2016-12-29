/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SemiCircle.h
 * Author: llazar
 *
 * Created on 2016. november 9., 9:52
 */

#ifndef SEMICIRCLE_H
#define SEMICIRCLE_H

#include "Circle.h"


namespace geom {
    


class SemiCircle : public Circle {
protected:
    CVector2D normal;   //center -> midpoint
public:
    SemiCircle();
    SemiCircle(const CVector2D& center0, const double r0, const CVector2D& p1, const CVector2D& p2);    //
    
        
    SemiCircle(const SemiCircle& orig);
    virtual ~SemiCircle();
    
    CVector2D getStartPoint() const {
        CVector2D ret(normal);
        ret.rotate270();
        ret += center;
        return ret;
    }
    
    CVector2D getEndPoint() const {
        CVector2D ret(normal);
        ret.rotate90();
        ret += center;
        return ret;
    }
    
    virtual bool containsPoint(const CVector2D &p) const;
    
    virtual Angle getFieldOfView(const CVector2D& p0) const;
    
//    virtual std::string toSvg(const float stroke_width = 1.0f, std::string color = "#000000") override;
    
    virtual std::string toSvg(const std::string & css_class_name = "" ) const;
    

private:

};

}

#endif /* SEMICIRCLE_H */

