/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ellipse.cpp
 * Author: llazar
 * 
 * Created on 2016. november 18., 23:30
 */

#include "Ellipse.h"

#include <sstream>

namespace geom {



Ellipse::~Ellipse() {
}

//std::string Ellipse::toSvg(const float stroke_width, std::string color)
//{
//    //<circle cx="50" cy="50" r="40" stroke="black" stroke-width="3" fill="red" />
//    std::stringstream ss;
//    ss << "<ellipse cx=\"" << center.x << "\" cy=\"" << center.y << "\" rx=\"" << radiusX 
//        << "\" ry=\"" << radiusY << "\" stroke=\"" << color  << "\" stroke-width=\"" << stroke_width << "\" fill=\"none\"  />\n";
//    return ss.str();
//}

std::string Ellipse::toSvg(const std::string & css_class_name) const
{
    //<circle cx="50" cy="50" r="40" stroke="black" stroke-width="3" fill="red" />
    std::stringstream ss;
    ss << "\t<ellipse cx=\"" << center.x << "\" cy=\"" << center.y << "\" rx=\"" << radiusX 
        << "\" ry=\"" << radiusY << "\" class=\"" << css_class_name << "\"  />\n";
    return ss.str();
}

}