#ifndef BRUJAS_H_INCLUDED
#define BRUJAS_H_INCLUDED
#include "Bruja.h"
#include "Iterador.h"


class Brujas{

    public:
        Brujas ();
        bool member (String);
        void Insert (Bruja *);
        Bruja * Find (String);
        Iterador listarBruja ();
    private:
        struct Nodo {
            Bruja * info;
            Nodo * hizq;
            Nodo * hder;
        };
        Nodo * abb;
        void InsertEnArbol (Bruja *, Nodo * &);
        void listarBrujaRec (Nodo* , Iterador & );

        //Bruja * ObtenerDelArbol (Nodo *, String);
};

#endif // BRUJAS_H_INCLUDED
