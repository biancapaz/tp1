#include "armasDeCombate.hpp"
#include <iostream>
using namespace std;

/* Implementacion HachaSimple */

// Constructor
HachaSimple::HachaSimple( string material, double peso, bool conGema) : ArmasDeCombate("Hacha Simple", material, peso), conGema(conGema) {};

// Metodos
void HachaSimple::usar() {
    cout << "Usando el hacha simple..." << endl;
};

void HachaSimple::showInfo() {
    cout << "Nombre: " << nombre << endl;
    cout << "Material: " << material << endl;
    cout << "Peso: " << peso << endl;
    cout << "Daño: " << danio << endl;
    cout << "Con gema: " << (conGema ? "Si" : "No") << endl;
};

/* Implementacion HachaDoble */

// Constructor
HachaDoble::HachaDoble( string material, double peso, double largo, bool filoExtra) : ArmasDeCombate("Hacha Doble", material, peso), largo(largo), filoExtra(filoExtra) {};

// Metodos
void HachaDoble::usar() {
    cout << "Usando el hacha doble..." << endl;
};

void HachaDoble::showInfo() {
    cout << "Nombre: " << nombre << endl;
    cout << "Material: " << material << endl;
    cout << "Peso: " << peso << endl;
    cout << "Daño: " << danio << endl;
    cout << "Largo: " << largo << "cm" << endl;
    cout << "Tiene filo extra: " << (filoExtra ? "Si" : "No") << endl;
};

/* Implementacion Espada */

// Constructor
Espada::Espada(string material, double peso, double largo, bool tieneBrillo) : ArmasDeCombate("Espada", material, peso), largo(largo), tieneBrillo(tieneBrillo) {};

// Metodos
void Espada::usar() {
    cout << "Usando la espada..." << endl;
};

void Espada::showInfo() {
    cout << "Nombre: " << nombre << endl;
    cout << "Material: " << material << endl;
    cout << "Peso: " << peso << endl;
    cout << "Daño: " << danio << endl;
    cout << "Largo: " << largo << "cm" << endl;
    cout << "Tiene brillo: " << (tieneBrillo ? "Si" : "No") << endl;
};

/* Implementacion Lanza */

// Constructor
Lanza::Lanza(string material, double peso, int largo, int cantidadPuntas) : ArmasDeCombate("Lanza", material, peso), largo(largo), cantidadPuntas(cantidadPuntas) {};

// Metodos
void Lanza::usar() {
    cout << "Usando la lanza..." << endl;
};

void Lanza::showInfo() {
    cout << "Lanza: " << nombre << endl;
    cout << "Material: " << material << endl;
    cout << "Peso: " << peso << endl;
    cout << "Daño: " << danio << endl;
    cout << "Largo: " << largo << "cm" << endl;
    cout << "Cantidad de puntas: " << cantidadPuntas << endl;
};

/* Implementacion Garrote */

// Constructor
Garrote::Garrote(string material, double peso, bool tienePicos, bool doblePunta) : ArmasDeCombate("Garrote", material, peso), tienePicos(tienePicos), doblePunta(doblePunta) {};

// Metodos
void Garrote::usar() {
    cout << "Usando el garrote..." << endl;
};

void Garrote::showInfo() {
    cout << "Garrote: " << nombre << endl;
    cout << "Material: " << material << endl;
    cout << "Peso: " << peso << endl;
    cout << "Daño: " << danio << endl;
    cout << "Tiene picos: " << (tienePicos ? "Si" : "No") << endl;
    cout << "Tiene doble punta: " << (doblePunta ? "Si" : "No") << endl;
};