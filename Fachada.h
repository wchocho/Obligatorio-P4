#ifndef FACHADA_H_INCLUDED
#define FACHADA_H_INCLUDED

#include <cstdlib>
#include "Fachada.h"
#include "Fecha.h"
#include "Bruja.h"
#include "Suprema.h"
#include "Comun.h"
#include "Especial.h"
#include "Brujas.h"
#include "Suprema.h"
#include "Comun.h"
#include "Hechizo.h"
#include <stdio.h>
#include <conio.h>
#include <clocale>

class Fachada
{

    private:

  Brujas brujas;
    public:
void menuInicio();
        Fachada();
        void RegistrarBruja(Bruja*);

        bool ExisteBruja(String);
        Bruja * ObtenerBruja(String);
        Iterador listarBruja();
        void registrarHechizo(String  , Hechizo *);
        void listadoDetalleBrujaMasAntigua(Brujas);
        Iterador getSupremas();
        void cantidadHechizosPorTipo(Bruja *, int &, int&);

        //menu
        void registrarNuevaBruja ();


        //impresiones
        void imprimirMenu ();
        void listadoBrujas();
        void registrarHechizo();
        //void cantidadHechizosPorBruja();
        void listadoDetallePorBruja();
        //void listadoDetalleBrujaMasAntigua();
        void listadoDetalleBrujaHechizos();


        // auxiliares
        bool preguntoReintentar (string);
        void imprimirDatosBasicosBruja(Bruja *);
        void imprimirDatosSuprema(Suprema *);
        void imprimirDatosComun(Comun *);
        String boolAString(bool);
        void cantidadHechizosPorTipo();
        void listadoDetalleBrujaMasAntigua();
        void mayorSuprema();





};

#endif // FACHADA_H_INCLUDED
