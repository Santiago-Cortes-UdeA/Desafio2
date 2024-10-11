#ifndef SURTIDOR_H
#define SURTIDOR_H
//#include <iostream>
#include <string>

using namespace std;

class Surtidor
{
private:
    short unsigned int codigo_;
    string modelo_;
    short unsigned int cantventas_;
    bool activado_;
    int** ventas = new int* [cantventas_];

    void setCodigo(unsigned int newCodigo){codigo_ = newCodigo;}
    void setModelo(unsigned int newModelo){modelo_ = newModelo;}
    void setCantVentas(unsigned int newCantVentas){cantventas_ = newCantVentas;}
    void setActivado(bool newActivado){activado_ = newActivado;}
    void setVentas(int** newVentas);


public:
    Surtidor(short unsigned int codigo, string modelo, bool activado = true);
    ~Surtidor();

    short unsigned int getCodigo() {return codigo_;}
    string getModelo() const {return modelo_;}
    short unsigned int getCantVentas() const {return cantventas_;}
    unsigned int getDatoVentas(unsigned short int numVenta, unsigned short int numData);
    bool getActivado()const {return activado_;}

    void printCodigo() const;
    void printModelo() const;
    void printCantVentas() const;
    void printVentas(int posventa) const;
    void printActivado() const;

    void newVenta(int CantComb, int TipoComb, int MetodoPago, int DocCliente, int Dinero);
};

#endif // SURTIDOR_H
