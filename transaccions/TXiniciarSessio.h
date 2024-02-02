#pragma once
#include <iostream>
#include "../passareles/passarelaUsuari.h"
#include "../cercadors/cercadoraUsuari.h"
#include "../videoconsola.h"

using namespace std;

class TXiniciarSessio {
	private:
		
		string sobrenom, contrasenya;
		bool resultat;

	public:

		TXiniciarSessio(string sn, string cs);

		~TXiniciarSessio();

		void executar();

		bool obteResultat();

};