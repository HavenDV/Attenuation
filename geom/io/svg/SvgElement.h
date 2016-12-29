/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SvgElement.h
 * Author: llazar
 *
 * Created on 2016. november 23., 13:05
 */

#ifndef SVGELEMENT_H
#define SVGELEMENT_H


#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include <iostream>

#include "Attribute.h"

namespace geom {
namespace io {    
namespace svg {    


class SvgElement : public SvgBase
{
protected:
    std::string _name;
    std::vector<Attribute> _attributes;
//    std::vector<Attribute> _children;
    
public:
    SvgElement(const std::string& name) : _name(name) { }
    
    virtual std::string toSvg(const std::string& css_class_name = "") const {
        std::stringstream ss;
        ss << "\t<" + _name + " ";
        for (const Attribute& item : _attributes) {
            ss << item.toSvg();
        }
        ss << "</" + _name + ">\n"; 
        return ss.str();
    }
    
   
    void addId(const std::string& id) {
        //StringValue idv(id);
        Attribute attrId("id", new StringValue(id));
        _attributes.push_back(attrId);
    }
    
    void addClass(const std::string& classname) {
        //StringValue value(classname);
        Attribute attrId("class", new StringValue(classname));
        _attributes.push_back(attrId);
    }
    
    void addAttribute(std::string const & attribute_name, AbstractAttributeValue * pValue, std::string const & unit = "") {
        Attribute attr(attribute_name, pValue, unit);
        _attributes.push_back(attr);
    }
    
protected:
    virtual std::string elemStart() const
    {
        return "\t<" + _name + " ";
    }
    virtual std::string elemEnd() const
    {
        return "</" + _name + ">\n";
    }
    
    std::string attributes() const {
        std::stringstream ss;
        for (const Attribute& item : _attributes) {
            ss << item.toSvg();
        }
        return ss.str();
    }

};
    
}
}
}

#endif /* SVGELEMENT_H */

