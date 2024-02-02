#include "passarelaVideojoc.h"

// Constructora: Inicialitza passarelaVideojoc amb els paràmetres donats.
passarelaVideojoc::passarelaVideojoc(string n, int q, string data, string g, int mins) {
    nom = n;           // Assigna el nom del videojoc.
    qualificacio = q;  // Assigna la qualificació per edat.
    dataLlan = data;   // Assigna la data de llançament.
    genere = g;        // Assigna el gènere del videojoc.
    minsEstimat = mins; // Assigna el temps estimat de joc en minuts.
}

// Destructora: Neteja qualsevol recurs si és necessari.
passarelaVideojoc::~passarelaVideojoc() {}

// Getters: Funcions per obtenir les propietats de l'objecte.
string passarelaVideojoc::getNom() { return nom; }
string passarelaVideojoc::getDataLlan() { return dataLlan; }
string passarelaVideojoc::getGenere() { return genere; }
int passarelaVideojoc::getQualificacio() { return qualificacio; }
int passarelaVideojoc::getMinsEstimat() { return minsEstimat; }

// Setters: No es defineixen ja que l'objecte representa dades fixes d'un videojoc.
// No són necessàries operacions addicionals amb la base de dades.