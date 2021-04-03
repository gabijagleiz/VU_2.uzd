#define pragma once
#include <iostream>
#include <list>

void sort (list <Studentas> S, int k);
bool CompareLastNames(Studentas& a, Studentas& b);
void rikiavimas(list <Studentas>& S);
double vidurkis(list <Studentas> S, int k);
double mediana (list <Studentas> S, int k);
void skirstymas(list <Studentas> &S, list <Studentas> &protingi, list <Studentas> &nevykeliai, int k);
void spausdinimas(list <Studentas> &S, list <Studentas> &protingi, list <Studentas> &nevykeliai);
//void spausdinimas(list <Studentas> S, int k);
void Livedimas(list <Studentas> &S, list <Studentas> &protingi, list <Studentas> &nevykeliai);
void Lskaitymas(list <Studentas> &S, list <Studentas> &protingi, list <Studentas> &nevykeliai);
void generavimas(list <Studentas> &S);
void Lgenskaitymas(list <Studentas> &S, list <Studentas> &protingi, list <Studentas> &nevykeliai);