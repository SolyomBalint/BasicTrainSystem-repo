
#ifndef VONAT_H
#define VONAT_H

#include "Jarmu.h"

//a jarmu vonat alosztalya
class Vonat : public Jarmu {
	int carrigenumber; //hany kocsibol all a szerelveny
	int carrigecapacity; //egy kocsi ferohelye (kocsinkent nem indul ujra az ulesek szamozasa
public:
	//parameter nelkuli konstruktor, a Vonat jarmu tipust alltija be minden Vonat objektumnak
	Vonat():Jarmu(), carrigenumber(0), carrigecapacity(0) {
		Jarmu::settype("Vonat");
	}
	//konstruktor, megfelelo kocsi meret ellenorzese a beolvaso fuggveny kotelessege
	Vonat(Ido departure, Ido arrival, std::string from, std::string to, int tagnumber, int carrigenumber, 
		int carrigecapacity, double cost);
	~Vonat() {}

	void print(std::ostream& os) const;

	//ososztaly virtual fugvenyei deklaralva (cpp-ben definialva)
	void terminalbeolvas();
	void fajlkiir();
	void stringbeolvas(const std::string& rhs);
	Jegy* createticket(const int& seatnumber,const std::string& name);
	void pointerprint(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const Vonat& rhs);

#endif // !VONAT_H

