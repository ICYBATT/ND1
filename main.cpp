#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

const int MAX_STUD = 200;
const int MAX_NAME = 64;
const int MAX_GRADES = 200;

struct Studentas {
    char Vardas[MAX_NAME];
    char Pavarde[MAX_NAME];
    int paz[MAX_GRADES];
    int paz_count;
    int exam;
    double rez;
};

double mediana_int_array(int arr[], int n) {
    if (n <= 0) return 0.0;
    
    int tmp[MAX_GRADES];
    for (int i = 0; i < n; ++i) tmp[i] = arr[i];
    sort(tmp, tmp + n);
    if (n % 2 == 1) return tmp[n/2];
    return (tmp[n/2 - 1] + tmp[n/2]) / 2.0;
}

void skaiciuoti(Studentas &A, char pasirinkimas) {
    double vid = 0.0;
    if (A.paz_count > 0) {
        int s = 0;
        for (int i = 0; i < A.paz_count; ++i) s += A.paz[i];
        vid = (double)s / A.paz_count;
    }
    if (pasirinkimas == 'M' || pasirinkimas == 'm') {
        A.rez = mediana_int_array(A.paz, A.paz_count) * 0.4 + A.exam * 0.6;
    } else {
        A.rez = vid * 0.4 + A.exam * 0.6;
    }
}

void outputas(Studentas grupe[], int m) {
    cout << left << setw(12) << "Vardas"
         << setw(20) << "Pavarde"
         << setw(12) << "Galutinis" << "\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < m; ++i) {
        cout << left << setw(12) << grupe[i].Vardas
             << setw(20) << grupe[i].Pavarde
             << fixed << setprecision(2)
             << setw(12) << grupe[i].rez << "\n";
    }
}

int randomPaz() { return rand() % 10 + 1; }

const char* vardai[] = {"Jonas","Ona","Mantas","Ieva","Tomas","Greta","Paulius","Egle"};
const char* pavardes[] = {"Kazlauskas","Petrauskas","Jankauskas","Vaitkus","Zukauskas","Sabonis"};
const int NVARD = 8;
const int NPAV = 6;

