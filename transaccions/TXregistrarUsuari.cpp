#include "TXregistrarUsuari.h"

// Constructora: Inicialitza les dades d'un nou usuari.
TXregistrarUsuari::TXregistrarUsuari(string n, string sn, string c, string correu, string data) 
    : nom(n), sobrenom(sn), constrasenya(c), correuE(correu), dataN(data) {
}

// Destructora
TXregistrarUsuari::~TXregistrarUsuari() {
}

// executar: Realitza la funció de registrar un nou usuari.
// Pre: Totes les dades de l'usuari són inicialitzades.
// Post: Registra l'usuari si no existeix, altrament llança excepció.
void TXregistrarUsuari::executar(){
    passarelaUsuari pus(nom, sobrenom, constrasenya, correuE, dataN);
    cercadoraUsuari find_us = cercadoraUsuari();
    try {
        find_us.cercaPerSobrenom(sobrenom);
    }
    catch (...) {
        try {
            pus.insereix();
            return;
        }
        catch (...) {
            throw exception("Correu ja registrat.");
        }
    }
    throw exception("L'usuari ja existeix.");
}
