/*
 * Line.h
 *
 *  Created on: 2016. nov. 4.
 *      Author: Laszlo Lazar
 */

#ifndef GEOM_LINE_H_
#define GEOM_LINE_H_

#include <vector>
#include "Geom2D.h"
//#include "Vector2D.h"

namespace geom {
    
    class Angle;

    class Line : public Geom2D {
    protected:
        CVector2D point;
        CVector2D direction;

    public:
        Line();

        Line(const Line &line) : point(line.point), direction(line.direction) {  }
        
        Line(const CVector2D& p1, const CVector2D& p2) : point(p1), direction(p2 - p1) { }

        Line(double x0, double y0, double vx0, double vy0) : point(x0, y0), direction(vx0, vy0) {
        }

        Line(double a, double b, double c) : direction(-b, a) { //linear equation: a * x + b * y = c
            if (isSteep()) {
                point.x = c / a;
                point.y = 0.0;
            } else {
                point.x = 0.0;
                point.y = c / b;
            }
        }
        virtual ~Line();

        bool isSteep() const {
            return fabs(direction.y) > fabs(direction.x);
        }

        virtual bool containsPoint(const CVector2D &p) const {
            return NumericComparator::ApproximatelyEqual( (p - point).cross(direction) , 0.0); //(p.x - point.x) * direction.y == (p.y - point.y) * direction.x;
        }

        virtual bool intersect(const Line &l, std::vector<CVector2D> &intersection_points);

        virtual void translate(const CVector2D &translation) {
            point += translation;
        }

        
        
    public:
        //getters & setters

        const CVector2D& getDirection() const {
            return direction;
        }

        //	void setDirection(const CVector2D& direction) {
        //		this->direction = direction;
        //	}

        const CVector2D& getPoint() const {
            return point;
        }

        //	void setPoint(const CVector2D& point) {
        //		this->point = point;
        //	}
    };

}

#endif /* GEOM_LINE_H_ */
