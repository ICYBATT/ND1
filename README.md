## Projekto aprasymas

Tai C++ programa, skirta studentu duomenu apdorojimui ir spartos tyrimui.

Programa leidzia:
- ivesti studentus ranka
- generuoti pazymius
- generuoti studentus automatiskai
- nuskaityti duomenis is failo
- suskirstyti studentus i vargsiukus ir kietiakius
- atlikti spartos tyrimus


## Versijos


### v0.4
v0.4 versijoje realizuota:
- studentu nuskaitymas is failu
- studentu skirstymas i dvi grupes
- testiniu failu generavimas
- vieno failo ir visu failu spartos tyrimai

### v1.0
v1.0 versijoje papildomai realizuota:
- triju konteineriu analize:
  - vector
  - list
  - deque
- trys studentu skirstymo strategijos
- rikiavimo laiko matavimas
- keliu paleidimu vidurkio skaiciavimas
- CMake failas

## Testavimo sistema

Testavimas atliktas su sia sistema:
- Operacine sistema: Windows 11
- Procesorius: AMD Ryzen 9 5900X
- Branduoliai / gijos: 12 / 24
- RAM: 15.9 GB
- Diskai:
  - SSD (NVMe)
  - HDD (SATA)
- Vaizdo plokste: NVIDIA GeForce RTX 3080
- Kompiliatorius / aplinka: MSVC / Visual Studio Code

## Testavimas


### Vector konteineris

Atliktas vector konteinerio testavimas su visomis trimis strategijomis:

- Strategija 1 – veikia korektiškai
- Strategija 2 – veikia korektiškai
- Strategija 3 – veikia korektiškai

Naudotas failas:
- studentai1000.txt

Rezultatai:
- programa nelūžta
- skirstymas veikia teisingai
- gaunami vargšiukai ir kietiakai


### List konteineris

Atliktas list konteinerio testavimas su visomis trimis strategijomis:

- Strategija 1 – veikia korektiškai
- Strategija 2 – veikia korektiškai
- Strategija 3 – veikia korektiškai

Naudotas failas:
- studentai1000.txt

Rezultatai:
- programa nelūžta
- skirstymas veikia teisingai
- gaunami vargšiukai ir kietiakai


### Deque konteineris


Atliktas deque konteinerio testavimas su visomis trimis strategijomis:

- Strategija 1 – veikia korektiškai
- Strategija 2 – veikia korektiškai
- Strategija 3 – veikia korektiškai

Naudotas failas:
- studentai1000.txt

  
## Tyrimo metodika

Visi testai atlikti naudojant tuos pacius sugeneruotus failus.

Kiekvienas testas buvo vykdomas 5 kartus, o rezultatas – vidurkis.


Rezultatai:
- programa veikia stabiliai
- visi skirstymai atliekami teisingai

## Programos paleidimas

Programa paleidziama taip:

1. Atidaryti projekto aplanka.
2. Sukompiliuoti projekta (per Visual Studio arba tasks.json).
3. Paleisti `main.exe`.
4. Pasirinkti skaiciavimo buda:
   - V - vidurkis
   - M - mediana
5. Naudoti meniu:

Svarbiausi punktai:
- 7 - generuoti testinius failus
- 10 - vieno failo konteineriu tyrimas
- 11 - visu failu konteineriu tyrimas


## Isvados

Atlikus tyrima su `vector`, `list` ir `deque`, galima teigti, kad:

- `vector` daugeliu atveju yra greiciausias.
- `list` patogus elementu salinimui, bet ne visada optimalus.
- `deque` uzima tarpine vieta tarp `vector` ir `list`.
- 2 strategija yra letesne del elementu salinimo.
- 1 ir 3 strategijos veikia efektyviau.

Didinant duomenu kieki, skirtumai tarp konteineriu tampa labiau pastebimi.
