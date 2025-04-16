#include <iostream>
#include <utility>
#include <cstdlib>
#include <ctime>
#include "factory.hpp"
using namespace std;

enum Ataque { GOLPE_FUERTE=1, GOLPE_RAPIDO, DEFENSA_GOLPE };

pair<Ataque, Ataque> definirAtaque(shared_ptr<Personaje> p1, shared_ptr<Personaje> p2) {
    cout << "El jugador 1 tiene " << p1->getHP() << "HP y el jugador 2 tiene " << p2->getHP() << "HP." << endl;
    cout << "Su opción: (1) Golpe Fuerte, (2) Golpe Rápido, (3) Defensa y Golpe: ";
    int ataque1;
    cin >> ataque1;

    srand(time(NULL));
    int ataque2 = (rand() % 3) + 1;

    return make_pair(static_cast<Ataque>(ataque1), static_cast<Ataque>(ataque2));
}

shared_ptr<Personaje> combate(shared_ptr<Personaje> p1, shared_ptr<Personaje> p2) {
    while (p1->estaVivo() && p2->estaVivo()) {
        pair<Ataque, Ataque> ataques = definirAtaque(p1, p2);
        
        if (ataques.first == ataques.second) {
            continue;
        }

        switch(ataques.first) {
            case Ataque::GOLPE_FUERTE : {
                if (ataques.second == Ataque::GOLPE_RAPIDO) { // FUERTE > RAPIDO
                    int danio = p1->atacar();
                    p2->recibirDanio(danio);
                    cout << "El " << p1->getNombre() << " ataca con " << p1->getArma() << " y hace" << danio << " puntos de daño." << endl;
                }
                else { // ataques.second == Ataque::DEFENSA_GOLPE --> FUERTE < DEFENSA_GOLPE
                    int danio = p2->atacar();
                    p1->recibirDanio(danio);
                    cout << "El " << p2->getNombre() << " ataca con " << p2->getArma() << " y hace" << danio << " puntos de daño." << endl;
                }
                break;
            }
            case Ataque::GOLPE_RAPIDO : {
                if (ataques.second == Ataque::DEFENSA_GOLPE) { // RAPIDO > DEFENSA_GOLPE
                    int danio = p1->atacar();
                    p2->recibirDanio(danio);
                    cout << "El " << p1->getNombre() << " ataca con " << p1->getArma() << " y hace" << danio << " puntos de daño." << endl;
                }
                else { // ataques.second == Ataque::GOLPE_FUERTE --> RAPIDO < FUERTE
                    int danio = p2->atacar();
                    p1->recibirDanio(danio);
                    cout << "El " << p2->getNombre() << " ataca con " << p2->getArma() << " y hace" << danio << " puntos de daño." << endl;
                }
                break;
            }
            case Ataque::DEFENSA_GOLPE : {
                if (ataques.second == Ataque::GOLPE_FUERTE) { // DEFENSA_GOLPE > FUERTE
                    int danio = p1->atacar();
                    p2->recibirDanio(danio);
                    cout << "El " << p1->getNombre() << " ataca con " << p1->getArma() << " y hace" << danio << " puntos de daño." << endl;
                }
                else { // ataques.second == Ataque::GOLPE_RAPIDO --> DEFENSA_GOLPE < RAPIDO
                    int danio = p2->atacar();
                    p1->recibirDanio(danio);
                    cout << "El " << p2->getNombre() << " ataca con " << p2->getArma() << " y hace" << danio << " puntos de daño." << endl;
                }
                break;
            }
        }
    }
    return (p1->estaVivo() ? p1 : p2);        
}

int main() {
    shared_ptr<Personaje> p1 = PersonajeFactory::crearPersonajeArmado(TipoPersonaje::GUERRERO, 1);
    shared_ptr<Personaje> p2 = PersonajeFactory::crearPersonajeArmado(TipoPersonaje::MAGO, 1);

    shared_ptr<Personaje> winner = combate(p1, p2);
    cout << "GANADOR: " << winner->getNombre() << " con puntos de HP restantes: " << winner->getHP() << endl;
}