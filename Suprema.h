#ifndef SUPREMA_H_INCLUDED
#define SUPREMA_H_INCLUDED
#include "Bruja.h"
#include "Fecha.h"

class Suprema: public Bruja{
    private:
        Fecha fechaNacimiento;
        int cantPoderes;

    public:
        Suprema();
        Suprema(int, String, HechizosBruja, Fecha, int);
        Fecha getFechaNacimiento();
        int getCantPoderes();
        String getTipoBruja();
        int calcularPuntos();

};


#endif // SUPREMA_H_INCLUDED
