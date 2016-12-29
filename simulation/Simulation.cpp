/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Simulation.cpp
 * Author: llazar
 * 
 * Created on 2016. november 10., 22:06
 */

#include "Simulation.h"
#include "../sources/SourceBase.h"
#include "../geom/Segment.h"
#include "../geom/CVector2D.h"
#include "../sources/FanSource.h"
#include "../util/StringUtils.h"
#include "../geom/io/svg/Group.h"
#include "../geom/io/svg/Transformation.h"
#include "../report/chart/SvgChart.h"
#include "../report/ReportHelper.h"

#include "../rude/config.h"

using namespace rude;


#include <algorithm>
#include <math.h>
#include <sstream>
#include <cstdio>

#ifndef M_PI
#define M_PI		3.14159265358979323846
#endif


using namespace std;

Simulation::Simulation(SourceBase * pSource)
            : m_pSource(pSource)                  
{
    
    double extent = 2.0 * m_pSource->getScannedArea()->getRadius();
    int screenSize = 900;
    m_SvgFrameFile.setCssFileName("./report/simulation.css");
    m_SvgFrameFile.setHeight(screenSize);
    m_SvgFrameFile.setWidth(screenSize);
    std::shared_ptr<geom::io::svg::SvgGroup> pGroup = m_SvgFrameFile.createGroup();
    int center = screenSize / 2;
    pGroup->addTransformation(new geom::io::svg::Translation(center, center));
    const int margin = 10;
    double ratio = (screenSize - 2*margin) / extent;
    pGroup->addTransformation(new geom::io::svg::Scale(ratio, -ratio));
    
//    m_SvgLogFile.open("phantom.htm", std::ios_base::out);
//    m_SvgLogFile << "<svg height=\"900\" width=\"900\" style=\"border:1px solid #000000;\">\n";
//    m_SvgLogFile << "<g id=\"renderer\" transform=\"translate(450, 450) scale(0.75, -0.75)\">\n";
//    m_SvgLogFile.close();
    

}


Simulation::~Simulation() {
    delete m_pSource;
}

void Simulation::initSource()
{
    FanSource* pFanSource = dynamic_cast<FanSource*>(m_pSource);
    if (pFanSource)
    {
        std::vector<geom::CVector2D> referencePoints;
        m_Phantom.getPointsOfInterest(referencePoints, m_projectionOrder);
        pFanSource->initReferencePoints(referencePoints);

    }
}

void Simulation::outputHeader(std::ostream& outStream)
{
    outStream << "CT source modulation no.    1\n";
    outStream << "Attenuation of Some Phantom.\n";
    outStream << "Source trajectory: step\n";
    outStream << "Start angle :         " << StringUtils::formatNumber("%.3lf", m_startAngle) << "\n";
    outStream << "Angular step:            " << StringUtils::formatNumber("%.2lf", m_angularStep) << "\n";
    outStream << "Start height:           " << StringUtils::formatNumber("%.2lf", m_startHeight) <<"\n";
    outStream << "Height step :            " << StringUtils::formatNumber("%.2lf", m_heightStep) << "\n";
    outStream << "Number of steps:        " << getNumberOfSteps() << "\n";
    outStream << "Slice thickness:         5.00\n";
}

int Simulation::getNumberOfSteps() const
{
    double max_height = m_Phantom.getHeight();
    return (360.0 / m_angularStep) * (max_height / m_heightStep) * m_pSource->getBeamCount();
}

void Simulation::createChart(const std::string& name, const std::vector<double>& x_values, 
        std::vector<std::vector<std::vector<double> > >& y_values)
{
    double maxX = *std::max_element(x_values.begin(), x_values.end());
    double maxY = -1.0;
    for (const std::vector<std::vector<double> >& graphs :  y_values) {
        for (const std::vector<double>& graph : graphs) {
            double tempMaxY = *std::max_element(graph.begin(), graph.end());
            if (tempMaxY > maxY) maxY = tempMaxY;
        }
    }
    
    double r = round(log10(maxY));  
    double gridY = pow(10, r-1) * (round(2.0 * (maxY / pow(10, r))) / 2.0);
    const size_t count = y_values.size();
    for (size_t i = 0; i < count; i++)
    {
        report::chart::SvgChart chart1(400, 400, 30.0, gridY, 25, "./report/chart.css");
        std::stringstream ss;
        ss << name << (int)(i*m_heightStep) << ".svg";
        chart1.open(ss.str());
        chart1.setViewport(0.0, 0.0, maxX, maxY);
        chart1.createChart(x_values, y_values[i]);
        chart1.close();
    }
}

