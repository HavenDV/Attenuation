/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fill.h
 * Author: llazar
 *
 * Created on 2016. november 23., 14:46
 */

#ifndef FILL_H
#define FILL_H

#include "Attribute.h"
#include "Color.h"


namespace geom {
namespace io {    
namespace svg {   
    
 class Fill : public Attribute
 {
 public:
     Fill(std::string const & attribute_name, Color const & value = Color::None)
        : Attribute<Color>("fill", value)
        {}
 };
    
}
}
}

#endif /* FILL_H */

