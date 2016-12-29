/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestPhantom.h
 * Author: llazar
 *
 * Created on 2016. november 16., 11:41
 */

#ifndef TESTPHANTOM_H
#define TESTPHANTOM_H

//#include "CompoundObject.h"
#include "Ring.h"

namespace geom {

class TestPhantom {
protected:
    double z;
    std::vector<std::shared_ptr<Ring> > m_Rings;
public:
    TestPhantom();
    TestPhantom(const TestPhantom& orig);
    virtual ~TestPhantom();
    
    
    
    virtual void intersect(std::shared_ptr<geom::Segment> segment, std::vector<CVector2D>& outIntersectionPoints);
    
    virtual void getPointsOfInterest(std::vector<CVector2D>& outPoints);
    
    virtual std::string toSvg() const;
        
    
    virtual void setZ(double z) { this->z = z; init(); }

    
protected:
    virtual void init();
    
};


}

#endif /* TESTPHANTOM_H */

