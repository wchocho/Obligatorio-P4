#ifndef FACHADA_H_INCLUDED
#define FACHADA_H_INCLUDED

#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <clocale>

#include "Brujas.h"
#include "Especial.h"
#include "Comun.h"



class Fachada
{

private:

    Brujas brujas;
    void imprimirMenu ();
    bool preguntoReintentar (string);
    void imprimirDatosBasicosBruja(Bruja *);
    void imprimirDatosSuprema(Suprema *);
    void imprimirDatosComun(Comun *);
    String boolAString(bool);
    bool ExisteBruja(String);
    Bruja * ObtenerBruja(String);
    Iterador listarBruja();
    void registrarHechizo(String, Hechizo *);
    void listadoDetalleBrujaMasAntigua(Brujas);
    Iterador getSupremas();

public:
    Fachada();
    void menuInicio();
    //menu
    void registrarBruja();
    void registrarHechizo();
    void cantidadHechizosPorTipo();
    void listadoBrujas();
    void listadoDetallePorBruja();
    void listadoDetalleBrujaHechizos();
    void mayorSuprema();
    void listadoDetalleBrujaMasAntigua();

};

#endif // FACHADA_H_INCLUDED
