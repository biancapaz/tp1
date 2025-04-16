
#include "headers/magos.hpp"
#include <iostream>
#include <string>
using namespace std;

/* Implementacion Hechicero */

// Constructor
Hechicero::Hechicero(int inteligencia, int edad, string afinidadElemental) : Mago("Hechicero", inteligencia, edad), afinidadElemental(afinidadElemental) {};

// Metodos
//string elegirHechizo() {};

void Hechicero::sobrecargaMagica() {};

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
void Brujo::invocarDemonio() {
    if (pactoConDemonio) {
        cout << "Invocando demonio..." << endl;
        // EL DAÑO TIENE QUE SER MAYOR CON EL DEMONIO
    } else {
        cout << "No se puede invocar un demonio sin pacto." << endl;
    }
};

/* Implementacion Nigromante */

// Constructor
Nigromante::Nigromante(int inteligencia, int edad, int energiaOscura, int cantidadDeAlmas) : Mago("Nigromante", inteligencia, edad), energiaOscura(energiaOscura), cantidadDeAlmas(cantidadDeAlmas) {};

// Metodos
void Nigromante::absorberAlma() {
    cout << "Absorbiendo alma del enemigo..." << endl;
    cantidadDeAlmas++;
    energiaOscura += 20; // Aumenta energia al absorber un alma
}