#include "armas.hpp"
#include <iostream>
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
void ItemsMagicos::recargar() {
    durabilidad = 10; // Recarga la durabilidad a 10
};


/*Implementacion Clase Abstracta AemasDeCombate*/ 

// Constructor
ArmasDeCombate::ArmasDeCombate(string nombre, string material, double peso) : nombre(nombre), material(material), peso(peso) {};

// Metodos
string ArmasDeCombate::getNombre() {
    return nombre;
};
double ArmasDeCombate::getDanio() {
    return danio;
};
bool ArmasDeCombate::esPesada() {
    return peso > 20; // Considera pesada si el peso es mayor a 20
};