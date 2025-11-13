// Controller/HResources.h

#pragma once
#include <iostream>

#include "../Model/Employee.h"
#include "../Model/Dates.h"



struct HResources
{
    // Variables
    std::vector <Employee> list_of_employees;
    int next_id = 0;

    // Helper Functions
    bool checkEmployeeExists(Employee& emp);
    bool checkEmployeeNameExists(std::string name);
    int checkDateExists(Date day, Employee &emp);

    // List Employees
    std::vector <Employee> get_list_employees();

    // Add Employee
    void add_employee(std:: string name);
    void add_loaded_employee(std:: string name, std::vector<Date> vacations, std::vector<Date> absences);

    Employee& get_employee(int emp_id);

    // Vacation
    void add_vacation(Employee &emp, Date day);
    void remove_vacation(Employee &emp, Date day_to_remove);
    std::vector<Date> get_vacation_days(Employee &emp, int month, int year);

    // Absences
    void add_absence(Employee &emp, Date day);
    void remove_absence(Employee &emp, Date day_to_remove);
    std::vector<Date> get_absence_days(Employee &emp, int month, int year);
};

