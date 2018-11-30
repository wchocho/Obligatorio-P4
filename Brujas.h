#ifndef BRUJAS_H_INCLUDED
#define BRUJAS_H_INCLUDED
#include "Bruja.h"
#include "Suprema.h"
#include "Iterador.h"
#include "Fecha.h"


class Brujas{

    public:
        Brujas ();
        bool member (String);
        void Insert (Bruja *);
        Bruja * Find (String);

        Iterador listarBruja ();
        Iterador darSupremas();
    private:
        struct Nodo {
            Bruja * info;
            Nodo * hizq;
            Nodo * hder;
        };
        Nodo * abb;

        void mayorSuprema(String & , Fecha , Brujas abb );
        void InsertEnArbol (Bruja *, Nodo * &);
        void listarBrujaRec (Nodo* , Iterador & );
        /*void mostrarArbolOrdenado(Nodo *);*/
void darSupremasRec(Nodo*, Iterador &);


        //Bruja * ObtenerDelArbol (Nodo *, String);
};

#endif // BRUJAS_H_INCLUDED
