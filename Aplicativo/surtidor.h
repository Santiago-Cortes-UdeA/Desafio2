#ifndef SURTIDOR_H
#define SURTIDOR_H
#include <string>

using namespace std;

class Surtidor
{
private:
    unsigned int codigo_;
    string modelo_;
    short unsigned int cantventas_;
    bool activado_;
    int** ventas;

public:
    Surtidor(unsigned int codigo, string modelo);
    ~Surtidor();

    unsigned int getCodigo() {return codigo_;}
    string getModelo() const {return modelo_;}
    short unsigned int getCantVentas() const {return cantventas_;}
    unsigned int getDatoVentas(unsigned short int numVenta, unsigned short int numData);
    bool getActivado()const {return activado_;}

    void setActivado(bool newActivado){activado_ = newActivado;}

    void printVentas(int posventa) const;

    void newVenta(int CantComb, int TipoComb, int MetodoPago, int DocCliente, int Dinero);
};

#endif // SURTIDOR_H
