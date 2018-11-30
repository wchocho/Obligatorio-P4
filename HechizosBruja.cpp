#include "HechizosBruja.h"

HechizosBruja :: HechizosBruja(){

    tope = 0;
}
bool HechizosBruja:: esvacia(){
return (tope == 0);
}
bool HechizosBruja :: estaLlena (){
return (bool) (tope== CANT_HECHIZOS);
}

void HechizosBruja:: insBack (Hechizo*he){
arre[tope]=he;
tope++;
}

bool HechizosBruja :: existeHechizo(Hechizo*he){
int i=0;
bool existe=false;
while(!existe && i<tope){
    if(arre[i]==he)
        existe=true;
    else
        i++;
}
    return existe;
}

int HechizosBruja:: getTope(){
return tope;


}

void HechizosBruja :: cantidadHechizosPorTipo(int &comunes, int&especiales){
comunes = 0;
especiales = 0;
for (int i = 0; i < tope;i++){
    if (arre[i]->getTipoHechizo() == 0){
        comunes ++;
        cout<<"tacontndocualquiera";}
    else{
        especiales ++;
}

}

}


