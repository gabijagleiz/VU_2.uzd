#include "funkcijos.h"

int main(){
	srand (time(NULL));

	char kont;
    char ats;

	cout << "Koki konteineri naudosite?\n" << "v - vector\n" << "l - list\n" << "d - deque\n";
	cin >> kont; 

	galutinis(kont);

/*	if (kont == 'v' || kont == 'V'){
		vector <Studentas> S;
		vector <Studentas> protingi;
		vector <Studentas> nevykeliai;
		duomenis(S, protingi, nevykeliai);
    }

	//list
	if (kont == 'l' || kont == 'L'){
		list <Studentas> S;
		list <Studentas> protingi;
		list <Studentas> nevykeliai;
		duomenis(S, protingi, nevykeliai);
    }
	
	//deque
	if (kont == 'd' || kont == 'D'){
		deque <Studentas> S;
		deque <Studentas> protingi;
		deque <Studentas> nevykeliai;
		duomenis(S, protingi, nevykeliai);
}*/

}
