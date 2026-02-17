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

