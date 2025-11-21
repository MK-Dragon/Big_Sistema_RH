// Controller/HResources.cpp

#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // Required for std::remove

#include "HResources.h"
#include "../Model/Employee.h"
#include "../Model/Dates.h"



// Helper Funtions
bool HResources::checkEmployeeExists(Employee& emp)
{
    for (auto &&e : list_of_employees)
    {
        if (emp.name == e.name)
        {
            return true; // He/she does Exist!
        }
    }
    return false; // Nop! With don't have that one!
}

bool HResources::checkEmployeeNameExists(std::string name)
{
    for (auto &&e : list_of_employees)
    {
        if (name == e.name)
        {
            return true; // He/she does Exist!
        }
    }
    return false; // Nop! With don't have that one!
}

bool HResources::checkEmployeeIdExists(int id)
{
    for (auto &&e : list_of_employees)
    {
        if (id == e.id)
        {
            return true; // He/she does Exist!
        }
    }
    return false; // Nop! With don't have that one!
}

int HResources::checkDateExists(Date day, Employee &emp)
{
    for (auto &&d : emp.vacations)
    {
        if (day.day == d.day && day.month == d.month && day.year == d.year)
        {
            return 1; // it's a Vacations Day
        }
    }
    for (auto &&d : emp.absences)
    {
        if (day.day == d.day && day.month == d.month && day.year == d.year)
        {
            return 2; // It's an Absence Day
        }
    }
    return 0; // Nop! With don't have that one!
}

bool check_emp_vac_abs_date(Date date, Employee emp)
{
    /* checks if emp has vaction or absences in the month&year*/
    for (auto &&d : emp.vacations)
    {
        if (d.month == date.month && d.year == date.year)
        {
            return true;
        } 
    }
    for (auto &&d : emp.absences)
    {
        if (d.month == date.month && d.year == date.year)
        {
            return true;
        } 
    }
    return false;
}

bool HResources::checkDepartementNameExists(std::string dep_name)
{
    for (auto &&dep : department_list)
    {
        if (dep.name_department == dep_name)
        {
            return true;
        }
    }
    return false;
}
bool HResources::checkDepartementIdExists(int dep_id)
{
    for (auto &&dep : department_list)
    {
        if (dep.id == dep_id)
        {
            return true;
        }
    }
    return false;
}

bool HResources::checkVacationOnDepartment(Date day, int id_department)
{
    for (auto &&emp : get_employes_from_department(id_department))
    {
        for (auto &&d : emp.vacations)
        {
            if (d.day == day.day && d.month == day.month && d.year == day.year)
            {
                return true;
            }
        }
    }
    return false;
}



// List Employees
std::vector <Employee> HResources::get_list_employees()
{
    return list_of_employees;
}

// Get ALL Employees with vacation or Absence:
std::vector <Employee> HResources::get_employee_with_vac_abs(Date date)
{
    std::vector <Employee> emps;
    for (auto &&emp : list_of_employees)
    {
        if (check_emp_vac_abs_date(date, emp))
        {
            emps.push_back(emp);
        }
    }
    return emps;
}



// Add NEW Employee
void HResources::add_employee(std:: string name)
{
    Employee new_emp {
        next_id,
        name,
        std::vector<Date>{},
        std::vector<Date>{},
        {}
    };
    list_of_employees.push_back(new_emp);
    next_id++;
}

// Add Loaded Employee
void HResources::add_loaded_employee(int id, std:: string name, std::vector<Date> vacations, std::vector<Date> absences, int dep_id, std::vector<Course> courses, std::vector<Note> notes)
{
    Employee new_emp {
        id,
        name,
        vacations,
        absences,
        this->get_department_from_id(dep_id),
        courses,
        notes
    };
    list_of_employees.push_back(new_emp);
    if (id >= next_id)
    { id++; next_id = id; }
}

// Get Employees by ID:
Employee& HResources::get_employee(int emp_id)
{
    for (int i = 0; i < next_id; i++)
    {
        if (list_of_employees[i].id == emp_id)
        {
            return list_of_employees[i];
        }
    }
    return list_of_employees[0];
}

// Get Employees By Name:
Employee& HResources::get_employee_by_name(std::string name)
{
    for (auto &&emp : list_of_employees)
    {
        if (emp.name == name)
        {
            return emp;
        }
        
    }
    return list_of_employees[0];
}



// Vacation
void HResources::add_vacation(Employee &emp, Date day)
{
    emp.vacations.push_back(day);
}
void HResources::remove_vacation(Employee &emp, Date day_to_remove)
{
    // The erase-remove idiom:
    
    // 1. std::remove goes through the vector and shifts any element that 
    //    DOES NOT match 'day_to_remove' to the front. 
    //    It returns an iterator pointing to the first "removed" (now junk) element.
    auto it = std::remove(emp.vacations.begin(), emp.vacations.end(), day_to_remove);

    // 2. std::vector::erase uses the iterator range (from the result of std::remove 
    //    to the end) to physically delete the elements and resize the vector.
    emp.vacations.erase(it, emp.vacations.end());
}

