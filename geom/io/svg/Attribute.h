/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Attribute.h
 * Author: llazar
 *
 * Created on 2016. november 23., 14:17
 */

#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include "Serializable.h"
#include "AbstractAttributeValue.h"


namespace geom {
namespace io {    
namespace svg {
  

class Attribute : public SvgBase
{
private:
    std::string _key;
    std::shared_ptr<AbstractAttributeValue> _value;
    std::string _unit;

public:
    Attribute(std::string const & attribute_name, AbstractAttributeValue * value, std::string const & unit = "")
            : _key(attribute_name), _value(value), _unit(unit) 
            { }
            
    virtual std::string toSvg() const {
        std::stringstream ss;
        ss << _key << "=\"" << _value->toString() << _unit << "\" ";
        return ss.str();
    }
    
};
    
}
}
}


#endif /* ATTRIBUTE_H */

