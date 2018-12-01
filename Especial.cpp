#include "Especial.h"

Especial :: Especial (int num, String nom, int anio, String desc) : Hechizo(num,nom) ,descripcion(desc){
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

