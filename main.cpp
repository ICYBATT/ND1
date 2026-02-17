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

int main() {
    srand((unsigned)time(nullptr));

    Studentas grupe[MAX_STUD];
    int m = 0;

    char pasirinkimas;
    cout << "Skaiciuoti pagal (V)idurkis ar (M)ediana? ";
    cin >> pasirinkimas;

    int rezimas;
    cout << "\nPasirink rezima:\n";
    cout << "1 - viska ivedi ranka\n";
    cout << "2 - ivedi studentu ir pazymiu kieki, pazymiai generuojami\n";
    cout << "3 - viska generuoja programa\n";
    cin >> rezimas;

    int n; 
    if (rezimas == 1) {
        cout << "Kiek studentu? ";
        cin >> m;
        if (m > MAX_STUD) { cout << "Per daug studentu (max " << MAX_STUD << ").\n"; return 1; }
        cout << "Kiek pazymiu kiekvienam? ";
        cin >> n;
        if (n > MAX_GRADES) { cout << "Per daug pazymiu (max " << MAX_GRADES << ").\n"; return 1; }

        for (int i = 0; i < m; ++i) {
            cout << "Ivesk varda ir pavarde: ";
            
            cin >> ws;
            cin.getline(grupe[i].Vardas, MAX_NAME, ' ');
            cin >> grupe[i].Pavarde;

            grupe[i].paz_count = n;
            for (int j = 0; j < n; ++j) {
                int x;
                cout << "Pazymys: ";
                cin >> x;
                grupe[i].paz[j] = x;
            }
            cout << "Egzamino pazymys: ";
            cin >> grupe[i].exam;
            skaiciuoti(grupe[i], pasirinkimas);
        }
    }
    else if (rezimas == 2) {
        cout << "Kiek studentu? ";
        cin >> m;
        if (m > MAX_STUD) { cout << "Per daug studentu (max " << MAX_STUD << ").\n"; return 1; }
        cout << "Kiek pazymiu kiekvienam? ";
        cin >> n;
        if (n > MAX_GRADES) { cout << "Per daug pazymiu (max " << MAX_GRADES << ").\n"; return 1; }

        for (int i = 0; i < m; ++i) {
            cout << "Ivesk varda ir pavarde: ";
            cin >> ws;
            cin.getline(grupe[i].Vardas, MAX_NAME, ' ');
            cin >> grupe[i].Pavarde;

            grupe[i].paz_count = n;
            for (int j = 0; j < n; ++j) grupe[i].paz[j] = randomPaz();
            grupe[i].exam = randomPaz();
            skaiciuoti(grupe[i], pasirinkimas);
        }
    }
    else if (rezimas == 3) {
        m = rand() % 5 + 3;
        n = rand() % 5 + 3;
        cout << "Sugeneruota " << m << " studentai ir " << n << " pazymiai\n";
        if (m > MAX_STUD) m = MAX_STUD;
        if (n > MAX_GRADES) n = MAX_GRADES;

        for (int i = 0; i < m; ++i) {
            strncpy(grupe[i].Vardas, vardai[rand() % NVARD], MAX_NAME);
            strncpy(grupe[i].Pavarde, pavardes[rand() % NPAV], MAX_NAME);
            grupe[i].Vardas[MAX_NAME-1] = '\0';
            grupe[i].Pavarde[MAX_NAME-1] = '\0';

            grupe[i].paz_count = n;
            for (int j = 0; j < n; ++j) grupe[i].paz[j] = randomPaz();
            grupe[i].exam = randomPaz();
            skaiciuoti(grupe[i], pasirinkimas);
        }
    }
    else {
        cout << "Neteisingas rezimas.\n";
        return 1;
    }

    cout << "\nRezultatai:\n";
    outputas(grupe, m);

    return 0;
}
