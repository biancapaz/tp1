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
shared_ptr<Arma> Mago::getArma() {
    return itemEnUso; // Si no tiene item1, devuelve "Sin Arma"
};
bool Mago::estaVivo() {
    return HP > 0;
};

void Mago::agregarArma(shared_ptr<Arma> item) {
    if (item1 == nullptr) {
        item1 = dynamic_pointer_cast<ItemsMagicos>(item);
        itemEnUso = item1; // Se usa el item 1 por defecto
    } else if (item2 == nullptr) {
        item2 = dynamic_pointer_cast<ItemsMagicos>(item);
    } else {
        cout << "No se pueden agregar mas items magicos." << endl;
    }
};
int Mago::atacar() {
    if (!item1) { // Si no tiene item1 tampoco tiene item2, se da por perdida la jugada
        cout << "No tiene un item magico equipado." << endl;
        cout << "No puede atacar." << endl;
        HP = 0;
        return 0;
    }

    if(!item1->usar()) { // Usa el item magico, si devuelve false no tenia mas usos
        if (item2 && item2->usar()) {// Si tiene otro item para usar y tiene durabilidad 
            itemEnUso = item2;
        }
        else if (item2 && !item2->getRecargaUasada()) { // Si tiene otro item pero no tiene durabilidad 
            item2->intentarRecargar(); // Intenta recargar el item2
            if (item2->getRecargaUasada()) {// Si se recargo, lo usa
                item2->usar(); 
                itemEnUso = item2;
            }
            else { // Si no se recargo, pierde
                HP = 0;
                return 0;
            }
        }
        else { // Si no tiene item 2, pierde
            cout << "No tiene mas items magicos para usar." << endl;
            HP = 0; // Si no tiene mas items, pierde
            return 0;
        }
    }
    else {
        itemEnUso = item1; // Si no se recargo, usa el item1
    } 
    
    int danio_total = (itemEnUso->getDanio() * 0.7 + calcularDanioBase() * 0.3);

    mana -= 10; // Resta mana al mago
    if (mana < 0) {
        mana = 0; // Asegura que el mana no sea negativo
    }

    return danio_total;
};
void Mago::recibirDanio(int danio) {
    HP -= danio; // Resta el daño al HP
    if (HP < 0) {
        HP = 0; // Asegura que el HP no sea negativo
    }
};
int Mago::calcularDanioBase() {
    return static_cast<int>((inteligencia * 0.7 + mana * 0.2) - edad * 0.1);
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
shared_ptr<Arma> Guerrero::getArma() {
    return armaEnUso; // Si no tiene arma1, devuelve "Sin Arma"
};
bool Guerrero::estaVivo() {
    return HP > 0;
};  

void Guerrero::agregarArma(shared_ptr<Arma> arma) {
    if (arma1 == nullptr) {
        arma1 = dynamic_pointer_cast<ArmasDeCombate>(arma);
        armaEnUso = arma1; // Se usa el arma 1 por defecto
    } else if (arma2 == nullptr) {
        arma2 = dynamic_pointer_cast<ArmasDeCombate>(arma);
    } else {
        cout << "No se pueden agregar mas armas de combate." << endl;
    }
};
int Guerrero::atacar() {
    if (!armaEnUso) {
        cout << "No tiene un arma de combate equipada." << endl;
        HP = 0;
        return 0;
    }

    armaEnUso->usar(); // Usa el item magico
    
    int danio_total = (armaEnUso->getDanio() * 0.7 + calcularDanioBase() * 0.3);

    if (armaEnUso->esPesada()) { // Si el arma es pesada, resta energia
        energia -= 20; // Resta energia al guerrero
    } else {
        energia -= 5; // Resta menos energia si el arma no es pesada
    }
    if (energia < 0) {
        energia = 0; // Asegura que la energia no sea negativo
    }

    return danio_total;
};
void Guerrero::recibirDanio(int danio) {
    HP -= danio; // Resta el daño al HP
    if (HP < 0) {
        HP = 0; // Asegura que el HP no sea negativo
    }
};
int Guerrero::calcularDanioBase() {
    return static_cast<int>(fuerza * 0.6 + velocidad * 0.5);
};
void Guerrero::cambiarArmaEnUso() {
    if (arma1->getNombre() == arma1->getNombre()) {
        armaEnUso = arma2;
    } else {
        armaEnUso = arma1;
    }
};
