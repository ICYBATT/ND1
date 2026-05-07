# ND1 v2.0

## Projekto aprašymas

Tai C++ programa, skirta studentų duomenų apdorojimui, rūšiavimui, skirstymui bei spartos tyrimams naudojant skirtingus STL konteinerius.

---

# Programos galimybės

- rankinė įvestis
- automatinis generavimas
- failų skaitymas
- rūšiavimas
- skirstymas į grupes
- spartos tyrimai
- dokumentacijos generavimas

---

# Versijų istorija

## v0.1
- bazinė programos versija

## v0.2
- pridėtas failų skaitymas

## v0.4
- pridėti spartos tyrimai

## v1.0
- konteinerių analizė (`vector`, `list`, `deque`)
- realizuotos 3 strategijos

## v1.2
- realizuotas Rule of Five
- operatorių perdengimas

## v1.5
- realizuotas paveldėjimas (`Zmogus`)

## v2.0
- unit testai
- Doxygen dokumentacija
- PDF dokumentacija
- optimizuotas projektas

---

# Naudojimosi instrukcija

## Programos paleidimas

```bash
./main
```

## Programos meniu

1 - rankinė įvestis  
2 - automatinis generavimas  
3 - skaitymas iš failo  
4 - rūšiavimas  
5 - skirstymas  
6 - spartos tyrimai  

---

# Įdiegimo instrukcija

## CMake build

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

---

# Unit testai

Unit testai realizuoti naudojant Catch2 framework.

Testų tikslas – patikrinti svarbiausią `Studentas` klasės funkcionalumą ir parodyti, kad klasė veikia teisingai.

Testuojama:

| Testas | Ką tikrina |
|---|---|
| Default konstruktorius | Ar tuščias `Studentas` objektas sukuriamas teisingai |
| Parametrinis konstruktorius | Ar studento duomenys teisingai perduodami per konstruktorių |
| Copy konstruktorius | Ar objektas teisingai nukopijuojamas |
| Move konstruktorius | Ar objektas teisingai perkeliamas |
| Copy assignment operatorius | Ar objektas teisingai priskiriamas kopijuojant |
| Move assignment operatorius | Ar objektas teisingai priskiriamas perkeliant |
| `operator>>` | Ar studento duomenys teisingai nuskaitomi iš srauto |
| `operator<<` | Ar studento duomenys teisingai išvedami į srautą |

Rule of Five tikrinimas yra būtina v2.0 dalis, todėl testuose tikrinami:

- copy konstruktorius
- move konstruktorius
- copy assignment operatorius
- move assignment operatorius
- destruktoriaus veikimas per objekto gyvavimo ciklą

## Testų paleidimas

```bash
ctest
```

## Unit testų rezultatai

<img width="822" height="359" alt="image" src="https://github.com/user-attachments/assets/62696500-b3c8-42a8-8ae9-20faae91517b" />


---

# Doxygen dokumentacija

Dokumentacija generuojama naudojant Doxygen ir MiKTeX.

## HTML generavimas

```bash
doxygen Doxyfile
```

## PDF generavimas

```bash
cd latex
make.bat
```

Sugeneruojamas:
- HTML dokumentacijos aplankas
- `refman.pdf`

---

# Spartos tyrimai

Atlikus tyrimus pastebėta, kad `vector` konteineris daugeliu atvejų veikė greičiausiai, ypač dirbant su dideliais duomenų kiekiais.

## Testavimo sistema

| Komponentas | Reikšmė |
|---|---|
| OS | Windows 11 |
| CPU | AMD Ryzen 9 5900X 12-Core |
| RAM | 16 GB |

---

# Nuotraukos

## Programos veikimas

<img width="822" height="359" alt="image" src="https://github.com/user-attachments/assets/eefe2baf-8660-4fec-a78a-cd2f6ac1397c" />

## Doxygen dokumentacija

### PDF

<img width="3089" height="2083" alt="image" src="https://github.com/user-attachments/assets/71237d32-10e3-4576-87e1-5aa964318794" />

### HTML

<img width="1526" height="914" alt="image" src="https://github.com/user-attachments/assets/62c0d026-ea04-4a78-9dba-df241ba65e5e" />

---

# Projekto struktūra

```txt
├── main.cpp
├── studentas.cpp
├── studentas.h
├── Zmogus.h
├── tests/
├── Doxyfile
├── CMakeLists.txt
├── README.md
```
