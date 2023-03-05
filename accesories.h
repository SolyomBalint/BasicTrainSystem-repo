
#ifndef ACCESORIES_H
#define ACCESORIES_H

//Az egyszerúség kedvéért létrehozott mini osztály, feladata az órában és percben megadott idõpontok kezelése
//késõbb akár dátumokkal is kilehet egészíteni
class Ido {
	int ora;
	int perc;
public:
	Ido(int ora = 0, int perc = 0):ora(ora), perc(perc) {} //deafult és paraméteres konstruktor
	Ido(const Ido& rhs) {
		ora = rhs.ora;
		perc = rhs.perc;
	} //másoló konstruktor
	void terminalbe();//szabvanyos bementrol olvas be
	//a friend kapcsolatok segitenek a getter/setter fuggvenyek elkeruleseben
	friend class Jarmu;
	friend class Jegy;
	friend std::ostream& operator<<(std::ostream& os, const Ido& rhs);
};

std::ostream& operator<<(std::ostream& os, const Ido& rhs); //kiiro operator tulterhelese
//a menu kezeleset/ertelmezeset megegyszerusiti, itt sorolja fel az osszes lehetseges allapotat a menunek
enum MenuState {
	mainmenu = 0,
	newvehicle = 1,
	buyticket = 2,
	soldticketlist = 3,
	quit = 4,
};

//ellenorzi, hogy egy stringben van-e szam, aminek nem kéne ott lennie
bool isnumber(const std::string& rhs);
//szimplan annyi a celja, hogy a terminalon belul a kulonbozo funkciok hasznalatat elhatarolja vizualisan is
inline void terminalborder() {
	std::cout << "\n /////////////////////////////////////// \n";
}

void setcurrentstate(MenuState& state);//Menupontok kozotti valtast valositja meg felhasznaloi input alapjan

int intbeolvas();//sok helyen a sima std::cin-t helyettesiti, ellenorzi az EOF-ot, illetvem hogy helyes-e a bemenet, ha nem hibat dob

#endif // !ACCESORIES_H


