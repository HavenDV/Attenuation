/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SvgChart.cpp
 * Author: llazar
 * 
 * Created on 2016. november 25., 12:23
 */

#include <memory>
#include <float.h>
#include <xmmintrin.h>

#include "SvgChart.h"
#include "../../geom/io/svg/SvgLine.h"

#include "../../geom/io/svg/SvgPolyline.h"
#include "../../geom/io/svg/SvgText.h"
#include "../../util/StringUtils.h"

//#include "../../geom/io/svg/simple_svg.hpp"

namespace report {
namespace chart {
    
    using namespace geom::io::svg;

SvgChart::SvgChart(int width, int height, double gridSpacingX, double gridSpacingY, int margin, const std::string & cssfile) :
    SvgDocument(width, height, cssfile), 
    _gridSpacingX(gridSpacingX), _gridSpacingY(gridSpacingY), _margin(margin),
    _minX(DBL_MAX), _maxX(-DBL_MAX), _minY(DBL_MAX), _maxY(-DBL_MAX)
{
    
}

SvgChart::SvgChart(const SvgChart& orig) {
}

SvgChart::~SvgChart() {
}

double renderX(double xi, double scale_x, double xmin)
{    
    return xi * scale_x + xmin;
}

double renderY(double yi, double scale_y, double ymin)
{    
    return yi * scale_y + ymin;
}

void SvgChart::createChart(const std::vector<double>& x_values, const std::vector<std::vector<double> >& y_values) {


//    for (const double& x : x_values) {
//        if (x > _maxX) _maxX = x;
//        if (x < _minX) _minX = x;
//    }
//    for (const std::vector<double>& y_series : y_values) {
//        for (const double& y : y_series) {
//            if (y > _maxY) _maxY = y;
//            if (y < _minY) _minY = y;
//        }
//    }
    
    //_maxY = 350.0;
    Layout viewport(0, 0, m_Width/* - 2*_margin*/, m_Height/* - 2*_margin*/);
    Layout world(0, 0, _maxX, _maxY);
    Renderer renderer(world, viewport, _margin);

    
    drawGridLines(renderer);
    
    int graphIndex = 0;
    for (const std::vector<double>& y_series : y_values) {
        int i = 0;        
        SvgPolyline polyline;
        for (const double& y : y_series) {
            SvgPoint currentPoint (renderer(x_values[i], y));
            polyline << currentPoint;


            i++;
        }        
        polyline.addClass("graph" + std::to_string(graphIndex + 1));
        m_File << polyline.toSvg();
        graphIndex++;
    }
    
    
}

void SvgChart::drawGridLines(const Renderer & renderer)
{
    
    Layout rect = renderer.getWorld();
    {
        int x_grid_count = (int)(rect.range.x / _gridSpacingX) + 1;
        SvgPoint p1(0.0, 0.0);
        SvgPoint p2(0.0, rect.range.y);
        SvgLine gridLineY(renderer(p1), renderer(p2));
        m_File << gridLineY.toSvg();
        SvgPoint dx(_gridSpacingX, 0.0);
        for (int i = 0; i < x_grid_count; i++) {
            p1 += dx;
            p2 += dx;
            gridLineY = SvgLine(renderer(p1), renderer(p2));
            gridLineY.addClass("gridline-y");
            m_File << gridLineY.toSvg();
            
            //label
            SvgPoint pt(p1);
            pt.y -= 14.0 / renderer.getScale().y;
            std::stringstream ss;
            ss << p1.x;
            SvgText labelX(renderer(pt), ss.str()/*StringUtils::formatNumber("%5.1lf", p1.x)*/);
            labelX.addClass("label-x");
            m_File << labelX.toSvg();
        }
    }

    {
        //gridline-x
        int y_grid_count = (int)(rect.range.y / _gridSpacingY) + 1;
        SvgPoint p1(0.0, 0.0);
        SvgPoint p2(rect.range.x, 0.0);
        SvgLine gridLineX(renderer(p1), renderer(p2));
        m_File << gridLineX.toSvg();
        SvgPoint dy(0.0, _gridSpacingY);
        for (int i = 0; i < y_grid_count; i++) {
            p1 += dy;
            p2 += dy;
            gridLineX = SvgLine(renderer(p1), renderer(p2));
            gridLineX.addClass("gridline-x");
            m_File << gridLineX.toSvg();

            //label
            SvgPoint pt(p1);
            pt.x -= 2.0 / renderer.getScale().x;
            pt.y -= 6.0 / renderer.getScale().y;
            std::stringstream ss;
            ss << p1.y;
            SvgText labelY(renderer(pt), ss.str()/*StringUtils::formatNumber("%5.1lf", p1.y)*/);
            labelY.addClass("label-y");
            m_File << labelY.toSvg();
        }
    }
    
}

}
}