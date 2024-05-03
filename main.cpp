#include <iostream>
#include <stdlib.h>
#include "Cuenta.h"
#include "Cliente.h"
#include "Fecha.h"
#include "Abono.h"
#define TM 5
// Karla Estefany Hernandez Pocasangre P2C1 15/03/2024

using namespace std;

int menu()
{
    int op;
    cout << "MENU\n";
    cout << "1. Agregar cliente a la lista\n";
    cout << "2. Agregar cuenta a la lista.\n";
    cout << "3. Hacer abonos\n";
    cout << "4. Mostrar lista de clientes\n";
    cout << "5. Mostrar lista de cuentas\n";
    cout << "6. Mostrar detalles de la cuenta\n";
    cout << "7. Salir\n";
    cout << "Ingrese una opcion: ";
    cin >> op;
    return op;
}
Cliente *agregarCliente()
{
    Cliente *cli;
    int id;
    string n, a;
    cout << "\nIngrese el id del cliente: ";
    cin >> id;
    cout << "Ingrese el nombre del Cliente: ";
    cin >> n;
    cout << "Ingrese el apellido del cliente: ";
    cin >> a;
    cli = new Cliente(id, n, a);
    return cli;
}
Cliente *buscarCliente(Cliente *lst[], int cont, int id)
{
    bool encontrado = false;
    int contador = 0;
    Cliente *cli = NULL;
    while (contador < cont && !encontrado)
    {
        if (lst[contador]->getIdCliente() == id)
        {
            encontrado = true;
            cli = lst[contador];
        }
        else
        {
            contador++;
        }
    }
    return cli;
}
Cuenta *buscarCuenta(Cuenta *lst[], int cont, int nc)
{
    bool encontrado = false;
    int contador = 0;
    Cuenta *cta = NULL;
    while (contador < cont && !encontrado)
    {
        if (lst[contador]->getNumeroCuenta() == nc)
        {
            encontrado = true;
            cta = lst[contador];
        }
        else
        {
            contador++;
        }
    }
    return cta;
}
Cuenta *agregarCuenta(Cliente *cli)
{
    int nc;
    Cuenta *cta;
    cout << "Ingrese el numero de cuenta: ";
    cin >> nc;
    cta = new Cuenta(nc, cli);
    return cta;
}
void hacerAbono(Cuenta *cta)
{
    int d, m, a;
    Fecha *fa;
    float ma;
    Abono *ab;
    cout << "Ingrese la fecha del abono (dd/mmm/aa): \n";
    cin >> d;
    cin >> m;
    cin >> a;
    cout << "Ingrese el monto del abono: ";
    cin >> ma;
    fa = new Fecha(d, m, a);
    ab = new Abono(fa, ma);
    cta->agregarAbono(ab);
}

void verDetalles(Cuenta *cta)
{
    cout << "Numero de cuenta : " << cta->getNumeroCuenta() << endl;
    cout << "Cliente : " << cta->getCliente()->getNombre() << " " << cta->getCliente()->getApellido() << endl;
    cout << "Saldo : " << cta->getSaldo() << endl;
    if (cta->getContadorAbonos() == 0)
    {
        cout << "No hay Abonos \n";
    }
    else
    {
        cout << "No\tFecha\tMonto\n";
        Abono **lst = cta->getLstAbonos();
        for (int i = 0; i < cta->getContadorAbonos(); i++)
        {
            cout << (i + 1) << "\t";
            lst[i]->getFechaAbono()->mostrarFecha();
            cout << "\t" << lst[i]->getMontoAbono() << endl;
        }
    }
}

int main()
{
    Cliente *lstCliente[TM];
    Cuenta *lstCuenta[TM];
    int contCli = 0, contCta = 0, idCli, idCta, opc;
    Cliente *cli = NULL;
    Cuenta *cta = NULL;
    do
    {
        system("cls");
        opc = menu();
        switch (opc)
        {
        case 1:
            // Agregar clientes
            if (contCli < TM)
            {
                lstCliente[contCli] = agregarCliente();
                contCli++;
                cout << "\nEl Cliente fue agregado exitosamente\n";
            }
            else
            {
                cout << "\nLa lista esta llena\n";
            }
            break;
        case 2:
            // Agregar cuentas
            if (contCta < TM)
            {
                cout << "Ingrese el id del cliente: ";
                cin >> idCli;
                cli = buscarCliente(lstCliente, contCli, idCli);
                if (cli)
                {
                    // El cliente se encontro
                    lstCuenta[contCta] = agregarCuenta(cli);
                    contCta++;
                    cout << "La cuenta se agrego con exito\n";
                }
                else
                {
                    cout << "El cliente no se encontro\n";
                }
            }
            else
            {
                cout << "La lista esta llena\n";
            }
            break;
        case 3:
            // Hacer abonos
            cout << "Ingrese el numero de cuenta: ";
            cin >> idCta;
            cta = buscarCuenta(lstCuenta, contCta, idCta);
            if (cta)
            {
                // La cuenta se encontro
                hacerAbono(cta);
                cout << "El abono se agrego con exito\n";
            }
            else
            {
                cout << "La cuenta no se encontro\n";
            }
            break;
        case 4:
            // Ver lista de clientes
            if (contCli == 0)
                cout << "La lista esta vacia\n";
            else
            {
                cout << "Id\tNombre\tApellido\n";
                for (int i = 0; i < contCli; i++)
                {
                    cout << lstCliente[i]->getIdCliente() << "\t";
                    cout << lstCliente[i]->getNombre() << "\t";
                    cout << lstCliente[i]->getApellido() << "\n";
                }
            }
            break;
        case 5:
            // Ver lista de cuentas
            if (contCta == 0)
            {
                cout << "La lista esta vacia\n";
            }
            else
            {
                cout << "No\tCliente\tSaldo\n";
                for (int i = 0; i < contCta; i++)
                {
                    cout << lstCuenta[i]->getNumeroCuenta() << "\t";
                    cout << lstCuenta[i]->getCliente()->getNombre() << " " << lstCuenta[i]->getCliente()->getApellido() << "\t";
                    cout << lstCuenta[i]->getSaldo() << "\n";
                }
            }
            break;
        case 6:
            // Ver detalles de la cuenta
            cout << "Ingrese el numero de cuenta: ";
            cin >> idCta;
            cta = buscarCuenta(lstCuenta, contCta, idCta);
            if (cta)
            {
                // La cuenta se encontro
                verDetalles(cta);
            }
            else
            {
                cout << "La cuenta no se encontro \n";
            }
            break;
        case 7:
            // Salir
            cout << "Saliendo del programa\n";
            break;
        default:
            cout << "\nError, opcion no esta definida\n";
            break;
        }
        system("pause");
    } while (opc != 7);

    return 0;
}
