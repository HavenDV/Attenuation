/*
 * Vector2D.h
 *
 *  Created on: 2016. nov. 4.
 *      Author: llazar
 */

#ifndef GEOM_CVECTOR2D_H_
#define GEOM_CVECTOR2D_H_

//#define __XSI_VISIBLE
#include <math.h>
//#undef __XSI_VISIBLE

#define M_PI		3.14159265358979323846

#include <iostream> 


namespace geom {

    class CVector2D {
    public:
        double x; //!< x-component
        double y; //!< y-component

    public:

        CVector2D() : x(0.0), y(0.0) {
        }

        CVector2D(double xx, double yy) : x(xx), y(yy) {
        }

        CVector2D(const CVector2D &v) : x(v.x), y(v.y) {
        }

        virtual ~CVector2D() { 
            //std::cout << "CVector2D destructor"  << std::endl;
        }

        CVector2D &operator=(const CVector2D &v) {
            x = v.x;
            y = v.y;
            return *this;
        }

        // Vector2D additions
        //

        CVector2D operator+(const CVector2D &v) const {
            return CVector2D(x + v.x, y + v.y);
        }

        CVector2D &operator+=(const CVector2D &v) {
            x += v.x;
            y += v.y;
            return *this;
        }

        // Vector2D substractions
        //

        CVector2D operator-(const CVector2D &v) const {
            return CVector2D(x - v.x, y - v.y);
        }

        CVector2D &operator-=(const CVector2D &v) {
            x -= v.x;
            y -= v.y;
            return *this;
        }


        // Vector2D multiplications
        //

        CVector2D operator*(const double f) const {
            return CVector2D(x * f, y * f);
        }

        CVector2D &operator*=(const double f) {
            x *= f;
            y *= f;
            return *this;
        }

        friend CVector2D operator*(double f, CVector2D &v) {
            return v * f;
        }

        friend std::ostream& operator<<(std::ostream &out, const geom::CVector2D &point) {
            out << "Point(" << point.x << ", " << point.y << ")";
        }

        //dot product

        double operator*(const CVector2D &v) const {
            return this->dot(v);
        }

        double dot(const CVector2D &v) const {
            return x * v.x + y * v.y;
        }


        // vector product

        double cross(const CVector2D &v) const {
            return (x * v.y - y * v.x);
        }

        // scale

        CVector2D getScaled(const CVector2D &s) const {
            return CVector2D(x * s.x, y * s.y);
        }

        void scale(const CVector2D &s) {
            x *= s.x;
            y *= s.y;
        }

        void scale(const double scaleFactor) {
            x *= scaleFactor;
            y *= scaleFactor;
        }

        CVector2D getScaled(const double scaleFactor) const {
            CVector2D ret(*this);
            ret.scale(scaleFactor);
            return ret;
        }

        // Some other useful methods.

        double length() const {
            return sqrt(x * x + y * y);
        }
        ;

        double length2() const {
            return x * x + y * y;
        }

        void normalize() {
            double tmp = 1. / length();
            x *= tmp;
            y *= tmp;
        }

        void rotate(double phi) {
            double tempX = x;
            double tempY = y;
            x = tempX * cos(phi) - tempY * sin(phi);
            y = tempX * sin(phi) + tempY * cos(phi);
        }

        CVector2D getRotated(const double phi) const {
            double x0 = x * cos(phi) - y * sin(phi);
            double y0 = x * sin(phi) + y * cos(phi);
            return CVector2D(x0, y0);
        }

        void rotate90() {
            double tempX = x;
            x = -y;
            y = tempX;
        }

        void rotate180() {
            x = -x;
            y = -y;
        }

        void rotate270() {
            double tempX = x;
            x = y;
            y = -tempX;
        }

        void translate(const CVector2D &v) {
            x += v.x;
            y += v.y;
        }
        
        double getAngle() {
            CVector2D x(1.0, 0.0);
            double cos_phi = this->dot(x) / this->length();
            double phi = acos(cos_phi) * 180.0 / M_PI;
            if (this->y < 0.0) {
                phi = 360.0 - phi;
            }
            return phi;
        }
    };

}

#endif /* GEOM_CVECTOR2D_H_ */
