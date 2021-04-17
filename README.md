# VU_2.uzd

# Paskirtis
Programa skirta studentų duomenų nuskaitymui ir išskaidymui į du atskirus failus.

# Veikimo principas
Paleidus programą vartotojo prašo :
- Pasirinkti ar duomenys bus įvedami, skaitomi ar generuojamas naujas atsitiktinis failas (rašyti 'i' (įvedami), 's' (skaitomi) arba 'g' (generuojami)) 

### Pasirinkus 'i' (duomenys įvedami), vartotojo prašoma:
- Įvesti studentų kiekį 
- Įvesti studento vardą, pavardę
- Pasirinkti, ar namų darbų kiekis bus įvedamas ranka (rašyti 't' (Taip) arba 'n' (Ne))
  - Pasirinkus 't', įvesti namų darbų kiekį
- Pasirinkti, ar namų darbų rezultatai bus įvedami ranka (rašyti 't' (Taip) arba 'n' (Ne))
  - Pasirinkus 't', įvesti namų darbų rezultatus
- Pasirinkti, ar egzamino rezultatas bus įvedamas ranka (rašyti 't' (Taip) arba 'n' (Ne))
  - Pasirinkus 't', įvesti egzamino rezultatą
- Pasirinkti, ar norima išvesti vidurkį, ar medianą (rašyti 'v' (vidurkį) arba 'm' (medianą))


Įvedant duomenis, vartotojui pasirinkus 'n', rezultatai/kiekis yra sugeneruojami atsitiktinai. 

Tada duomenys yra išrikiuojami ir išvedami į du failus: protingi (galutinis įvertinimas >=5) ir nevykeliai (galutinis įvertinimas <5).

### Pasirinkus 's' (duomenys skaitomi):
- duomenys yra nuskaitomi, išrikiuojami ir išvedami į du failus: protingi (galutinis įvertinimas >=5) ir nevykeliai (galutinis įvertinimas <5)

### Pasirinkus 'g' (duomenys generuojami), vartotojo prašoma: 
-Pasirinkti studentų kiekį (1 - 1000, 2 - 10000, 3 - 100000, 4 - 100000, 5 - 1000000)
-Pasirinkus 1, bus generuojama 1000 studentų, pasirinkus 2 - 10000 ir t.t.

Tada duomenys yra išrikiuojami ir išvedami į du failus: protingi (galutinis įvertinimas >=5) ir nevykeliai (galutinis įvertinimas <5).

### Svarbu
- Įvedant pažymius ranka, juos atskirti 'space' klavišu
- Įvedus paskutinį pažymį spausti 'enter' klavišą
- Įvedant studentų kiekį, įvedus skaičių mažesnį/lygu 0 arba didesnį už 100, reikės įvesti naują skaičių
- Įvedant namų darbų ar egzaminų rezultatus, įvedus skaičių mažesnį už 1 arba didesnį už 10, reikės įvesti naują skaičių

# Programos įdiegimas
- Atsisiųskite programos versiją iš [releases](https://github.com/gabijagleiz/VU_2.uzd/releases)
- Išarchivuokite parsisiųstą failą.
- Paleiskite main.cpp naudojantis C++ IDE

# Versijos
- [v0.1](https://github.com/gabijagleiz/VU_2.uzd/releases/tag/v0.1)
- [v0.1.1](https://github.com/gabijagleiz/VU_2.uzd/releases/tag/v.1.1) pataisyta 0.1 versija
- [v0.2](https://github.com/gabijagleiz/VU_2.uzd/releases/tag/v0.2) pridėta galimybė skaityti duomenis iš failo
- [v0.3](https://github.com/gabijagleiz/VU_2.uzd/releases/tag/v0.3) pridėtas header failas, du cpp failai
- [v0.3.1](https://github.com/gabijagleiz/VU_2.uzd/releases/tag/v0.3.1) pridėtas išimčių valdymas
- [v0.4](https://github.com/gabijagleiz/VU_2.uzd/releases/tag/v0.4) pridėta galimybėta generuoti naują studentų failą. Duomenų išskaidymas į du failus.
- [v0.5](https://github.com/gabijagleiz/VU_2.uzd/releases/tag/v0.5) pridėta galimybė rinktis konteinerį
