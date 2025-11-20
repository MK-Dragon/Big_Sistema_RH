// Utils/CSV_Manager.h

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

#include "DEncript.h"

namespace fs = std::filesystem;
int key = 93;



bool Check_File_Exists(std::string FILE_NAME)
{
    // 1. Construct a path object
    fs::path p(FILE_NAME);
    
    // 2. Use fs::exists()
    return fs::exists(p);
}


std::vector<std::string> split_string(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    
    // 1. Create a stringstream from the input string
    std::stringstream ss(s);
    std::string token;
    
    // 2. Use std::getline to extract tokens up to the delimiter
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    
    return tokens;
}


std::ofstream create_file_with_dirs(const std::string& filepath) {
    // 1. Determine the directory path
    fs::path p(filepath);
    fs::path dir = p.parent_path();

    // 2. Check if the directory is specified and if it exists
    if (!dir.empty()) {
        if (!fs::exists(dir)) {
            std::cout << "🗂️ Directory does not exist. Creating: " << dir << std::endl;
            try {
                // fs::create_directories creates the necessary path hierarchy recursively
                if (!fs::create_directories(dir)) {
                    // This case handles a rare success (e.g., another thread created it) 
                    // but the primary check is the exception below.
                    std::cerr << "⚠️ Could not confirm directory creation for: " << dir << std::endl;
                }
            } catch (const fs::filesystem_error& e) {
                // Handle permission denied or other system errors
                std::cerr << "🚨 Error creating directory " << dir << ": " << e.what() << std::endl;
                // Return a closed stream to signal failure
                return std::ofstream(); 
            }
        }
    }

    // 3. Create/Open the file
    // std::ofstream constructor will create the file if it doesn't exist.
    std::ofstream output_file(filepath);

    if (!output_file.is_open()) {
        std::cerr << "🚨 Error: Could not open/create file: " << filepath << std::endl;
    } else {
        std::cout << "✅ File successfully opened/created: " << filepath << std::endl;
    }
    
    return output_file;
}



// Department helper Funtions
bool checkDepartementIdExists(int dep_id, std::vector<Department> list_dep)
{
    for (auto &&dep : list_dep)
    {
        if (dep.id == dep_id)
        {
            return true;
        }
    }
    return false;
}
Department get_department_from_id(int id, std::vector<Department> list_dep)
{
    for (auto &&dep : list_dep)
    {
        if (dep.id == id)
        {
            return dep;
        }
    }
    return {0, "Null"};
}




bool write_csv(const std::string& filename, const std::vector<Employee>& list_emp) {
    // Open the file for writing.
    std::ofstream ofs(filename);
    

    if (!ofs.is_open()) {
        // NOTE: If this fails, the directories might not exist. 
        // C++ ofstream cannot create missing directories.
        //std::cerr << "🚨 Error: Could not open/create file " << filename << " for writing." << std::endl;
        //std::cerr << "Please ensure the directory path exists." << std::endl;
        std::cout << "Creating File and Dir " << filename << std::endl;

        // create Folder and File if needed
        ofs = create_file_with_dirs(filename);
        // reTest
        if (!ofs.is_open())
        {
            std::cerr << "Error: Could not open/create file " << filename << " for writing." << std::endl;
            std::cerr << "Please ensure the directory path exists." << std::endl;
            return false;
        }
    }

    // Write the header row
    ofs << "Id,Name,Vacations,Absences,Departement" << std::endl;

    // Write the data rows
    
    for (const auto& emp : list_emp) {
        // vaction -> String
        std::string vacations;
        bool first = true;
        if (emp.vacations.size() == 0)
        {
            vacations = "0-0-0";
        }
        
        for (const auto& day : emp.vacations)
        {
            if (!first)
            {
                vacations += "+";
                
            }
            vacations += parse_to_string(day);
            first = false;
        }

        // Absences -> String
        std::string absences;
        first = true;
        if (emp.absences.size() == 0)
        {
            absences = "0-0-0";

        }
        for (const auto& day : emp.absences)
        {
            if (!first)
            {
                absences += "+";
                
            }
            absences += parse_to_string(day);
            first = false;
        }
        
        // Save line to File!
        std::string line_buffer = std::to_string(emp.id) + ',' + emp.name + ',' + vacations + "," + absences + "," + std::to_string(emp.departement.id);
        ofs <<  encriptar(line_buffer, key) << std::endl;
    }

    ofs.close();
    std::cout << "Data successfully written to " << filename << std::endl;
    return true;
}




