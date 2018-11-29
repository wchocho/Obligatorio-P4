#include "Utiles.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

Utiles::Utiles():fachada(){
}

void Utiles::imprimirMenu(){
    system("CLS");
    cout << " 1 - Registrar nueva bruja" << endl;
    cout << "10 - Salir" << endl << endl;

}

void Utiles::registrarNuevaBrujaSuprema(){
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
    if (existe){
        cout << "Error: ya existe una bruja registrada con el identificador";
    }else{
        String nombre;
        HechizosBruja hechizos;

        cout << "Ingrese su nombre: ";
        nombre.scan();
        do{
            reintentar = false;
            cout << "Indique el tipo de bruja que desea registrar ( (0)Suprema, (1)Comun )"; cin >> tipo_bruja;

            switch (tipo_bruja){
                case 0:{ //suprema
                    Fecha fecha_nacimiento;
                    int cant_poderes = 0;
                    cout << "Ingrese la fecha de nacimiento" << endl;
                    fecha_nacimiento.scan();
                    if (!fecha_nacimiento.esValida()){
                        reintentar = preguntoReintentar("Error: fecha invalida");
                    }else{
                        bruja = new Suprema(identificador, nombre, hechizos, fecha_nacimiento, cant_poderes);
                        fachada.RegistrarBruja(bruja, error);
                        if (!error){
                            cout << "Bruja suprema registrada" << endl;
                        }
                    }
                    break;
                }

                case 1:{ //comun
                    String region_origen;
                    bool vuela_escoba = true;
                    String vuela_escoba_aux;
                    String id_suprema;
                    cout << "Ingrese la region de origen" << endl;
                    region_origen.scan();


                    cout << "¿Vuela en escoba? (s, n)";
                    //vuela_escoba_aux.scan();
                    //if(vuela_escoba_aux[0] != 's' or vuela_escoba_aux[0] != 'S' ){
                    //    vuela_escoba = false;
                    // }
                    printf("%d", vuela_escoba);
                    cout << "Ingrese el identificador de la bruja suprema para su asignacion." << endl;
                    id_suprema.scan();


                    if( fachada.ExisteBruja(id_suprema)){
                        Bruja * bruja_aux = NULL;
                        bruja_aux = fachada.ObtenerBruja(id_suprema);
                        if(bruja_aux->getTipoBruja()== 0){
                            bruja = new Comun(identificador, nombre, hechizos, region_origen, vuela_escoba);
                            fachada.RegistrarBruja(bruja, error);
                            if (!error){
                                cout << "Bruja comun registrada" << endl;
                            }
                        }else{
                            cout << "Error: El identificador ingresado no corresponde a una bruja suprema." << endl;
                        }

                    }else{
                        cout << "Error: El identificador ingresado no corresponde a una bruja registrada." << endl;

                    }

                    break;
                }

                default:
                    reintentar = preguntoReintentar("Error: La opcion seleccionada no esta dentro de las valida, verifique.");
            }
        }while (reintentar);
    }

}



bool Utiles::preguntoReintentar (string msg){
    char reintentar;

    do{
        cout << endl << msg << endl;
        cout << "¿Desea intentarlo nuevamente? (s, n)?: ";
        cin.ignore();
        reintentar = getchar();
    }while (reintentar != 's' && reintentar != 'n');

    return reintentar == 's';
}
