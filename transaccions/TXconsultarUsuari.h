#pragma once
#include <iostream>
#include "../cercadors/cercadoraUsuari.h"
#include "../passareles/passarelaUsuari.h"
#include "../videoconsola.h"
#include <stdexcept>

using namespace std;

class TXconsultarUsuari {
	public:

		//Tupla amb tota la informacio a retornar.
		struct res {
			string nom, sobrenom, correu, dataN, contrasenya;
		};

		//Constructora
		TXconsultarUsuari();

		//Destructora
		~TXconsultarUsuari();

		//executar: Crida per executar.
		void executar();

		//obteResultat: Crida per retornar el resultat.
		res obteResultat();
	
	private:
		
		res resultat;

};