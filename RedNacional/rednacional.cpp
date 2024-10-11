#include "rednacional.h"

RedNacional::RedNacional(){
    int precio = 1000;
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            PrecioCombustible[i][j]=precio*((j+1)+(i+1)/(3-i));
        }
    }
}

RedNacional::~RedNacional(){}

void RedNacional::setPrecios(int Region, int Tipo, int NuevoPrecio){
    PrecioCombustible[Region][Tipo]=NuevoPrecio;
}
