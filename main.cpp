#include "ListaDoble.hpp" // Aseg�rate de incluir el archivo de encabezado correctamente
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool condicion(int num) { return (num % 2) == 0; }

int main() {
  // Crear una instancia de la lista
  ListaDoble<int> lista;


  try {

    srand(time(NULL));

    cout << "Metodo de eliminar ocurrencia, eliminar todos los 2" << endl;
    for (int i = 0; i < 7; ++i) {
      int n = 1 + rand() % 10;
      lista.AgregarAlFinal(n);
    }
    cout << "\nLista antes:" << endl;
    lista.Imprimir();
    cout << "*********************************" << endl;
    lista.EliminarRepetidos();
    cout << "*********************************" << endl;
    cout << "Lista despues:" << endl;
    lista.Imprimir();
    cout << "*********************************" << endl;

    /*
    cout << "Intercambiar listas" << endl;
    ListaDoble<int> lista1;
    ListaDoble<int> lista2;
    int x, n;

    for (int i = 0; i < 7; ++i) {
      n = 1 + rand() % 2;
      lista1.AgregarAlFinal(n);
      x = i + rand() % 2;
      lista2.AgregarAlFinal(x);
    }
    cout << "\nLista1:" << endl;
    lista1.Imprimir();
    cout << "*********************************" << endl;
    cout << "\nLista2:" << endl;
    lista2.Imprimir();
    cout << "*********************************" << endl;
    lista1.Intercambiar(lista2);
    cout << "*********************************" << endl;
    cout << "Lista despues de intercambiar:" << endl;
    cout << "\nLista1:" << endl;
    lista1.Imprimir();
    cout << "*********************************" << endl;
    cout << "\nLista2:" << endl;
    lista2.Imprimir();
    cout << "*********************************" << endl;


    // Agregar elementos a la lista
    lista.AgregarAlFinal(10);
    cout << endl;
    lista.Imprimir();
    cout << endl;
    lista.AgregarAlInicio(5);
    cout << endl;
    lista.Imprimir();
    cout << endl;
    lista.AgregarEnPos(15, 1); // Agregar el valor 15 en la posicion 1
    cout << endl;
    lista.Imprimir();
    cout << endl;

    // Imprimir la lista
    cout << "Lista despues de agregar elementos: " << endl;
    lista.Imprimir();
    cout << endl;

    // Modificar un elemento en una posicion especifica
    //lista.ModificarEnPos(1, 8); // Modificar el valor en la posicion 1 por 8
    lista[1] = 5;
    cout << lista[1] << endl;



    // Imprimir la lista despues de la modificacion
    cout << "Lista despues de modificar el elemento en la posici�n 1: ";
    lista.Imprimir();
    cout << endl;

    // Eliminar ocurrencias
    lista.EliminarOcurrencia(5);
    //lista.EliminarDePos(1);
    //lista.EliminarDePos(0);
    cout << "Lista despues de eliminar ocurrencias: ";
    lista.Imprimir();

    lista.AgregarAlFinal(5);
    lista.AgregarAlFinal(5);
    // Eliminar elementos de la lista
    lista.EliminarDelInicio();
    cout << endl;
    lista.Imprimir();
    cout << endl;
    lista.EliminarDelFinal();
    cout << endl;
    lista.Imprimir();
    cout << endl;
    lista.EliminarDePos(0); // Eliminar el elemento en la posicion 0
    cout << endl;
    lista.Imprimir();
    cout << endl;

    // Imprimir la lista despues de eliminar elementos
    cout << "Lista despu�s de eliminar elementos: ";
    lista.Imprimir();
    cout << endl;

    // Verificar si la lista esta vacia
    if (lista.EstaVacia()) {
      cout << "La lista esta vacia." << endl;
    } else {
      cout << "La lista no esta vacia." << endl;
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
