#include "headers/personajes.hpp"
#include <iostream>
using namespace std;

/*Implementacion Clase Abstracta Mago*/ 

// Constructor
Mago::Mago(string nombre, int inteligencia, int edad) : nombre(nombre), inteligencia(inteligencia), edad(edad) {};

// Metodos
string Mago::getNombre() {
    return nombre;
};
TipoPersonaje Mago::getTipo() {
    return tipo;
};
int Mago::getHP() {
    return HP;
};
string Mago::getArma() {
    return item1->getNombre();
};
bool Mago::estaVivo() {
    return HP > 0;
};
void Mago::agregarArma(shared_ptr<Arma> item) {
    if (item1 == nullptr) {
        item1 = dynamic_pointer_cast<ItemsMagicos>(item);
    } else if (item2 == nullptr) {
        item2 = dynamic_pointer_cast<ItemsMagicos>(item);
    } else {
        cout << "No se pueden agregar mas items magicos." << endl;
    }
};
int Mago::atacar() {
    if (!item1) {
        cout << "No tiene un item magico equipado." << endl;
        return 0;
    }

    item1->usar(); // Usa el item magico
    
    mana -= 10; // Resta mana al mago
    if (mana < 0) {
        mana = 0; // Asegura que el mana no sea negativo
    }

    return item1->getDanio();
};
void Mago::recibirDanio(int danio) {
    HP -= danio; // Resta el daño al HP
    if (HP < 0) {
        HP = 0; // Asegura que el HP no sea negativo
    }
};

/*Implementacion Clase Abstracta Guerrero*/

// Constructor
Guerrero::Guerrero(string nombre, int fuerza, int velocidad) : nombre(nombre), fuerza(fuerza), velocidad(velocidad) {};

// Metodos
string Guerrero::getNombre() {
    return nombre;
};
TipoPersonaje Guerrero::getTipo() {
    return tipo;
};
int Guerrero::getHP() {
    return HP;
};
string Guerrero::getArma() {
    return arma1->getNombre();
};
bool Guerrero::estaVivo() {
    return HP > 0;
};  
void Guerrero::agregarArma(shared_ptr<Arma> arma) {
    if (arma1 == nullptr) {
        arma1 = dynamic_pointer_cast<ArmasDeCombate>(arma);
    } else if (arma2 == nullptr) {
        arma2 = dynamic_pointer_cast<ArmasDeCombate>(arma);
    } else {
        cout << "No se pueden agregar mas armas de combate." << endl;
    }
};
int Guerrero::atacar() {
    if (!arma1) {
        cout << "No tiene un arma de combate equipada." << endl;
        return 0;
    }

    arma1->usar(); // Usa el item magico
    
    energia -= 10; // Resta mana al mago
    if (energia < 0) {
        energia = 0; // Asegura que la energia no sea negativo
    }

    return arma1->getDanio();
};
void Guerrero::recibirDanio(int danio) {
    HP -= danio; // Resta el daño al HP
    if (HP < 0) {
        HP = 0; // Asegura que el HP no sea negativo
    }
};
