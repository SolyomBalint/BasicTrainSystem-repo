
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
	void addtolistandwriteout(std::string rhs, int i); //új elemet vesz fel a lanc vegere es kiirja annak adatait a szabvanyos kimenetre
	int readfromtxt();//beolvas és az addtolistandwriteout segítsegevel létrehoz és kiir a terminalra, egy fajlban tarolt vonatok adatait
	JarmuLanc* findmember(int i) const; //megkeresi a lanc i edik tagjat és visszadja a memoricímét
	void overwrite(); //a lancban tarolt adatokkal felulirja az adatbazis txt-t
};




#endif // !LANCKEZELO_H

