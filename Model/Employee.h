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

    // Later:
    std::vector <Note> notes;
    std::vector <Course> courses;
};
