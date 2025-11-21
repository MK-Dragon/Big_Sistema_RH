// Model/Course.h

#pragma once
#include <string>
#include <vector>


struct Course {
    std::string nome_curso;
    std::string completion_date;
};

inline bool operator==(const Course& lhs, const Course& rhs) {
    return (lhs.nome_curso == rhs.nome_curso) && 
           (lhs.completion_date == rhs.completion_date);
}