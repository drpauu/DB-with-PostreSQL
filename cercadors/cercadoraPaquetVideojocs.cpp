#include "cercadoraPaquetVideojocs.h"

// Constructor: Inicialitza l'objecte cercadoraPaquetVideojocs.
cercadoraPaquetVideojocs::cercadoraPaquetVideojocs() {
    // No requereix inicialització especial.
}

// Destructor: Neteja recursos si es necessari.
cercadoraPaquetVideojocs::~cercadoraPaquetVideojocs() {
    // No requereix accions de neteja especials.
}

// cercaPerNom: Cerca a la base de dades un paquet per nom.
// Pre: 'nomP' conté el nom del paquet a cercar.
// Post: Retorna un objecte 'passarelaPaquetVideojocs' amb les dades del paquet si es troba.
passarelaPaquetVideojocs cercadoraPaquetVideojocs::cercaPerNom(string nomP) {
    string comanda = "SELECT * FROM paquet_videojoc WHERE nom = '" + nomP + "';";
    pqxx::row q;
    try {
        pqxx::connection conn(PARAMS); // Connecta amb la base de dades.
        pqxx::work txn(conn); // Inicia una transacció.
        q = txn.exec1(comanda); // Executa la consulta.
        txn.commit(); // Confirma la transacció.
    } catch(...) {
        // Si no es troba el paquet, llença una excepció.
        throw exception("No existeix el paquet a buscar");
    }
    return passarelaPaquetVideojocs(q[0].c_str()); // Retorna el paquet trobat.
}

// preuJocs: Calcula el preu total dels videojocs inclosos en un paquet.
// Pre: 'nomP' és el nom del paquet del qual volem saber el preu total dels videojocs.
// Post: Retorna el preu total dels videojocs que conté el paquet.
double cercadoraPaquetVideojocs::preuJocs(string nomP) {
    string comanda = "SELECT preu_jocs FROM preu_jocs WHERE nom_paquet = '" + nomP + "';";
    pqxx::row q;
    try {
        pqxx::connection conn(PARAMS); // Connecta amb la base de dades.
        pqxx::work txn(conn); // Inicia una transacció.
        q = txn.exec1(comanda); // Executa la consulta.
        txn.commit(); // Confirma la transacció.
    }
    catch (...) {
        // Si no es troba el paquet, llença una excepció.
        throw exception("No existeix el paquet a buscar");
    }
    return q[0].as<double>(); // Retorna el preu total dels videojocs del paquet.
}
