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

void isvedimo_pasirinkimas(const vector<Studentas> &grupe) {
    if (grupe.empty()) {
        cout << "Grupe tuscia.\n";
        return;
    }

    cout << "\nKur isvesti rezultatus?\n";
    cout << "1 - I ekrana\n";
    cout << "2 - I faila\n";
    int kur;
    cin >> kur;
    while (!cin || (kur != 1 && kur != 2)) {
        cout << "Klaida: 1 arba 2: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> kur;
    }

    if (kur == 1) {
        isvesti_i_ekrana(grupe);
    } else {
        string outname;
        cout << "Failo pavadinimas (pvz. rezultatai.txt): ";
        cin >> outname;
        isvesti_i_faila(grupe, outname);
        cout << "Rezultatai irasyti i faila: " << outname << endl;
    }
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
    vector<Studentas> grupe;

    while (true) {
        int p = meniu();
        if (p == 4) break;

        if (p == 1) {
            int m = ivesti_kieki("Kiek studentu? ");
            int n = ivesti_kieki("Kiek pazymiu kiekvienam? ");
            for (int i = 0; i < m; i++) {
                Studentas A;
                cout << "Ivesk varda ir pavarde: ";
                cin >> A.vardas >> A.pavarde;
                for (int j = 0; j < n; j++) {
                    int x = ivesti_skaiciu("Pazymys (1-10): ", 1, 10);
                    A.paz.push_back(x);
                }
                A.egz = ivesti_skaiciu("Egzamino pazymys (1-10): ", 1, 10);
                skaiciuoti(A);
                grupe.push_back(A);
            }
            cout << "Uzbaigta. Is viso studentu: " << grupe.size() << endl;
        }
        else if (p == 2) {
            int m = ivesti_kieki("Kiek studentu? ");
            int n = ivesti_kieki("Kiek pazymiu generuoti kiekvienam? ");
            for (int i = 0; i < m; i++) {
                Studentas A;
                cout << "Ivesk varda ir pavarde: ";
                cin >> A.vardas >> A.pavarde;
                for (int j = 0; j < n; j++) A.paz.push_back(atsitiktinis_pazymys());
                A.egz = atsitiktinis_pazymys();
                skaiciuoti(A);
                grupe.push_back(A);
            }
            cout << "Sugeneruoti ir prideti " << m << " studentai.\n";
        }
        else if (p == 3) {
            int m = rand() % 5 + 3;
            int n = rand() % 5 + 3;
            vector<string> vardai = {"Jonas","Ona","Ieva","Mantas","Egle","Tomas","Ruta","Paulius","Greta","Lukas"};
            vector<string> pavardes = {"Kazlauskas","Petrauskas","Jankauskas","Vaitkus","Zukauskas","Stankevicius","Pocius","Noreika","Mikulenas","Sabonis"};
            for (int i = 0; i < m; i++) {
                Studentas A;
                A.vardas = vardai[rand() % (int)vardai.size()];
                A.pavarde = pavardes[rand() % (int)pavardes.size()];
                for (int j = 0; j < n; j++) A.paz.push_back(atsitiktinis_pazymys());
                A.egz = atsitiktinis_pazymys();
                skaiciuoti(A);
                grupe.push_back(A);
            }
            cout << "Programa sugeneravo " << m << " studentu ir po " << n << " ND kiekvienam.\n";
        } else {
            cout << "5 ir 6 dar padaryti reikia\n";
        }

        if (!grupe.empty()) {
            cout << "Ar norite isvesti rezultatus dabar? (1 - Taip, 2 - Ne): ";
            int a; cin >> a;
            if (a == 1) isvedimo_pasirinkimas(grupe);
        }
    }

    return 0;
}