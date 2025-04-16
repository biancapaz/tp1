#include <iostream>
#include <utility>
#include <cstdlib>
#include <ctime>
#include "factory.hpp"
#include "tipos.hpp"
#include "headers/magos.hpp"
#include "headers/guerreros.hpp"
#include "headers/itemsMagicos.hpp"
#include "headers/armasDeCombate.hpp"
using namespace std;

enum Ataque { GOLPE_FUERTE=1, GOLPE_RAPIDO, DEFENSA_GOLPE };

shared_ptr<Personaje> crearPersonajeAleatorio() {
    int tipoPersonaje = (rand() % 2) + 1;
    TipoPersonaje p = static_cast<TipoPersonaje>(tipoPersonaje);

    switch(p) {
        case TipoPersonaje::GUERRERO : {

            int fuerza = rand() % 101; // valores de 0 a 100
            int velocidad = rand() % 101; // valores de 0 a 100

            int tipoGuerrero = (rand() % 5) + 1; // valores de 1 a 5
            TipoGuerrero g = static_cast<TipoGuerrero>(tipoGuerrero);

            switch (g) {
                case TipoGuerrero::BARBARO : {
                    int nivelFuria = rand() % 101; // valores de 0 a 100
                    return make_shared<Barbaro>(fuerza, velocidad, nivelFuria);
                }
                case TipoGuerrero::PALADIN : {
                    int nivelSagrado = rand() % 101; // valores de 0 a 100
                    return make_shared<Paladin>(fuerza, velocidad, nivelSagrado);
                }
                case TipoGuerrero::CABALLERO : {
                    bool montado = rand() % 2; // valores de 0 a 1
                    return make_shared<Caballero>(fuerza, velocidad, montado);
                }
                case TipoGuerrero::MERCENARIO : {
                    int dineroGanado = rand() % 101; // valores de 0 a 100
                    return make_shared<Mercenario>(fuerza, velocidad, dineroGanado);
                }
                case TipoGuerrero::GLADIADOR : {
                    int altura_cm = (rand() % 291) + 10; // valores de 10 a 300
                    return make_shared<Gladiador>(fuerza, velocidad, altura_cm);
                }
            }
        }
        case TipoPersonaje::MAGO : {

            int inteligencia = rand() % 101; // valores de 0 a 100
            int edad = (rand() % 91) + 10; // valores de 10 a 100

            int tipoMago = (rand() % 4) + 1; // valores de 1 a 4
            TipoMago m = static_cast<TipoMago>(tipoMago);

            switch (m) {
                case TipoMago::HECHICERO : {  //0=fuego, 1=hielo, 2=rayo
                    int afinidadElemental = rand() % 3;

                    string nombreElemento = vector<string>{"fuego", "hielo", "rayo"}[afinidadElemental];
                    return make_shared<Hechicero>(inteligencia, edad, nombreElemento);
                }
                case TipoMago::CONJURADOR : {
                    int cantidadDeCriaturas = rand() % 21; // valores de 0 a 20
                    return make_shared<Conjurador>(inteligencia, edad, cantidadDeCriaturas);
                }
                case TipoMago::BRUJO : {
                    int energiaOscura = rand() % 101; // valores de 0 a 100
                    bool pactoConDemonio = rand() % 2; // valores de 0 a 1
                    return make_shared<Brujo>(inteligencia, edad, energiaOscura, pactoConDemonio);
                }
                case TipoMago::NIGROMANTE : {
                    int energiaOscura = rand() % 101; // valores de 0 a 100
                    int cantidadDeAlmas = rand() % 21; // valores de 0 a 20
                    return make_shared<Nigromante>(inteligencia, edad, energiaOscura, cantidadDeAlmas);
                }
            }
        }
    }
    return nullptr;
}

