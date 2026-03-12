#include "Menu.h"
#include "Input.h"
#include <iostream>

int meniu() {
    std::cout << "\n========== MENIU ==========\n";
    std::cout << "1 - Vesti studentus ranka\n";
    std::cout << "2 - Vesti vardus, pazymiai generuojami\n";
    std::cout << "3 - Viską generuoja programa\n";
    std::cout << "4 - Nuskaityti studentus is failo\n";
    std::cout << "5 - Suskirstyti studentus i vargsiukus ir kietiakus\n";
    std::cout << "6 - Rikiuoti ir isvesti dabartine grupe\n";
    std::cout << "7 - Sugeneruoti testinius failus\n";
    std::cout << "8 - Atlikti vieno failo spartos tyrima\n";
    std::cout << "9 - Baigti\n";

    return ivesti_skaiciu("Pasirinkimas: ", 1, 9);
}