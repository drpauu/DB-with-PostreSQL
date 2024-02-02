#pragma once
#include <iostream>
#include "../passareles/passarelaVideojoc.h"
#include "../cercadors/cercadoraVideojoc.h"
#include "../passareles/passarelaElementCompra.h"
#include "../cercadors/cercadoraElementCompra.h"
#include "../passareles/passarelaConte.h"
#include "../cercadors/cercadoraConte.h"

using namespace std;

class TXconsultarVideojocsPerEdat {
	public:

		struct res
		{
			string nom, desc, genere, data;
			int qualificacio;
			double preu;
			vector<string> paquets;
		};

		TXconsultarVideojocsPerEdat(int e);

		~TXconsultarVideojocsPerEdat();

		void executar();

		vector<res> obteResultat();

	private:
		
		int edat;
		vector<res> resultat;

};