#include "Especial.h"

Especial :: Especial (int anio, String desc, int num, String nom) : Hechizo(num,nom) ,descripcion(desc){
    anioManifiesto= anio;
}

int Especial :: getAnioManifiesto (){
    return anioManifiesto;
}

String Especial:: getDescripcion (){
    return descripcion;
}

int Especial :: getTipoHechizo(){
    return 1;
}

