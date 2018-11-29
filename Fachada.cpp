#include "Fachada.h"

Fachada::Fachada(){
    Brujas brujas;
}

void Fachada :: RegistrarBruja(Bruja* bruja, int &error){
    error = 0;
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

Iterador Fachada::listarBruja(){
    return brujas.listarBruja();
}



