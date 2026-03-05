#include "Menu.h"
#include "Input.h"
#include <iostream>

int meniu() {
    std::cout << "\nMeniu:\n";
    std::cout << "1 - viska ivedi ranka\n";
    std::cout << "2 - ivedi studentu ir pazymiu kieki, pazymiai generuojami\n";
    std::cout << "3 - viska generuoja programa\n";
    std::cout << "4 - Baigti\n";
    std::cout << "5 - Nuskaityti studentus is failo (v0.2)\n";
    std::cout << "6 - Rikiuoti ir isvesti rezultatus\n";
    return ivesti_skaiciu("Pasirinkimas: ", 1, 6);
}