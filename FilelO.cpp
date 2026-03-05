#include "FileIO.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::cout;
using std::endl;

static void patikrinti_faila_ar_throw(const string& failas) {
    ifstream in(failas);
    if (!in) throw std::runtime_error("Nepavyko atidaryti failo: " + failas);
}

bool nuskaityti_is_failo(const string& failas, vector<Studentas>& grupe, int& praleista) {
    grupe.clear();
    praleista = 0;

    try {
        patikrinti_faila_ar_throw(failas);
    } catch (const std::exception& e) {
        cout << e.what() << endl;
        return false;
    }

    ifstream in(failas);
    string line;

    while (std::getline(in, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        Studentas a;

        if (!(iss >> a.vardas >> a.pavarde)) {
            praleista++;
            continue;
        }
        if (a.vardas == "Vardas" && a.pavarde == "Pavarde") continue;

        vector<int> skaiciai;
        int x;
        while (iss >> x) skaiciai.push_back(x);

        if (!iss.eof()) { praleista++; continue; }
        if (skaiciai.size() < 2) { praleista++; continue; }

        bool bloga = false;
        for (int v : skaiciai) {
            if (v < 1 || v > 10) { bloga = true; break; }
        }
        if (bloga) { praleista++; continue; }

        a.egz = skaiciai.back();
        skaiciai.pop_back();
        a.paz = skaiciai;

        skaiciuoti(a);
        grupe.push_back(a);
    }

    return true;
}