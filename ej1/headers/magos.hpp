#pragma once
#include "personajes.hpp"
#include <vector>
using namespace std;

class Hechicero : public Mago { 
    /* El Hechicero domina el fuego, hielo, rayo, etc. Su rol es hacer daño masivo con magia ofensiva. */
    public:
        // Constructor
        Hechicero(int inteligencia, int edad, string afinidadElemental);
    
        // Metodos
        string elegirHechizo(); // Elige un hechizo de la lista de hechizos
        void sobrecargaMagica(); // Consume mucho mana para lanzar 2 hechizos seguidos
    
    private:
        string afinidadElemental; // Afinidad del hechicero:  0=fuego, 1=hielo, 2=rayo
};

class Conjurador : public Mago {
    /* Maestro de la invocación de criaturas temporales para atacar o defender. */
    public:
        // Constructor
        Conjurador(int inteligencia, int edad, int cantidadDeCriaturas);
    
        // Metodos
        void sacrificarCriatura(); // Recupera mana o HP sacrificando una invocación
    private:
        int cantidadDeCriaturas;
        //vector<string> criaturasInvocadas; // Lista de criaturas invocadas
};

class Brujo : public Mago {
    /* Utiliza maldiciones, pociones y poderes oscuros. Especialista en ataques con pociones venenosas y amuletos.*/
    public:
        // Constructor
        Brujo(int inteligencia, int edad, int energiaOscura, bool pactoConDemonio);
    
        // Metodos
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
        void absorberAlma(); // Si mata a un enemigo aumenta energia absorbiendo su alma
    private:
        int energiaOscura;
        int cantidadDeAlmas;
};