#include "studentas.h"
#include <algorithm>
#include <cstdlib>

Studentas::Studentas()
    : vardas_(""), pavarde_(""), paz_(), egz_(0), gal_vid_(0.0), gal_med_(0.0) {
}

Studentas::Studentas(const std::string& vardas, const std::string& pavarde,
                     const std::vector<int>& paz, int egz)
    : vardas_(vardas), pavarde_(pavarde), paz_(paz), egz_(egz), gal_vid_(0.0), gal_med_(0.0) {
    skaiciuotiGalutinius();
}

Studentas::Studentas(const Studentas& kitas)
    : vardas_(kitas.vardas_),
      pavarde_(kitas.pavarde_),
      paz_(kitas.paz_),
      egz_(kitas.egz_),
      gal_vid_(kitas.gal_vid_),
      gal_med_(kitas.gal_med_) {
}

Studentas& Studentas::operator=(const Studentas& kitas) {
    if (this != &kitas) {
        vardas_ = kitas.vardas_;
        pavarde_ = kitas.pavarde_;
        paz_ = kitas.paz_;
        egz_ = kitas.egz_;
        gal_vid_ = kitas.gal_vid_;
        gal_med_ = kitas.gal_med_;
    }
    return *this;
}

Studentas::~Studentas() {
}

const std::string& Studentas::getVardas() const {
    return vardas_;
}

const std::string& Studentas::getPavarde() const {
    return pavarde_;
}

const std::vector<int>& Studentas::getPaz() const {
    return paz_;
}

int Studentas::getEgz() const {
    return egz_;
}

double Studentas::getGalVid() const {
    return gal_vid_;
}

double Studentas::getGalMed() const {
    return gal_med_;
}

void Studentas::setVardas(const std::string& vardas) {
    vardas_ = vardas;
}

void Studentas::setPavarde(const std::string& pavarde) {
    pavarde_ = pavarde;
}

void Studentas::setPaz(const std::vector<int>& paz) {
    paz_ = paz;
}

void Studentas::addPazymys(int pazymys) {
    paz_.push_back(pazymys);
}

void Studentas::setEgz(int egz) {
    egz_ = egz;
}

double mediana(const std::vector<int>& paz) {
    if (paz.empty()) return 0.0;

    std::vector<int> tmp = paz;
    std::sort(tmp.begin(), tmp.end());

    int n = (int)tmp.size();
    if (n % 2 == 1) return (double)tmp[n / 2];
    return (tmp[n / 2 - 1] + tmp[n / 2]) / 2.0;
}

void Studentas::skaiciuotiGalutinius() {
    double vid = 0.0;

    if (!paz_.empty()) {
        long long suma = 0;
        for (int x : paz_) suma += x;
        vid = (double)suma / (double)paz_.size();
    }

    double med = mediana(paz_);

    gal_vid_ = vid * 0.4 + egz_ * 0.6;
    gal_med_ = med * 0.4 + egz_ * 0.6;
}

void skaiciuoti(Studentas& a) {
    a.skaiciuotiGalutinius();
}

int atsitiktinis_pazymys() {
    return std::rand() % 10 + 1;
}

double galutinis_pagal(const Studentas& a, char vm) {
    if (vm == 'M' || vm == 'm') return a.getGalMed();
    return a.getGalVid();
}