#include "funkcijos.h"

int main(){
	srand (time(NULL));
    vector <Studentas> S;
    vector <Studentas> protingi;
	vector <Studentas> nevykeliai;

    char ats;
    cout << "Duomenys ivesite ranka, skaitysite is failo ar generuosite faila? (i/s/g) ";
    	cin >> ats;

	if (ats == 'i' || ats == 'I'){
		ivedimas(S, protingi, nevykeliai);
	}
	
	if (ats == 's' || ats == 'S'){
		skaitymas(S, protingi, nevykeliai);
	}

	if (ats == 'g' || ats == 'G'){
		genskaitymas(S, protingi, nevykeliai);
	}
    
}
