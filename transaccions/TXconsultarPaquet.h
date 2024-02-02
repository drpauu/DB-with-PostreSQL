#pragma once
#include <iostream>
#include <vector>
#include "../cercadors/cercadoraElementCompra.h"
#include "../cercadors/cercadoraPaquetVideojocs.h"
#include "../cercadors/cercadoraConte.h"
#include "../passareles/passarelaConte.h"
#include "../passareles/passarelaElementCompra.h"
#include "../passareles/passarelaPaquetVideojocs.h"

using namespace std;

class TXconsultarPaquet {
	public:
		
		struct res{
			string nom, desc;
			double preu, estalvi;
			vector<string> vnoms;
			vector<string> vdescs;
			vector<double> vpreus;
		};

		TXconsultarPaquet(string nom);

		~TXconsultarPaquet();

		void executar();

		res obteResultat();

	private:
		
		string n;
		res resultat;

};