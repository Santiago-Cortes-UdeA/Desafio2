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
    unsigned int** ventas = new unsigned int* [cantventas_];

    void setCodigo(unsigned int newCodigo){codigo_ = newCodigo;}
    void setModelo(unsigned int newModelo){modelo_ = newModelo;}
    void setCantVentas(unsigned int newCantVentas){cantventas_ = newCantVentas;}
    void setActivado(bool newActivado){activado_ = newActivado;}
    void setVentas(unsigned int** newVentas, unsigned int cantventas);


public:
    Surtidor(short unsigned int codigo, string modelo, short unsigned int cantventas = 0, bool activado = true);
    ~Surtidor();

    short unsigned int getCodigo() {return codigo_;}
    string getModelo() const {return modelo_;}
    short unsigned int getCantVentas() const {return cantventas_;}
    unsigned int** getDatoVentas() const;
    bool getActivado()const {return activado_;}

    void printCodigo() const;
    void printModelo() const;
    void printCantVentas() const;
    void printVentas(int posventa) const;
    void printActivado() const;

    void newVenta(short unsigned int cantventas, short unsigned int Year, short unsigned int Mes, short unsigned int Dia, short unsigned int Hora, short unsigned int Min, short unsigned int CantComb, short unsigned int TipoComb, short unsigned int MetodoPago, unsigned int DocCliente, unsigned int Dinero);
};

#endif // SURTIDOR_H
