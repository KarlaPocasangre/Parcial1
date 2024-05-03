#ifndef CUENTA_H_INCLUDED
#define CUENTA_H_INCLUDED
#include "Abono.h"
#include "Cliente.h"
#define DA 5
// Karla Estefany Hernandez Pocasangre P2C1 15/03/2024

class Cuenta
{
private:
    int numeroCuenta;
    Cliente *cliente;
    Abono *lstAbonos[DA];
    float saldo;
    int contadorAbonos;

public:
    Cuenta()
    {
        this->numeroCuenta = 0;
        this->saldo = 0;
        this->contadorAbonos = 0;
    }
    Cuenta(int nc, Cliente *cli)
    {
        this->numeroCuenta = nc;
        this->cliente = cli;
        this->saldo = 0;
        this->contadorAbonos = 0;
    }
    int getNumeroCuenta()
    {
        return this->numeroCuenta;
    }
    void setNumeroCuenta(int nc)
    {
        this->numeroCuenta = nc;
    }
    Cliente *getCliente()
    {
        return this->cliente;
    }
    void setCliente(Cliente *cli)
    {
        this->cliente = cli;
    }
    bool agregarAbono(Abono *ab)
    {
        bool retorno = false;
        if (this->contadorAbonos < DA)
        {
            this->lstAbonos[this->contadorAbonos] = ab;
            this->contadorAbonos++;
            this->saldo += ab->getMontoAbono();
            retorno = true;
        }
        return retorno;
    }
    Abono **getLstAbonos()
    {
        return this->lstAbonos;
    }
    float getSaldo()
    {
        return this->saldo;
    }
    int getContadorAbonos()
    {
        return this->contadorAbonos;
    }
};
#endif // CUENTA_H_INCLUDED
