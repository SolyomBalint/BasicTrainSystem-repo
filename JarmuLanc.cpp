#include "memtrace.h"
#include "JarmuLanc.h"
#include "vonat.h"

//Jarmu torlese
void JarmuLanc::erase() {
	if(vehicle != NULL)
		delete vehicle;
}

void JarmuLanc::allocateveh(const std::string& str) {
	if (vehicle != NULL)
		delete vehicle;
	vehicle = new Vonat; //uj vonat tag lefoglalasa
	vehicle->stringbeolvas(str); //string tarolja az uj vonat adatait
}
