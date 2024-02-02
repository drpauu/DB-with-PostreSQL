#include "passarelaElementCompra.h"

// Constructora: Inicialitza l'objecte amb les dades de l'element de compra.
passarelaElementCompra::passarelaElementCompra(string n, string desc, double p, string t) {
    nom = n; // Assigna el nom de l'element de compra.
    descripcio = desc; // Assigna la descripció de l'element.
    preu = p; // Assigna el preu de l'element.
    tipus = t; // Assigna el tipus de l'element (ex: videojoc, paquet).
}

// Destructora: Neteja recursos si és necessari.
passarelaElementCompra::~passarelaElementCompra() {}

// Getters: Mètodes per obtenir les dades de l'element.
string passarelaElementCompra::getNom() {
    return nom; // Retorna el nom de l'element.
}

string passarelaElementCompra::getDescripcio() {
    return descripcio; // Retorna la descripció de l'element.
}

double passarelaElementCompra::getPreu() {
    return preu; // Retorna el preu de l'element.
}

string passarelaElementCompra::getTipus() {
    return tipus; // Retorna el tipus de l'element.
}

// Setters: No es defineixen ja que les dades de l'element són fixes i no modificables per l'usuari.
// Operacions amb la base de dades: No són necessàries ja que l'usuari no pot modificar el catàleg de la botiga.
