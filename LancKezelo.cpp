
#include <fstream>
#include "memtrace.h"
#include "LancKezelo.h"



int LancKezelo::readfromtxt() {
	std::ifstream file;
	file.open("vonatadatbazis.txt", std::ios::in);
	std::string buffer;
	int i = 1;
	while (std::getline(file, buffer)) {//EOF-is olvas
		addtolistandwriteout(buffer, i);//atajda a bufferbe beirt jarmu adaokat, illetve, hogy hanyadik sort olvasta
		buffer.clear(), ++i;
	}
	file.close();
	return i-1;
}

void LancKezelo::addtolistandwriteout(std::string rhs, int i) {
	JarmuLanc* uj = new JarmuLanc;
	uj->allocateveh(rhs);//ujtag lefoglalsa es inicializalsa
	std::cout << "(" << i << ") ";//sorszam kirasa
	uj->terminalkiir();//adatok kiirasa terminalra
	if (first == NULL)//uj tag lanchoz adasa
		first = uj;
	else {
		JarmuLanc* iter = first;
		while (!(iter->isNULL())) {
			iter = iter->getnext();
		}
		iter->setnext(uj);
	}
}

void LancKezelo::eraselist() {
	JarmuLanc* iter = first;
	while (iter != NULL) {
		JarmuLanc* kov = iter->getnext();
		delete iter;
		iter = kov;
	}
}

JarmuLanc* LancKezelo::findmember(int i) const {
	JarmuLanc* iter = first; //hibe ellenorzés kell majd !!
	for (int j = 1; j != i; ++j)
		iter = iter->getnext();
	return iter;
}

void LancKezelo::overwrite() {
	std::fstream file;
	file.open("vonatadatbazis.txt", std::ios::out);
	file.close();//fajl kitisztitasa (kicsit favagos)
	JarmuLanc* iter = first;
	iter->fajlkiir();//minden listaban tarolt tag fajlba kiirasa
	while (!(iter->isNULL())) {
		iter = iter->getnext();
		iter->fajlkiir();
	}
}