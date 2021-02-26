#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
//const int k = 100;

struct Studentas {
	string var;    //vardas
	string pav;    //pavarde
	int nkiek;
	int *nd;     //namu darbu rezultatas
	int egz;    //egzamino rezultatas
	double vid;
	double med;
	
};


void skaitymas (Studentas S[], int k){
	
	srand ( time ( NULL ));
	
	char ats;
	
	for (int i = 0; i < k; i++){
		cout << "Iveskite studento varda ir pavarde ";
		cin >> S[i].var >> S[i].pav;
		cout << endl;
		
		cout << "Ar ivesite namu darbu kieki? (t/n) ";
		cin >> ats;

		

		if (ats == 't' || ats == 'T') {                          //zinomas namu darbu kiekis
			cout << "Iveskite namu darbu kieki ";
		    cin >> S[i].nkiek;
		    cout << endl;
			S[i].nd= new (nothrow) int[S[i].nkiek];

	    	cout << "Ar ivesite namu darbu rezultatus? (t/n) ";
		    cin >> ats;
		    
		    if (ats == 't' || ats == 'T'){                       //zinomi namu darbu rezultatai
		    	cout << "Iveskite namu darbu rezultatus ( > 0) ";
		    	for (int j = 0; j < S[i].nkiek; j++){
		    		int paz;
					do{
						cin >> paz;
						S[i].nd[j] = paz;
					} while (paz < 1 || paz > 10);
					
					}
				cout << endl;
			}
			if (ats == 'n' || ats == 'N'){
				cout << "Sugeneruoti namu darbu rezultatai ";   //nezinomi namu darbu rezultatai
				for (int j = 0; j < S[i].nkiek; j++){
					S[i].nd[j] = rand() % 10 + 1;
					cout << S[i].nd[j] << " ";
				} cout << endl;
			}
		}
		
		
		else if (ats == 'n' || ats == 'N'){                   //nezinomas namu darbu kiekis
		                 
			cout << "Ar ivesite namu darbu rezultatus? (t/n) ";
			cin >> ats;
			
			if (ats == 't' || ats == 'T'){                      //zinomi namu darbu rezultatai
				char paz; 
				cout << "Iveskite namu darbu rezultatus ";
				do {
				S[i].nkiek = 1;
				S[i].nd= new (nothrow) int[S[i].nkiek];   
				for (int j = 0; j < S[i].nkiek; j++){
					cin >> paz;
					S[i].nd[j] = paz;
				//	cout << S[j].nd;
					S[i].nkiek++;
				}
				} while (paz != '\n');
			}	
			
			if (ats == 'n' || ats == 'N'){
				S[i].nkiek = rand()% 10 + 1;
				S[i].nd= new (nothrow) int[S[i].nkiek];   
				cout << "Sugeneruoti pazymiai ";
				for (int j = 0; j < S[i].nkiek; j++){
					S[i].nd[j] = rand() % 10 + 1;
					cout << S[i].nd[j] << " ";
				}
			}	
		}
		
		cout << endl;
		cout << "Ar ivesite egzamino rezultata? (t/n) ";       //egzaminas
		cin >> ats;
	
		if (ats == 't' || ats == 'T'){ 
		cout << "Iveskite egzamino rezultata ( > 0) "    ;   
		int paz;              
		do {
		cin >> paz;
		S[i].egz = paz;
		} while (paz <1 || paz > 10);
		}
	
		if (ats == 'n' || ats == 'N'){
		cout << "Sugeneruotas egzamino rezultatas ";
		S[i].egz = rand() % 10 + 1;
		cout << S[i].egz;
		}
		cout << endl;
	
	
	}
}


void vidurkis(Studentas S[], int k){
	double sum = 0;
//	double nv;
   for (int i = 0; i < k; i++){
   	  for (int j = 0; j < S[i].nkiek; j++){
   	  	sum += S[i].nd[j];
	 }
	S[i].vid = (sum / S[i].nkiek)* 0.4 + S[i].egz * 0.6;
}
}


void sort (Studentas S[], int k){
	for (int i = 0; i < k; i++){
		for (int j = 0; j < S[i].nkiek - 1; j++){
			for (int x = j + 1; x < S[i].nkiek; x++){
				if (S[i].nd[j] < S[i].nd[x]) swap (S[i].nd[j], S[i].nd[x]);
			}
		}
	}	
}


void mediana (Studentas S[], int k){
	double median;
	int d = 0;
    sort(S, k);
    for (int i = 0; i < k; i++){
    	for (int j = 0; j < S[i].nkiek; j++){
    	d = S[i].nkiek;
		if (S[i].nkiek % 2 != 0) median = S[i].nd[d / 2];
    else median = (S[i].nd[d / 2 - 1] + S[i].nd[d / 2]) / 2.0;
	}
	S[i].med = median * 0.4 + S[i].egz * 0.6;
    }
}




void print (Studentas S[], int k){
	char ats;
	cout << "Spausdinti vidurki ar mediana? (v/m) ";
	cin >> ats;
	cout << left << setw(12) << "Vardas " << setw(15) << "Pavarde " << setw(15); 
	if (ats == 'v' || ats == 'V') cout << "Galutinis (vid.)" << endl;
	if (ats == 'm' || ats == 'M') cout << "Galutinis (med.)" <<endl;
	cout << left;
	for (int i = 0; i < 45; i++)
		cout << "-";
	cout << endl;
	for (int i = 0; i < k; i++){
		cout << left << setw(12) << S[i].var << setw(15) << S[i].pav << setw(15) << fixed << setprecision(2);
		if (ats == 'v' || ats == 'V') cout << S[i].vid << endl;
		if (ats == 'm' || ats == 'M') cout << S[i].med << endl;
	}
	
}



int main(){
	int k = 0;
	double sum = 0;
//	int r;
	
	cout << "Kiek studentu ivesite? ";
	do{
		cin >> k;
	} while (k <= 0);
	
	Studentas *S = new Studentas[k];
	
	skaitymas (S, k);
	vidurkis (S, k);
	sort (S, k);
	mediana (S, k);
	print (S, k);
	
	
}
