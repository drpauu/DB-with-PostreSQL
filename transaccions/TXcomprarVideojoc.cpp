#include "TXcomprarVideojoc.h"

//Constructora
TXcomprarVideojoc::TXcomprarVideojoc(string n) {
    nom = n;
}

//Destructora
TXcomprarVideojoc::~TXcomprarVideojoc() {
    
}

//executar: Crida per executar
void TXcomprarVideojoc::executar() {
    //Crea les cercadores
    cercadoraElementCompra cercadorEl = cercadoraElementCompra();
    cercadoraVideojoc cercadorVid = cercadoraVideojoc();

    Videoconsola& consola = Videoconsola::getInstance();
    passarelaUsuari usuari = consola.getUsuari(); //Obté l'usuari a partir de la videoconsola.

    //Crear les passareles d'elementCompra i videojoc.
    passarelaVideojoc pvid = cercadorVid.cercaPerNom(nom);
    passarelaElementCompra pel = cercadorEl.cercaPerNom(nom);

    //Obtenir data de naixement de l'usuari.
    string dataN = usuari.getDataN();

    //Calcular edat de l'usuari.
    char delimiter;
    istringstream data_str(dataN);
    int dia, mes, any;
    data_str >> any >> delimiter >> mes >> delimiter >> dia;
    struct tm dataNaix;
    dataNaix.tm_year = any - 1900; dataNaix.tm_mon = mes - 1; dataNaix.tm_mday = dia;
    dataNaix.tm_hour = 0; dataNaix.tm_min = 0; dataNaix.tm_sec = 0;
    time_t ara = time(0);
    struct tm temps;
    localtime_s(&temps, &ara);
    string data = to_string(temps.tm_year + 1900) + "-" + to_string(temps.tm_mon + 1) + "-" + to_string(temps.tm_mday);

    //Obtenir segons de diferencia entre el dia de naixement de l'usuari i el dia actual.
    double segons = difftime(mktime(&temps), mktime(&dataNaix));

    //Obtenir edat en anys
    int anys = (int)segons / 31536000;
    
    //Comprovar si l'usuari te suficient edat per comprar el videojoc.
    if (pvid.getQualificacio() > anys) throw exception("No tens suficient edat.");
    passarelaCompra compra = passarelaCompra(usuari.getSobrenom(), nom, data, pel.getPreu());
    try {
        compra.insereix();
    }
    catch (...) {
        //Si es rep una excepcio a la hora d'inserir, vol dir que l'usuari ja ha comprat el videojoc anteriorment.
        throw exception("Ja s'ha comprat el videojoc.");
    }
    //Guarda la data de compra al resultat
    resultat.data = data;
    //Busca tots els paquets on esta el videojoc adquirit
    cercadoraConte con = cercadoraConte();
    vector<passarelaConte> conv = con.cerca(nom);
    for (auto& conte : conv) {
        //Busca tots els videojocs que conte cada paquet
        vector<passarelaConte> conp = con.cerca(conte.getPaquet());
        for (auto& conteP : conp) {
            if (conteP.getVideojoc() != nom) {
                bool trobat = false;
                passarelaElementCompra r = cercadorEl.cercaPerNom(conteP.getVideojoc());
                recomanacio re = recomanacio();
                re.nom = r.getNom();
                re.desc = r.getDescripcio();
                re.preu = r.getPreu();
                for (int i = 0; !trobat && i < resultat.recomanats.size(); i++) trobat = (resultat.recomanats[i].nom == re.nom);
                //Si el videojoc no es el videojoc aquirit i encara no s'ha afegit a la llista de recomantas, l'afegeix
                if(!trobat) resultat.recomanats.push_back(re);
            }
        }
    }
}

//obteResultat: Crida per retornar el resultat.
TXcomprarVideojoc::res TXcomprarVideojoc::obteResultat() {
    return resultat; //Retorna el resultat.
}