void Simulation::createOutputFile(std::ostream& outStream, 
        std::vector<std::vector<std::vector<double> > >& values, const int columnCount)
{
    double maxValue = -1.0;
    for (const std::vector<std::vector<double> >& graphs :  values) {
        for (const std::vector<double>& graph : graphs) {
            double tempMaxY = *std::max_element(graph.begin(), graph.end());
            if (tempMaxY > maxValue) maxValue = tempMaxY;
        }
    }
    
    size_t dataCounter = 0;
    for (std::vector<std::vector<double> >& slice :  values) {
        const size_t steps = slice[0].size();
        for (int j = 0; j < steps; j++) {
            const size_t projCount = slice.size();
            for (int i = 0; i < projCount; i++, dataCounter++) {
                if (m_normalization) {
                    slice[i][j] /= maxValue;
                }
                outStream << " " <<  StringUtils::formatNumber("%.3lf", slice[i][j]);
                if ((dataCounter+1) % columnCount == 0) {
                    outStream << "\n";
                }
            }
        }
    }
}

void Simulation::run()
{
    initSource();
    
    //if (m_simPlotting) {
      //  int i = std::system(" rm ./data/img_*");
//        printf ("The value returned was: %d.\n",i);
//    }
//    if (m_chartPlotting) {
//        int i = std::system(" rm ./data/chart_*");
//        printf ("The value returned was: %d.\n",i);
//    }
    
    const std::string outputDirectory("./data/"); //"c:\\Users\\llazar\\Google Drive\\munka\\atten\\sajat\\data\\");
    
//    double max_height = 300.0;
    //m_startAngle = m_pSource->getPosition().getAngle();
    m_pSource->setAngle(m_startAngle);

    std::ofstream dataFile("attenuation.dat", std::ios_base::out);
    outputHeader(dataFile);
    outputHeader(std::cout);

    std::vector<double> angles; //initialization of x-values
    for (double beta = 0.0; beta < 360.0; beta += m_angularStep) {
        angles.push_back(beta);
    }
       
    int sliceCount = m_Phantom.getHeight() / m_heightStep;
    vector<vector<vector<double> > > allLengths(sliceCount, vector<vector<double> >(m_pSource->getBeamCount()));    //z, proj., angle
    vector<vector<vector<double> > > allAttenuations(sliceCount, vector<vector<double> >(m_pSource->getBeamCount()));    //z, proj., angle

    
    const int row_size = 15;
    std::vector<CVector2D> intersectionPoints;
    double z = 0.0;
    for (int z_index = 0; z_index < sliceCount; z_index++, z += m_heightStep)
    //for (double z = 0.0; z < max_height; z += m_heightStep)
    {        
        m_Phantom.setZ(z);
        initSource();
//        m_SvgLogFile << m_Phantom.toSvg() << "\n";
        
        int angle_index = 0;
        for (double beta = 0.0; beta < 360.0; beta += m_angularStep, angle_index++)
        {
            if (m_simPlotting) {
                std::stringstream ss;
                ss << outputDirectory << "img_" << z << "_" << beta << ".svg";
                m_SvgFrameFile.open(ss.str(), std::ios_base::out);
                m_SvgFrameFile << m_Phantom.toSvg("phantom");
                m_SvgFrameFile << m_pSource->getScannedArea()->toSvg("scanned-area");
            }

            for (int i = 0; i < m_pSource->getBeamCount(); i++)
            {
                std::shared_ptr<geom::Segment> beam = m_pSource->getBeam(i);
                m_Phantom.intersect(beam, intersectionPoints);
                
                double length = calculateTotalLength(beam, intersectionPoints);
                double attenuation = calcAttenuation(length);
                
                allLengths[z_index][i].push_back(length);
                allAttenuations[z_index][i].push_back(attenuation);
                
                intersectionPoints.clear();
            }

            if (m_simPlotting) {
                m_SvgFrameFile.close();
            }                

            m_pSource->rotate(m_angularStep * M_PI / 180.0);
        }
    }
    
    createOutputFile(dataFile, allAttenuations, row_size);
    
    if (m_chartPlotting) {
        std::string path(outputDirectory + "chart_length_"); 
        createChart(path, angles, allLengths);

        path.assign(outputDirectory + "chart_atten_"); 
        createChart(path, angles, allAttenuations);
    }
    
    createReport();

    
    
//    m_SvgLogFile << "</g>\n";
//    m_SvgLogFile << "Sorry, your browser does not support inline SVG.\n";
//    m_SvgLogFile << "</svg>\n";
//    m_SvgLogFile.close();
    
}

