#ifndef SURTIDOR_H
#define SURTIDOR_H
//#include <iostream>
#include <string>

using namespace std;

class Surtidor
{
private:
    int codigo_;
    string modelo_;
    short unsigned int cantventas_;
    bool activado_;
    int** ventas;

    void setCodigo(unsigned int newCodigo){codigo_ = newCodigo;}
    void setModelo(unsigned int newModelo){modelo_ = newModelo;}
    void setCantVentas(unsigned int newCantVentas){cantventas_ = newCantVentas;}

    void setVentas(int** newVentas);


public:
    Surtidor(unsigned int codigo, string modelo);
    ~Surtidor();

    int getCodigo() {return codigo_;}
    string getModelo() const {return modelo_;}
    short unsigned int getCantVentas() const {return cantventas_;}
    unsigned int getDatoVentas(unsigned short int numVenta, unsigned short int numData);
    bool getActivado()const {return activado_;}

    void setActivado(bool newActivado){activado_ = newActivado;}

    void printCodigo() const;
    void printModelo() const;
    void printCantVentas() const;
    void printVentas(int posventa) const;
    void printActivado() const;

    void newVenta(int CantComb, int TipoComb, int MetodoPago, int DocCliente, int Dinero);
    void cambiarIsla(int NewIsla);//Conversar si es necesario o no (problemas de seguridad)
};

#endif // SURTIDOR_H
