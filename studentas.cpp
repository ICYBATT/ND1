#include "studentas.h"
#include <algorithm>
#include <cstdlib>

double mediana(const std::vector<int>& paz) {
    if (paz.empty()) return 0.0;

    std::vector<int> tmp = paz;
    std::sort(tmp.begin(), tmp.end());

    int n = (int)tmp.size();
    if (n % 2 == 1) return (double)tmp[n / 2];
    return (tmp[n / 2 - 1] + tmp[n / 2]) / 2.0;
}

void skaiciuoti(Studentas& a) {
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

int atsitiktinis_pazymys() {
    return std::rand() % 10 + 1;
}

double galutinis_pagal(const Studentas& a, char vm) {
    if (vm == 'M' || vm == 'm') return a.gal_med;
    return a.gal_vid;
}