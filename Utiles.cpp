#include "Utiles.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

Utiles::Utiles():fachada()
{
}

void Utiles::imprimirMenu()
{
    system("CLS");
    cout << " 1 - Registrar nueva bruja" << endl;
    cout << " 2 - Regsitrar hechizo" << endl;
    cout << " 3 - Cantidad de hechizos por bruja" << endl;
    cout << " 4 - Listado de brujas alfabetico" << endl;
    cout << " 5 - Listado de detalle por bruja" << endl;
    cout << " 6 - Listado de detalle por bruja mas antigua" << endl;
    cout << " 7 - Listado de detalle por bruja y hechizo" << endl;
    cout << "8 - Salir" << endl << endl;


}

void Utiles::registrarNuevaBruja()
{
    bool existe = false;
    Bruja * bruja = NULL;
    String identificador;
    int tipo_bruja = 0;
    bool reintentar = false;
    int error;
    system("CLS");
    cout << "REGISTRAR NUEVA BRUJA" << endl << endl;

    cout << "Ingrese su identificador: ";
    identificador.scan();
    existe = fachada.ExisteBruja(identificador);

    if (existe)
    {
        cout << "Error: ya existe una bruja registrada con el identificador";
    }
    else
    {
        String nombre;
        HechizosBruja hechizos;

        cout << "Ingrese su nombre: ";
        nombre.scan();
        do
        {
            reintentar = false;
            cout << "Indique el tipo de bruja que desea registrar ( (0)Suprema, (1)Comun )";
            cin >> tipo_bruja;

            switch (tipo_bruja)
            {
            case 0:  //suprema
            {
                Fecha fecha_nacimiento;
                int cant_poderes = 0;
                cout << "Ingrese la fecha de nacimiento" << endl;
                fecha_nacimiento.scan();
                if (!fecha_nacimiento.esValida())
                {
                    reintentar = preguntoReintentar("Error: fecha invalida");
                }
                else
                {
                    bruja = new Suprema(identificador, nombre, hechizos, fecha_nacimiento, cant_poderes);
                    fachada.RegistrarBruja(bruja, error);
                    if (!error)
                    {
                        cout << "Bruja suprema registrada" << endl;
                    }
                }
                break;
            }

            case 1:  //comun
            {
                String region_origen;
                bool vuela_escoba = false;
                char vuela_escoba_aux;
                String id_suprema;

                cout << "Ingrese la region de origen" << endl;
                region_origen.scan();




                //NO ESTA LEYENDO EL CHAR DE FORMA CORRECTA - REVISAR

                do
                {
                    cout << " Vuela en escoba? (s, n)";
                    cin >> vuela_escoba_aux;
                }
                while (vuela_escoba_aux != 's' && vuela_escoba_aux != 'n');
                if(vuela_escoba_aux == 's' || vuela_escoba_aux == 'S' )
                {
                    vuela_escoba = true;
                }



                cout << "Ingrese el identificador de la bruja suprema para su asignacion." << endl;
                id_suprema.scan();


                if( fachada.ExisteBruja(id_suprema))
                {
                    Bruja * suprema_aux = NULL;
                    suprema_aux = fachada.ObtenerBruja(id_suprema);
                    if(suprema_aux->getTipoBruja()== 0)
                    {

                        bruja = new Comun(identificador, nombre, hechizos, region_origen, vuela_escoba, (Suprema*)suprema_aux);
                        fachada.RegistrarBruja(bruja, error);

                        if (!error)
                        {
                            cout << "Bruja comun registrada" << endl;
                        }
                    }
                    else
                    {
                        cout << "Error: El identificador ingresado no corresponde a una bruja suprema." << endl;
                    }

                }
                else
                {
                    cout << "Error: El identificador ingresado no corresponde a una bruja registrada." << endl;

                }

                break;
            }

            default:
                reintentar = preguntoReintentar("Error: La opcion seleccionada no esta dentro de las valida, verifique.");
            }
        }
        while (reintentar);
    }

}



bool Utiles::preguntoReintentar (string msg)
{
    char reintentar;

    do
    {
        cout << endl << msg << endl;
        cout << "¿Desea intentarlo nuevamente? (s, n)?: ";
        cin.ignore();
        reintentar = getchar();
    }
    while (reintentar != 's' && reintentar != 'n');

    return reintentar == 's';
}


