#pragma once
#include <iostream>
#include "../videoconsola.h"

using namespace std;

class TXtancarSessio {
	private:

		bool resultat;
	
	public:

		TXtancarSessio();

		~TXtancarSessio();

		void executar();

		bool obteResultat();
};