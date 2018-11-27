#include "String.h"
#include <stdio.h>

String :: String(){
    cadena = new char[1];
    cadena[0] = '\0';
}


String :: String(char* s){
   int largo = strlen(s);
    cadena = new char[largo+1];
    strcpy(cadena,s);
}

String :: String(const String &otro){
    int largo = strlen(otro.cadena);
    cadena = new char[largo+1];
    strcpy(otro.cadena, cadena);
}

void String :: strcpy(char* s1, char * &s2){
    int i = 0;
    while(s1[i]!='\0'){
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
}

String :: ~String(){
    delete [] cadena;
}

int String :: strlen(char* s){
    int i = 0;
    while(i<MAX && s[i]!='\0'){
        i++;
    }
    return i - 1;
}

void String :: print(){
    int i = 0;
    while(this->cadena[i]!='\0'){
        printf("%c", this->cadena[i]);
        i++;
    }
}
