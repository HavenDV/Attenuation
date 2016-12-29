/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Group.h
 * Author: llazar
 *
 * Created on 2016. november 23., 14:56
 */

#ifndef GROUP_H
#define GROUP_H

#include "Serializable.h"
#include "Attribute.h"


namespace geom {
namespace io {    
namespace svg {   
    
class Group : public SvgElement {

public:
    Group() : SvgElement("g") { }
    virtual ~Group() { }

};

}
}
}

#endif /* GROUP_H */

