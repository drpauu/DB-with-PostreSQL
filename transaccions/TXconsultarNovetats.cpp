#include "TXconsultarNovetats.h"

// Constructor: Inicialitza la data de consulta per a les novetats
TXconsultarNovetats::TXconsultarNovetats(string d) {
    data = d;
}

// Destructor
TXconsultarNovetats::~TXconsultarNovetats() {
}

// executar: Realitza la consulta de les novetats des de la data especificada
// Pre: data ha estat inicialitzada
// Post: resultat conté les novetats trobades des de la data especificada
void TXconsultarNovetats::executar() {
    cercadoraElementCompra el = cercadoraElementCompra();
    cercadoraVideojoc vid = cercadoraVideojoc();
    cercadoraConte co = cercadoraConte();
    vector<passarelaVideojoc> novetats = vid.cercaNovetats(data);
    for (auto& novetat : novetats) {
        passarelaElementCompra pel = el.cercaPerNom(novetat.getNom());
        vector<passarelaConte> pco = co.cerca(novetat.getNom());
        res r = res();
        r.nom = pel.getNom();
        r.desc = pel.getDescripcio();
        r.preu = pel.getPreu();
        r.qualificacio = novetat.getQualificacio();
        r.data = novetat.getDataLlan();
        for (auto& conte : pco) {
            r.paquets.push_back(conte.getPaquet());
        }
        resultat.push_back(r);
    }
}

// obteResultat: Retorna les novetats trobades
// Pre: 'executar' ha estat cridat
// Post: Retorna un vector amb les novetats des de la data especificada
vector<TXconsultarNovetats::res> TXconsultarNovetats::obteResultat() {
    return resultat;
}
