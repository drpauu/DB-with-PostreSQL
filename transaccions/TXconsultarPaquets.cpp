#include "TXconsultarPaquets.h"

// Constructora
TXconsultarPaquets::TXconsultarPaquets() {
}

// Destructora
TXconsultarPaquets::~TXconsultarPaquets() {
}

// executar: Realitza la consulta de tots els paquets
// Pre: Cap
// Post: 'resultat' conté informació de tots els paquets i l'estalvi que representen
void TXconsultarPaquets::executar(){
	cercadoraElementCompra el = cercadoraElementCompra();
	cercadoraPaquetVideojocs pa = cercadoraPaquetVideojocs();
	vector<passarelaElementCompra> paquets = el.totsPaquets(); // Obté tots els paquets
	for (auto& paquet : paquets) {
		res r;
		r.nom = paquet.getNom();
		r.desc = paquet.getDescripcio();
		r.preu = paquet.getPreu();
		r.estalvi = pa.preuJocs(paquet.getNom())- r.preu;
		resultat.push_back(r);
    }
}

// obteResultat: Retorna llista de paquets consultats
// Pre: 'executar' ha estat cridat
// Post: Retorna 'resultat' amb la llista de paquets i l'estalvi de cada un
vector<TXconsultarPaquets::res> TXconsultarPaquets::obteResultat() {
    return resultat;
}
