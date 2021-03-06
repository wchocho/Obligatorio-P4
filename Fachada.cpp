#include "Fachada.h"

Fachada::Fachada(){
    Brujas brujas;
}

void Fachada :: menuInicio(){
 // agregado para tener letra � y tildes
    setlocale(LC_CTYPE,"Spanish");
    int op = 0;


    do{
        imprimirMenu();
        cout << "Ingrese una opci�n: ";
        cin >> op;
        switch(op){
            case 1:
                registrarBruja();
                break;

            case 2 :
                registrarHechizo();
                break;


            case 3:{
                cantidadHechizosPorTipo();
                break;

            }
            case 4:{
                listadoBrujas();
                break;

            }
            case 5:{
                listadoDetallePorBruja();
                break;
            }
            case 6:{
                mayorSuprema();
                break;
            }
            case 7:{
              listadoDetalleBrujaHechizos();
                break;
            }

        }
        if (op != 8){
            cin.ignore();
            getch();

        }
    }while(op != 8);


}


// MENU
// Caso 1
// REGISTRAR NUEVA BRUJA
 void Fachada::registrarBruja()
{
    bool existe = false;
    Bruja * bruja = NULL;
    String identificador;
    int tipo_bruja = 0;
    bool reintentar = false;
    int error;
    system("CLS");
    cout << " ** REGISTRAR NUEVA BRUJA ** " << endl << endl;

    cout << "Ingrese su identificador: ";
    identificador.scan();
    existe = ExisteBruja(identificador);

    if (existe)
    {
        cout << "Error: ya existe una bruja registrada con el identificador ingresado.";
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
            cout << "Indique el tipo de bruja que desea registrar ( (1)Suprema, (2)Comun ): ";
            cin >> tipo_bruja;

            while (!(tipo_bruja == 1 || tipo_bruja ==2)){

                cout << "Opci�n incorrecta !!!";
                cout << "Indique el tipo de bruja que desea registrar ( (1)Suprema, (2)Comun ): ";

                cin.clear(); // saca failbit

                cin.ignore(numeric_limits<streamsize>::max(),'\n'); // descarta lo que esta mal ingresado
                cin >> tipo_bruja;
            }

            switch (tipo_bruja)
            {
            case 1:  //suprema
            {
                Fecha fecha_nacimiento;
                String cant_poderes_str;

                cout << "Ingrese la cantidad de poderes: " << endl;
                cant_poderes_str.scan();
                while (!cant_poderes_str.esNumerica()){

                    cout << "Ingrese la cantidad de poderes: " << endl;
                    cant_poderes_str.scan();

                }

                int cant_poderes;
                cant_poderes = atoi(cant_poderes_str.getCadena());

                cout << "Ingrese la fecha de nacimiento: " << endl;
                fecha_nacimiento.scan();
                if (!fecha_nacimiento.esValida())
                {
                    reintentar = preguntoReintentar("Error: fecha inv�lida.");
                }
                else
                {

                    bruja = new Suprema(identificador, nombre, hechizos, fecha_nacimiento, cant_poderes);
                    brujas.Insert(bruja);
                    cout << "Bruja suprema registrada." << endl;

                }
                break;
            }

            case 2:  //comun
            {

                String region_origen;
                bool vuela_escoba = false;
                char vuela_escoba_aux;
                String id_suprema;

                cout << "Ingrese la regi�n de origen: " << endl;
                region_origen.scan();

                do
                {
                    cout << "Vuela en escoba? (s, n): ";
                    cin >> vuela_escoba_aux;
                }
                while (vuela_escoba_aux != 's' && vuela_escoba_aux != 'n');

                if(vuela_escoba_aux == 's' || vuela_escoba_aux == 'S' )
                {
                    vuela_escoba = true;
                }

                cout << "Ingrese el identificador de la bruja suprema para su asignaci�n: " << endl;
                id_suprema.scan();


                if( ExisteBruja(id_suprema))
                {
                    Bruja * suprema_aux = NULL;
                    suprema_aux = ObtenerBruja(id_suprema);
                    if(suprema_aux->getTipoBruja()== 0)
                    {

                        bruja = new Comun(identificador, nombre, hechizos, region_origen, vuela_escoba, (Suprema*)suprema_aux);
                        brujas.Insert(bruja);
                        cout << "Bruja comun registrada." << endl;

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
                reintentar = preguntoReintentar("Error: La opci�n seleccionada no esta dentro de las opciones v�lida, verifique.");
            }
        }
        while (reintentar);
    }

}

// Caso 2
// REGISTRAR HECHIZO

void Fachada :: registrarHechizo()
{
    system("CLS");
    cout << " ** REGISTRAR HECHIZO ** " << endl << endl;
    cout << "Ingrese el identificador de la bruja: ";
    String identificador;
    identificador.scan();
    bool existe = ExisteBruja(identificador);

    if (!existe)
    {
        cout << "Error: El identificador ingresado no corresponde a una bruja registrada." << endl;
    }
    else
    {
        Bruja * bru = ObtenerBruja(identificador);
        int opcion;
        cout<< "Indique que tipo de hechizo desea ingresar - ( (1) Com�n (2) Especial ) :";
        cin >> opcion;

        if ( bru->getHechizos().getTope() < CANT_HECHIZOS){

            while ( !(opcion == 1 || opcion == 2)){
                cout << "Opcion incorrecta !!!" << endl;
                cout << "Indique que tipo de hechizo desea ingresar - ( (1) Com�n (2) Especial ) :" << endl;

                cin.clear(); // saca failbit
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); // descarta lo que esta mal ingresado
                cin >> opcion;

            }

            if (opcion == 1)
            {
                cout<< "Ingrese el nombre del hechizo: ";
                String nom;
                nom.scan();
                int numero = bru->getHechizos().getTope();
                Hechizo * he = new Hechizo(numero,nom);


            bru->insertarHechizos(he);
            }
            else
            {
                String nom, des;
                int year;

                cout<< "Ingrese el nombre del hechizo: ";
                nom.scan();
                cout << "Ingrese la descripci�n del hechizo: ";
                des.scan();

                int numero = bru->getHechizos().getTope();

                String anio_str;
                cout << "Ingrese el a�o de manifiesto: " << endl;
                anio_str.scan();
                while (!anio_str.esNumerica()){

                    cout << "Ingrese el a�o de manifiesto: " << endl;
                    anio_str.scan();

                }
                year = atoi(anio_str.getCadena());

                Especial * he = new Especial(numero,nom, year, des);
                bru->insertarHechizos(he);


            }
        }else{
            cout << "Error: No es posible registrar otro hechizo para la bruja seleccionada ya que alcanzo su m�ximo." << endl;
        }

    }
}

// Caso 3
// CANTIDAD DE HECHIZOS BRUJA POR TIPO

void Fachada :: cantidadHechizosPorTipo(){
cout << "Ingrese el identificador de la bruja: ";
    String identificador;
    identificador.scan();
    bool existe = ExisteBruja(identificador);

    if (!existe)
    {
        cout << "Error: El identificador ingresado no corresponde a una bruja registrada."; ;

    }
    else
    {
        Bruja * bru = ObtenerBruja(identificador);
        int comunes =0;
        int especiales=0;

        bru->getHechizos().cantidadHechizosPorTipo(comunes,especiales);

        cout << "Hechizos Comunes: " << comunes << endl;
        cout << "Hechizos Especiales: " << especiales << endl;



}}

// Caso 4
// LISTADO BRUJAS ALFABETICO

void Fachada::listadoBrujas ()
{
    Iterador iterador = listarBruja();

    if (iterador.hayMasBrujas())
    {
        system("CLS");
        cout << " ** LISTADO DE BRUJAS ORDENADAS DE FORMA ALFABETICA ** " << endl << endl;
        while (iterador.hayMasBrujas())
        {
            Bruja* bruja = (Bruja*)iterador.proximaBruja();
            imprimirDatosBasicosBruja(bruja);
            cout << endl;
        }
    }
    else
    {
        cout << "ERROR: No hay brujas ingresadas en el sistema.";
    }
}

// Caso 5
// LISTADO DETALLE POR BRUJA
void Fachada :: listadoDetallePorBruja()
{
    bool existe=false;
    String identificador;


    system("CLS");
    cout << " ** DETALLE POR BRUJA ** " << endl << endl;
    cout << "Ingrese el indentificador de la bruja que desea ver en detalle: ";
    identificador.scan();
    existe = ExisteBruja(identificador);
    if(!existe)
    {
        cout << "Error: El identificador ingresado no corresponde a una bruja registrada." << endl;
    }
    else
    {
        Bruja * bruja_aux = NULL;
        bruja_aux = ObtenerBruja(identificador);
        if(bruja_aux->getTipoBruja() == 0)
        {

            imprimirDatosSuprema((Suprema*)bruja_aux);
        }
        else
        {
            Bruja * bruja_suprema = NULL;
            imprimirDatosComun((Comun*)bruja_aux);
            Comun *c = (Comun*)bruja_aux;
            bruja_suprema = ObtenerBruja( c->getSuprema()->getIdentificador() );
            imprimirDatosSuprema((Suprema*)bruja_suprema);
        }
    }
}

// Caso 6
// MAYOR SUPREMA
void Fachada :: mayorSuprema(){
    system("CLS");
    cout << " ** INFORMACI�N DE LA MAYO BRUJA REGISTRADA ** " << endl << endl;
    Iterador itera = getSupremas();
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
        cout << "Error: No existen brujas cargadas en el sistema.";
    }


}

