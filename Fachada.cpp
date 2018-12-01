#include "Fachada.h"

Fachada::Fachada(){
    Brujas brujas;
}

void Fachada :: RegistrarBruja(Bruja* bruja){
    brujas.Insert(bruja);
}

bool Fachada :: ExisteBruja(String id){
    return brujas.member(id);
}

Iterador Fachada :: getSupremas(){

return brujas.darSupremas();



}

Bruja * Fachada :: ObtenerBruja(String id){
    Bruja * bruja = NULL;
    bruja = brujas.Find(id);
    return bruja;
}

Iterador Fachada::listarBruja(){
    return brujas.listarBruja();
}

 void Fachada :: registrarHechizo(String id , Hechizo * he){
    Bruja * bru = ObtenerBruja(id);
    bru->insertarHechizos(he);
}



