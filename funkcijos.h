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
bool CompareLastNames(Studentas& a, Studentas& b);

template <class T>
void rikiavimas(T& );

double vidurkis(vector <Studentas> S, int k);
double mediana (vector <Studentas> S, int k);


template <class T>
void skirstymas(T&, T&, T&, int k);


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

/*
template <class T>
void Trikiavimas(T & S)
{
    sort(S.begin(), S.end(), CompareLastNames);
}

template <class T>
void Tskirstymas(T &S, T &protingi, T &nevykeliai, int k){
	auto start = high_resolution_clock::now();
	int pk = 0;
	int nk = 0;
	for (int i = 0; i < k; i++){
		if (S[i].gr >= 5){
			protingi.push_back(S[i]);
		//	pk++;
			}
		if (S[i].gr < 5){
			nevykeliai.push_back(S[i]);
			//nk++;
			}
	}
	auto end= high_resolution_clock::now();
	duration<double> diff= end-start; 
	cout << "duomenu skirstymas uztruko: " << diff.count() << "s\n" << endl;

	S.clear();
}

template <class T>
void Tspausdinimas(T &S, T &protingi, T &nevykeliai){
//	auto start = high_resolution_clock::now();

	ofstream rf;	
	
	rf.open("nevykeliai.txt");
	rf << left << setw(12) << "Vardas " << setw(15) << "Pavarde " << setw(15) << "Galutinis " <<endl;
	for (int i = 0; i < 45; i++)
	rf << "-";
	rf << endl;
	for(int i = 0; i < nevykeliai.size(); i++){
	rf << left << setw(12) << nevykeliai[i].var << setw(15) << nevykeliai[i].pav << setw(15) << fixed << setprecision(2) << nevykeliai[i].gr << endl;
	}

	nevykeliai.clear();
	rf.close();

	rf.open("protingi.txt");
	rf << left << setw(12) << "Vardas " << setw(15) << "Pavarde " << setw(15) << "Galutinis "  <<endl;
	for (int i = 0; i < 45; i++)
	rf << "-";
	rf << endl;
	for(int i = 0; i < protingi.size(); i++){
	rf << left << setw(12) << protingi[i].var << setw(15) << protingi[i].pav << setw(15) << fixed << setprecision(2) << protingi[i].gr << endl;
	}

/*	auto end= high_resolution_clock::now();
	duration<double> diff= end-start; 
	cout << "duomenu spausdinimas uztruko: " << diff.count() << "s\n" << endl;

	protingi.clear();
	rf.close();

}	

template <class T>
//egzistuojansio failo skaitymas ir spausdinimas
void skaitymas(T &S, T &protingi, T &nevykeliai){

	int k;
	char pas;
	cout << "Koki studentu kieki nuskaityti?\n" << "1 - 1000 \n" << "2 - 10000 \n" << "3 - 100000 \n" << "4 - 1000000 \n" << "5 - 10000000\n";
	do{
		cin >> pas;

		if (pas == 1) k = 1000;
		if (pas == 2) k = 10000;
		if (pas == 3) k = 100000;
		if (pas == 4) k = 1000000;
		if (pas == 5) k = 10000000;

	}while (pas > 5 || pas < 1);
	
	auto start= high_resolution_clock::now();

            stringstream buffer;
            ifstream df("Failas" + to_string(k) + ".txt");
            buffer << df.rdbuf();
            string line;
            getline(buffer, line);
            Studentas studentas;

		 try
        {
            if (!df.good())
                throw "Toks failas neegzistuoja.";
        }
        catch(const char *Message)
        {
            cout << Message << endl;
        }

            while (getline(buffer, line))
            {
                stringstream df(line);
                int paz;
                df >> studentas.var >> studentas.pav;
                while (df >> paz) studentas.nd.push_back(paz);   
                studentas.nd.pop_back();
                studentas.nkiek = studentas.nd.size();
                studentas.egz = paz;
                studentas.vid = vidurkis(studentas.nd, studentas.nkiek, studentas.egz);
                studentas.med = mediana(studentas.nd, studentas.nkiek, studentas.egz);
				studentas.gr = (studentas.vid+studentas.med) / 2;
                S.push_back(studentas);

				k++;
            }

		try
        {
            if (k == 0)
                throw "Nuskaitytas failas tuščias! ";
        }
        catch(const char *Message)
        {
            cout << Message << endl;
        }

	auto end= high_resolution_clock::now();
	duration<double> diff= end-start; 
	cout << "Failo skaitymas uztruko: " << diff.count() << "s\n" << endl;

	if (k > 0) {
		Trikiavimas(S);
		Tskirstymas(S, protingi, nevykeliai, k);
		Tspausdinimas(S, protingi, nevykeliai);
	}

	df.close();
}
*/