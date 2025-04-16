#pragma once
#include "armas.hpp"
#include <memory>
#include <map>
#include <vector>
using namespace std;

class Baston : public ItemsMagicos {
    public: 
        // Contenedor
        Baston(int durabilidad, int largo_cm);

        // Metodos
        void usar() override;
        void showInfo() override;

    private:
        int largo_cm;
        //shared_ptr<LibroDeHechizos> libroAsociado;  // Si se usa la combinacion Baston + Libro 
        //shared_ptr<Amuleto> amuletoAsociado; // Si se usa la combinacion Baston + Amuleto
    };

class LibroDeHechizos : public ItemsMagicos {
    public: 
        // Contenedor
        LibroDeHechizos(int durabilidad);
        
        // Metodos
        void usar() override;
        void showInfo() override;

        void setConBaston(bool cond);
        void agregarHechizo(string hechizo);

    protected:
        bool conBaston = false; // Si se usa la combinacion Baston + Libro
        vector<string> listaHechizos = {"Bola de fuego", "Tormenta de rayos", "Rayo congelante", "Maleficio sagrado", "Contraconjuro", "Tormenta de hielo"};    
};

class Pocion : public ItemsMagicos {
    public: 
        // Contenedor
        Pocion(int durabilidad, string efecto, bool esParmanente);
        
        // Metodos
        void usar() override;
        void showInfo() override;
        
    private:
        string efecto; // Puede ser: 0=veneno, 1=paralizante, 2=envejecedora, 3=lentificante
        bool esPermanente;
};

class Amuleto : public ItemsMagicos {
    public: 
        // Contenedor
        Amuleto(int durabilidad, bool bonoSurte);

        // Metodos
        void usar() override;
        void showInfo() override;

        
    private:
        bool bonoSuerte;
        //shared_ptr<Baston> bastonAsociado; // Si se usa la combinacion Amuleto + Baston
};