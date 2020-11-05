#include <iostream>
#include "arreglo.h"
#include "computadora.h"
using namespace std;

int main()
{
    Arreglo<Computadora> computadoras;

    Computadora c1("Windows","core i7","GTX 1050",16);
    Computadora c2("Linux","Ryzen 5","radeon 9",8);
    Computadora c3("MacOS","core i5","integrados",4);
    Computadora c4("Windows","Ryzen 5","RTX 2060",16);
    Computadora c5("MacOS","Ryzen 5","GTX 1650",8);

    computadoras << c1 << c2 << c3 << c4 << c5;
    Computadora c6("Linux","Ryzen 5","integrados",8);
    Computadora c7("Linux","Ryzen 7","integrados",8);

    cout << "\n*****Uso de buscar() para encontrar una computadora \ncon coincidencias:" << endl<<endl;
    Computadora *ptr = computadoras.buscar(c6);

    if (ptr != nullptr)
    {
        cout << *ptr << endl;
    }
    else
    {
        cout << "No existe" << endl;
    }

    cout << "*****Uso de buscar() para encontrar una computadora \nsin coincidencias:" << endl<<endl;
    ptr = computadoras.buscar(c7);

    if (ptr != nullptr)
    {
        cout << *ptr << endl;
    }
    else
    {
        cout << "No existe" << endl;
    }
    cout << endl;
    
    cout << "****Uso de buscar_todos para guardar e imprimir todas \nlas coincidencias entre computadoras con mismo procesador: "<<endl<<endl;
    Arreglo<Computadora*> ptrs = computadoras.buscar_todos(c6);

    if (ptrs.size() > 0)
    {
         for ( size_t i = 0; i < ptrs.size(); i++)
        {
            Computadora *c =  ptrs[i];
            cout << *c << endl;
        }
    }
    else 
    {
        cout << "No existen coincidencias" << endl;
    }

    return 0;
}