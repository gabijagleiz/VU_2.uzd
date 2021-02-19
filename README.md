# VU_2.uzd

# Paskirtis
Programa skirta studentų duomenų išvedimui į lentelę.

# Veikimo principas
Paleidus programą vartotojo prašo :
- Įvesti studentų kiekį 
- Įvesti studento vardą, pavardę
- Pasirinkti, ar namų darbų kiekis bus įvedamas ranka (rašyti 't' (Taip) arba 'n' (Ne))
  - Pasirinkus 't', įvesti namų darbų kiekį
- Pasirinkti, ar namų darbų rezultatai bus įvedami ranka (rašyti 't' (Taip) arba 'n' (Ne))
  - Pasirinkus 't', įvesti namų darbų rezultatus
- Pasirinkti, ar egzamino rezultatas bus įvedamas ranka (rašyti 't' (Taip) arba 'n' (Ne))
  - Pasirinkus 't', įvesti egzamino rezultatą
- Pasirinkti, ar norima išvesti vidurkį, ar medianą (rašyti 'v' (vidurkį) arba 'm' (medianą))

Pasirinkimo metu, vartotojui pasirinkus 'n', rezultatai/kiekis yra sugeneruojami atsitiktinai. 
Tuomet yra išvedama lentelė su įvestais duomenimis, kurią sudaro skiltys "Vardas", "Pavardė" ir pasirinktinai - "Galutinis(vid.)" arba "Galutinis(med.).
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
