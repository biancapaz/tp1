#pragma once
#include "personajes.hpp"
#include <vector>
using namespace std;

class Hechicero : public Mago { 
    /* El Hechicero domina el fuego, hielo y el rayo. Su rol es hacer daño masivo con magia ofensiva. */
    public:
        // Constructor
        Hechicero(int inteligencia, int edad, string afinidadElemental);
    
        // Metodos
        int atacar(Personaje& enemigo) override; // Ataca al enemigo
        void showFraseDePoder(); // Muestra una frase de poder dependiendo de la afinidad elemental
    
    private:
        string afinidadElemental; // Afinidad del hechicero:  0=fuego, 1=hielo, 2=rayo
};

class Conjurador : public Mago {
    /* Maestro de la invocación de criaturas temporales. */
    public:
        // Constructor
        Conjurador(int inteligencia, int edad, int cantidadDeCriaturas);
    
        // Metodos
        void sacrificarCriatura(); // Recupera HP sacrificando una invocación
    private:
        int cantidadDeCriaturas; // Cantidad de criaturas invocadas
};

class Brujo : public Mago {
    /* Utiliza maldiciones, pociones y poderes oscuros. Especialista en ataques con pociones venenosas y amuletos.*/
    public:
        // Constructor
        Brujo(int inteligencia, int edad, int energiaOscura, bool pactoConDemonio);
    
        // Metodos
        int atacar(Personaje& enemigo) override; 
        void invocarDemonio(); // Consume mana para invocar demonios

    private:
        int energiaOscura;
        bool pactoConDemonio; // Si el brujo tiene un pacto con un demonio
};

class Nigromante : public Mago {
    /* Domina la muerte: revive enemigos, invoca esqueletos y absorbe energía vital. */
    public:
        // Constructor
        Nigromante(int inteligencia, int edad, int energiaOscura, int cantidadDeAlmas);
    
        // Metodos
        void postCombate(bool gano) override; // Si gana, ambsorbe el alma
        void absorberAlma(); // Si mata a un enemigo aumenta energia absorbiendo su alma
    private:
        int energiaOscura;
        int cantidadDeAlmas;
};