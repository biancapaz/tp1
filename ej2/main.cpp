#include "factory.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

/*int main() {
    srand(time(NULL));
    int cantidadMagos = (rand() % 5) + 3;
    int cantidadGuerreros = (rand() % 5) + 3;
    
    vector<std::shared_ptr<Personaje>> listaMagos;
    for (int i = 0; i < cantidadMagos; i++) {
        int cantidadArmas = rand() % 3;
        std::shared_ptr<Personaje> personaje = PersonajeFactory::crearPersonajeArmado(TipoPersonaje::MAGO, cantidadArmas);
        listaMagos.push_back(personaje);
    }

    vector<std::shared_ptr<Personaje>> listaGuerreros;
    for (int i = 0; i < cantidadGuerreros; i++) {
        int cantidadArmas = rand() % 3;
        std::shared_ptr<Personaje> personaje = PersonajeFactory::crearPersonajeArmado(TipoPersonaje::GUERRERO, cantidadArmas);
        listaGuerreros.push_back(personaje);
    }

    for (int i = 0; i < cantidadMagos; i++) {
        cout << "Mago " << i + 1 << ": " << listaMagos[i]->getNombre() << endl;
    }
    for (int i = 0; i < cantidadGuerreros; i++) {
        cout << "Guerrero " << i + 1 << ": " << listaGuerreros[i]->getNombre() << endl;
    }

    return 0;
} */
