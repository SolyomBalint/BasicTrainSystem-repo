
#include <iostream>
#include <string>
#include "Jegy.h"
#include "vonatjegy.h"

#ifndef VASARLO_H
#define VASARLO_H

class Vasarlo {
	std::string name;//vasarlo keresztneve
	Jegy* bougthticket;//megvett jegye
public:
	Vasarlo() :name(" "), bougthticket(NULL) {}
	Vasarlo(std::string name, Jegy* bought):name(name), bougthticket(bought) {}
	~Vasarlo() {
		if (bougthticket != NULL)
			delete bougthticket;
	}
	void fajlkiir() const;
	void stringbeolvas(std::string str);
	void terminalkiir() const;
};

#endif // !VASARLO_H
