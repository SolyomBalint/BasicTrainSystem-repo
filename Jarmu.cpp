#include "memtrace.h"
#include "Jarmu.h"
#include "vonatjegy.h"
#include "Genefg.hpp"
//parameteres konstruktor
Jarmu::Jarmu(std::string vehtype = "", Ido departure = Ido(), Ido arrival = Ido(), std::string from = "", std::string to = "", int tagnumber = 0, int capacity = 0,
	double cost = 0.0) :from(from), to(to), vehtype(vehtype), cost(cost), tagnumber(tagnumber),
	capacity(capacity),taken(0), freeseats(NULL), departure(departure), arrival(arrival) {}

//terminalbol beolvaso fg. jelenleg technikai gondok miatt nem tartalmaz hibas input ellenorzest
int Jarmu::terminalbeolvasrejtett() {
	std::cout << "adja meg: \n" << "indulasi hely, majd ido: \n";
	std::cin >> from;
	if (std::cin.eof()) {//EOF ra is dob hibát
		std::cin.clear();
		throw "hiba";
	}
	if (isnumber(from))//ha kerül szam a varos nevbe hibat dob, ugyanez tortenek a to nal is
		throw "hiba";
	departure.terminalbe();
	std::cout << "erkezesi hely, majd ido: \n";
	std::cin >> to;
	if (std::cin.eof()) {
		std::cin.clear();
		throw "hiba";
	}
	if (isnumber(to))
		throw "hiba";
	arrival.terminalbe();
	std::cout << "jegyar: \n";
	cost = intbeolvas();
	if (cost < 0)//nem lehet negativ ara
		throw "hiba";
	std::cout << "max ferohely(paros szamot adjon, hiszen az ulesek 2-esevel vannak): \n";
	capacity = intbeolvas();//fentebb a cout leirja
	if ((capacity % 2) != 0)
		throw "hiba";
	std::cout << "Jarmu azonosito szam: \n";
	tagnumber = intbeolvas();
	return capacity;
}
//protected fuggveny, az alostalyoknak engedelyezi, hogy utolag valtoztassank a Jarmu tipus neven (parameter nelkuli konstruktor hasznalatanal indokolt)
void Jarmu::settype(const std::string& rhs) {
	vehtype = rhs;
}
//tulindexeles eseten negativ szammal ter vissza
int Jarmu::operator[](int i) const {
	if (i < taken && i >= 0)
		return freeseats[i];
	return -1;
}

void Jarmu::allocatefreeseats(int size) {//freeseats-et lefoglalja
	freeseats = new int[size];
}


int Jarmu::stringbeolvasrejtett(const std::string& rhs) {
	int index = 0;
	to.clear();
	from.clear();
	while (rhs[index] != ';') //Jarmutipus atugrasa (az alapertelmezett az alosztalyok eseteben)
		++index;
	++index; //atugorja ez elvasztot, hiszen azt az objektumnak nem kell tarolnia (kesobb is)
	genestringbeolvas(from, index, rhs);
	genestringbeolvas(to, index, rhs);
	genestringbeolvas(cost, index, rhs);
	genestringbeolvas(tagnumber, index, rhs);
	genestringbeolvas(capacity, index, rhs);
	genestringbeolvas(departure.ora, index, rhs);
	genestringbeolvas(departure.perc, index, rhs);
	genestringbeolvas(arrival.ora, index, rhs);
	genestringbeolvas(arrival.perc, index, rhs);
	genestringbeolvas(taken, index, rhs);
	if (taken > 0) {
		if (freeseats != NULL)//felulirja a korabbit
			delete[] freeseats;
		allocatefreeseats(taken);
		for (int i = 0; i < taken; ++i) {
			genestringbeolvas(freeseats[i], index, rhs);
		}

	}
	return index;
}

void Jarmu::terminalfreeseats() const {//ellenorzi es kiirja, hogy mely helyek foglaltak a freeseast alapjan
	if (taken == 0)
		std::cout << "minden hely szabad! \n" << "Valasszon 1-tol " << capacity << "-ig egy szekszamot (helyjegy)\n";
	else {
		std::cout << "\nA kovetkezo helyek foglaltak: ";
		for (int i = 0; i < taken; ++i)
			std::cout << freeseats[i] << ", ";
		std::cout << "\nA felsoroltak kivetelevel " << "valasszon 1-tol " << capacity << "-ig egy szekszamot (helyjegy)\n";
	}
}
//hozza ad egy uj elemet a freeseatshez
void Jarmu::reallocatenadaddfreeseats(int newmember) {
	int newsize = taken + 1;
	int* newarray = new int[newsize];
	int i = 0;
	for (; i < taken; ++i) {
		newarray[i] = freeseats[i];
	}
	newarray[taken] = newmember;
	if (freeseats != NULL)
		delete[] freeseats;
	freeseats = newarray;
	taken += 1;
}

bool Jarmu::isfree(int seat) const {
	if (seat <= 0 || seat > capacity)
		return false;//ellenorzi, hogy helyes e egyeltalan az input
	for (int i = 0; i < taken; ++i) {
		if (freeseats[i] == seat)
			return false;
	}
	return true;
}

void Jarmu::print(std::ostream& os) const {
	os << "Jarmutipus: " << vehtype << " " << "azonosito: " << tagnumber << '\n'
		<< "indul: " << departure << ", " << from << " " << "vegallomas: " << arrival << ", "
		<< to << '\n' << "Jegyar: " << cost << "Ft, ";
}

std::ostream& operator<<(std::ostream& os, Jarmu* rhs) {
	rhs->pointerprint(os);
	return os;
}

void Jarmu::rejtettkiir(std::fstream& database) const {
	database.open("vonatadatbazis.txt", std::ios::app);
	if (database.is_open()) {// adott formatum alapjan irja ki fajlba
		database << vehtype << ";" << from << ";" << to << ";" << cost
			<< ";" << tagnumber << ";" << capacity << ";" << departure.ora << ";"
			<< departure.perc << ";" << arrival.ora << ";" << arrival.perc
			<< ";" << taken << ";";
		if (!(Jarmu::checkseats())) {
			for (int i = 0; i < taken; ++i) {
				database << Jarmu::operator[](i) << ";";
			}
		}
	}
}

Jegy* Jarmu::vonatjegyfoglal(const int& carrige,const int& seat,const std::string& name) const{
	return new Vonatjegy(departure, arrival, from, to, cost, seat,tagnumber,name,carrige);
}