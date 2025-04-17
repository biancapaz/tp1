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
            int afinidadElemental;
            cout << "Ingrese la afinidad elemental del hechicero (fuego, hielo, rayo): " << endl;
            cout << "0. Fuego" << endl;
            cout << "1. Hielo" << endl;
            cout << "2. Rayo" << endl;
            cin >> afinidadElemental;

            while (afinidadElemental < 0 || afinidadElemental > 2) {
                cout << "Opcion no valida. Ingrese nuevamente la afinidad elemental: " << endl;
                cin >> afinidadElemental;
            }
            string nombreElemento = vector<string>{"fuego", "hielo", "rayo"}[afinidadElemental];

            return make_shared<Hechicero>(inteligencia, edad, nombreElemento);
        }            
        case TipoMago::CONJURADOR: {
            int cantidadDeCriaturas;
            cout << "Ingrese la cantidad de criaturas invocadas: ";
            cin >> cantidadDeCriaturas;
            return make_shared<Conjurador>(inteligencia, edad, cantidadDeCriaturas);
        }
        case TipoMago::BRUJO: {
            int energiaOscura;
            int pactoConDemonio;

            cout << "Ingrese la energia oscura del brujo: ";
            cin >> energiaOscura;

            cout << "El brujo tiene pacto con demonio?: " << endl;
            cout << "0. No" << endl;
            cout << "1. Si" << endl;
            cin >> pactoConDemonio;

            while (pactoConDemonio < 0 || pactoConDemonio > 1) {
                cout << "Opcion no valida. Ingrese nuevamente si el brujo tiene pacto con demonio: " << endl;
                cin >> pactoConDemonio;
            }

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
            int montado;
            cout << "El caballero esta montado?: " << endl;
            cout << "0. No" << endl;
            cout << "1. Si" << endl;
            cin >> montado;
            while (montado < 0 || montado > 1) {
                cout << "Opcion no valida. Ingrese nuevamente si el caballero esta montado: " << endl;
                cin >> montado;
            }

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
            cout << "Elija el tipo de Mago: " << endl;
            cout << "1. Hechicero" << endl;
            cout << "2. Conjurador" << endl;
            cout << "3. Brujo" << endl;
            cout << "4. Nigromante" << endl;
            int tipoMago;
            cin >> tipoMago;
            while (tipoMago < 1 || tipoMago > 4) {
                cout << "Opcion no valida. Ingrese nuevamente el tipo de mago: " << endl;
                cin >> tipoMago;
            }

            return crearMago(static_cast<TipoMago>(tipoMago));
        }
        case TipoPersonaje::GUERRERO: {
            cout << "Elija el tipo de Guerrero: " << endl;
            cout << "1. Barbaro" << endl;
            cout << "2. Paladin" << endl;
            cout << "3. Caballero" << endl;
            cout << "4. Mercenario" << endl;
            cout << "5. Gladiador" << endl;
            int tipoGuerrero;
            cin >> tipoGuerrero;
            while (tipoGuerrero < 1 || tipoGuerrero > 5) {
                cout << "Opcion no valida. Ingrese nuevamente el tipo de guerrero: " << endl;
                cin >> tipoGuerrero;
            }

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
            int largo_cm;
            cout << "Ingrese el largo del baston: ";
            cin >> largo_cm;
            return make_shared<Baston>(durabilidad, largo_cm);
        }
        case TipoItemMagico::LIBRO_DE_HECHIZOS: {
            return make_shared<LibroDeHechizos>(durabilidad);
        }
        case TipoItemMagico::POCION: {
            int efecto;
            int esPermanente;
            cout << "Ingrese el efecto de la pocion: " << endl;
            cout << "Seleccione el efecto de la poción:" << endl;
            cout << "0. Veneno" << endl;
            cout << "1. Paralizante" << endl;
            cout << "2. Envejecedora" << endl;
            cout << "3. Lentificante" << endl;
            cin >> efecto;
            while (efecto < 0 || efecto > 3) {
                cout << "Opcion no valida. Ingrese nuevamente el efecto de la pocion: " << endl;
                cin >> efecto;
            }

            string nombreEfecto = vector<string>{"veneno", "paralizante", "envejecedora", "lentificante"}[efecto];

            cout << "La pocion es permanente?: " << endl;
            cout << "0. No" << endl;
            cout << "1. Si" << endl;
            cin >> esPermanente;
            while (esPermanente < 0 || esPermanente > 1) {
                cout << "Opcion no valida. Ingrese nuevamente si la pocion es permanente: " << endl;
                cin >> esPermanente;
            }

            return make_shared<Pocion>(durabilidad, nombreEfecto, esPermanente);
        }
        case TipoItemMagico::AMULETO: {
            int bonoSuerte;
            cout << "El amuleto tiene bono de suerte?: " << endl;
            cout << "0. No" << endl;
            cout << "1. Si" << endl;
            cin >> bonoSuerte;
            while (bonoSuerte < 0 || bonoSuerte > 1) {
                cout << "Opcion no valida. Ingrese nuevamente si el amuleto tiene bono de suerte: " << endl;
                cin >> bonoSuerte;
            }

            return make_shared<Amuleto>(durabilidad, bonoSuerte);
        }
        default:
            throw invalid_argument("Tipo de item magico no válido");
    }
};

