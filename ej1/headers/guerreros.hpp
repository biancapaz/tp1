#pragma once
#include "personajes.hpp"
using namespace std;

class Barbaro : public Guerrero {
    /* Furia salvaje. */
    public:
        // Constructor
        Barbaro(int fuerza, int velocidad, int nivelFuria);
    
        // Metodos
        void gritar(); // Grito de guerra que aumenta la fuerza
    
    private:
        int nivelFuria;
};

class Paladin : public Guerrero {
    /* Guerrero sagrado. */
    public:
        // Constructor
        Paladin(int fuerza, int velocidad, int nivelSagrado);
    
        // Metodos
        void curar(); // restaura algo de HP
    
    private:
        int nivelSagrado;
};

class Caballero : public Guerrero {
    /* Guerrero veloz y elegante que combate montado a caballo. */
    public:
        // Constructor
        Caballero(int fuerza, int velocidad, bool montado);
    
        // Metodos
        void aumentarVelocidad(); // Se hace mas rapido al estar montado

    private:
        bool montado; // Si esta en caballo
};

class Mercenario : public Guerrero {
    /* Pelea por dinero, no por gloria. */
    public:
        Mercenario(int fuerza, int velocidad, int precio);

        // Metodos
        void recibirDinero(int dinero);
    private:
        int dineroGanado;
};

class Gladiador : public Guerrero {
    /* Lucha en la arena usando su gran altura. */
    public:
        Gladiador(int fuerza, int velocidad, int altura_cm);

        // Metodos
        void saltarAlto(); // Aumenta la fuerza al ganar un combate
    private:
        int altura_cm;
};