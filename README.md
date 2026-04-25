# ND1 v1.5

## Projekto aprašymas

Tai C++ programa, skirta studentų duomenų apdorojimui, rūšiavimui, skirstymui ir spartos tyrimams.

Programa leidžia:

* įvesti studentus rankiniu būdu
* generuoti pažymius
* pilnai generuoti studentus
* nuskaityti duomenis iš failo
* išvesti rezultatus į ekraną arba failą
* suskirstyti studentus į vargšiukus ir kietiakus
* atlikti spartos tyrimus
* testuoti Studentas klasės veikimą

---

## v1.5 versijos tikslas

v1.5 versijoje realizuotas paveldimumas:

* sukurta abstrakti bazinė klasė `Zmogus`
* klasė `Studentas` yra išvestinė iš `Zmogus`
* išlaikyta visa v1.2 programos logika
* patikrintas visų metodų veikimas

---

## Abstrakti klasė Zmogus

Bazė:

```cpp
class Zmogus
```

Klasė yra abstrakti, nes turi grynai virtualų metodą:

```cpp
virtual void spausdintiInformacija() const = 0;
```

Dėl to negalima kurti objektų:

```cpp
Zmogus z; // nesikompiliuoja
```

Galima kurti tik išvestines klases objektus:

```cpp
Studentas s;
```

---

## Paveldimumas

`Studentas` klasė paveldi iš `Zmogus`:

```cpp
class Studentas : public Zmogus
```

Paveldimi bendri duomenys:

* vardas
* pavardė

Papildomi Studentas duomenys:

* pažymiai
* egzamino balas
* galutinis balas (vidurkis ir mediana)

---

## Rule of Five

Studentas klasėje realizuota penkių metodų taisyklė:

| Metodas             | Aprašymas               |
| ------------------- | ----------------------- |
| Destruktorius       | Objektų sunaikinimas    |
| Copy konstruktorius | Objekto kopijavimas     |
| Copy assignment     | Priskyrimas kopijuojant |
| Move konstruktorius | Objektų perkėlimas      |
| Move assignment     | Priskyrimas perkeliant  |

Papildomai realizuota:

* default konstruktorius
* parametrinis konstruktorius
* įvesties operatorius `>>`
* išvesties operatorius `<<`

---

## Metodų aprašymas

### Duomenų įvedimas

* Rankinis įvedimas – vartotojas įveda visus duomenis
* Dalinis generavimas – pažymiai generuojami automatiškai
* Pilnas generavimas – sugeneruojami visi duomenys
* Nuskaitymas iš failo – duomenys skaitomi iš `.txt`

### Duomenų išvedimas

* Į ekraną – rezultatai pateikiami terminale
* Į failą – rezultatai išsaugomi `.txt` faile
* Skirstymas – sukuriami `vargsiukai.txt` ir `kietiakai.txt`

### Skaičiavimai

Galutinis balas skaičiuojamas pagal formulę:

```
0.4 * ND + 0.6 * egzaminas
```

---

## Testavimas

Programa turi integruotus testus (meniu pasirinkimas 12).

Testuojama:

| Testas                      | Tikslas                      |
| --------------------------- | ---------------------------- |
| Default konstruktorius      | Patikrina tuščią objektą     |
| Parametrinis konstruktorius | Patikrina duomenų priskyrimą |
| Copy konstruktorius         | Patikrina kopijavimą         |
| Copy assignment             | Patikrina priskyrimą         |
| Move konstruktorius         | Patikrina perkėlimą          |
| Move assignment             | Patikrina perkėlimą          |
| operator<<                  | Patikrina išvedimą           |
| operator>>                  | Patikrina įvedimą            |
| Paveldimumas                | Studentas per Zmogus rodyklę |
| Destruktorius               | Objektų sunaikinimas         |

Rezultatas:

```
Praejo 11 is 11 testu (visi testai sekmingi)
```

---

## Duomenų įvedimas

| Būdas       | Aprašymas                         |
| ----------- | --------------------------------- |
| Rankinis    | Vartotojas įveda duomenis         |
| Generavimas | Duomenys generuojami automatiškai |
| Failas      | Nuskaitymas iš `.txt` failo       |

---

## Duomenų išvedimas

| Būdas      | Aprašymas                |
| ---------- | ------------------------ |
| Ekranas    | Išvedama į terminalą     |
| Failas     | Išsaugoma į `.txt`       |
| Skirstymas | Sukuriami atskiri failai |

---

## Programos veikimo logika

Programa išlaiko v1.2 funkcionalumą:

* rūšiavimas
* skirstymas
* failų nuskaitymas
* spartos matavimas

Papildomai:

* realizuotas paveldimumas
* realizuota abstrakti klasė

---

## Testavimo aplinka

| Komponentas    | Reikšmė            |
| -------------- | ------------------ |
| OS             | Windows 11         |
| CPU            | AMD Ryzen 9        |
| RAM            | 16 GB              |
| Kompiliatorius | MSVC               |
| Aplinka        | Visual Studio Code |

---

## Programos veikimo pavyzdys

<img width="708" height="378" alt="image" src="https://github.com/user-attachments/assets/fec09c68-2b6d-400f-8b0e-570a199ea6cd" />


---

## Išvada

v1.5 versijoje programa papildyta paveldimumu.

Sukurta abstrakti klasė `Zmogus`, iš kurios paveldi `Studentas`.
Programa išlaiko v1.2 logiką, realizuoja Rule of Five ir turi pilnai veikiančius testus.
