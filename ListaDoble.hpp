#ifndef LISTADOBLE_HPP_INCLUDED
#define LISTADOBLE_HPP_INCLUDED

#include <exception>
#include <iostream>

#define NO_ENCONTRADO (-1)

template <typename T> class ListaDoble {
public:
  ListaDoble();
  ListaDoble(ListaDoble<T> &lista);
  ListaDoble<T> &operator=(const ListaDoble<T> &lista);
  ~ListaDoble();

  void AgregarAlInicio(T valor);
  void AgregarAlFinal(T valor);
  void AgregarEnPos(T valor, int pos);

  void EliminarDelInicio();
  void EliminarDelFinal();
  void EliminarDePos(int pos);
  void EliminarPorCondicion(bool (*condicion)(T valor));
  void EliminarOcurrencia(T valor);
  void EliminarRepetidos();

  bool SeEncuentraValor(T valor) const;
  int BuscarPos(T valor) const;
  bool EstaVacia() const;
  T ObtenerPrimero() const;
  T ObtenerUltimo() const;
  T ObtenerEnPos(int pos) const;


  T & operator[](int pos) ;

  void ModificarEnPos(int pos, T valor);
  void Ordenar(bool (*EsMenor)(T valor1, T valor2));
  void Ordenar();
  void Intercambiar(ListaDoble<T> & lista);
  void IntercambiarElementos(int posElemento1, int posElemento2);
  int ObtenerTam() const;
  void Vaciar();
  void Imprimir() const;
  void ImprimirEnReversa() const;

  class ListaVacia : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class FueraDeRango : public std::exception {
  public:
    virtual const char *what() const throw();
  };

private:
  int tam;

  struct Elemento {
    T valor;
    Elemento *siguiente;
    Elemento *anterior;
    Elemento(T valor, Elemento *sig = nullptr, Elemento *ant = nullptr);
  } *ultimo, *primero;
};

/****************************************************************************************************************/

template <typename T>
ListaDoble<T>::Elemento::Elemento(T valor, Elemento *sig /* = nullptr*/,
                                  Elemento *ant /* = nullptr*/) {
  this->valor = valor;
  this->siguiente = sig;
  this->anterior = ant;
}

/****************************************************************************************************************/

template <typename T> ListaDoble<T>::ListaDoble() {
  primero = nullptr;
  ultimo = nullptr;
  tam = 0;
}

/****************************************************************************************************************/

template <typename T>
ListaDoble<T>::ListaDoble(ListaDoble<T> &lista)
    : tam(0), ultimo(nullptr), primero(nullptr) {
  *this = lista;
}

/****************************************************************************************************************/

template <typename T>
ListaDoble<T> &ListaDoble<T>::operator=(const ListaDoble<T> &lista) {
    if (this == &lista) return *this;
  Vaciar();
  Elemento* porAgregar = lista.primero;
  while (porAgregar != NULL){
    AgregarAlFinal(porAgregar->valor);
    porAgregar = porAgregar->siguiente;
  }
  return *this;
}

/****************************************************************************************************************/

template <typename T> ListaDoble<T>::~ListaDoble() { Vaciar(); }

/****************************************************************************************************************/

template <typename T> void ListaDoble<T>::AgregarAlInicio(T valor) {
  Elemento *nuevo =
      new Elemento(valor, primero, EstaVacia() ? nullptr : primero);
  primero = nuevo;
  ++tam;
}

/****************************************************************************************************************/

template <typename T> void ListaDoble<T>::AgregarAlFinal(T valor) {
  Elemento *nuevo = new Elemento(valor, nullptr, ultimo);
  if (!EstaVacia()) {
    ultimo->siguiente = nuevo;
  } else {
    primero = nuevo;
    primero->anterior = nullptr;
  }
  ultimo = nuevo;
  ++tam;
}

/****************************************************************************************************************/

template <typename T> void ListaDoble<T>::AgregarEnPos(T valor, int pos) {
  if (pos < 0 || pos > tam)
    throw FueraDeRango();
  if (pos == 0)
    AgregarAlInicio(valor);
  else if (pos == tam)
    AgregarAlFinal(valor);
  else {
    Elemento *ant = primero;
    // Buscar la pos para agregar en ese lugar el elemento
    for (int i = 1; i < pos; ++i)
      ant = ant->siguiente;
    Elemento *nuevo = new Elemento(valor, ant->siguiente, ant);
    ant -> siguiente -> anterior = nuevo;
    ant -> siguiente = nuevo;
    ++tam;
  }
}

