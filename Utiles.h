#ifndef UTILES_H_INCLUDED
#define UTILES_H_INCLUDED

#include <cstdlib>
#include "Fachada.h"
#include "Fecha.h"
#include "Bruja.h"
#include "Suprema.h"
#include "Comun.h"
class Utiles
{
    private:
        Fachada fachada;

    public:
        Utiles();

        //menu
        void registrarNuevaBrujaSuprema ();

        bool preguntoReintentar (string);

        //impresiones
        void imprimirMenu ();

void listadoBrujas();


};

/*
void borrarPantalla();
void continuar();
//void preguntarCedula(long int &cedula);
*/
#endif // UTILES_H_INCLUDED
