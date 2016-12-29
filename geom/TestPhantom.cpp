/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestPhantom.cpp
 * Author: llazar
 * 
 * Created on 2016. november 16., 11:41
 */

#include "TestPhantom.h"
#include "SemiCircle.h"
#include "Segment.h"
#include "GeometricRelation.h"

#include <sstream>

/*
 200 x 160
r  = 80
 */



namespace geom {

TestPhantom::TestPhantom() : z(0.0) {
    init();
}

TestPhantom::TestPhantom(const TestPhantom& orig) {
}

TestPhantom::~TestPhantom() {
}

void TestPhantom::init()
{
    m_Rings.clear();
    
    double x = 100.0;
    double y = 80.0;
    double R = 80.0;
    

    const double r = 5.5;
    
    std::shared_ptr<Ring> outerRing(new Ring);
    outerRing->addElement(std::shared_ptr<SemiCircle>(new SemiCircle(
            CVector2D(x, 0.0), R, CVector2D(x, -y), CVector2D(x + R, 0.0) 
        ) ));
    outerRing->addElement(std::shared_ptr<Segment>(new Segment(x, y, -x, y)));
    outerRing->addElement(std::shared_ptr<SemiCircle>(new SemiCircle(
            CVector2D(-x, 0.0), R, CVector2D(-x, y), CVector2D(-(x + R), 0.0) 
        ) ));
    outerRing->addElement(std::shared_ptr<Segment>(new Segment(-x, -y, x, -y)));
    m_Rings.push_back(outerRing);
     
}

void TestPhantom::getPointsOfInterest(std::vector<CVector2D>& outPoints)
{
//    double x_hole_cx = calcExtent(150.0, 30.0);
//    double y_hole_cy = calcExtent(60.0, 20.0);
    
    outPoints.push_back(CVector2D(0.0, 0.0));
}

void TestPhantom::intersect(std::shared_ptr<geom::Segment> beam, std::vector<CVector2D>& outIntersectionPoints)
{
    GeometricRelation gm;
    for (std::vector<std::shared_ptr<Ring> >::iterator iterRing = m_Rings.begin() ; iterRing != m_Rings.end(); ++iterRing)
    {
        std::shared_ptr<Ring> ring = *iterRing;
        std::vector<std::shared_ptr<Geom2D> >& items = ring->getItems();
        for (std::vector<std::shared_ptr<Geom2D> >::iterator iterItem = items.begin() ; iterItem != items.end(); ++iterItem)
        {
            std::shared_ptr<Geom2D> geom = *iterItem;
            gm.intersection(geom, beam, outIntersectionPoints);
        }
    }
}

std::string TestPhantom::toSvg() const
{
    std::stringstream ss;
    for (std::vector<std::shared_ptr<Ring> >::const_iterator iterRing = m_Rings.begin() ; iterRing != m_Rings.end(); ++iterRing)
    {
        std::shared_ptr<Ring> ring = *iterRing;
        ss << ring->toSvg();
    }
    return ss.str();
}

}