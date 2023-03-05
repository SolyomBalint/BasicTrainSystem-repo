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
			int vonatszam = test.readfromtxt(); //beolvas egy txt fajlbol, és kiirja  terminalra a szerzett jarmu adatokat
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
	Vonat test; //vonat létrehozása
	Ido kieg;
	Vonat test2(kieg, kieg, "teszt", "teszt", 10, 1, 50, 1000);
	test.terminalbeolvas();//vonat adatainak beolvasása
	test.isfree(2);
	std::cout << test;
	terminalborder();//elválasztás
	GeneLanc<JarmuLanc> test1;//láncolt lista létrehozása
	int szam = test1.readfromtxt();//adatok beolvasása és kiírása
	JarmuLanc* current = test1.findmember(szam);//az elõbb felvett vonatot választja ki
	current->freeseats();
	int seat = intbeolvas(); //itt végig feltételezzük a helyes bemenetet
	current->reallocfreeseats(seat);//hozzáadjuk a foglalt székhez
	Jegy* vett = current->createticketfromchain(seat, "teszt"); //jegyet generálunk az inputból
	std::cout << vett;
	vett->fajlkiir();
	test1.overwrite();//kiírjuk a változásokat
	delete vett;
	//kiírjuk a vásárlókat listában
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
	MenuState currents;//osszes menupont kipróbálása
	setcurrentstate(currents);
	setcurrentstate(currents);
	setcurrentstate(currents);
	setcurrentstate(currents);
	//hibás bemenetek
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