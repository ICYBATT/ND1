#pragma once
#include "Zmogus.h"
#include <string>
#include <vector>
#include <iostream>

/**
 * @brief Studento klasė.
 * 
 * Saugo studento pažymius,
 * egzamino rezultatą ir galutinius balus.
 * 
 * Klasė paveldi Zmogus klasę.
 */
class Studentas : public Zmogus {
private:

    /**
     * @brief Namų darbų pažymiai.
     */
    std::vector<int> paz_;

    /**
     * @brief Egzamino rezultatas.
     */
    int egz_;

    /**
     * @brief Galutinis balas pagal vidurkį.
     */
    double gal_vid_;

    /**
     * @brief Galutinis balas pagal medianą.
     */
    double gal_med_;

public:

    /**
     * @brief Numatytasis konstruktorius.
     */
    Studentas();

    /**
     * @brief Konstruktorius su parametrais.
     * 
     * @param vardas Studento vardas.
     * @param pavarde Studento pavardė.
     * @param paz Namų darbų pažymiai.
     * @param egz Egzamino rezultatas.
     */
    Studentas(const std::string& vardas, const std::string& pavarde,
              const std::vector<int>& paz, int egz);

    /**
     * @brief Copy konstruktorius.
     * 
     * @param kitas Kitas studento objektas.
     */
    Studentas(const Studentas& kitas);

    /**
     * @brief Move konstruktorius.
     * 
     * @param kitas Perkeliamas objektas.
     */
    Studentas(Studentas&& kitas) noexcept;

    /**
     * @brief Copy assignment operatorius.
     * 
     * @param kitas Kitas objektas.
     * @return Studentas&
     */
    Studentas& operator=(const Studentas& kitas);

    /**
     * @brief Move assignment operatorius.
     * 
     * @param kitas Perkeliamas objektas.
     * @return Studentas&
     */
    Studentas& operator=(Studentas&& kitas) noexcept;

    /**
     * @brief Destruktorius.
     */
    ~Studentas();

    /**
     * @brief Grąžina pažymius.
     * 
     * @return Pažymių vektorius.
     */
    const std::vector<int>& getPaz() const;

    /**
     * @brief Grąžina egzamino rezultatą.
     * 
     * @return Egzamino pažymys.
     */
    int getEgz() const;

    /**
     * @brief Grąžina galutinį balą pagal vidurkį.
     * 
     * @return Galutinis balas.
     */
    double getGalVid() const;

    /**
     * @brief Grąžina galutinį balą pagal medianą.
     * 
     * @return Galutinis balas.
     */
    double getGalMed() const;

    /**
     * @brief Nustato pažymius.
     * 
     * @param paz Nauji pažymiai.
     */
    void setPaz(const std::vector<int>& paz);

    /**
     * @brief Prideda pažymį.
     * 
     * @param pazymys Naujas pažymys.
     */
    void addPazymys(int pazymys);

    /**
     * @brief Nustato egzamino rezultatą.
     * 
     * @param egz Egzamino pažymys.
     */
    void setEgz(int egz);

    /**
     * @brief Apskaičiuoja galutinius balus.
     */
    void skaiciuotiGalutinius();

    /**
     * @brief Išveda studento informaciją.
     */
    void spausdintiInformacija() const override;

    /**
     * @brief Įvesties operatorius.
     * 
     * @param in Įvesties srautas.
     * @param s Studentas.
     * @return std::istream&
     */
    friend std::istream& operator>>(std::istream& in, Studentas& s);

    /**
     * @brief Išvesties operatorius.
     * 
     * @param out Išvesties srautas.
     * @param s Studentas.
     * @return std::ostream&
     */
    friend std::ostream& operator<<(std::ostream& out, const Studentas& s);
};

/**
 * @brief Apskaičiuoja medianą.
 * 
 * @param paz Pažymiai.
 * @return Mediana.
 */
double mediana(const std::vector<int>& paz);

/**
 * @brief Apskaičiuoja galutinius balus.
 * 
 * @param a Studentas.
 */
void skaiciuoti(Studentas& a);

/**
 * @brief Sugeneruoja atsitiktinį pažymį.
 * 
 * @return Atsitiktinis pažymys.
 */
int atsitiktinis_pazymys();

/**
 * @brief Grąžina pasirinktą galutinį balą.
 * 
 * @param a Studentas.
 * @param vm Vidurkis arba mediana.
 * @return Galutinis balas.
 */
double galutinis_pagal(const Studentas& a, char vm);