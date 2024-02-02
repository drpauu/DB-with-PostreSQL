#include "passarelaCompra.h"

//Constructora
passarelaCompra::passarelaCompra(string u, string e, string d, double p) {
	usuari = u;
	element = e;
	data = d;
	preuPagat = p;
}

//Destructora
passarelaCompra::~passarelaCompra() {

}

//Getters

string passarelaCompra::getUsuari() {
	return usuari;
}

string passarelaCompra::getElement() {
	return element;
}

string passarelaCompra::getData() {
	return data;
}

double passarelaCompra::getPreu() {
	return preuPagat;
}

//No fan falta setters ja que l'usuari no ha de modificar els camps de la Compra

//Funcions de la base de dades
//No fan falta les funcions de modificar(l'usuari no ha de modificar les compres) i esborrar(la responsabilitat d'esborrar les compres esta a la BD)
void passarelaCompra::insereix() {
	pqxx::connection conn(PARAMS);
	pqxx::work txn = pqxx::work(conn);
	string comanda = "INSERT INTO compra VALUES ('" + usuari + "', '" + element + "', '" + data + "', " + to_string(preuPagat) + ");";
	txn.exec(comanda);
	txn.commit();
}

/*void passarelaCompra::esborra() {
	pqxx::connection conn(PARAMS);
	pqxx::work txn = pqxx::work(conn);
	string comanda = "DELETE FROM compra WHERE usuari = '" + usuari + "' AND element = '" + element + "';";
	txn.exec(comanda);
	txn.commit();
}*/