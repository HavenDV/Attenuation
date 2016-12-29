/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CompoundObject.h
 * Author: llazar
 *
 * Created on 2016. november 11., 6:43
 */

#ifndef COMPOUNDOBJECT_H
#define COMPOUNDOBJECT_H

#include "Ring.h"


namespace geom {
    
//    class Ring;

class CompoundObject {
protected:
    double z;
    std::vector<std::shared_ptr<Ring> > m_Rings;
public:
    CompoundObject();
    CompoundObject(const CompoundObject& orig);
    virtual ~CompoundObject();
    
    
    
    virtual void intersect(std::shared_ptr<geom::Segment> segment, std::vector<CVector2D>& outIntersectionPoints);
    
    virtual void getPointsOfInterest(std::vector<CVector2D>& outPoints, const std::string & order);
    
    virtual std::string toSvg(const std::string & css_class_name = "" ) const;
    
//    friend std::ostream& operator<< (std::ostream& stream, const CompoundObject& object);
    
    
    virtual void setZ(double z) { this->z = z; init(); }
    
    double getHeight() const { return 300.0; }

    
protected:
    virtual void init();
    virtual double calcExtent(double xb, double xt);
};

}

#endif /* COMPOUNDOBJECT_H */

