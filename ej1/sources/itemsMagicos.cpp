#include "itemsMagicos.hpp"
#include <iostream>
using namespace std;

/* Implementacion Baston */

// Constructor
Baston::Baston(int durabilidad, double largo) : ItemsMagicos("Baston", durabilidad), largo(largo) {};

// Metodos
void Baston::usar() {
    if (durabilidad <= 0) {
        cout << "El baston se ha agotado." << endl;
        return;
    }

    cout << "Usando el baston..." << endl;
    durabilidad--;
};

void Baston::showInfo() {
    cout << "Nombre: " << nombre << endl;
    cout << "Daño: " << danio << endl;
    cout << "Durabilidad: " << durabilidad << endl;
    cout << "Largo: " << largo << endl;
};  


/* Implementacion LibroDeHechizos */

// Constructor
LibroDeHechizos::LibroDeHechizos(int durabilidad) : ItemsMagicos("LibroDeHechizos", durabilidad) {};

// Metodos
void LibroDeHechizos::usar() {
    if (durabilidad <= 0) {
        cout << "El libro de hechizos ya no sirve." << endl;
        return;
    }

    cout << "Usando el libro de hechizos..." << endl;
    durabilidad--;
};

void LibroDeHechizos::showInfo() {
    cout << "Nombre: " << nombre << endl;
    cout << "Daño: " << danio << endl;
    cout << "Durabilidad: " << durabilidad << endl;
    cout << "Tiene baston asociado: " << (conBaston ? "Si" : "No") << endl;
    cout << "Lista de hechizos: " << endl;
    for (int i = 0; i < listaHechizos.size(); i++) {
        cout << " - " << listaHechizos[i] << endl;
    }
};

void LibroDeHechizos::setConBaston(bool cond) {
    conBaston = cond;
};

void LibroDeHechizos::agregarHechizo(string hechizo) {
    listaHechizos.push_back(hechizo);
};

/* Implementacion Pocion */

// Constructor
Pocion::Pocion(int durabilidad, string efecto, bool esParmanente) : ItemsMagicos("Pocion", durabilidad), efecto(efecto), esPermanente(esParmanente) {};

// Metodos
void Pocion::usar() {
    if (durabilidad <= 0) {
        cout << "La pocion se ha agotado." << endl;
        return;
    }

    cout << "Usando la pocion..." << endl;
    durabilidad--;
};

void Pocion::showInfo() {
    cout << "Nombre: " << nombre << endl;
    cout << "Daño: " << danio << endl;
    cout << "Durabilidad: " << durabilidad << endl;
    cout << "Efecto: " << efecto << endl;
    cout << "Es permanente: " << (esPermanente ? "Si" : "No") << endl;
};


/* Implementacion Amuleto */

// Constructor
Amuleto::Amuleto(int durabilidad, bool bonoSurte) : ItemsMagicos("Amuleto", durabilidad), bonoSuerte(bonoSurte) {};

// Metodos
void Amuleto::usar() { // se usa en defensa
    if (durabilidad <= 0) {
        cout << "El amuleto ya no sirve." << endl;
        return;
    }

    cout << "Usando el amuleto..." << endl;
    durabilidad--;
};

void Amuleto::showInfo() {
    cout << "Nombre: " << nombre << endl;
    cout << "Daño: " << danio << endl;
    cout << "Durabilidad: " << durabilidad << endl;
    cout << "Bono de suerte: " << (bonoSuerte ? "Si" : "No") << endl;
};
