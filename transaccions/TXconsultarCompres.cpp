#include "TXconsultarCompres.h"

// Constructor
TXconsultarCompres::TXconsultarCompres() {
}

// Destructor
TXconsultarCompres::~TXconsultarCompres() {
}

// executar: Realitza la consulta de compres d'un usuari.
// Pre: cap
// Post: Emplena 'resultat' amb les compres realitzades per l'usuari.
void TXconsultarCompres::executar() {
    //Crea les cercadores
    cercadoraCompra comp = cercadoraCompra();
    cercadoraElementCompra el = cercadoraElementCompra();

    //Obté l'usuari a partir de la videoconsola
    Videoconsola& consola = Videoconsola::getInstance();
    passarelaUsuari usuari = consola.getUsuari();

    //Obté totes les compres fetes per l'usuari logejat
    vector<passarelaCompra> compres = comp.cercaPerUsuari(usuari.getSobrenom());

    //Inicialitza valors
    resultat.total = 0; resultat.paquets = 0; resultat.videojocs = 0;

    // Processa cada compra, incloent informació dels videojocs i paquets.
    for (auto& compra : compres) {
        element e = element();
        e.nom = compra.getElement();
        passarelaElementCompra pel = el.cercaPerNom(e.nom);
        //Si el preu de compra és el mateix que el preu de l'element, vol dir que si és un videojoc, no es va comprar dins de cap paquet
        if (pel.getPreu() == compra.getPreu()) {
            e.desc = pel.getDescripcio();
            e.tipus = pel.getTipus();
            e.preu = compra.getPreu();
            e.data = compra.getData();
            //Si l'element és un paquet, cerca la llista de tots els videojocs que conté
            if (e.tipus == "paquet") {
                resultat.paquets++; //Actualitzar comptador de paquets
                cercadoraConte con = cercadoraConte();
                vector<passarelaConte> videojocs = con.cerca(e.nom);
                for (auto& vids : videojocs) {
                    for (auto& com : compres) {
                        if (com.getElement() == vids.getVideojoc() && com.getPreu() != pel.getPreu()) break;
                        else if (com.getElement() == vids.getVideojoc() && com.getPreu() == pel.getPreu()) {
                            resultat.videojocs++; //Actualitzar comptador de videojocs
                            passarelaElementCompra videojoc = el.cercaPerNom(vids.getVideojoc());
                            e.nomv.push_back(videojoc.getNom());
                            e.descv.push_back(videojoc.getDescripcio());
                            break;
                        }
                    }
                }
            }
            else resultat.videojocs++; //Actualitzar comptador de videojocs
            resultat.total += e.preu;
            resultat.elements.push_back(e);
        }
    }
}

// obteResultat: Retorna el resultat de la consulta.
// Pre: 'executar' ha estat cridat.
// Post: Retorna les dades de les compres realitzades.
TXconsultarCompres::res TXconsultarCompres::obteResultat() {
    return resultat;
}
