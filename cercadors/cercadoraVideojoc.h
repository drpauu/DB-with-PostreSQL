#pragma once
#include <pqxx/pqxx>
#include <iostream>
#include "../passareles/passarelaVideojoc.h"
#include "../config.txt"

using namespace std;

class cercadoraVideojoc
{
	private:

	public:
		
		//Constructora
		cercadoraVideojoc();

		//Destructora
		~cercadoraVideojoc();

		// cercaPerNom: Busca un videojoc per nom en la base de dades.
		passarelaVideojoc cercaPerNom(string n);
		
		// cercaNovetats: Retorna una llista de videojocs llançats des d'una data especifica.
		vector<passarelaVideojoc> cercaNovetats(string d);

		// cercaPerEdat: Retorna videojocs que son adequats per a una edat especifica o menys.
		vector<passarelaVideojoc> cercaPerEdat(int e);

};

