

#ifndef GENEFG_HPP
#define GENEFG_HPP

//ez egy sablon fuggveny stringbol valo beolvasashoz
//A bemeneti stringben az adattagok ";"-al vannak elvalasztva, ezert olvas mindig addig
template<typename Variable>
void genestringbeolvas(Variable& V, int& index, const std::string& source) {
	std::string buffer;
	while (source[index] != ';')
		buffer += source[index++];
	V = std::stoi(buffer);//visszaadja egy stringben stereplo szamokat
	buffer.clear();
	++index;
}
template<>
void genestringbeolvas<std::string>(std::string& str, int& index, const std::string& source) {
	while (source[index] != ';')
		str += source[index++];
	++index;
}

#endif // !GENEFG_HPP

