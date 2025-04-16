#include "factory.hpp"
#include "tipos.hpp"
#include "headers/magos.hpp"
#include "headers/guerreros.hpp"
#include "headers/itemsMagicos.hpp"
#include "headers/armasDeCombate.hpp"
#include <iostream>
#include <string>
using namespace std;

shared_ptr<Mago> crearMago(TipoMago tipo) {
    int inteligencia, edad;
    cout << "Ingrese la inteligencia del mago: ";
    cin >> inteligencia;
    cout << "Ingrese la edad del mago: ";
    cin >> edad;
    
    switch (tipo) {
        case TipoMago::HECHICERO: {
            string afinidadElemental;
            cout << "Ingrese la afinidad elemental del hechicero (fuego, hielo, rayo): ";
            cin >> afinidadElemental;
            return make_shared<Hechicero>(inteligencia, edad, afinidadElemental);
        }            
        case TipoMago::CONJURADOR: {
            int cantidadDeCriaturas;
            cout << "Ingrese la cantidad de criaturas invocadas: ";
            cin >> cantidadDeCriaturas;
            return make_shared<Conjurador>(inteligencia, edad, cantidadDeCriaturas);
        }
        case TipoMago::BRUJO: {
            int energiaOscura;
            bool pactoConDemonio;
            cout << "Ingrese la energia oscura del brujo: ";
            cin >> energiaOscura;
            cout << "El brujo tiene pacto con demonio? (1=si, 0=no): ";
            cin >> pactoConDemonio;
            return make_shared<Brujo>(inteligencia, edad, energiaOscura, pactoConDemonio);
        }
        case TipoMago::NIGROMANTE: {
            int energiaOscura;
            int cantidadDeAlmas;
            cout << "Ingrese la energia oscura del nigromante: ";
            cin >> energiaOscura;
            cout << "Ingrese la cantidad de almas absorbidas: ";
            cin >> cantidadDeAlmas;
            return make_shared<Nigromante>(inteligencia, edad, energiaOscura, cantidadDeAlmas);
        }
        default:
            throw invalid_argument("Tipo de mago no válido");
    }
}

shared_ptr<Guerrero> crearGuerrero(TipoGuerrero tipo) {
    int fuerza, velocidad;
    cout << "Ingrese la fuerza del guerrero: ";
    cin >> fuerza;
    cout << "Ingrese la velocidad del guerrero: ";
    cin >> velocidad;
    
    switch (tipo) {
        case TipoGuerrero::BARBARO: {
            int nivelFuria;            
            cout << "Ingrese el nivel de furia del barbaro: ";
            cin >> nivelFuria;
            return make_shared<Barbaro>(fuerza, velocidad, nivelFuria);
        }            
        case TipoGuerrero::PALADIN: {
            int nivelSagrado;
            cout << "Ingrese el nivel sagrado del paladin: ";
            cin >> nivelSagrado;
            return make_shared<Paladin>(fuerza, velocidad, nivelSagrado);
        }
        case TipoGuerrero::CABALLERO: {
            bool montado;
            cout << "El caballero esta montado? (1=si, 0=no): ";
            cin >> montado;
            return make_shared<Caballero>(fuerza, velocidad, montado);
        }
        case TipoGuerrero::MERCENARIO: {
            int dineroGanado;
            cout << "Ingrese el dinero ganado por el mercenario: ";
            cin >> dineroGanado;
            return make_shared<Mercenario>(fuerza, velocidad, dineroGanado);
        }
        case TipoGuerrero::GLADIADOR: {
            float altura_cm;
            cout << "Ingrese la altura del gladiador (en cm): ";
            cin >> altura_cm;
            return make_shared<Gladiador>(fuerza, velocidad, altura_cm);
        }
        default:
            throw invalid_argument("Tipo de mago no válido");
    }
}

shared_ptr<Personaje> PersonajeFactory::crearPersonaje(TipoPersonaje tipo) {
    switch (tipo) {
        case TipoPersonaje::MAGO: {
            cout << "Elija el tipo de Mago: ";
            cout << "1. Hechicero" << endl;
            cout << "2. Conjurador" << endl;
            cout << "3. Brujo" << endl;
            cout << "4. Nigromante" << endl;
            int tipoMago;
            cin >> tipoMago;

            return crearMago(static_cast<TipoMago>(tipoMago));
        }
        case TipoPersonaje::GUERRERO: {
        cout << "Elija el tipo de Guerrero: ";
        cout << "1. Barbaro" << endl;
        cout << "2. Paladin" << endl;
        cout << "3. Caballero" << endl;
        cout << "4. Mercenario" << endl;
        cout << "5. Gladiador" << endl;
        int tipoGuerrero;
        cin >> tipoGuerrero;

        return crearGuerrero(static_cast<TipoGuerrero>(tipoGuerrero));
        }
        default:
            throw invalid_argument("Tipo de personaje no válido");
    }
};

