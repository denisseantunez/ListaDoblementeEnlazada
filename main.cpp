#include "ListaDoble.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool EsMenor(int x, int y) {
  return x < y;
}

int main() {
  // Crear una instancia de la lista
  ListaDoble<int> lista;


  try {

    srand(time(NULL));

    cout << "Metodo ordenamiento de una lista" << endl;
    for (int i = 0; i < 20; ++i) {
      int n = 1 + rand() % 10;
      lista.AgregarAlFinal(n);
    }
    cout << "\nLista antes:" << endl;
    lista.Imprimir();
    cout << "*********************************" << endl;
    cout << "Lista despues:" << endl;
    lista.Ordenar(EsMenor);
    lista.Imprimir();
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
