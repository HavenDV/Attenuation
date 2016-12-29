/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SourceBase.h
 * Author: llazar
 *
 * Created on 2016. november 10., 16:20
 */

#ifndef SOURCEBASE_H
#define SOURCEBASE_H

#include "../geom/CVector2D.h"
#include "../geom/Segment.h"
#include "../geom/Circle.h"



class SourceBase {
protected:
    geom::CVector2D position;
    std::shared_ptr<geom::Circle> m_scannedArea;
    //double angularStep;
public:
    SourceBase(const geom::CVector2D& pos0, const double radius_of_scanned_area) : 
        position(pos0),
        m_scannedArea(new geom::Circle(0.0, 0.0, radius_of_scanned_area) )      
        {}
    SourceBase(const SourceBase& orig);
    virtual ~SourceBase();
    
    std::shared_ptr<geom::Circle> getScannedArea() const { return m_scannedArea;  }
    
    void rotate(double phi)
    {
        position.rotate(phi);
    }
    
    geom::CVector2D getPosition() const { return position;  }
    
    void setAngle(double degree) {
        double current_angle = position.getAngle();
        double phi = (degree - current_angle) *  M_PI / 180.0;
        if (phi != 0) {
            position.rotate(phi);
        }        
    }

    virtual std::shared_ptr<geom::Segment> getBeam(int index) const = 0;
    virtual int getBeamCount() const = 0;
    
    virtual std::string toSvg(const std::string & css_class_name = "" ) const = 0;
//    virtual std::string toSvg(const float stroke_width = 1.0f, std::string color = "#000000") const = 0;
    
private:

};

#endif /* SOURCEBASE_H */

