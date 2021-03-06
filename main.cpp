#include "funkcijos.h"

int main(){
	srand (time(NULL));
    vector <Studentas> S;
    
    char ats;
    cout << "Duomenys ivesite ranka ar skaitysite is failo? (i/s) ";
    	cin >> ats;

	if (ats == 'i' || ats == 'I'){
		ivedimas(S);
	}
	
	if (ats == 's' || ats == 'S'){
		skaitymas(S);
	}
    
}
