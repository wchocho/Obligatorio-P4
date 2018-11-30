#ifndef ITERADOR_H
#define ITERADOR_H

#include <stdio.h>
#include "Bruja.h"



class Iterador {
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
        Bruja* actualBruja ();

    protected:


};

#endif // ITERADOR_H
