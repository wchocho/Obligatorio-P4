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
    cout << " 1 - Registrar nueva bruja - Requerimientos 1 y 2" << endl;
    cout << " 2 - Regsitrar hechizo - Requerimiento 6" << endl;
    cout << " 3 - Cantidad de hechizos por bruja - Requerimiento 8" << endl;
    cout << " 4 - Listado de brujas alfabetico - Requerimiento 3" << endl;
    cout << " 5 - Listado de detalle por bruja - Requerimiento 4" << endl;
    cout << " 6 - Listado de detalle de Mayor Bruja Suprema Requerimiento 5 " << endl;
    cout << " 7 - Listado de detalle por bruja y hechizo" << endl;
    cout << " 8 - Salir" << endl << endl;


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
            cout << "Indique el tipo de bruja que desea registrar ( (0)Suprema, (1)Comun ): ";
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
                /* AGREGARA ALGUN CONTROL QUE VERIFIQUE SI EXISTE ALGUNA SUPREMA INGRESADA Y SI NO HAY NO SE PUEDE REALIZAR EL INSERT DE LA COMUN*/
                String region_origen;
                bool vuela_escoba = false;
                char vuela_escoba_aux;
                String id_suprema;

                cout << "Ingrese la region de origen" << endl;
                region_origen.scan();

                do
                {
                    cout << "Vuela en escoba? (s, n)";
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


void Utiles :: mayorSuprema(){
    Iterador itera = fachada.getSupremas();
    Suprema * su = NULL;
    if (itera.hayMasBrujas()){
        su = (Suprema *)itera.proximaBruja();
        Suprema * actual = su;
        while (itera.hayMasBrujas()){

            actual=((Suprema *)itera.proximaBruja());
            if (actual->getFechaNacimiento()<su->getFechaNacimiento())
                su = actual;

        }


    }
    // agregado para el caso donde se ingresa al requeriminto sin ingresar brujas previamente.
    if(su != NULL){
        imprimirDatosSuprema(su);
    }else{
        cout << "No existen brujas cargadas";
    }


}

void Utiles::listadoBrujas ()
{
    Iterador iterador = fachada.listarBruja();

    if (iterador.hayMasBrujas())
    {
        system("CLS");
        cout << "LISTADO DE BRUJAS ORDENADAS DE FORMA ALFABETICA" << endl << endl;
        while (iterador.hayMasBrujas())
        {
            Bruja* bruja = (Bruja*)iterador.proximaBruja();
            imprimirDatosBasicosBruja(bruja);
            cout << endl;
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


void Utiles :: listadoDetalleBrujaHechizos(){
 bool existe=false;
    String identificador;
   int numhechizo;

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
        cout << "Ingrese el número de hechizo que desea ver en detalle";
        cin >> numhechizo;
        Hechizo * h( bruja_aux->getHechizos().getHechizo(numhechizo));
        if (h->getTipoHechizo()==0){

            cout << "Numero" << h->getNumero();
            cout << endl;
            cout << "Nombre" << endl;
            h->getNombre().print();
        }
        else{

            cout << "Numero" << ((Especial *)h)->getNumero();
            cout << endl;
            cout << "Nombre" << endl;
            ((Especial *)h)->getNombre().print();
            cout << endl;
            cout << "Anio" << ((Especial *)h)->getAnioManifiesto() ;

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
    cout << " - Puntos de Poder: " << bruja_suprema->calcularPuntos();
    cout << endl;
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
    cout << " - Puntos de Poder: " << bruja_comun->calcularPuntos();
    cout << endl;
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
        cout << "Error: El identificador ingresado no corresponde a una bruja registrada." << endl;
    }
    else
    {
        Bruja * bru = fachada.ObtenerBruja(identificador);
        int opcion;
        cout<< "Indique que tipo de hechizo desea ingresar - ( (0) Comun (1) Especial ) :";
        cin >> opcion;

        if (opcion == 0)
        {
            cout<< "Ingrese el nombre del hechizo: ";
            String nom;
            nom.scan();
            int numero = bru->getHechizos().getTope();
            Hechizo * he = new Hechizo(numero,nom);

            fachada.registrarHechizo(identificador, he);
        }
        else
        {
            String nom, des;
            int year;

            cout<< "Ingrese el nombre del hechizo: ";

            nom.scan();
            cout << "Ingrese la descripcion del hechizo: ";
            des.scan();


            int numero = bru->getHechizos().getTope();
            cout << "Ingrese el año de manifiesto: ";
            cin >> year;

            Especial * he = new Especial(numero,nom, year, des);

            fachada.registrarHechizo(identificador, he);

        }


    }
}

void Utiles :: cantidadHechizosPorTipo(){
cout << "Ingrese su identificador de la bruja: ";
    String identificador;
    identificador.scan();
    bool existe = fachada.ExisteBruja(identificador);

    if (!existe)
    {
        cout << "Error: El identificador ingresado no corresponde a una bruja registrada."; ;

    }
    else
    {
        Bruja * bru = fachada.ObtenerBruja(identificador);
        int comunes =0;
        int especiales=0;
        bru->getHechizos().cantidadHechizosPorTipo(comunes,especiales);
        cout << "Hechizos Comunes: " << comunes << endl;
        cout << "Hechizos Especiales: " << especiales << endl;



}}
