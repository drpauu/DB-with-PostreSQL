#pragma once
#include <iostream>

using namespace std;

class passarelaVideojoc
{
	private:
		
		string nom, dataLlan, genere;
		int qualificacio, minsEstimat;

	public:

		//Constructora
		passarelaVideojoc(string n, int q, string data, string g, int mins);

		//Destructora
		~passarelaVideojoc();

		//Getters
		string getNom();

		string getDataLlan();

		string getGenere();

		int getQualificacio();

		int getMinsEstimat();

		//No fan falta setters ja que l'usuari no pot modificar el cataleg de la botiga.

		//No fa falta cap operacio amb la base de dades ja que l'usuari no pot modificar el catalega de la botiga.
};