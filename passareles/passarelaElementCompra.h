#pragma once
#include<iostream>

using namespace std;

class passarelaElementCompra
{
	private:

		string nom, descripcio, tipus;
		double preu;

	public:

		//Constructora
		passarelaElementCompra(string n, string desc, double p, string t);

		//Destructora
		~passarelaElementCompra();

		//Getters
		string getNom();

		string getDescripcio();

		double getPreu();

		string getTipus();

		//No fan falta setters ja que l'usuari no pot modificar el cataleg de la botiga.

		//No fan falta operacions de inserir, modificar i esborrar ja que l'usuari no pot modificar el cataleg de la botiga.
};