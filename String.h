#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <iostream>
#include <stdio.h>

using namespace std;

const int MAX = 1000;
class String
{
    private:
        char *cadena;
        int _strlar(char*);
        int _strlar(string);
        void _strcop(char*&, char*);
        void _strcop (char*, string);

    public:
        String();
        String(const String&);
        String(string);
        virtual ~String();

        char* getCadena();
        void scan();
        void print();

        void print(char* s);
        int strlar();
        bool operator< (String);
        bool operator== (String);
        void operator= (const String&);
        void operator= (char*);
        bool operator!= (String);
        String operator+ (String&);
        bool strmen(char * , char * );
        bool strcmp(char * , char * );
        bool esNumerica();




};


#endif // STRING_H_INCLUDED
