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
String Suprema :: getTipoBruja(){
    String resu ("Suprema");
    return resu;
}
int Suprema :: calcularPuntos(){
    // èndiente de implementae
    return 0;

}
