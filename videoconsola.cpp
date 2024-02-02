#include "videoconsola.h"

Videoconsola& Videoconsola::getInstance() {
	static Videoconsola instance;
	return instance;
}

//Getter
passarelaUsuari Videoconsola::getUsuari(){
	return usuari;
}

//Setters
void Videoconsola::iniciarSessio(passarelaUsuari pus){
	usuari = pus;
}

void Videoconsola::tancarSessio(){

}

void Videoconsola::refrescaUsuari(string nom, string contrasenya, string correu, string data) {
	string correuAnt = usuari.getCorreu();
	try {
		usuari.setNom(nom);
		usuari.setContrasenya(contrasenya);
		usuari.setCorreu(correu);
		usuari.setDataN(data);
		usuari.modifica();
	}
	catch (...) {
		usuari.setCorreu(correuAnt);
		if (correuAnt != correu) throw exception("Correu ja registrat.");

	}
}