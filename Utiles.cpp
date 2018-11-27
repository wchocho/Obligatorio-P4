#include "Utiles.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void borrarPantalla(){
    system("cls");
}

void continuar(){
    printf("\n\nPresione una tecla para continuar");
    fflush(stdin);
    getch();
}
/*
void preguntarCedula(long int &cedula){
    printf("\nIngrese la cedula: ");
    fflush(stdin);
    scanf("%ld", &cedula);
}
*/
