/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SemiCircle.cpp
 * Author: llazar
 * 
 * Created on 2016. november 9., 9:52
 */

#include "SemiCircle.h"
#include "Angle.h"
#include "Segment.h"
#include <sstream>

namespace geom {

SemiCircle::SemiCircle() {
}

//SemiCircle::SemiCircle(const CVector2D& center0, const double r0, const CVector2D& direction0) :
//    Circle(center0, r0), normal(direction0)
//{
//    normal.normalize();
//    normal.scale(r0);
//}

SemiCircle::SemiCircle(const CVector2D& center0, const double r0, const CVector2D& p1, const CVector2D& p2) : 
        Circle(center0, r0)
{
    CVector2D r1(p1 - center0);
    CVector2D r2(p2 - center0);
    if (r1.cross(r2) < 0) {
        r1 = r2;
    }
    r1.normalize();
    r1.scale(r0);
    r1.rotate90();
    this->normal = r1;
}

SemiCircle::SemiCircle(const SemiCircle& orig) {
}

SemiCircle::~SemiCircle() {
}

Angle SemiCircle::getFieldOfView(const CVector2D& p0) const
{
    Angle circleField = Circle::getFieldOfView(p0);
    CVector2D v(normal);
    
    Segment diamater(getStartPoint(), getEndPoint());
    Angle diameterField = diamater.getFieldOfView(p0);
    
    CVector2D pc = center - p0;
    bool normal_is_left = NumericComparator::isPositive(pc.cross(normal));
    CVector2D c_arm1 = circleField.getArm1();
    CVector2D c_arm2 = circleField.getArm2();
    bool c_arm1_left = NumericComparator::isPositive(pc.cross(c_arm1));
//    bool c_arm2_left = NumericComparator::isPositive(pc.cross(c_arm2));
    if (normal_is_left) {
        if (c_arm1_left) {
            diameterField.addArm(c_arm1);
        } else {
            diameterField.addArm(c_arm1);
        }
    } else {
        if (!c_arm1_left) {
            diameterField.addArm(c_arm1);
        } else {
            diameterField.addArm(c_arm1);
        }
    }
   
    
    return diameterField;
}

bool SemiCircle::containsPoint(const CVector2D &p) const
{
    bool isInCircle = Circle::containsPoint(p);
    if (isInCircle) {
        return NumericComparator::isNonNegative((p - center).dot(normal));
    }
    return false;
}

//std::string SemiCircle::toSvg(const float stroke_width, std::string color) 
//{
//    //<path d="M100,-80  A80,80 0 0,1 100,80" style="stroke: #000000; stroke-width:2; fill:none;"/>
//    std::stringstream ss;
//    CVector2D startPoint = getStartPoint();
//    CVector2D endPoint = getEndPoint();
//    ss << "<path d=\"M" << startPoint.x << "," << startPoint.y << 
//        "  A" << radius << "," << radius << " 0 0,1 " << endPoint.x << "," << endPoint.y << 
//        "\" style=\"stroke: " << color << "; stroke-width:" << stroke_width << "; fill:none;\" /> \n";
//    return ss.str();
//}

std::string SemiCircle::toSvg(const std::string & css_class_name) const
{
    std::stringstream ss;
    CVector2D startPoint = getStartPoint();
    CVector2D endPoint = getEndPoint();
    ss << "\t<path d=\"M" << startPoint.x << "," << startPoint.y << 
        "  A" << radius << "," << radius << " 0 0,1 " << endPoint.x << "," << endPoint.y << 
        "\" class=\"" << css_class_name << "\"  />\n";
    return ss.str();    
}

}
