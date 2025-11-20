#pragma once
#include <string>

struct Department {
    int id;
    std::string name_department;
    int num_vac = 0;
    int num_abs = 0;
    bool highest_abs = false;
};


struct StatusDepartment {
    int id = 0;
    int num_vac = 0;
    int num_abs = 0;
};