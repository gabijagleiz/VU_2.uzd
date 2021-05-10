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
#include <list>
#include <deque>
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
/*bool CompareLastNames(Studentas& a, Studentas& b);

template <class T>
void rikiavimas(T& );*/

double vidurkis(vector <Studentas> S, int k);
double mediana (vector <Studentas> S, int k);

bool isWinner(Studentas const& S);
bool isLooser(Studentas const& S);

template <class T>
void skirstymas(T&, T&, T&);


template <class T>
void spausdinimas(T&, T&, T&);

//void skirstymas(vector <Studentas> &S, vector <Studentas> &protingi, vector <Studentas> &nevykeliai, int k)
//void spausdinimas(vector <Studentas> S, int k);

template <class T>
void ivedimas(T&, T&, T&);

template <class T>
void skaitymas(T&, T&, T&);

template <class T>
void generavimas(T&);

template <class T>
void genskaitymas(T&, T&, T&);

template <class T>
void duomenys(T&, T&, T&);

//template <class T>
void galutinis(char);

