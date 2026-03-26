#pragma once
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <type_traits>

#include "studentas.h"
#include "NaturalSort.h"

template <typename Container>
bool nuskaityti_i_konteineri(const std::string& failas, Container& grupe, int& praleista) {
    grupe.clear();
    praleista = 0;

    std::ifstream in(failas);
    if (!in) {
        std::cout << "Nepavyko atidaryti failo: " << failas << "\n";
        return false;
    }

    std::string line;

    while (std::getline(in, line)) {
        if (line.empty()) continue;

        std::istringstream iss(line);
        Studentas a;

        if (!(iss >> a.vardas >> a.pavarde)) {
            praleista++;
            continue;
        }

        if (a.vardas == "Vardas" && a.pavarde == "Pavarde") continue;

        std::vector<int> skaiciai;
        int x;
        while (iss >> x) {
            skaiciai.push_back(x);
        }

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

template <typename Container>
void rikiuoti_konteineri(Container& grupe, int r) {
    if constexpr (std::is_same_v<Container, std::list<Studentas>>) {
        if (r == 1) grupe.sort(compareByName);
        else if (r == 2) grupe.sort(compareBySurname);
        else if (r == 3) grupe.sort(compareByAvg);
        else grupe.sort(compareByMed);
    } else {
        if (r == 1) std::sort(grupe.begin(), grupe.end(), compareByName);
        else if (r == 2) std::sort(grupe.begin(), grupe.end(), compareBySurname);
        else if (r == 3) std::sort(grupe.begin(), grupe.end(), compareByAvg);
        else std::sort(grupe.begin(), grupe.end(), compareByMed);
    }
}

template <typename Container>
void skirstyti_strategija1(const Container& studentai, Container& vargsiukai, Container& kietiakai, char vm) {
    vargsiukai.clear();
    kietiakai.clear();

    for (const auto& a : studentai) {
        if (galutinis_pagal(a, vm) < 5.0) {
            vargsiukai.push_back(a);
        } else {
            kietiakai.push_back(a);
        }
    }
}

template <typename Container>
void skirstyti_strategija2(Container& studentai, Container& vargsiukai, char vm) {
    vargsiukai.clear();

    auto it = studentai.begin();
    while (it != studentai.end()) {
        if (galutinis_pagal(*it, vm) < 5.0) {
            vargsiukai.push_back(*it);
            it = studentai.erase(it);
        } else {
            ++it;
        }
    }
}

template <typename Container>
void skirstyti_strategija3(const Container& studentai, Container& vargsiukai, Container& kietiakai, char vm) {
    vargsiukai.clear();
    kietiakai.clear();

    Container kopija = studentai;

    auto riba = std::partition(kopija.begin(), kopija.end(),
        [vm](const Studentas& a) {
            return galutinis_pagal(a, vm) < 5.0;
        });

    vargsiukai.insert(vargsiukai.end(), kopija.begin(), riba);
    kietiakai.insert(kietiakai.end(), riba, kopija.end());
}