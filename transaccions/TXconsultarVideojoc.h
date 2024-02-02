#pragma once
#include <iostream>
#include <vector>
#include "../passareles/passarelaElementCompra.h"
#include "../cercadors/cercadoraElementCompra.h"
#include "../passareles/passarelaVideojoc.h"
#include "../cercadors/cercadoraVideojoc.h"
#include "../passareles/passarelaConte.h"
#include "../cercadors/cercadoraConte.h"

using namespace std;

class TXconsultarVideojoc {
	public:

		//Tupla amb tota la informacio a retornar.
		struct res
		{
			string nom, desc, genere, data;
			int qualificacio;
			double preu;
			vector<string> paquets;
		};

		//Constructora
		TXconsultarVideojoc(string n);

		//Destructora
		~TXconsultarVideojoc();

		//executar: Crida per executar.
		void executar();

		//obteResultat: Crida per retornar el resultat.
		res obteResultat();

	private:

		string nomV;
		res resultat;
};