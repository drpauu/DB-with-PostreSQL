#include "TXconsultarUsuari.h"

//Constructora
TXconsultarUsuari::TXconsultarUsuari() {
    
}

//Destructora
TXconsultarUsuari::~TXconsultarUsuari() {
    
}

//executar: Crida per executar.
void TXconsultarUsuari::executar() {
    Videoconsola& vid = Videoconsola::getInstance();
    passarelaUsuari usuari = vid.getUsuari(); //Obte l'usuari a partir de la videoconsola.
    
    //Emplena la informacio del resultat amb l'usuari.
    resultat.nom = usuari.getNom();
    resultat.sobrenom = usuari.getSobrenom();
    resultat.correu = usuari.getCorreu();
    resultat.dataN = usuari.getDataN();
    resultat.contrasenya = usuari.getContrasenya();
}

//obteResultat: Crida per retornar el resultat.
TXconsultarUsuari::res TXconsultarUsuari::obteResultat() {
    return resultat; //Retorna el resultat
}
