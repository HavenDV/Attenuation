/*
 * Circle.h
 *
 *  Created on: 2016. nov. 4.
 *      Author: Laszlo Lazar
 */

#ifndef GEOM_CIRCLE_H_
#define GEOM_CIRCLE_H_

#include "Geom2D.h"
#include "IViewable.h"
#include "io/svg/SvgElement.h"

#include <vector>

//#include "CVector2D.h"
//#include <Eigen/Geometry>

namespace geom {
    
class Line;
class Angle;

class Circle : public Geom2D, public IViewable {

protected:
	CVector2D center;
	double radius;

public:
	Circle() : radius(0.0) { }
        Circle(const double x0, const double y0, const double r0) : center(x0, y0), radius(r0) { }
        Circle(const CVector2D& center0, const double r0) : center(center0), radius(r0) { }
        Circle(const Circle &circle) : center(circle.center), radius(circle.radius) {}
	virtual ~Circle();

	bool isOnBorder(const CVector2D &v) const {
		return (center - v).length2() == getSqrRadius();	//TODO: fp comp
	}

	bool isInside(const CVector2D &v) const {
		return (v - center).length2() < getSqrRadius();	//TODO: fp comp
	}

	bool isOutside(const CVector2D &v) const {
		return (v - center).length2() > getSqrRadius();		//TODO: fp comp
	}

	double getRadius() const { return radius; }
	double getSqrRadius() const { return radius * radius; }
        
        CVector2D getCenter() const { return center; }
                
        virtual void translate(const CVector2D &translation) {
            center += translation;
        }
        
        virtual bool intersectionCircleLine(const Line &line, std::vector<CVector2D> &intersection_points) const;
        
        virtual bool intersectionCircleCircle(const Circle &circle2, std::vector<CVector2D> &intersection_points) const;
        
        virtual Angle getFieldOfView(const CVector2D& p0) const;
        
        virtual bool containsPoint(const CVector2D &p) const;
        
//        virtual std::string toSvg(const float stroke_width = 1.0f, std::string color = "#000000");
        
        virtual std::string toSvg(const std::string & css_class_name = "" ) const;
};

}

#endif /* GEOM_CIRCLE_H_ */
