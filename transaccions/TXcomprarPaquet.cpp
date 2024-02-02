#include "TXcomprarPaquet.h"

// Constructor: Inicialitza la transacció amb el nom del paquet.
TXcomprarPaquet::TXcomprarPaquet(string nom) : nomPaquet(nom) {
}

// Destructor: No realitza cap acció específica.
TXcomprarPaquet::~TXcomprarPaquet() {
}

// executar: Realitza la lògica per comprar un paquet.
// Pre: cap
// Post: La compra del paquet s'ha realitzat, o s'ha llançat una excepció si ja s'ha comprat anteriorment.
void TXcomprarPaquet::executar() {
    //Crea les cercadores
    cercadoraElementCompra cercadorEl = cercadoraElementCompra();
    cercadoraPaquetVideojocs cercadorPa = cercadoraPaquetVideojocs();
    cercadoraConte cercadorCon = cercadoraConte();

    //Obté l'usuari a partir de la videoconsola
    Videoconsola& v = Videoconsola::getInstance();
    passarelaUsuari usuari = v.getUsuari();

    //Cerca tota la informació relativa al paquet
    passarelaElementCompra el = cercadorEl.cercaPerNom(nomPaquet);
    passarelaPaquetVideojocs pa = cercadorPa.cercaPerNom(nomPaquet);
    vector<passarelaConte> pcon = cercadorCon.cerca(nomPaquet);

    //Obté la data actual
    time_t ara = time(0);
    struct tm temps;
    localtime_s(&temps, &ara);
    string data = to_string(temps.tm_year + 1900) + "-" + to_string(temps.tm_mon + 1) + "-" + to_string(temps.tm_mday);

    // Realitza la compra dels videojocs inclosos en el paquet i del mateix paquet.
    try {
        passarelaCompra compra = passarelaCompra(usuari.getSobrenom(), nomPaquet, data, el.getPreu());
        compra.insereix();
    }
    catch (...) {
        // Si insereix llença una excepció, vol dir que el paquet ja ha sigut comprat
        throw exception("Ja s'ha comprat el paquet.");
    }
    for (auto& conte : pcon) {
        try {
            passarelaCompra vid = passarelaCompra(usuari.getSobrenom(), conte.getVideojoc(), data, el.getPreu());
            vid.insereix();
        }
        catch (...) {
            // Si l'usuari ja ha comprat el videojoc anteriorment, ignora l'excepció.
        }
    }
    resultat = data; // Estableix la data de la compra com a resultat.
}

// obteResultat: Retorna la data de la compra.
// Pre: 'executar' ha estat cridat.
// Post: Retorna la data en què s'ha realitzat la compra.
string TXcomprarPaquet::obteResultat() {
    return resultat;
}
