/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CompoundObject.cpp
 * Author: llazar
 * 
 * Created on 2016. november 11., 6:43
 */

#include "CompoundObject.h"
#include "SemiCircle.h"
#include "Segment.h"
#include "GeometricRelation.h"
#include "Ellipse.h"


#include <sstream>

using namespace std;




namespace geom {

    /*
     
     * SemiCircle 100 0, 80, 100 -80, 180 0
     * Segment 100 80 -100 80
     * SemiCircle -100 0 80 -180 0
     * Segment -100 -80 100 -80
     
     x = (300 - z) * 12 / 15 + 120
     y = 80 - 2/15.0  * z
     lx = 2/5 * (300 - z) + 30
     ly =(300-A2)*2/15+20
     
     (x1 - x2) * (300 - z)/300.0 + x2       //x1: bottom, x2: top 
     
     */
    
    
CompoundObject::CompoundObject() : z(0.0) {
    init();
}

void CompoundObject::init()
{
    m_Rings.clear();
    
    double xb = 100.0, xt = 20.0;
    double yb = 80.0, yt = 40.0;
    double Rb = 80.0, Rt = 40.0;
    
    double xi = calcExtent(xb, xt);
    double yi = calcExtent(yb, yt);
    double Ri = calcExtent(Rb, Rt);
    double x_hole_cx = calcExtent(150.0, 30.0);
    double y_hole_cy = calcExtent(60.0, 20.0);
    const double r = 5.5;
    
    std::shared_ptr<Ring> outerRing(new Ring);
    outerRing->addElement(std::shared_ptr<SemiCircle>(new SemiCircle(
            CVector2D(xi, 0.0), Ri, CVector2D(xi, -yi), CVector2D(calcExtent(xb + Rb, xt+Rt), 0.0) 
        ) ));
    outerRing->addElement(std::shared_ptr<Segment>(new Segment(xi, yi, -xi, yi)));
    outerRing->addElement(std::shared_ptr<SemiCircle>(new SemiCircle(
            CVector2D(-xi, 0.0), Ri, CVector2D(-xi, yi), CVector2D(-calcExtent(xb + Rb, xt+Rt), 0.0) 
        ) ));
    outerRing->addElement(std::shared_ptr<Segment>(new Segment(-xi, -yi, xi, -yi)));
    m_Rings.push_back(outerRing);
    
    std::shared_ptr<Ring> innerRing0(new Ring);
    innerRing0->addElement(std::shared_ptr<Circle>(new Circle(0.0, 0.0, r)));
    m_Rings.push_back(innerRing0);
    
    double a = 5.9319411;
    double b = 5.55405164885;
    std::shared_ptr<Ring> innerRing1(new Ring);
    innerRing1->addElement(std::shared_ptr<Ellipse>(new Ellipse(x_hole_cx, 0.0, a, r)));
    //innerRing1->addElement(std::shared_ptr<Circle>(new Circle(x_hole_cx, 0.0, r)));
    m_Rings.push_back(innerRing1);
    
    shared_ptr<Ring> innerRing2(new Ring);
    innerRing1->addElement(std::shared_ptr<Ellipse>(new Ellipse(0.0, y_hole_cy, r, b)));
//    innerRing2->addElement(shared_ptr<Circle>(new Circle(0.0, y_hole_cy, r)));
    m_Rings.push_back(innerRing2);
    
    shared_ptr<Ring> innerRing3(new Ring);
    innerRing1->addElement(std::shared_ptr<Ellipse>(new Ellipse(-x_hole_cx, 0.0, a, r)));
//    innerRing3->addElement(shared_ptr<Circle>(new Circle(-x_hole_cx, 0.0, r)));
    m_Rings.push_back(innerRing3);
    
    shared_ptr<Ring> innerRing4(new Ring);
    innerRing1->addElement(std::shared_ptr<Ellipse>(new Ellipse(0.0, -y_hole_cy, r, b)));
//    innerRing4->addElement(shared_ptr<Circle>(new Circle(0.0, -y_hole_cy, r)));
    m_Rings.push_back(innerRing4);
}

CompoundObject::CompoundObject(const CompoundObject& orig) {
}

CompoundObject::~CompoundObject() {
}

double CompoundObject::calcExtent(double xb, double xt)
{
    return (xb - xt) * (300.0 - this->z) / 300.0 + xt;    
}

void CompoundObject::getPointsOfInterest(std::vector<CVector2D>& outPoints, const std::string & order)
{
    double x_hole_cx = calcExtent(150.0, 30.0);
    double y_hole_cy = calcExtent(60.0, 20.0);
    
    for (int i = 0; i < order.size(); ++i) {
        switch (order[i]) {
            case 'c' : outPoints.push_back(CVector2D(0.0, 0.0)); break;
            case 'r' : outPoints.push_back(CVector2D(x_hole_cx, 0.0)); break;
            case 't' : outPoints.push_back(CVector2D(0.0, y_hole_cy)); break;
            case 'l' : outPoints.push_back(CVector2D(-x_hole_cx, 0.0)); break;
            case 'b' : outPoints.push_back(CVector2D(0.0, -y_hole_cy)); break;
            default : break;
        }
    }
}

void CompoundObject::intersect(std::shared_ptr<geom::Segment> beam, std::vector<CVector2D>& outIntersectionPoints)
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
    
//    for (const CVector2D& v : intersection_points)
//    {
//        std::cout << v << endl;
//    }
}

//std::ostream& operator<< (std::ostream& stream, const CompoundObject& object)
//{
//    for (std::vector<std::shared_ptr<Ring> >::const_iterator iterRing = object.m_Rings.begin() ; iterRing != object.m_Rings.end(); ++iterRing)
//    {
//        std::shared_ptr<Ring> ring = *iterRing;
//        stream << ring->toSvg();
//    } 
//    return stream;
//}

std::string CompoundObject::toSvg(const std::string & css_class_name ) const
{
    std::stringstream ss;
    for (std::vector<std::shared_ptr<Ring> >::const_iterator iterRing = m_Rings.begin() ; iterRing != m_Rings.end(); ++iterRing)
    {
        std::shared_ptr<Ring> ring = *iterRing;
        ss << ring->toSvg(css_class_name);
    }
    return ss.str();
}

}

