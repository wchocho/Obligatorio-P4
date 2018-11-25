#ifndef BRUJAS_H_INCLUDED
#define BRUJAS_H_INCLUDED

class Brujas{
    private:
        struct Nodo {
            Bruja * info;
            Nodo * hizq;
            Nodo * hder;
        };
        Nodo * abb;
    public:
        Brujas ();
        bool member (int);
        void Insert (Bruja *);
        Bruja * Find (int);

};

#endif // BRUJAS_H_INCLUDED
