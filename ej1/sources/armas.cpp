#include "armas.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*Implementacion Clase Abstracta ItemasMagicos*/ 

// Constructor
ItemsMagicos::ItemsMagicos(string nombre, int durabilidad) : nombre(nombre), durabilidad(durabilidad) {};

// Metodos
string ItemsMagicos::getNombre() {
    return nombre;
};
double ItemsMagicos::getDanio() {
    return danio;
};
bool ItemsMagicos::getRecargaUasada() {
    return recargaUsada;
};
bool ItemsMagicos::intentarRecargar() {
    double prob = static_cast<double>(rand()) / RAND_MAX; // Genera un número aleatorio entre 0 y 1
    
    if (prob < 0.5) { // 50% de probabilidad de recargar
        durabilidad = 2; // Recarga la durabilidad a 10
        recargaUsada = true;

        return true;
    } else {
        cout << "No se pudo recargar el item." << endl;
        
        return false;
    }
};


/*Implementacion Clase Abstracta AemasDeCombate*/ 

// Constructor
ArmasDeCombate::ArmasDeCombate(string nombre, string material, int peso_gr) : nombre(nombre), material(material), peso_gr(peso_gr) {};

// Metodos
string ArmasDeCombate::getNombre() {
    return nombre;
};
double ArmasDeCombate::getDanio() {
    return danio;
};
bool ArmasDeCombate::esPesada() {
    return peso_gr > 20; // Considera pesada si el peso es mayor a 20
};