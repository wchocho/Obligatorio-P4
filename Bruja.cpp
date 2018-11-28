#include "Bruja.h"

// si es abstracta aplican los constructores?
Bruja :: Bruja(): nombre(), hechizos(){

}
Bruja :: Bruja(String id, String nom, HechizosBruja hechizos_bruja): identificador(id), nombre(nom), hechizos(hechizos_bruja){

}

String Bruja :: getIdentificador(){
    return identificador;
}

String Bruja :: gerNombre(){
    return nombre;
}

HechizosBruja Bruja :: getHechizos(){
    return hechizos;
}




