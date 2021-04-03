#define pragma once
#include <iostream>
#include <vector>

void sort (vector <Studentas> S, int k);
bool CompareLastNames(Studentas& a, Studentas& b);
void rikiavimas(vector <Studentas>& S);
double vidurkis(vector <Studentas> S, int k);
double mediana (vector <Studentas> S, int k);
void skirstymas(vector <Studentas> &S, vector <Studentas> &protingi, vector <Studentas> &nevykeliai, int k);
void spausdinimas(vector <Studentas> &S, vector <Studentas> &protingi, vector <Studentas> &nevykeliai);
//void spausdinimas(vector <Studentas> S, int k);
void Vivedimas(vector <Studentas> &S, vector <Studentas> &protingi, vector <Studentas> &nevykeliai);
void Vskaitymas(vector <Studentas> &S, vector <Studentas> &protingi, vector <Studentas> &nevykeliai);
void generavimas(vector <Studentas> &S);
void Vgenskaitymas(vector <Studentas> &S, vector <Studentas> &protingi, vector <Studentas> &nevykeliai);
