/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ring.h
 * Author: llazar
 *
 * Created on 2016. november 10., 5:15
 */

#ifndef RING_H
#define RING_H

#include "Geom2D.h"
#include <memory>
#include <vector>

namespace geom {

    class Segment;
   
class Ring {
protected:
    std::vector<std::shared_ptr<Geom2D> > m_Items;
    
public:
    Ring();
    Ring(const Ring& orig);
    virtual ~Ring();
    
    void addElement(std::shared_ptr<Geom2D> element);
    virtual bool intersection(const Segment& segment, std::vector<CVector2D>& intersection_points);
    
    std::vector<std::shared_ptr<Geom2D> >& getItems()  { return m_Items; }
    
    virtual std::string toSvg(const std::string & css_class_name = "" ) const;
    
    //virtual std::string toSvg(const float stroke_width = 1.0f, std::string color = "#000000") const;
private:

};

}

#endif /* RING_H */