shared_ptr<ArmasDeCombate> crearArmaDeCombate(TipoArmaDeCombate tipo) {
    int material;
    int peso;

    cout << "Ingrese el material del arma de combate: " << endl;
    cout << "0. Piedra" << endl;
    cout << "1. Madera" << endl;
    cout << "2. Hierro" << endl;
    cin >> material;
    while(material < 0 || material > 2) {
        cout << "Opcion no valida. Ingrese nuevamente el material del arma de combate: " << endl;
        cin >> material;
    }
    string nombreMaterial = vector<string>{"piedra", "madera", "hierro"}[material];

    cout << "Ingrese el peso del arma de combate: ";
    cin >> peso;

    switch (tipo) {
        case TipoArmaDeCombate::HACHA_SIMPLE: {
            int conGema;
            cout << "El hacha simple tiene gema?: " << endl;
            cout << "0. No" << endl;
            cout << "1. Si" << endl;
            cin >> conGema;
            while (conGema < 0 || conGema > 1) {
                cout << "Opcion no valida. Ingrese nuevamente si el hacha simple tiene gema: " << endl;
                cin >> conGema;
            }

            return make_shared<HachaSimple>(nombreMaterial, peso, conGema);
        }
        case TipoArmaDeCombate::HACHA_DOBLE: {
            int largo;
            int filoExtra;
            cout << "Ingrese el largo del hacha doble: ";
            cin >> largo;
            cout << "El hacha doble tiene filo extra?: " << endl;
            cout << "0. No" << endl;
            cout << "1. Si" << endl;
            cin >> filoExtra;
            while (filoExtra < 0 || filoExtra > 1) {
                cout << "Opcion no valida. Ingrese nuevamente si el hacha doble tiene filo extra: " << endl;
                cin >> filoExtra;
            }

            return make_shared<HachaDoble>(nombreMaterial, peso, largo, filoExtra);
        }
        case TipoArmaDeCombate::ESPADA: {
            int largo;
            int tieneBrillo;
            cout << "Ingrese el largo de la espada: ";
            cin >> largo;
            cout << "La espada tiene brillo?: " << endl;
            cout << "0. No" << endl;
            cout << "1. Si" << endl;
            cin >> tieneBrillo;
            while (tieneBrillo < 0 || tieneBrillo > 1) {
                cout << "Opcion no valida. Ingrese nuevamente si la espada tiene brillo: " << endl;
                cin >> tieneBrillo;
            }

            return make_shared<Espada>(nombreMaterial, peso, largo, tieneBrillo);
        }
        case TipoArmaDeCombate::LANZA: {
            int largo;
            int cantidadPuntas;
            cout << "Ingrese el largo de la lanza: ";
            cin >> largo;
            cout << "Ingrese la cantidad de puntas de la lanza: ";
            cin >> cantidadPuntas;
            return make_shared<Lanza>(nombreMaterial, peso, largo, cantidadPuntas);
        }
        case TipoArmaDeCombate::GARROTE: {
            int tienePicos;
            int doblePunta;
            cout << "El garrote tiene picos?: " << endl;
            cout << "0. No" << endl;
            cout << "1. Si" << endl;
            cin >> tienePicos;
            while (tienePicos < 0 || tienePicos > 1) {
                cout << "Opcion no valida. Ingrese nuevamente si el garrote tiene picos: " << endl;
                cin >> tienePicos;
            }

            cout << "El garrote tiene doble punta?: " << endl;
            cout << "0. No" << endl;
            cout << "1. Si" << endl;
            cin >> doblePunta;
            while (doblePunta < 0 || doblePunta > 1) {
                cout << "Opcion no valida. Ingrese nuevamente si el garrote tiene doble punta: " << endl;
                cin >> doblePunta;
            }

            return make_shared<Garrote>(nombreMaterial, peso, tienePicos, doblePunta);
        }
        default:
            throw invalid_argument("Tipo de arma de combate no válido");
    }
};

shared_ptr<Arma> PersonajeFactory::crearArma(TipoArma tipo) {
    switch (tipo) {
        case TipoArma::ITEM_MAGICO: {
            cout << "Elija el tipo de Item Magico: " << endl;
            cout << "1. Baston" << endl;
            cout << "2. Libro de Hechizos" << endl;
            cout << "3. Pocion" << endl;
            cout << "4. Amuleto" << endl;
            int tipoItemMagico;
            cin >> tipoItemMagico;
            while (tipoItemMagico < 1 || tipoItemMagico > 4) {
                cout << "Opcion no valida. Ingrese nuevamente el tipo de item magico: " << endl;
                cin >> tipoItemMagico;
            }

            return crearItemMagico(static_cast<TipoItemMagico>(tipoItemMagico));
        }
        case TipoArma::ARMA_DE_COMBATE: {
            cout << "Elija el tipo de Arma de Combate: " << endl;
            cout << "1. Hacha Simple" << endl;
            cout << "2. Hacha Doble" << endl;
            cout << "3. Espada" << endl;
            cout << "4. Lanza" << endl;
            cout << "5. Garrote" << endl;
            int tipoArmaDeCombate;
            cin >> tipoArmaDeCombate;
            while (tipoArmaDeCombate < 1 || tipoArmaDeCombate > 5) {
                cout << "Opcion no valida. Ingrese nuevamente el tipo de arma de combate: " << endl;
                cin >> tipoArmaDeCombate;
            }

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

