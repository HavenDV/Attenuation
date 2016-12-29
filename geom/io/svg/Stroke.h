/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stroke.h
 * Author: llazar
 *
 * Created on 2016. november 23., 14:38
 */

#ifndef STROKE_H
#define STROKE_H

#include "Attribute.h"
#include "Color.h"



namespace geom {
namespace io {    
namespace svg {
    
class Stroke : public Attribute<Color>
{
    
    
public:
    Stroke(std::string const & attribute_name, Color const & value = Color::Black) :
        Attribute("stroke", value)
    {
        
    }
};

class StrokeWidth : public Attribute<float>
{

public:
    Stroke(std::string const & attribute_name, float const & value = 1.0f) :
        Attribute("stroke-width", value)
    {
        
    }
};
    
}
}
}


#endif /* STROKE_H */

