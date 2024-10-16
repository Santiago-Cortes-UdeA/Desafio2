#include "estacion.h"
#include "surtidor.h"
#include <iostream>
#include <string>

void AsignarCapTC(Estacion& Est){
    srand(time(0));
    for (int i = 0; i<3; i++){
        Est.tanque_central_[i]=(rand()%101)+100;
        Est.almacenamiento_actual_[i]=Est.tanque_central_[i];
    }
}

Estacion::Estacion(string nombre, int codigo, string gerente, int region, int cantidad_islas, int gps[2])
    : nombre_(nombre), codigo_(codigo), gerente_(gerente), region_(region), cantidad_surtidores_(0), cantidad_islas_(cantidad_islas), gps_{gps[0],gps[1]}, Surtidores(nullptr), codigos_islas(nullptr) {
    AsignarCapTC(*this);
}

Estacion::~Estacion(){}

void Estacion::AddSurtidor(string Modelo, short unsigned int cod_surt) {
    unsigned int codigo = (codigo_ * 100) + cod_surt;
    Surtidor* Nuevo = new Surtidor (codigo, Modelo);
    Surtidor** SurtidoresNew = new Surtidor*[cantidad_surtidores_+1];
    for (int i = 0; i<cantidad_surtidores_; i++){
        SurtidoresNew[i]=Surtidores[i];
    }
    delete[] Surtidores;
    SurtidoresNew[cantidad_surtidores_] = Nuevo;
    Surtidores = SurtidoresNew;
    cantidad_surtidores_++;
}

void Estacion::DeleteSurtidor(int Surt){
    if (!Surtidores[Surt]->getActivado()){
        Surtidor** Nuevo = new Surtidor* [cantidad_surtidores_-1];
        for (int i = 0; i<cantidad_surtidores_; i++){
            if (i<Surt) Nuevo[i]=Surtidores[i];
            else if (i>Surt) Nuevo[i-1]=Surtidores[i];
        }
        delete Surtidores[Surt];
        delete [] Surtidores;
        Surtidores=Nuevo;
        cantidad_surtidores_--;
        std::cout<<endl<<"Surtidor borrado exitosamente"<<endl;
    }
    else{
        std::cout<<endl<<"No se puedo eliminar el surtidor "<<Surtidores[Surt]->getCodigo()<<" ya que permanece activo"<<endl;
    }
}

void Estacion::ActivarSurtidor(int Surt){
    if (!Surtidores[Surt]->getActivado()){
        Surtidores[Surt]->setActivado(true);
        std::cout<<"El surtidor "<<Surtidores[Surt]->getCodigo()<<" fue activado exitosamente"<<std::endl;
    }
    else{
        std::cout<<"El surtidor "<<Surtidores[Surt]->getCodigo()<<" ya estaba activado"<<std::endl;
    }
}

void Estacion::DesactivarSurtidor(int Surt){
    if (Surtidores[Surt]->getActivado()){
        Surtidores[Surt]->setActivado(false);
        std::cout<<"El surtidor "<<Surtidores[Surt]->getCodigo()<<" fue desactivado exitosamente"<<std::endl;
    }
    else{
        std::cout<<"El surtidor "<<Surtidores[Surt]->getCodigo()<<" ya estaba desactivado"<<std::endl;
    }
}

void Estacion::ConsultarTransacciones(){
    for (int i = 0; i<cantidad_surtidores_; i++){
        for (int j = 0; j<Surtidores[i]->getCantVentas(); j++){
            Surtidores[i]->printVentas(j);
        }
    }
}

void Estacion::ReporteCantVendidaCombustibles(){
    cout<<"Se ha vendido:"<<endl<<"Regular\t\tPremium\t\tEcoExtra\n";
    for (int i = 0; i<3; i++){
        cout<<tanque_central_[i]-almacenamiento_actual_[i]<<" Litros\t";
    }
}

void Estacion::SimularVenta(int Surt, int PrecioCombustible){

    int CantComb = (rand()%18)+3;
    int TipoComb = rand()%3;
    if (CantComb>almacenamiento_actual_[TipoComb]) CantComb=almacenamiento_actual_[TipoComb];
    Surtidores[Surt]->newVenta(CantComb, TipoComb, rand()%3, (rand()%1000000000)+1000000000, CantComb*PrecioCombustible);
    Surtidores[Surt]->printVentas(Surtidores[Surt]->getCantVentas()-1);
    almacenamiento_actual_[TipoComb]-=CantComb;
}
