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
    int cantventas_;
    bool activado_;
    int** ventas = new int* [cantventas_];

    void setCodigo(int newCodigo){codigo_ = newCodigo;}
    void setModelo(int newModelo){modelo_ = newModelo;}
    void setCantVentas(int newCantVentas){cantventas_ = newCantVentas;}
    void setActivado(bool newActivado){activado_ = newActivado;}
    void setVentas(int** newVentas, int cantventas);


public:
    Surtidor(int codigo, string modelo, int cantventas = 0, bool activado = true);
    ~Surtidor();

    int getCodigo() {return codigo_;}
    string getModelo() const {return modelo_;}
    int getCantVentas() const {return cantventas_;}
    int** getVentas() const {return ventas;}
    bool getActivado()const {return activado_;}

    void printCodigo() const;
    void printModelo() const;
    void printCantVentas() const;
    void printVentas() const;
    void printActivado() const;

    void newVenta(int cantventas, int Year, int Mes, int Dia, int Hora, int Min, int CantComb, int TipoComb, int MetodoPago, int DocCliente, int Dinero);
};

#endif // SURTIDOR_H
