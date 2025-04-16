#pragma once
#include "armas.hpp"
using namespace std;

class HachaSimple : public ArmasDeCombate {
    public: 
        // Constructor
        HachaSimple( string material, double peso, bool conGema);

        // Metodos
        void usar() override;
        void showInfo() override;
    
    private:
        bool conGema;
};

class HachaDoble : public ArmasDeCombate {
    public: 
        // Constructor
        HachaDoble( string material, double peso, double largo, bool filoExtra);

        // Metodos
        void usar() override;
        void showInfo() override;
    
    private:
        double largo;
        bool filoExtra;
};

class Espada : public ArmasDeCombate {
    public: 
        // Constructor
        Espada( string material, double peso, double largo, bool tieneBrillo);

        // Metodos
        void usar() override;
        void showInfo() override;
    
    private:
        double largo;
        bool tieneBrillo;
};

class Lanza : public ArmasDeCombate {
    public: 
        // Constructor
        Lanza(string material, double peso, int largo, int cantidadPuntas);

        // Metodos
        void usar() override;
        void showInfo() override;
    
    private:
        double largo;
        int cantidadPuntas;
};

class Garrote : public ArmasDeCombate {
    public: 
        // Constructor
        Garrote(string material, double peso, bool tienePicos, bool doblePunta);

        // Metodos
        void usar() override;
        void showInfo() override;
    
    private:
        bool tienePicos;
        bool doblePunta;
};