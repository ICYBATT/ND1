#include "Output.h"
#include "Input.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using std::cout;
using std::endl;
using std::left;
using std::setw;
using std::fixed;
using std::setprecision;
using std::ofstream;
using std::string;
using std::vector;

void isvesti_i_ekrana(const vector<Studentas>& grupe) {
    cout << left << setw(15) << "Vardas"
         << setw(20) << "Pavarde"
         << setw(18) << "Galutinis (Vid.)"
         << setw(18) << "Galutinis (Med.)"
         << "\n";

    cout << string(15 + 20 + 18 + 18, '-') << "\n";

    cout << fixed << setprecision(2);
    for (const auto& a : grupe) {
        cout << left << setw(15) << a.vardas
             << setw(20) << a.pavarde
             << setw(18) << a.gal_vid
             << setw(18) << a.gal_med
             << "\n";
    }
}

void isvesti_i_faila(const vector<Studentas>& grupe, const string& failas) {
    ofstream out(failas);
    if (!out) {
        cout << "Nepavyko sukurti failo.\n";
        return;
    }

    out << left << setw(15) << "Vardas"
        << setw(20) << "Pavarde"
        << setw(18) << "Galutinis (Vid.)"
        << setw(18) << "Galutinis (Med.)"
        << "\n";

    out << string(15 + 20 + 18 + 18, '-') << "\n";

    out << fixed << setprecision(2);
    for (const auto& a : grupe) {
        out << left << setw(15) << a.vardas
            << setw(20) << a.pavarde
            << setw(18) << a.gal_vid
            << setw(18) << a.gal_med
            << "\n";
    }
}

void isvedimo_pasirinkimas(const vector<Studentas>& grupe) {
    if (grupe.empty()) {
        cout << "Grupe tuscia.\n";
        return;
    }

    cout << "\nKur isvesti rezultatus?\n";
    cout << "1 - I ekrana\n";
    cout << "2 - I faila\n";
    int kur = ivesti_skaiciu("Pasirinkimas: ", 1, 2);

    if (kur == 1) {
        if (grupe.size() > 10000) {
            cout << "Perspejimas: studentu labai daug, isvedimas i ekrana gali buti labai letas.\n";
            cout << "1 - Vis tiek testi\n";
            cout << "2 - Geriau i faila\n";
            int k = ivesti_skaiciu("Pasirinkimas: ", 1, 2);
            if (k == 2) {
                string outname;
                cout << "Failo pavadinimas (pvz. rezultatai.txt): ";
                std::cin >> outname;
                isvesti_i_faila(grupe, outname);
                cout << "Rezultatai irasyti i faila: " << outname << endl;
                return;
            }
        }
        isvesti_i_ekrana(grupe);
    } else {
        string outname;
        cout << "Failo pavadinimas (pvz. rezultatai.txt): ";
        std::cin >> outname;
        isvesti_i_faila(grupe, outname);
        cout << "Rezultatai irasyti i faila: " << outname << endl;
    }
}