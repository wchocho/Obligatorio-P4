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
    // èndiente de implementae
    return 0;

}
