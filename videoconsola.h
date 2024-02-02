#pragma once
#include <iostream>
#include "passareles/passarelaUsuari.h"

using namespace std;

class Videoconsola {

private:

	passarelaUsuari usuari;

	//Constructora privada
	Videoconsola() {

	}

public:

	//Operacio per rebre la instancia de videoconsola 
	static Videoconsola& getInstance();

	//Getter
	passarelaUsuari getUsuari();

	//Setters
	void iniciarSessio(passarelaUsuari pus);

	void tancarSessio();

	void refrescaUsuari(string nom, string contrasenya, string correu, string data);
};