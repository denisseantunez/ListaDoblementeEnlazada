#include "ListaDoble.hpp" // Aseg�rate de incluir el archivo de encabezado correctamente
#include <iostream>

using namespace std;

bool condicion(int num) { return (num % 2) == 0; }

int main() {
  // Crear una instancia de la lista
  ListaDoble<int> lista;

  /**try catch*/
  try {
    cout << "Metodo eliminar por condicion, eliminar si el numero es par" << endl;
    for (int i = 0; i < 7; ++i) {
      lista.AgregarAlFinal(i);
    }
    cout << "\nLista antes:" << endl;
    lista.Imprimir();
    cout << "*********************************" << endl;
    lista.EliminarCondicion((condicion));
    cout << "*********************************" << endl;
    cout << "Lista despues:" << endl;
    lista.Imprimir();
    cout << "*********************************" << endl;

    /* // Agregar elementos a la lista
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
    } */
  } catch (ListaDoble<int>::ListaVacia &exc) {
    cerr << "Error: " << exc.what() << endl;
  } catch(ListaDoble<int>::FueraDeRango &exc) {
    cerr << "Error: " << exc.what() << endl;
  } catch (const char* e) {
    cerr << "Error: " << e << endl;
  } catch (...) {
    cerr << "Ocurrio un error inesperado" << endl; // TODO: Poner acentos
  }

  return 0;
}
