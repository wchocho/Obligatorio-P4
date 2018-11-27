#include "Bruja.h"

// si es abstracta aplican los constructores?
Bruja :: Bruja(): nombre(), hechizos(){

}
Bruja :: Bruja(int id, String nom, HechizosBruja hechizos_bruja): nombre(nom), hechizos(hechizos_bruja){
    identificador = id;
}

int Bruja :: getIdentificador(){
    return identificador;
}

String Bruja :: gerNombre(){
    return nombre;
}

HechizosBruja Bruja :: getHechizos(){
    return hechizos;
}




