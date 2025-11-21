// UI/ReportMaker.h

#pragma once
#include "../Model/Employee.h"
#include "../Model/Dates.h"

#include <string>
#include <iostream>
#include <vector>


std::string __parse_to_string(Date d){
    return std::to_string(d.day) + "-" + std::to_string(d.month) + "-" + std::to_string(d.year);
}

std::string report_header(std::string title)
{
    std::string line = "* " + title + " *";
    int size_title = line.size();

    line += "\n";
    for (int i = 0; i < size_title; i++)
    {
        line += "-";
    }
    
    return line;
}

// Print Emp
std::string report_emp(Employee emp, std::vector<Date> vac_year, std::vector<Date>abs_year, int max_vac)
{
    std::string line = "Report: " + emp.name + " - " + emp.departement.name_department + "\n";

    line += "Vaction Days [" + std::to_string(vac_year.size()) + "/" + std::to_string(max_vac) + "] - " + std::to_string(max_vac-vac_year.size()) +" Days Left\n";
    for (auto &&d : vac_year)
    {
        line += "\t" + __parse_to_string(d) + "\n";
    }
    line += "Absence Days [" + std::to_string(vac_year.size()) + "]\n";
    for (auto &&d : vac_year)
    {
        line += "\t" + __parse_to_string(d) + "\n";
    }
    
    return line;
}

// Print Department Status
std::string report_dep(Department dep, std::vector<Date> vac_year, std::vector<Date>abs_year, int total_days_vac)
{
    std::string line = "Report: " + dep.name_department + ": " + std::to_string(total_days_vac) + " days of vactions on total\n";

    line += "Vaction Days [" + std::to_string(vac_year.size()) + "]\n";
    for (auto &&d : vac_year)
    {
        line += "\t" + __parse_to_string(d) + "\n";
    }
    line += "Absence Days [" + std::to_string(vac_year.size()) + "]\n";
    for (auto &&d : vac_year)
    {
        line += "\t" + __parse_to_string(d) + "\n";
    }
    
    return line;
}
