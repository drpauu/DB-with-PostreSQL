#include "passarelaConte.h"

//Constructora
passarelaConte::passarelaConte(string v, string p) {
	videojoc = v;
	paquet = p;
}

//Destructora
passarelaConte::~passarelaConte() {

}

//Getters
string passarelaConte::getVideojoc() {
	return videojoc;
}

string passarelaConte::getPaquet() {
	return paquet;
}

//No fan falta setters ja que l'usuari no pot modificar el cataleg de la botiga.

//No fan falta operacions de inserir, modificar i esborrar ja que l'usuari no pot modificar el cataleg de la botiga.