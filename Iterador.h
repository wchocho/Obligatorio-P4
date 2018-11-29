#ifndef ITERADOR_H
#define ITERADOR_H

#include <stdio.h>
#include "Brujas.h"


class Iterador : public Brujas
{
        private:
        struct Nodo{
            Bruja* info;
            Nodo* sig;
        };

        struct LPPF{
            Nodo* prim;
            Nodo* ult;
            Nodo* actual;
        };

        LPPF lppf;
        Nodo* actual;

        public:
        Iterador();
        ~Iterador();

        void insertarBruja (Bruja*);
        Bruja* proximaBruja ();
        bool hayMasBrujas ();

    protected:


};

#endif // ITERADOR_H
