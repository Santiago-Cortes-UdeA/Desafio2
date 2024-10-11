#ifndef REDNACIONAL_H
#define REDNACIONAL_H

class RedNacional
{
private:
    //ES* Estaciones = new ES [x]
    int PrecioCombustible [3][3];

public:
    RedNacional();
    ~RedNacional();
    void AgregarES();
    void EliminarES();
    void Ventas();
    void setPrecios(int Region, int Tipo, int NuevoPrecio);

    int getPrecio(int Region, int Tipo){return PrecioCombustible[Region][Tipo];}
};

#endif // REDNACIONAL_H
