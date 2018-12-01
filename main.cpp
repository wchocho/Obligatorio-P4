#include <stdio.h>
#include <conio.h>
#include "Utiles.h"
#include <clocale>

int main(){
    // agregado para tener letra ñ y tildes
    setlocale(LC_CTYPE,"Spanish");
    int op = 0;
    Utiles utiles;


    do{
        utiles.imprimirMenu();
        cout << "Ingrese una opción: ";
        cin >> op;
        switch(op){
            case 1:
                utiles.registrarNuevaBruja();
                break;

            case 2 :{
                utiles.registrarHechizo();
                break;
            }

            case 3:{
                utiles.cantidadHechizosPorTipo();
                break;

            }
            case 4:{
                utiles.listadoBrujas();
                break;

            }
            case 5:{
                utiles.listadoDetallePorBruja();
                break;
            }
            case 6:{
                utiles.mayorSuprema();
                break;
            }
            case 7:{
              utiles.listadoDetalleBrujaHechizos();
                break;
            }

        }
        if (op != 8){
            cin.ignore();
            getch();

        }
    }while(op != 8);

     return 0;
}

