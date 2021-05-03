#include "funkcijos.h"

void sort (vector <Studentas> S, int k){

	for (int i = 0; i < k; i++)
		for (int j = 0; j < S[i].nkiek - 1; j++){
			for (int x = j + 1; x < S[i].nkiek; x++){
				if (S[i].nd[j] < S[i].nd[x]) swap (S[i].nd[j], S[i].nd[x]);
		}
}
}

/*
bool CompareLastNames(Studentas& a, Studentas& b)
{
    return a.pav < b.pav;
}

template<class T>
void rikiavimas(T& S)
{
    sort(S.begin(), S.end(), CompareLastNames);
}*/


//vidurkis
double vidurkis(vector <int> nd, int nkiek, int egz){
    double vv;
    int sum = 0;
   	  for (int j = 0; j < nkiek; j++){
   	  	sum += nd[j];
	 }
	vv = (sum / nkiek)* 0.4 + egz * 0.6;
    return vv;
}



//mediana
double mediana (vector <int> nd, int nkiek, int egz){
	double median;
	int d = 0;
    	for (int j = 0; j < nkiek; j++){
    	d = nkiek;
		if (nkiek % 2 != 0) median = nd[d / 2];
    else median = (nd[d / 2 - 1] + nd[d / 2]) / 2.0;
	}
	return median * 0.4 + egz * 0.6;
}


template <class T>
void skirstymas(T& S, T& protingi, T& nevykeliai){
	auto start = high_resolution_clock::now();

	for (int i = 0; i < S.size(); i++){
			copy_if(S.begin(), S.end(), protingi.begin(), [](Studentas S) {return S.gr >= 5;});
		copy_if(S.begin(), S.end(), nevykeliai.begin(), [](Studentas S) {return S.gr < 5;});
	}
	auto end= high_resolution_clock::now();
	duration<double> diff= end-start; 
	cout << "duomenu skirstymas uztruko: " << diff.count() << "s\n" << endl;

	S.clear();
}
/*
void skirstymas(vector <Studentas> &S, vector <Studentas> &protingi, vector <Studentas> &nevykeliai, int k){
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
}*/


template <class T>
void spausdinimas(T& S, T& protingi, T& nevykeliai){
//	auto start = high_resolution_clock::now();

	ofstream rf;	
	
	rf.open("nevykeliai.txt");
	rf << left << setw(12) << "Vardas " << setw(15) << "Pavarde " << setw(15) << "Galutinis " <<endl;
	for (int i = 0; i < 45; i++)
	rf << "-";
	rf << endl;
	for(int i = 0; i < nevykeliai.size(); i++){
	rf << left << setw(12) << nevykeliai.back().var << setw(15) << nevykeliai.back().pav << setw(15) << fixed << setprecision(2) << nevykeliai.back().gr << endl;
	}

	rf.close();
	nevykeliai.clear();

	rf.open("protingi.txt");
	rf << left << setw(12) << "Vardas " << setw(15) << "Pavarde " << setw(15) << "Galutinis "  <<endl;
	for (int i = 0; i < 45; i++)
	rf << "-";
	rf << endl;
	for(int i = 0; i < protingi.size(); i++){
	rf << left << setw(12) << protingi.back().var << setw(15) << protingi.back().pav << setw(15) << fixed << setprecision(2) << protingi.back().gr << endl;
	}

/*	auto end= high_resolution_clock::now();
	duration<double> diff= end-start; 
	cout << "duomenu spausdinimas uztruko: " << diff.count() << "s\n" << endl;*/

	rf.close();
	protingi.clear();

}	



