#include "personajes.hpp"
#include "armas.hpp"
#include "armasDeCombate.hpp"
#include "itemsMagicos.hpp"
#include "guerreros.hpp"
#include "magos.hpp"
#include <iostream>
using namespace std;

int main() {

    cout << "=== CREACIÓN DE PERSONAJES ===" << endl;

    // Creo dos personajes de cada tipo
    cout << "Creando guerrero..." << endl;
    shared_ptr<Barbaro> guerrero1 = make_shared<Barbaro>(10, 5, 3);
    cout << "Creando mago..." << endl;
    shared_ptr<Hechicero> mago1 = make_shared<Hechicero>(8, 25, "fuego");
    
    cout << "\n=== INFORMACIÓN DE PERSONAJES ===" << endl;

    // Muestro informacion de los personajes
    cout << "Personaje 1: " << guerrero1->getNombre() << endl;
    cout << "Tipo: " << (guerrero1->getTipo() == TipoPersonaje::GUERRERO ? "Guerrero" : "Mago") << endl;
    cout << "HP: " << guerrero1->getHP() << endl;

    cout << "\n--------------------------\n";

    cout << "Personaje 2: " << mago1->getNombre() << endl;
    cout << "Tipo: " << (mago1->getTipo() == TipoPersonaje::GUERRERO ? "Guerrero" : "Mago") << endl;
    cout << "HP: " << mago1->getHP() << endl;

    cout << "\n=== CREACIÓN DE ARMAS ===" << endl;

    // Creo un arma de combate y un item magico
    cout << "Creando arma de combate..." << endl;
    shared_ptr<Espada> espada = make_shared<Espada>("hierro", 10, 60, true);
    cout << "Creando item magico..." << endl;
    shared_ptr<Baston> baston = make_shared<Baston>(10, 50);

    cout << "\n=== ASIGNACIÓN DE ARMAS ===" << endl;

    // Agrego las armas a los personajes
    cout << "Agregando arma de combate..." << endl;
    guerrero1->agregarArma(espada);
    cout << "Agregando item magico..." << endl;
    mago1->agregarArma(baston);

    cout << "\n=== INFORMACIÓN DE ARMAS ===" << endl;

    // Muestro informacion de las armas
    guerrero1->getArma()->showInfo();

    cout << "\n--------------------------\n";
    
    mago1->getArma()->showInfo();

    cout << "\n=== ACCIONES DE LOS PERSONAJES ===" << endl;

    // Realizo las acciones de los personajes
    guerrero1->gritar();
    mago1->showFraseDePoder();

    return 0;
}