shared_ptr<ItemsMagicos> crearItemMagicoAleatorio() {
    int tipo = (rand() % 4) + 1;
    TipoItemMagico i = static_cast<TipoItemMagico>(tipo);
    
    int durabilidad = (rand() % 100) + 1; // valores de 1 a 100
    
    switch(i) {
        
        case TipoItemMagico::BASTON : {
            int largo_cm = (rand() % 21) + 10; // valores de 10 a 30
            return make_shared<Baston>(durabilidad, largo_cm);
        }
        case TipoItemMagico::LIBRO_DE_HECHIZOS : {
            return make_shared<LibroDeHechizos>(durabilidad);
        }
        case TipoItemMagico::POCION : { // 0=veneno, 1=paralizante, 2=envejecedora, 3=lentificante
            int efecto = rand() % 4; // valores de 0 a 3
            bool esPermanente = rand() % 2; // valores de 0 a 1

            string nombreEfecto = vector<string>{"veneno", "paralizante", "envejecedora", "lentificante"}[efecto];
            return make_shared<Pocion>(durabilidad, nombreEfecto, esPermanente);
        }
        case TipoItemMagico::AMULETO : {
            bool bonoSuerte = rand() % 2; // valores de 0 a 1
            return make_shared<Amuleto>(durabilidad, bonoSuerte);
        }
    }
    return nullptr;
}

shared_ptr<ArmasDeCombate> crearArmaDeCombateAleatorio() {
    int tipo = (rand() % 5) + 1;
    TipoArmaDeCombate a = static_cast<TipoArmaDeCombate>(tipo);
    
    int material = rand() % 3; // 0=piedra, 1=madera y 2=hierro
    int peso_gr = (rand() % 100) + 1; // valores de 1 a 100

    string nombreMaterial = vector<string>{"piedra", "madera", "hierro"}[material];
    
    switch(a) {
        
        case TipoArmaDeCombate::HACHA_SIMPLE : {
            bool conGema = rand() % 2; // valores de 0 a 1
            return make_shared<HachaSimple>(nombreMaterial, peso_gr, conGema);
        }
        case TipoArmaDeCombate::HACHA_DOBLE : {
            int largo_cm = (rand() % 91) + 10; // valores de 10 a 100;
            bool filoExtra = rand() % 2; // valores de 0 a 1;
            return make_shared<HachaDoble>(nombreMaterial, peso_gr, largo_cm, filoExtra);
        }
        case TipoArmaDeCombate::ESPADA : { // 0=veneno, 1=paralizante, 2=envejecedora, 3=lentificante
            int largo_cm = (rand() % 71) + 10; // valores de 10 a 70;
            bool tieneBrillo = rand() % 2; // valores de 0 a 1
            return make_shared<Espada>(nombreMaterial, peso_gr, largo_cm, tieneBrillo);
        }
        case TipoArmaDeCombate::LANZA : {
            int largo_cm = (rand() % 91) + 10; // valores de 10 a 100;
            int cantidadPuntas = (rand() % 3) + 1; // valores de 1 a 3
            return make_shared<Lanza>(nombreMaterial, peso_gr, largo_cm, cantidadPuntas);
        }
        case TipoArmaDeCombate::GARROTE : {
            bool tienePicos = rand() % 2; // valores de 0 a 1
            bool doblePunta = rand() % 2; // valores de 0 a 1
            return make_shared<Garrote>(nombreMaterial, peso_gr, tienePicos, doblePunta);
        }
    }
    return nullptr;
}

pair<Ataque, Ataque> definirAtaque(shared_ptr<Personaje> p1, shared_ptr<Personaje> p2) {
    cout << "El jugador 1  tiene " << p1->getHP() << "HP y el jugador 2 tiene " << p2->getHP() << "HP." << endl;
    cout << "Su opción: (1) Golpe Fuerte, (2) Golpe Rápido, (3) Defensa y Golpe: ";
    int ataque1;
    cin >> ataque1;
    while (ataque1 < 1 || ataque1 > 3) {
        cout << "Opcion no valida. Ingrese nuevamente el numero de ataque: " << endl;
        cin >> ataque1;
    }
    cout << endl;

    int ataque2 = (rand() % 3) + 1;

    return make_pair(static_cast<Ataque>(ataque1), static_cast<Ataque>(ataque2));
}

