#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>

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

void outputas(const vector<Studentas>& grupe);

int main() {
    vector<Studentas> grupe;

    char pasirinkimas;
    cout << "Skaiciuoti pagal (V)idurki ar (M)ediana? ";
    cin >> pasirinkimas;

    for (int ii = 0; ii < 2; ii++) {
        Studentas A;    // KIEKVIENAM studentui naujas objektas
        int n, temp, sum = 0;

        cout << "Iveskite varda ir pavarde: ";
        cin >> A.Vardas >> A.Pavarde;

        cout << "Iveskite semestro pazymius:\nKiek pazymiu bus? ";

        while (!(cin >> n) || n <= 0) {
            cout << "Klaida: iveskite teigiama sveika skaiciu: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        for (int i = 0; i < n; i++) {
            cout << "Iveskite " << i + 1 << " pazymi is " << n << ": ";

            while (!(cin >> temp) || temp < 1 || temp > 10) {
                cout << "Klaida: pazymys turi buti sveikas skaicius nuo 1 iki 10. Bandykite dar karta: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            A.paz.push_back(temp);
            sum += temp;
        }

        cout << "Iveskite egzamino paz: ";

        while (!(cin >> A.exam) || A.exam < 1 || A.exam > 10) {
            cout << "Klaida: egzamino pazymys turi buti sveikas skaicius nuo 1 iki 10. Bandykite dar karta: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // ---- PASIRINKIMAS ----
        if (pasirinkimas == 'M' || pasirinkimas == 'm') {
            double med = mediana(A.paz);
            A.rez = med * 0.4 + A.exam * 0.6;
        } else {
            double vidurkis = 0.0;
            if (!A.paz.empty()) vidurkis = static_cast<double>(sum) / A.paz.size();
            A.rez = vidurkis * 0.4 + A.exam * 0.6;
        }

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