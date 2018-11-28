#include "String.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
String :: String(){
    cadena = new char[1];
    cadena[0] = '\0';
}

String :: String(char* s){
    int largo = strlen(s);
    cadena = new char[largo+1];
    strcpy(s, cadena);
}
String :: String(const String &otro){
    int largo = strlen(otro.cadena);
    cadena = new char[largo+1];
    strcpy(otro.cadena, cadena);
}
String :: ~String(){
    delete [] cadena;
}

String String :: operator=(const String &otro){
    if (this != &otro){
        delete [] cadena;
    int largo = strlen(otro.cadena);
    cadena = new char[largo+1];
    strcpy(otro.cadena, cadena);
    }
    return (*this);
}

bool String :: operator==(String s){
    return strcmp(this->cadena, s.cadena);
}

bool String :: operator<(String s){
    return strmen(this->cadena, s.cadena);
}

String String :: operator+ (char * otro){
    String aux;
    int largo1 = strlen(cadena);
    int largo2 = strlen(otro);
    aux.cadena = new char [largo1 + largo2 + 1];
    strcpy(cadena, aux.cadena);
    //strcat(aux.cadena,otro.cadena);
    return aux;
}
void String :: scan(){
    char aux[MAX];
    char c = cin.get();
    int i=0;
    while (c!='\n' && i<MAX-1){
        aux[i] = c;
        i++;
        c = cin.get();
    }
    aux[i]='\0';
    cadena = new char[i+1];
    strcpy(aux, cadena);
}
void String :: print(){
    int i = 0;
    while(i<MAX && this->cadena[i]!='\0'){
        printf("%c", this->cadena[i]);
        i++;
    }
}

int String :: strlen(char* s){
    int i = 0;
    while(i<MAX && s[i]!='\0'){
        i++;
    }
    return i - 1;
}

void String :: strcpy(char* s1, char * &s2){
    int i = 0;
    while(s1[i]!='\0'){
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
}

bool String :: strmen(char * s1, char * s2){
    int i = 0;
    bool esMenor = true;
    while(s1[i]!='\0' && s2[i]!='\0' && esMenor){
        if(s1[i] > s2[i]){
            esMenor = false;
        }
        i++;
    }
    return esMenor;
}

bool String :: strcmp(char * s1, char * s2 ){
    int i = 0;
    bool sonIguales = true;
    while(s1[i]!='\0' && s2[i]!='\0' && sonIguales){
        if(s1[i] != s2[i]){
            sonIguales = false;
        }
        i++;
    }
    if(s1[i] != s2[i]){
        sonIguales = false;
    }
    return sonIguales;

}
