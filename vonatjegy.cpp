#include "memtrace.h"
#include "vonatjegy.h"

template<typename Variable>
void genestringbeolvas(Variable& V, int& index, const std::string& source);//igy elkerulheto a linker hiba


void Vonatjegy::fajlkiir()	{
	std::fstream database;
	Jegy::rejtettkiir(database);//itt ez a fuggveny nyitja meg a fajlt, aminek bezarasa a hivo feladata
	database << carriage << ";\n";
	database.close();
}

void Vonatjegy::stringbeolvas(const std::string& str, int& index) {
	Jegy::rejtettstringbeolvas(str, index);//az indexet attudja allitani hiszen refeenciakent van megoldva
	genestringbeolvas(carriage, index, str);
}
//kiirashoz
void Vonatjegy::print(std::ostream& os) const {
	Jegy::print(os);
	os << "Vagon: " << carriage << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Vonatjegy& rhs) {
	rhs.print(os);
	return os;
}