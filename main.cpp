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

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> paz;
    int egz = 0;
    double gal_vid = 0.0;
    double gal_med = 0.0;
};

int main() {
    
    Studentas s;
    cout << "Iveskite varda ir pavarde (J S): ";
    cin >> s.vardas >> s.pavarde;
    cout << "Ivesti pavyzdinis studentas: " << s.vardas << " " << s.pavarde << "\n";
    return 0;
}