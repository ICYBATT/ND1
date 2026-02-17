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

void outputas(const vector<Studentas>& grupe) {
    cout << left << setw(12) << "Vardas"
         << setw(20) << "Pavarde"
         << setw(12) << "Galutinis" << "\n";

    cout << "----------------------------------------\n";

    for (const auto& A : grupe) {
        cout << left << setw(12) << A.Vardas
             << setw(20) << A.Pavarde
             << std::fixed << std::setprecision(2)
             << setw(12) << A.rez << "\n";
    }
}

int randomPaz() { return rand() % 10 + 1; }

string vardai[] = {"Jonas","Ona","Mantas","Ieva","Tomas","Greta","Paulius","Egle"};
string pavardes[] = {"Kazlauskas","Petrauskas","Jankauskas","Vaitkus","Zukauskas","Sabonis"};

int main() {
    srand(time(NULL));


    vector<Studentas> grupe;


    char pasirinkimas;
    cout << "Skaiciuoti pagal (V)idurkis ar (M)ediana? ";
    cin >> pasirinkimas;


    int rezimas;
    cout << "\nPasirink rezima:\n";
    cout << "1 - viska ivedi ranka\n";
    cout << "2 - ivedi studentu ir pazymiu kieki, pazymiai generuojami\n";
    cout << "3 - viska generuoja programa\n";
    cin >> rezimas;

    int m, n;

    if (rezimas == 1) {

        cout << "Kiek studentu? ";
        cin >> m;
        cout << "Kiek pazymiu kiekvienam? ";
        cin >> n;

        for (int i = 0; i < m; i++) {
            Studentas A;

            cout << "Ivesk varda ir pavarde: ";
            cin >> A.Vardas >> A.Pavarde;

            for (int j = 0; j < n; j++) {
                int x;
                cout << "Pazymys: ";
                cin >> x;
                A.paz.push_back(x);
            }

            cout << "Egzamino pazymys: ";
            cin >> A.exam;

            skaiciuoti(A, pasirinkimas);

            grupe.push_back(A);
        }
    }

    else if (rezimas == 2) {

        cout << "Kiek studentu? ";
        cin >> m;
        cout << "Kiek pazymiu kiekvienam? ";
        cin >> n;

        for (int i = 0; i < m; i++) {
            Studentas A;


            cout << "Ivesk varda ir pavarde: ";
            cin >> A.Vardas >> A.Pavarde;

           
            for (int j = 0; j < n; j++)
                A.paz.push_back(randomPaz());

            A.exam = randomPaz();

            skaiciuoti(A, pasirinkimas);
            grupe.push_back(A);
        }
    }

    else if (rezimas == 3) {

        m = rand() % 5 + 3;
        n = rand() % 5 + 3;

        cout << "Sugeneruota " << m << " studentai ir " << n << " pazymiai\n";

        for (int i = 0; i < m; i++) {
            Studentas A;

            A.Vardas = vardai[rand()%8];
            A.Pavarde = pavardes[rand()%6];

            for (int j = 0; j < n; j++)
                A.paz.push_back(randomPaz());

            A.exam = randomPaz();

            skaiciuoti(A, pasirinkimas);
            grupe.push_back(A);
        }
    }

    cout << "\nRezultatai:\n";
   
    outputas(grupe);
}
