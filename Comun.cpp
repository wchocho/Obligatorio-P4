#include "Comun.h"
#include "String.h"

Comun :: Comun(String id, String nom, HechizosBruja hechizos , String region, bool volar): Bruja(id, nom, hechizos), regionOrigen(region){
    vuelaEscoba = volar;
}

String Comun :: getRegionOrigen(){
    return regionOrigen;
}

bool Comun :: getVuelaEscoba(){
    return vuelaEscoba;
}

int Comun :: getTipoBruja(){
    return 1;
}

int Comun :: calcularPuntos(){
    // èndiente de implementae
    return 0;

}
