#pragma once
#include <string>
using namespace std;

class Arma { // Interfaz
    public:
        virtual string getNombre() = 0;
        virtual double getDanio() = 0;
        virtual void usar() = 0; // le cambia los valores de durabilidad e imprime los golpes
        virtual void showInfo() = 0; // muestra la informacion de cada arma
};

class ItemsMagicos : public Arma { // Clase Abstracta
    public:
        ItemsMagicos(string nombre, int durabilidad);
        virtual string getNombre() override;
        virtual double getDanio() override;
        virtual void usar() override = 0; // se usa especifico para cada arma porque tienen diferentes atributos
        virtual void showInfo() override = 0; // se muestar especifico para cada arma porque tienen diferentes atributos

        virtual void recargar(); // recarga la durabilidad

    protected:
        string nombre; // Puede ser: bastón, libro de hechizos, poción y amuleto.
        int danio = 10; // Para todas las armas
        int durabilidad; // Limite de usos hasta que se gastan
        //int efectividad; // probabilidad de que sea efectivo
};

class ArmasDeCombate : public Arma { // Clase Abstracta
    public:
        ArmasDeCombate(string nombre, string material, double peso);
        virtual string getNombre() override;
        virtual double getDanio() override;
        virtual void usar() override = 0; // imprime los golpes
        virtual void showInfo() override = 0; // muestra la informacion de cada arma

        virtual bool esPesada();

    protected:
        string nombre; // Puede ser: hacha simple, hacha doble, espada, lanza y garrote.
        double danio = 10; // Para todas las armas
        string material; // Puede ser: piedra, madera y hierro
        double peso; // Afeta en la energia del personaje al usarla
};