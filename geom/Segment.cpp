/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Segment.cpp
 * Author: llazar
 * 
 * Created on 2016. november 8., 9:17
 */

#include "Segment.h"
#include "Angle.h"

#include <fstream>
#include <sstream>

namespace geom {



Segment::Segment(const Segment& orig) {
}

Segment::~Segment() {
}

bool Segment::intersection(std::shared_ptr<Geom2D> geom, std::vector<CVector2D>& intersection_points)
{
    std::shared_ptr<Segment> derived = std::dynamic_pointer_cast<Segment> (geom);
    if (derived.get()) {
        123345
    }  
}

bool Segment::intersect(const Segment &segment, std::vector<CVector2D> &intersection_points)
{
    double minX1 = std::min(point.x, point2.x);
    double maxX1 = std::max(point.x, point2.x);
    double minX2 = std::min(segment.getPoint().x, segment.getPoint2().x);
    double maxX2 = std::max(segment.getPoint().x, segment.getPoint2().x);
    
    double minY1 = std::min(point.y, point2.y);
    double maxY1 = std::max(point.y, point2.y);
    double minY2 = std::min(segment.getPoint().y, segment.getPoint2().y);
    double maxY2 = std::max(segment.getPoint().y, segment.getPoint2().y);
    
    bool hasIntersection = false;
    if (maxX1 >= minX2 && minX1 <= maxX2 && maxY1 >= minY2 && minY1 <= maxY2) {     //TODO: fp comp
        hasIntersection = Line::intersect(segment, intersection_points);
    }
    if (hasIntersection) {
        CVector2D ip = intersection_points.back();
        segment.containsPoint(ip);
        bool isbb = minX1 <= ip.x && ip.x <= maxX1 && minY1 <= ip.y && ip.y <= maxY1
                && minX2 <= ip.x && ip.x <= maxX2 && minY2 <= ip.y && ip.y <= maxY2;
        if (!isbb) {
            intersection_points.pop_back();
            return false;
        }
        return true;
    }
    return false;
}

Angle Segment::getFieldOfView(const CVector2D& p0) const
{
    Angle ret(p0, point - p0, point2 - p0);
    return ret;
}

void Segment::logSvg()
{
    //<line x1="0" y1="0" x2="200" y2="200" style="stroke:rgb(255,0,0);stroke-width:2" />}
    std::ofstream myfile;
    myfile.open ("log.htm", std::ios_base::app);
    myfile << "<line x1=\"" << point.x << "\" y1=\"" << point.y << "\" x2=\"" << point2.x << "\" y2=\"" << point2.y << 
            "\" style=\"stroke:rgb(255,0,0);stroke-width:1\"  />\n";
    myfile.close();
}

//std::string Segment::toSvg(const float stroke_width, std::string color)
//{
//    std::stringstream ss;
//    ss << "<line x1=\"" << point.x << "\" y1=\"" << point.y << "\" x2=\"" << point2.x << "\" y2=\"" << point2.y << 
//            "\" stroke=\"" << color << "\" stroke-width=\"" << stroke_width << "\" fill=\"none\"  />\n";
//    return ss.str();
//}

std::string Segment::toSvg(const std::string & css_class_name) const
{
    std::stringstream ss;
    ss << "\t<line x1=\"" << point.x << "\" y1=\"" << point.y << "\" x2=\"" << point2.x << "\" y2=\"" << point2.y << 
            "\" class=\"" << css_class_name << "\"  />\n";
    return ss.str();
}



}
