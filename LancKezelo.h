
#include <iostream>
#include "JarmuLanc.h"


#ifndef LANCKEZELO_H
#define LANCKEZELO_H


//lancolt lista kezelese
class LancKezelo {
	JarmuLanc* first;
public:
	//konstruktorok
	LancKezelo() :first(NULL) {} //NULL-al inicialiualo deafult konstruktor
	LancKezelo(JarmuLanc *in) :first(in) {}
	void eraselist(); //listat torli
	virtual ~LancKezelo() { eraselist(); }
	void addtolistandwriteout(std::string rhs, int i); //�j elemet vesz fel a lanc vegere es kiirja annak adatait a szabvanyos kimenetre
	int readfromtxt();//beolvas �s az addtolistandwriteout seg�tsegevel l�trehoz �s kiir a terminalra, egy fajlban tarolt vonatok adatait
	JarmuLanc* findmember(int i) const; //megkeresi a lanc i edik tagjat �s visszadja a memoric�m�t
	void overwrite(); //a lancban tarolt adatokkal felulirja az adatbazis txt-t
};




#endif // !LANCKEZELO_H

