/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FanSource.cpp
 * Author: llazar
 * 
 * Created on 2016. november 11., 5:44
 */

#include <sstream>

#include "FanSource.h"





FanSource::~FanSource() {
    
}

std::shared_ptr<geom::Segment> FanSource::getBeam(int index) const
{
    CVector2D dirIsoCenter(m_scannedArea->getCenter() - position);
    CVector2D point(m_Points[index]);
    CVector2D direction(point - position);        
    double clippedLength = 2.0 * dirIsoCenter.dot(direction) / direction.length();
    direction.normalize();
    direction.scale(clippedLength);
    std::shared_ptr<Segment> beam(new Segment(position, position + direction));
    return beam;
}

void FanSource::initReferencePoints(std::vector<CVector2D>& refPoints) {
    m_Points.clear();
    for (std::vector<geom::CVector2D>::iterator it = refPoints.begin() ; it != refPoints.end(); ++it)
    {
        m_Points.push_back(*it);
    }
}

std::string FanSource::toSvg(const std::string & css_class_name ) const
{
    std::stringstream ss;
    for (int i = 0; i < m_Points.size(); i++)
    {
        std::shared_ptr<geom::Segment> beam = this->getBeam(i);
        ss << beam->toSvg(css_class_name);
    }
    //ss << m_scannedArea->toSvg();
    return ss.str();
}



