#pragma once
#include <string>

/**
 * @class Zmogus
 * @brief Abstrakti bazinė žmogaus klasė.
 *
 * Ši klasė saugo pagrindinius žmogaus duomenis:
 * vardą ir pavardę.
 *
 * Klasė naudojama kaip bazinė klasė Studentas klasei.
 */
class Zmogus {
protected:
    std::string vardas_;
    std::string pavarde_;

public:

    /**
     * @brief Default konstruktorius.
     */
    Zmogus();

    /**
     * @brief Parametrinis konstruktorius.
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
     * @return Žmogaus vardas.
     */
    const std::string& getVardas() const;

    /**
     * @brief Grąžina pavardę.
     * @return Žmogaus pavardė.
     */
    const std::string& getPavarde() const;

    /**
     * @brief Nustato vardą.
     * @param vardas Naujas vardas.
     */
    void setVardas(const std::string& vardas);

    /**
     * @brief Nustato pavardę.
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

inline void Zmogus::setVardas(const std::string& vardas) { vardas_ = vardas; }
inline void Zmogus::setPavarde(const std::string& pavarde) { pavarde_ = pavarde; }