//duomenu ivedimas ir spausdinimas
template <class T>
void ivedimas(T& S, T& protingi, T& nevykeliai){
		int k = 0;
	double sum = 0;
	int r;
	
	char ats;
	char pas;   //pasirinkimas
	cout << "Ar norite prideti studenta? (t/n) ";
	cin >> pas;
    Studentas studentas;
	if (pas == 't' || pas == 'T'){
      do{ 
		cout << "Iveskite studento varda ir pavarde ";
		cin >> studentas.var >> studentas.pav;
		cout << endl;
		
		cout << "Ar ivesite namu darbu kieki? (t/n) ";
		cin >> ats;
		
		if (ats == 't' || ats == 'T') {                          //zinomas namu darbu kiekis
			cout << "Iveskite namu darbu kieki ";
		    cin >> studentas.nkiek;
		    cout << endl;
	    	cout << "Ar ivesite namu darbu rezultatus? (t/n) ";
		    cin >> ats;
		    
		    if (ats == 't' || ats == 'T'){                       //zinomi namu darbu rezultatai
		    	cout << "Iveskite namu darbu rezultatus ( > 0) ";
		    	for (int j = 0; j < studentas.nkiek; j++){
		    		int paz;
					do{
						cin >> paz;
						studentas.nd.push_back(paz);
					} while (paz < 1 || paz > 10);
					
					}
				cout << endl;
			}
			if (ats == 'n' || ats == 'N'){
				cout << "Sugeneruoti namu darbu rezultatai ";   //nezinomi namu darbu rezultatai
				for (int j = 0; j < studentas.nkiek; j++){
					int paz = rand() % 10 + 1;
					studentas.nd.push_back(paz);
					cout << studentas.nd[j] << " ";
				} cout << endl;
			}
		}
		
		
		else if (ats == 'n' || ats == 'N'){                          //nezinomas namu darbu kiekis
			cout << "Ar ivesite namu darbu rezultatus? (t/n) ";
			cin >> ats;
			
			if (ats == 't' || ats == 'T'){                      //zinomi namu darbu rezultatai
				char paz; 
				cout << "Iveskite namu darbu rezultatus ";
				do {
				studentas.nkiek = 1;
				for (int j = 0; j < studentas.nkiek; j++){
					cin >> paz;
					studentas.nd.push_back(paz);
				//	cout << S[j].nd;
					studentas.nkiek++;
				}
				} while (paz != '\n');
			}	
			
			if (ats == 'n' || ats == 'N'){
				studentas.nkiek = rand()% 10 + 1;
				cout << "Sugeneruoti pazymiai ";
				for (int j = 0; j < studentas.nkiek; j++){
					int paz  = rand() % 10 + 1;
					studentas.nd.push_back(paz);
					cout << studentas.nd[j] << " ";
				}
			}	
		}
		
		
		cout << "Ar ivesite egzamino rezultata? (t/n) ";       //egzaminas
		cin >> ats;
	
		if (ats == 't' || ats == 'T'){ 
		cout << "Iveskite egzamino rezultata ( > 0) "    ;   
		int paz;              
		do {
		cin >> paz;
		studentas.egz = paz;
		} while (paz <1 || paz > 10);
		}
	
		if (ats == 'n' || ats == 'N'){
		cout << "Sugeneruotas egzamino rezultatas ";
		studentas.egz = rand() % 10 + 1;
		cout << studentas.egz;
		}
		cout << endl;
	studentas.vid = vidurkis (studentas.nd, studentas.nkiek, studentas.egz);
	studentas.med = mediana (studentas.nd, studentas.nkiek, studentas.egz);
	studentas.gr = (studentas.vid+studentas.med) / 2;
    S.push_back(studentas);
	k++;
	cout << "Ar ivesite dar viena studenta? (t/n) ";
	cin >> pas;
	} while (pas == 't' || pas == 'T');
    }

	if (pas == 'n' || pas == 'N') {
	//	rikiavimas(S);
		skirstymas(S, protingi, nevykeliai);
		spausdinimas(S, protingi, nevykeliai);
	}
	
}

