#ifndef ESTACION_H
#define ESTACION_H

//#include <iostream>
#include <string>
#include "surtidor.h"

using namespace std;

class Estacion {

    friend void AsignarCapTC(Estacion& Est);

private:
    // Atributos
    string nombre_;
    int codigo_;
    string gerente_;
    int region_;
    int cantidad_surtidores_;
    int cantidad_islas_;
    float gps_[2];
    int almacenamiento_actual_[3];
    Surtidor** Surtidores;
    int* codigos_islas;
    int tanque_central_[3];

    // Setters
    void setNombre(string nombre) {nombre_= nombre;}
    void setCodigo(int codigo) {codigo_= codigo;}
    void setGerente(string gerente) {gerente_= gerente;}
    void setRegion(int region) {region_= region;}
    void setGPS(float gps[2]) {
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

public:
    // Constructor
    Estacion(string nombre, int codigo, string gerente, int region, float gps[2]);
    ~Estacion();

    // Getters
    string getnombre() const {return nombre_;}
    int getcodigo() const {return codigo_;}
    string getgerente() const {return gerente_;}
    int getregion() const {return region_;}
    int getcantsurts() const {return cantidad_surtidores_;}
    int getcantislas() const {return cantidad_islas_;}
    int getcodigoisla(int isla){return codigos_islas[isla];}
    int gettanquecentral(int tipo) {return tanque_central_[tipo];}
    int getalmacenamientoactual(int tipo) {return almacenamiento_actual_[tipo];}
    float* getgps() {return gps_;}
    Surtidor* getSurtidor(int Surt) {return Surtidores[Surt];}

    // Otros
    void AddSurtidor(string Modelo, int Isla);
    void DeleteSurtidor(int Surt);
    void MoverSurtIsla(int Surt, int Isla); //Conversar si es necesario (Problemas de seguridad)
    void ActivarSurtidor(int Surt);
    void DesactivarSurtidor(int Surt);

    void SimularVenta(int Surt, int PrecioCombustible);
    void ConsultarTransacciones();
    void ReporteCantVendidaCombustibles();
};

#endif // ESTACION_H
