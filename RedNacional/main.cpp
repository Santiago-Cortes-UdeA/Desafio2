#include <iostream>
#include "rednacional.h"
#include <string>
using namespace std;

int main()
{
    string Funcione = "";
    srand(time(0));
    RedNacional Red;

    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            cout << Red.getPrecio(i, j) << endl;
        }
    }

    int NuevosPrecios[3][3]{2000,2500,3000,1500,2500,3200,2500,3000,3500};

    cout << endl;
    for (int i = 0; i<3; i++){
        for (int j = 0; j<3; j++){
            Red.setPrecios(i,j,NuevosPrecios[i][j]);
            cout << Red.getPrecio(i, j) << endl;
        }
    }

    Red.AgregarES("Terpel", 1014, "Sara Hincapie", 1, 1, 14,15);

    Red.getEstacion(0)->AddSurtidor("TfV5",1);
    Red.getEstacion(0)->AddSurtidor("BcT14",2);
    Red.getEstacion(0)->AddSurtidor("SDfh5",3);

    Red.AgregarES("TerMax", 2016, "Santiago Cortes", 2, 2, 17,19);

    Red.getEstacion(1)->AddSurtidor("TfV5",1);
    Red.getEstacion(1)->AddSurtidor("BcT14",2);
    Red.getEstacion(1)->AddSurtidor("SDfh5",3);

    for (int i = 0; i<5; i++){
        for (int j = 0; j<Red.getCantEsts(); j++){
            Red.getEstacion(j)->SimularVenta(rand()%Red.getEstacion(j)->getcantsurts(),Red.getPrecio(Red.getEstacion(j)->getregion(),rand()%3));
        }
    }

    Red.Ventas();
    return 0;
}