shared_ptr<ItemsMagicos> crearItemMagico(TipoItemMagico tipo) {
    int durabilidad;
    cout << "Ingrese la durabilidad del item magico: ";
    cin >> durabilidad;

    switch (tipo) {
        case TipoItemMagico::BASTON: {
            double largo;
            cout << "Ingrese el largo del baston: ";
            cin >> largo;
            return make_shared<Baston>(durabilidad, largo);
        }
        case TipoItemMagico::LIBRO_DE_HECHIZOS: {
            return make_shared<LibroDeHechizos>(durabilidad);
        }
        case TipoItemMagico::POCION: {
            string efecto;
            bool esPermanente;
            cout << "Ingrese el efecto de la pocion (veneno, paralizante, envejecedora, lentificante): ";
            cin >> efecto;
            cout << "La pocion es permanente? (1=si, 0=no): ";
            cin >> esPermanente;
            return make_shared<Pocion>(durabilidad, efecto, esPermanente);
        }
        case TipoItemMagico::AMULETO: {
            bool bonoSuerte;
            cout << "El amuleto tiene bono de suerte? (1=si, 0=no): ";
            cin >> bonoSuerte;
            return make_shared<Amuleto>(durabilidad, bonoSuerte);
        }
        default:
            throw invalid_argument("Tipo de item magico no válido");
    }
};

shared_ptr<ArmasDeCombate> crearArmaDeCombate(TipoArmaDeCombate tipo) {
    string material;
    double peso;
    cout << "Ingrese el material del arma de combate (piedra, madera, hierro): ";
    cin >> material;
    cout << "Ingrese el peso del arma de combate: ";
    cin >> peso;

    switch (tipo) {
        case TipoArmaDeCombate::HACHA_SIMPLE: {
            bool conGema;
            cout << "El hacha simple tiene gema? (1=si, 0=no): ";
            cin >> conGema;
            return make_shared<HachaSimple>(material, peso, conGema);
        }
        case TipoArmaDeCombate::HACHA_DOBLE: {
            double largo;
            bool filoExtra;
            cout << "Ingrese el largo del hacha doble: ";
            cin >> largo;
            cout << "El hacha doble tiene filo extra? (1=si, 0=no): ";
            cin >> filoExtra;
            return make_shared<HachaDoble>(material, peso, largo, filoExtra);
        }
        case TipoArmaDeCombate::ESPADA: {
            double largo;
            bool tieneBrillo;
            cout << "Ingrese el largo de la espada: ";
            cin >> largo;
            cout << "La espada tiene brillo? (1=si, 0=no): ";
            cin >> tieneBrillo;
            return make_shared<Espada>(material, peso, largo, tieneBrillo);
        }
        case TipoArmaDeCombate::LANZA: {
            double largo;
            int cantidadPuntas;
            cout << "Ingrese el largo de la lanza: ";
            cin >> largo;
            cout << "Ingrese la cantidad de puntas de la lanza: ";
            cin >> cantidadPuntas;
            return make_shared<Lanza>(material, peso, largo, cantidadPuntas);
        }
        case TipoArmaDeCombate::GARROTE: {
            bool tienePicos;
            bool doblePunta;
            cout << "El garrote tiene picos? (1=si, 0=no): ";
            cin >> tienePicos;
            cout << "El garrote tiene doble punta? (1=si, 0=no): ";
            cin >> doblePunta;
            return make_shared<Garrote>(material, peso, tienePicos, doblePunta);
        }
        default:
            throw invalid_argument("Tipo de arma de combate no válido");
    }
};

shared_ptr<Arma> PersonajeFactory::crearArma(TipoArma tipo) {
    switch (tipo) {
        case TipoArma::ITEM_MAGICO: {
            cout << "Elija el tipo de Item Magico: ";
            cout << "1. Baston" << endl;
            cout << "2. Libro de Hechizos" << endl;
            cout << "3. Pocion" << endl;
            cout << "4. Amuleto" << endl;
            int tipoItemMagico;
            cin >> tipoItemMagico;

            return crearItemMagico(static_cast<TipoItemMagico>(tipoItemMagico));
        }
        case TipoArma::ARMA_DE_COMBATE: {
            cout << "Elija el tipo de Arma de Combate: ";
            cout << "1. Hacha Simple" << endl;
            cout << "2. Hacha Doble" << endl;
            cout << "3. Espada" << endl;
            cout << "4. Lanza" << endl;
            cout << "5. Garrote" << endl;
            int tipoArmaDeCombate;
            cin >> tipoArmaDeCombate;

            return crearArmaDeCombate(static_cast<TipoArmaDeCombate>(tipoArmaDeCombate));
        }
        default:
            throw invalid_argument("Tipo de arma no válido");
    }
};

shared_ptr<Personaje> PersonajeFactory::crearPersonajeArmado(TipoPersonaje tipoPersonaje, int cantidadArmas) {
    shared_ptr<Personaje> personaje = crearPersonaje(tipoPersonaje);
    
    if (tipoPersonaje == TipoPersonaje::MAGO) {
        for (int i = 0; i < cantidadArmas; ++i) {
            shared_ptr<Arma> item = crearArma(TipoArma::ITEM_MAGICO);
            personaje->agregarArma(item);
        }
    } else if (tipoPersonaje == TipoPersonaje::GUERRERO) {
        for (int i = 0; i < cantidadArmas; ++i) {
            shared_ptr<Arma> arma = crearArma(TipoArma::ARMA_DE_COMBATE);
            personaje->agregarArma(arma);
        }
    }

    return personaje;
};

