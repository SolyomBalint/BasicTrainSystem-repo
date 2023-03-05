

#ifndef VONATJEGY_H
#define VONATJEGY_H

#include "Jegy.h"

class Vonatjegy : public Jegy{
	int carriage; //vagon szam, amibe a jegy szol
public:
	//alap, parameters, illetve alatta a masolo konstruktor
	Vonatjegy(Ido departure = Ido(), Ido arrival = Ido(), std::string from = " ", std::string to = " ", double cost = 1000, int seatnumber = 0,
		int vehnumber = 0, std::string name = "", int carriage = 1) : Jegy(departure, arrival, from, to, cost, seatnumber, vehnumber, name),
		carriage(carriage) {}
	~Vonatjegy() {}
	//getterek
	void print(std::ostream& os) const;

	//kezelo fuggvenyek
	void fajlkiir();
	void stringbeolvas(const std::string& str, int& index);
}; 

std::ostream& operator<<(std::ostream& os, const Vonatjegy& rhs);
#endif // !VONATJEGY_H