//egzistuojansio failo skaitymas ir spausdinimas
template <class T>
void skaitymas(T& S, T& protingi, T& nevykeliai){

	int p = 0;
	int k = 0;
	int pas;

	cout << "Koki studentu kieki nuskaityti?\n" << "1 - 1000 \n" << "2 - 10000 \n" << "3 - 100000 \n" << "4 - 1000000 \n" << "5 - 10000000\n";
	do{
		cin >> pas;
	//	if (pas == 0) k = 10;
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

		if (df.good()){
        while (getline(buffer, line))
            {
				stringstream df(line);
                int paz;
                df >> studentas.var >> studentas.pav;
			//	cout << 1 << " ";
                while (df >> paz) studentas.nd.push_back(paz);   
                studentas.nd.pop_back();
                studentas.nkiek = studentas.nd.size();
                studentas.egz = paz;
                studentas.vid = vidurkis(studentas.nd, studentas.nkiek, studentas.egz);
                studentas.med = mediana(studentas.nd, studentas.nkiek, studentas.egz);
				studentas.gr = (studentas.vid+studentas.med) / 2;
                S.push_back(studentas);

				p++;
            }
		

		try
        {
            if (p == 0)
                throw "Nuskaitytas failas tuscias! ";
        }
        catch(const char *Message)
        {
            cout << Message << endl;
        }

	auto end= high_resolution_clock::now();
	duration<double> diff= end-start; 
	cout << "Failo skaitymas uztruko: " << diff.count() << "s\n" << endl;

	if (p > 0) {
		skirstymas(S, protingi, nevykeliai);
		spausdinimas(S, protingi, nevykeliai);
	}
		}
	df.close();
}


//naujo failo generavimas, skaitymas ir spausdinimas
template <class T>
void generavimas(T& S){
	//auto start= high_resolution_clock::now();
	ofstream rf;
	Studentas studentas;
	int pas;
	int k;
	cout << "Kiek studentu norite sugeneruoti? " << endl;
	cout << "1 - 1000 \n" << "2 - 10000 \n" << "3 - 100000 \n" << "4 - 1000000 \n" << "5 - 10000000\n";

	do{
		cin >> pas;
		//if (pas == 0) k = 10;
		if (pas == 1) k = 1000;
		if (pas == 2) k = 10000;
		if (pas == 3) k = 100000;
		if (pas == 4) k = 1000000;
		if (pas == 5) k = 10000000;

	}while (pas > 5 || pas < 1);

	rf.open("Failas" + to_string(k) + ".txt");

	for (int i = 0; i < k; i++){
		rf << "Vardas" + to_string(i+1) << " Pavarde" + to_string(i+1);
		studentas.nkiek = rand()% 10 + 1;

		vector <int> Pazymiai;
        vector <int>::iterator IT;

		for (int j = 0; j < studentas.nkiek; j++){
					int paz = rand() % 10 + 1;
					Pazymiai.push_back(paz);
				//	rf << studentas.nd.push_back(paz);
		}

	for (IT = Pazymiai.begin(); IT < Pazymiai.end(); IT++ )
	rf << " " << *IT;

	studentas.egz = rand() % 10 + 1;
	rf << " " << studentas.egz << endl;
	S.push_back(studentas);

	}	
	
	
/*	auto end= high_resolution_clock::now();
	duration<double> diff= end-start; 
	cout << k << " elementu failo kurimas uztruko: " << diff.count() << "s\n" << endl;*/
	rf.close();
}

template <class T>
void genskaitymas(T& S, T& protingi, T& nevykeliai){

	generavimas(S);

	auto start= high_resolution_clock::now();
	stringstream buffer;
	int i = S.size();
	ifstream df("Failas" + to_string(i) + ".txt");				//sugeneruoto failo skaitymas
    buffer << df.rdbuf();
    string line;
	int k = 0;
   Studentas studentas;
	if (df.good()){
while (getline(buffer, line))
            {
                stringstream df(line);
                int paz;
                df >> studentas.var >> studentas.pav;
			//	cout << studentas.var << endl;
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
	
	
	auto end= high_resolution_clock::now();
	duration<double> diff= end-start; 
	cout << "Failo skaitymas uztruko: " << diff.count() << "s\n" << endl;

	if (k > 0) {
	//	rikiavimas(S);
		skirstymas(S, protingi, nevykeliai);
		spausdinimas(S, protingi, nevykeliai);
	}}
	df.close();
}

template <class T>
void duomenys(T& S, T& protingi, T& nevykeliai){
	char ats;

	cout << "Duomenis ivesite, skaitysite ar generuosite naujus? (i/s/g)\n";
	cin >> ats;
	if (ats == 'i' || ats == 'I') ivedimas(S, protingi, nevykeliai);
	if (ats == 's' || ats == 'S') skaitymas(S, protingi, nevykeliai);
	if (ats == 'g' || ats == 'G') genskaitymas(S, protingi, nevykeliai);

}

//template <class T>
void galutinis(char kont){

	//char ats; 

	if (kont == 'v' || kont == 'V'){
		vector <Studentas> S;
		vector <Studentas> protingi;
		vector <Studentas> nevykeliai;
		duomenys(S, protingi, nevykeliai);
    }

	//list
	if (kont == 'l' || kont == 'L'){
		list <Studentas> S;
		list <Studentas> protingi;
		list <Studentas> nevykeliai;
		duomenys(S, protingi, nevykeliai);
    }
	
	//deque
	if (kont == 'd' || kont == 'D'){
		deque <Studentas> S;
		deque <Studentas> protingi;
		deque <Studentas> nevykeliai;
		duomenys(S, protingi, nevykeliai);
    }
}
