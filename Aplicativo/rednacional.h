#ifndef REDNACIONAL_H
#define REDNACIONAL_H
#include "estacion.h"
class RedNacional
{
private:
    Estacion** Estaciones;
    int PrecioCombustible [3][3];
    int CantidadEstaciones;

public:
    RedNacional();
    ~RedNacional();
    void AgregarES(string nombre, string gerente, int region, float Lat, float Long);
    void EliminarES(int Est);
    void Ventas();
    void setPrecios(int Region, int Tipo, int NuevoPrecio);

    int getPrecio(int Region, int Tipo){return PrecioCombustible[Region][Tipo];}
    int getCantEsts(){return CantidadEstaciones;}
    Estacion* getEstacion(int Est){return Estaciones[Est];}
};

#endif // REDNACIONAL_H