shared_ptr<Personaje> combate(shared_ptr<Personaje> p1, shared_ptr<Personaje> p2) {
    cout << endl;
    cout << "COMBATE ENTRE " << p1->getNombre() << " y " << p2->getNombre() << endl;

    while (p1->estaVivo() && p2->estaVivo()) {
        cout << endl;
        pair<Ataque, Ataque> ataques = definirAtaque(p1, p2);
        
        if (ataques.first == ataques.second) {
            cout << "Los ataques son iguales. Se vuelve a pedir el tipo ataque." << endl;
            continue;
        }

        switch(ataques.first) {
            case Ataque::GOLPE_FUERTE : {
                if (ataques.second == Ataque::GOLPE_RAPIDO) { // FUERTE > RAPIDO

                    int danio = p1->atacar();
                    p2->recibirDanio(danio);
                    cout << "El " << p1->getNombre() << " ataca con " << p1->getArma()->getNombre() <<  " y hace " << danio << " puntos de daño." << endl;
                }
                else { // ataques.second == Ataque::DEFENSA_GOLPE --> FUERTE < DEFENSA_GOLPE

                    int danio = p2->atacar();
                    p1->recibirDanio(danio);
                    cout << "El " << p2->getNombre() << " ataca con "  << p2->getArma()->getNombre() <<  " y hace " << danio << " puntos de daño." << endl;
                }
                break;
            }
            case Ataque::GOLPE_RAPIDO : {
                if (ataques.second == Ataque::DEFENSA_GOLPE) { // RAPIDO > DEFENSA_GOLPE

                    int danio = p1->atacar();
                    p2->recibirDanio(danio);
                    cout << "El " << p1->getNombre() << " ataca con " << p1->getArma()->getNombre() << " y hace " << danio << " puntos de daño." << endl;
                }
                else { // ataques.second == Ataque::GOLPE_FUERTE --> RAPIDO < FUERTE

                    int danio = p2->atacar();
                    p1->recibirDanio(danio);
                    cout << "El " << p2->getNombre() << " ataca con " << p2->getArma()->getNombre() << " y hace " << danio << " puntos de daño." << endl;
                }
                break;
            }
            case Ataque::DEFENSA_GOLPE : {
                if (ataques.second == Ataque::GOLPE_FUERTE) { // DEFENSA_GOLPE > FUERTE

                    int danio = p1->atacar();
                    p2->recibirDanio(danio);
                    cout << "El " << p1->getNombre() << " ataca con " << p1->getArma()->getNombre() << " y hace " << danio << " puntos de daño." << endl;
                }
                else { // ataques.second == Ataque::GOLPE_RAPIDO --> DEFENSA_GOLPE < RAPIDO

                    int danio = p2->atacar();
                    p1->recibirDanio(danio);
                    cout << "El " << p2->getNombre() << " ataca con " << p2->getArma()->getNombre() << " y hace " << danio << " puntos de daño." << endl;
                }
                break;
            }
        }
    }
    return (p1->estaVivo() ? p1 : p2);        
}

int main() {
    
    // MI PERSONAJE GUERRERO
    shared_ptr<Personaje> p1 = PersonajeFactory::crearPersonajeArmado(TipoPersonaje::GUERRERO, 1);
    cout<< endl;
    cout << "NOMBRE DE MI PERSONAJE GUERRERO" << endl;
    cout << "Nombre: " << p1->getNombre() << endl;
    cout<< endl;
    cout << "INFORMACION DE MI ARMA DE COMBATE" << endl;
    p1->getArma()->showInfo();


    // Creo personaje random y arma random
    srand(time(NULL));
    shared_ptr<Personaje> p2 = crearPersonajeAleatorio();

    cout<< endl;
    cout << "NOMBRE DEL PERSONAJE RANDOM" << endl;
    //shared_ptr<Personaje> p1 = PersonajeFactory::crearPersonaje(TipoPersonaje::GUERRERO);
    cout << "Nombre: " << p2->getNombre() << endl;
    
    if (p2->getTipo() == TipoPersonaje::MAGO) {
        shared_ptr<ItemsMagicos> item = crearItemMagicoAleatorio();
        p2->agregarArma(item);

        cout<< endl;
        cout << "INFORMACION DEL ITEM MAGICO" << endl;
        p2->getArma()->showInfo();
    }
    else {
        shared_ptr<ArmasDeCombate> arma = crearArmaDeCombateAleatorio();
        p2->agregarArma(arma);

        cout<< endl;
        cout << "INFORMACION DEL ARMA DE COMBATE" << endl;
        p2->getArma()->showInfo();
        cout<< endl;
    }  
    
    shared_ptr<Personaje> winner = combate(p1, p2);
    cout << "GANADOR: " << winner->getNombre() << " con " << winner->getHP() << " puntos de HP restantes."  << endl;
} 