/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Segment.h
 * Author: llazar
 *
 * Created on 2016. november 8., 9:17
 */

#ifndef SEGMENT_H
#define SEGMENT_H

#include <algorithm>
#include "Line.h"
#include "IViewable.h"

namespace geom {
    
class Angle;

class Segment : public Line, public IViewable {
    
protected:
    CVector2D point2;
    
public:
    Segment(const double x0, const double y0, const double x1, const double y1) : 
        Line(x0, y0, x1 - x0, y1 - y0), point2(x1, y1) { }
    Segment(const CVector2D p1, const CVector2D p2) : Line(p1, p2), point2(p2) { }
    Segment(const Segment& orig);
    virtual ~Segment();
    
    virtual bool containsPoint(const CVector2D &p) const {
        if (Line::containsPoint(p)) {
            return isInBoundingBox(p);
        }
        return false;
    }
    
    virtual bool isInBoundingBox(const CVector2D &p) const {
        double minX = std::min(point.x, point2.x);
        double maxX = std::max(point.x, point2.x);
        double minY = std::min(point.y, point2.y);
        double maxY = std::max(point.y, point2.y);

        //minX <= p.x <= maxX && minY <= p.y <= maxY;
        return NumericComparator::GreaterThanOrEqual(p.x, minX) && NumericComparator::LessThanOrEqual(p.x, maxX)
            && NumericComparator::GreaterThanOrEqual(p.y, minY) && NumericComparator::LessThanOrEqual(p.y, maxY);
    }
    
    virtual void translate(const CVector2D &translation) {
            Line::translate(translation);
            point2 += translation;
        }
    
    virtual bool intersect(const Segment &segment, std::vector<CVector2D> &intersection_points);

    virtual bool intersection(std::shared_ptr<Geom2D> geom, std::vector<CVector2D>& intersection_points);

    virtual Angle getFieldOfView(const CVector2D& p0) const;

    const CVector2D getPoint2() const {
        return point2;
    }

    void setPoint2(const CVector2D& point2) {
        this->point2 = point2;
    }
    
    double getLength() const { return (point2 - point).length(); }
    
    void logSvg();
    
    virtual std::string toSvg(const std::string & css_class_name = "" ) const;
    
//    std::string toSvg(const float stroke_width = 1.0f, std::string color = "#000000");
    
//    virtual std::string toSvg() const;

private:

};

}

#endif /* SEGMENT_H */

