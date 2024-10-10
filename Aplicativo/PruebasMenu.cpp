#include <iostream>
//#include <string>
//#include "surtidor.h"
#include "rednacional.cpp"
using namespace std;


bool OpcionValida(unsigned short int& Opcion, short unsigned int limSup, short unsigned int limInf=0){
    if (cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Entrada invalida. Intenta nuevamente.\n";
    }
    else if(Opcion>=limInf && Opcion<=limSup){
        return true;
    }
    else cout<<"Numero fuera de rango. Intenta nuevamente.\n";
    return false;
}

int main()
{
    RedNacional Red;
    bool salir = false;
    bool entradaValida = false;
    unsigned short int Opcion=-1;
    unsigned short int Opcion_=-1;
    unsigned short int Opcion_Region=-1;
    unsigned short int Opcion_Combustible=-1;
    unsigned short int Opcion_Precio=-1;
    cout << "Bienvenido al Sistema Administrativo del TerMax" << endl;
    do{

        while(!entradaValida){
            cout<<"\nEscoja una opcion:\n0. Salir\n1. Gestion de Red\n2. Gestion de Estaciones de Servicio\n3. Verificar Fugas\n4. Simulacion de ventas\n";
            cin>>Opcion;
            entradaValida=OpcionValida(Opcion, 4);
        }

        entradaValida=false;

        if (Opcion==0) salir = true;

        else if (Opcion==1){

            do{
                cout<<"\nEscoja una opcion:\n0. Salir\n1. Agregar Estacion de Servicio\n2. Eliminar Estaciones de Servicio\n3. Calcular Monto Total de Ventas\n4. Fijar los precios de combustible\n";
                cin>>Opcion_;
                entradaValida=OpcionValida(Opcion_, 4);

                if (Opcion_==0) entradaValida=true;

                else if (Opcion_==1){
                    cout<<"Se agrego la estacion (magia)\n";
                    entradaValida=false;
                }

                else if (Opcion_==2){
                    cout<<"Se elimino la estacion (o no si no se puede) (magia)\n";
                    entradaValida=false;
                }

                else if (Opcion_==3){
                    cout<<"Se calculo el monto total (magia)\n";
                    entradaValida=false;
                }

                else if (Opcion_==4){
                    entradaValida=false;
                    while(!entradaValida){
                        cout<<"\nEn que region desea cambiar el precio?\n1. Norte\n2. Centro\n3. Sur\n";
                        cin>>Opcion_Region;
                        entradaValida=OpcionValida(Opcion_Region,3,1);
                        Opcion_Region--;
                    }

                    entradaValida=false;

                    while(!entradaValida){
                        cout<<"\nDe que tipo de combustible desea cambiar el precio?\n1. Regular\n2. Premium\n3. EcoExtra\n";
                        cin>>Opcion_Combustible;
                        entradaValida=OpcionValida(Opcion_Combustible,3);
                        Opcion_Combustible--;
                    }

                    entradaValida=false;

                    while(!entradaValida){
                        cout<<"\nCual sera el nuevo precio? (Precio por litro)\n";
                        cin>>Opcion_Precio;
                        entradaValida=OpcionValida(Opcion_Precio,65535);
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
        entradaValida=false;
    }
    while(!salir);
    return 0;
}
