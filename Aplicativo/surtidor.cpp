#include "surtidor.h"
#include <iostream>
#include <chrono>

Surtidor::Surtidor(unsigned int codigo, string modelo):codigo_(codigo), modelo_(modelo), cantventas_(0), activado_(true), ventas(nullptr){}

Surtidor::~Surtidor(){
    for (int i = 0; i<cantventas_; i++){
        delete[] ventas[i];
    }
    delete[] ventas;
}

void Surtidor::setVentas(int** newVentas){

    delete[] ventas;
    ventas=new int* [cantventas_+1];

    for (int i = 0; i<cantventas_+1; i++){
        *(ventas+i)=*(newVentas+i);
    }
    cantventas_++;
}

unsigned int Surtidor::getDatoVentas(unsigned short int numVenta, unsigned short int numData){
    if (numVenta<cantventas_){
        return ventas[numVenta][numData];
    }
    else return 0;
}

void Surtidor:: newVenta(int CantComb, int TipoComb, int MetodoPago, int DocCliente, int Dinero){
    int** ventaActu = new int* [cantventas_+1];
    for (int i = 0; i<cantventas_; i++){
        ventaActu[i]=ventas[i];
    }

    auto ahora = std::chrono::system_clock::now();
    std::time_t tiempoActual = std::chrono::system_clock::to_time_t(ahora);
    std::tm tmStruct;
    localtime_s(&tmStruct, &tiempoActual);

    ventaActu[cantventas_]=new int [10]{tmStruct.tm_year+1900, tmStruct.tm_mon+1, tmStruct.tm_mday, tmStruct.tm_hour, tmStruct.tm_min, CantComb, TipoComb, MetodoPago, DocCliente, Dinero};

    Surtidor::setVentas(ventaActu);
    delete[] ventaActu;
}

void Surtidor::printCodigo() const{
    std::cout<<"Codigo: "<<codigo_<<std::endl;
}

void Surtidor:: printModelo() const{
    std::cout<<"Modelo: "<<modelo_<<std::endl;
}

void Surtidor:: printCantVentas() const{
    std::cout<<"Cantidad Ventas: "<<cantventas_<<std::endl;
}

void Surtidor:: printVentas(int posventa) const{

    if (cantventas_<1){
        std::cout<<std::endl<<"El surtidor con codigo "<< codigo_ <<" no ha realizado ventas"<<std::endl;
        return;
    }

    if (posventa>=cantventas_){
        std::cout<<std::endl<<"Ya se mostraron todas las ventas del surtidor con codigo "<< codigo_ <<std::endl;
        return;
    }

    std::cout<<std::endl<<"Venta Numero "<<posventa+1<<" del Surtidor con Codigo "<<codigo_<<std::endl;
    for (int j = 0; j<10; j++){
        switch (j){

        case 0:
            std::cout<<std::endl<<"Fecha y Hora:\nAnio\tMes\tDia\tHora\tMins"<<std::endl;
            std::cout<<ventas[posventa][j]<<'\t';
            break;

        case 5:
            std::cout<<std::endl<<"\nCombustible:\nCantidad\tTipo"<<std::endl;
            std::cout<<ventas[posventa][j]<<'\t'<<'\t';
            break;

        case 6:
            switch (ventas[posventa][j]){
            case 0:
                std::cout<<"Regular\n";
                break;
            case 1:
                std::cout<<"Premium\n";
                break;
            case 2:
                std::cout<<"EcoExtra\n";
                break;
            }
            break;

        case 7:
            std::cout<<std::endl<<"Cliente: "<<std::endl<<"Metodo pago\tDocumento\tDinero"<<std::endl;
            switch (ventas[posventa][j]){
            case 0:
                std::cout<<"Efectivo\t";
                break;
            case 1:
                std::cout<<"TCredito\t";
                break;
            case 2:
                std::cout<<"Tdebito \t";
                break;
            }
            break;

        default:
            std::cout<<ventas[posventa][j]<<'\t';
        }
    }
    std::cout<<std::endl<<"_________________________________________"<<std::endl;
}

void Surtidor::cambiarIsla(int NewIsla){
    codigo_-=codigo_%1000-codigo_%10;
    codigo_+=NewIsla*1000;
}