/****************************************************************************************************************/

template <typename T> void ListaDoble<T>::EliminarDelInicio() {
  if (EstaVacia())
    throw ListaVacia();
  Elemento *porBorrar = primero;
  primero = primero->siguiente;

  if(primero == nullptr) ultimo = nullptr;
  else primero -> anterior = nullptr;

  delete porBorrar;
  --tam;
}

/****************************************************************************************************************/

template <typename T> void ListaDoble<T>::EliminarDelFinal() {
  if (EstaVacia())
    throw ListaVacia();
  Elemento *porBorrar = ultimo;
  ultimo = ultimo->anterior;
  if (tam == 1) {
    primero = nullptr;
    ultimo = nullptr;
  }else{
    ultimo->siguiente = nullptr;
  }
  delete porBorrar;
  --tam;
}

/****************************************************************************************************************/

template <typename T> void ListaDoble<T>::EliminarDePos(int pos) {
  if (pos < 0 || pos >= tam)
    throw FueraDeRango();
  if (pos == 0)
    EliminarDelInicio();
  else if (pos == tam - 1)
    EliminarDelFinal();
  else {
    Elemento *porBorrar = primero;
    // Buscar la pos
    for (int i = 0; i < pos; ++i)
      porBorrar = porBorrar->siguiente;
    porBorrar->anterior->siguiente = porBorrar->siguiente;
    porBorrar->siguiente->anterior = porBorrar->anterior;
    delete porBorrar;
    --tam;
  }
}

/****************************************************************************************************************/

template <typename T> void ListaDoble<T>::EliminarOcurrencia(T valor) {

  if(EstaVacia()) throw ListaVacia();

  Elemento *aux = primero;
  Elemento *auxSig = aux -> siguiente;
  int pos = 0;

  while(aux != nullptr) {
    if (aux->valor == valor) {
      aux = aux->siguiente;
      EliminarDePos(pos);
    }
    else {
      pos++;
      aux = aux->siguiente;
    }
    aux = auxSig;
    if (auxSig != nullptr) auxSig = auxSig->siguiente;
  }
}

/****************************************************************************************************************/

template <typename T> void ListaDoble<T>::EliminarRepetidos() {

  if(EstaVacia()) throw ListaVacia();

  ListaDoble<T> ListaSinRep;
  Elemento * actual = primero;

  for(int i = 0; i < tam; ++i){
    if(!ListaSinRep.SeEncuentraValor(actual -> valor)) ListaSinRep.AgregarAlFinal(actual -> valor);
    actual = actual -> siguiente;
  }
  *this = ListaSinRep;

}

/****************************************************************************************************************/

template <typename T> bool ListaDoble<T>::SeEncuentraValor(T valor) const {
  Elemento *actual = primero;
  for (int i = 0; i < tam; ++i) {
    if (actual->valor == valor)
      return true;
    actual = actual->siguiente;
  }
  return false;
}

/****************************************************************************************************************/

template <typename T> int ListaDoble<T>::BuscarPos(T valor) const {
  Elemento *actual = primero;
  int pos;
  for (pos = 0; actual != nullptr && actual->valor != valor; ++pos)
    actual = actual->siguiente;
  if (actual != nullptr)
    return pos;
  else
    return NO_ENCONTRADO;
}

/****************************************************************************************************************/

template <typename T> bool ListaDoble<T>::EstaVacia() const { return tam == 0; }

/****************************************************************************************************************/

template <typename T> T ListaDoble<T>::ObtenerPrimero() const {
  if (EstaVacia())
    throw ListaVacia();
  return primero->valor;
}

/****************************************************************************************************************/

template <typename T> T ListaDoble<T>::ObtenerUltimo() const {
  if (EstaVacia())
    throw ListaVacia();
  return ultimo->valor;
}

/****************************************************************************************************************/

// Para obtener
template <typename T> T & ListaDoble<T>::operator[](int pos) {
  if (EstaVacia())
    throw ListaVacia();

  Elemento *actual = primero;
  for (int i = 0; i < pos; ++i)
    actual = actual->siguiente;
  return actual->valor;
}

/****************************************************************************************************************/

template <typename T> T ListaDoble<T>::ObtenerEnPos(int pos) const {
  if (EstaVacia())
    throw ListaVacia();

  Elemento *actual = primero;
  for (int i = 0; i < pos; ++i)
    actual = actual->siguiente;
  return actual->valor;
}

/****************************************************************************************************************/

