#ifndef HECHIZO_H_INCLUDED
#define HECHIZO_H_INCLUDED

class Hechizo{
    private:
        int numero;
        String nombre;
    public:
        Hechizo();
        Hechizo(int, String);
        int getNumero();
        String getNombre();

};

#endif // HECHIZO_H_INCLUDED
