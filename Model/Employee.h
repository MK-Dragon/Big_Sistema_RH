// Model/Employee.h

#pragma once
#include <string>
#include <vector>

#include "Dates.h"
#include "Notas.h"
#include "Formacao.h"


struct Employee {
    int id;
    std::string name;

    std::vector <Date> vacations;
    std::vector <Date> absences;

    std::vector <Nota> notas;
    std::vector <Formacao> formacoes;
};
