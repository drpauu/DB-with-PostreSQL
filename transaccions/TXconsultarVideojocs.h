#pragma once
#include <iostream>
#include <vector>
#include "../cercadors/cercadoraElementCompra.h"
#include "../passareles/passarelaElementCompra.h"
#include "../cercadors/cercadoraVideojoc.h"
#include "../passareles/passarelaVideojoc.h"
#include "../cercadors/cercadoraConte.h"
#include "../passareles/passarelaConte.h"

using namespace std;

class TXconsultarVideojocs {		
	public:

		struct res
		{
			string nom, desc, genere, data;
			int qualificacio;
			double preu;
			vector<string> paquets;
		};

		TXconsultarVideojocs();

		~TXconsultarVideojocs();

		void executar();

		vector<res> obteResultat();

	private:

		vector<res> resultat;

};