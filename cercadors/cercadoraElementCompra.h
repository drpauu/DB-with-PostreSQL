#pragma once
#include<pqxx/pqxx>
#include<iostream>
#include<vector>
#include "../passareles/passarelaElementCompra.h"
#include "../config.txt"

using namespace std;

class cercadoraElementCompra
{
	private:

	public:
		
		//Constructora
		cercadoraElementCompra();

		//Destructora
		~cercadoraElementCompra();

		//cercaPerNom: Realitza una consulta a la base de dades per trobar un element per nom.
		passarelaElementCompra cercaPerNom(string n);

		//totsVideojocs: Retorna tots els videojocs presents a la base de dades.
		vector<passarelaElementCompra> totsVideojocs();

		//totsPaquets: Retorna tots els paquets presents a la base de dades.
		vector<passarelaElementCompra> totsPaquets();

};

