#include "ListaDoble.hpp" // Aseg�rate de incluir el archivo de encabezado correctamente
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool condicion(int num) { return (num % 2) == 0; }

int main() {
  srand(time(nullptr));

  try {

    // Transferir elementos de una lista a otra
    ListaDoble<int> lista1;
    ListaDoble<int> lista2;
    int n = 1 + rand() % 9;
    for (int i = 0; i < 10; ++i) {
      lista1.AgregarAlFinal(n);
      lista2.AgregarAlFinal(n);
    }
    cout << "Lista 1: ";
    lista1.Imprimir();
    cout << "Lista 2: ";
    lista2.Imprimir();
    cout << "**********************************" << endl;
    cout << "Eliminar pares" << endl;
    lista1.EliminarPorCondicion(condicion);
    cout << "Lista 1: ";
    lista1.Imprimir();
    lista2.EliminarPorCondicion(condicion);
    cout << "Lista 2: ";
    lista2.Imprimir();
    cout << "**********************************" << endl;
    cout << "Transferir los elementos del 3-6 de la lista 2"
    << " a la lista 1" << endl;
    lista1.Transferir(lista2, 3);
    cout << "Lista 1: ";
    lista1.Imprimir();
    cout << "Lista 2: ";
    lista2.Imprimir();
    cout << "**********************************" << endl;
    cout << "Intercambiar listas" << endl;
    lista1.Intercambiar(lista2);
    cout << "Lista 1: ";
    lista1.Imprimir();
    cout << "Lista 2: ";
    lista2.Imprimir();
    cout << "**********************************" << endl;
    cout << "Eliminar pares" << endl;
    lista1.EliminarPorCondicion(condicion);
    cout << "Lista 1: ";
    lista1.Imprimir();
    lista2.EliminarPorCondicion(condicion);
    cout << "Lista 2: ";
    lista2.Imprimir();
    cout << "**********************************" << endl;
    cout << "Eliminar repetidos" << endl;
    lista1.EliminarRepetidos();
    cout << "Lista 1: ";
    lista1.Imprimir();
    lista2.EliminarRepetidos();
    cout << "Lista 2: ";
    lista2.Imprimir();
  // Ordenar una lista
  /* srand(time(nullptr));
  ListaDoble<int> lista;
  for (int i = 0; i < 7; ++i) {
    int x = 1 + rand() % 9;
    lista.AgregarAlFinal(x);
  }

  cout << "Lista: ";
  lista.Imprimir();
  cout << "Lista ordenada: ";
  lista.Ordenar();
  lista.Imprimir();
  cout << "*******************************" << endl;
  for (int i = 0; i < 7; ++i) {
    lista.EliminarDelInicio();
    cout << "Lista: ";
    lista.Imprimir();
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
