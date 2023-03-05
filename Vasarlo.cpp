#include <fstream>
#include "Vasarlo.h"
#include "memtrace.h"

void Vasarlo::fajlkiir() const {
	std::fstream file;
	file.open("vasarloadatbazis.txt", std::ios::app);
	if (file.is_open())
		file << name << ";";
	file.close();
	bougthticket->fajlkiir();
}

void Vasarlo::stringbeolvas(std::string str) {
	int idx = 0;
	name.clear();
	while (str[idx] != ';')
		name += str[idx++];
	++idx;
	bougthticket = new Vonatjegy;
	bougthticket->stringbeolvas(str, idx);
}

void Vasarlo::terminalkiir() const{
	std::cout << "Vasarlo keresztneve: " << name << " " << ":Jegy informaciok: \n";
	bougthticket->terminalkiir();
}