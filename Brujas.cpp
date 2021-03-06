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
            if(id < abbAux->info->getIdentificador()){
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
        //bruja->getIdentificador().print();
        //abb->info->getIdentificador().print();
        if (bruja->getIdentificador()  <  abb->info->getIdentificador() ){
            InsertEnArbol(bruja, abb->hizq);
        }else{
            InsertEnArbol(bruja, abb->hder);
        }
    }
}



Iterador Brujas::darSupremas(){
    Iterador iterador;
    darSupremasRec(abb, iterador);
    return iterador;
}

void Brujas :: darSupremasRec(Nodo * abbAux, Iterador& iterador){

  if (abbAux != NULL) {

      if ((abbAux->info->getTipoBruja() == 0))
        iterador.insertarBruja(abbAux->info);

        darSupremasRec(abbAux->hizq, iterador);

        darSupremasRec(abbAux->hder, iterador);
    }


}


Iterador Brujas::listarBruja (){
    Iterador iterador;
    listarBrujaRec(abb, iterador);
    return iterador;
}


void Brujas::listarBrujaRec (Nodo* abbAux, Iterador& iterador){

    if (abbAux != NULL){
        listarBrujaRec (abbAux->hizq, iterador);
        iterador.insertarBruja(abbAux->info);
        listarBrujaRec (abbAux->hder, iterador);
    }
}

Bruja * Brujas :: Find (String id){
    Nodo* abbAux = abb;
    while(!(abbAux->info->getIdentificador() == id)){
        if(id < abbAux->info->getIdentificador()){
            abbAux = abbAux->hizq;
        }else{
            abbAux = abbAux->hder;
        }
    }
    return abbAux->info;
}



