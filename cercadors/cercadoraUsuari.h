#pragma once
#include<pqxx/pqxx>
#include<iostream>
#include "../passareles/passarelaUsuari.h"
#include "../config.txt"

class cercadoraUsuari
{
	private:

	public:
		
		//Constructora
		cercadoraUsuari();

		//Destructora
		~cercadoraUsuari();

		//cercaPerSobrenom: Busca un usuari per sobrenom en la base de dades.
		passarelaUsuari cercaPerSobrenom(string sn);

};