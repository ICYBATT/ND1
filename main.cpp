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

