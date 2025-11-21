// UI/UI.h

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

#include <cstdlib>
void clearScreenANSI() {
    // \033[2J clears the screen, \033[1;1H moves the cursor to the top-left (row 1, column 1)
    std::cout << "\033[2J\033[1;1H";
    //std::cout << "\n\n\n" << std::endl;
}



// Main Menu
void printMainMenu(){
    clearScreenANSI();

    // Header
    std::cout << "* Main Menu *" << std::endl;
    std::cout << "* --------- *"<< std::endl;
    
    std::cout << std::endl;

    // Options
    std::cout << "(1) List Employees " << std::endl;
    std::cout << "(2) Add Employee" << std::endl;

    std::cout << std::endl;

    std::cout << "(3) Mark Vacation" << std::endl;
    std::cout << "(4) Remove Vacation" << std::endl;

    std::cout << std::endl;

    std::cout << "(5) Mark absences" << std::endl;
    std::cout << "(6) Remove absences" << std::endl;

    std::cout << std::endl;

    std::cout << "(7) Employee's Monthly Calendar" << std::endl;

    std::cout << std::endl;

    std::cout << "(8) Employee's Monthly Report" << std::endl;
    std::cout << "(9) Find Employee By Name or ID" << std::endl;

    std::cout << std::endl;

    std::cout << "(10) Add New Department" << std::endl;
    std::cout << "(11) Change Employee's Department" << std::endl;
    std::cout << "(12) Department Status" << std::endl;

    std::cout << std::endl;

    std::cout << "(13) Monthly Dashboard" << std::endl;

    std::cout << std::endl;

    std::cout << "(14) Courses" << std::endl;
    std::cout << "(15) Notes" << std::endl;

    std::cout << std::endl;
    std::cout << "(16) Export Employee's Report" << std::endl;
    std::cout << "(17) Export Department's Report" << std::endl;

    // Exit
    std::cout << std::endl;
    std::cout << "(0) Exit" << std::endl;
    std::cout << "> "; // for user input
}



// Add Employee
void printAddEmployee_name(){
    clearScreenANSI();
    std::cout << "* Add Employee *" << std::endl;
    std::cout << "* ------------ *"<< std::endl;

    std::cout << "Name: "; // for user input
}



// List Employees - Helper Funtion
void printEmployees(std::vector <Employee> emp_list){
    for (auto &&emp : emp_list)
    {
        std::cout << "[" << emp.id << "] " << emp.name
        << " - " << emp.departement.name_department
        << "\n";
    }
}
// List Employees - ** Function **
void printListOfEmployees(std::vector <Employee> emp_list){
    clearScreenANSI();
    std::cout << "* List of Empoyees *" << std::endl;
    std::cout << "* ---------------- *"<< std::endl;

    printEmployees(emp_list);    
}



// ASK generic:
void printEnterValue(std::string title, std::string ask){
    clearScreenANSI();

    std::cout << "* " << ANSI_COLOR_YELLOW << title << ANSI_COLOR_RESET << " *" << std::endl;
    
    std::cout << "* ";
    for (int i = 0; i < title.size(); i++)
    {
            std::cout << "-";
    }
    std::cout << " *"<< std::endl;
    
    std::cout << ask << ": "; // for user input
}



// Choose Employee:
void printChooseEmployee(std::string title, std::vector <Employee> emp_list){
    clearScreenANSI();

    std::cout << "* " << title << " *" << std::endl;
    printEmployees(emp_list);
    std::cout << "\tEmployee number: "; // for user input
}


// Choose Day - Helper Function:
void printDays(std::string title, std::vector<Date> days){
    std::cout << title << ":" << std::endl;
    for (auto &day : days) {
        std::cout << "\t< " << day.day << "-" << day.month << "-" << day.year << " >\n"; // for user input
    }
}
// Choose Day - ** Function **
void printChooseDay(std::string title, std::vector<Date> vac_days, std::vector<Date> abs_days){
    clearScreenANSI();
    std::cout << "* " << title << " *" << std::endl;

    std::cout << "* ";
    for (int i = 0; i < title.size(); i++)
    {
            std::cout << "-";
    }
    std::cout << " *"<< std::endl;

    if (vac_days.size() != 0) {
        printDays("Vacation Days", vac_days);
    }
    if (abs_days.size() != 0) {
        printDays("Absence Days", abs_days);
    }
    std::cout << "Date (dd-mm-yyyy): "; // for user input
}



