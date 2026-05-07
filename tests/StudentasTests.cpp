#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <type_traits>
#include <utility>

#include "studentas.h"
#include "Zmogus.h"

TEST_CASE("Zmogus klase yra abstrakti") {
    REQUIRE(std::is_abstract_v<Zmogus>);
}

TEST_CASE("Studentas default konstruktorius") {
    Studentas s;

    REQUIRE(s.getVardas() == "");
    REQUIRE(s.getPavarde() == "");
    REQUIRE(s.getPaz().empty());
    REQUIRE(s.getEgz() == 0);
}

TEST_CASE("Parametrinis konstruktorius") {
    Studentas s("Jonas", "Jonaitis", {8, 9, 10}, 9);

    REQUIRE(s.getVardas() == "Jonas");
    REQUIRE(s.getPavarde() == "Jonaitis");
    REQUIRE(s.getPaz().size() == 3);
    REQUIRE(s.getEgz() == 9);
}

TEST_CASE("Copy konstruktorius") {
    Studentas a("Petras", "Petraitis", {7, 8, 9}, 10);
    Studentas b(a);

    REQUIRE(b.getVardas() == a.getVardas());
    REQUIRE(b.getPaz() == a.getPaz());
}

TEST_CASE("Move konstruktorius") {
    Studentas a("Ona", "Onaite", {10, 9, 8}, 10);
    Studentas b(std::move(a));

    REQUIRE(b.getVardas() == "Ona");
}

TEST_CASE("Copy assignment") {
    Studentas a("Ieva", "Ievaite", {5, 6, 7}, 8);
    Studentas b;

    b = a;

    REQUIRE(b.getVardas() == "Ieva");
}

TEST_CASE("Move assignment") {
    Studentas a("Mantas", "Mantaitis", {6, 7, 8}, 9);
    Studentas b;

    b = std::move(a);

    REQUIRE(b.getVardas() == "Mantas");
}

TEST_CASE("operatorius >>") {
    std::istringstream in("Tomas Tomaitis 8 9 10 9");

    Studentas s;
    in >> s;

    REQUIRE(s.getVardas() == "Tomas");
}

TEST_CASE("operatorius <<") {
    Studentas s("Ruta", "Rutaite", {8, 9, 10}, 9);

    std::ostringstream out;
    out << s;

    REQUIRE_FALSE(out.str().empty());
}