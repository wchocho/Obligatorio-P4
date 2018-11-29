#ifndef COMUN_H_INCLUDED
#define COMUN_H_INCLUDED
#
#include "Bruja.h"
#include "Suprema.h"
#include "String.h"

class Comun: public Bruja{
    private:
        String regionOrigen;
        bool vuelaEscoba;
        Suprema* suprema_vinculada;
    public:
        Comun();
        Comun(String, String, HechizosBruja, String, bool, Suprema*);
        String getRegionOrigen();
        bool getVuelaEscoba();
        Suprema * getSuprema();
        int getTipoBruja();
        int calcularPuntos();

};

#endif // COMUN_H_INCLUDED
