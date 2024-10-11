#ifndef ESTACION_H
#define ESTACION_H

//#include <iostream>
#include <string>
#include "surtidor.h"

using namespace std;

class Estacion {

friend void AsignarCapTC(Estacion &Est);

private:
    // Atributos
    string nombre_;
    int codigo_;
    string gerente_;
    int region_;
    int cantidad_surtidores_;
    int cantidad_islas_;
    int gps_[2];
    int almacenamiento_actual_[3];
    Surtidor* Surtidores;
    unsigned short int* codigos_islas;
    int tanque_central_[3];

    // Setters
    void setNombre(string nombre) {nombre_= nombre;}
    void setCodigo(int codigo) {codigo_= codigo;}
    void setGerente(string gerente) {gerente_= gerente;}
    void setRegion(int region) {region_= region;}
    void setGPS(int gps[2]) {
        gps_[0]= gps[0];
        gps_[1]= gps[1];
    }

    void setAlmacenamientoActual(int almacenamiento_actual[3]) {
        almacenamiento_actual_[0]= almacenamiento_actual[0];
        almacenamiento_actual_[1]= almacenamiento_actual[1];
        almacenamiento_actual_[2]= almacenamiento_actual[2];
    }
    void set_cantidad_surtidores(int cantidad_surtidores) {cantidad_surtidores_ = cantidad_surtidores;}
    void set_cantidad_islas(int cantidad_islas) {cantidad_islas_ = cantidad_islas;}

    // Otros
    void AddSurtidor();
    void DeleteSurtidor();
    void ActivarSurtidor();
    void DesactivarSurtidor();
    void ConsultarTransacciones();
    void ReporteCantVendidaCombustibles();
    void SimularVenta();

public:
    // Constructor
    Estacion(string nombre, int codigo, string gerente, int region, int cantidad_islas, int cantidad_surtidores, int gps[2], int almacenamiento_actual[3]);
    ~Estacion();

    // Getters
    string getnombre() const {return nombre_;}
    int getcodigo() const {return codigo_;}
    string getgerente() const {return gerente_;}
    int getregion() const {return region_;}
    int* getgps() {return gps_;}
    int* gettanquecentral() {return tanque_central_;}
    int* getalmacenamientoactual() {return almacenamiento_actual_;}
};

#endif // ESTACION_H
