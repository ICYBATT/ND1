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

Rezultatai:
- programa veikia stabiliai
- visi skirstymai atliekami teisingai
