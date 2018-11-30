#include "Iterador.h"

Iterador::Iterador(){
    lppf.prim = NULL;
    lppf.ult = NULL;
    actual = NULL;
}

Iterador::~Iterador(){
    actual = lppf.prim;
    while (actual != NULL){
        lppf.prim = lppf.prim->sig;
        delete actual;
        actual = lppf.prim;
    }
}

void Iterador::insertarBruja (Bruja* bruja){
    Nodo* nodo = new Nodo;
    nodo->info = bruja;
    nodo->sig = NULL;

    if (lppf.prim == NULL){
        lppf.prim = nodo;
        lppf.ult = nodo;
    }else{
        lppf.ult->sig = nodo;
        lppf.ult = nodo;
    }
}

Bruja* Iterador::proximaBruja (){
    if (actual == NULL){
        actual = lppf.prim;
    }else{
        actual = actual->sig;
    }
    return actual->info;
}

Bruja* Iterador::actualBruja (){
    return actual->info;
}


bool Iterador::hayMasBrujas (){
    bool hayMas = false;

    if (actual == NULL){
        hayMas = lppf.prim != NULL;
    }else{
        hayMas = (actual->sig != NULL);
    }


    return hayMas;
}
