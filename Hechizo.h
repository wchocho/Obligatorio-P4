#ifndef HECHIZO_H_INCLUDED
#define HECHIZO_H_INCLUDED
#include "String.h"
class Hechizo{
    private:
        int numero;
        String nombre;
    public:
        Hechizo();
        Hechizo(int, String);
        Hechizo(const Hechizo &);
        int getNumero();
        String getNombre();
        virtual int getTipoHechizo();

};

#endif // HECHIZO_H_INCLUDED
