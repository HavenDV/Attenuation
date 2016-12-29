/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Color.h
 * Author: llazar
 *
 * Created on 2016. november 23., 13:54
 */

#ifndef COLOR_H
#define COLOR_H

#include "AbstractAttributeValue.h"

namespace geom {
namespace io {    
namespace svg {  

class Color : public AbstractAttributeValue
{
public:
    enum Defaults { Transparent = -1, None, Aqua, Black, Blue, Brown, Cyan, Fuchsia,
        Green, Lime, Magenta, Orange, Purple, Red, Silver, White, Yellow };

    Color(int r, int g, int b) : transparent(false), red(r), green(g), blue(b) { }
    Color(Defaults color)
        : transparent(false), red(0), green(0), blue(0), none(false)
    {
        switch (color)
        {
            case None: none = true; break;
            case Aqua: assign(0, 255, 255); break;
            case Black: assign(0, 0, 0); break;
            case Blue: assign(0, 0, 255); break;
            case Brown: assign(165, 42, 42); break;
            case Cyan: assign(0, 255, 255); break;
            case Fuchsia: assign(255, 0, 255); break;
            case Green: assign(0, 128, 0); break;
            case Lime: assign(0, 255, 0); break;
            case Magenta: assign(255, 0, 255); break;
            case Orange: assign(255, 165, 0); break;
            case Purple: assign(128, 0, 128); break;
            case Red: assign(255, 0, 0); break;
            case Silver: assign(192, 192, 192); break;
            case White: assign(255, 255, 255); break;
            case Yellow: assign(255, 255, 0); break;
            default: transparent = true; break;
        }
    }
    virtual ~Color() { }
    
    virtual std::string toString() const 
    {
        std::stringstream ss;
        if (none)
            ss << "none";
        else if (transparent)
            ss << "transparent";
        else 
            ss << "rgb(" << red << "," << green << "," << blue << ")";
        return ss.str();
    }
private:
        bool transparent;
        int red;
        int green;
        int blue;
        bool none;

        void assign(int r, int g, int b)
        {
            red = r;
            green = g;
            blue = b;
        }
};
    
    
}
}
}

#endif /* COLOR_H */

