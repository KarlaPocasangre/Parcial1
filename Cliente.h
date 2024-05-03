#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <string.h>
using namespace std;
// Karla Estefany Hernandez Pocasangre P2C1 15/03/2024

class Cliente
{
private:
    int idCliente;
    string nombre;
    string apellido;

public:
    Cliente()
    {
        this->idCliente = 0;
    }
    Cliente(int id, string n, string a)
    {
        this->idCliente = id;
        this->nombre = n;
        this->apellido = a;
    }
    int getIdCliente()
    {
        return this->idCliente;
    }
    string getNombre()
    {
        return this->nombre;
    }
    string getApellido()
    {
        return this->apellido;
    }
};

#endif // CLIENTE_H_INCLUDED
