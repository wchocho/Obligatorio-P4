#ifndef COMUN_H_INCLUDED
#define COMUN_H_INCLUDED
#include "Bruja.h"
#include "String.h"

class Comun: public Bruja{
    private:
        String regionOrigen;
        bool vuelaEscoba;

    public:
        Comun();
        Comun(int, String, HechizosBruja, String, bool);
        String getRegionOrigen();
        bool getVuelaEscoba();
        String getTipoBruja();
        int calcularPuntos();

};

#endif // COMUN_H_INCLUDED
