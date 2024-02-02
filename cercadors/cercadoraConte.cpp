#include "cercadoraConte.h"

// Constructor: Inicialitza la classe cercadoraConte sense estat intern.
cercadoraConte::cercadoraConte() {
    // No requereix inicialització especial.
}

// Destructor: Neteja recursos si es necessari.
cercadoraConte::~cercadoraConte() {
    // No requereix accions especials en la destrucció.
}

// Funcio cerca: Realitza la cerca de continguts relacionats amb un nom específic.
// Pre: 'n' conté el nom del paquet o videojoc a cercar.
// Post: Retorna un vector de 'passarelaConte' amb els continguts relacionats amb 'n'.
vector<passarelaConte> cercadoraConte::cerca(std::string n) {
    vector<passarelaConte> res;
    pqxx::connection conn(PARAMS); // Connecta amb la base de dades.
    pqxx::work txn(conn); // Inicia una transacció.
    string comanda = "SELECT * FROM conte WHERE paquet = '" + n + "' OR videojoc = '" + n + "';";
    pqxx::result q = txn.exec(comanda); // Executa la consulta SQL.
    txn.commit(); // Confirma la transacció.
    for (auto fila : q) {
        // Afegeix a la llista els continguts trobats.
        res.emplace_back(fila[1].c_str(), fila[0].c_str());
    }
    return res; // Retorna els continguts trobats.
}