template <typename T> void ListaDoble<T>::ModificarEnPos(int pos, T valor) {
  if (EstaVacia())
    throw ListaVacia();
  Elemento *ant = primero;
  for (int i = 1; i < pos; ++i)
    ant = ant->siguiente;
  ant->siguiente->valor = valor;
}

/****************************************************************************************************************/

template <typename T> void ListaDoble<T>::Intercambiar(ListaDoble<T> & lista) {
  ListaDoble<T> aux;

  aux = lista;
  lista = *this;
  *this = aux;
}


/****************************************************************************************************************/

template <typename T> int ListaDoble<T>::ObtenerTam() const { return tam; }

/****************************************************************************************************************/

template <typename T> void ListaDoble<T>::Vaciar() {
  while (!EstaVacia()) {
    EliminarDelInicio();
  }
}

/****************************************************************************************************************/

template <typename T> void ListaDoble<T>::Imprimir() const {
  if (EstaVacia())
    std::cout << "( )" << std::endl;
  else {
    std::cout << "( ";
    Elemento *actual = primero;
    while (actual != nullptr) {
      std::cout << actual->valor << ", ";
      actual = actual->siguiente;
    }
    std::cout << "\b\b )" << std::endl;
  }
}

/****************************************************************************************************************/

template <typename T>
void ListaDoble<T>::ImprimirEnReversa() const
{
  if(EstaVacia()) std::cout <<"( )" << std::endl;
  else{
    std::cout << "( ";
    Elemento *actual = ultimo;
    for(int i = 0; i < tam; ++i){
         std::cout << actual -> valor << ", ";
         actual = actual -> anterior;
    }
     std::cout << "\b\b  )";
  }
}

/****************************************************************************************************************/

template <typename T>
const char *ListaDoble<T>::ListaVacia::what() const throw() {
  return "Se intento modificar una lista vacia..."; // TODO: Poner acento
}

/****************************************************************************************************************/

template <typename T>
const char *ListaDoble<T>::FueraDeRango::what() const throw() {
  return "El indice de posicion se encuentra fuera de rango..."; // TODO: Poner
                                                                 // acento
}

/****************************************************************************************************************/

template <typename T>
void ListaDoble<T>::EliminarPorCondicion(bool (*condicion)(T valor)) {
  if (EstaVacia())
    throw ListaVacia();
  else {
    Elemento *aux = primero;
    int pos = 0;
    while (aux != nullptr) {
      if (condicion(aux->valor)) {
        aux = aux->siguiente;
        EliminarDePos(pos);
      } else {
        ++pos;
        aux = aux->siguiente;
      }
    }
  }
}

/****************************************************************************************************************/

template <typename T>
void ListaDoble<T>::Ordenar(bool (*EsMenor)(T valor1, T valor2)) {
  if (EstaVacia()) throw ListaVacia();
  int min;
  for (int i = 0; i < tam-1; ++i) {
    min = i;
    for (int j = i+1; j < tam; ++j) {
      // TODO: Ver si lo puedo hacer con el operador []
      T elemento_j = ObtenerEnPos(j); 
      T elemento_min = ObtenerEnPos(min);
      if (EsMenor(elemento_j, elemento_min))
        min = j;
    }
    IntercambiarElementos(i, min);
  }
}

/****************************************************************************************************************/

template <typename T>
void ListaDoble<T>::Ordenar() {
  if (EstaVacia()) throw ListaVacia();
  int min;
  for (int i = 0; i < tam-1; ++i) {
    min = i;
    for (int j = i+1; j < tam; ++j) {
      // TODO: Ver si lo puedo hacer con el operador []
      T elemento_j = ObtenerEnPos(j); 
      T elemento_min = ObtenerEnPos(min);
      if (elemento_j < elemento_min)
        min = j;
    }
    IntercambiarElementos(i, min);
  }
}

/****************************************************************************************************************/

template <typename T>
void ListaDoble<T>::IntercambiarElementos(int posElemento1, int posElemento2) {
  if (posElemento1 < 0 || posElemento1 >= tam) throw FueraDeRango();
  else if (posElemento2 < 0 || posElemento2 >= tam) throw FueraDeRango();
  else if (posElemento1 != posElemento2) {
    T aux = ObtenerEnPos(posElemento1);
    // TODO: Ver si lo puedo hacer con el operador []
    ModificarEnPos(posElemento1, ObtenerEnPos(posElemento2));
    ModificarEnPos(posElemento2, aux);
  }
}

#endif // LISTADOBLE_HPP_INCLUDED
