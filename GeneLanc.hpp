
#ifndef GENELANC_HPP
#define GENELANC_HPP
//lancolt lista kezelesere letrehozott osztaly template
//fontos, hogy a T helyere olyan osztaly/struktura keruljon, ami Jarmu-bol(annak alosztalyaibol) szeretne letrehozni lancot
//Így a bemeneti T-nek friendnek kell lennie, illetve rendelkeznie kell << operatorral, es egy az adattagjait lefoglalo fugvennyel
template<typename T>
class GeneLanc {
	T* first;//lista elso eleme
public:
	GeneLanc(): first(NULL) {}
	GeneLanc(T* in): first(in) {}

	void eraselist() {//lista dinamikusan lefoglalt elemeinek felszabaditasa, az objektum meg megmarad
		T* iter = first;
		while (iter != NULL) {
			T* kov = iter->next;
			delete iter;
			iter = kov;
		}
	}
	virtual ~GeneLanc() { eraselist(); }
	T* findmember(int index) const {//lista index-edik tagjanak megkeresese es visszaadasa
		T* iter = first;
		for (int i = 1; i != index; ++i) {
			iter = iter->next;
		}
		return iter;
	}

	void addtolistandwriteout(const std::string& rhs, int i) {//az rhs-ben szereplo informaciokat menti le az uj objektumba es írja ki azt a szabvanyos kimenetre, illetve hozzafuzi a lista vegere
		T* uj = new T;
		uj->allocateveh(rhs);
		std::cout << "(" << i << ") " << uj->vehicle;
		if (first == NULL)
			first = uj;
		else {
			T* iter = first;
			while (!(iter->next == NULL))
				iter = iter->next;
			iter->next = uj;
		}
	}
	int readfromtxt() {//megfelelo formatomu fajlbol beolvas es letrehozza a lancolt listat ez alapjan, az addtolistnadwriteout() segítsegevel
		std::ifstream file;
		file.open("vonatadatbazis.txt", std::ios::in);
		std::string buffer;
		int i = 1;
		while (std::getline(file, buffer)) {
			addtolistandwriteout(buffer, i);
			buffer.clear(), ++i;
		}
		file.close();
		return i - 1;
	}
	void overwrite() {//Vissza írja a lista elemeinek informacioit a forras szoveges fajlba, felulirja az ottani adatokat
		std::fstream file;
		file.open("vonatadatbazis.txt", std::ios::out);
		file.close();
		T* iter = first;
		iter->fajlkiir();
		while (!(iter->next == NULL)) {
			iter = iter->next;
			iter->fajlkiir();
		}
	}
};

#endif // !GENELANC_HPP

