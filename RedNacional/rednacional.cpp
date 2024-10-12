#include "rednacional.h"
#include "estacion.h"
#include <iostream>
#include <string>

RedNacional::RedNacional():CantidadEstaciones(0),Estaciones(nullptr){
    int precio = 1000;
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            PrecioCombustible[i][j]=precio*((j+1)+(i+1)/(3-i));
        }
    }
}

RedNacional::~RedNacional(){}

void RedNacional::setPrecios(int Region, int Tipo, int NuevoPrecio){
    PrecioCombustible[Region][Tipo]=NuevoPrecio;
}

void RedNacional::AgregarES(string nombre, int cod_est, string gerente, int region, int cantidad_islas, int Lat, int Long){
    int gps[2]{Lat, Long};
    Estacion* Nueva = new Estacion (nombre, cod_est, gerente, region, cantidad_islas, gps);
    Estacion** NuevaEstaciones = new Estacion* [CantidadEstaciones+1];
    NuevaEstaciones[CantidadEstaciones] = Nueva;
    for (int i = 0; i<CantidadEstaciones; i++){
        NuevaEstaciones[i]=Estaciones[i];
    }
    //string nombre, int codigo, string gerente, int region, int cantidad_islas, int gps[2]

    delete [] Estaciones;
    Estaciones=NuevaEstaciones;
    CantidadEstaciones++;
}

void RedNacional::EliminarES(int Est){
    Estacion** Eliminar = new Estacion* [CantidadEstaciones+1];
    for (int i = 0; i<CantidadEstaciones; i++){
        if (i<Est) Eliminar[i]=Estaciones[i];
        else if (i>Est) Eliminar[i-1]=Estaciones[i];
    }
    for (int i = 0; i<CantidadEstaciones; i++){
        delete Estaciones[i];
    }
    delete [] Estaciones;
    Estaciones = Eliminar;
}

void RedNacional::Ventas(){
    unsigned int pais [3]{0,0,0};
    unsigned int total [3]{0,0,0};
    unsigned int parcial [3]{0,0,0};
    std::cout<<"Ventas a lo largo del pais:\n";
    for (int i = 0; i < CantidadEstaciones; i++){
        std::cout<<"_______________________________________\nEstacion "<<Estaciones[i]->getcodigo()<<std::endl;
        std::cout<<"Surtidor|Regular|Premium|EcoExtra"<<std::endl;
        for (int j = 0; j<Estaciones[i]->getcantsurts(); j++){
            std::cout<<(Estaciones[i]->getSurtidor(j))->getCodigo()<<"\t|";
            for (int k = 0; k<(Estaciones[i]->getSurtidor(j))->getCantVentas(); k++){
                parcial[(Estaciones[i]->getSurtidor(j))->getDatoVentas(k,6)]+=(Estaciones[i]->getSurtidor(j))->getDatoVentas(k,9);
            }
            for (int k = 0; k<3; k++){
                std::cout<<parcial[k]<<"\t|";
                total[k]+=parcial[k];
                pais[k]+=parcial[k];
                parcial[k]=0;
            }
            std::cout<<std::endl;
        }
        std::cout<<"Total\t|"<<total[0]<<"\t|"<<total[1]<<"\t|"<<total[2]<<"\t|"<<std::endl;
        total[0]=0; total[1]=0; total[2]=0;
    }
    std::cout<<"_______________________________________\nPais\t|"<<pais[0]<<"\t|"<<pais[1]<<"\t|"<<pais[2]<<"\t|"<<std::endl;
}
