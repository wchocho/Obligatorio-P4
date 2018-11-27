#include <stdio.h>
#include "Menu.h"
#include "Utiles.h"


int main(){
    int op = 0;
    do{
        menuPrincipal(op);
        switch(op){
            case 1:

                continuar();
                break;

            case 2:
                continuar();
                break;

            case 3 :{
                continuar();
                break;
            }

            case 4:{
                continuar();
                break;
            }

            case 5:{
                int op2 = 0;
                do{
                    menuListados(op2);
                    switch(op2){
                        case 1: //R3
                            continuar();
                            break;

                        case 2: //R4
                            continuar();
                            break;

                        case 3: //R5
                            continuar();
                            break;
                        case 4: //R7
                            continuar();
                            break;
                    }
                }while(op2 != 5);
                menuPrincipal(op);
                break;
            }
        }
    }while(op != 6);
}

