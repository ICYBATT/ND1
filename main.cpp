#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <cstdlib>
#include <ctime>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::left;
using std::setw;

struct Studentas {
    string Vardas;
    string Pavarde;
    vector<int> paz;
    int exam;
    double rez;
};

double mediana(vector<int> paz) {
    if (paz.empty()) return 0.0;
    std::sort(paz.begin(), paz.end());
    int n = paz.size();

    if (n % 2 == 1)
        return paz[n / 2];
    else
        return (paz[n / 2 - 1] + paz[n / 2]) / 2.0;
}

void skaiciuoti(Studentas &A, char pasirinkimas) {
    double vidurkis = 0.0;
    if (!A.paz.empty()) {
        int sum = 0;
        for (int x : A.paz) sum += x;
        vidurkis = (double)sum / A.paz.size();
    }

    if (pasirinkimas == 'M' || pasirinkimas == 'm')
        A.rez = mediana(A.paz) * 0.4 + A.exam * 0.6;
    else
        A.rez = vidurkis * 0.4 + A.exam * 0.6;
}

