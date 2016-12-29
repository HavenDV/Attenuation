/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FanSource.h
 * Author: llazar
 *
 * Created on 2016. november 11., 5:44
 */

#ifndef FANSOURCE_H
#define FANSOURCE_H

#include "SourceBase.h"
#include "../geom/CVector2D.h"

#include "../geom/Segment.h"
#include <memory>
#include <vector>

using namespace geom;

class FanSource : public SourceBase {
protected:
    std::vector<CVector2D> m_Points;
    
    
//    std::vector<Segment> m_Beams;
public:
    FanSource(const geom::CVector2D& pos0, const double radius_of_scanned_area) : 
        SourceBase(pos0, radius_of_scanned_area)        
        { }
    FanSource(const FanSource& orig) : SourceBase(orig) { }
    virtual ~FanSource();
    
    void addPoint(const CVector2D& point) {
        m_Points.push_back(point);
    }
    
    void initReferencePoints(std::vector<CVector2D>& refPoints);
    
    
    
    virtual std::shared_ptr<geom::Segment> getBeam(int index) const;
    int getBeamCount() const { return m_Points.size(); }
    
//    virtual std::string toSvg(const float stroke_width = 1.0f, std::string color = "#000000") const;
    
    virtual std::string toSvg(const std::string & css_class_name = "" ) const;
    
private:

};

#endif /* FANSOURCE_H */

