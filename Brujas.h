#ifndef BRUJAS_H_INCLUDED
#define BRUJAS_H_INCLUDED
#include "Bruja.h"

class Brujas{

    public:
        Brujas ();
        bool member (String);
        void Insert (Bruja *);
        Bruja * Find (String);
    private:
        struct Nodo {
            Bruja * info;
            Nodo * hizq;
            Nodo * hder;
        };
        Nodo * abb;
        void InsertEnArbol (Bruja *, Nodo * &);
        //Bruja * ObtenerDelArbol (Nodo *, String);
};

#endif // BRUJAS_H_INCLUDED
