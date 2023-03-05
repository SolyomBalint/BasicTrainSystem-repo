
#ifndef JARMULANC_H
#define JARMULANC_H
#include "Jarmu.h"



class JarmuLanc {
	Jarmu* vehicle;
	JarmuLanc* next;
public:
	JarmuLanc():vehicle(NULL), next(NULL) {}
	void erase();
	virtual ~JarmuLanc() { erase(); }

	bool isfree(int seat) const { return vehicle->isfree(seat); }//ellenorzi, hogy szabad-e az adott hely
	void allocateveh(const std::string& str);//lefoglal a *vehicle-re egy Vonat ot
	void freeseats() const { vehicle->terminalfreeseats(); }//kiirja a terminalra, hogy a vehicle adattagban melyek a foglalat helyek, es melyek szabadok meg
	Jegy* createticketfromchain(const int& seat,const std::string& name) { return vehicle->createticket(seat, name); }//letrehoz egy Jegy objektumot (annak alosztalyat, hisezn a jegy absztrakt), a vehicle adattag es a megadott hely alapjan
	void fajlkiir() const { vehicle->fajlkiir(); }//kiirja a vehicle adatait a terminalra
	void reallocfreeseats(int newmember) { vehicle->reallocatenadaddfreeseats(newmember); }//biztonsagosan megnyujtja a freeseats tombot es hozza adja a megadott uj elemet
	template<typename T> friend class GeneLanc;//emiatt mukodik a GeneLanc ezen az osztalyon is
};



#endif // !JARMULANC_H

