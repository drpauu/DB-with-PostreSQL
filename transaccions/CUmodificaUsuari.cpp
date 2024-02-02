#include "CUmodificaUsuari.h"

// Constructora: Inicialitza l'objecte sense estat específic.
CUmodificaUsuari::CUmodificaUsuari() {}

// Destructora: Neteja recursos si és necessari.
CUmodificaUsuari::~CUmodificaUsuari() {}

// consultaUsuari: Retorna informació de l'usuari actualment logejat.
// Pre: Cap
// Post: Retorna un objecte amb les dades de l'usuari logejat.
TXconsultarUsuari::res CUmodificaUsuari::consultaUsuari() {
    TXconsultarUsuari op;
    op.executar();
    return op.obteResultat(); // Retorna les dades de l'usuari logejat.
}

// modificaUsuari: Modifica les dades de l'usuari logejat.
// Pre: Requereix nom, contrasenya, correu electrònic i data de naixement.
// Post: Actualitza les dades de l'usuari logejat a la videoconsola.
void CUmodificaUsuari::modificaUsuari(string nomU, string contraU, string correuU, string naixU) {
    Videoconsola& vid = Videoconsola::getInstance();
    vid.refrescaUsuari(nomU, contraU, correuU, naixU); // Actualitza les dades de l'usuari a la videoconsola i la BD.
}
