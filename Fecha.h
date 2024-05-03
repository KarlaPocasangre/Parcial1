#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
using namespace std;
// Karla Estefany Hernandez Pocasangre P2C1 15/03/2024

class Fecha
{
private:
    int dia;
    int mes;
    int anio;

public:
    Fecha()
    {
        this->dia = 0;
        this->mes = 0;
        this->anio = 0;
    }
    Fecha(int d, int m, int a)
    {
        this->dia = d;
        this->mes = m;
        this->anio = a;
    }
    void mostrarFecha()
    {
        cout << this->dia << "/";
        cout << this->mes << "/";
        cout << this->anio << "/";
    }
};
#endif // FECHA_H_INCLUDED
