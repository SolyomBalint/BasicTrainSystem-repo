
#include <iostream>
#include "memtrace.h"
#include "accesories.h"


//kiiro operator tulterhelese
std::ostream& operator<<(std::ostream& os, const Ido& rhs) {
	os << rhs.ora << ":";//a H:PP formatumban valo kiiras
	if (rhs.perc < 10) //ha a perc kisebb 10-nel szukseges plust egy nullat kiirni, hogy a forumula megmaradjon
		os << 0;
	os << rhs.perc;
	return os;
}
//ellenorzi, hogy kerult-e szam a stringe (pl, hogy telepules nevbe ne kerulhessen szam: Buda4pest)
bool isnumber(const std::string& rhs) {
	for (const char& c : rhs) {
		if (std::isdigit(c))
			return true;
	}
	return false;
}
//ido beolvasasa a termnialon keresztul
void Ido::terminalbe() {
	int x;
	std::cout << "Ora: \n";
	x = intbeolvas();
	if (x < 0 || x > 24)
		throw "kacsa";
	ora = x;
	std::cout << "Perc: \n";
	x = intbeolvas();
	if (x < 0 || x >= 60)
		throw "kacsa";
	perc = x;
}
//menu kezelese
void setcurrentstate(MenuState& current) {
	std::string be;
	int x;
	std::cin >> be;
	if (std::cin.eof()) {
		std::cout << "EOF\n";
		std::cin.clear();
		std::cout.flush();
		current = mainmenu;
		return;
	}
		
	if (!isnumber(be)) {
		std::cout << "\nilyen menupont nincs\n";
		terminalborder();
		current = mainmenu;
		return;
	}
	x = std::stol(be);
	if (x == 1)
		current = newvehicle;
	else if (x == 4)
		current = quit;
	else if (x == 2)
		current = buyticket;
	else if (x == 3)
		current = soldticketlist;
	else {
		std::cout << "\nilyen menupont nincs\n";
		terminalborder();
		current = mainmenu;
	}
	return;
}
//sima std:.cin helyett
int intbeolvas() {
	std::string buffer;
	std::cin >> buffer;
	if (std::cin.eof()) {
		std::cin.clear();
		throw "hiba";
	}
	if (!isnumber(buffer))//ha egyeltalan nincs szam az inputban
		throw "hiba";
	return std::stol(buffer);
}