// Caso 7
// LISTADO DETALLE BRUJA HECHIZOS
void Fachada :: listadoDetalleBrujaHechizos(){
 bool existe=false;
    String identificador;
   int numhechizo;

    system("CLS");
    cout << " ** DETALLE POR BRUJA Y HECHIZO **" << endl << endl;
    cout << "Ingrese el indentificador de la bruja que desea ver en detalle: ";
    identificador.scan();
    existe = ExisteBruja(identificador);
    if(!existe)
    {
        cout << "Error: El identificador ingresado no corresponde a una bruja registrada." << endl;
    }
    else
    {

        Bruja * bruja_aux = NULL;
        bruja_aux = ObtenerBruja(identificador);
        if( !bruja_aux->getHechizos().esvacia() ){
            cout << "Ingrese el numero de hechizo que desea ver en detalle: ";

            cin >> numhechizo;
            while (numhechizo<1 || numhechizo > CANT_HECHIZOS){
                cout << "Error !!! El numero de hechizo debe estar entre 1 y " << CANT_HECHIZOS << endl;
                cout << "Ingrese el numero de hechizo que desea ver en detalle: ";
                cin.clear(); // saca failbit
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); // descarta lo que esta mal ingresado
                cin >> numhechizo;
            }


            numhechizo--;

            if(bruja_aux->getHechizos().existeHechizoPorId(numhechizo)){

                Hechizo * h( bruja_aux->getHechizos().getHechizo(numhechizo));
                if (h->getTipoHechizo()==0){

                    cout << "Numero: " << h->getNumero() + 1;
                    cout << endl;
                    cout << "Nombre: ";
                    h->getNombre().print();
                }
                else{

                    cout << "Numero: " << ((Especial *)h)->getNumero() +1;
                    cout << endl;
                    cout << "Nombre: " ;
                    ((Especial *)h)->getNombre().print();
                    cout << endl;
                    cout << "Anio: " << ((Especial *)h)->getAnioManifiesto() ;

                }
            }else{
                cout << "Error: El numero ingresado no corresponde a un hechizo registrado.";
            }
        }else{
            cout << "Error: La bruja seleccionada no tiene hechizos cargados.";
        }
    }



}





