/*
 * Geom2D.h
 *
 *  Created on: 2016. nov. 4.
 *      Author: Laszlo Lazar
 */

#ifndef GEOM_GEOM2D_H_
#define GEOM_GEOM2D_H_

#include "CVector2D.h"
#include "../util/NumericComparator.h"


//#include <Eigen/Geometry>
//using Eigen::Vector2d;

#include <memory>
#include <vector>

//#include "io/svg/SvgBase.h"

namespace geom {

    
class Geom2D /*: public io::svg::SvgBase*/ {
public:
	Geom2D()  { }
	virtual ~Geom2D() {} 
        
        virtual bool containsPoint(const CVector2D &p) const { }
        
        virtual void translate(const CVector2D &translation) = 0;
        
        virtual bool intersection(std::shared_ptr<Geom2D> geom, std::vector<CVector2D>& intersection_points) { }
        
        virtual std::string toSvg(const std::string & css_class_name = "" ) const { 
//            std::stringstream ss;
           // ss << " class=\"" << css_class_name << "\"\n";
//            return ss.str();
            return "";
        }
        
        //virtual std::string toSvg(const float stroke_width = 1.0f, std::string color = "#000000" ) { return ""; }
        
        
};

}


#endif /* GEOM_GEOM2D_H_ */
