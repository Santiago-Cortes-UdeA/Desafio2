#include "surtidor.h"
#include <iostream>

Surtidor::Surtidor(int codigo, string modelo, int cantventas, bool activado):codigo_(codigo), modelo_(modelo), cantventas_(cantventas), activado_(activado){}

Surtidor::~Surtidor(){

}

void Surtidor::setVentas(int** newVentas, int cantventas){
    delete[] ventas;
    ventas=new int* [cantventas];

    for (int i = 0; i<cantventas; i++){
        *(ventas+i)=*(newVentas+i);
    }
}

void Surtidor:: newVenta(int cantventas, int Year, int Mes, int Dia, int Hora, int Min, int CantComb, int TipoComb, int MetodoPago, int DocCliente, int Dinero){
    int** ventaActu = new int* [cantventas+1];
    for (int i = 0; i<cantventas; i++){
        ventaActu[i]=ventas[i];
    }

    ventaActu[cantventas]=new int [10]{Year, Mes, Dia, Hora, Min, CantComb, TipoComb, MetodoPago, DocCliente, Dinero};

    Surtidor::setVentas(ventaActu, cantventas+1);
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

void Surtidor:: printVentas() const{
    std::cout<<"Datos de Ventas:"<<std::endl;
    for (int i = 0; i<cantventas_; i++){
        std::cout<<std::endl<<"Venta Numero "<<i+1<<std::endl;
        for (int j = 0; j<10; j++){
            switch (j){

            case 0:
                std::cout<<"Fecha y Hora:"<<std::endl<<"Anio\tMes\tDia\tHora\tMins"<<std::endl;
                std::cout<<ventas[i][j]<<'\t';
                break;

            case 5:
                std::cout<<std::endl<<"Combustible: "<<std::endl<<"Cantidad\tTipo"<<std::endl;
                std::cout<<ventas[i][j]<<'\t'<<'\t';
                break;

            case 6:
                switch (ventas[i][j]){
                case 0:
                    std::cout<<"Regular";
                    break;
                case 1:
                    std::cout<<"Premium";
                    break;
                case 2:
                    std::cout<<"EcoExtra";
                    break;
                }
                break;

            case 7:
                std::cout<<std::endl<<"Cliente: "<<std::endl<<"Metodo pago\tDocumento\tDinero"<<std::endl;
                switch (ventas[i][j]){
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
                    std::cout<<ventas[i][j]<<'\t';
            }
        }
        std::cout<<std::endl<<"_________________________________________";
    }
}
