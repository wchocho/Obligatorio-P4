#ifndef BRUJAS_H_INCLUDED
#define BRUJAS_H_INCLUDED
#include "Bruja.h"
class Brujas{
    private:
        struct Nodo {
            Bruja * info;
            Nodo * hizq;
            Nodo * hder;
        };
        Nodo * abb;
        bool ExisteEnArbol (Nodo *, String);
        void InsertEnArbol (Nodo * &, Bruja *);
        Bruja * ObtenerDelArbol (Nodo *, String);
    public:
        Brujas ();
        bool member (String);
        void Insert (Bruja *);
        Bruja * Find (String);

};

#endif // BRUJAS_H_INCLUDED
