#include "itemsMagicos.hpp"
#include <iostream>
using namespace std;

/* Implementacion Baston */

// Constructor
Baston::Baston(int durabilidad, int largo_cm) : ItemsMagicos("Baston", durabilidad), largo_cm(largo_cm) {};

// Metodos
bool Baston::usar() {
    if (durabilidad <= 0) {
        cout << "El baston ya no funciona." << endl;
        return false;
    }

    cout << "Usando el baston..." << endl;
    durabilidad--;

    return true;
};

void Baston::showInfo() {
    cout << "Nombre: " << nombre << endl;
    cout << "Daño: " << danio << endl;
    cout << "Durabilidad: " << durabilidad << endl;
    cout << "Largo: " << largo_cm << endl;
};  


/* Implementacion LibroDeHechizos */

// Constructor
LibroDeHechizos::LibroDeHechizos(int durabilidad) : ItemsMagicos("LibroDeHechizos", durabilidad) {};

// Metodos
bool LibroDeHechizos::usar() {
    if (durabilidad <= 0) {
        cout << "El libro de hechizos ya no sirve." << endl;
        return false;
    }

    cout << "Usando el libro de hechizos..." << endl;
    durabilidad--;
    return true;
};

void LibroDeHechizos::showInfo() {
    cout << "Nombre: " << nombre << endl;
    cout << "Daño: " << danio << endl;
    cout << "Durabilidad: " << durabilidad << endl;
    cout << "Lista de hechizos: " << endl;
    for (int i = 0; i < listaHechizos.size(); i++) {
        cout << " - " << listaHechizos[i] << endl;
    }
};

void LibroDeHechizos::agregarHechizo(string hechizo) {
    listaHechizos.push_back(hechizo);
};

/* Implementacion Pocion */

// Constructor
Pocion::Pocion(int durabilidad, string efecto, bool esParmanente) : ItemsMagicos("Pocion", durabilidad), efecto(efecto), esPermanente(esParmanente) {};

// Metodos
bool Pocion::usar() {
    if (durabilidad <= 0) {
        cout << "La pocion se ha agotado." << endl;
        return false;
    }

    cout << "Usando la pocion..." << endl;
    durabilidad--;

    if (efecto == "veneno" && esPermanente) {
        danio += 10;
    }
    return true;
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
bool Amuleto::usar() { // se usa en defensa
    if (durabilidad <= 0) {
        cout << "El amuleto ya no sirve." << endl;
        return false;
    }

    cout << "Usando el amuleto..." << endl;
    durabilidad--;

    if (bonoSuerte) {
        danio += 4;
    }

    return true;
};

void Amuleto::showInfo() {
    cout << "Nombre: " << nombre << endl;
    cout << "Daño: " << danio << endl;
    cout << "Durabilidad: " << durabilidad << endl;
    cout << "Bono de suerte: " << (bonoSuerte ? "Si" : "No") << endl;
};
