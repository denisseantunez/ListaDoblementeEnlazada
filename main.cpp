#include <iostream>
#include "ListaDoble.hpp" // Aseg�rate de incluir el archivo de encabezado correctamente

//using namespace std;

int main()
{
    // Crear una instancia de la lista
    ListaDoble<int> lista;

    /**try catch*/

    // Agregar elementos a la lista
    lista.AgregarAlFinal(10);
    std::cout << std::endl;
    lista.Imprimir();
    std::cout << std::endl;
    lista.AgregarAlInicio(5);
    std::cout << std::endl;
    lista.Imprimir();
    std::cout << std::endl;
    lista.AgregarEnPos(15, 1); // Agregar el valor 15 en la posici�n 1
    std::cout << std::endl;
    lista.Imprimir();
    std::cout << std::endl;
    std::cout << "En reversa: " << std::endl;
    lista.ImprimirEnReversa();

    // Imprimir la lista
    std::cout << "Lista despu�s de agregar elementos: ";
    lista.Imprimir();
    std::cout << std::endl;

    // Modificar un elemento en una posici�n espec�fica
    lista.ModificarEnPos(1, 8); // Modificar el valor en la posici�n 1 por 8

    // Imprimir la lista despu�s de la modificaci�n
    std::cout << "Lista despu�s de modificar el elemento en la posici�n 1: ";
    lista.Imprimir();
    std::cout << std::endl;

    // Eliminar elementos de la lista
    lista.EliminarDelInicio();
    std::cout << std::endl;
    lista.Imprimir();
    std::cout << std::endl;
    lista.EliminarDelFinal();
    std::cout << std::endl;
    lista.Imprimir();
    std::cout << std::endl;
    lista.EliminarDePos(0); // Eliminar el elemento en la posici�n 0
    std::cout << std::endl;
    lista.Imprimir();
    std::cout << std::endl;

    // Imprimir la lista despu�s de eliminar elementos
    std::cout << "Lista despu�s de eliminar elementos: ";
    lista.Imprimir();
    std::cout << std::endl;

    // Verificar si la lista est� vac�a
    if (lista.EstaVacia()) {
        std::cout << "La lista est� vac�a." << std::endl;
    } else {
        std::cout << "La lista no est� vac�a." << std::endl;
    }

    return 0;
}
