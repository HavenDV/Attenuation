/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Document.h
 * Author: llazar
 *
 * Created on 2016. november 23., 14:06
 */

#ifndef DOCUMENT_H
#define DOCUMENT_H

namespace geom {
namespace io {    
namespace svg {  
    
  
//class Document
//{
//public:
//    Document(std::string const & file_name)
//        : file_name(file_name) { }
//
//    Document & operator<<(Shape const & shape)
//    {
//        body_nodes_str += shape.toString(layout);
//        return *this;
//    }
//    std::string toString() const
//    {
//        std::stringstream ss;
//        ss << "<?xml " << attribute("version", "1.0") << attribute("standalone", "no")
//            << "?>\n<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" "
//            << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n<svg "
//            << attribute("width", layout.dimensions.width, "px")
//            << attribute("height", layout.dimensions.height, "px")
//            << attribute("xmlns", "http://www.w3.org/2000/svg")
//            << attribute("version", "1.1") << ">\n" << body_nodes_str << elemEnd("svg");
//        return ss.str();
//    }
//    bool save() const
//    {
//        std::ofstream ofs(file_name.c_str());
//        if (!ofs.good())
//            return false;
//
//        ofs << toString();
//        ofs.close();
//        return true;
//    }
//private:
//    std::string file_name;
////    Layout layout;
//
//    std::string body_nodes_str;
//};

}
}
}

#endif /* DOCUMENT_H */

