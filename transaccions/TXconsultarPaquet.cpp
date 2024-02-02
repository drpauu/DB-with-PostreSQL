#include "TXconsultarPaquet.h"

// Constructora: Inicialitza el nom del paquet a consultar
TXconsultarPaquet::TXconsultarPaquet(string nom) : n(nom) {
    resultat = res(); // Prepara objecte resultat per emmagatzemar les dades trobades
}

// Destructora
TXconsultarPaquet::~TXconsultarPaquet() {
}

// executar: Realitza la consulta del paquet
// Pre: n conté el nom del paquet
// Post: resultat conté informació del paquet i els seus videojocs
void TXconsultarPaquet::executar(){
	cercadoraElementCompra el = cercadoraElementCompra();
	passarelaElementCompra pel = el.cercaPerNom(n);
	cercadoraPaquetVideojocs pa = cercadoraPaquetVideojocs();
	passarelaPaquetVideojocs ppa = pa.cercaPerNom(n);
	cercadoraConte co = cercadoraConte();
	vector<passarelaConte> pco = co.cerca(n);
	resultat.nom = ppa.getNom();
	resultat.desc = pel.getDescripcio();
	resultat.preu = pel.getPreu();
	double total = 0;
	for (int i = 0; i < pco.size(); i++) {
		passarelaElementCompra pvid = el.cercaPerNom(pco[i].getVideojoc());
		resultat.vnoms.push_back(pvid.getNom());
		resultat.vdescs.push_back(pvid.getDescripcio());
		resultat.vpreus.push_back(pvid.getPreu());
	}
	resultat.estalvi = pa.preuJocs(n) - resultat.preu;
}

// obteResultat: Retorna informació del paquet consultat
// Pre: 'executar' ha estat cridat
// Post: Retorna resultat amb les dades del paquet i els seus videojocs
TXconsultarPaquet::res TXconsultarPaquet::obteResultat() {
    return resultat;
}
