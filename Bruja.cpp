#include "Bruja.h"

//Bruja();
Bruja :: Bruja(int id, String nom, HechizosBruja hechizos_bruja): nombre(nom), hechizos(hechizos_bruja){
    identificador = id;
}

int Bruja :: getIdentificador(){
    return identificador;
}
String Bruja :: gerNombre(){
    return nombre;
}



