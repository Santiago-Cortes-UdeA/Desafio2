#include <iostream>
#include <string>
//#include "surtidor.h"
#include "rednacional.h"
using namespace std;
template <typename T>
bool OpcionValida(T& Opcion, T limSup, T limInf=0){
    if (cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<endl<<"Entrada invalida. Intenta nuevamente.\n";
    }
    else if(Opcion>=limInf && Opcion<=limSup){
        return true;
    }
    else cout<<endl<<"Numero fuera de rango. Intenta nuevamente.\n";
    return false;
}



int main()
{
    RedNacional Red;
    bool salir = false;
    bool entradaValida = false;
    unsigned short int Opcion;
    unsigned short int Opcion_;
    cout << "Bienvenido al Sistema Administrativo del TerMax" << endl;
    do{
        Opcion=-1;
        while(!entradaValida){
            cout<<"\nEscoja una opcion:\n0. Salir\n1. Gestion de Red\n2. Gestion de Estaciones de Servicio\n3. Verificar Fugas\n4. Simulacion de ventas\n";
            cin>>Opcion;
            entradaValida=OpcionValida<short unsigned int>(Opcion, 4);
        }

        if (Opcion==0) salir = true;

        else if (Opcion==1){

            do{
                Opcion_=-1;
                cout<<"\nEscoja una opcion:\n0. Salir\n1. Agregar Estacion de Servicio\n2. Eliminar Estaciones de Servicio\n3. Calcular Monto Total de Ventas\n4. Fijar los precios de combustible\n";
                cin>>Opcion_;
                entradaValida=OpcionValida<short unsigned int>(Opcion_, 4);

                if (Opcion_==0) entradaValida=true;

                else if (Opcion_==1){
                    string Nombre;
                    string Gerente;
                    unsigned short int Region;
                    float Lat;
                    float Long;
                    cout<<"\nIngrese el Nombre de la Estacion: ";
                    do{
                        cin>>Nombre;
                        if (Nombre.empty()) cout<<endl<<"\nEl nombre no puede estar vacio. Intentelo de nuevo: ";
                    }
                    while (Nombre.empty());

                    cout<<"\nIngrese el Nombre del Gerente: ";
                    do{
                        cin>>Gerente;
                        if (Gerente.empty()) cout<<endl<<"\nEl nombre no puede estar vacio. Intentelo de nuevo: ";
                    }
                    while (Gerente.empty());

                    entradaValida=false;

                    while(!entradaValida){
                        cout<<"\nIngrese la Region de la Estacion:\n1. Norte\n2. Centro\n3. Sur\n";
                        cin>>Region;
                        entradaValida=OpcionValida<short unsigned int>(Region,3,1);
                    }

                    entradaValida=false;

                    while(!entradaValida){
                        cout<<"\nIngrese la Latitud en grados de la estacion (valor entre -180 y 180)\n";
                        cin>>Lat;
                        entradaValida=OpcionValida<float>(Lat,180,-180);
                    }

                    entradaValida=false;

                    while(!entradaValida){
                        cout<<"\nIngrese la Longitud en grados de la estacion (valor entre -180 y 180)\n";
                        cin>>Long;
                        entradaValida=OpcionValida<float>(Long,180,-180);
                    }

                    entradaValida=false;

                    cout<<"Estos son los datos de la estacion a agregar:\n"
                            "\nNombre: "<<Nombre<<endl
                         <<"\nGerente: "<<Gerente<<endl;

                    cout<<"\nRegion: ";
                    switch (Region){
                    case 1:
                        cout<<"Norte\n";
                        break;
                    case 2:
                        cout<<"Centro\n";
                        break;
                    case 3:
                        cout<<"Sur\n";
                        break;
                    }
                    cout<<"\nCoordenadas:\n"
                                "\tLatitud: "<<Lat<<endl
                             <<"\tLongitud: "<<Long<<endl;

                    short unsigned int Agregar;

                    while(!entradaValida){
                        cout<<"\nEsta seguro que desea agregar esta estacion?"<<endl
                             <<"1. Si, Agregar\n2. No, Cancelar"<<endl;
                        cin>>Agregar;
                        entradaValida=OpcionValida<short unsigned int>(Agregar,2,1);
                    }

                    if (Agregar==1) Red.AgregarES(Nombre, Gerente, Region-1, Lat, Long);

                    entradaValida=false;
                }

                else if (Opcion_==2){
                    entradaValida=false;
                    if (Red.getCantEsts()==0){
                        cout<<endl<<"No hay estaciones creadas, no se puede eliminar nada\n";
                    }
                    else{
                        short unsigned int Eliminar;
                        cout<<"0. "<<"Cancelar"<<endl;
                        for (int i = 0; i<Red.getCantEsts(); i++){
                            cout<<i+1<<". "<<Red.getEstacion(i)->getcodigo()<<endl;
                        }
                        while(!entradaValida){
                            cout<<"Ingrese el numero correspondiente a la estacion que desea eliminar"<<endl;
                            cin>>Eliminar;
                            entradaValida=OpcionValida<short unsigned int>(Eliminar,Red.getCantEsts());
                        }
                        if (Eliminar>0){
                            Red.EliminarES(Eliminar-1);
                        }
                    }
                    entradaValida=false;
                }

                else if (Opcion_==3){
                    Red.Ventas();
                    entradaValida=false;
                }

                else if (Opcion_==4){
                    entradaValida=false;
                    unsigned short int Opcion_Region=-1;
                    unsigned short int Opcion_Combustible=-1;
                    unsigned short int Opcion_Precio=-1;
                    while(!entradaValida){
                        cout<<"\nEn que region desea cambiar el precio?\n1. Norte\n2. Centro\n3. Sur\n";
                        cin>>Opcion_Region;
                        entradaValida=OpcionValida<short unsigned int>(Opcion_Region,3,1);
                        Opcion_Region--;
                    }

                    entradaValida=false;

                    while(!entradaValida){
                        cout<<"\nDe que tipo de combustible desea cambiar el precio?\n1. Regular\n2. Premium\n3. EcoExtra\n";
                        cin>>Opcion_Combustible;
                        entradaValida=OpcionValida<short unsigned int>(Opcion_Combustible,3);
                        Opcion_Combustible--;
                    }

                    entradaValida=false;

                    while(!entradaValida){
                        cout<<"\nCual sera el nuevo precio? (Precio por litro)\n";
                        cin>>Opcion_Precio;
                        entradaValida=OpcionValida<short unsigned int>(Opcion_Precio,65535);
                    }

                    entradaValida=false;

                    cout<<"\nPrecios antes:"<<"\n____________________\n\n";
                    for (int i = 0; i<3; i++){
                        for (int j = 0; j<3; j++){
                            cout<<Red.getPrecio(i, j)<<endl;
                        }
                        cout<<"____________________\n\n";
                    }

                    Red.setPrecios(Opcion_Region, Opcion_Combustible, Opcion_Precio);

                    cout<<"\nPrecios despues:"<<"\n____________________\n\n";
                    for (int i = 0; i<3; i++){
                        for (int j = 0; j<3; j++){
                            cout<<Red.getPrecio(i, j)<<endl;
                        }
                        cout<<"____________________\n\n";
                    }
                }
            }
            while(!entradaValida);
        }
        else if (Opcion==2){
            entradaValida=false;
            if (Red.getCantEsts()==0){
                cout<<"\nNo hay estaciones creadas, no se puede acceder a estas opciones\n";
            }
            else{
                short unsigned int Est=-1;
                for (int i = 0; i<Red.getCantEsts(); i++){
                    cout<<i+1<<". "<<Red.getEstacion(i)->getcodigo()<<endl;
                }
                while (!entradaValida){
                    cout<<"\nIngrese el numero que corresponde a la estacion a la que desea acceder:"<<endl;
                    cin>>Est;
                    entradaValida = OpcionValida <short unsigned int>(Est,Red.getCantEsts());
                }
                do{
                    Estacion* EstAct=Red.getEstacion(Est-1);
                    entradaValida=false;

                    Opcion_=-1;
                    while (!entradaValida){
                        cout<<"\nEscoja una opcion:\n0. Salir\n1. Agregar Surtidor\n2. Eliminar Surtidor\n3. Activar Surtidor\n4. Desactivar Surtidor\n5. Consultar Transacciones\n6. Reporte Cantidad de Gasolina Vendida\n";
                        cin>>Opcion_;
                        entradaValida=OpcionValida<short unsigned int>(Opcion_, 6);
                    }

                    if (Opcion_==0) entradaValida=true;

                    else if (Opcion_==1){
                        entradaValida=false;
                        string Modelo;
                        unsigned short int Isla = 0;
                        while (!entradaValida){
                            cout<<"\nIngrese el modelo del surtidor\n:";
                            cin>>Modelo;
                            if (Modelo.empty()){
                                cout<<"\nEl modelo no puede estar vacio\n";
                            }
                            else entradaValida=true;
                        }

                        entradaValida=false;

                        if (EstAct->getcantislas()>0){
                            cout<<"\nIslas disponibles:\n"
                                    "0. Isla Nueva\n";
                            for (int i = 0; i<EstAct->getcantislas(); i++){
                                cout<<i+1<<". "<<EstAct->getcodigoisla(i)<<endl;
                            }
                            while (!entradaValida){
                                cout<<endl<<"Ingrese el numero correspondiente a la isla en la que desea agregar el surtidor:\n";
                                cin>>Isla;
                                entradaValida=OpcionValida<unsigned short int>(Isla, EstAct->getcantislas());
                            }
                            entradaValida=false;
                        }
                        else{
                            cout<<endl<<"Se agregara en una isla nueva ya que no hay islas preexistentes en esta estacion\n";
                        }

                        EstAct->AddSurtidor(Modelo,Isla);
                    }

                    else if (Opcion_==2){

                    }

                    else if (Opcion_==3){

                    }

                    else if (Opcion_==4){

                    }

                    else if (Opcion_==5){

                    }

                    else if (Opcion_==6){

                    }

                    else if (Opcion_==7){

                    }

                }
                while(!entradaValida);
            }
        }

        else if (Opcion==3){

        }

        else{
            entradaValida=false;
            if (Red.getCantEsts()==0){
                cout<<endl<<"No se puede simular una venta ya que no hay estaciones creadas"<<endl;
            }
            else{
                short unsigned int Est=-1;
                cout<<endl<<"Estaciones Disponibles:";
                for (int i = 0; i<Red.getCantEsts(); i++){
                    cout<<i+1<<". "<<Red.getEstacion(i)->getcodigo()<<endl;
                }
                while (!entradaValida){
                    cout<<"\nIngrese el numero que corresponde a la estacion a la que desea acceder:"<<endl;
                    cin>>Est;
                    entradaValida = OpcionValida <short unsigned int>(Est,Red.getCantEsts());
                }

                Estacion* EstAct = Red.getEstacion(Est-1);

                if (EstAct->getcantsurts()==0){
                    cout<<endl<<"No se puede simular una venta ya que no hay surtidores en esta estacion"<<endl;
                }
                else{
                    EstAct->SimularVenta(rand()%EstAct->getcantsurts(),Red.getPrecio(EstAct->getregion(),rand()%3));
                }
            }
        }

        entradaValida=false;
    }
    while(!salir);
    return 0;
}
