#include "cercadoraElementCompra.h"

// Constructor: Inicialitza l'objecte sense estat intern.
cercadoraElementCompra::cercadoraElementCompra() {
    // No requereix inicialització especial.
}

// Destructor: Neteja recursos si es necessari.
cercadoraElementCompra::~cercadoraElementCompra() {
    // No requereix accions especials en la destrucció.
}

// cercaPerNom: Cerca a la base de dades un element específic pel seu nom.
// Pre: 'n' conté el nom de l'element a cercar.
// Post: Retorna un objecte 'passarelaElementCompra' amb les dades de l'element si es troba.
passarelaElementCompra cercadoraElementCompra::cercaPerNom(string n) {
    string comanda = "SELECT * FROM element_compra WHERE nom = '" + n + "';";
    pqxx::row q;
    try {
        pqxx::connection conn(PARAMS); // Connecta amb la base de dades.
        pqxx::work txn(conn); // Inicia una transacció.
        q = txn.exec1(comanda); // Executa la consulta.
        txn.commit(); // Confirma la transacció.
    } catch(...) {
        // Si no es troba l'element, llença una excepció.
        throw exception("No existeix l'element a buscar");
    }
    return passarelaElementCompra(q[0].c_str(), q[1].c_str(), q[2].as<double>(), q[3].c_str()); // Retorna l'element trobat.
}

// totsVideojocs: Cerca tots els videojocs a la base de dades.
// Pre: Cap.
// Post: Retorna un vector de 'passarelaElementCompra' amb tots els videojocs.
vector<passarelaElementCompra> cercadoraElementCompra::totsVideojocs() {
    vector<passarelaElementCompra> res;
    string comanda = "SELECT * FROM element_compra INNER JOIN videojoc ON element_compra.nom = videojoc.nom ORDER BY videojoc.data_llansament DESC;";
    pqxx::connection conn(PARAMS); // Connecta amb la base de dades.
    pqxx::work txn(conn); // Inicia una transacció.
    pqxx::result q = txn.exec(comanda); // Executa la consulta.
    txn.commit(); // Confirma la transacció.
    for (auto fila : q) {
        // Afegeix a la llista els videojocs trobats.
        res.emplace_back(fila[0].c_str(), fila[1].c_str(), fila[2].as<double>(), fila[3].c_str());
    }
    return res; // Retorna la llista de videojocs.
}

// totsPaquets: Cerca tots els paquets a la base de dades.
// Pre: Cap.
// Post: Retorna un vector de 'passarelaElementCompra' amb tots els paquets.
vector<passarelaElementCompra> cercadoraElementCompra::totsPaquets() {
    vector<passarelaElementCompra> res;
    string comanda = "SELECT * FROM element_compra WHERE tipus = 'paquet';";
    pqxx::connection conn(PARAMS); // Connecta amb la base de dades.
    pqxx::work txn(conn); // Inicia una transacció.
    pqxx::result q = txn.exec(comanda); // Executa la consulta.
    txn.commit(); // Confirma la transacció.
    for (auto fila : q) {
        // Afegeix a la llista els paquets trobats.
        res.emplace_back(fila[0].c_str(), fila[1].c_str(), fila[2].as<double>(), fila[3].c_str());
    }
    return res; // Retorna la llista de paquets.
}
