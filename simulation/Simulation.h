/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Simulation.h
 * Author: llazar
 *
 * Created on 2016. november 10., 22:06
 */

#ifndef SIMULATION_H
#define SIMULATION_H

#include <memory>
#include "../geom/Circle.h"
#include "../geom/CompoundObject.h"
#include "../geom/TestPhantom.h"
#include "../geom/io/svg/SvgDocument.h"
#include <fstream>

#define     FRAME_LOG

class SourceBase;
//class geom::CompoundObject;



class Simulation {
    
protected:
    SourceBase* m_pSource;
    
    geom::CompoundObject m_Phantom;
    
    //std::ofstream m_SvgLogFile;
    
    void initSource();
    //double calculateAttenuation(std::shared_ptr<geom::Segment> beam, std::vector<geom::CVector2D>& intersectionPoints);
    double calculateTotalLength(std::shared_ptr<geom::Segment> beam, std::vector<geom::CVector2D>& intersectionPoints);
    
    double calcAttenuation(double length) const;
    
    void createChart(const std::string& name, const std::vector<double>& x_values, 
        std::vector<std::vector<std::vector<double> > >& y_values);
    
    void createOutputFile(std::ostream& outStream, 
        std::vector<std::vector<std::vector<double> > >& values, const int columnCount = 15);
    
    void createReport();
    
public:
    Simulation(SourceBase * pSource);
    
    virtual ~Simulation();
    
    void run();
    
    void processInputs(int argc, char** argv);

    int getNumberOfSteps() const;
    
private:
    Simulation(const Simulation& orig);
    
    void outputHeader(std::ostream& outStream);
    
    geom::io::svg::SvgDocument m_SvgFrameFile;

    //input paramters
    double m_startAngle;
    double m_angularStep;
    double m_startHeight;
    double m_heightStep;

    std::string m_projectionOrder;
    
    
    bool m_simPlotting;
    bool m_chartPlotting;
    bool m_normalization;
    double m_M;


};

#endif /* SIMULATION_H */

