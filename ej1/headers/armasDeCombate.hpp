#pragma once
#include "armas.hpp"
using namespace std;

class HachaSimple : public ArmasDeCombate {
    public: 
        // Constructor
        HachaSimple(string material, int peso_gr, bool conGema);

        // Metodos
        bool usar() override;
        void showInfo() override;
    
    private:
        bool conGema;
};

class HachaDoble : public ArmasDeCombate {
    public: 
        // Constructor
        HachaDoble(string material, int peso_gr, int largo_cm, bool filoExtra);

        // Metodos
        bool usar() override;
        void showInfo() override;
    
    private:
        int largo_cm;
        bool filoExtra;
};

class Espada : public ArmasDeCombate {
    public: 
        // Constructor
        Espada(string material, int peso_gr, int largo_cm, bool tieneBrillo);

        // Metodos
        bool usar() override;
        void showInfo() override;
    
    private:
        int largo_cm;
        bool tieneBrillo;
};

class Lanza : public ArmasDeCombate {
    public: 
        // Constructor
        Lanza(string material, int peso_gr, int largo_cm, int cantidadPuntas);

        // Metodos
        bool usar() override;
        void showInfo() override;
    
    private:
        int largo_cm;
        int cantidadPuntas;
};

class Garrote : public ArmasDeCombate {
    public: 
        // Constructor
        Garrote(string material, int peso_gr, bool tienePicos, bool doblePunta);

        // Metodos
        bool usar() override;
        void showInfo() override;
    
    private:
        bool tienePicos;
        bool doblePunta;
};