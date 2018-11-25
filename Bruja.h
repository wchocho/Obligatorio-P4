#ifndef BRUJA_H_INCLUDED
#define BRUJA_H_INCLUDED
#include "Fecha.h"
#include "String.h"
#include "HechizosBruja.h"
class Bruja{
    private:
        int identificador;
        String nombre;
        HechizosBruja hechizos;

    public:
        Bruja(); // hay que hacer este constructor?
        Bruja(int, String, HechizosBruja);
        int getIdentificador();
        String gerNombre();
        //HechizosBruja getHechizos(); -- ver si es correcto este.
        // aca me queda la duda si vas definidos asi.
        virtual String getTipoBruja() = 0;
        virtual int calcularPuntos() = 0;

};


#endif // BRUJA_H_INCLUDED
