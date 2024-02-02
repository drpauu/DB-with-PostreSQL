#include <iostream>
#include "../transaccions/TXconsultarUsuari.h"
#include "../passareles/passarelaUsuari.h"
#include "../videoconsola.h"

using namespace std;

class CUmodificaUsuari {
	public:

		//Constructora
		CUmodificaUsuari();

		//Destructora
		~CUmodificaUsuari();

		//consultaUsuari: retorna informacio sobre l'usuari.
		TXconsultarUsuari::res consultaUsuari();

		//modificaUsuari: modifica la informacio de l'usuari logejat.
		void modificaUsuari(string nomU, string contraU, string correuU, string naixU);

	private:

	
};