// Find Employee by NAME OR ID
void printFindEmployee(int maxID){
    clearScreenANSI();
    std::cout << "* " << "Find Employee" << " *" << std::endl;
    std::cout << "Insert Name or ID (ID between 1 and " << maxID << ")" << std::endl;
    std::cout << "> "; // for user input
}

void printEmployee_Info(Employee emp){
    clearScreenANSI();
    std::cout << "* " << emp.name << " *" << std::endl;
    std::cout << "Department: " << emp.departement.name_department << std::endl;
    std::cout << "Formação: " << emp.name << std::endl;
    std::cout << "Notas: " << emp.name << std::endl;
    
    std::cout << "-- --" << std::endl;
}

void printNumberDays(std::string title, std::vector<Date> days){
    std::cout << title << ": " << days.size() << std::endl;
}



// --- Main Calendar Function ---   *** IT WORKS!!! DO NOT TOUCH!!! ***
void printCalendarMarked(
    const std::string& month_name, 
    int days_in_month, 
    int start_day_of_week, // 0 = Domingo, 6 = Sábado
    // NEW PARAMETERS for two sets of dates and their markers
    const std::vector<Date>& vacations, 
    char vacation_marker,
    const std::vector<Date>& absences, 
    char absence_marker
) {
    // ... (Input validation omitted for brevity)

    // 1. Print the Month Title
    std::cout << "\n-----------------------------\n";
    std::cout << std::setw(20) << std::right << month_name << "\n";
    std::cout << "-----------------------------\n";

    // 2. Print Weekday Headers
    std::cout << "Sun Mon Tue Wed Thu Fri Sat\n";

    // 3. Print the Empty Spacing
    for (int i = 0; i < start_day_of_week; ++i) {
        std::cout << "    "; 
    }

    // 4. Print the Days
    int current_day_of_week = start_day_of_week;

   for (int day = 1; day <= days_in_month; ++day){
        // Check for a marker in either list
        char marker = ' '; // Default to space
        
        // Check Vacation list
        //if (vacations.size() == 0)
        //{
            // just look cute ^_^  and Please don't Crash
        //}
        //else 
        if (std::find_if(vacations.begin(), vacations.end(), 
            [day](const Date& d) { return d.day == day; }) != vacations.end()) 
        {
            marker = vacation_marker;
        } 
        // Check Absence list (ONLY if not already a Vacation. If a day can be BOTH, 
        // you need a more complex system, like a char for each, e.g., 'VA')
        else if (std::find_if(absences.begin(), absences.end(), 
            [day](const Date& d) { return d.day == day; }) != absences.end()) 
        {
            marker = absence_marker;
        }

        // Print the day number and marker
        // Using setw(2) for the day, and then printing the marker and an alignment space
        std::cout << std::setw(2) << day;
        if (marker != ' ') {
            std::cout << marker << " "; // Marker + 1 space
        } else {
            std::cout << "  "; // 2 spaces to maintain column width
        }
        
        // Move to the next day of the week
        current_day_of_week++;

        // If we reach the end of the week (Saturday), start a new line
        if (current_day_of_week % 7 == 0) {
            std::cout << "\n";
            current_day_of_week = 0; // Reset to Sunday (0)
        }
    }

    // 5. Final Formatting
    std::cout << "\n-----------------------------\n";
}



// Print Monthly Report
void printMonthlyReport_Header(Date date){
    std::cout << "* " << "Monthly Report " << nomeMes(date.month) << " " << date.year << " *" << std::endl;
    std::cout << "-- --" << std::endl;
    std::cout << "-- --" << std::endl;
}
void printMonthlyReport_Emp(Date date, std::string emp_name, std::vector <Date> vacations, std::vector <Date> absences){
    printCalendarMarked(
        emp_name,
        diasNoMes(date.month, date.year),
        diaSemana(1, date.month, date.year),
        vacations,
        'V',
        absences,
        'A'
    );
    std::cout << "Number of Vacation days: " << vacations.size() << std::endl;
    std::cout << "Number of Absente days: " << absences.size() << std::endl;
    std::cout << "-- --" << std::endl;
}
void printMonthlyReport_Footer(Date date, int num_vac, int num_abs, std::vector <Date> vacations, std::vector <Date> absences){
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "-- --" << std::endl;
    std::cout << "-- --" << std::endl;

    std::cout << "* " << "Totals for " << nomeMes(date.month) << " " << date.year << " *" << std::endl;
    std::cout << "Number of Vacation days: " << num_vac << std::endl;
    std::cout << "Number of Absente days: " << num_abs << std::endl;
    std::cout << std::endl;

    printCalendarMarked(
        "Days with Missing Employes",
        diasNoMes(date.month, date.year),
        diaSemana(1, date.month, date.year),
        vacations,
        'X',
        absences,
        'X'
    );
    std::cout << std::endl;
}


