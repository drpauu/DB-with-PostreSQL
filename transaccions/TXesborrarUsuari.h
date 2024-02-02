#pragma once
#include "../videoconsola.h"
#include "../cercadors/cercadoraUsuari.h"
#include "../passareles/passarelaUsuari.h"
#include <iostream>

using namespace std;

class TXesborrarUsuari {
	private:
		
		string contrasenya;
		bool result;

	public:

		TXesborrarUsuari(string c);

		~TXesborrarUsuari();

		void executar();

		bool obteResultat();
};