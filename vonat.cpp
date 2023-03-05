#include "memtrace.h"
#include "vonat.h"

template<typename Variable>
void genestringbeolvas(Variable& V, int& index, const std::string& source); //Amikor includolom ketszer a Genefg.hpp-t link hibat dob, ezert deklaralom itt megint a fuggvenyt



//parameteres konstruktor, a Vonat jarmu tipust alapertelmezetten beallitja
Vonat::Vonat(Ido departure, Ido arrival, std::string from, std::string to, int tagnumber, int carrigenumber,
	int carrigecapacity, double cost):Jarmu("Vonat", departure, arrival, from, to, tagnumber, carrigecapacity*carrigecapacity, cost), carrigenumber(carrigenumber),
 carrigecapacity(carrigecapacity) {}


//az alaposztaly beolvaso fuggvenyet felhasznlva, meg beolvassa a sajat adattgjait is, kesobb lesz hibas input ellenorzes
void Vonat::terminalbeolvas() {
	int cap = Jarmu::terminalbeolvasrejtett();
	std::cout << "Vagonszam (a ferohellyel oszthatonak kell lennie, hiszen ugyanakkorak a vagonok): \n";
	carrigenumber = intbeolvas();
	if ((cap % carrigenumber) != 0)
		throw "hiba";
	carrigecapacity = cap / carrigenumber; //a felhasznalo nem adhatja meg egy vagon kapacitasat, ezt a program kiszamolja a vagonszam, és a kapacitas alapjan
}

void Vonat::fajlkiir() { //kell meg az foglalat jegyek szama, es az ido operator
	std::fstream database;
	Jarmu::rejtettkiir(database);//ez a fuggveny nyitja meg a fajlt, de annak bezarasat itt kell megoldani
	database << carrigecapacity << ";" << carrigenumber << ";";
	database << "! \n";
	database.close();
}

void Vonat::stringbeolvas(const std::string& rhs) {
	int index = Jarmu::stringbeolvasrejtett(rhs);//visszaadja, hogy eppen hol tart a bementi stringben
	genestringbeolvas(carrigecapacity, index, rhs);
	genestringbeolvas(carrigenumber, index, rhs);
}

Jegy* Vonat::createticket(const int& seatnumber,const std::string& name) {
	int carrigeticket = 1;
	for (int i = 1; i <= carrigenumber; ++i) {
		if (((i - 1) * carrigecapacity < seatnumber) && seatnumber < (i * carrigecapacity)) {
			carrigeticket = i;//kiszamolja hogy  valasztott jegy hanyadik vagonba kerul, a a kisebb sorszamu helyek a kisebb sorzsamu vagonokba kerulnek
		}
	}
	Jegy* uj = Jarmu::vonatjegyfoglal(carrigeticket, seatnumber, name);
	return uj; 
}
//ezek a fuggvenyek oldjak meg a szabvanyos kimentre valo kiirast
void Vonat::print(std::ostream& os) const {
	Jarmu::print(os);
	os << "Vagonszam: " << carrigenumber << '\n';
}

void Vonat::pointerprint(std::ostream& os) const {
	print(os);
}

std::ostream& operator<<(std::ostream & os, const Vonat & rhs) {
	rhs.pointerprint(os);
	return os;
}