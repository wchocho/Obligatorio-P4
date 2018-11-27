#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "String.h"

typedef enum{
    ESQ_SD = 187,
    ESQ_SI = 201,
    ESQ_ID = 188,
    ESQ_II = 200,
    LINEA_H = 205,
    LINEA_V = 186,
    T_D = 185,
    T_I = 204
} BordesMenu;

void imprimirBordeSuperior(int largo);
void imprimirBordeInferior(int largo);
void imprimirBordeDivisor(int largo);
void menuPrincipal(int &op);
void menuConsultas(int &op);
void menuListados(int &op);
void imprimirTitulo(String titulo);

#endif // MENU_H_INCLUDED