// AUXILIARES


bool Fachada :: ExisteBruja(String id){
    return brujas.member(id);
}

Iterador Fachada :: getSupremas(){

return brujas.darSupremas();

}

Bruja * Fachada :: ObtenerBruja(String id){
    Bruja * bruja = NULL;
    bruja = brujas.Find(id);
    return bruja;
}


Iterador Fachada::listarBruja(){
    return brujas.listarBruja();
}

void Fachada::imprimirMenu()
{
    system("CLS");
    cout << " 1 - Registrar bruja " << endl;
    cout << " 2 - Regsitrar hechizo " << endl;
    cout << " 3 - Cantidad de hechizos por bruja " << endl;
    cout << " 4 - Listado de brujas alfabetico "  << endl;
    cout << " 5 - Listado de detalle por bruja " << endl;
    cout << " 6 - Listado de detalle de mayor bruja suprema " << endl;
    cout << " 7 - Listado de detalle por bruja y hechizo " << endl;
    cout << " 8 - Salir" << endl << endl;


}

bool Fachada::preguntoReintentar (string msg)
{
    char reintentar;

    do
    {
        cout << endl << msg << endl;
        cout << "Desea intentarlo nuevamente? (s, n)?: ";
        cin.ignore();
        reintentar = getchar();

    }
    while (reintentar != 's' && reintentar != 'n');

    return reintentar == 's';
}

String Fachada :: boolAString(bool aux)
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




// IMPRESIONES

void Fachada :: imprimirDatosBasicosBruja(Bruja* bruja)
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

void Fachada :: imprimirDatosSuprema(Suprema* bruja_suprema)
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
void Fachada :: imprimirDatosComun(Comun* bruja_comun)
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

