#include <iostream>
#include <pqxx/pqxx>
#include <stdlib.h>
#include "capaPresentacio.h"

using namespace std;

int main() {
	int op;
	bool sessioIniciada = false; 
	capaPresentacio& cP = capaPresentacio::getInstance();
	while (true) {
		if (!sessioIniciada) {
			while (!sessioIniciada) {
				cout << "*********************" << "\n" << "    Menu Principal" << "\n" << "*********************" << "\n";
				cout << "1. Iniciar sessio" << "\n";
				cout << "2. Registrar usuari" << "\n";
				cout << "3. Sortir" << "\n";
				cout << "Opcio: ";
				cin >> op;
				system("CLS");
				switch (op) {
				case 1:
					sessioIniciada = cP.iniciarSessioPres();
					break;
				case 2:
					cP.registrarUsuariPres();
					break;
				case 3:
					return 0;
				default:
					cout << "Selecciona una opcio valida amb les tecles de l'1 al 3" << "\n";
				}
			}
		}
		cout << "*********************" << "\n" << "    Menu Principal" << "\n" << "*********************" << "\n";
		cout << "1. Gestionar usuari" << "\n";
		cout << "2. Gestionar compres" << "\n";
		cout << "3. Consultar" << "\n";
		cout << "4. Tancar sessio" << "\n";
		cout << "5. Sortir" << "\n";
		cout << "Opcio: ";
		cin >> op;
		system("CLS");
		switch (op) {
			case 1:
				cout << "\n" << "--- GESTIONAR USUARI ---" << "\n";
				cout << "1. Consultar usuari" << "\n";
				cout << "2. Modificar usuari" << "\n";
				cout << "3. Esborrar usuari" << "\n";
				cout << "4. Tornar" << "\n";
				cout << "Opcio: ";
				cin >> op;
				system("CLS");
				switch (op) {
					case 1:
						cP.consultarUsuariPres();
						break;
					case 2:
						cP.modificarUsuariPres();
						break;
					case 3:
						sessioIniciada = cP.esborrarUsuariPres();
						break;
					case 4:
						break;
					default:
						cout << "Selecciona una opcio valida amb les tecles de l'1 al 4" << "\n";
						break;
					}
				break;
			case 2:
				cout << "\n" << "--- GESTIO DE COMPRES ---" << "\n";
				cout << "1. Comprar videojoc" << "\n";
				cout << "2. Comprar paquet videojocs" << "\n";
				cout << "3. Consultar compres" << "\n";
				cout << "4. Tornar" << "\n";
				cout << "Opcio: ";
				cin >> op;
				system("CLS");
				switch (op) {
					case 1:
						cP.comprarVideojocPres();
						break;
					case 2:
						cP.comprarPaquetPres();
						break;
					case 3:
						cP.consultarCompresPres();
						break;
					case 4:
						break;
					default:
					cout << "Selecciona una opcio valida amb les tecles de l'1 al 4" << "\n";
					break;
				}
				break;
			case 3:
				cout << "\n" << "--- CONSULTES DE VIDEOJOCS ---" << "\n";
				cout << "1. Consultar videojoc" << "\n";
				cout << "2. Consultar videojocs" << "\n";
				cout << "3. Consultar videojocs per edat" << "\n";
				cout << "4. Consultar novetats videojocs" << "\n";
				cout << "5. Consultar paquet videojocs" << "\n";
				cout << "6. Consultar paquets videojocs" << "\n";
				cout << "7. Tornar" << "\n";
				cout << "Opcio: ";
				cin >> op;
				system("CLS");
				switch (op) {
					case 1:
						cP.consultarVideojocPres();
						break;
					case 2:
						cP.consultarVideojocsPres();
						break;
					case 3:
						cP.consultarVideojocsEdatPres();
						break;
					case 4:
						cP.consultarNovetatsPres();
						break;
					case 5:
						cP.consultarPaquetPres();
						break;
					case 6:
						cP.consultarPaquetsPres();
						break;
					case 7:
						break;
					default:
						cout << "Selecciona una opcio valida amb les tecles de l'1 al 7" << "\n";
						break;
				}
				break;
			case 4:
				sessioIniciada = cP.tancarSessioPres();
				break;
			case 5:
				return 0;
			default:
				cout << "Selecciona una opcio vàlida amb les tecles de l'1 al 5" << "\n";
		}
	}
	return 0;
}