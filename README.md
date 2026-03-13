v0.4 – Programos spartos tyrimas

Šioje versijoje atliktas programos testavimas naudojant sugeneruotus skirtingo dydžio studentų duomenų failus.

Naudoti testiniai failai:
- studentai1000.txt
- studentai10000.txt
- studentai100000.txt
- studentai1000000.txt
- studentai10000000.txt

Programa matuoja:
- failo nuskaitymo laiką
- studentų skirstymo į vargšiukus ir kietiakus laiką
- rezultatų išvedimo laiką
- bendrą vykdymo laiką

Studentai skirstomi į dvi grupes naudojant atskirus konteinerius:
- vargšiukai
- kietiakiai

## Programos veikimo eiga:

1. Sugeneruojami testiniai studentų duomenų failai.
2. Failai nuskaityti į programą.
3. Studentai suskirstomi į dvi grupes:
   - vargšiukai
   - kietiakai
4. Rezultatai išvedami į atskirus failus.
5. Atliekamas programos spartos tyrimas.

Tyrimas atliktas naudojant release programos versiją.
Rezultatai ir lentelės pateikti README.md faile.

Kiekvieno failo testavimas buvo atliktas kelis kartus,
o lentelėje pateikti vidutiniai vykdymo laikai.

## Testavimo rezultatai

| Failas | Studentų kiekis | Nuskaitymas (s) | Skirstymas (s) | Išvedimas (s) | Visas laikas (s) |
|------|------|------|------|------|------|
| studentai1000.txt | 1000 | 0.019 | 0.0004 | 0.0034 | 0.023 |
| studentai10000.txt | 10000 | 0.182 | 0.0054 | 0.019 | 0.207 |
| studentai100000.txt | 100000 | 1.82 | 0.047 | 0.185 | 2.05 |
| studentai1000000.txt | 1000000 | 18.15 | 0.48 | 1.78 | 20.42 |
| studentai10000000.txt | 10000000 | 182.73 | 5.31 | 17.82 | 205.87 |


## Testinių failų generavimas

![Testinių failų generavimas](https://github.com/user-attachments/assets/8650d3b8-3a96-4c8f-a963-4f78403c5324)
