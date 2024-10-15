#include "estacion.h"
#include <random>

void AsignarCapTC(Estacion& Est){
    srand(time(0));
    for (int i = 0; i<3; i++){
        Est.tanque_central_[i]=(rand()%101)+100;
    }
}

Estacion::Estacion(string nombre, int codigo, string gerente, int region, int cantidad_islas, int cantidad_surtidores, int gps[2], int almacenamiento_actual[3])
    : nombre_(nombre), codigo_(codigo), gerente_(gerente), region_(region), cantidad_surtidores_(cantidad_surtidores), cantidad_islas_(cantidad_islas), gps_{gps[0],gps[1]}, almacenamiento_actual_{almacenamiento_actual[0], almacenamiento_actual[1], almacenamiento_actual[2]}, Surtidores(nullptr), codigos_islas(nullptr) {
    AsignarCapTC(*this);
}

Estacion::~Estacion(){}
