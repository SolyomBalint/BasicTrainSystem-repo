
#ifndef JEGY_H
#define JEGY_H

#include "accesories.h"

class Jegy {
	std::string from; //indulasi hely
	std::string to; //erkezesi hely
	double cost; //jegy ar
	int seatnumber; //melyik ulesre szol a jegy
	int vehnumber; //a Jarmu azonosito szama
	Ido departure; //indulasi ido
	Ido	arrival; //erkezesi ido
	std::string name; //a jegyet megvasarlo szemely keresztneve
protected:
	void rejtettstringbeolvas(const std::string& str, int& idx);//stringbol valo beolvasas
	void rejtettkiir(std::fstream& database) const;//fajlba kiirasban segit
public:
	//egyben az alap és a paraméteres konstruktor
	Jegy(Ido departure = Ido(), Ido arrival = Ido(), std::string from = " ", std::string to = " ", double cost = 1000, int seatnumber = 0,
		int vehnumber = 0, std::string name = "") : from(from), to(to), cost(cost),
		seatnumber(seatnumber), vehnumber(vehnumber) , departure(departure), arrival(arrival), name(name) {}

	//virtualis destruktor szükseges hoszen vannak virtualis tagfuggvenyek is, illetve absztrakt az osztaly
	virtual ~Jegy() {}
	

	void print(std::ostream& os) const;
	//fugvenyek
	virtual void fajlkiir() = 0;
	virtual void stringbeolvas(const std::string& str, int& index) = 0;
};

#endif // !JEGY_H
