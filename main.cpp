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

        cout << "Iveskite egzamino paz: ";
        cin >> A.exam;

        double vidurkis = static_cast<double>(sum) / A.paz.size();
        A.rez = vidurkis * 0.4 + A.exam * 0.6;
        
        grupe.push_back(A);
    }

    outputas(grupe);
    return 0;
}

void outputas(const vector<Studentas>& grupe) {
    cout << left << setw(10) << "Vardas"
         << setw(20) << "Pavarde"
         << setw(10) << "Galutinis" << std::endl;

    cout << "---------------------------------------------" << std::endl;

    for (const auto& A : grupe) {
        cout << left << setw(10) << A.Vardas
             << setw(20) << A.Pavarde
             << std::fixed << std::setprecision(2)
             << setw(10) << A.rez << std::endl;
    }
}


