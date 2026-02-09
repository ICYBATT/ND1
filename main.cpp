#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

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

void outputas(const vector<Studentas>& grupe);

int main() {
    vector<Studentas> grupe;

    for (int ii = 0; ii < 2; ii++) {
        Studentas A;              // KIEKVIENAM studentui naujas objektas
        int n, temp, sum = 0;
        
                cout << "Iveskite varda ir pavarde: ";
        cin >> A.Vardas >> A.Pavarde;

        cout << "Iveskite semestro pazymius:\nKiek pazymiu bus? ";
        cin >> n;

             for (int i = 0; i < n; i++) {
            cout << "Iveskite " << i + 1 << " pazymi is " << n << ": ";
            cin >> temp;
            A.paz.push_back(temp);
            sum += temp;
        }
