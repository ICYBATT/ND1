#pragma once
#include <string>

/**
 * @brief Abstrakti bazinė žmogaus klasė.
 * 
 * Saugo žmogaus vardą ir pavardę.
 */
class Zmogus {
protected:
    std::string vardas_;
    std::string pavarde_;

public:

    /**
     * @brief Numatytasis konstruktorius.
     */
    Zmogus();

    /**
     * @brief Konstruktorius su parametrais.
     * 
     * @param vardas Žmogaus vardas.
     * @param pavarde Žmogaus pavardė.
     */
    Zmogus(const std::string& vardas, const std::string& pavarde);

    /**
     * @brief Virtualus destruktorius.
     */
    virtual ~Zmogus() = 0;

    /**
     * @brief Išveda žmogaus informaciją.
     */
    virtual void spausdintiInformacija() const = 0;

    /**
     * @brief Grąžina vardą.
     * 
     * @return Vardas.
     */
    const std::string& getVardas() const;

    /**
     * @brief Grąžina pavardę.
     * 
     * @return Pavardė.
     */
    const std::string& getPavarde() const;

    /**
     * @brief Nustato vardą.
     * 
     * @param vardas Naujas vardas.
     */
    void setVardas(const std::string& vardas);

    /**
     * @brief Nustato pavardę.
     * 
     * @param pavarde Nauja pavardė.
     */
    void setPavarde(const std::string& pavarde);
};

inline Zmogus::Zmogus() : vardas_(""), pavarde_("") {}

inline Zmogus::Zmogus(const std::string& vardas, const std::string& pavarde)
    : vardas_(vardas), pavarde_(pavarde) {}

inline Zmogus::~Zmogus() {}

inline const std::string& Zmogus::getVardas() const { return vardas_; }

inline const std::string& Zmogus::getPavarde() const { return pavarde_; }

inline void Zmogus::setVardas(const std::string& vardas) {
    vardas_ = vardas;
}

inline void Zmogus::setPavarde(const std::string& pavarde) {
    pavarde_ = pavarde;
}