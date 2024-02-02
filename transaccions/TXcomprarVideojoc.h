#pragma once
#include "../cercadors/cercadoraElementCompra.h"
#include "../cercadors/cercadoraVideojoc.h"
#include "../cercadors/cercadoraConte.h"
#include "../cercadors/cercadoraCompra.h"
#include "../passareles/passarelaElementCompra.h"
#include "../passareles/passarelaUsuari.h"
#include "../passareles/passarelaVideojoc.h"
#include "../passareles/passarelaConte.h"
#include "../passareles/passarelaCompra.h"
#include "../videoconsola.h"
#include <iostream>
#include <ctime>

using namespace std;

class TXcomprarVideojoc {
	public:

		//Tupla de la informacio dels recomanats (videojocs que estan a paquets on esta el videojoc adquirit).
		struct recomanacio {
			string nom, desc;
			double preu;
		};

		//Tupla amb informacio de la compra i tots els videojocs recomanats.
		struct res {
			string data;
			vector<recomanacio> recomanats;
		};

		//Constructora
		TXcomprarVideojoc(string n);

		//Destructora
		~TXcomprarVideojoc();

		//executar: Crida per executar.
		void executar();

		//obteResultat: Crida per retornar el resultat.
		res obteResultat();

	private:

		res resultat;
		string nom;

};