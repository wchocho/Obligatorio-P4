#ifndef FACHADA_H_INCLUDED
#define FACHADA_H_INCLUDED

#include "Brujas.h"
#include "Suprema.h"
#include "Comun.h"
class Fachada
{

    private:
        Brujas brujas;

    public:
        Fachada();
        void RegistrarBruja(Bruja*, int&);

        bool ExisteBruja(String);
        Bruja * ObtenerBruja(String);


};

#endif // FACHADA_H_INCLUDED
