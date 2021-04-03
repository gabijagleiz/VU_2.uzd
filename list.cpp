#include "list.h"
#include "funkcijos.h"

void sort (list <Studentas> S, int k){

	for (int i = 0; i < k; i++)
		for (int j = 0; j < S[i].nkiek - 1; j++){
			for (int x = j + 1; x < S[i].nkiek; x++){
				if (S[i].nd[j] < S[i].nd[x]) swap (S[i].nd[j], S[i].nd[x]);
		}
}
}


bool CompareLastNames(Studentas& a, Studentas& b)
{
    return a.pav < b.pav;
}

void rikiavimas(list <Studentas>& S)
{
    sort(S.begin(), S.end(), CompareLastNames);
}


//vidurkis
double vidurkis(list <int> nd, int nkiek, int egz){
    double vv;
    int sum = 0;
   	  for (int j = 0; j < nkiek; j++){
   	  	sum += nd[j];
	 }
	vv = (sum / nkiek)* 0.4 + egz * 0.6;
    return vv;
}



//mediana
double mediana (list <int> nd, int nkiek, int egz){
	double median;
	int d = 0;
    	for (int j = 0; j < nkiek; j++){
    	d = nkiek;
		if (nkiek % 2 != 0) median = nd[d / 2];
    else median = (nd[d / 2 - 1] + nd[d / 2]) / 2.0;
	}
	return median * 0.4 + egz * 0.6;
}

void skirstymas(list <Studentas> &S, list <Studentas> &protingi, list <Studentas> &nevykeliai, int k){
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


void spausdinimas(list <Studentas> &S, list <Studentas> &protingi, list <Studentas> &nevykeliai){
	auto start = high_resolution_clock::now();

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

	auto end= high_resolution_clock::now();
	duration<double> diff= end-start; 
	cout << "duomenu spausdinimas uztruko: " << diff.count() << "s\n" << endl;

	protingi.clear();
	rf.close();

}	



//duomenu ivedimas ir spausdinimas
void Vivedimas(list <Studentas> &S, list <Studentas> &protingi, list <Studentas> &nevykeliai){
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
		rikiavimas(S);
		skirstymas(S, protingi, nevykeliai, k);
		spausdinimas(S, protingi, nevykeliai);
	}
	
}

//egzistuojansio failo skaitymas ir spausdinimas
void Vskaitymas(list <Studentas> &S, list <Studentas> &protingi, list <Studentas> &nevykeliai){

		int k[5] = {1000, 10000, 100000, 1000000, 10000000};

	for (int x = 0; x < 5; x++){
	auto start= high_resolution_clock::now();
            stringstream buffer;
            ifstream df("Failas" + to_string(k[x]) + ".txt");
            buffer << df.rdbuf();
            string line;
			int m = 0;
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

				m++;
            }

		try
        {
            if (m == 0)
                throw "Nuskaitytas failas tuščias! ";
        }
        catch(const char *Message)
        {
            cout << Message << endl;
        }

	auto end= high_resolution_clock::now();
	duration<double> diff= end-start; 
	cout << "Failo skaitymas uztruko: " << diff.count() << "s\n" << endl;

	if (m > 0) {
		rikiavimas(S);
		skirstymas(S, protingi, nevykeliai, k);
		spausdinimas(S, protingi, nevykeliai);
	}

	df.close();
	
	}
}


//naujo failo generavimas, skaitymas ir spausdinimas
void generavimas(list <Studentas> &S){
	auto start= high_resolution_clock::now();
	ofstream rf;
	Studentas studentas;
	int pas = 0;
	int k[5] = {1000, 10000, 100000, 1000000, 10000000};

	for (int x = 0; x < 5; x++){

	rf.open("Failas" + to_string(k[x]) + ".txt");

	for (int i = 0; i < k; i++){
		rf << "Vardas" + to_string(i+1) << " Pavarde" + to_string(i+1);
		studentas.nkiek = rand()% 10 + 1;

		list <int> Pazymiai;
        list <int>::iterator IT;

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
	
	
	auto end= high_resolution_clock::now();
	duration<double> diff= end-start; 
	cout << k << " elementu failo kurimas uztruko: " << diff.count() << "s\n" << endl;
	rf.close();
	}
}

void Vgenskaitymas(list <Studentas> &S, list <Studentas> &protingi, list <Studentas> &nevykeliai){

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
		rikiavimas(S);
		skirstymas(S, protingi, nevykeliai, k);
		spausdinimas(S, protingi, nevykeliai);
	}}
	df.close();
}