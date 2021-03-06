#ifndef HECHIZOSBRUJA_H_INCLUDED
#define HECHIZOSBRUJA_H_INCLUDED
#include "Hechizo.h"

int const CANT_HECHIZOS = 20;

class HechizosBruja{
    private:
        Hechizo * arre[CANT_HECHIZOS];
        int tope;
    public:
        HechizosBruja();
        bool esvacia();
        bool estaLlena();
        void insBack (Hechizo*);
        bool existeHechizo(Hechizo*);
        int getTope();
        void cantidadHechizosPorTipo(int &, int&);
        Hechizo* getHechizo(int);
        bool existeHechizoPorId(int);


 };

#endif // HECHIZOSBRUJA_H_INCLUDED
