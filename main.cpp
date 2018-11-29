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
                utiles.registrarNuevaBrujaSuprema();
                break;

            case 2:
                break;

            case 3 :{
                utiles.listadoBrujas();
                break;
            }

            case 4:{
                break;
            }
            case 5:{
                break;
            }
            case 6:{
                break;
            }
            case 7:{
                break;
            }
            case 8:{
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

