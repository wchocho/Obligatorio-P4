#ifndef COMUN_H_INCLUDED
#define COMUN_H_INCLUDED

class Comun: public Bruja{
    private:
        String regionOrigen;
        bool vuelaEscoba;

    public:
        Comun();
        Comun(int, String, HechizosBruja, String, bool);
        int regionOrigen();
        bool vuelaEscoba();
        String getTipoBruja();
        int calcularPuntos();

};

#endif // COMUN_H_INCLUDED
