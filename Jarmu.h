
#ifndef JARMU_H
#define JARMU_H

#include "Jegy.h"

//jarmuvek altalanos osztalya
class Jarmu {
	std::string from; //honnan indul a jarmu
	std::string to; //hova megy	
	std::string vehtype; //milyen jarmu(vonat/busz/repulo....)
	double cost;	//Jegy ar (egyseges)
	int tagnumber; //a jarmuvet azonosito szam
	int capacity; //maximum hany jegy adhato el
	int taken;	//megvett jegyek szama 
	int* freeseats; //lefoglalat helyek sorszamat tarolja
	Ido departure; //mikor indul
	Ido arrival; //mikor erkezik
	
	//egyenloseg operator, és a másolo kontruktor, mivel absztrakt lesz a Jarmu osztaly, elerhetetlenne kell oket tenni

	Jarmu& operator=(const Jarmu&);
	Jarmu(const Jarmu& rhs);
protected: //kivulrol nem erhetoek el, de az alaposztalyok fuggvenyeit/operatorait konnyebb a segitsegukkel megvalositani
	// hiszen igy nem kell a privat tagokkal kulon foglalkozni (altalalban)
	//dobhat kivetelt!
	int terminalbeolvasrejtett();//szabvanyos bementrol adattagok beolvasasa
	void settype(const std::string& rhs);//beallitja a vehtype-ot
	int stringbeolvasrejtett(const std::string& rhs); //stringbol adott formulam alpjan beolvassa az objektum adatiat, visszatér az indexel, hogy eppen hol tart a stringben
	void rejtettkiir(std::fstream& database) const;//fajlba kiirja az objektum adatait, adott formatum alapjan
	Jegy* vonatjegyfoglal(const int& carrige,const int& seat,const std::string& name) const;//letrehoz egy vonatjegy pointert, es beirja neki a bemeneten kapott informaciokat
public:
	Jarmu() :from(" "), to(" "), vehtype(" "), cost(0), tagnumber(0), capacity(0),taken(0), freeseats(NULL), 
	departure(0,0), arrival(0,0) {}
	// A paraméteres konstruktor mindent inicializáló listával old meg, kivéve a szabad helyek ellenorzesre
	Jarmu(std::string vehtype, Ido departure, Ido arrival, std::string from, std::string to, int tagnumber, int capacity,
		double cost);
	//virtualis destruktor, a dinamikusan foglalt tömböket szabaditja fel, illetve szukseges, hiszen absztrakt osztalyrol van szo
	virtual ~Jarmu() {
		delete[] freeseats;
	}
	void print(std::ostream& os) const;//szabvanoys kimenetre irja ki az objektum adatait, cout overloadjahoz kell
	//freeseat kezelese
	bool checkseats() const { return freeseats == NULL; }//ellenorzi, hogy szabad-e az osszes hely
	void allocatefreeseats(int size);//lefoglalja a freesetas tombot
	void terminalfreeseats() const;//terminalra kiirja a foglalat/szabad helyek allapotat
	void reallocatenadaddfreeseats(int newmember);//dinamikusan ad egy uj tagot a freeseatshez
	bool isfree(int seat) const;//ellenerozi, hogy a bemeneten kapott szam szerepel-e a freeseast tombben
	//operatorok
	int operator[](int i) const; //freeseats tombon mukodik
	//tisztan virtualis fuggvenyek
	virtual void terminalbeolvas() = 0;//szabvanyos bementrol olvas be
	virtual void fajlkiir() = 0;
	virtual void stringbeolvas(const std::string& rhs) = 0;
	virtual Jegy* createticket(const int& seatnumber,const std::string& name) = 0;
	virtual void pointerprint(std::ostream& os) const = 0;//<< operator tulterheleseben van szerepe
};

std::ostream& operator<<(std::ostream& os, Jarmu* rhs);//csak pointerre mukodik

#endif // !JARMU_H

