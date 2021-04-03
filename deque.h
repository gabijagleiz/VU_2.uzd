#define pragma once
#include <iostream>
#include <deque>

void sort (deque <Studentas> S, int k);
bool CompareLastNames(Studentas& a, Studentas& b);
void rikiavimas(deque <Studentas>& S);
double vidurkis(deque <Studentas> S, int k);
double mediana (deque <Studentas> S, int k);
void skirstymas(deque <Studentas> &S, deque <Studentas> &protingi, deque <Studentas> &nevykeliai, int k);
void spausdinimas(deque <Studentas> &S, deque <Studentas> &protingi, deque <Studentas> &nevykeliai);
//void spausdinimas(deque <Studentas> S, int k);
void Divedimas(deque <Studentas> &S, deque <Studentas> &protingi, deque <Studentas> &nevykeliai);
void Dskaitymas(deque <Studentas> &S, deque <Studentas> &protingi, deque <Studentas> &nevykeliai);
void generavimas(deque <Studentas> &S);
void Dgenskaitymas(deque <Studentas> &S, deque <Studentas> &protingi, deque <Studentas> &nevykeliai);