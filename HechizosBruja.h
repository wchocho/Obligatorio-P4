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
        bool estaLlena();
        void insBack (Hechizo);
        bool existeHechizo(Hechizo);

 };

#endif // HECHIZOSBRUJA_H_INCLUDED
