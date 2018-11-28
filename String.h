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
        String operator+ (char *);

        // lee un string desde la entrada estándar.
        void scan();

        // muestra un string en la salida estándar
        void print();


        int strlen(char *);
        void strcpy(char *, char * &);
        bool strcmp(char *, char *);
        bool strmen(char *, char *);

};


#endif // STRING_H_INCLUDED
