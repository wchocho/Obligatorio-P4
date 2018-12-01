#include "Fecha.h"

Fecha::Fecha()
{
    dia = 1;
    mes = 1;
    anio = 2000;
}

Fecha::Fecha(int dia, int mes, int anio)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

Fecha::Fecha(const Fecha &f)
{
    dia = f.dia;
    mes = f.mes;
    anio = f.anio;
}

int Fecha::Getdia()
{
    return dia;
};

void Fecha::Setdia(int val)
{
    dia = val;
}

int Fecha::Getmes()
{
    return mes;
};

void Fecha::Setmes(int val)
{
    mes = val;
}

int Fecha::Getanio()
{
    return anio;
};

void Fecha::Setanio(int val)
{
    anio = val;
}

bool Fecha::operator< (Fecha f)
{
    bool es = false;
    if (anio < f.anio)
        es = true;
    else if (anio > f.anio)
        es = false;
    else if (mes < f.mes)
        es = true;
    else if (mes > f.mes)
        es = false;
    else if (dia < f.dia)
        es = true;
    else
        es = false;
    return es;

}

bool Fecha::operator== (Fecha f)
{
    if (anio == f.anio && mes == f.mes && dia == f.dia)
        return true;
    else
        return false;
}

Fecha Fecha::operator++ ()
{
    sumo1(*this);
    return (*this);
}

Fecha Fecha::operator++ (int posfija)
{
    Fecha f = (*this);
    sumo1(*this);
    return f;
}

Fecha Fecha::operator+ (int val)
{
    Fecha f = (*this);
    for (int i = 0; i<val; i++)
        sumo1(f);
    return (f);
}

int Fecha::operator- (Fecha f)
{
    int diferencia = 0;
    Fecha fAux = (*this);
    if (fAux < f)
    {
        do
        {
            f.resto1();
            diferencia++;
        }
        while (! (fAux == f));
    }
    else
    {
        do
        {
            fAux.resto1();
            diferencia--;
        }
        while (! (fAux == f));
    }
    return diferencia;
}

bool Fecha::esValida ()
{
    bool es = false;
    switch (mes)
    {
        using namespace std;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (dia >= 1 && dia <= 31)
            es = true;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        if (dia >= 1 && dia <= 30)
            es = true;
        break;

    case 2:
        if (anio % 4 == 0)
        {
            if (dia >= 1 && dia <= 29)
                es = true;
        }
        else if (dia >= 1 && dia <= 28)
            es = true;
    }

    return es;
}

void Fecha::imprimir()
{
    cout << dia << '/' << mes << '/' << anio;
}

void Fecha::scan()
{
    cout << "dia: ";
    cin >> dia;
    while(0==dia || dia>31)
    {

        cout << "dia invalido"<< endl;
        cout << "Ingrese nuevamente el dia: ";

        cin.clear(); // saca failbit

        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // descarta lo que esta mal ingresado
        cin >> dia;

    }

    cout << "mes: ";
    cin >> mes;
    while(0==mes || mes>12)
    {

        cout << "mes invalido"<< endl;
        cout << "Ingrese nuevamente el mes: ";

        cin.clear(); // saca failbit

        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // descarta lo que esta mal ingresado
        cin >> mes;

    }

    cout << "anio: ";
    cin >> anio;
    while(0==anio )
    {

        cout << "anio invalido"<< endl;
        cout << "Ingrese nuevamente el anio: ";

        cin.clear(); // saca failbit

        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // descarta lo que esta mal ingresado
        cin >> anio;

    }
}

void Fecha::sumo1(Fecha &fecha)
{
    fecha.dia++;
    if (!fecha.esValida())
    {
        fecha.dia = 1;
        fecha.mes++;
        if (!fecha.esValida())
        {
            fecha.mes = 1;
            fecha.anio++;
        }
    }
}

void Fecha::resto1()
{
    if (dia == 1)
    {
        dia = 31;
        if (mes == 1)
        {
            mes = 12;
            anio--;
        }
        else
        {
            mes--;
        }
    }
    else
    {
        dia--;
    }
    while (!esValida())
    {
        resto1();
    }
}

