#define pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <time.h>
#include <chrono>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>


using namespace std;
using namespace std::chrono;
//const int k = 100;
const char DFV[] = "failas1000.txt";

struct Studentas {
	string var;    //vardas
	string pav;    //pavarde
	int nkiek;
	vector <int> nd;  //namu darbu rezultatas
	int egz;    //egzamino rezultatas
	double vid;
	double med;
	double gr;  //galutinis rezultatas
	
};

void sort (vector <Studentas> S, int k);
bool CompareLastNames(Studentas& a, Studentas& b);
void rikiavimas(vector <Studentas>& S);
double vidurkis(vector <Studentas> S, int k);
double mediana (vector <Studentas> S, int k);
void skirstymas(vector <Studentas> &S, vector <Studentas> &protingi, vector <Studentas> &nevykeliai, int k);
void spausdinimas(vector <Studentas> &S, vector <Studentas> &protingi, vector <Studentas> &nevykeliai);
//void spausdinimas(vector <Studentas> S, int k);
void ivedimas(vector <Studentas> &S, vector <Studentas> &protingi, vector <Studentas> &nevykeliai);
void skaitymas(vector <Studentas> &S, vector <Studentas> &protingi, vector <Studentas> &nevykeliai);
void generavimas(vector <Studentas> &S);
void genskaitymas(vector <Studentas> &S, vector <Studentas> &protingi, vector <Studentas> &nevykeliai);
