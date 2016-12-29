/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Serializable.h
 * Author: llazar
 *
 * Created on 2016. november 23., 13:56
 */

#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

namespace geom {
namespace io {    
namespace svg { 

      

//}
    
    
    
class SvgBase
{
public:
    SvgBase() { }
    virtual ~SvgBase() { };
    virtual std::string toSvg(const std::string& css_class_name = "") const  {
    }
    
    // Utility XML/String Functions.
    template <typename T>
    std::string attribute(std::string const & attribute_name,
        T const & value, std::string const & unit = "") const
    {
        std::stringstream ss;
        ss << attribute_name << "=\"" << value << unit << "\" ";
        return ss.str();
    }
    std::string elemStart(std::string const & element_name) const
    {
        return "\t<" + element_name + " ";
    }
    std::string elemEnd(std::string const & element_name) const
    {
        return "</" + element_name + ">\n";
    }
    std::string emptyElemEnd() const
    {
        return "/>\n";
    }
};

}
}
}

#endif /* SERIALIZABLE_H */

