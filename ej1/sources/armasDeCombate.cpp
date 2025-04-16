#include "armasDeCombate.hpp"
#include <iostream>
using namespace std;

/* Implementacion HachaSimple */

// Constructor
HachaSimple::HachaSimple( string material, int peso_gr, bool conGema) : ArmasDeCombate("Hacha Simple", material, peso_gr), conGema(conGema) {};

// Metodos
bool HachaSimple::usar() {
    cout << "Usando el hacha simple..." << endl;

    if (conGema) {
        danio += 5;
    }

    return true;
};

void HachaSimple::showInfo() {
    cout << "Nombre: " << nombre << endl;
    cout << "Material: " << material << endl;
    cout << "Peso: " << peso_gr << endl;
    cout << "Daño: " << danio << endl;
    cout << "Con gema: " << (conGema ? "Si" : "No") << endl;
};

/* Implementacion HachaDoble */

// Constructor
HachaDoble::HachaDoble( string material, int peso_gr, int largo_cm, bool filoExtra) : ArmasDeCombate("Hacha Doble", material, peso_gr), largo_cm(largo_cm), filoExtra(filoExtra) {};

// Metodos
bool HachaDoble::usar() {
    cout << "Usando el hacha doble..." << endl;

    if (largo_cm > 30 && filoExtra) {
        danio += 8;
    }

    return true;
};

void HachaDoble::showInfo() {
    cout << "Nombre: " << nombre << endl;
    cout << "Material: " << material << endl;
    cout << "Peso: " << peso_gr << endl;
    cout << "Daño: " << danio << endl;
    cout << "Largo: " << largo_cm << "cm" << endl;
    cout << "Tiene filo extra: " << (filoExtra ? "Si" : "No") << endl;
};

/* Implementacion Espada */

// Constructor
Espada::Espada(string material, int peso_gr, int largo_cm, bool tieneBrillo) : ArmasDeCombate("Espada", material, peso_gr), largo_cm(largo_cm), tieneBrillo(tieneBrillo) {};

// Metodos
bool Espada::usar() {
    cout << "Usando la espada..." << endl;

    if (largo_cm > 30 && tieneBrillo) {
        danio += 5;
    }

    return true;
};

void Espada::showInfo() {
    cout << "Nombre: " << nombre << endl;
    cout << "Material: " << material << endl;
    cout << "Peso: " << peso_gr << endl;
    cout << "Daño: " << danio << endl;
    cout << "Largo: " << largo_cm << "cm" << endl;
    cout << "Tiene brillo: " << (tieneBrillo ? "Si" : "No") << endl;
};

/* Implementacion Lanza */

// Constructor
Lanza::Lanza(string material, int peso_gr, int largo_cm, int cantidadPuntas) : ArmasDeCombate("Lanza", material, peso_gr), largo_cm(largo_cm), cantidadPuntas(cantidadPuntas) {};

// Metodos
bool Lanza::usar() {
    cout << "Usando la lanza..." << endl;

    if (largo_cm > 50 && cantidadPuntas >= 2) {
        danio += 9;
    }
    
    return true;
};

void Lanza::showInfo() {
    cout << "Lanza: " << nombre << endl;
    cout << "Material: " << material << endl;
    cout << "Peso: " << peso_gr << endl;
    cout << "Daño: " << danio << endl;
    cout << "Largo: " << largo_cm << "cm" << endl;
    cout << "Cantidad de puntas: " << cantidadPuntas << endl;
};

/* Implementacion Garrote */

// Constructor
Garrote::Garrote(string material, int peso_gr, bool tienePicos, bool doblePunta) : ArmasDeCombate("Garrote", material, peso_gr), tienePicos(tienePicos), doblePunta(doblePunta) {};

// Metodos
bool Garrote::usar() {
    cout << "Usando el garrote..." << endl;

    if (tienePicos && doblePunta) {
        danio += 10;
    }

    return true;
};

void Garrote::showInfo() {
    cout << "Garrote: " << nombre << endl;
    cout << "Material: " << material << endl;
    cout << "Peso: " << peso_gr << endl;
    cout << "Daño: " << danio << endl;
    cout << "Tiene picos: " << (tienePicos ? "Si" : "No") << endl;
    cout << "Tiene doble punta: " << (doblePunta ? "Si" : "No") << endl;
};