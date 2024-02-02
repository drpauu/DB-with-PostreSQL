#pragma once
#include<iostream>

using namespace std;

class passarelaConte
{
	private:

		string videojoc, paquet;

	public:

		//Constructora
		passarelaConte(string v, string p);

		//Destructora
		~passarelaConte();

		//Getters
		string getVideojoc();

		string getPaquet();

		//No fan falta setters ja que l'usuari no pot modificar el cataleg de la botiga.

		//No fan falta operacions de inserir, modificar i esborrar ja que l'usuari no pot modificar el cataleg de la botiga.
};