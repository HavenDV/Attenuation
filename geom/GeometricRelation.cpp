/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GeometricRelation.cpp
 * Author: llazar
 * 
 * Created on 2016. november 8., 9:07
 */

#include "GeometricRelation.h"

#include "Line.h"
#include "Segment.h"
#include "Circle.h"
#include "SemiCircle.h"
#include "Ellipse.h"

namespace geom {

GeometricRelation::GeometricRelation() {
}

GeometricRelation::GeometricRelation(const GeometricRelation& orig) {
}

GeometricRelation::~GeometricRelation() {
}

void GeometricRelation::intersection(std::shared_ptr<Geom2D> obj1, std::shared_ptr<Geom2D> obj2, std::vector<CVector2D>& intersection_points)
{
    if (dynamic_cast<Segment*>(obj1.get()) && dynamic_cast<Segment*>(obj2.get())) {
        shared_ptr<Segment> segment1 = std::dynamic_pointer_cast<Segment>(obj1);
        shared_ptr<Segment> segment2 = std::dynamic_pointer_cast<Segment>(obj2);
        intersectionSegmentSegment(segment1, segment2, intersection_points);
    } else if (dynamic_cast<Line*>(obj1.get()) && dynamic_cast<Line*>(obj2.get())) {
        shared_ptr<Line> line1 = std::dynamic_pointer_cast<Line>(obj1);
        shared_ptr<Line> line2 = std::dynamic_pointer_cast<Line>(obj2);
        intersectionLineLine(line1, line2, intersection_points);
    } else if (dynamic_cast<Segment*>(obj1.get()) && dynamic_cast<SemiCircle*>(obj2.get())) {
        intersectionSemiCircleSegment(dynamic_pointer_cast<SemiCircle>(obj2), dynamic_pointer_cast<Segment>(obj1), intersection_points);
    } else if (dynamic_cast<Segment*>(obj2.get()) && dynamic_cast<SemiCircle*>(obj1.get())) {
        intersectionSemiCircleSegment(dynamic_pointer_cast<SemiCircle>(obj1), dynamic_pointer_cast<Segment>(obj2), intersection_points);
    } else if (dynamic_cast<Segment*>(obj1.get()) && dynamic_cast<Circle*>(obj2.get())) {
        intersectionCircleSegment(dynamic_pointer_cast<Circle>(obj2), dynamic_pointer_cast<Segment>(obj1), intersection_points);
    } else if (dynamic_cast<Segment*>(obj2.get()) && dynamic_cast<Circle*>(obj1.get())) {
        intersectionCircleSegment(dynamic_pointer_cast<Circle>(obj1), dynamic_pointer_cast<Segment>(obj2), intersection_points);
    } 
    else if (dynamic_cast<Segment*>(obj2.get()) && dynamic_cast<Ellipse*>(obj1.get())) {
        intersectionEllipseSegment(dynamic_pointer_cast<Ellipse>(obj1), dynamic_pointer_cast<Segment>(obj2), intersection_points);
    } else if (dynamic_cast<Segment*>(obj1.get()) && dynamic_cast<Ellipse*>(obj2.get())) {
        intersectionEllipseSegment(dynamic_pointer_cast<Ellipse>(obj2), dynamic_pointer_cast<Segment>(obj1), intersection_points);
    }
}

int GeometricRelation::intersectionLineLine(std::shared_ptr<Line> obj1, std::shared_ptr<Line> obj2, std::vector<CVector2D>& intersection_points)
{
//    std::cout << __func__ << endl;
    CVector2D b;
    b.x = obj1->getPoint().cross(obj1->getDirection()); //direction.y * point.x - direction.x * point.y;
    b.y = obj2->getPoint().cross(obj2->getDirection()); //line.getPoint().y * line.getPoint().x - line.direction.x * line.point.y;
    double det;
    CVector2D result;
    det = obj1->getDirection().cross(obj2->getDirection());
    if (!NumericComparator::EssentiallyEqual(det, 0.0)) {
        result.x = (-b.x * obj2->getDirection().x + obj1->getDirection().x * b.y) / det;
        result.y = (obj1->getDirection().y * b.y - b.x * obj2->getDirection().y) / det;
        intersection_points.push_back(result);
        return 1;
    }
    return 0;
}

int GeometricRelation::intersectionSegmentSegment(std::shared_ptr<Segment> segment1, std::shared_ptr<Segment> segment2, 
        std::vector<CVector2D>& intersection_points)
{
//    std::cout << "intersectionSegmentSegment" << endl;
    double minX1 = std::min(segment1->getPoint().x, segment1->getPoint2().x);
    double maxX1 = std::max(segment1->getPoint().x, segment1->getPoint2().x);
    double minX2 = std::min(segment2->getPoint().x, segment2->getPoint2().x);
    double maxX2 = std::max(segment2->getPoint().x, segment2->getPoint2().x);
    
    double minY1 = std::min(segment1->getPoint().y, segment1->getPoint2().y);
    double maxY1 = std::max(segment1->getPoint().y, segment1->getPoint2().y);
    double minY2 = std::min(segment2->getPoint().y, segment2->getPoint2().y);
    double maxY2 = std::max(segment2->getPoint().y, segment2->getPoint2().y);
    
    int ip_count = 0;
    if (maxX1 >= minX2 && minX1 <= maxX2 && maxY1 >= minY2 && minY1 <= maxY2) {     //TODO: fp comp
        ip_count = intersectionLineLine(dynamic_pointer_cast<Line>(segment1),
                dynamic_pointer_cast<Line>(segment2), intersection_points);
    }
    if (ip_count) {
        CVector2D ip = intersection_points.back();
//        bool is_in_segment1 = segment1->containsPoint(ip);
//        bool is_in_segment2 = segment2->containsPoint(ip);
//        bool isbb = minX1 <= ip.x && ip.x <= maxX1 && minY1 <= ip.y && ip.y <= maxY1
//                && minX2 <= ip.x && ip.x <= maxX2 && minY2 <= ip.y && ip.y <= maxY2;
        
        if (!segment1->isInBoundingBox(ip) || !segment2->isInBoundingBox(ip)) {    //point is not inside the segments
            intersection_points.pop_back();
            return 0;
        }
//        std::cout << "Segment x Segment: " << ip << endl;
        return 1;
    }
    return 0;
}

int GeometricRelation::intersectionCircleLine(std::shared_ptr<Circle> circle0, 
        std::shared_ptr<Line> line, 
        std::vector<CVector2D>& intersection_points)
{
    int ip_count = 0;
    CVector2D tr(circle0->getCenter());
    tr.rotate180();
    Circle circle(*circle0);
    circle.translate(tr);
    
    Line tempLine(*line.get());
    tempLine.translate(tr);
    
    CVector2D dir = tempLine.getDirection();
    
    CVector2D result1, result2;
    
    double c = tempLine.getPoint().cross(dir);
    double r2 = circle.getSqrRadius();
    double t3 = dir.x * dir.x;
    double t5 = dir.y * dir.y;
    double t9 = c * c;
    if (fabs(dir.y) > fabs(dir.x)) {    //steep line
        double t7 = t5 * t5;
        double discriminator = r2 * t3 * t5 + r2 * t7 - t9 * t5;
        if (discriminator >= 0) {            
            double t12 = sqrt(discriminator);
            result1.y = (-c * dir.x + t12) / (t3 + t5);
            result2.y = -(c * dir.x + t12) / (t3 + t5);
            
            //x = (v1*y+c)/v2
            result1.x = (dir.x * result1.y + c) / dir.y;
            result2.x = (dir.x * result2.y + c) / dir.y;
            
            ip_count = 2;
        }        
    } else {
        double t4 = t3 * t3;
        double discriminator = r2 * t3 * t5 + r2 * t4 - t9 * t3;
        if (discriminator >= 0) {            
            double t12 = sqrt(discriminator);
            result1.x = (c * dir.y + t12) / (t3 + t5);
            result2.x = -(-c * dir.y + t12) / (t3 + t5);

            //(v2*x - c)/v1
            result1.y = (dir.y * result1.x - c) / dir.x;
            result2.y = (dir.y * result2.x - c) / dir.x;
            ip_count = 2;
            
        }        
    }
    if (ip_count) {
        result1.translate(circle0->getCenter());
        result2.translate(circle0->getCenter());
        
        intersection_points.push_back(result1);
        intersection_points.push_back(result2);
    }
    return ip_count;
}

/**    */
int GeometricRelation::intersectionSemiCircleSegment(std::shared_ptr<SemiCircle> circle, 
        std::shared_ptr<Segment> segment, 
        std::vector<CVector2D>& intersection_points)
{
    std::vector<CVector2D> temp_intersection_points;
    int ip_count = intersectionCircleLine(dynamic_pointer_cast<Circle>(circle), dynamic_pointer_cast<Line>(segment), temp_intersection_points);
    for (int i = 0; i < temp_intersection_points.size(); i++) {
        bool isInSegment = true; //segment->containsPoint(temp_intersection_points[i]);
        bool isInSemiCircle = circle->containsPoint(temp_intersection_points[i]);
        if (isInSegment && isInSemiCircle) {
            intersection_points.push_back(temp_intersection_points[i]);
//            std::cout << "Semicircle x Segment: " << temp_intersection_points[i] << endl;
        }
    }    
}

int GeometricRelation::intersectionCircleSegment(std::shared_ptr<Circle> circle, 
        std::shared_ptr<Segment> segment, 
        std::vector<CVector2D>& intersection_points)
{
    std::vector<CVector2D> temp_intersection_points;
    int ip_count = intersectionCircleLine(dynamic_pointer_cast<Circle>(circle), dynamic_pointer_cast<Line>(segment), temp_intersection_points);
    for (int i = 0; i < temp_intersection_points.size(); i++) {
        bool isInSegment = true; //segment->containsPoint(temp_intersection_points[i]);
        if (isInSegment) {
            intersection_points.push_back(temp_intersection_points[i]);
            //std::cout << "Circle x Segment: " << temp_intersection_points[i] << endl;
        }
    }    
}

int GeometricRelation::intersectionEllipseLine(std::shared_ptr<Ellipse> ellipse, 
        std::shared_ptr<Line> line, 
        std::vector<CVector2D>& intersection_points)
{
    int ip_count = 0;
    CVector2D tr(ellipse->getCenter());
    tr.rotate180();
    Ellipse tempEllipse(*ellipse);
    tempEllipse.translate(tr);
    
    Line tempLine(*line);
    tempLine.translate(tr);
    
    CVector2D dir = tempLine.getDirection();
    CVector2D result1, result2;
    double c = tempLine.getPoint().cross(dir);
    double a = tempEllipse.getRadiusX();
    double b = tempEllipse.getRadiusY();
    double a2 = a * a;
    double b2 = b * b;
    double v1_2 = dir.x * dir.x;     //v1 * v1;
    double v2_2 = dir.y * dir.y;      //v2 * v2;
    double c2 = c * c;
    if (fabs(dir.y) > fabs(dir.x)) {    //steep line (dir.x ~ 0)   //y is calculated first
        double a4 = a2 * a2;
        double v2_4 = v2_2 * v2_2;
        double discriminant = a2 * b2 * v1_2 * v2_2 - a2 * c2 * v2_2 + a4 * v2_4;
        if (discriminant >= 0.0) {
            double t17 = sqrt(discriminant);
            result1.y = (-c * dir.x * b + t17) / (v1_2 * b2 + v2_2 * a2) * b;
            result2.y = -(c * dir.x * b + t17) / (v1_2 * b2 + v2_2 * a2) * b;
            //x = (v1*y+c)/v2
            result1.x = (dir.x * result1.y + c) / dir.y;
            result2.x = (dir.x * result2.y + c) / dir.y;
            ip_count = 2;
        }
    } else {    //flat line (dir.y ~ 0)   //x is calculated first
        double b4 = b2 * b2;
        double v1_4 = v1_2 * v1_2;
        double discriminant = a2 * b2 * v1_2 * v2_2 - b2 * c2 * v1_2 + b4 * v1_4;
        if (discriminant >= 0.0) {
            double t17 = sqrt(discriminant);
            result1.x =   (c * dir.y * a + t17) / (v2_2 * a2 + v1_2 * b2) * a;
            result2.x = -(-c * dir.y * a + t17) / (v2_2 * a2 + v1_2 * b2) * a;
            //(v2*x - c)/v1
            result1.y = (dir.y * result1.x - c) / dir.x;
            result2.y = (dir.y * result2.x - c) / dir.x;
            ip_count = 2;
        }
    }
    if (ip_count) {
        result1.translate(ellipse->getCenter());
        result2.translate(ellipse->getCenter());
        
        intersection_points.push_back(result1);
        intersection_points.push_back(result2);
    }
    return ip_count;
    
}

int GeometricRelation::intersectionEllipseSegment(std::shared_ptr<Ellipse> ellipse, 
        std::shared_ptr<Segment> segment, 
        std::vector<CVector2D>& intersection_points)
{
    std::vector<CVector2D> temp_intersection_points;
    int ip_count = intersectionEllipseLine(dynamic_pointer_cast<Ellipse>(ellipse), dynamic_pointer_cast<Line>(segment), temp_intersection_points);
    for (int i = 0; i < temp_intersection_points.size(); i++) {
        bool isInSegment = true; //segment->containsPoint(temp_intersection_points[i]);
        //bool isInEllipse = ellipse->containsPoint(temp_intersection_points[i]);
        if (isInSegment ) {
            intersection_points.push_back(temp_intersection_points[i]);
//            std::cout << "Ellipse x Segment: " << temp_intersection_points[i] << endl;
        }
    }    
}



}