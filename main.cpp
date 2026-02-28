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
using std::sort;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::getline;
using std::numeric_limits;
using std::streamsize;
using std::ws;

using std::chrono::high_resolution_clock;
using std::chrono::duration;

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
    sort(tmp.begin(), tmp.end());
    int n = (int)tmp.size();
    if (n % 2 == 1) return (double)tmp[n / 2];
    return (tmp[n / 2 - 1] + tmp[n / 2]) / 2.0;
}

int atsitiktinis_pazymys() {
    return rand() % 10 + 1;
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


bool nuskaityti_is_failo(const string &failas, vector<Studentas> &grupe, int &praleista) {
    ifstream in(failas);
    if (!in) {
        cout << "Nepavyko atidaryti failo: " << failas << endl;
        return false;
    }

    grupe.clear();
    praleista = 0;

    string line;
    while (getline(in, line)) {
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

        if (!iss.eof()) {
            praleista++;
            continue;
        }

        if (skaiciai.size() < 2) {
            praleista++;
            continue;
        }

        bool bloga = false;
        for (int v : skaiciai) {
            if (v < 1 || v > 10) {
                bloga = true;
                break;
            }
        }
        if (bloga) {
            praleista++;
            continue;
        }

        a.egz = skaiciai.back();
        skaiciai.pop_back();
        a.paz = skaiciai;

        skaiciuoti(a);
        grupe.push_back(a);
    }

    return true;
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

    int r = ivesti_skaiciu("Pasirinkimas: ", 1, 4);

    if (r == 1) {
        std::sort(grupe.begin(), grupe.end(), compareByName);
    } else if (r == 2) {
        std::sort(grupe.begin(), grupe.end(), compareBySurname);
    } else if (r == 3) {
        std::sort(grupe.begin(), grupe.end(), compareByAvg);
    } else {
        std::sort(grupe.begin(), grupe.end(), compareByMed);
    }
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
                cin >> outname;
                isvesti_i_faila(grupe, outname);
                cout << "Rezultatai irasyti i faila: " << outname << endl;
                return;
            }
        }
        isvesti_i_ekrana(grupe);
    } else {
        string outname;
        cout << "Failo pavadinimas (pvz. rezultatai.txt): ";
        cin >> outname;
        isvesti_i_faila(grupe, outname);
        cout << "Rezultatai irasyti i faila: " << outname << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));

    char pasirinkimas;
    cout << "Skaiciuoti pagal (V)idurkis ar (M)ediana? ";
    cin >> pasirinkimas;
    while (pasirinkimas != 'V' && pasirinkimas != 'v' && pasirinkimas != 'M' && pasirinkimas != 'm') {
        cout << "Klaida: iveskite V arba M: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> pasirinkimas;
    }

    Studentas a;
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
                    int x;
                    x = ivesti_skaiciu("Pazymys (1-10): ", 1, 10);
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
            vector<string> pavardes = {"Kazlauskas","Petrauskas","Jankauskas","Vaitkus","Zukauskas",
                                       "Stankevicius","Pocius","Noreika","Mikulenas","Sabonis"};

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
        }
        else if (p == 5) {
            cout << "Iveskite failo pavadinima: ";
            string fname;
            cin >> fname;

            int praleista = 0;

            auto start = high_resolution_clock::now();
            bool ok = nuskaityti_is_failo(fname, grupe, praleista);
            auto end = high_resolution_clock::now();

            if (!ok) {
                cout << "Skaitymas nepavyko.\n";
            } else {
                duration<double> diff = end - start;
                cout << "Studentu: " << grupe.size() << endl;
                cout << "Laikas: " << diff.count() << " s\n";
                if (praleista > 0) cout << "Praleista eiluciu: " << praleista << endl;

                cout << "\nAr norite dabar rikiuoti ir isvesti?\n";
                cout << "1 - Taip\n";
                cout << "2 - Ne (grizti i meniu)\n";
                int ats = ivesti_skaiciu("Pasirinkimas: ", 1, 2);

                if (ats == 1) {
                    rikiuoti(grupe);
                    isvedimo_pasirinkimas(grupe);
                }
            }
        }
        else if (p == 6) {
            if (grupe.empty()) {
                cout << "Grupe tuscia.\n";
            } else {
                rikiuoti(grupe);
                isvedimo_pasirinkimas(grupe);
            }
        }
    }

    return 0;
}