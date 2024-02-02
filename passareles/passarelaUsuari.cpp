#include "passarelaUsuari.h"

//Constructora
passarelaUsuari::passarelaUsuari(string n, string sn, string c, string cE, string dN) {
	nom = n;
	sobrenom = sn;
	contrasenya = c;
	correuE = cE;
	dataN = dN;
}

//Constructora per defecte (per poder posar una passarelaUsuari com a atribut a la classe videconsola)
passarelaUsuari::passarelaUsuari() {

}

//Destructora
passarelaUsuari::~passarelaUsuari() {

}

//Getters
string passarelaUsuari::getNom() {
    return nom;
}


string passarelaUsuari::getSobrenom() {
	return sobrenom;
}

string passarelaUsuari::getContrasenya() {
	return contrasenya;
}

string passarelaUsuari::getCorreu() {
	return correuE;
}

string passarelaUsuari::getDataN() {
	return dataN;
}

//Setters
void passarelaUsuari::setNom(string n) {
	nom = n;
}

//No hi ha setter pel sobrenom ja que es l'id

void passarelaUsuari::setContrasenya(string c) {
	contrasenya = c;
}

void passarelaUsuari::setCorreu(string cE) {
	correuE = cE;
}

void passarelaUsuari::setDataN(string dN) {
	dataN = dN;
}

//Operacions sobre la BD
void passarelaUsuari::insereix() {
	pqxx::connection conn(PARAMS); //Crea la connexio amb la base de dades.
	pqxx::work txn(conn); //Crea la transaccio.
	string comanda = "INSERT INTO usuari VALUES('"+sobrenom+"', '"+nom+"', '"+contrasenya+"', '"+correuE+"', '"+dataN+"');";
	pqxx::result result = txn.exec(comanda); //Executa la comanda d'inserir.
	txn.commit(); //Finalitza la transaccio.
}

void passarelaUsuari::modifica() {
	pqxx::connection conn(PARAMS); //Crea la connexio amb la base de dades.
	pqxx::work txn = pqxx::work(conn); //Crea la transaccio.
	string comanda = "UPDATE usuari SET nom = '" + nom + "', contrasenya = '" + contrasenya + "', correu_electronic = '" + correuE + "', data_naixement = '" + dataN + "' WHERE sobrenom = '" + sobrenom + "';";
	txn.exec(comanda); //Executa la comanda de modificacio.
	txn.commit(); //Finalitza la transaccio.
}

void passarelaUsuari::esborra() {
	pqxx::connection conn(PARAMS); //Crea la connexio amb la base de dades.
	pqxx::work txn = pqxx::work(conn); //Crea la transaccio.
	string comanda = "DELETE FROM usuari WHERE sobrenom = '" + sobrenom + "';";
	txn.exec(comanda); //Executa la comanda de modificacio.
	txn.commit(); //Finalitza la transaccio.
}