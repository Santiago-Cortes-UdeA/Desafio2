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
    short unsigned int codigo_;
    string gerente_;
    short unsigned int region_;
    short unsigned int cantidad_surtidores_;
    short unsigned int cantidad_islas_;
    float gps_[2];
    short unsigned int almacenamiento_actual_[3];
    Surtidor** Surtidores;
    short unsigned int* codigos_islas;
    short unsigned int tanque_central_[3];
    short unsigned int vendido_[3];

public:
    // Constructor
    Estacion(string nombre, short unsigned int codigo, string gerente, short unsigned int region, float gps[2]);
    ~Estacion();

    // Getters
    string getnombre() const {return nombre_;}
    short unsigned int getcodigo() const {return codigo_;}
    string getgerente() const {return gerente_;}
    short unsigned int getregion() const {return region_;}
    short unsigned int getcantsurts() const {return cantidad_surtidores_;}
    short unsigned int getcantislas() const {return cantidad_islas_;}
    short unsigned int getcodigoisla(short unsigned int isla){return codigos_islas[isla];}
    short unsigned int gettanquecentral(short unsigned int tipo) {return tanque_central_[tipo];}
    short unsigned int getalmacenamientoactual(short unsigned int tipo) {return almacenamiento_actual_[tipo];}
    short unsigned int getvendido(short unsigned int tipo){return vendido_[tipo];}
    float* getgps() {return gps_;}
    Surtidor* getSurtidor(int Surt) {return Surtidores[Surt];}

    // Otros
    void AddSurtidor(string Modelo, short unsigned int Isla);
    void DeleteSurtidor(short unsigned int Surt);
    void ActivarSurtidor(short unsigned int Surt);
    void DesactivarSurtidor(short unsigned int Surt);

    void SimularVenta(short unsigned int PrecioCombustible, short unsigned int TipoComb);
    void SimularFuga();
    void ConsultarTransacciones();
    void ReporteCantVendidaCombustibles();
};

#endif // ESTACION_H
