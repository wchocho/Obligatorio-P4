#ifndef BRUJA_H_INCLUDED
#define BRUJA_H_INCLUDED

#include "String.h"
#include "HechizosBruja.h"

class Bruja{
    private:
        String identificador;
        String nombre;
        HechizosBruja hechizos;

    public:
        Bruja();
        Bruja(String, String, HechizosBruja);
        String getIdentificador();
        String getNombre();
        HechizosBruja getHechizos();

         void  insertarHechizos(Hechizo *);
        virtual int getTipoBruja() = 0;
        virtual int calcularPuntos() = 0;


};


#endif // BRUJA_H_INCLUDED
