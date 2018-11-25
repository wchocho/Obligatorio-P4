#ifndef SUPREMA_H_INCLUDED
#define SUPREMA_H_INCLUDED

class Suprema: public Bruja{
    private:
        Fecha fechaNacimiento;
        int cantPoderes;

    public:
        Suprema();
        Bruja(int, String, HechizosBruja, Fecha, int);
        int getFechaNacimiento();
        int cantPoderes();
        String getTipoBruja();
        int calcularPuntos();

};


#endif // SUPREMA_H_INCLUDED