void Utiles::listadoBrujas ()
{
    Iterador iterador = fachada.listarBruja();

    if (iterador.hayMasBrujas())
    {
        system("CLS");
        cout << "LISTADO DE BRUJAS" << endl << endl;
        while (iterador.hayMasBrujas())
        {
            Bruja* bruja = (Bruja*)iterador.proximaBruja();
            imprimirDatosBasicosBruja(bruja);
            //bruja->getNombre().print(); cout << " - ";
        }
    }
    else
    {
        cout << "ERROR: no hay brujas ingresadas en el sistema";
    }
}

void Utiles :: listadoDetallePorBruja()
{
    bool existe=false;
    String identificador;
    system("CLS");
    cout << "DETALLE POR BRUJA" << endl << endl;
    cout << "Ingrese el indentificador de la bruja que desea ver en detalle: ";
    identificador.scan();
    existe = fachada.ExisteBruja(identificador);
    if(!existe)
    {
        cout << "Error: El identificador ingresado no corresponde a una bruja registrada." << endl;
    }
    else
    {
        Bruja * bruja_aux = NULL;
        bruja_aux = fachada.ObtenerBruja(identificador);
        if(bruja_aux->getTipoBruja() == 0)
        {
            imprimirDatosSuprema((Suprema*)bruja_aux);
        }
        else
        {
            Bruja * bruja_suprema = NULL;
            imprimirDatosComun((Comun*)bruja_aux);
            Comun *c = (Comun*)bruja_aux;
            bruja_suprema = fachada.ObtenerBruja( c->getSuprema()->getIdentificador() );
            imprimirDatosSuprema((Suprema*)bruja_suprema);
        }
    }
}

void Utiles :: imprimirDatosBasicosBruja(Bruja* bruja)
{
    cout << "Identificador: ";
    bruja->getIdentificador().print();
    cout ;
    cout << " - Nombre: ";
    bruja->getNombre().print();
    cout ;
    String tipo;
    if(bruja->getTipoBruja() == 0)
    {
        tipo = ("Suprema");
    }
    else
    {
        tipo = ("Comun");
    }
    cout << " - Tipo de bruja: ";
    tipo.print();
}

void Utiles :: imprimirDatosSuprema(Suprema* bruja_suprema)
{
    imprimirDatosBasicosBruja( (Bruja*)bruja_suprema);
    cout << " - Fecha de nacimiento: ";
    bruja_suprema->getFechaNacimiento().imprimir();
    cout ;
    // impresion de numeros
    cout << " - Cantidad de poderes: " << bruja_suprema->getCantPoderes() ;

}
void Utiles :: imprimirDatosComun(Comun* bruja_comun)
{
    imprimirDatosBasicosBruja( (Bruja*)bruja_comun);
    cout << " - Region de origen: ";
    bruja_comun->getRegionOrigen().print();
    cout ;
    String resu;
    resu = boolAString(bruja_comun->getVuelaEscoba());
    cout << " - Vuela en escoba: ";
    resu.print();
    cout;
}

String Utiles :: boolAString(bool aux)
{
    String resu;
    if(aux)
    {
        resu = ("SI");
    }
    else
    {
        resu = ("NO");
    }
    return resu;
}

void Utiles :: registrarHechizo()
{
    cout << "Ingrese su identificador de la bruja: ";
    String identificador;
    identificador.scan();
    bool existe = fachada.ExisteBruja(identificador);

    if (!existe)
    {
        cout << "Error: El identificador ingresado no corresponde a una bruja registrada.";

    }
    else
    {
   Bruja * bru = fachada.ObtenerBruja(identificador);
        int opcion;
        cout<< "Indique que tipo de hechizo desea ingresar - (0) Comun (1) Especial";
        cin >> opcion;

        if (opcion == 0){
            cout<< "Ingrese el nombre del hechizo";
            String nom;
            nom.scan();
            int numero = bru->getHechizos().getTope();
            Hechizo * he = new Hechizo(numero,nom);

            fachada.registrarHechizo(identificador, he);
        }
        else{



        }


    }
}
