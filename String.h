#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

int const MAX = 80;
class String{
    private:
        char * cadena;
    public:
        // constructor por defecto.
        String();
        // constructor com�n
        String(char* s);
        // constructor de copia
        String(const String &);
        // destructor
        ~String();
        // sobrecarga de asignaci�n
        String operator=(const String &);
        // compara dos strings por igualdad.
        bool operator==(String);
        // compara dos strings alfab�ticamente
        bool operator< (String);
        // concatenaci�n de strings.
        String operator+ (String);
        // lee un string desde la entrada est�ndar.
        void scan();
        // muestra un string en la salida est�ndar
        void print();
        int strlen(char * s);
        void strcpy(char * s, char * & s2);
        int strcmp(String, String);

};


#endif // STRING_H_INCLUDED
