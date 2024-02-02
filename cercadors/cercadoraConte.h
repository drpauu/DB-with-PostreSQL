#pragma once
#include<pqxx/pqxx>
#include<iostream>
#include "../passareles/passarelaConte.h"
#include "../config.txt"
#include <vector>

class cercadoraConte
{
	private:

	public:
		
		//Constructora
		cercadoraConte();

		//Destructora
		~cercadoraConte();

		//Funcio cerca: Busca tots els continguts (videojocs o paquets) que coincideixen amb el nom donat.
		vector<passarelaConte> cerca(string n);
};