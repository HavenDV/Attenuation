/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ChartistReport.cpp
 * Author: llazar
 * 
 * Created on 2016. november 24., 21:29
 */

#include <fstream>

#include "ReportHelper.h"
#include "../util/StringUtils.h"


namespace report {

using namespace std;

ReportHelper::ReportHelper(const ReportHelper& orig) {
}

ReportHelper::~ReportHelper() {
}

void ReportHelper::createReport(map<string, string>& dictionary)
{
    ofstream report;
    report.open("./attenuation_report.html");

    string line;
    ifstream templateFile (m_Directory + m_Template);
    if (templateFile.is_open())
    {
        while ( getline (templateFile, line) )
        {
            for(auto const& entry : dictionary) {
                size_t pos = 0;
                while ((pos = line.find(entry.first, pos)) != string::npos) {
                    line.replace(pos, entry.first.size(), entry.second);
                    pos += entry.second.size();
                }               
            }
            report << line;
        }
        templateFile.close();
    }    
    
    report.close();    
}

}