#include "Brujas.h"
#include <stdio.h>

bool Brujas :: member (String id){
    return ExisteEnArbol(abb, id);
}
void Brujas :: Insert (Bruja * bruja){
    InsertEnArbol(abb, bruja);
}
Bruja * Brujas :: Find (String id){
    return ObtenerDelArbol(abb, id);
}

Brujas :: Brujas (){
    abb = NULL;
}
bool Brujas :: ExisteEnArbol (Nodo * n, String id){
    bool exito = false;
    while(! exito && n != NULL){
        if(id == id){
            exito = true;
        }else{
            if(id < n->info->getIdentificador()){
                ExisteEnArbol(n->hizq, id);
            }else{
                ExisteEnArbol(n->hder, id);
            }
        }
    }
    return exito;
}

void Brujas :: InsertEnArbol (Nodo * &n, Bruja * bruja){
    if(n == NULL){
        n = new Nodo;
        n->info = bruja;
        n->hizq = NULL;
        n->hder= NULL;
    }else{
        if (bruja->getIdentificador() < n->info->getIdentificador()){
            InsertEnArbol(n->hizq, bruja);
        }else{
            InsertEnArbol(n->hizq, bruja);
        }
    }
}

Bruja * Brujas :: ObtenerDelArbol (Nodo * n, String id){

    /*ACA ESTOY TENIENDO PROBLEMAS CON EL STRCMP*/

    //while(strcmp(id, n->info->getIdentificador()) == 0){
    /*while(id.strcmp(n->info->getIdentificador()) == 0){
        /*if(id < n->info->getIdentificador()){
            ObtenerDelArbol(n->hizq, id);
        }else{
            ObtenerDelArbol(n->hder, id);
        }

    }
    */
    return n->info;

}


