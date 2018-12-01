#include "String.h"
#include <cstdlib>

String::String()
{
    cadena = new char[1];
    cadena[0] = '\0';
}

String::String(const String &s){
    cadena = new char[1];
    cadena[0] = '\0';
    _strcop(cadena, s.cadena);
}

String::String(string s){
    cadena = new char[1];
    cadena[0] = '\0';
    _strcop(cadena, s);
}

String::~String()
{
    delete []cadena;
}

void String::scan(){
    char aux[MAX];
    int i = 0;
    fflush(stdin);
    scanf("%c", &aux[0]);
    while(i<MAX && aux[i]!='\n'){
        i++;
        scanf("%c", &aux[i]);
    }
    aux[i]='\0';

    _strcop(cadena, aux);
}

void String::print(){
    int i = 0;
    while(cadena[i]!='\0'){
        printf("%c", cadena[i]);
        i++;
    }
}

void String::print(char* s){
    int i = 0;
    while(s[i]!='\0'){
        printf("%c", s[i]);
        i++;
    }
}

char* String::getCadena(){
    return cadena;
}

int String::strlar(){
    return _strlar(cadena);
}

int String::_strlar(char *s){
    int i = 0;
    while(s[i]!='\0'){
        i++;
    }
    return i;
}

int String::_strlar(string s){
    int i = 0;
    while(s[i]!='\0'){
        i++;
    }
    return i;
}

//bool String::operator<(String s){
//    int i = 0;
//    bool esMenor = false;
//    while((cadena[i]!='\0' && s.cadena[i]!='\0') && !esMenor){
//        if(cadena[i] > s.cadena[i]  ){
//            esMenor = true;
//        }
//        i++;
//    }
//    return esMenor;
//}


bool String :: operator<(String s){
int i =0;
bool encontre = false;
bool menor=false;
while ((!encontre) && (cadena[i] !='\0') && (s.cadena[i] !='\0')){

    if (cadena[i] != s.cadena[i])
        encontre = true;
    if (cadena[i]<s.cadena[i])
        menor = true;
    i++;
}
if ((!encontre) && (s.cadena[i] != '\0'))
    menor = true;
return menor;
}
bool String::operator==(String s){
    int i = 0;
    bool sonIguales = true;
    while(cadena[i]!='\0' && s.cadena[i]!='\0' && sonIguales){
        if(cadena[i] != s.cadena[i]){
            sonIguales = false;
        }
        i++;
    }
    if(cadena[i] != s.cadena[i]){
        sonIguales = false;
    }
    return sonIguales;
}


void String::operator=(const String &s){
    _strcop(cadena, s.cadena);
}

void String::operator= (char* s){
    _strcop(cadena, s);
}

/*
void String::operator= (const string &s){
    delete [] cadena;
    int largo = _strlar(s) + 1;
    cadena = new char [largo];
    int i = 0;
    while(i<largo){
        cadena[i] = s[i];
        i++;
    }
}
*/
void String::_strcop (char* &s1, char* s2){
    delete s1;
    int largo = _strlar(s2) + 1;
    s1 = new char [largo];
    int i = 0;
    while(i<largo){
        s1[i] = s2[i];
        i++;
    }
}

void String::_strcop (char *s1, string s2){
    delete [] s1;
    int largo = _strlar(s2) + 1;
    s1 = new char [largo];
    int i = 0;
    while(i<largo){
        s1[i] = s2[i];
        i++;
    }
}

String String::operator+ (String &s){
    String stringAux;
    int largoS1 = strlar();
    int largoS2 = s.strlar();
    int largo = largoS1 + largoS2 + 1;
    int i = 0;

    stringAux.cadena = new char[largo];

    for(int j = 0; j<largoS1; j++){
        stringAux.cadena[i] = cadena[j];
        i++;
    }
    for(int j = 0; j<largoS2; j++){
        stringAux.cadena[i] = s.cadena[j];
        i++;
    }
    stringAux.cadena[i] = '\0';

    return stringAux;
}


 bool String :: esNumerica(){

 int i =0;
 bool es = true;
 while (this->cadena[i] != '\0' && es){

    if (this->cadena[i]<48 || this->cadena[i]>57)
        es = false;
    i++;

 }
 return es;
 }


