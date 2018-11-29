#include "Fachada.h"

Fachada::Fachada(){
    Brujas brujas;
}

void Fachada :: RegistrarBruja(Bruja* bruja, int &error){
    error = 0;
    //String tipo;
    //tipo = bruja->getTipoBruja();
    brujas.Insert(bruja);
}

bool Fachada :: ExisteBruja(String id){
    return brujas.member(id);
}

Bruja * Fachada :: ObtenerBruja(String id){
    Bruja * bruja = NULL;
    bruja = brujas.Find(id);
    return bruja;
}


