/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: llazar
 *
 * Created on 2016. november 8., 8:51
 */


//a= exp (0.19*L)


#include <iostream>
#include <memory>
#include <math.h>
#include <vector>

//#include <cmath>
#include <limits>
#include <chrono>
//#include <iomanip>
//#include <iostream>
//#include <type_traits>
//#include <algorithm>

#include "geom/Segment.h" 
#include "geom/Circle.h"
#include "simulation/Simulation.h"
#include "sources/FanSource.h" 

#include "util/StringUtils.h"
#include "report/chart/SvgChart.h"

using namespace std;

using namespace geom;



/*
 * 
 */
int main(int argc, char** argv) {

//    std::cout << "Have " << argc << " arguments:" << std::endl;
//    for (int i = 0; i < argc; ++i) {
//        std::cout << argv[i] << std::endl;
//    }
    
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();


     
    CVector2D sourcePos(595.0, 0.0);
    FanSource* pSource = new FanSource(sourcePos, 595.0);
    Simulation sim(pSource);
    sim.processInputs(argc, argv);
    sim.run();
    
    
//    std::vector<double> x = { 0, 10, 20, 30, 40 };
//    std::vector<std::vector<double> > y = { { 50, 40, 30, 30, 70 }, { 10, 80, 11, 13, 15 } };
    
//    report::chart::SvgChart chart(400, 400, "chart.css");
//    chart.open("chart.svg");
//    chart.createChart(x, y);
//    chart.close();

    
    
    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    std::cout << "\nElapsed time = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() /1000.0 << " sec" << std::endl;
    
//    Line l1(1.0, 1.0, -2, 5);
//    Line l2(0.0, 4.8, 5, 2);
//    std::vector<CVector2D> points;
//    l1.intersect(l2, points);
//    std::cout <<  points[0].x << ", " << points[0].y << endl; 
    
//    Segment segment1(1.0, 1.0, -2, 5);
//    Segment segment2(0.0, 5, 5, 2);
//    std::vector<CVector2D> points;
//    bool inter = segment1.intersect(segment2, points);
//    if (inter) {
//        cout << "Itersects" << endl;
//        std::cout <<  points[0].x << ", " << points[0].y << endl; 
//    }
    
//    std::vector<CVector2D> points;
//    Circle c1(0, 0, 3);
//    Circle c2(0, 6, 3);
//    Segment segment1(0.0, 0.0, 10, 0);
//    c1.intersectionCircleCircle(c2, points);
     
//     shared_ptr<A> a(new A());
//     shared_ptr<B> b(new B());
//     shared_ptr<A> c(new C());
//     
//     dynamic_pointer_cast<B>(a)->print();
//
//     a->print();
//     b->print();
//     c->print();

    
    return 0;
}

