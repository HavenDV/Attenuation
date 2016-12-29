/*
 * Circle.cpp
 *
 *  Created on: 2016. nov. 4.
 *      Author: Laszlo Lazar
 */

#include "Circle.h"
#include "Line.h"
#include "Angle.h"

#include <math.h> 
#include <sstream>

namespace geom {

Circle::~Circle() {

}

bool Circle::intersectionCircleLine(const Line &line, std::vector<CVector2D> &intersection_points) const
{
    bool ret = false;
    CVector2D tr(center);
    tr.rotate180();
    Circle circle(*this);
    circle.translate(tr);
    
    Line tempLine(line);
    tempLine.translate(tr);
    
    CVector2D dir = tempLine.getDirection();
    
    CVector2D result1, result2;
    
    double c = tempLine.getPoint().cross(dir);
    double r2 = getSqrRadius();
    double t3 = dir.x * dir.x;
    double t5 = dir.y * dir.y;
    double t9 = c * c;
    if (fabs(dir.y) > fabs(dir.x)) {    //steep line
        double t7 = t5 * t5;
        double discriminator = r2 * t3 * t5 + r2 * t7 - t9 * t5;
        if (discriminator >= 0) {            
            double t12 = sqrt(discriminator);
            result1.y = (-c * dir.x + t12) / (t3 + t5);
            result2.y = -(c * dir.x + t12) / (t3 + t5);
            
            //x = (v1*y+c)/v2
            result1.x = (dir.x * result1.y + c) / dir.y;
            result2.x = (dir.x * result2.y + c) / dir.y;
            
            ret = true;
        }        
    } else {
        double t4 = t3 * t3;
        double discriminator = r2 * t3 * t5 + r2 * t4 - t9 * t3;
        if (discriminator >= 0) {            
            double t12 = sqrt(discriminator);
            result1.x = (c * dir.y + t12) / (t3 + t5);
            result2.x = -(-c * dir.y + t12) / (t3 + t5);

            //(v2*x - c)/v1
            result1.y = (dir.y * result1.x - c) / dir.x;
            result2.y = (dir.y * result2.x - c) / dir.x;
            ret = true;
            
        }        
    }
    if (ret) {
        result1.translate(center);
        result2.translate(center);
        
        intersection_points.push_back(result1);
        intersection_points.push_back(result2);
    }
    return ret;
}

bool Circle::intersectionCircleCircle(const Circle &other, std::vector<CVector2D> &intersection_points) const
{
    CVector2D tr(other.center);
    tr.rotate180();
    Circle circle1(*this);
    circle1.translate(tr);
    Circle circle2(other);
    circle2.translate(tr);
    
    double c = circle2.getSqrRadius() - circle1.getSqrRadius() + circle1.getCenter().dot(circle1.getCenter());
    Line line(2.0 * circle1.getCenter().x, 2.0 * circle1.getCenter().y, c);    // c = r2^2 - r1^2 + c1.x^2 + c1.y^2
    
    bool ret = circle2.intersectionCircleLine(line, intersection_points);

    tr.rotate180();
    for(std::vector<CVector2D>::iterator it = intersection_points.begin(); it != intersection_points.end(); ++it) {
        it->translate(tr);
        std::cout << *it << std::endl;
    }
    return ret;
}

Angle Circle::getFieldOfView(const CVector2D& p0) const
{
    CVector2D cp(p0 - center);
    cp *= 0.5;
    
    CVector2D centerThalesCircle(center + cp);
    
    Circle thalesCircle(centerThalesCircle.x, centerThalesCircle.y, cp.length());
    
    std::vector<CVector2D> intersectionPoints;
    this->intersectionCircleCircle(thalesCircle, intersectionPoints);
    
    CVector2D arm1(intersectionPoints[0] - p0);
    CVector2D arm2(intersectionPoints[1] - p0);
    Angle ret(p0, arm1, arm2);
    return ret;
}

bool Circle::containsPoint(const CVector2D &p) const
{
    return NumericComparator::LessThanOrEqual((p - center).length2(), getSqrRadius());
}

//std::string Circle::toSvg(const float stroke_width, std::string color)
//{
//    //<circle cx="50" cy="50" r="40" stroke="black" stroke-width="3" fill="red" />
//    std::stringstream ss;
//    ss << "<circle cx=\"" << center.x << "\" cy=\"" << center.y << "\" r=\"" << radius 
//            << "\" stroke=\"" << color  << "\" stroke-width=\"" << stroke_width << "\" fill=\"none\"  />\n";
//    return ss.str();
//}

std::string Circle::toSvg(const std::string & css_class_name) const
{
    //<circle cx="50" cy="50" r="40" stroke="black" stroke-width="3" fill="red" />
    std::stringstream ss;
    ss << "\t<circle cx=\"" << center.x << "\" cy=\"" << center.y << "\" r=\"" << radius 
            << "\" class=\"" << css_class_name << "\"  />\n";
    return ss.str();
}

}

