#pragma once
#include<iostream>

using namespace std;

class passarelaPaquetVideojocs
{
	private:

		string nom;

	public:

		//Constructora
		passarelaPaquetVideojocs(string n);

		//Destructora
		~passarelaPaquetVideojocs();

		//Getter
		string getNom();

		//No fan falta setters ja que l'usuari no pot modificar el cataleg de la botiga.

		//No fan falta operacions de inserir, modificar i esborrar ja que l'usuari no pot modificar el cataleg de la botiga.
};