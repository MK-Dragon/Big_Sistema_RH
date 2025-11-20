// Model/Employee.h

#pragma once
#include <string>
#include <vector>

#include "Dates.h"
#include "Note.h"
#include "Course.h"
#include "Department.h"


struct Employee {
    int id;
    std::string name;

    std::vector <Date> vacations;
    std::vector <Date> absences;

    Department departement;

    std::vector <Course> courses;
    std::vector <Note> notes;
};
