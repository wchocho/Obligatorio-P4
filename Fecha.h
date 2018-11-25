#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
    private:
        int dia;
        int mes;
        int anio;
    public:
        Fecha();
        Fecha(int, int, int);
        Fecha(const Fecha &);
        int getDia();
        int getMes();
        int getAnio();
        void setDia(int);
        void setMes(int);
        void setAnio(int);
        bool operator<(Fecha);
        bool operator==(Fecha);
        //(devuelve la fecha correspondiente al día siguiente a la fecha dada)
        //prefijo
        Fecha operator++();
        //postfijo
        Fecha operator++(int);
        Fecha operator+(int);
        // (devuelve la cantidad de días de diferencia entre 2 fechas)
        int operator-(Fecha);
        bool esValida();
        int cantidadDiasMes(int, int);


};


#endif // FECHA_H_INCLUDED
