/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ChartistReport.h
 * Author: llazar
 *
 * Created on 2016. november 24., 21:29
 */

#ifndef CHARTISTREPORT_H
#define CHARTISTREPORT_H

#include <vector>
#include <map>

namespace report {

class ReportHelper {
protected:
    std::string m_Template;
    std::string m_Directory;
public:
    ReportHelper(const std::string & directory, const std::string & templatefile) : m_Directory(directory), m_Template(templatefile) { }
    ReportHelper(const ReportHelper& orig);
    virtual ~ReportHelper();
    
    void createReport(std::map<std::string, std::string>& dictionary);
private:

};

}

#endif /* CHARTISTREPORT_H */

