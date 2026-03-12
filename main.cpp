#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

#include "studentas.h"
#include "Input.h"
#include "Menu.h"
#include "FileIO.h"
#include "Output.h"
#include "NaturalSort.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

static void rikiuoti(vector<Studentas>& grupe) {
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

    if (r == 1) std::sort(grupe.begin(), grupe.end(), compareByName);
    else if (r == 2) std::sort(grupe.begin(), grupe.end(), compareBySurname);
    else if (r == 3) std::sort(grupe.begin(), grupe.end(), compareByAvg);
    else std::sort(grupe.begin(), grupe.end(), compareByMed);
}

static void skirstyti_studentus(
    const vector<Studentas>& visi,
    vector<Studentas>& vargsiukai,
    vector<Studentas>& kietiakai,
    char vm
) {
    vargsiukai.clear();
    kietiakai.clear();

    for (const auto& s : visi) {
        if ((vm == 'M' || vm == 'm' ? s.gal_med : s.gal_vid) < 5.0)
            vargsiukai.push_back(s);
        else
            kietiakai.push_back(s);
    }
}

static void issaugoti_suskirstytus(
    const vector<Studentas>& vargsiukai,
    const vector<Studentas>& kietiakai,
    char vm
) {
    isvesti_i_faila(vargsiukai, "vargsiukai.txt", vm);
    isvesti_i_faila(kietiakai, "kietiakai.txt", vm);

    cout << "Sukurti failai:\n";
    cout << " - vargsiukai.txt\n";
    cout << " - kietiakai.txt\n";
}

int main() {
    std::srand((unsigned)std::time(nullptr));

    try {
        char pasirinktasVM = ivesti_vm();

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
                    std::cin >> A.vardas >> A.pavarde;

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
                    std::cin >> A.vardas >> A.pavarde;

                    for (int j = 0; j < n; j++) A.paz.push_back(atsitiktinis_pazymys());
                    A.egz = atsitiktinis_pazymys();

                    skaiciuoti(A);
                    grupe.push_back(A);
                }

                cout << "Sugeneruoti ir prideti " << m << " studentai.\n";
            }
            else if (p == 3) {
                int m = std::rand() % 5 + 3;
                int n = std::rand() % 5 + 3;

                vector<string> vardai = {"Jonas","Ona","Ieva","Mantas","Egle","Tomas","Ruta","Paulius","Greta","Lukas"};
                vector<string> pavardes = {"Kazlauskas","Petrauskas","Jankauskas","Vaitkus","Zukauskas",
                                           "Stankevicius","Pocius","Noreika","Mikulenas","Sabonis"};

                for (int i = 0; i < m; i++) {
                    Studentas A;
                    A.vardas = vardai[std::rand() % (int)vardai.size()];
                    A.pavarde = pavardes[std::rand() % (int)pavardes.size()];

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
                std::cin >> fname;

                int praleista = 0;

                auto start = std::chrono::high_resolution_clock::now();
                bool ok = nuskaityti_is_failo(fname, grupe, praleista);
                auto end = std::chrono::high_resolution_clock::now();

                if (!ok) {
                    cout << "Skaitymas nepavyko.\n";
                } else {
                    std::chrono::duration<double> diff = end - start;
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
                if (grupe.empty()) cout << "Grupe tuscia.\n";
                else {
                    rikiuoti(grupe);
                    isvedimo_pasirinkimas(grupe);
                }
            }
        }

        return 0;
    }
    catch (const std::exception& e) {
        std::cout << "Ivyko kritine klaida: " << e.what() << "\n";
        return 1;
    }
}