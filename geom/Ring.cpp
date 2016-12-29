/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ring.cpp
 * Author: llazar
 * 
 * Created on 2016. november 10., 5:15
 */

#include "Ring.h"
#include <sstream>

namespace geom {

Ring::Ring() {
}

Ring::Ring(const Ring& orig) {
}

Ring::~Ring() {

}

void Ring::addElement(std::shared_ptr<Geom2D> element)
{
    m_Items.push_back(element);
}

bool Ring::intersection(const Segment& segment, std::vector<CVector2D>& intersection_points)
{
    
}

std::string Ring::toSvg(const std::string & css_class_name) const
{
    std::stringstream ss;
    for (std::vector<std::shared_ptr<Geom2D> >::const_iterator iterItem = m_Items.begin() ; iterItem != m_Items.end(); ++iterItem)
    {
        std::shared_ptr<Geom2D> geom = *iterItem;
        ss << geom->toSvg(css_class_name);
    }
    return ss.str();
}

}

