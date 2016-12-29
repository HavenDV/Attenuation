/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Angle.cpp
 * Author: llazar
 * 
 * Created on 2016. november 9., 10:16
 */

#include "Angle.h"

namespace geom {

Angle::Angle(const CVector2D &p0, const CVector2D& dir1, const CVector2D& dir2) : vertex(p0)
{
    if (dir1.cross(dir2) < 0) {
        arm1 = dir2;
        arm2 = dir1;
    } else {
        arm1 = dir1;
        arm2 = dir2;
    }
}

Angle::Angle(const Angle& orig) {
}

Angle::~Angle() {
}

bool Angle::containsPoint(const CVector2D &p) const
{
    CVector2D pp(p - vertex);
    return arm1.cross(pp) >= 0.0 && arm2.cross(pp) <= 0.0;
}

void Angle::addArm(const CVector2D& arm)
{
    double side1 = arm1.cross(arm);
    double side2 = arm2.cross(arm);
    if (side1 > 0.0 && side2 > 0.0) {
        arm2 = arm;
    } else if (side1 < 0.0 && side2 < 0.0) {
        arm1 = arm;
    }
}

}