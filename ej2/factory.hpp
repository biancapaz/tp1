#pragma once
#include "tipos.hpp"
#include "headers/personajes.hpp"
#include "headers/armas.hpp"
#include <memory>
using namespace std;

class PersonajeFactory {
    public:
        static shared_ptr<Personaje> crearPersonaje(TipoPersonaje tipo);
        static shared_ptr<Arma> crearArma(TipoArma tipo);
        static shared_ptr<Personaje> crearPersonajeArmado(TipoPersonaje tipoPersonaje, int cantidadArmas);
};