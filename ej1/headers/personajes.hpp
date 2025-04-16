#pragma once
#include <armas.hpp>
#include <string>
#include <memory>
using namespace std;

class Personaje {
    public:
        virtual string getNombre() = 0;
        virtual int getHP() = 0;
        virtual string getArma() = 0;
        virtual bool estaVivo() = 0;
        virtual void agregarArma(shared_ptr<Arma> arma) = 0;
        virtual int atacar() = 0;
        virtual void recibirDanio(int danio) = 0;
};

class Mago : public Personaje {
    public:
        // Constructor
        Mago(string nombre, int inteligencia, int edad);

        // Metodos
        virtual string getNombre() override;
        virtual int getHP() override;
        virtual string getArma() override;
        virtual bool estaVivo() override;
        virtual void agregarArma(shared_ptr<Arma> arma) override;
        virtual int atacar() override;
        virtual void recibirDanio(int danio) override;

        //virtual void regenerarMana();

    protected:
        string nombre;
        int HP = 100;
        int mana = 100; // Mana del mago
        int inteligencia;
        int edad;

        shared_ptr<ItemsMagicos> item1; // Item Magico 1 del mago
        shared_ptr<ItemsMagicos> item2; // Item Magico 2 del mago
};

class Guerrero : public Personaje {
    public:
        // Constructor
        Guerrero(string nombre, int fuerza, int velocidad);

        // Metodos
        virtual string getNombre() override;
        virtual int getHP() override;
        virtual string getArma() override;
        virtual bool estaVivo() override;
        virtual void agregarArma(shared_ptr<Arma> arma) override;
        virtual int atacar() override;
        virtual void recibirDanio(int danio) override;

        //virtual void regenerarEnergia();

    protected:
        string nombre;
        int HP = 100;
        int fuerza;
        int velocidad;
        double energia = 100; // Energia del guerrero

        shared_ptr<ArmasDeCombate> arma1; // Arma 1 del guerrero
        shared_ptr<ArmasDeCombate> arma2; // Arma 2 del guerrero
};