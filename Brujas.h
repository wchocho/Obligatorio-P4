#ifndef BRUJAS_H_INCLUDED
#define BRUJAS_H_INCLUDED
#include "Bruja.h"
#include "Suprema.h"
#include "Iterador.h"
#include "Fecha.h"


class Brujas{

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
        void darSupremasRec(Nodo*, Iterador &);

     public:
        Brujas ();
        bool member (String);
        void Insert (Bruja *);
        Bruja * Find (String);

        Iterador listarBruja ();
        Iterador darSupremas();

        //Bruja * ObtenerDelArbol (Nodo *, String);
};

#endif // BRUJAS_H_INCLUDED