std::vector<Employee> read_csv(const std::string& filename, std::vector<Department> list_dep) {
    // no  more Magic Numbers! ^_^
    const int seg_id = 0;
    const int seg_name = 1;
    const int seg_vac = 2;
    const int seg_abs = 3;
    const int seg_dep = 4;

    const int num_seg = 5; // total num of segments!

    std::vector<Employee> list_employees;
    std::ifstream ifs(filename);

    if (!ifs.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for reading." << std::endl;
        return list_employees; // Return an empty vector
    }

    std::string line;
    // Read and discard the header line
    if (!std::getline(ifs, line)) {
        std::cout << "File is empty or only contains a header." << std::endl;
        return list_employees;
    }

    // Read the rest of the lines (data)
    while (getline(ifs, line)) {
        std:: cout << "\t\tread_csV -> Reading RAW line: " << line << "\n";
        line = desencriptar(line, key);
        std:: cout << "\t\tread_csV -> Reading Decripted line: " << line << "\n";

        std::stringstream ss(line);
        std::string segment;
        std::vector<std::string> segments;

        // Split the line by the delimiter (comma)
        while (getline(ss, segment, ',')) {
            // Remove potential carriage return from the last field (\r\n for Windows)
            segment.erase(std::remove(segment.begin(), segment.end(), '\r'), segment.end());
            segments.push_back(segment);
        }

        // We expect exactly 3 fields
        if (segments.size() == num_seg) {
            Employee emp;
            
            try {
                emp.id = std::stoi(segments[seg_id]);
                emp.name = segments[seg_name];

                // Check and get department
                int dep_id = std::stoi(segments[seg_dep]);
                if (checkDepartementIdExists(dep_id, list_dep))
                {
                    emp.departement = get_department_from_id(dep_id, list_dep);
                }

                // Parse Dates:
                // splite ;
                std::vector<std::string> vac_strings = split_string(segments[seg_vac], '+');
                std::vector<std::string> abs_strings = split_string(segments[seg_abs], '+');
                // for date in list -> parse to Date
                for (const auto& date_string : vac_strings)
                {
                    Date date_date = parse_date(date_string);
                    if (date_date.day != 0 && date_date.month != 0 && date_date.year != 0)
                    {
                        emp.vacations.push_back(date_date);
                    }
                }
                for (const auto& date_string : abs_strings)
                {
                    Date date_date = parse_date(date_string);
                    if (date_date.day != 0 && date_date.month != 0 && date_date.year != 0)
                    {
                        emp.absences.push_back(date_date);
                    }
                }
                list_employees.push_back(emp);

            } catch (const std::exception& e) {
                std::cerr << "Data conversion error on line: " << line << " (" << e.what() << ")" << std::endl;
            }
        } else {
            std::cerr << "Warning: Skipping malformed line with " << segments.size() << " fields: " << line << std::endl;
        }
    }
    ifs.close();
    std::cout << "Data successfully read from " << filename << std::endl;
    return list_employees;
}





bool write_department_csv(const std::string& filename, const std::vector<Department>& list_dep) {
    // Open the file for writing.
    std::ofstream ofs(filename);
    

    if (!ofs.is_open()) {
        // NOTE: If this fails, the directories might not exist. 
        // C++ ofstream cannot create missing directories.
        //std::cerr << "🚨 Error: Could not open/create file " << filename << " for writing." << std::endl;
        //std::cerr << "Please ensure the directory path exists." << std::endl;
        std::cout << "Creating File and Dir " << filename << std::endl;

        // create Folder and File if needed
        ofs = create_file_with_dirs(filename);
        // reTest
        if (!ofs.is_open())
        {
            std::cerr << "Error: Could not open/create file " << filename << " for writing." << std::endl;
            std::cerr << "Please ensure the directory path exists." << std::endl;
            return false;
        }
    }

    // Write the header row
    ofs << "Id,Name" << std::endl;

    // Write the data rows
    
    for (const auto& dep : list_dep) {
        
        
        // Save line to File!
        std::string line_buffer = std::to_string(dep.id) + ',' + dep.name_department;
        ofs <<  encriptar(line_buffer, key) << std::endl;
    }

    ofs.close();
    std::cout << "Data successfully written to " << filename << std::endl;
    return true;
}


std::vector<Department> read_department_csv(const std::string& filename) {
    // no  more Magic Numbers! ^_^
    const int seg_id = 0;
    const int seg_name = 1;

    const int num_seg = 2; // total num of segments!

    std::vector<Department> list_departments;
    std::ifstream ifs(filename);

    if (!ifs.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for reading." << std::endl;
        return list_departments; // Return an empty vector
    }

    std::string line;
    // Read and discard the header line
    if (!std::getline(ifs, line)) {
        std::cout << "File is empty or only contains a header." << std::endl;
        return list_departments;
    }

    // Read the rest of the lines (data)
    while (getline(ifs, line)) {
        std:: cout << "\t\tread_csV -> Reading RAW line: " << line << "\n";
        line = desencriptar(line, key);
        std:: cout << "\t\tread_csV -> Reading Decripted line: " << line << "\n";

        std::stringstream ss(line);
        std::string segment;
        std::vector<std::string> segments;

        // Split the line by the delimiter (comma)
        while (getline(ss, segment, ',')) {
            // Remove potential carriage return from the last field (\r\n for Windows)
            segment.erase(std::remove(segment.begin(), segment.end(), '\r'), segment.end());
            segments.push_back(segment);
        }

        // We expect exactly 3 fields
        if (segments.size() == num_seg) {
            Department dep;
            
            try {
                dep.id = std::stoi(segments[seg_id]);
                dep.name_department = segments[seg_name];

                list_departments.push_back(dep);

            } catch (const std::exception& e) {
                std::cerr << "Data conversion error on line: " << line << " (" << e.what() << ")" << std::endl;
            }
        } else {
            std::cerr << "Warning: Skipping malformed line with " << segments.size() << " fields: " << line << std::endl;
        }
    }
    ifs.close();
    std::cout << "Data successfully read from " << filename << std::endl;
    return list_departments;
}