// Get Vacation
std::vector<Date> HResources::get_vacation_days(Employee &emp, int month, int year)
{
    std::vector<Date> vaction_days;
    //std::cout << "Emp: " << emp.id << " " << emp.name << "\n";
    //std::cout << "Emp Vacation size @ start hr get vacation: " << emp.vacations.size() << "\n";
    for (int i = 0; i < emp.vacations.size(); i++)
    {
        //std::cout << "\tDebug @ get vact:" << emp.vacations[i].day << "-" << emp.vacations[i].month << "-" << emp.vacations[i].year;
        if (emp.vacations[i].month == month && emp.vacations[i].year == year)
        {
            vaction_days.push_back(emp.vacations[i]);
            //std::cout << "\tIN";
        }
        //std::cout << "\n";
    }
    //std::cout << "Vacation size @ Return: " << vaction_days.size() << "\n";
    return vaction_days;
}



// Absences
void HResources::add_absence(Employee &emp, Date day)
{
    emp.absences.push_back(day);
}
void HResources::remove_absence(Employee &emp, Date day_to_remove)
{
    auto it = std::remove(emp.absences.begin(), emp.absences.end(), day_to_remove);
    emp.absences.erase(it, emp.absences.end());
}

// Get Absences
std::vector<Date> HResources::get_absence_days(Employee &emp, int month, int year)
{
    std::vector<Date> absence_days;
    //std::cout << "Emp: " << emp.id << " " << emp.name << "\n";
    //std::cout << "Emp Vacation size @ start hr get vacation: " << emp.vacations.size() << "\n";
    for (int i = 0; i < emp.absences.size(); i++)
    {
        //std::cout << "\tDebug @ get vact:" << emp.vacations[i].day << "-" << emp.vacations[i].month << "-" << emp.vacations[i].year;
        if (emp.absences[i].month == month && emp.absences[i].year == year)
        {
            absence_days.push_back(emp.absences[i]);
            //std::cout << "\tIN";
        }
        //std::cout << "\n";
    }
    //std::cout << "Vacation size @ Return: " << absence_days.size() << "\n";
    return absence_days;
}



// Add NEW Department
void HResources:: add_department(std::string dep_name)
{
    Department new_dep = {
        next_id_department,
        dep_name
    };
    next_id_department++;
    department_list.push_back(new_dep);
}
// Add Loaded Department
void HResources:: add_loaded_department(int dep_id, std::string dep_name)
{
    Department new_dep = {
        dep_id,
        dep_name
    };
    department_list.push_back(new_dep);
    if (dep_id >= next_id_department)
    { dep_id++; next_id_department = dep_id; }
}

// Get Departments
std::vector<Department> HResources::get_list_of_departments()
{
    return department_list;
}

// Get Department from ID
Department HResources:: get_department_from_id(int id)
{
    for (auto &&dep : department_list)
    {
        if (dep.id == id)
        {
            return dep;
        }
    }
    return {0, "Null"};
}

Department HResources::get_department_by_name(std::string name)
{
    for (auto &&dep : department_list)
    {
        if (dep.name_department == name)
        {
            return dep;
        }
        
    }
    return {0, "Null"};
}

// Get Employes from Departments
std::vector<Employee> HResources::get_employes_from_department(int id_department)
{
    std::vector<Employee> emps;
    for (auto &&emp : list_of_employees)
    {
        if (emp.departement.id == id_department)
        {
            emps.push_back(emp);
        }
    }
    return emps;
}

// Change Employees Department
void HResources::change_employees_department(Employee &emp, int id_department)
{
    for (auto &&dep : department_list)
    {
        if (dep.id == id_department)
        {
            emp.departement = dep;
        }
    }
}



// Status for Department
std::vector <StatusDepartment> HResources::run_status_for_department()
{
    status_departments.clear();
    max_abs = 0;

    for (auto &&dep : department_list)
    {
        StatusDepartment sd { dep.id };
        
        // Add abs from all Emps!
        std::vector <Employee> emps = get_employes_from_department(dep.id);
        for (auto &&e : emps)
        {
            sd.num_vac += e.vacations.size();
            sd.num_abs += e.absences.size();
        }
        // Check Max
        if (sd.num_abs > max_abs)
        {
            max_abs = sd.num_abs;
        }
        // save status from department
        status_departments.push_back(sd);
    }
    return status_departments;
}
// Count days in the the year
int HResources::count_VacAbs_year(std::vector<Date> dates, int year)
{
    int num_days = 0;
    for (auto &&d : dates)
    {
        if (d.year == year)
        {
            num_days++;
        }
    }
    return num_days;
}
// get days in year
std::vector<Date> HResources::get_VacAbs_year(std::vector<Date> dates, int year)
{
    std::vector<Date> days;
    for (auto &&d : dates)
    {
        if (d.year == year)
        {
            days.push_back(d);
        }
    }
    return days;
}



// Couse Add
void HResources::add_course(Employee &emp, Course course)
{
    emp.courses.push_back(course);
}
// Course Remove
void HResources::remove_course(Employee &emp, Course course_to_remove)
{
    auto it = std::remove(emp.courses.begin(), emp.courses.end(), course_to_remove);
    emp.courses.erase(it, emp.courses.end());
}
// Course Edit
void HResources::edit_course(Course &course, std::string name, std::string date) // TODO: Test
{
    std::cout << "\tDebug " << name << " | " << date << std::endl;
    course.nome_curso = name;
    course.completion_date = date;
}

// Notes
void HResources::add_note(Employee &emp, Note note)
{
    emp.notes.push_back(note);
}
void HResources::remove_note(Employee &emp, Note note_to_remove)
{
    auto it = std::remove(emp.notes.begin(), emp.notes.end(), note_to_remove);
    emp.notes.erase(it, emp.notes.end());
}
void HResources::edit_note(Note &note, std::string text, std::string date)
{
    note.text = text;
    note.date = date;
}

