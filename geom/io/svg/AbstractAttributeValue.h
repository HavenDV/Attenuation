/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AbstractAttributeValue.h
 * Author: llazar
 *
 * Created on 2016. november 23., 15:18
 */

#ifndef ABSTRACTATTRIBUTEVALUE_H
#define ABSTRACTATTRIBUTEVALUE_H

namespace geom {
namespace io {    
namespace svg {   
    
class AbstractAttributeValue
{
public:
    virtual std::string toString() const { return ""; }
};

class FloatValue : public AbstractAttributeValue {
protected:
    float _value;
    
public:
    FloatValue(float value) : _value(value) { }
    
    virtual std::string toString() const {
        std::stringstream ss;
        ss << _value;
        return ss.str();
    }
};

class StringValue : public AbstractAttributeValue {
protected:
    std::string _value;
    
public:
    StringValue(const std::string & value) : _value(value) { }
    
    virtual std::string toString() const {
        return _value;
    }
};
    
}
}
}

#endif /* ABSTRACTATTRIBUTEVALUE_H */

