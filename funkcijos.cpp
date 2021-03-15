#include "funkcijos.h"

void sort (vector <Studentas> S, int k){

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

void rikiavimas(vector <Studentas>& S)
{
    sort(S.begin(), S.end(), CompareLastNames);
}

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

void spausdinimas(vector <Studentas> S, int k){

	rikiavimas(S);
	cout << left << setw(12) << "Vardas " << setw(15) << "Pavarde " << setw(15) << "Galutinis (vid.) " << setw(25) << "Galutinis (med.)" <<endl;
	for (int i = 0; i < 45; i++)
		cout << "-";
	cout << endl;
	for (int i = 0; i < k; i++){
		cout << left << setw(12) << S[i].var << setw(15) << S[i].pav << setw(15) << fixed << setprecision(2) << S[i].vid << setw(25) << fixed << setprecision(2) << S[i].med << endl;
	}

}	

void ivedimas(vector <Studentas> S){
		int k = 0;
//	double sum = 0;
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
    S.push_back(studentas);
	k++;
	cout << "Ar ivesite dar viena studenta? (t/n) ";
	cin >> pas;
	} while (pas == 't' || pas == 'T');
    }

	if (pas == 'n' || pas == 'N') spausdinimas(S, k);
	
}


void skaitymas(vector <Studentas> S){

            stringstream buffer;
            ifstream df(DFV);
            buffer << df.rdbuf();
            string line;
			int k = 0;
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

		if (k > 0) spausdinimas(S, k);

			df.close();
}
