#include "memtrace.h"
#include "Jegy.h"
#include "accesories.h"

template<typename Variable>
void genestringbeolvas(Variable& V, int& index, const std::string& source);

void Jegy::rejtettstringbeolvas(const std::string& str, int& idx) {
	from.clear();//mivel a fuggvenyek csak hozzafuznek, indokolt a string kiuritese, plusz ha lenne bennuk folosleges space, az is eltunik
	to.clear();
	name.clear();
	genestringbeolvas(name, idx, str);
	genestringbeolvas(from, idx, str);
	genestringbeolvas(to, idx, str);
	genestringbeolvas(cost, idx, str);
	genestringbeolvas(vehnumber, idx, str);
	genestringbeolvas(departure.ora, idx, str);
	genestringbeolvas(departure.perc, idx, str);
	genestringbeolvas(arrival.ora, idx, str);
	genestringbeolvas(arrival.perc, idx, str);
	genestringbeolvas(seatnumber, idx, str);
}

void Jegy::rejtettkiir(std::fstream& database) const {
	database.open("vasarloadatbazis.txt", std::ios::app);
	if (database.is_open()) {
		database << name << ";" << from << ";" << to << ";" << cost
			<< ";" << vehnumber << ";" << departure.ora << ";"
			<< departure.ora << ";" << arrival.ora << ";" << arrival.perc << ";"
			<< seatnumber << ";";
	}
}

void Jegy::print(std::ostream& os) const {
	os << "Vasarlo neve: " << name << ", " << "indulas: " << departure << " " << "erkezes: " << arrival << '\n'
		<< "Honnan: " << from << " " << "Hova: " << to << '\n'
		<< "Jegyar: " << cost << "Ft" << " " << "Hely: " << seatnumber << '\n'
		<< "Vonatszam: " << vehnumber << " ";
}