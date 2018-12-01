#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <iostream>
#include <limits>
using namespace std;

class Fecha
{
    private:
        int dia;
        int mes;
        int anio;

        void sumo1(Fecha&);
        void resto1();

    public:
        Fecha();
        Fecha(int, int, int);
        Fecha(const Fecha&);
        int Getdia();
        void Setdia(int);
        int Getmes();
        void Setmes(int);
        int Getanio();
        void Setanio(int);

        bool operator< (Fecha);
        bool operator== (Fecha);
        Fecha operator++ ();
        Fecha operator++ (int);
        Fecha operator+ (int);
        int operator- (Fecha);
        bool esValida ();
        void imprimir();
        void scan();

};

#endif // FECHA_H_INCLUDED
