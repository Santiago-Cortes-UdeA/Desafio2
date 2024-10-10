#include <iostream>
#include "rednacional.h"
using namespace std;

int main()
{
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

    return 0;
}
