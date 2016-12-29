/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GeometricRelation.h
 * Author: llazar
 *
 * Created on 2016. november 8., 9:07
 */

#ifndef GEOMETRICRELATION_H
#define GEOMETRICRELATION_H

#include "Geom2D.h"

#include <memory>
#include <vector>

using namespace std;

namespace geom {
    
    class Line;
    class Segment;
    class Circle;
    class SemiCircle;
    class Ellipse;

class GeometricRelation {
public:
    GeometricRelation();
    GeometricRelation(const GeometricRelation& orig);
    virtual ~GeometricRelation();
    //bool intersection(Geom2D *geom1, Geom2D *geom2);
    void intersection(std::shared_ptr<Geom2D> obj1, std::shared_ptr<Geom2D> obj2, std::vector<CVector2D>& intersection_points);
    
    int intersectionLineLine(std::shared_ptr<Line> obj1, std::shared_ptr<Line> obj2, std::vector<CVector2D>& intersection_points);
    int intersectionSegmentSegment(std::shared_ptr<Segment> obj1, std::shared_ptr<Segment> obj2, std::vector<CVector2D>& intersection_points);
    int intersectionSemiCircleSegment(std::shared_ptr<SemiCircle> circle, std::shared_ptr<Segment> segment, std::vector<CVector2D>& intersection_points);
    int intersectionCircleLine(std::shared_ptr<Circle> circle, std::shared_ptr<Line> line, std::vector<CVector2D>& intersection_points);
    int intersectionCircleSegment(std::shared_ptr<Circle> circle, std::shared_ptr<Segment> segment, std::vector<CVector2D>& intersection_points);
    
    int intersectionEllipseLine(std::shared_ptr<Ellipse> ellipse0, std::shared_ptr<Line> line, std::vector<CVector2D>& intersection_points);
    int intersectionEllipseSegment(std::shared_ptr<Ellipse> ellipse, std::shared_ptr<Segment> segment, std::vector<CVector2D>& intersection_points);
private:

};

}

#endif /* GEOMETRICRELATION_H */

