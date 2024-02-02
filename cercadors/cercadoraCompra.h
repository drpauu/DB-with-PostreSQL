#pragma once
#include <iostream>
#include <pqxx/pqxx>
#include <vector>
#include "../config.txt"
#include "../passareles/passarelaCompra.h"

using namespace std;

class cercadoraCompra
{
	private:

	public:
		
		//Constructora
		cercadoraCompra();

		//Destructora
		~cercadoraCompra();

		//cercaPerUsuari: Busca totes les compres d'un usuari en especific.
		vector<passarelaCompra> cercaPerUsuari(string u);

		// cercaPerElement: Busca una compra per un element especific.
		passarelaCompra cercaPerElement(string el);

};