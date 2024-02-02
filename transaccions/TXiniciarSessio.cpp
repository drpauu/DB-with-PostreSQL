#include "TXiniciarSessio.h"

// Constructora
TXiniciarSessio::TXiniciarSessio(string sn, string cs) {
    sobrenom = sn;
    contrasenya = cs;
    resultat = false;
}

// Destructora
TXiniciarSessio::~TXiniciarSessio() {
}

// executar: Realitza la funció d'iniciar sessió.
// Pre: 'sobrenom' i 'contrasenya' han estat inicialitzades.
// Post: Si l'usuari i contrasenya són correctes, inicia la sessió, altrament llança excepció.
void TXiniciarSessio::executar(){
    cercadoraUsuari us = cercadoraUsuari();
    passarelaUsuari pus = us.cercaPerSobrenom(sobrenom);
    if(pus.getContrasenya() == contrasenya){
        resultat = true;
        Videoconsola& vid = Videoconsola::getInstance();
        vid.iniciarSessio(pus);
    }else throw exception("Usuari o contrasenya incorrecta");
}

// obteResultat: Retorna el resultat de l'operació.
// Pre: 'executar' ha estat cridat.
// Post: Retorna 'resultat', indicant si la sessió s'ha iniciat amb èxit.
bool TXiniciarSessio::obteResultat(){
    return resultat;
}