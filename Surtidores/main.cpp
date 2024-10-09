#include <iostream>
#include "surtidor.h"
using namespace std;

int main()
{
    Surtidor Surt1(1012, "Vf5");
    Surt1.newVenta(Surt1.getCantVentas(), 2024, 7, 24, 5, 35, 4, 1, 0, 1015071356, 120000);
    Surt1.newVenta(Surt1.getCantVentas(), 2024, 7, 26, 14, 42, 7, 2, 2, 1012086371, 154000);
    Surt1.newVenta(Surt1.getCantVentas(), 2024, 8, 2, 2, 12, 5, 1, 1, 1023034634, 123987);
    Surt1.printCodigo();
    cout<<endl;
    Surt1.printModelo();
    cout<<endl;
    Surt1.printCantVentas();
    cout<<endl;
    Surt1.printVentas();
    //int**& ventas, int cantventas, int Year, int Mes, int Dia, int Hora, int Min, int CantComb, int TipoComb, int MetodoPago, int DocCliente, int Dinero
    return 0;
}
