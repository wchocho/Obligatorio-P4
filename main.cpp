#include <stdio.h>
#include <conio.h>
#include "Utiles.h"

int main(){
    int op = 0;
    Utiles utiles;
    do{
        utiles.imprimirMenu();
        cout << "Ingrese una opcion: ";
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
                //utiles.listadoDetalleBrujaMasAntigua();
                break;
            }
            case 7:{
//                utiles.listadoDetalleBrujaHechizos();
                break;
            }

        }
        if (op != 7){
            cin.ignore();
            getch();

        }
    }while(op != 7);
     return 0;
}

