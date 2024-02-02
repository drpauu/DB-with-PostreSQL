#pragma once
#include<pqxx/pqxx>
#include<iostream>
#include "../config.txt"

using namespace std;

class passarelaUsuari
{
	private:

		string nom, sobrenom, contrasenya, correuE, dataN;

	public:
		
		//Constructora
		passarelaUsuari(string n, string sn, string c, string cE, string dN);

		//Constructora per defecte (per poder posar una passarelaUsuari com a atribut a la classe videconsola)
		passarelaUsuari();

		//Destructora
		~passarelaUsuari();

		//Getters
		string getNom();

		string getSobrenom();

		string getContrasenya();

		string getCorreu();

		string getDataN();

		//Setters
		void setNom(string n);

		//No hi ha setter pel sobrenom ja que es l'id
		
		void setContrasenya(string c);

		void setCorreu(string cE);

		void setDataN(string dN);

		//Operacions sobre la BD
		void insereix();

		void modifica();

		void esborra();
};

