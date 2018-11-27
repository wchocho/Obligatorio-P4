#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

int const MAX = 80;
class String{
    private:
        char * cadena;
    public:
        // constructor por defecto.
        String();
        // constructor común
        String(char* s);
        // constructor de copia
        String(const String &);
        // destructor
        ~String();
        // sobrecarga de asignación
        String operator=(const String &);
        // compara dos strings por igualdad.
        bool operator==(String);
        // compara dos strings alfabéticamente
        bool operator< (String);
        // concatenación de strings.
        String operator+ (String);
        // lee un string desde la entrada estándar.
        void scan();
        // muestra un string en la salida estándar
        void print();
        int strlen(char * s);
        void strcpy(char * s, char * & s2);
        int strcmp(String, String);

};


#endif // STRING_H_INCLUDED
