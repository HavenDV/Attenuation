/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumericComparator.h
 * Author: llazar
 *
 * Created on 2016. november 9., 13:31
 */

#ifndef NUMERICCOMPARATOR_H
#define NUMERICCOMPARATOR_H

class NumericComparator {
public:
    static const double EPSILON;
public:
    NumericComparator();
    NumericComparator(const NumericComparator& orig);
    virtual ~NumericComparator();
    
    static bool ApproximatelyEqual(double a, double b);
    static bool EssentiallyEqual(double a, double b);
    static bool GreaterThan(double a, double b);
    static bool LessThan(double a, double b);
    static bool GreaterThanOrEqual(double a, double b);
    static bool LessThanOrEqual(double a, double b);
    
    static bool isPositive(const double a);
    static bool isNegative(const double a);
    
    static bool isNonNegative(const double a);
    static bool isNonPositive(const double a);
    
private:

};

#endif /* NUMERICCOMPARATOR_H */

