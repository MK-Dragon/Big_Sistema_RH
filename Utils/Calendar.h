// Utils/Calendar.h

#include <iostream>
#include <string>
#include <sstream>

#include "../Model/Dates.h"



//1. Função para calcular o dia da semana
//Usa a congruência de Zeller para determinar o dia da semana de qualquer data.

int diaSemana(int dia, int mes, int ano) {
    if(mes < 3) { mes += 12; ano--; }
    int k = ano % 100;
    int j = ano / 100;
    int h = (dia + 13*(mes+1)/5 + k + k/4 + j/4 + 5*j) % 7;
    int d = (h + 6) % 7; // 0 = Domingo, 6 = Sábado
    return d;
}


//2. Função para calcular o número de dias num mês
//Esta função deve tratar corretamente anos bissextos.
 
int diasNoMes(int mes, int ano) {
    switch(mes){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return ((ano%4==0 && ano%100!=0) || (ano%400==0)) ? 29 : 28;
        default: return 30;
    }
}

//3. Função auxiliar para o nome do mês
std::string nomeMes(int mes){
    const std::string meses[] = {"Janeiro","Fevereiro","Março","Abril","Maio","Junho",
                                 "Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};
    return meses[mes-1];
}




Date parse_date(const std::string& date_str) {
    Date result = {0, 0, 0}; // Initialize to zero
    
    // 1. Create a stringstream from the input string
    std::stringstream ss(date_str);
    std::string segment;
    char delimiter = '-';
    int part_index = 0;

    // 2. Read segments separated by the delimiter
    while (std::getline(ss, segment, delimiter)) {
        // Convert the string segment to an integer
        try {
            int value = std::stoi(segment);
            
            // 3. Populate the struct fields based on the index
            if (part_index == 0) {
                result.day = value;
            } else if (part_index == 1) {
                result.month = value;
            } else if (part_index == 2) {
                result.year = value;
            }
            part_index++;

        } catch (const std::exception& e) {
            std::cout << "Invalid Format! Please use on this formats: eg 01-02-2025 or 1-2-2025!" << std::endl;
            result = {0, 0, 0};
            return result;
        }
    }
    
    // 3. check mounth size && mounth not Zero!
    if (result.month > 12)
    {
        result = {0, 0, 0};
        return result;
    }
    int num_days = diasNoMes(result.month, result.year);
    if (result.day > num_days || result.day == 0){
        std::cout << "Invalid Date! Please Enter Valid Date" << std::endl;
        result = {0, 0, 0};
        return result;
    }
    //std::cout << "\tDebug: parse @ return: " << result.day << "-" << result.month << "-" << result.year << "\n";
    return result;
}



Date parse_month_year(const std::string& date_str) {
    // Initialize with day = 0 (as requested), month = 0, year = 0
    Date result = {0, 0, 0};
    
    // 1. Create a stringstream from the input string
    std::stringstream ss(date_str);
    std::string segment;
    char delimiter = '-';
    int part_index = 0; // 0 for month, 1 for year
    int segment_count = 0;

    // 2. Read segments separated by the delimiter
    while (std::getline(ss, segment, delimiter)) {
        segment_count++; // Count how many parts we successfully read

        // Convert the string segment to an integer
        try {
            // Trim leading/trailing whitespace if necessary, though std::stoi usually handles it.
            int value = std::stoi(segment);
            
            // 3. Populate the struct fields based on the index
            if (part_index == 0) {
                // The first segment is the MONTH
                result.month = value;
            } else if (part_index == 1) {
                // The second segment is the YEAR
                result.year = value;
            }
            part_index++;

        } catch (const std::exception& e) {
            std::cout << "Invalid Format! Month or year must be a valid number." << std::endl;
            // On error, reset the result and return immediately.
            return {0, 0, 0}; 
        }
    }
    
    // 4. Validate that exactly two parts (Month and Year) were found
    if (segment_count != 2) {
        std::cout << "Invalid Format! Please use the M-YYYY format (e.g., 5-2025)." << std::endl;
        return {0, 0, 0};
    }

    // 5. check mounth size && mounth not Zero!
    if (result.month > 12)
    {
        result = {0, 0, 0};
        return result;
    }
    int num_days = diasNoMes(result.month, result.year);
    if (result.day > num_days){
        std::cout << "Invalid Date! Please Enter Valid Date" << std::endl;
        result = {0, 0, 0};
        return result;
    }

    return result;
}




std::string parse_to_string(Date d){
    return std::to_string(d.day) + "-" + std::to_string(d.month) + "-" + std::to_string(d.year);
}