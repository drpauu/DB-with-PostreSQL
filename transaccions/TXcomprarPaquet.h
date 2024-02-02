#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include "../cercadors/cercadoraElementCompra.h"
#include "../cercadors/cercadoraPaquetVideojocs.h"
#include "../passareles/passarelaElementCompra.h"
#include "../passareles/passarelaPaquetVideojocs.h"
#include "../passareles/passarelaCompra.h"
#include "../cercadors/cercadoraCompra.h"
#include "../cercadors/cercadoraConte.h"
#include "../passareles/passarelaConte.h"
#include "../videoconsola.h"

using namespace std;

class TXcomprarPaquet {

	public:

		struct res{
			string nom, desc;
			double preu;
		};

		TXcomprarPaquet(string nom);

		~TXcomprarPaquet();

		void executar();

		string obteResultat();

	private:
		
		string nomPaquet;
		string resultat;
};