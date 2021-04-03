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

