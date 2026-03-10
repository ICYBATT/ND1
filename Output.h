#pragma once
#include <vector>
#include <string>
#include "Studentas.h"

void isvesti_i_ekrana(const std::vector<Studentas>& grupe);
void isvesti_i_faila(const std::vector<Studentas>& grupe, const std::string& failas);
void isvedimo_pasirinkimas(const std::vector<Studentas>& grupe);