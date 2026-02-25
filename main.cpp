#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <limits>
#include <chrono>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::left;
using std::setw;
using std::fixed;
using std::setprecision;
using std::endl;
using std::numeric_limits;
using std::streamsize;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> paz;
    int egz = 0;
    double gal_vid = 0.0;
    double gal_med = 0.0;
};

double mediana(const vector<int> &paz) {
    if (paz.empty()) return 0.0;
    vector<int> tmp = paz;
    std::sort(tmp.begin(), tmp.end());
    int n = (int)tmp.size();
    if (n % 2 == 1) return (double)tmp[n / 2];
    return (tmp[n / 2 - 1] + tmp[n / 2]) / 2.0;
}

int atsitiktinis_pazymys() {
    return rand() % 10 + 1;
}

void skaiciuoti(Studentas &a) {
    double vid = 0.0;
    if (!a.paz.empty()) {
        long long suma = 0;
        for (int x : a.paz) suma += x;
        vid = (double)suma / (double)a.paz.size();
    }
    double med = mediana(a.paz);
    a.gal_vid = vid * 0.4 + a.egz * 0.6;
    a.gal_med = med * 0.4 + a.egz * 0.6;
}

int ivesti_skaiciu(const string &tekstas, int nuo, int iki) {
    int x;
    cout << tekstas;
    cin >> x;
    while (!cin || x < nuo || x > iki) {
        cout << "Klaida: iveskite skaiciu nuo " << nuo << " iki " << iki << ": ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> x;
    }
    return x;
}

int ivesti_kieki(const string &tekstas) {
    int x;
    cout << tekstas;
    cin >> x;
    while (!cin || x <= 0) {
        cout << "Klaida: skaicius turi buti bent 1. Iveskite dar karta: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> x;
    }
    return x;
}

int meniu() {
    int x;
    cout << "\nMeniu:\n";
    cout << "1 - viska ivedi ranka\n";
    cout << "2 - ivedi studentu ir pazymiu kieki, pazymiai generuojami\n";
    cout << "3 - viska generuoja programa\n";
    cout << "4 - Baigti\n";
    cout << "5 - Nuskaityti studentus is failo (v0.2)\n";
    cout << "6 - Rikiuoti ir isvesti rezultatus\n";
    cout << "Pasirinkimas: ";
    cin >> x;
    while (!cin || x < 1 || x > 6) {
        cout << "Klaida: iveskite skaiciu nuo 1 iki 6: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> x;
    }
    return x;
}

int main() {
    srand((unsigned)time(NULL));
    while (true) {
        int p = meniu();
        if (p == 4) break;
        cout << "Pasirinkimas: " << p << " (dar reikia papildyti)\n";
    }
    return 0;
}