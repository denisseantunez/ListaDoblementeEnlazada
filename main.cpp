#include <iostream>
#include "ListaDoble.hpp" // Asegúrate de incluir el archivo de encabezado correctamente

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
    lista.AgregarEnPos(15, 1); // Agregar el valor 15 en la posición 1
    std::cout << std::endl;
    lista.Imprimir();
    std::cout << std::endl;
    std::cout << "En reversa: " << std::endl;
    lista.ImprimirEnReversa();

    // Imprimir la lista
    std::cout << "Lista después de agregar elementos: ";
    lista.Imprimir();
    std::cout << std::endl;

    // Modificar un elemento en una posición específica
    lista.ModificarEnPos(1, 8); // Modificar el valor en la posición 1 por 8

    // Imprimir la lista después de la modificación
    std::cout << "Lista después de modificar el elemento en la posición 1: ";
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
    lista.EliminarDePos(0); // Eliminar el elemento en la posición 0
    std::cout << std::endl;
    lista.Imprimir();
    std::cout << std::endl;

    // Imprimir la lista después de eliminar elementos
    std::cout << "Lista después de eliminar elementos: ";
    lista.Imprimir();
    std::cout << std::endl;

    // Verificar si la lista está vacía
    if (lista.EstaVacia()) {
        std::cout << "La lista está vacía." << std::endl;
    } else {
        std::cout << "La lista no está vacía." << std::endl;
    }

    return 0;
}
