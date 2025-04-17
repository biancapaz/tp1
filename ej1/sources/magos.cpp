
#include "headers/magos.hpp"
#include <iostream>
#include <string>
using namespace std;

/* Implementacion Hechicero */

// Constructor
Hechicero::Hechicero(int inteligencia, int edad, string afinidadElemental) : Mago("Hechicero", inteligencia, edad), afinidadElemental(afinidadElemental) {};

// Metodos
int Hechicero::atacar(Personaje& enemigo) {
    showFraseDePoder(); // Muestra la frase de poder
    if (afinidadElemental == "fuego") {
        return static_cast<int>(Mago::atacar(enemigo) * 1.3);
    } 
    else if (afinidadElemental == "hielo") {
        return static_cast<int>(Mago::atacar(enemigo) * 1.2);
    } 
    else {
        return static_cast<int>(Mago::atacar(enemigo) * 1.1);
    }
};
void Hechicero::showFraseDePoder() {
    if (afinidadElemental == "fuego") {
        cout << "¡Que las llamas purifiquen este lugar!" << endl;
    } 
    else if (afinidadElemental == "hielo") {
        cout << "El frío eterno será tu castigo." << endl;
    } 
    else {
        cout << "¡El trueno es mi voluntad!" << endl;
    }
};

/* Implementacion Conjurador */

// Constructor
Conjurador::Conjurador(int inteligencia, int edad, int cantidadDeCriaturas) : Mago("Conjurador", inteligencia, edad), cantidadDeCriaturas(cantidadDeCriaturas) {};

// Metodos
void Conjurador::sacrificarCriatura() {
    if (cantidadDeCriaturas > 0) {
        cantidadDeCriaturas--;
        HP += 10; // Recupera HP al sacrificar una invocación
    } else {
        cout << "No hay criaturas para sacrificar." << endl;
    }
};

/* Implementacion Brujo */

// Constructor
Brujo::Brujo(int inteligencia, int edad, int energiaOscura, bool pactoConDemonio) : Mago("Brujo", inteligencia, edad), energiaOscura(energiaOscura), pactoConDemonio(pactoConDemonio) {};

// Metodos
int Brujo::atacar(Personaje& enemigo) {
    if (pactoConDemonio) {
        invocarDemonio();
        return static_cast<int>(Mago::atacar(enemigo) * 1.5); // Aumenta el daño si tiene pacto con demonio
    }
    return Mago::atacar(enemigo); // Si no tiene pacto, ataca normalmente
};
void Brujo::invocarDemonio() {
    cout << "Invocando demonio..." << endl;
    mana -= 5; // Consume mana para invocar demonios
    if (mana < 0) {
        mana = 0; // Asegura que el mana no sea negativo
    }
};

/* Implementacion Nigromante */

// Constructor
Nigromante::Nigromante(int inteligencia, int edad, int energiaOscura, int cantidadDeAlmas) : Mago("Nigromante", inteligencia, edad), energiaOscura(energiaOscura), cantidadDeAlmas(cantidadDeAlmas) {};

// Metodos
void Nigromante::postCombate(bool gano) {
    if (gano) {
        absorberAlma(); // Absorbe el alma del enemigo si gana
        batallasGanadas++;
    } else {
        cout << "No se puede absorber el alma, has perdido." << endl;
        batallasPerdidas++;
    }
    HP = 100; // Restaura el HP al 100%
    mana = 100; // Restaura el mana al 100%
}
void Nigromante::absorberAlma() {
    cout << "Absorbiendo alma del enemigo..." << endl;
    cantidadDeAlmas++;
    energiaOscura += 20; // Aumenta energia al absorber un alma
}