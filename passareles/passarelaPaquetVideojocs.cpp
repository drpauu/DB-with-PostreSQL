#include "passarelaPaquetVideojocs.h"

// Constructora: Inicialitza l'objecte passarelaPaquetVideojocs amb el nom del paquet.
passarelaPaquetVideojocs::passarelaPaquetVideojocs(string n) {
    nom = n; // Assigna el nom del paquet de videojocs.
}

// Destructora: Neteja recursos si és necessari.
passarelaPaquetVideojocs::~passarelaPaquetVideojocs() {}

// Getter: Retorna el nom del paquet de videojocs.
string passarelaPaquetVideojocs::getNom() { return nom; }// Retorna el nom assignat al paquet 

// Setters: No es defineixen ja que l'objecte representa dades fixes d'un paquet de videojocs.
// No són necessàries operacions addicionals amb la base de dades ja que l'usuari no pot modificar el catàleg de la botiga.
