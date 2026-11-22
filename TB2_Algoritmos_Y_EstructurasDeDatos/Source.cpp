#include <iostream>
using namespace std;
#include "Pruebas.h"
#include "Controlador.h"

int main()
{
    //ejecutarPruebas();
    Controlador* controlador = new Controlador();

    controlador->programa();

    delete controlador;
    return 0;
}