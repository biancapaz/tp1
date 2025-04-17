#include "headers/guerreros.hpp"
#include <iostream>
#include <string>
using namespace std;

/* Implementacion Barbaro */

// Constructor
Barbaro::Barbaro(int fuerza, int velocidad, int nivelFuria) : Guerrero("Barbaro", fuerza, velocidad), nivelFuria(nivelFuria) {};

// Metodos
void Barbaro::gritar() {
    cout << "Grito de guerra! Aumentando fuerza temporalmente." << endl;
    fuerza += 10; // Aumenta la fuerza
};

/* Implementacion Paladin */

// Constructor
Paladin::Paladin(int fuerza, int velocidad, int nivelSagrado) : Guerrero("Paladin", fuerza, velocidad), nivelSagrado(nivelSagrado) {};

// Metodos
void Paladin::curar() {
    if (HP >= 100) {
        cout << "HP ya está al máximo." << endl;
        return;
    }
    if (nivelSagrado < 5) {
        cout << "No tiene suficiente nivel sagrado para curar." << endl;
        return;
    }
    cout << "Curando HP..." << endl;
    HP += 5; // Restaura algo de HP
    nivelSagrado--; // Reduce el nivel sagrado
};

/* Implementacion Caballero */

// Constructor
Caballero::Caballero(int fuerza, int velocidad, bool montado) : Guerrero("Caballero", fuerza, velocidad), montado(montado) {};

// Metodos
void Caballero::aumentarVelocidad() {
    if (montado) {
        cout << "Aumentando velocidad al estar montado." << endl;
        velocidad += 10; // Aumenta la velocidad al estar montado
    } else {
        cout << "No se puede aumentar la velocidad sin estar montado." << endl;
    }
};

/* Implementacion Mercenario */

// Constructor
Mercenario::Mercenario(int fuerza, int velocidad, int precio) : Guerrero("Mercenario", fuerza, velocidad), dineroGanado(0) {};

// Metodos
void Mercenario::recibirDinero(int dinero) {
    cout << "Recibiendo dinero por el trabajo." << endl;
    dineroGanado += dinero; // Aumenta el dinero ganado
};

/* Implementacion Gladiador */

// Constructor
Gladiador::Gladiador(int fuerza, int velocidad, int altura_cm) : Guerrero("Gladiador", fuerza, velocidad), altura_cm(altura_cm) {};

// Metodos
void Gladiador::saltarAlto() {
    if (altura_cm < 200) {
        cout << "No puede saltar alto, necesita ser más alto." << endl;
        return;
    }
    cout << "Saltando alto..." << endl;
    energia -= 5; // Disminuye la energia
};