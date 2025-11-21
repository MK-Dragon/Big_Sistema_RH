#pragma once
#include "../Model/Employee.h"
#include "../Model/Dates.h"
#include "../Utils/Calendar.h"

#include <string>
#include <iostream>
#include <conio.h> // Header for _getch()
#include <vector>
#include <unordered_map>

#include <iomanip>
#include <algorithm> // Required for std::find_if
#include <optional> // Requires C++17, but is the cleanest way to return a marker

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"

#define ANSI_COLOR_RESET   "\x1b[0m"

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
    std::string line = "> " + emp.name + " | " + emp.departement.name_department + "\n";

    line += "Vaction Days [" + std::to_string(vac_year.size()) + "/" + std::to_string(max_vac) + "]";
    for (auto &&d : vac_year)
    {
        line += "\t" + parse_to_string(d) + "\n";
    }
    line += "Absence Days [" + std::to_string(vac_year.size()) + "]";
    for (auto &&d : vac_year)
    {
        line += "\t" + parse_to_string(d) + "\n";
    }
    
    return line;
}

// Print Department Status
std::string report_dep(Department dep, std::vector<Date> vac_year, std::vector<Date>abs_year, int max_vac)
{
    std::string line = "> " + dep.name_department + ":\n";

    line += "Vaction Days [" + std::to_string(vac_year.size()) + "/" + std::to_string(max_vac) + "]";
    for (auto &&d : vac_year)
    {
        line += "\t" + parse_to_string(d) + "\n";
    }
    line += "Absence Days [" + std::to_string(vac_year.size()) + "]";
    for (auto &&d : vac_year)
    {
        line += "\t" + parse_to_string(d) + "\n";
    }
    
    return line;
}
