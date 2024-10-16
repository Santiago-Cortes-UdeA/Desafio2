#include "rednacional.h"
#include "estacion.h"
#include <iostream>
#include <string>

RedNacional::RedNacional():CantidadEstaciones(0),Estaciones(nullptr){
    short unsigned int precio = 1000;
    for (short unsigned int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            PrecioCombustible[i][j]=precio*((j+1)+(i+1)/(3-i));
        }
    }
}

RedNacional::~RedNacional(){
    delete[] Estaciones;
}

void RedNacional::setPrecios(short unsigned int Region, short unsigned int Tipo, short unsigned int NuevoPrecio){
    PrecioCombustible[Region][Tipo]=NuevoPrecio;
}

void RedNacional::AgregarES(string nombre, string gerente, short unsigned int region, float Lat, float Long){
    float gps[2]{Lat, Long};
    int cod_est = (region+1)*100;
    bool crear = true;
    if (CantidadEstaciones>0){
        cod_est += ((Estaciones[CantidadEstaciones-1]->getcodigo())%100)+1;
        for (short unsigned int i = 0; i<CantidadEstaciones; i++){
            if (Estaciones[i]->getnombre()==nombre){
                crear = false;
                cout<<endl<<"El nombre de la Estacion no puede coincidir con el de otra ya existente"<<endl;
                break;
            }
            else if (Estaciones[i]->getgps()[0]==gps[0] && Estaciones[i]->getgps()[1]==gps[1]){
                crear = false;
                cout<<endl<<"Las coordenadas GPS de la Estacion no pueden coincidir con las de otra ya existente"<<endl;
                break;
            }
        }
    }
    if (crear){
        Estacion* Nueva = new Estacion (nombre, cod_est, gerente, region, gps);
        Estacion** NuevaEstaciones = new Estacion* [CantidadEstaciones+1];
        NuevaEstaciones[CantidadEstaciones] = Nueva;
        for (short unsigned int i = 0; i<CantidadEstaciones; i++){
            NuevaEstaciones[i]=Estaciones[i];
        }

        delete [] Estaciones;
        Estaciones=NuevaEstaciones;
        CantidadEstaciones++;
        cout<<endl<<"Se agrego la estacion exitosamente"<<endl;
    }

    else{
        cout<<endl<<"No se pudo agregar la Estacion"<<endl;
    }
}

void RedNacional::EliminarES(short unsigned int Est){
    for (short unsigned int i = 0; i<Estaciones[Est]->getcantsurts(); i++){
        if (Estaciones[Est]->getSurtidor(i)->getActivado()){
            std::cout<<std::endl<<"La estacion no se puede eliminar ya que todavia posee surtidores activos"<<std::endl;
            return;
        }
    }
    Estacion** Eliminar = new Estacion* [CantidadEstaciones+1];
    for (short unsigned int i = 0; i<CantidadEstaciones; i++){
        if (i<Est) Eliminar[i]=Estaciones[i];
        else if (i>Est) Eliminar[i-1]=Estaciones[i];
    }
    delete [] Estaciones;
    CantidadEstaciones--;
    Estaciones = Eliminar;
    std::cout<<endl<<"La estacion fue eliminada con exito"<<endl;
}

void RedNacional::Ventas(){
    unsigned int pais [3]{0,0,0};
    unsigned int total [3]{0,0,0};
    unsigned int parcial [3]{0,0,0};
    std::cout<<"Ventas a lo largo del pais:\n";
    for (short unsigned int i = 0; i < CantidadEstaciones; i++){
        std::cout<<"_______________________________________\nEstacion "<<Estaciones[i]->getnombre()<<" ("<<Estaciones[i]->getcodigo()<<')'<<std::endl;
        std::cout<<"Surtidor|Regular|Premium|EcoExtra"<<std::endl;
        for (short unsigned int j = 0; j<Estaciones[i]->getcantsurts(); j++){
            std::cout<<(Estaciones[i]->getSurtidor(j))->getCodigo()<<"\t|";
            for (short unsigned int k = 0; k<(Estaciones[i]->getSurtidor(j))->getCantVentas(); k++){
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

void RedNacional::VerificarFugas(Estacion* Est){
    bool fuga = false;
    for (short unsigned int i = 0; i<3; i++){
        if (Est->getvendido(i)+Est->getalmacenamientoactual(i)<Est->gettanquecentral(i)*0.95){
            cout<<"Hay una fuga de "<<Est->gettanquecentral(i) - (Est->getvendido(i)+Est->getalmacenamientoactual(i))<<" Litros de ";
            switch (i){
            case 0:
                cout<<"Regular";
                break;
            case 1:
                cout<<"Premium";
                break;
            case 2:
                cout<<"EcoExtra";
                break;
            }
            cout<<" en la Estacion "<<Est->getnombre()<<" ("<<Est->getcodigo()<<')'<<endl;
            fuga = true;
        }
    }

    if (!fuga){
        cout<<endl<<"No se encontraron fugas en la Estacion "<<Est->getnombre()<<" ("<<Est->getcodigo()<<')'<<endl;
    }
}
