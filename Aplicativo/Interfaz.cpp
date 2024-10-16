#include <iostream>
#include <string>
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
                cout<<"\nEscoja una opcion:\n0. Salir\n1. Agregar Estacion de Servicio\n2. Eliminar Estaciones de Servicio\n3. Calcular Monto Total de Ventas\n4. Fijar los Precios de Combustible\n";
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
                    getline(cin, Nombre);
                    do{
                        getline(cin, Nombre);
                        if (Nombre.empty()) cout<<endl<<"\nEl nombre no puede estar vacio. Intentelo de nuevo: ";
                    }
                    while (Nombre.empty());

                    cout<<"\nIngrese el Nombre del Gerente: ";
                    do{
                        getline(cin, Gerente);
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

                    if (Agregar==1) {
                        Red.AgregarES(Nombre, Gerente, Region-1, Lat, Long);
                        Estacion* EstAct = Red.getEstacion(Red.getCantEsts()-1);
                        cout<<"\nLa estacion debe poseer al menos 2 surtidores.\nSe procedera con su creacion.\nSi desea agregar mas surtidores ingrese a Gestion de Estaciones -> Seleccione la estacion correspondiente -> Agregar Surtidor"<<endl;
                        string Modelo;
                        unsigned short int Isla = 0;
                        getline(cin, Modelo);
                        for (short unsigned int i = 0; i<2; i++){
                            entradaValida=false;
                            cout<<"\nIngrese el modelo del surtidor: \n";
                            while (!entradaValida){
                                getline(cin, Modelo);
                                if (Modelo.empty()){
                                    cout<<"\nEl modelo no puede estar vacio. Intentelo de nuevo\n";
                                }
                                else entradaValida=true;
                            }
                            entradaValida=false;
                            if (i>0){
                                cout<<"\nIslas disponibles:\n"
                                        "0. Isla Nueva\n"
                                        "1. 0"<<endl;

                                while (!entradaValida){
                                    cout<<endl<<"Ingrese el numero correspondiente a la isla en la que desea agregar el surtidor:\n";
                                    cin>>Isla;
                                    entradaValida=OpcionValida<unsigned short int>(Isla, EstAct->getcantislas());
                                }

                            }
                            else{
                                cout<<endl<<"Se agregara en una isla nueva ya que no hay islas preexistentes en esta estacion\n";
                            }
                            EstAct->AddSurtidor(Modelo,Isla);
                        }
                    }

                    entradaValida=false;
                }

                else if (Opcion_==2){
                    entradaValida=false;
                    if (Red.getCantEsts()==0){
                        cout<<endl<<"No hay estaciones creadas, no se puede eliminar nada\n";
                    }
                    else{
                        cout<<endl<<"Estaciones disponibles: "<<endl;
                        short unsigned int Eliminar;
                        cout<<"0. "<<"Cancelar"<<endl;
                        for (short unsigned int i = 0; i<Red.getCantEsts(); i++){
                            cout<<i+1<<". "<<Red.getEstacion(i)->getnombre()<<" ("<<Red.getEstacion(i)->getcodigo()<<')'<<endl;
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
                    cout<<endl<<"Precios Actuales:"<<endl
                         <<"\tRegular\tPremium\tEcoExtra\n";
                    for (int i = 0; i<3; i++){
                        switch (i){
                        case 0:
                            cout<<"Norte\t";
                            break;
                        case 1:
                            cout<<"Centro\t";
                            break;
                        case 2:
                            cout<<"Sur\t";
                            break;
                        }
                        for (int j=0; j<3; j++){
                            cout<<Red.getPrecio(i,j)<<'\t';
                        }
                        cout<<endl;
                    }
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



                    Red.setPrecios(Opcion_Region, Opcion_Combustible, Opcion_Precio);

                    cout<<endl<<"Precios Nuevos:"<<endl
                         <<"\tRegular\tPremium\tEcoExtra\n";
                    for (int i = 0; i<3; i++){
                        switch (i){
                        case 0:
                            cout<<"Norte\t";
                            break;
                        case 1:
                            cout<<"Centro\t";
                            break;
                        case 2:
                            cout<<"Sur\t";
                            break;
                        }
                        for (int j=0; j<3; j++){
                            cout<<Red.getPrecio(i,j)<<'\t';
                        }
                        cout<<endl;
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
                cout<<endl<<"Estaciones disponibles: "<<endl;
                short unsigned int Est=-1;
                for (short unsigned int i = 0; i<Red.getCantEsts(); i++){
                    cout<<i+1<<". "<<Red.getEstacion(i)->getnombre()<<" ("<<Red.getEstacion(i)->getcodigo()<<')'<<endl;
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
                        if (EstAct->getcantsurts()==12){
                            cout<<endl<<"Hay 12 surtidores. No se pueden agregar mas."<<endl;
                        }
                        else{
                            entradaValida=false;
                            string Modelo;
                            unsigned short int Isla = 0;
                            cout<<"\nIngrese el modelo del surtidor: \n";
                            getline(cin, Modelo);
                            while (!entradaValida){
                                getline(cin, Modelo);
                                if (Modelo.empty()){
                                    cout<<"\nEl modelo no puede estar vacio. Intentelo de nuevo\n";
                                }
                                else entradaValida=true;
                            }

                            entradaValida=false;

                            if (EstAct->getcantislas()>0){
                                cout<<"\nIslas disponibles:\n"
                                        "0. Isla Nueva\n";
                                for (short unsigned int i = 0; i<EstAct->getcantislas(); i++){
                                    cout<<i+1<<". "<<EstAct->getcodigoisla(i)<<endl;
                                }
                                while (!entradaValida){
                                    cout<<endl<<"Ingrese el numero correspondiente a la isla en la que desea agregar el surtidor:\n";
                                    cin>>Isla;
                                    entradaValida=OpcionValida<unsigned short int>(Isla, EstAct->getcantislas());
                                }

                            }
                            else{
                                cout<<endl<<"Se agregara en una isla nueva ya que no hay islas preexistentes en esta estacion\n";
                            }
                            entradaValida=false;
                            short unsigned int Agregar;

                            cout<<"Datos del Surtidor:\nModelo: "<<Modelo<<endl<<"Isla: ";
                            if (Isla==0) cout<<"Nueva Isla"<<endl;
                            else cout<<Isla-1<<endl;

                            while (!entradaValida){
                                cout<<endl<<"Esta seguro que desea agregar este surtidor?\n1. Si, Agregar\n2. No, Cancelar\n"<<endl;
                                cin>>Agregar;
                                entradaValida=OpcionValida<short unsigned int>(Agregar,2,1);
                            }

                            if (Agregar==1) EstAct->AddSurtidor(Modelo,Isla);
                        }
                        entradaValida=false;
                    }

                    else if (Opcion_==2){
                        entradaValida=false;
                        if (EstAct->getcantsurts()<=2){
                            cout<<endl<<"Hay 2 Surtidores o menos, no se puede eliminar ninguno\n";
                        }
                        else{
                            short unsigned int Eliminar;
                            cout<<"0. "<<"Cancelar"<<endl;
                            for (int i = 0; i<EstAct->getcantsurts(); i++){
                                cout<<i+1<<". "<<EstAct->getSurtidor(i)->getCodigo()<<endl;
                            }
                            while(!entradaValida){
                                cout<<"Ingrese el numero correspondiente al surtidor que desea eliminar"<<endl;
                                cin>>Eliminar;
                                entradaValida=OpcionValida<short unsigned int>(Eliminar,EstAct->getcantsurts());
                            }
                            if (Eliminar>0){
                                EstAct->DeleteSurtidor(Eliminar-1);
                            }
                        }
                        entradaValida=false;
                    }

                    else if (Opcion_==3){
                        entradaValida=false;
                        short unsigned int* SurtidoresInactivos = new short unsigned int [EstAct->getcantsurts()];
                        short unsigned int CantSurtsIna = 0;
                        cout<<endl<<"Surtidores Inactivos:"<<endl;
                        for (short unsigned int i = 0; i<EstAct->getcantsurts(); i++){
                            if (!EstAct->getSurtidor(i)->getActivado()){
                                cout<<CantSurtsIna+1<<". "<<EstAct->getSurtidor(i)->getCodigo()<<endl;
                                SurtidoresInactivos[CantSurtsIna]=i;
                                CantSurtsIna++;
                            }
                        }
                        if (CantSurtsIna>0){
                            cout<<"0. Cancelar"<<endl;
                            short unsigned int Activar;
                            cout<<endl<<"Ingrese el numero que corresponde al surtidor que desea activar"<<endl;
                            while (!entradaValida){
                                cin>>Activar;
                                entradaValida=OpcionValida<unsigned short int>(Activar,CantSurtsIna);
                            }
                            if (Activar>0){
                                EstAct->ActivarSurtidor(SurtidoresInactivos[Activar-1]);
                            }
                        }
                        else{
                            cout<<endl<<"No hay surtidores inactivos. Ninguno puede ser activado."<<endl;
                        }
                        entradaValida=false;
                    }

                    else if (Opcion_==4){
                        entradaValida=false;
                        short unsigned int* SurtidoresActivos = new short unsigned int [EstAct->getcantsurts()];
                        short unsigned int CantSurtsAct = 0;
                        cout<<endl<<"Surtidores Activos:"<<endl;
                        for (short unsigned int i = 0; i<EstAct->getcantsurts(); i++){
                            if (EstAct->getSurtidor(i)->getActivado()){
                                cout<<CantSurtsAct+1<<". "<<EstAct->getSurtidor(i)->getCodigo()<<endl;
                                SurtidoresActivos[CantSurtsAct]=i;
                                CantSurtsAct++;
                            }
                        }
                        if (CantSurtsAct>0){
                            cout<<"0. Cancelar"<<endl;
                            short unsigned int Desactivar;
                            cout<<endl<<"Ingrese el numero que corresponde al surtidor que desea desactivar"<<endl;
                            while (!entradaValida){
                                cin>>Desactivar;
                                entradaValida=OpcionValida<unsigned short int>(Desactivar,CantSurtsAct);
                            }
                            if (Desactivar>0){
                                EstAct->DesactivarSurtidor(SurtidoresActivos[Desactivar-1]);
                            }
                        }
                        else{
                            cout<<endl<<"No hay surtidores activos. Ninguno puede ser desactivado."<<endl;
                        }
                        entradaValida=false;
                    }

                    else if (Opcion_==5){
                        EstAct->ConsultarTransacciones();
                        entradaValida=false;
                    }

                    else if (Opcion_==6){
                        EstAct->ReporteCantVendidaCombustibles();
                        entradaValida=false;
                    }

                }
                while(!entradaValida);
            }
        }

        else if (Opcion==3){
            entradaValida=false;
            if (Red.getCantEsts()==0){
                cout<<endl<<"No se pueden verificar fugas, ya que no hay estaciones"<<endl;
            }
            else{
                short unsigned int Est=-1;
                cout<<endl<<"Estaciones Disponibles:"<<endl;
                for (short unsigned int i = 0; i<Red.getCantEsts(); i++){
                    cout<<i+1<<". "<<Red.getEstacion(i)->getnombre()<<" ("<<Red.getEstacion(i)->getcodigo()<<')'<<endl;
                }
                while (!entradaValida){
                    cout<<"\nIngrese el numero que corresponde a la estacion donde desea verificar la presencia de fugas:"<<endl;
                    cin>>Est;
                    entradaValida = OpcionValida <short unsigned int>(Est,Red.getCantEsts());
                }

                Estacion* EstAct = Red.getEstacion(Est-1);
                Red.VerificarFugas(EstAct);
            }
        }

        else{
            entradaValida=false;
            if (Red.getCantEsts()==0){
                cout<<endl<<"No se puede simular una venta ya que no hay estaciones creadas"<<endl;
            }
            else{
                short unsigned int Est=-1;
                cout<<endl<<"Estaciones Disponibles:"<<endl;
                for (short unsigned int i = 0; i<Red.getCantEsts(); i++){
                    cout<<i+1<<". "<<Red.getEstacion(i)->getnombre()<<" ("<<Red.getEstacion(i)->getcodigo()<<')'<<endl;
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
                    short unsigned int TipoComb = rand()%3;
                    EstAct->SimularVenta(Red.getPrecio(EstAct->getregion(),TipoComb), TipoComb);
                }
            }
        }

        if (Red.getCantEsts()>0){
            unsigned short int Num1 = rand()%5;
            unsigned short int Num2 = rand()%5;
            if (Num1==Num2){
                Estacion* Est = Red.getEstacion(rand()%Red.getCantEsts());
                Est->SimularFuga();
            }
        }

        entradaValida=false;
    }
    while(!salir);
    return 0;
}
