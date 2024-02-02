#include "cercadoraUsuari.h"

// Constructor: Inicialitza l'objecte sense parametres especifics.
cercadoraUsuari::cercadoraUsuari() {
}

// Destructor: Neteja recursos si es necessari.
cercadoraUsuari::~cercadoraUsuari() {
}

// cercaPerSobrenom: Busca un usuari per sobrenom en la base de dades.
passarelaUsuari cercadoraUsuari::cercaPerSobrenom(string sn) {
    string comanda = "SELECT * FROM usuari WHERE sobrenom = '" + sn + "';";
    pqxx::row q;
    try {
        pqxx::connection conn(PARAMS); // Estableix connexio amb la base de dades.
        pqxx::work txn(conn); // Inicia una transaccio.
        q = txn.exec1(comanda); // Executa la consulta SQL.
        txn.commit(); // Finalitza la transaccio.
    } catch(...) {
        //Si la consulta no retorna exactament una fila (excepcio de exec1), llença la excepcio UsuariNoExisteix
        throw exception("No existeix l'usuari");
    }
    return passarelaUsuari(q[1].c_str(), q[0].c_str(), q[2].c_str(), q[3].c_str(), q[4].c_str()); // Retorna el resultat.
}
