# ND1 v1.1

## Projekto aprasymas

Tai C++ programa, skirta studentu duomenu apdorojimui ir spartos tyrimui.

Programa leidzia:
- ivesti studentus ranka
- generuoti pazymius
- generuoti studentus automatiskai
- nuskaityti duomenis is failo
- suskirstyti studentus i vargsiukus ir kietiakus
- atlikti spartos tyrimus

## v1.1 versijos pakeitimai

Sioje versijoje ankstesne `struct Studentas` realizacija buvo pakeista i `class Studentas`.

Realizuota:
- default konstruktorius
- konstruktorius su parametrais
- copy konstruktorius
- priskyrimo operatorius
- destruktorius
- getteriai ir setteriai

Kadangi pereita is strukturos i klase, buvo atitinkamai pakeisti ir kiti failai:
- `main.cpp`
- `FileIO.cpp`
- `Output.cpp`
- `NaturalSort.cpp`
- `KonteineriuStrategijos.h`

## Testavimo aplinka

Testai atlikti su sia sistema:
- Operacine sistema: Windows 11
- Procesorius: AMD Ryzen 9 5900X
- RAM: 15.9 GB
- Vaizdo plokste: NVIDIA GeForce RTX 3080
- Kompiliatorius: MSVC
- Aplinka: Visual Studio Code

## Struct ir Class palyginimas

Palyginimui naudoti:
- tas pats konteineris: `vector`
- ta pati greiciausia bendroji tyrimo schema
- tie patys failai:
  - `studentai100000.txt`
  - `studentai1000000.txt`

### Veikimo laiko lentele

| Versija | Optimizacija | 100000 | 1000000 |
|---|---:|---:|---:|
| Struct | O1 | 0.674304 s | 6.806057 s |
| Struct | O2 | 0.662797 s | 6.713789 s |
| Struct | O3 | 0.674079 s | 6.799089 s |
| Class  | O1 | 2.126576 s | 21.302598 s |
| Class  | O2 | 2.125712 s | 21.353622 s |
| Class  | O3 | 0.694726 s | 7.069426 s |

## EXE failu dydzio palyginimas

| Versija | O1 | O2 | O3 |
|---|---:|---:|---:|
| Struct | 379904 B | 420352 B | 425984 B |
| Class  | 384000 B | 408064 B | 413184 B |

## Rezultatu analize

- `struct` versija sioje realizacijoje buvo greitesne uz `class` versija su O1 ir O2 optimizacijomis.
- `class` versija su O3 optimizacija stipriai pagreitejo ir savo rezultatais beveik susilygino su `struct` versija.
- Didziausias skirtumas tarp versiju matomas su 1000000 dydzio failu.
- O3 optimizacija turejo didziausia teigiama itaka `class` versijai.
- Programos veikimo laikui daugiausia itakos turi failo nuskaitymas ir rezultatu isvedimas.
- Visi testai atlikti po kelis kartus, siekiant gauti stabilesnius ir patikimesnius rezultatus.

## Isvados

- Perejimas is `struct` i `class` leido realizuoti labiau objektiskai orientuota programa.
- `class Studentas` realizacija atitinka reikalavima tureti pilnai realizuotus konstruktorius ir destruktoriu.
- Optimizavimo flagai turi didele itaka programos spartai.
- Geriausias `class` versijos rezultatas gautas su O3 optimizacija.
- v1.1 versijoje programa sekmingai pritaikyta darbui su klase ir veikia korektiskai.

## Programos paleidimas

### Paprastas paleidimas
- sukompiliuoti projekta
- paleisti `main.exe`

### Optimizuoti paleidimai
- `main_O1.exe`
- `main_O2.exe`
- `main_O3.exe`
