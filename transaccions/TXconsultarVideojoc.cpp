#include "TXconsultarVideojoc.h"

// Constructora: Assigna el nom del videojoc a consultar.
TXconsultarVideojoc::TXconsultarVideojoc(string n) {
    nomV = n;
    resultat = res();
}
// Destructora: Accions de neteja si són necessàries.
TXconsultarVideojoc::~TXconsultarVideojoc() {}

// executar: Realitza la consulta del videojoc a la base de dades.
// Pre: 'nomV' ha estat inicialitzat.
// Post: 'resultat' conté les dades del videojoc consultat.
void TXconsultarVideojoc::executar() {
    cercadoraElementCompra el;
    passarelaElementCompra pel = el.cercaPerNom(nomV);
    cercadoraVideojoc vid;
    passarelaVideojoc pvid = vid.cercaPerNom(nomV);
    cercadoraConte con;
    vector<passarelaConte> pcon = con.cerca(nomV);

    // Emplena el resultat amb les dades del videojoc.
    resultat.nom = pel.getNom();
    resultat.desc = pel.getDescripcio();
    resultat.preu = pel.getPreu();
    resultat.genere = pvid.getGenere();
    resultat.data = pvid.getDataLlan();
    resultat.qualificacio = pvid.getQualificacio();
    for (auto &conte : pcon) {
        resultat.paquets.push_back(conte.getPaquet());
    }
}

// obteResultat: Retorna el resultat de la consulta.
// Pre: 'executar' ha estat cridat.
// Post: Retorna 'resultat' amb les dades del videojoc consultat.
TXconsultarVideojoc::res TXconsultarVideojoc::obteResultat() {
    return resultat; // Retorna l'objecte 'resultat' amb les dades del videojoc.
}
