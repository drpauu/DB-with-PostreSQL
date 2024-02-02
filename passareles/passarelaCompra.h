#pragma once
#include <pqxx/pqxx>
#include <iostream>
#include "../config.txt"

using namespace std;

class passarelaCompra
{
	private:

		string usuari, element, data;
		double preuPagat;
	
	public:

		//Constructora
		passarelaCompra(string u, string e, string d, double p);

		//Destructora
		~passarelaCompra();

		//Getters
		string getUsuari();

		string getElement();

		string getData();

		double getPreu();

		//No fan falta setters ja que l'usuari no ha de modificar els camps de la Compra

		//Funcions de la base de dades
		//No fan falta les funcions de modificar(l'usuari no ha de modificar les compres) i esborrar(la responsabilitat d'esborrar les compres esta a la BD)
		
		void insereix();

};

