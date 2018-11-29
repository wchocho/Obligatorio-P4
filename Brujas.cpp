#include "Brujas.h"
#include <stdio.h>

Brujas :: Brujas (){
    abb = NULL;
}

bool Brujas :: member (String id){
    Nodo* abbAux = abb;
    bool exito = false;
    while(! exito && abbAux != NULL){
        if(abbAux->info->getIdentificador() == id){
            exito = true;
        }else{
            if(abbAux->info->getIdentificador() < id){
                abbAux = abbAux->hizq;
            }else{
                abbAux = abbAux->hder;
            }
        }
    }
    return exito;
}

void Brujas :: Insert (Bruja * bruja){
    InsertEnArbol(bruja, abb);
}

void Brujas :: InsertEnArbol (Bruja* bruja, Nodo* &abb){
    if(abb == NULL){
        abb = new Nodo;
        abb->info = bruja;
        abb->hizq = NULL;
        abb->hder= NULL;
    }else{
        if (bruja->getIdentificador() < abb->info->getIdentificador()){
            InsertEnArbol(bruja, abb->hizq);
        }else{
            InsertEnArbol(bruja, abb->hizq);
        }
    }
}


Bruja * Brujas :: Find (String id){
    Nodo* abbAux = abb;
    while(abbAux->info->getIdentificador() != id){
        if(abbAux->info->getIdentificador() < id){
            abbAux = abbAux->hizq;
        }else{
            abbAux = abbAux->hder;
        }
    }
    return abbAux->info;
}
