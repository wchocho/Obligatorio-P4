#include "Menu.h"
#include "Utiles.h"
#include "String.h"
#include <stdio.h>
/*

void menuPrincipal(int &op){
    borrarPantalla();
    int largo = 44;
    imprimirBordeSuperior(largo);
    printf("\n%c               MENU PRINCIPAL               %c", LINEA_V,LINEA_V);
    imprimirBordeDivisor(largo);
    printf("\n%c 1. Registrar bruja suprema                 %c", LINEA_V,LINEA_V); // R1
    printf("\n%c 2. Registrar bruja comun                   %c", LINEA_V,LINEA_V); // R2
    printf("\n%c 3. Regsitrar hechizo                       %c", LINEA_V,LINEA_V); // R6
    printf("\n%c 4. Cantidad de hechizos por bruja          %c", LINEA_V,LINEA_V); // R8
    printf("\n%c 5. Listados                                %c", LINEA_V,LINEA_V);
    printf("\n%c 6. Salir del programa                      %c", LINEA_V,LINEA_V);
    imprimirBordeInferior(largo);
    printf("\n\nIngrese una opcion: ");
    fflush(stdin);
    scanf("%d", &op);
}

void menuListados(int &op){
    borrarPantalla();
    int largo = 44;
    imprimirBordeSuperior(largo);
    printf("\n%c                   LISTADOS                 %c", LINEA_V,LINEA_V);
    imprimirBordeDivisor(largo);
    printf("\n%c 1. Listado de brujas alfabetico            %c", LINEA_V,LINEA_V); // R3
    printf("\n%c 2. Listado de detalle por bruja            %c", LINEA_V,LINEA_V); // R4
    printf("\n%c 3. Listado de detalle por bruja mas antigua%c", LINEA_V,LINEA_V); // R5
    printf("\n%c 4. Listado de detalle por bruja y hechizo  %c", LINEA_V,LINEA_V); // R7
    printf("\n%c 5. Salir del menu                          %c", LINEA_V,LINEA_V);
    imprimirBordeInferior(largo);
    printf("\n\nIngrese una opcion: ");
    fflush(stdin);
    scanf("%d", &op);
}

void imprimirTitulo(String titulo){
    int largo = 20;//titulo.strlen(titulo);
    int i;

    borrarPantalla();
    for(i=0; i<(80-largo)/2; i++)
        printf(" ");
    titulo.print();
    printf("\n");
    for(i=0; i<(80-largo)/2; i++)
        printf(" ");
    for(i=0; i<largo; i++)
        printf("%c", LINEA_H);

}

void imprimirBordeSuperior(int largo){
    printf("%c", ESQ_SI);
    for (int i = 0; i<largo; i++){
        printf("%c", LINEA_H);
    }
    printf("%c", ESQ_SD);
}

void imprimirBordeInferior(int largo){
    printf("\n%c", ESQ_II);
    for (int i = 0; i<largo; i++){
        printf("%c", LINEA_H);
    }
    printf("%c", ESQ_ID);
}

void imprimirBordeDivisor(int largo){
    printf("\n%c", T_I);
    for (int i = 0; i<largo; i++){
        printf("%c", LINEA_H);
    }
    printf("%c", T_D);
}
*/
