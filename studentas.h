#pragma once
#include "Zmogus.h"
#include <string>
#include <vector>
#include <iostream>

/**
 * @class Studentas
 * @brief Klasė studento duomenų saugojimui ir apdorojimui.
 *
 * Klasė paveldi Zmogus klasę ir saugo:
 * - namų darbų pažymius
 * - egzamino rezultatą
 * - galutinį balą pagal vidurkį
 * - galutinį balą pagal medianą
 *
 * Taip pat realizuoja Rule of Five principus.
 */
class Studentas : public Zmogus {
private:
    std::vector<int> paz_;
    int egz_;
    double gal_vid_;
    double gal_med_;

public:

    /**
     * @brief Default konstruktorius.
     */
    Studentas();

    /**
     * @brief Parametrinis konstruktorius.
     * @param vardas Studento vardas.
     * @param pavarde Studento pavardė.
     * @param paz Namų darbų pažymiai.
     * @param egz Egzamino rezultatas.
     */
    Studentas(const std::string& vardas, const std::string& pavarde,
              const std::vector<int>& paz, int egz);

    /**
     * @brief Copy konstruktorius.
     */
    Studentas(const Studentas& kitas);

    /**
     * @brief Move konstruktorius.
     */
    Studentas(Studentas&& kitas) noexcept;

    /**
     * @brief Copy assignment operatorius.
     */
    Studentas& operator=(const Studentas& kitas);

    /**
     * @brief Move assignment operatorius.
     */
    Studentas& operator=(Studentas&& kitas) noexcept;

    /**
     * @brief Destruktorius.
     */
    ~Studentas();

    /**
     * @brief Grąžina pažymių vektorių.
     * @return Pažymiai.
     */
    const std::vector<int>& getPaz() const;

    /**
     * @brief Grąžina egzamino rezultatą.
     * @return Egzamino pažymys.
     */
    int getEgz() const;

    /**
     * @brief Grąžina galutinį balą pagal vidurkį.
     * @return Galutinis balas.
     */
    double getGalVid() const;

    /**
     * @brief Grąžina galutinį balą pagal medianą.
     * @return Galutinis balas.
     */
    double getGalMed() const;

    /**
     * @brief Nustato pažymius.
     * @param paz Nauji pažymiai.
     */
    void setPaz(const std::vector<int>& paz);

    /**
     * @brief Prideda pažymį.
     * @param pazymys Naujas pažymys.
     */
    void addPazymys(int pazymys);

    /**
     * @brief Nustato egzamino rezultatą.
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
     */
    friend std::istream& operator>>(std::istream& in, Studentas& s);

    /**
     * @brief Išvesties operatorius.
     */
    friend std::ostream& operator<<(std::ostream& out, const Studentas& s);
};

/**
 * @brief Apskaičiuoja medianą.
 * @param paz Pažymių vektorius.
 * @return Mediana.
 */
double mediana(const std::vector<int>& paz);

/**
 * @brief Apskaičiuoja studento galutinius balus.
 * @param a Studentas.
 */
void skaiciuoti(Studentas& a);

/**
 * @brief Sugeneruoja atsitiktinį pažymį.
 * @return Atsitiktinis pažymys.
 */
int atsitiktinis_pazymys();

/**
 * @brief Grąžina pasirinktą galutinį balą.
 * @param a Studentas.
 * @param vm Vidurkis arba mediana.
 * @return Galutinis balas.
 */
double galutinis_pagal(const Studentas& a, char vm);