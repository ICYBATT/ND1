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

