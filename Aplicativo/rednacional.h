#ifndef REDNACIONAL_H
#define REDNACIONAL_H
#include "estacion.h"
class RedNacional
{
private:
    Estacion** Estaciones;
    short unsigned int PrecioCombustible [3][3];
    short unsigned int CantidadEstaciones;

public:
    RedNacional();
    ~RedNacional();
    void AgregarES(string nombre, string gerente, short unsigned int region, float Lat, float Long);
    void EliminarES(short unsigned int Est);
    void Ventas();
    void setPrecios(short unsigned int Region, short unsigned int Tipo, short unsigned int NuevoPrecio);

    short unsigned int getPrecio(int Region, int Tipo){return PrecioCombustible[Region][Tipo];}
    short unsigned int getCantEsts(){return CantidadEstaciones;}
    Estacion* getEstacion(int Est){return Estaciones[Est];}

    void VerificarFugas(Estacion* Est);
};

#endif // REDNACIONAL_H
