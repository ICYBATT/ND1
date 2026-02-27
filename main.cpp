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


bool ar_skaitmuo(char c) {
    return c >= '0' && c <= '9';
}

int skaicius_gale(const string &s) {
    int i = (int)s.size() - 1;
    if (i < 0) return -1;
    if (!ar_skaitmuo(s[i])) return -1;
    int daugiklis = 1;
    int sk = 0;
    while (i >= 0 && ar_skaitmuo(s[i])) {
        sk += (s[i] - '0') * daugiklis;
        daugiklis *= 10;
        i--;
    }
    return sk;
}

string tekstas_be_galo_skaiciaus(const string &s) {
    int i = (int)s.size() - 1;
    if (i < 0) return s;
    if (!ar_skaitmuo(s[i])) return s;
    while (i >= 0 && ar_skaitmuo(s[i])) i--;
    return s.substr(0, i + 1);
}

bool palyginti_nat(const string &a, const string &b) {
    string ta = tekstas_be_galo_skaiciaus(a);
    string tb = tekstas_be_galo_skaiciaus(b);
    if (ta != tb) return ta < tb;
    int na = skaicius_gale(a);
    int nb = skaicius_gale(b);
    if (na != -1 && nb != -1) return na < nb;
    return a < b;
}

bool compareByName(const Studentas &a, const Studentas &b) {
    if (a.vardas != b.vardas) return palyginti_nat(a.vardas, b.vardas);
    return palyginti_nat(a.pavarde, b.pavarde);
}

bool compareBySurname(const Studentas &a, const Studentas &b) {
    if (a.pavarde != b.pavarde) return palyginti_nat(a.pavarde, b.pavarde);
    return palyginti_nat(a.vardas, b.vardas);
}

bool compareByAvg(const Studentas &a, const Studentas &b) {
    if (a.gal_vid != b.gal_vid) return a.gal_vid < b.gal_vid;
    if (a.pavarde != b.pavarde) return palyginti_nat(a.pavarde, b.pavarde);
    return palyginti_nat(a.vardas, b.vardas);
}

bool compareByMed(const Studentas &a, const Studentas &b) {
    if (a.gal_med != b.gal_med) return a.gal_med < b.gal_med;
    if (a.pavarde != b.pavarde) return palyginti_nat(a.pavarde, b.pavarde);
    return palyginti_nat(a.vardas, b.vardas);
}


void isvesti_i_ekrana(const vector<Studentas> &grupe) {
    cout << left << setw(15) << "Vardas"
         << setw(20) << "Pavarde"
         << setw(18) << "Galutinis (Vid.)"
         << setw(18) << "Galutinis (Med.)"
         << "\n";

    cout << string(15 + 20 + 18 + 18, '-') << "\n";

    cout << fixed << setprecision(2);
    for (const auto &a : grupe) {
        cout << left << setw(15) << a.vardas
             << setw(20) << a.pavarde
             << setw(18) << a.gal_vid
             << setw(18) << a.gal_med
             << "\n";
    }
}

void isvesti_i_faila(const vector<Studentas> &grupe, const string &failas) {
    std::ofstream out(failas);
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
    for (const auto &a : grupe) {
        out << left << setw(15) << a.vardas
            << setw(20) << a.pavarde
            << setw(18) << a.gal_vid
            << setw(18) << a.gal_med
            << "\n";
    }
}

void rikiuoti(vector<Studentas> &grupe) {
    if (grupe.empty()) {
        cout << "Grupe tuscia - nera ka rikiuoti.\n";
        return;
    }

    cout << "\nRikiuoti studentus pagal:\n";
    cout << "1 - Varda\n";
    cout << "2 - Pavarde\n";
    cout << "3 - Galutini (Vid.)\n";
    cout << "4 - Galutini (Med.)\n";

    int r;
    cin >> r;
    while (!cin || r < 1 || r > 4) {
        cout << "Klaida: iveskite 1-4: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> r;
    }

    if (r == 1) std::sort(grupe.begin(), grupe.end(), compareByName);
    else if (r == 2) std::sort(grupe.begin(), grupe.end(), compareBySurname);
    else if (r == 3) std::sort(grupe.begin(), grupe.end(), compareByAvg);
    else std::sort(grupe.begin(), grupe.end(), compareByMed);
}

int main() {
    srand((unsigned)time(NULL));
    vector<Studentas> grupe;

    
    Studentas a; a.vardas = "Jonas"; a.pavarde = "Kazlauskas"; a.paz = {8,9,10}; a.egz = 9; skaiciuoti(a);
    Studentas b; b.vardas = "Ona"; b.pavarde = "Petrauskiene"; b.paz = {7,6,8}; b.egz = 8; skaiciuoti(b);
    grupe.push_back(a);
    grupe.push_back(b);

    rikiuoti(grupe);
    isvesti_i_ekrana(grupe);

    return 0;
}