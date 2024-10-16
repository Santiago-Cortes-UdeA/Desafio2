#include "estacion.h"
#include "surtidor.h"
#include <iostream>
#include <string>

Estacion::Estacion(string nombre, short unsigned int codigo, string gerente, short unsigned int region, float gps[2])
    : nombre_(nombre), codigo_(codigo), gerente_(gerente), region_(region), cantidad_surtidores_(0), cantidad_islas_(0), gps_{gps[0],gps[1]}, Surtidores(nullptr), codigos_islas(nullptr), vendido_{0,0,0} {

    srand(time(0));
    for (int i = 0; i<3; i++){
        tanque_central_[i]=(rand()%101)+100;
        almacenamiento_actual_[i]=tanque_central_[i];
    }
}

Estacion::~Estacion(){
    delete[] Surtidores;
}

void Estacion::AddSurtidor(string Modelo, short unsigned int Isla){
    unsigned int cod_surt=codigo_*10000;
    if (Isla == 0){
        short unsigned int* NuevaIsla = new short unsigned int [cantidad_islas_+1];
        if (codigos_islas){
            for (int i = 0; i<cantidad_islas_; i++){
                NuevaIsla[i]=codigos_islas[i];
            }
            NuevaIsla[cantidad_islas_]=codigos_islas[cantidad_islas_-1]+1;
        }
        else{
            NuevaIsla[0]=0;
        }
        delete[] codigos_islas;
        codigos_islas=NuevaIsla;
        cod_surt+=NuevaIsla[cantidad_islas_]*100;
        cantidad_islas_++;
    }
    else{
        cod_surt+=codigos_islas[Isla-1]*100;
    }

    if (cantidad_surtidores_>0){
        cod_surt+=((Surtidores[cantidad_surtidores_-1]->getCodigo())%100)+1;
    }
    Surtidor* Nuevo = new Surtidor (cod_surt, Modelo);
    Surtidor** SurtidoresNew = new Surtidor*[cantidad_surtidores_+1];
    for (int i = 0; i<cantidad_surtidores_; i++){
        SurtidoresNew[i]=Surtidores[i];
    }
    delete[] Surtidores;
    SurtidoresNew[cantidad_surtidores_] = Nuevo;
    Surtidores = SurtidoresNew;
    cantidad_surtidores_++;
    cout<<endl<<"El surtidor se agrego con exito"<<endl;
}

void Estacion::DeleteSurtidor(short unsigned int Surt){
    bool DeleteIsla = true;
    short unsigned int CodIsla = Surtidores[Surt]->getCodigo()%1000/100;
    if (!Surtidores[Surt]->getActivado()){
        Surtidor** Nuevo = new Surtidor* [cantidad_surtidores_-1];
        for (int i = 0; i<cantidad_surtidores_; i++){
            if (i<Surt) {
                Nuevo[i]=Surtidores[i];
                if (DeleteIsla && Nuevo[i]->getCodigo()%1000/100==CodIsla) DeleteIsla=false;
            }
            else if (i>Surt) {
                Nuevo[i-1]=Surtidores[i];
                if (DeleteIsla && Nuevo[i-1]->getCodigo()%1000/100==CodIsla) DeleteIsla=false;
            }
        }
        if (DeleteIsla){
            short unsigned int* BorradoIsla = new short unsigned int [cantidad_islas_-1];
            bool Eliminado = false;
            for (short unsigned int i = 0; i<cantidad_islas_; i++){
                if (codigos_islas[i]!=CodIsla && !Eliminado){
                    BorradoIsla[i]=codigos_islas[i];
                }
                else if (codigos_islas[i]==CodIsla){
                    Eliminado = true;
                }
                else{
                    BorradoIsla[i-1]=codigos_islas[i];
                }
            }
            delete[] codigos_islas;
            codigos_islas=BorradoIsla;
            cantidad_islas_--;
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

void Estacion::ActivarSurtidor(short unsigned int Surt){
    if (!Surtidores[Surt]->getActivado()){
        Surtidores[Surt]->setActivado(true);
        std::cout<<"El surtidor "<<Surtidores[Surt]->getCodigo()<<" fue activado exitosamente"<<std::endl;
    }
    else{
        std::cout<<"El surtidor "<<Surtidores[Surt]->getCodigo()<<" ya estaba activado"<<std::endl;
    }
}

void Estacion::DesactivarSurtidor(short unsigned int Surt){
    if (Surtidores[Surt]->getActivado()){
        Surtidores[Surt]->setActivado(false);
        std::cout<<"El surtidor "<<Surtidores[Surt]->getCodigo()<<" fue desactivado exitosamente"<<std::endl;
    }
    else{
        std::cout<<"El surtidor "<<Surtidores[Surt]->getCodigo()<<" ya estaba desactivado"<<std::endl;
    }
}

void Estacion::ConsultarTransacciones(){
    bool ventas = false;
    for (int i = 0; i<cantidad_surtidores_; i++){
        for (int j = 0; j<Surtidores[i]->getCantVentas(); j++){
            Surtidores[i]->printVentas(j);
            ventas=true;
        }
    }
    if (!ventas){
        cout<<endl<<"Esta estacion no ha realizado ventas aun"<<endl;
    }
}

void Estacion::ReporteCantVendidaCombustibles(){
    cout<<endl<<"Se ha vendido:"<<endl<<"Regular\t\tPremium\t\tEcoExtra\n";
    for (int i = 0; i<3; i++){
        cout<<vendido_[i]<<" Litros\t";
    }
    cout<<endl;
}

void Estacion::SimularVenta(int PrecioCombustible, short unsigned int TipoComb){
    short unsigned int CantComb = (rand()%18)+3;
    int* SurtidoresAct = new int [cantidad_surtidores_];
    short unsigned int CantSurtsAct = 0;
    for (int i = 0; i<cantidad_surtidores_; i++){
        if (Surtidores[i]->getActivado()){
            SurtidoresAct[CantSurtsAct]=i;
            CantSurtsAct++;
        }
    }
    if (CantSurtsAct>0){
        short unsigned int Surt = rand()%CantSurtsAct;
        if (CantComb>almacenamiento_actual_[TipoComb]) CantComb=almacenamiento_actual_[TipoComb];
        Surtidores[SurtidoresAct[Surt]]->newVenta(CantComb, TipoComb, rand()%3, (rand()%1000000000)+1000000000, CantComb*PrecioCombustible);
        Surtidores[SurtidoresAct[Surt]]->printVentas(Surtidores[SurtidoresAct[Surt]]->getCantVentas()-1);
        almacenamiento_actual_[TipoComb]-=CantComb;
        vendido_[TipoComb]+=CantComb;
    }
    else{
        cout<<endl<<"No se puede simular una venta ya que no hay surtidores activos en esta Estacion"<<endl;
    }
    delete[] SurtidoresAct;
}

void Estacion::SimularFuga(){
    short unsigned int Tipo = rand()%3;
    short unsigned int TamanoFuga = (rand()%tanque_central_[Tipo]/10)+1;
    if (TamanoFuga>almacenamiento_actual_[Tipo]) TamanoFuga=almacenamiento_actual_[Tipo];
    almacenamiento_actual_[Tipo]-=TamanoFuga;
    cout<<endl<<"Se ha creado una fuga de "<<TamanoFuga<<" Litros en la estacion "<<nombre_<<" ("<<codigo_<<')'<<endl;
}
