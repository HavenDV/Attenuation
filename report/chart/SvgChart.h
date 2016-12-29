/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SvgChart.h
 * Author: llazar
 *
 * Created on 2016. november 25., 12:23
 */

#ifndef SVGCHART_H
#define SVGCHART_H

#include "../../geom/io/svg/SvgDocument.h"
#include "../../geom/io/svg/Renderer.h"
#include "../../geom/io/svg/Color.h"

namespace report {
namespace chart {
    
using namespace geom::io::svg;





class SvgChart : public SvgDocument {
protected:
    
    
    
    double _minX, _maxX, _minY, _maxY;
    double _gridSpacingX, _gridSpacingY;
    int _margin;
public:
    SvgChart(int width, int height, double gridSpacingX, double gridSpacingY, int margin = 20, const std::string & cssfile = "");
    SvgChart(const SvgChart& orig);
    virtual ~SvgChart();
    
    void setViewport(const double minX, const double minY, const double maxX, const double maxY) {
        _minX = minX;
        _maxX = maxX;
        _minY = minY;
        _maxY = maxY;
    }    
    void createChart(const std::vector<double>& x_values, const std::vector<std::vector<double> >& y_values);
protected:
    void drawGridLines(const Renderer & renderer);
//    void drawAxis

};

}
}

#endif /* SVGCHART_H */

