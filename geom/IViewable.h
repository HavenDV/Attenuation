/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IViewable.h
 * Author: llazar
 *
 * Created on 2016. november 9., 13:05
 */

#ifndef IVIEWABLE_H
#define IVIEWABLE_H

#include "CVector2D.h"
//#include "Angle.h"


namespace geom {

class Angle;
    
class IViewable {
        
    public:
        virtual Angle getFieldOfView(const CVector2D& p0) const = 0;
        
    };
    
}


#endif /* IVIEWABLE_H */

