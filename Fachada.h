#ifndef FACHADA_H_INCLUDED
#define FACHADA_H_INCLUDED

#include "Brujas.h"
#include "Suprema.h"
#include "Comun.h"
#include "Hechizo.h"

class Fachada
{

    private:
        Brujas brujas;

    public:
        Fachada();
        void RegistrarBruja(Bruja*);

        bool ExisteBruja(String);
        Bruja * ObtenerBruja(String);
        Iterador listarBruja();
        void registrarHechizo(String  , Hechizo *);
        void listadoDetalleBrujaMasAntigua(Brujas);
        Iterador getSupremas();
        void cantidadHechizosPorTipo(Bruja *, int &, int&);
};

#endif // FACHADA_H_INCLUDED
