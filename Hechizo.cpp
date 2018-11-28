#include "Hechizo.h"



Hechizo :: Hechizo(int num, String nom): nombre(nom){
    numero = num;
}

int Hechizo :: getNumero(){
    return numero;
}

String Hechizo :: getNombre(){
    return nombre;
}
