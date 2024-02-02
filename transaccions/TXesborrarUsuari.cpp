#include "TXesborrarUsuari.h"

// Constructora
TXesborrarUsuari::TXesborrarUsuari(string c) : contrasenya(c), result(true) {
}

// Destructora
TXesborrarUsuari::~TXesborrarUsuari() {
}

// executar: Realitza l'acció d'esborrar l'usuari actual
// Pre: 'contrasenya' ha estat inicialitzada
// Post: Si la contrasenya és correcta, esborra l'usuari i tanca la sessió
void TXesborrarUsuari::executar() {
    Videoconsola& vid = Videoconsola::getInstance();
    passarelaUsuari usuari = vid.getUsuari();

    if (usuari.getContrasenya() == contrasenya) {
        usuari.esborra(); // Esborra l'usuari
        result = false;
        vid.tancarSessio(); // Tanca la sessió
    } else {
        throw exception("Contrasenya incorrecta");
    }
}

// obteResultat: Retorna si l'acció ha estat exitosa
// Pre: 'executar' ha estat cridat
// Post: Retorna 'result' amb l'èxit de l'acció
bool TXesborrarUsuari::obteResultat() {
    return result;
}
