#include "Generator.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstdlib>

bool generuoti_studentu_faila(const std::string& failas, int kiekis, int nd_kiekis) {

    std::ofstream out(failas);

    if (!out) {
        std::cout << "Nepavyko sukurti failo\n";
        return false;
    }

    out << std::left << std::setw(25) << "Vardas"
        << std::setw(25) << "Pavarde";

    for (int i = 1; i <= nd_kiekis; i++)
        out << std::setw(10) << ("ND" + std::to_string(i));

    out << std::setw(10) << "Egz." << "\n";

    for (int i = 1; i <= kiekis; i++) {

        out << std::setw(25) << ("Vardas" + std::to_string(i))
            << std::setw(25) << ("Pavarde" + std::to_string(i));

        for (int j = 0; j < nd_kiekis; j++)
            out << std::setw(10) << (rand() % 10 + 1);

        out << std::setw(10) << (rand() % 10 + 1) << "\n";
    }

    return true;
}

void generuoti_visus_testinius_failus() {

    generuoti_studentu_faila("studentai1000.txt", 1000);
    generuoti_studentu_faila("studentai10000.txt", 10000);
    generuoti_studentu_faila("studentai100000.txt", 100000);
    generuoti_studentu_faila("studentai1000000.txt", 1000000);
    generuoti_studentu_faila("studentai10000000.txt", 10000000);

}