//foprogram helye
#include "memtrace.h"
#include "gtest_lite.h"
#include "Jarmu.h"
#include "Jegy.h"
#include "accesories.h"
#include "vonat.h"
#include "vonatjegy.h"
#include "JarmuLanc.h"
#include "GeneLanc.hpp"



int main(void) {
	/*MenuState current = mainmenu; // switches menu kezelese
	while (current != quit) {
		std::cout << "(1)Uj vonat\n(2)Jegyvetel\n(3)Vasarlok\n(4) kilepes\n";
		setcurrentstate(current);//ez a fuggveny refenciakent kapja meg a current valtozot es felhasznoloi input alapjan donti el, hogy melyik menupontba kell kerulni
		switch (current)
		{
		case mainmenu:
			break;
		case newvehicle: {
			terminalborder();
			Vonat v1; //uj vonat letrehozasa
			try {
				v1.terminalbeolvas(); //jarmu adatainak beolvasasa
				v1.fajlkiir();//uj jarmu adatok kiirasa adatbazisunkba
				terminalborder();
			}
			catch (...) {
				std::cout << "\nHibas bemenet\n";
				current = mainmenu;
			}
			break;
		}
		case buyticket: {
			terminalborder();
			GeneLanc<JarmuLanc> test; //jarmuvek lnacolt listajat kezelo osztaly
			int vonatszam = test.readfromtxt(); //beolvas egy txt fajlbol, �s kiirja  terminalra a szerzett jarmu adatokat
			std::cout << "Valasszon egy jaratot(sorszam alapjan): \n";
			try {
				int jarat = intbeolvas();//kivalsztja a felhasznalo, hogy a felsorolt jaratok kozul meglyikete szeretne
				if (jarat <= 0 || jarat > vonatszam) {
					std::cout << "ilyen jarat nem letezik\n";
					break;
				}
				JarmuLanc* current = test.findmember(jarat);//megkeressuk a valsztott jaratot es kiemeljuk modositasra
				current->freeseats(); //kiirja hogy melyik helyek szabadok a valasztott jaraton
				int chosenseat; //a felhasznalo altal kivalsztott szek
				chosenseat = intbeolvas();
				if (!(current->isfree(chosenseat))) {
					std::cout << "Ez a hely foglalt, vagy nem letezik\n";
					break;
				}
				current->reallocfreeseats(chosenseat);//az adott jaraton ujrameretezi a freeseat tombot es hozza adja az uj foglalast
				std::string buyer;//vasarlo keresztnevenek beszerzese
				std::cout << "adja meg a keresztnevet!\n";
				std::cin >> buyer;
				Jegy* bought = current->createticketfromchain(chosenseat, buyer); // letrehoz egy jegyet az adott uleshelyre
				bought->fajlkiir();
				test.overwrite(); //kiirja a vonatadatbazisba a valtoztatasokat
				terminalborder();
				delete bought;
			}
			catch (...) {
				std::cout << "\nHibas bemenet\n";
				current = mainmenu;
			}
			break;
		}
		case soldticketlist: {
			std::ifstream file;
			file.open("vasarloadatbazis.txt", std::ios::in);
			std::string buffer;
			while (std::getline(file, buffer)) {
				Vonatjegy bought;//mindig ujat, met ezeket az adatokat nem kell utolag kezelni, csak egyzsr kiirni
				int index = 0;
				bought.stringbeolvas(buffer, index);
				std::cout << bought;
				buffer.clear();
			}
			file.close();
			break;
		}
		default:
			break;
		}
	}*/
	//tesztprogram/skeleton:
	Vonat test; //vonat l�trehoz�sa
	Ido kieg;
	Vonat test2(kieg, kieg, "teszt", "teszt", 10, 1, 50, 1000);
	test.terminalbeolvas();//vonat adatainak beolvas�sa
	test.isfree(2);
	std::cout << test;
	terminalborder();//elv�laszt�s
	GeneLanc<JarmuLanc> test1;//l�ncolt lista l�trehoz�sa
	int szam = test1.readfromtxt();//adatok beolvas�sa �s ki�r�sa
	JarmuLanc* current = test1.findmember(szam);//az el�bb felvett vonatot v�lasztja ki
	current->freeseats();
	int seat = intbeolvas(); //itt v�gig felt�telezz�k a helyes bemenetet
	current->reallocfreeseats(seat);//hozz�adjuk a foglalt sz�khez
	Jegy* vett = current->createticketfromchain(seat, "teszt"); //jegyet gener�lunk az inputb�l
	std::cout << vett;
	vett->fajlkiir();
	test1.overwrite();//ki�rjuk a v�ltoz�sokat
	delete vett;
	//ki�rjuk a v�s�rl�kat list�ban
	std::ifstream file;
	file.open("vasarloadatbazis.txt", std::ios::in);
	std::string buffer;
	while (std::getline(file, buffer)) {
		Vonatjegy bought;//mindig ujat, met ezeket az adatokat nem kell utolag kezelni, csak egyzsr kiirni
		int index = 0;
		bought.stringbeolvas(buffer, index);
		std::cout << bought;
		buffer.clear();
	}
	file.close();
	MenuState currents;//osszes menupont kipr�b�l�sa
	setcurrentstate(currents);
	setcurrentstate(currents);
	setcurrentstate(currents);
	setcurrentstate(currents);
	//hib�s bemenetek
	setcurrentstate(currents);
	for (int i = 0; i < 10; ++i) {
		try {
			test.terminalbeolvas();
		}
		catch (...) {
			std::cout << "hibas bemenet\n";
		}
	}
	Vonat teszt2;
	teszt2.reallocatenadaddfreeseats(4);
	teszt2.terminalfreeseats();
	return 0;
}