#include "cercadoraVideojoc.h"

// Constructor: S'inicialitza l'objecte sense parametres especifics.
cercadoraVideojoc::cercadoraVideojoc() {
}

// Destructor: Neteja recursos si es necessari.
cercadoraVideojoc::~cercadoraVideojoc() {
}

// cercaPerNom: Busca un videojoc per nom en la base de dades.
passarelaVideojoc cercadoraVideojoc::cercaPerNom(string n) {
    string comanda = "SELECT * FROM videojoc WHERE nom = '" + n + "';";
    pqxx::row q;
    try {
        pqxx::connection conn(PARAMS); // Estableix connexio amb la base de dades.
        pqxx::work txn(conn); // Inicia una transaccio.
        q = txn.exec1(comanda); // Executa la consulta SQL.
        txn.commit(); // Finalitza la transaccio.
    } catch (...) {
        //Si la consulta no retorna exactament una fila (excepcio de exec1), llença la excepcio VideojocNoExisteix
        throw exception("No existeix el videojoc a buscar");
    }
    return passarelaVideojoc(q[0].c_str(), q[2].as<int>(), q[3].c_str(), q[1].c_str(), 0); // Retorna el resultat.
}


// cercaNovetats: Retorna una llista de videojocs llançats des d'una data especifica.
vector<passarelaVideojoc> cercadoraVideojoc::cercaNovetats(string d) {
    vector<passarelaVideojoc> res;
    string comanda = "SELECT * FROM videojoc WHERE data_llansament >= '" + d + "' ORDER BY data_llansament DESC;";
    pqxx::connection conn(PARAMS); // Estableix connexio amb la base de dades.
    pqxx::work txn(conn); // Inicia una transaccio.
    pqxx::result r = txn.exec(comanda); // Executa la consulta SQL.
    txn.commit(); // Finalitza la transaccio.
    for (int i = 0; i < r.size(); i++) {
        //Crea passareles amb cada fila del resultat.
        res.push_back(passarelaVideojoc(r[i][0].c_str(), r[i][2].as<int>(), r[i][3].c_str(), r[i][1].c_str(), 0));
    }
    return res; // Retorna els resultats.
}

// cercaPerEdat: Retorna videojocs que son adequats per a una edat especifica o menys.
vector<passarelaVideojoc> cercadoraVideojoc::cercaPerEdat(int edat) {
    vector<passarelaVideojoc> res;
    string comanda = "SELECT * FROM videojoc WHERE qualificacio_edat <= " + to_string(edat) + " ORDER BY qualificacio_edat DESC;";
    pqxx::connection conn(PARAMS); // Estableix connexio amb la base de dades.
    pqxx::work txn(conn); // Inicia una transaccio.
    pqxx::result r = txn.exec(comanda); // Executa la consulta SQL.
    txn.commit(); // Finalitza la transaccio.
    for (int i = 0; i < r.size(); i++) {
        //Crea passareles amb cada fila del resultat.
        res.push_back(passarelaVideojoc(r[i][0].c_str(), r[i][2].as<int>(), r[i][3].c_str(), r[i][1].c_str(), 0));
    }
    return res; // Retorna els resultats.
}