double Simulation::calculateTotalLength(std::shared_ptr<geom::Segment> beam, std::vector<CVector2D>& intersectionPoints)
{
    class DistComparator {
    public:
        CVector2D source;
    public:
        DistComparator(CVector2D source0) : source(source0) { }
        bool operator()(CVector2D a, CVector2D b)
        {   
            return (a - source).length2() < (b - source).length2();
        }   
    };
    DistComparator distComparator(m_pSource->getPosition());
    std::sort (intersectionPoints.begin(), intersectionPoints.end(), distComparator); 
//    for (auto& v : intersectionPoints)
//    {
//        std::cout << v << std::endl;
//    }
    CVector2D prevPoint(m_pSource->getPosition());

    double totalLength = 0.0;
    for (int i = 0; i < intersectionPoints.size(); i++)
    {        
        if (i%2 == 0) {            
            std::shared_ptr<Segment> outerSegment(new Segment(prevPoint, intersectionPoints[i]));
            if (m_simPlotting) {            
                m_SvgFrameFile << outerSegment->toSvg("outer-segment");    //toSvg(0.5f, "#000000");
            }

            prevPoint = intersectionPoints[i];

        } else {
            std::shared_ptr<Segment> innerSegment(new Segment(prevPoint, intersectionPoints[i]));

            totalLength += innerSegment->getLength();

            if (m_simPlotting) {
                m_SvgFrameFile << innerSegment->toSvg("inner-segment");
            }

            
            prevPoint = intersectionPoints[i];
        }
    }
    std::shared_ptr<Segment> segment(new Segment(prevPoint, beam->getPoint2()));
    if (m_simPlotting) {
        m_SvgFrameFile << segment->toSvg("outer-segment");
    }
    
    
    //std::cout << "TotalLength = " << totalLength << "\n" <<  std::endl;
//    double attenuation = exp(-0.19 *  totalLength / 10.0);
    return totalLength;
}

double Simulation::calcAttenuation(double length) const
{
    return exp(m_M *  length / 10.0);
}

void Simulation::processInputs(int argc, char** argv)
{
//    if (argc != 9) {
//        std::cout << "Usage: atten start_angle 	angular_step start_height height_step order normalization simulation_plotting chart_plotting" << std::endl;
//        exit(-1);
//    }
    
    rude::Config config;
    
    if(config.load("atten.ini")) {
        config.setSection("source");
        m_startAngle = config.getDoubleValue("start_angle");
        m_angularStep = config.getDoubleValue("angular_step");
        m_startHeight = config.getDoubleValue("start_height");
        m_heightStep = config.getDoubleValue("height_step");
        
        std::string order(config.getStringValue("projecton_order"));
        std::transform(order.begin(), order.end(), order.begin(), ::tolower);
        m_projectionOrder = order;
        
        
        config.setSection("calculation");
        std::string strNormalization(config.getStringValue("normalization"));
        std::transform(strNormalization.begin(), strNormalization.end(), strNormalization.begin(), ::tolower);
        m_normalization = (strNormalization == "on");
        
        m_M = (config.getDoubleValue("m"));
        
        config.setSection("plotting");
        std::string strSimPlotting(config.getStringValue("simulation_plotting"));
        std::transform(strSimPlotting.begin(), strSimPlotting.end(), strSimPlotting.begin(), ::tolower);
        m_simPlotting = (strSimPlotting == "on");
        
        std::string strChartPlotting(config.getStringValue("chart_plotting"));
        std::transform(strChartPlotting.begin(), strChartPlotting.end(), strChartPlotting.begin(), ::tolower);
        m_chartPlotting = (strChartPlotting == "on");
        
    }
    
//    m_startAngle = std::stod(argv[1]);
//    m_angularStep = std::stod(argv[2]);
//    m_startHeight = std::stod(argv[3]);
//    m_heightStep = std::stod(argv[4]);
    
    
    
//    std::string order(argv[5]);
    
    
//    std::string strNormalization(argv[6]);
//    std::transform(strNormalization.begin(), strNormalization.end(), strNormalization.begin(), ::tolower);
//    m_normalization = (strNormalization == "on");
    
    
//    std::string strSimPlotting(argv[7]);
//    std::transform(strSimPlotting.begin(), strSimPlotting.end(), strSimPlotting.begin(), ::tolower);
//    m_simPlotting = (strSimPlotting == "on");
    
//    std::string strChartPlotting(argv[8]);
//    std::transform(strChartPlotting.begin(), strChartPlotting.end(), strChartPlotting.begin(), ::tolower);
//    m_chartPlotting = (strChartPlotting == "on");
    
    //    for (int i = 0; i < argc; ++i) {
//        std::cout << argv[i] << std::endl;
//    }
}

void Simulation::createReport()
{
    report::ReportHelper report("./report/", "attenuation_report_template.html");
    map<string, string> dictionary;
    dictionary["%max_angle%"] = std::to_string(360 - m_angularStep);     
    dictionary["%angular_step%"] = std::to_string(m_angularStep); 
    dictionary["%max_height%"] = std::to_string(m_Phantom.getHeight() - m_heightStep); 
    dictionary["%height_step%"] = std::to_string(m_heightStep); 
    
    report.createReport(dictionary);
    
}

