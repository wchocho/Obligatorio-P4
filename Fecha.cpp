#include "Fecha.h"
#include <stdio.h>

Fecha :: Fecha(){
    dia = 1;
    mes = 1;
    anio = 1900;
}
Fecha :: Fecha (int d, int m, int a){
    dia = d;
    mes = m;
    anio = a;
}

Fecha :: Fecha(const Fecha &f){
    dia = f.dia;
    mes = f.mes;
    anio = f.anio;
}
int Fecha :: getDia(){
    return dia;
}
int Fecha :: getMes(){
    return mes;
}
int Fecha :: getAnio(){
    return anio;
}

void Fecha :: setDia(int d){
    dia = d;
}
void Fecha :: setMes(int m){
    mes =  m;
}
void Fecha :: setAnio(int a){
    anio = a;
}

// true si f1 < f2
bool Fecha :: operator< (Fecha f){
    bool es = false;
    if(this->anio < f.anio){
        es = true;
    }else{
        if(this->anio > f.anio){
            es = false;
        }else{
            if(this->mes < f.mes){
                es = true;
            }else{
                if(this->mes > f.mes){
                    es = true;
                }else{
                    if(this->dia < f.dia){
                        es = true;
                    }else{
                        es = false;
                    }
                }
            }

        }
    }
    return es;
}
bool Fecha :: operator==(Fecha f){
    bool ret = false;
    if(this->dia == f.dia){
        if (this->mes == f.mes){
            if(this->anio ==  f.anio){
                ret = true;
            }
        }
    }
    return ret;

}
// (devuelve la fecha correspondiente al día siguiente a la fecha dada)
//prefijo
Fecha Fecha :: operator++(){
    bool bisiesto = false, dia_modificado = false;
    if (this->anio % 4 == 0){
        bisiesto = true;
    }
    switch(this->mes){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (this->dia < 31){
                ++this->dia;
                dia_modificado = true;
            }
            break;
        case 4: case 6: case 9: case 11:
            if (this->dia < 30){
                ++this->dia;
                dia_modificado = true;
            }
            break;
        case 2:
            if (bisiesto && this->dia < 29){
                ++this->dia;
                dia_modificado = true;
            }else{
                if(this->dia < 28){
                    ++this->dia;
                    dia_modificado = true;
                }
            }
            break;
    }
    if(!dia_modificado){
        if(this->mes < 12){
            ++this->mes;
            this->dia = 1;
        }else{
            ++this->anio;
            this->dia = 1;
            this->mes = 1;
        }
    }
    return (*this);
}
//postfijo
Fecha Fecha :: operator++(int a){
    bool bisiesto = false, dia_modificado = false;
    Fecha f = (*this);
    if (this->anio % 4 == 0){
        bisiesto = true;
    }
    switch(this->mes){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (this->dia < 31){
                this->dia++;
                dia_modificado = true;
            }
            break;
        case 4: case 6: case 9: case 11:
            if (this->dia < 30){
                this->dia++;
                dia_modificado = true;
            }
            break;
        case 2:
            if (bisiesto && this->dia < 29){
                this->dia++;
                dia_modificado = true;
            }else{
                if(this->dia < 28){
                    this->dia++;
                    dia_modificado = true;
                }
            }
            break;
    }
    if(!dia_modificado){
        if(this->mes < 12){
            this->mes++;
            this->dia = 1;
        }else{
            this->anio++;
            this->dia = 1;
            this->mes = 1;
        }
    }
    return f;

}

/*VER CON EL PROFESOR*/

Fecha Fecha :: operator+(int num){
    // preguntar al prfe que se debe hacer aca
    this->dia = this->dia + num;
    return (*this);
}
// (devuelve la cantidad de días de diferencia entre 2 fechas)
int Fecha :: operator-(Fecha f2){

    int cont = 0;
    Fecha f1(*this);
    for(int i=0; f1<f2; i++){
        f1++;
        cont ++;
    }
    return cont;

}
int Fecha :: cantidadDiasMes(int mes, int anio){
    bool bisiesto = false;
    int cant = 0;
    if (anio % 4 == 0 && anio % 400 != 0){
        bisiesto = true;
    }
    switch(mes){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            cant = 31;
            break;
        case 4: case 6: case 9: case 11:
            cant = 30;
            break;
        case 2:
            if (bisiesto){
                cant = 29;
            }else{
                cant = 28;
            }
            break;
    }
    return cant;
}
bool Fecha :: esValida(){
    bool exito = false;
    if(this->mes <= 12){
        if(this->dia <= cantidadDiasMes(this->mes, this->anio)){
            exito = true;
        }
    }
    return exito;
}

