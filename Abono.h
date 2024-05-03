#ifndef ABONO_H_INCLUDED
#define ABONO_H_INCLUDED
#include "Fecha.h"
// Karla Estefany Hernandez Pocasangre P2C1 15/03/2024
class Abono
{
private:
    Fecha *fechaAbono;
    float montoAbono;

public:
    Abono()
    {
        this->montoAbono = 0;
    }
    Abono(Fecha *fa, float ma)
    {
        this->fechaAbono = fa;
        this->montoAbono = ma;
    }
    Fecha *getFechaAbono()
    {
        return this->fechaAbono;
    }
    float getMontoAbono()
    {
        return this->montoAbono;
    }
};

#endif // ABONO_H_INCLUDED
