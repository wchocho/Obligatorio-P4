#include "Comun.h"
#include "String.h"

Comun :: Comun(String id, String nom, HechizosBruja hechizos , String region, bool volar, Suprema* sup): Bruja(id, nom, hechizos), regionOrigen(region), suprema_vinculada(sup){
    vuelaEscoba = volar;
}

String Comun :: getRegionOrigen(){
    return regionOrigen;
}

bool Comun :: getVuelaEscoba(){
    return vuelaEscoba;
}

Suprema* Comun :: getSuprema(){
    return suprema_vinculada;
}

int Comun :: getTipoBruja(){
    return 1;
}

int Comun :: calcularPuntos(){
    int total = 0;
    int comunes, especiales;

    getHechizos().cantidadHechizosPorTipo(comunes,especiales);

    total = total + comunes + especiales * 2;
    String region;
    region = "Salem";
    if (getRegionOrigen() == region ){
        total ++;

    }

    return total;

    return 0;

}



