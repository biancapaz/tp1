#pragma once
#include "tipos.hpp"
#include <armas.hpp>
#include <string>
#include <memory>
using namespace std;

class Personaje {
    public:
        // Getters
        virtual string getNombre() = 0;
        virtual TipoPersonaje getTipo() = 0;
        virtual int getHP() = 0;
        virtual shared_ptr<Arma> getArma() = 0;
        virtual bool estaVivo() = 0;

        // Combate
        virtual void agregarArma(shared_ptr<Arma> arma) = 0;
        virtual int atacar() = 0;
        virtual void recibirDanio(int danio) = 0;
        virtual int calcularDanioBase() = 0;
};

class Mago : public Personaje {
    public:
        // Constructor
        Mago(string nombre, int inteligencia, int edad);

        // Metodos
        virtual string getNombre() override;
        virtual TipoPersonaje getTipo() override;
        virtual int getHP() override;
        virtual shared_ptr<Arma> getArma() override;
        virtual bool estaVivo() override;

        virtual void agregarArma(shared_ptr<Arma> arma) override;
        virtual int atacar() override;
        virtual void recibirDanio(int danio) override;
        virtual int calcularDanioBase() override;

    protected:
        string nombre;
        TipoPersonaje tipo = TipoPersonaje::MAGO;
        int HP = 100;
        int mana = 100; // Mana del mago
        int inteligencia;
        int edad;

        shared_ptr<ItemsMagicos> item1 = nullptr; // Item Magico 1
        shared_ptr<ItemsMagicos> item2 = nullptr; // Item Magico 2
        shared_ptr<ItemsMagicos> itemEnUso = item1; // Siempre como defaul se usa el item 1
};

class Guerrero : public Personaje {
    public:
        // Constructor
        Guerrero(string nombre, int fuerza, int velocidad);

        // Metodos
        virtual string getNombre() override;
        virtual TipoPersonaje getTipo() override;
        virtual int getHP() override;
        virtual shared_ptr<Arma> getArma() override;
        virtual bool estaVivo() override;

        virtual void agregarArma(shared_ptr<Arma> arma) override;
        virtual int atacar() override;
        virtual void recibirDanio(int danio) override;
        virtual int calcularDanioBase() override;
        virtual void cambiarArmaEnUso(); // Cambia el arma en uso

    protected:
        string nombre;
        TipoPersonaje tipo = TipoPersonaje::GUERRERO;
        int HP = 100;
        int fuerza;
        int velocidad;
        double energia = 100; // Energia del guerrero

        shared_ptr<ArmasDeCombate> arma1 = nullptr; // Arma 1 del guerrero
        shared_ptr<ArmasDeCombate> arma2 = nullptr; // Arma 2 del guerrero
        shared_ptr<ArmasDeCombate> armaEnUso = arma1; // siempre como default se usa el arma 1
};