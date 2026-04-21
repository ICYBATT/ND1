#pragma once
#include <string>
#include <vector>
#include <iostream>

class Studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> paz_;
    int egz_;
    double gal_vid_;
    double gal_med_;

public:
    Studentas();
    Studentas(const std::string& vardas, const std::string& pavarde,
              const std::vector<int>& paz, int egz);

    Studentas(const Studentas& kitas);
    Studentas(Studentas&& kitas) noexcept;

    Studentas& operator=(const Studentas& kitas);
    Studentas& operator=(Studentas&& kitas) noexcept;

    ~Studentas();

    const std::string& getVardas() const;
    const std::string& getPavarde() const;
    const std::vector<int>& getPaz() const;
    int getEgz() const;
    double getGalVid() const;
    double getGalMed() const;

    void setVardas(const std::string& vardas);
    void setPavarde(const std::string& pavarde);
    void setPaz(const std::vector<int>& paz);
    void addPazymys(int pazymys);
    void setEgz(int egz);

    void skaiciuotiGalutinius();

    friend std::istream& operator>>(std::istream& in, Studentas& s);
    friend std::ostream& operator<<(std::ostream& out, const Studentas& s);
};

double mediana(const std::vector<int>& paz);
void skaiciuoti(Studentas& a);
int atsitiktinis_pazymys();
double galutinis_pagal(const Studentas& a, char vm);