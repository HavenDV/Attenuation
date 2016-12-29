/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Angle.h
 * Author: llazar
 *
 * Created on 2016. november 9., 10:16
 */

#ifndef ANGLE_H
#define ANGLE_H

#include "Geom2D.h"

namespace geom {

class Angle : public Geom2D {
protected:
    CVector2D vertex;
    CVector2D arm1;
    CVector2D arm2;
public:
    //Angle() {}
    Angle(const CVector2D &p0, const CVector2D& dir1, const CVector2D& dir2);
    Angle(const Angle& orig);
    virtual ~Angle();
    
    virtual void translate(const CVector2D &translation) { vertex.translate(translation); } 
    
    virtual bool containsPoint(const CVector2D &p) const;
    void addArm(const CVector2D& arm);
    
    CVector2D getArm1() const { return arm1; }
    CVector2D getArm2() const { return arm2; }
    CVector2D getVertex() const { return vertex; }


    
private:

};

}

#endif /* ANGLE_H */

