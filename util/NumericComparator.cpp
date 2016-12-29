/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumericComparator.cpp
 * Author: llazar
 * 
 * Created on 2016. november 9., 13:31
 */

#include "NumericComparator.h"

#include <math.h>

const double NumericComparator::EPSILON = 1.0e-10;

NumericComparator::NumericComparator() {
}

NumericComparator::NumericComparator(const NumericComparator& orig) {
}

NumericComparator::~NumericComparator() {
}

bool NumericComparator::ApproximatelyEqual(double a, double b)
{
    //return fabs(a - b) <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
    double epsilon = (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * NumericComparator::EPSILON;
    if (epsilon < NumericComparator::EPSILON) epsilon = NumericComparator::EPSILON;
    return fabs(a - b) <= (epsilon);
}

bool NumericComparator::EssentiallyEqual(double a, double b)
{
    double epsilon = (fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * NumericComparator::EPSILON;
    if (epsilon < NumericComparator::EPSILON) epsilon = NumericComparator::EPSILON;
    return fabs(a - b) <= (epsilon);
}

bool NumericComparator::GreaterThan(double a, double b)
{
    double epsilon = (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * NumericComparator::EPSILON;
    if (epsilon < NumericComparator::EPSILON) epsilon = NumericComparator::EPSILON;
    return (a - b) > epsilon;
}

bool NumericComparator::LessThan(double a, double b)
{
    double epsilon = (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * NumericComparator::EPSILON;
    if (epsilon < NumericComparator::EPSILON) epsilon = NumericComparator::EPSILON;
    return (b - a) > epsilon;
}

bool NumericComparator::isPositive(const double a)
{
    return NumericComparator::GreaterThan(a, 0.0);
}

bool NumericComparator::isNegative(const double a)
{
    return NumericComparator::LessThan(a, 0.0);
}

bool NumericComparator::isNonNegative(const double a)
{
    double epsilon = fabs(a) * NumericComparator::EPSILON;
    if (epsilon < NumericComparator::EPSILON) epsilon = NumericComparator::EPSILON;
    return (a >=  -epsilon);
}

bool NumericComparator::isNonPositive(const double a)
{
    double epsilon = fabs(a) * NumericComparator::EPSILON;
    if (epsilon < NumericComparator::EPSILON) epsilon = NumericComparator::EPSILON;
    return (a <=  epsilon);
}

bool NumericComparator::GreaterThanOrEqual(double a, double b)
{
    double epsilon = (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * NumericComparator::EPSILON;
    if (epsilon < NumericComparator::EPSILON) epsilon = NumericComparator::EPSILON;
    return (a - b) >= -epsilon;
}

bool NumericComparator::LessThanOrEqual(double a, double b)
{
    double epsilon = (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * NumericComparator::EPSILON;
    if (epsilon < NumericComparator::EPSILON) epsilon = NumericComparator::EPSILON;
   return (b - a) >= -epsilon;
}
