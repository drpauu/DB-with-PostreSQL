#include <iostream>
#include <stdlib.h>
#include <pqxx/pqxx>
#include <vector>
#include <ctime>
#include <regex>
#include "transaccions/TXcomprarPaquet.h"
#include "transaccions/TXcomprarVideojoc.h"
#include "transaccions/TXconsultarCompres.h"
#include "transaccions/TXconsultarNovetats.h"
#include "transaccions/TXconsultarPaquet.h"
#include "transaccions/TXconsultarPaquets.h"
#include "transaccions/TXconsultarUsuari.h"
#include "transaccions/TXconsultarVideojoc.h"
#include "transaccions/TXconsultarVideojocs.h"
#include "transaccions/TXconsultarVideojocsPerEdat.h"
#include "transaccions/TXesborrarUsuari.h"
#include "transaccions/TXiniciarSessio.h"
#include "transaccions/TXregistrarUsuari.h"
#include "transaccions/TXtancarSessio.h"
#include "transaccions/CUmodificaUsuari.h"

using namespace std;

class capaPresentacio {
private:

	capaPresentacio() {

	};

	//Funcio privada per comprovar que el correu te un format correcte
	bool comprovarCorreu(string s);

	//Funcio privada per comprovar que la data introduida per l'usuari te un format correcte
	bool comprovarData(string data);
	
	//Funcio per traduir el format entre el que s'utilitza a la interfície i la que s'utilitza a la base de dades
	string dataFormatter(string data);

public:

	static capaPresentacio& getInstance();

	~capaPresentacio();

	bool iniciarSessioPres();

	bool tancarSessioPres();

	void registrarUsuariPres();

	void consultarUsuariPres();

	void modificarUsuariPres();

	bool esborrarUsuariPres();

	void comprarVideojocPres();

	void comprarPaquetPres();

	void consultarCompresPres();

	void consultarVideojocPres();

	void consultarVideojocsPres();

	void consultarVideojocsEdatPres();

	void consultarNovetatsPres();

	void consultarPaquetPres();

	void consultarPaquetsPres();

};