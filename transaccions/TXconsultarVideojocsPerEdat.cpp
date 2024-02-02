#include "TXconsultarVideojocsPerEdat.h"

// Constructora
TXconsultarVideojocsPerEdat::TXconsultarVideojocsPerEdat(int e) : edat(e) {
}

// Destructora
TXconsultarVideojocsPerEdat::~TXconsultarVideojocsPerEdat() {
}

// executar: Consulta els videojocs adequats per una edat específica
// Pre: 'edat' ha estat inicialitzada
// Post: 'resultat' conté la llista de videojocs adequats per l'edat especificada
void TXconsultarVideojocsPerEdat::executar(){
    cercadoraVideojoc vid = cercadoraVideojoc();
    vector<passarelaVideojoc> pvid = vid.cercaPerEdat(edat); // Cerca videojocs segons edat

    for (auto &videojoc : pvid) {
        cercadoraElementCompra el = cercadoraElementCompra();
        passarelaElementCompra pel = el.cercaPerNom(videojoc.getNom());
        cercadoraConte con = cercadoraConte();
        vector<passarelaConte> pcon = con.cerca(videojoc.getNom()); // Cerca paquets on es troba el videojoc

        res r; // Objecte per emmagatzemar dades del videojoc
        r.nom = pel.getNom();
        r.desc = pel.getDescripcio();
        r.preu = pel.getPreu();
        r.genere = videojoc.getGenere();
        r.data = videojoc.getDataLlan();
        r.qualificacio = videojoc.getQualificacio();
        for (auto &paquet : pcon) r.paquets.push_back(paquet.getPaquet()); // Afegeix paquets on està inclòs
        resultat.push_back(r); // Afegeix a la llista de resultats
    }
}

// obteResultat: Retorna llista de videojocs consultats per edat
// Pre: 'executar' ha estat cridat
// Post: Retorna 'resultat' amb la llista de videojocs
vector<TXconsultarVideojocsPerEdat::res> TXconsultarVideojocsPerEdat::obteResultat() {
    return resultat;
}
