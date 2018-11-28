#ifndef ESPECIAL_H_INCLUDED
#define ESPECIAL_H_INCLUDED
#include "Hechizo.h"

class Especial : public Hechizo{
    private:
        int anioManifiesto;
        String descripcion;
    public:
        //Especial();
        Especial(int, String, int, String);
        int getAnioManifiesto();
        String getDescripcion();

};


#endif // ESPECIAL_H_INCLUDED
