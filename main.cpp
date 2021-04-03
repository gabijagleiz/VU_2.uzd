#include "vector.h"
#include "list.h"
#include "deque.h"
#include "funkcijos.h"

int main(){
	srand (time(NULL));
    vector <Studentas> S;
    vector <Studentas> protingi;
	vector <Studentas> nevykeliai;
	list <Studentas> S;
    list <Studentas> protingi;
	list <Studentas> nevykeliai;
	deque <Studentas> S;
    deque <Studentas> protingi;
	deque <Studentas> nevykeliai;

    char ats;
    cout << "Duomenys ivesite ranka, skaitysite is failo ar generuosite faila? (i/s/g) ";
    	cin >> ats;

	if (ats == 'i' || ats == 'I'){
		cout << "Darbas su vector" << endl; 
		Vivedimas(S, protingi, nevykeliai);
		cout << "Darbas su list" << endl; 
		Livedimas(S, protingi, nevykeliai);
		cout << "Darbas su deque" << endl; 
		Divedimas(S, protingi, nevykeliai);
	}
	
	if (ats == 's' || ats == 'S'){
		cout << "Darbas su vector" << endl; 
		Vskaitymas(S, protingi, nevykeliai);
		cout << "Darbas su list" << endl; 
		Lskaitymas(S, protingi, nevykeliai);
		cout << "Darbas su deque" << endl; 
		Dskaitymas(S, protingi, nevykeliai);
}

	if (ats == 'g' || ats == 'G'){
		cout << "Darbas su vector" << endl; 
		Vgenskaitymas(S, protingi, nevykeliai);
		cout << "Darbas su list" << endl; 
		Lgenskaitymas(S, protingi, nevykeliai);
		cout << "Darbas su deque" << endl; 
		Dgenskaitymas(S, protingi, nevykeliai);
}
    
}