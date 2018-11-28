#ifndef BRUJA_H_INCLUDED
#define BRUJA_H_INCLUDED

#include "String.h"
#include "HechizosBruja.h"

class Bruja{
    private:
        int identificador;
        String nombre;
        HechizosBruja hechizos;

    public:
        Bruja();
        Bruja(int, String, HechizosBruja);
        int getIdentificador();
        String gerNombre();
        HechizosBruja getHechizos();


        virtual String getTipoBruja() = 0;
        virtual int calcularPuntos() = 0;

};


#endif // BRUJA_H_INCLUDED
