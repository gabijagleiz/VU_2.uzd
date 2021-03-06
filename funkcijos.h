#define pragma once

#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <time.h>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>


using namespace std;
//const int k = 100;
const char DFV[] = "kursiokai.txt";

struct Studentas {
	string var;    //vardas
	string pav;    //pavarde
	int nkiek;
	vector <int> nd;     //namu darbu rezultatas
	int egz;    //egzamino rezultatas
	double vid;
	double med;
	
};

void sort (vector <Studentas> S, int k);
bool CompareLastNames(Studentas& a, Studentas& b);
void rikiavimas(vector <Studentas> S);
double vidurkis(vector <Studentas> S, int k);
double mediana (vector <Studentas> S, int k);
void spausdinimas(vector <Studentas> S, int k);
void ivedimas(vector <Studentas> S);
void skaitymas(vector <Studentas> S);
