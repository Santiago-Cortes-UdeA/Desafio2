#include "surtidor.h"
#include <iostream>

Surtidor::Surtidor(short unsigned int codigo, string modelo, short unsigned int cantventas, bool activado):codigo_(codigo), modelo_(modelo), cantventas_(cantventas), activado_(activado){}

Surtidor::~Surtidor(){
    delete[] ventas;
}

void Surtidor::setVentas(unsigned int** newVentas){

    delete[] ventas;
    ventas=new unsigned int* [cantventas_+1];

    for (int i = 0; i<cantventas_+1; i++){
        *(ventas+i)=*(newVentas+i);
    }
}

unsigned int Surtidor::getDatoVentas(unsigned short int numVenta, unsigned short int numData){
    if (numVenta<cantventas_){
        return ventas[numVenta][numData];
    }
    else return -1;
}

void Surtidor:: newVenta(short unsigned int cantventas, short unsigned int Year, short unsigned int Mes, short unsigned int Dia, short unsigned int Hora, short unsigned int Min, short unsigned int CantComb, short unsigned int TipoComb, short unsigned int MetodoPago, unsigned int DocCliente, unsigned int Dinero){
    unsigned int** ventaActu = new unsigned int* [cantventas+1];
    for (int i = 0; i<cantventas; i++){
        ventaActu[i]=ventas[i];
    }

    ventaActu[cantventas]=new unsigned int [10]{Year, Mes, Dia, Hora, Min, CantComb, TipoComb, MetodoPago, DocCliente, Dinero};

    Surtidor::setVentas(ventaActu);
    delete[] ventaActu;
    this->setCantVentas(cantventas+1);
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

    std::cout<<std::endl<<"Venta Numero "<<posventa+1<<std::endl;
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
