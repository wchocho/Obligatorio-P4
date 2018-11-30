#include "Suprema.h"

Suprema :: Suprema(String id, String nom, HechizosBruja hechizos , Fecha f_nacimiento, int cant_poderes): Bruja(id, nom, hechizos), fechaNacimiento(f_nacimiento){
    cantPoderes = cant_poderes;
}

Fecha Suprema :: getFechaNacimiento(){
    return fechaNacimiento;
}
int Suprema :: getCantPoderes(){
    return cantPoderes;
}
int Suprema :: getTipoBruja(){
    return 0;
}
int Suprema :: calcularPuntos(){
    // èndiente de implementae
    int total = cantPoderes;
    int comunes, especiales;
    getHechizos().cantidadHechizosPorTipo(comunes,especiales);
    Fecha f(01,01,1900);
    total = total + comunes * 2 + especiales * 4;
    if (getFechaNacimiento()<f){
        total = total + 5;
    }

    return total;
}
