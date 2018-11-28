#include "Comun.h"
#include "String.h"

Comun :: Comun(int id, String nom, HechizosBruja hechizos , String region, bool volar): Bruja(id, nom, hechizos), regionOrigen(region){
    vuelaEscoba = volar;
}

String Comun :: getRegionOrigen(){
    return regionOrigen;
}

bool Comun :: getVuelaEscoba(){
    return vuelaEscoba;
}

String Comun :: getTipoBruja(){
    String resu("Comun");
    return resu;
}

int Comun :: calcularPuntos(){
    // èndiente de implementae
    return 0;

}
