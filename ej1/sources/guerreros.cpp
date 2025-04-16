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
    fuerza += 10; // Aumenta la fuerza temporalmente
};

/* Implementacion Paladin */

// Constructor
Paladin::Paladin(int fuerza, int velocidad, int nivelSagrado) : Guerrero("Paladin", fuerza, velocidad), nivelSagrado(nivelSagrado) {};

// Metodos
void Paladin::curar() {
    cout << "Curando HP..." << endl;
    HP += 5; // Restaura algo de HP
};

/* Implementacion Caballero */

// Constructor
Caballero::Caballero(int fuerza, int velocidad, bool montado) : Guerrero("Caballero", fuerza, velocidad), montado(montado) {};

// Metodos
void Caballero::aumentarVelocidad() {
    if (montado) {
        cout << "Aumentando velocidad al estar montado." << endl;
        velocidad += 5; // Aumenta la velocidad al estar montado
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
void Gladiador::aumentarFuerza() {
    cout << "Aumentando fuerza al ganar un combate." << endl;
    fuerza += 10; // Aumenta la fuerza al ganar un combate
};