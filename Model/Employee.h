// Model/Employee.h

#pragma once
#include <string>
#include <vector>

#include "Dates.h"


struct Employee {
    int id;
    std::string name;
    
    /*std::string birthday;
    std::string phone;*/

    std::vector <Date> vacations;
    std::vector <Date> absences;
};