// Print List of Departments - Helper Funtion
void printDepartments(std::vector <Department> departments)
{
    for (auto &&dep : departments)
    {
        std::cout << "> [" << dep.id<< "] " << dep.name_department << std::endl;
    }
}
// Add Departement
void printAddDepartment_Name(std::vector <Department> departments){
    clearScreenANSI();
    std::cout << "* " << "Add New Department" << " *" << std::endl;
    std::cout << "* " << "------------------" << " *" << std::endl;
    
    printDepartments(departments);

    std::cout << std::endl;
    std::cout << "Enter New Department Name" << std::endl;
    std::cout << "> "; // for user input
}
// Choose Departement
void printChooseDepartment_Name_ID(std::vector <Department> departments){
    clearScreenANSI();
    std::cout << "* " << "Choose New Department" << " *" << std::endl;
    std::cout << "* " << "---------------------" << " *" << std::endl;
    
    printDepartments(departments);

    std::cout << std::endl;
    std::cout << "Enter Department ID or Name" << std::endl;
    std::cout << "> "; // for user input
}

// Department Status
void printDepartmentStatus(std::vector <Department> deps, std::vector <StatusDepartment> all_status, int max_abs) {
    clearScreenANSI();
    std::cout << "* " << "Department Status" << " *" << std::endl;
    std::cout << "* " << "-----------------" << " *" << std::endl;

    std::cout << "ID" << "\t" << "Name" << "\t\t" << "Vac" << "\t" << "Abs" << std::endl;
    for (auto &&dep : deps)
    {
        // get status
        StatusDepartment sd;
        for (auto &&s : all_status)
        {
            if (dep.id == s.id)
            {
                sd = s;
            }
        }
        if (sd.num_abs == max_abs)
        {
            std::cout << ANSI_COLOR_RED << dep.id << "\t" << dep.name_department << "\t\t" << sd.num_vac << "\t" << sd.num_abs << ANSI_COLOR_RESET << std::endl;
        }
        else
        {
            std::cout << dep.id << "\t" << dep.name_department << "\t\t" << sd.num_vac << "\t" << sd.num_abs << std::endl;
        }
        //std::cout << std::endl;
    }
}


void printDashboard_Emp(std::string name, int num_vac, int num_abs, int vac_left)
{
    std::cout << name << "\t" << num_vac << "\t" << num_abs << "\t" << vac_left << std::endl;
}
void printDashboard_Header(Date date)
{
    clearScreenANSI();
    std::cout << "* " << "Monthly Dashboard " << nomeMes(date.month) << " " << date.year << " *" << std::endl;
    std::cout << "-- --" << std::endl;
}



// Menu CRUD Notes / Courses
void crud_printCrudMenu(std::string emp_name, std::string crud_item)
{
    clearScreenANSI();

    // Header
    std::cout << "* " << crud_item << ": " << emp_name << std::endl;
    std::cout << "* --------- *"<< std::endl;
    std::cout << std::endl;

    // Options
    std::cout << "(1) Add " << crud_item << std::endl;
    std::cout << "(2) Edit " << crud_item << std::endl;
    std::cout << "(3) Remove " << crud_item << std::endl;
    std::cout << "(4) List " << crud_item << std::endl;

    // Exit
    std::cout << std::endl;
    std::cout << "(0) Back" << std::endl;
    std::cout << "> "; // for user input
}

void crud_print_list_Header(std::string crud_item, std::string emp_name)
{
    clearScreenANSI();
    // Header
    std::cout << "* List " << crud_item << ": " << emp_name << std::endl;
    std::cout << "* --------- *"<< std::endl;
    std::cout << std::endl;
}
void crud_print_list_Item(std::string item, std::string date)
{
    std::cout << "> " << item << " | " << date << std::endl;
}
void crud_print_list_Item_Index(int i, std::string item, std::string date)
{
    std::cout << "[" << i << "] " << item << " | " << date << std::endl;
}
void crud_print_ask(std::string ask)
{
    std::cout << ask << ": "; // for user input
}


// General Use
void showPressAnyKey(){
    std::cout << "\nPress Any Key to Continue" << std::endl;
    char key = _getch();
}

void showError(std::string errorTitle, std::string errorMessage)
{
    std::cout << ANSI_COLOR_RED << "\nX " << errorTitle << " X" << ANSI_COLOR_RESET << std::endl;
    std::cout << errorMessage << std::endl;
    showPressAnyKey();
}