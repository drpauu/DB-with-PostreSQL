#include "TXtancarSessio.h"

// Constructor: Inicialitza 'resultat' a true.
TXtancarSessio::TXtancarSessio() {
	resultat = true;
}

// Destructor: No realitza cap acció específica.
TXtancarSessio::~TXtancarSessio() {

}

// executar: Realitza la lògica per tancar la sessió.
// Pre: cap
// Post: Si la sessió s'ha tancat correctament, 'resultat' és false.
void TXtancarSessio::executar(){
	Videoconsola& vid = Videoconsola::getInstance();
	vid.tancarSessio(); // Tancament de la sessió.
	resultat = false; // Actualització de l'estat a false per indicar el tancament.
}

// obteResultat: Retorna l'estat de la transacció.
// Pre: 'executar' ha estat cridat.
// Post: Retorna true si la sessió encara està activa, false si s'ha tancat.
bool TXtancarSessio::obteResultat(){
	return resultat;
}
