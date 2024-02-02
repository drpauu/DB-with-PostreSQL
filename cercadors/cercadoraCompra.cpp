#include "cercadoraCompra.h"

// Constructor: Inicialitza objecte sense estat intern.
cercadoraCompra::cercadoraCompra() {
    // No requereix inicialització especial.
}

// Destructor: Allibera recursos si és necessari.
cercadoraCompra::~cercadoraCompra() {
    // No requereix accions especials en la destrucció.
}

// cercaPerUsuari: Realitza la cerca de totes les compres realitzades per un usuari.
// Pre: 'u' conté el nom d'usuari per al qual es volen cercar les compres.
// Post: Retorna un vector de 'passarelaCompra' amb totes les compres realitzades per l'usuari.
vector<passarelaCompra> cercadoraCompra::cercaPerUsuari(string u) {
    vector<passarelaCompra> res;
    pqxx::connection conn(PARAMS); // Connecta amb la base de dades.
    pqxx::work txn(conn); // Crea una nova transacció.
    string comanda = "SELECT * FROM compra WHERE usuari = '" + u + "' ORDER BY data DESC;";
    pqxx::result r = txn.exec(comanda); // Executa la consulta SQL.
    txn.commit(); // Confirma la transacció.
    for (auto fila : r) {
        // Afegeix les dades de compra al vector de resultats.
        res.emplace_back(fila[0].c_str(), fila[1].c_str(), fila[2].c_str(), fila[3].as<double>());
    }
    return res; // Retorna les compres trobades.
}

// cercaPerElement: Cerca compres associades amb un element de compra específic.
// Pre: 'e' és el nom de l'element de compra a cercar.
// Post: Retorna un objecte 'passarelaCompra' amb les dades de la compra trobada.
passarelaCompra cercadoraCompra::cercaPerElement(string e) {
    pqxx::row q;
    try {
        pqxx::connection conn(PARAMS); // Connecta amb la base de dades.
        pqxx::work txn(conn); // Crea una nova transacció.
        string comanda = "SELECT * FROM compra WHERE element = '" + e + "';";
        q = txn.exec1(comanda); // Executa la consulta i espera una única fila com a resultat.
        txn.commit(); // Confirma la transacció.
    } catch (const std::exception& ex) {
        // Captura qualsevol excepció i la rellança amb un missatge d'error més específic.
        throw std::runtime_error("Error cercant la compra: " + std::string(ex.what()));
    }
    // Crea i retorna un objecte 'passarelaCompra' amb les dades de la fila obtinguda.
    return passarelaCompra(q[0].c_str(), q[1].c_str(), q[2].c_str(), q[3].as<double>());
}
