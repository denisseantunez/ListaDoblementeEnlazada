#ifndef LISTADOBLE_HPP_INCLUDED
#define LISTADOBLE_HPP_INCLUDED

#include <exception>
#include <iostream>

#define NO_ENCONTRADO (-1)

/**
 * @class ListaDoble
 * @brief Implementa una lista doblemente enlazada genérica.
 *
 * Esta clase permite realizar operaciones básicas como inserción, eliminación y búsqueda
 * de elementos, manteniendo un enlace doble entre nodos para permitir la navegación en ambas direcciones.
 *
 * @tparam T Tipo de datos de los elementos de la lista.
 */
template<typename T>
class ListaDoble {
private:
  struct Elemento {
    T valor; ///< Valor del elemento.
    Elemento *siguiente; ///< Puntero al siguiente elemento en la lista.
    Elemento *anterior; ///< Puntero al elemento anterior en la lista.
    
    /**
     * @brief Constructor del Elemento.
     * @param valor Valor del nuevo elemento.
     * @param sig Puntero al siguiente elemento en la lista.
     * @param ant Puntero al elemento anterior en la lista.
     */
    Elemento(T valor, Elemento *sig = nullptr, Elemento *ant = nullptr)
        : valor(valor), siguiente(sig), anterior(ant) {}
  };
  
  Elemento *ultimo; ///< Puntero al último elemento de la lista.
  Elemento *primero; ///< Puntero al primer elemento de la lista.
  int tam; ///< Tamaño actual de la lista.
  
  /**
   * @brief Elimina un elemento de la lista.
   * @param porBorrar Puntero al elemento a eliminar.
   */
  void EliminarPorPuntero(Elemento* porBorrar);

public:
  /**
   * @brief Constructor por default
   */
  ListaDoble();
  
  /**
   * @brief Constructor de copias
   */
  ListaDoble(const ListaDoble<T>& lista);
  
  /**
   * @brief Sobrecarga del operador de asigación
   * @param ListaDoble de un tipo de dato por referencia
   * @return ListaDoble por referencia
   */
  ListaDoble<T>& operator=(const ListaDoble<T>& lista);
  
  /**
   * @brief Destructor
   */
  ~ListaDoble();
  
  /**
   * @brief Agrega un elemento al inicio de la lista.
   * @param valor Valor del elemento a agregar.
   */
  void AgregarAlInicio(T valor);
  
  /**
   * @brief Agrega un elemento al final de la lista.
   * @param valor Valor del elemento a agregar.
   */
  void AgregarAlFinal(T valor);
  
  /**
   * @brief Inserta un elemento en una posición específica de la lista.
   * @param valor Valor del elemento a insertar.
   * @param pos Posición en la que se insertará el elemento.
   */
  void AgregarEnPos(T valor, int pos);
  
  /**
   * @brief Elimina el primer elemento de la lista
   */
  void EliminarDelInicio();
  
  /**
   * @brief Elimina el ultimo elemento de la lista
   */
  void EliminarDelFinal();
  
  /**
   * @brief Elimina un elemento de una posición específica.
   * @param pos Posición del elemento a eliminar.
   */
  void EliminarDePos(int pos);
  
  /**
   * @brief Elimina elementos que cumplan una condición específica.
   * @param condicion Función que determina si un elemento debe ser eliminado.
   */
  void EliminarPorCondicion(bool (*condicion)(T valor));
  
  /**
   * @brief Elimina todas las ocurrencias de la lista del valor recibido
   * @param valor del que se quieren eliminar las ocurrencias
   */
  void EliminarOcurrencia(T valor);
  
  /**
   * @brief Elimina elementos repetidos de la lista
   */
  void EliminarRepetidos();
  
  /**
   * @brief Buscar si existe un valor en la lista
   * @param Valor a buscar en la lista
   */
  bool SeEncuentraValor(T valor) const;
  /**
   * @brief Buscar el indice en la lista de un valor, si hay varios, regresa el primer indice de la lista
   * @param Indice del valor en la lista
   */
  int BuscarPos(T valor) const;
  
  /**
   * @brief Comprueba si la lista está vacía.
   * @return True si la lista está vacía, False en caso contrario.
   */
  bool EstaVacia() const;
  
  /**
   * @brief Obtiene el valor del primero elemento de la lista
   * @return Tipo de dato de la plantilla
   */
  T ObtenerPrimero() const;
  
  /**
   * @brief Obtiene el valor del ultimo elemento de la lista
   * @return Tipo de dato de la plantilla
   */
  T ObtenerUltimo() const; ///< Obtiene el valor del último elemento.
  
  /**
   * @brief Obtiene el valor de un elemento en una posición específica.
   * @param pos Posición del elemento.
   * @return Valor del elemento en la posición dada.
   */
  T ObtenerEnPos(int pos) const;
  
  /**
   * @brief Acceso de solo lectura a un elemento por su posicion
   */
  const T& operator[](int pos) const;
  /**
   * @brief Acceso de escritura a un elemento por su posicion
   */
  T& operator[](int pos);
  
  /**
   * @brief Modifica el valor de un elemento en una posición específica.
   * @param pos Posición del elemento a modificar.
   * @param valor Nuevo valor para el elemento.
   */
  void ModificarEnPos(int pos, T valor);
  
  /**
   * @brief Ordena los elementos de la lista utilizando el algoritmo de ordenamiento por inserción.
   */
  void Ordenar();
  
  /**
   * @brief Intercambia el contenido de esta lista con otra lista.
   * @param lista Lista con la que se intercambiará el contenido.
   */
  void Intercambiar(ListaDoble<T>& lista);
  
  /**
   * @brief Transfiere todos los elementos de esta lista a otra lista, dejando esta lista vacía.
   * @param lista Lista destino donde se transferirán los elementos.
   */
  void Transferir(ListaDoble<T>& lista);
  
  /**
   * @brief Transfiere los elementos de una subsección de esta lista a otra lista.
   * @param lista Lista destino donde se transferirán los elementos.
   * @param posInicial Posición inicial de la subsección a transferir.
   */
  void Transferir(ListaDoble<T>& lista, int posInicial);
  
  /**
   * @brief Transfiere los elementos dentro de un rango de posiciones de esta lista a otra lista.
   * @param lista Lista destino donde se transferirán los elementos.
   * @param posInicial Posición inicial del rango a transferir.
   * @param posFinal Posición final del rango a transferir.
   */
  void Transferir(ListaDoble<T>& lista, int posInicial, int posFinal);
  
  /**
   * @brief Obtiene el tamaño actual de la lista.
   * @return Número de elementos en la lista.
   */
  int ObtenerTam() const;
  
  /**
   * @brief Vacía la lista, eliminando todos sus elementos.
   */
  void Vaciar();
  
  /**
   * @brief Imprime los elementos de la lista en orden.
   */
  void Imprimir() const;
  
  /**
   * @brief Imprime los elementos de la lista en orden inverso.
   */
  void ImprimirEnReversa() const;
  
  /**
   * @class ListaVacia
   * @brief Excepción lanzada al realizar operaciones inválidas en una lista vacía.
   */
  class ListaVacia : public std::exception {
  public:
    /**
     * @brief Proporciona el mensaje de la excepción.
     * @return Mensaje explicativo de la excepción.
     */
    virtual const char* what() const throw() override {
      return "La operación no puede completarse: la lista está vacía.";
    }
  };
  
  /**
   * @class FueraDeRango
   * @brief Excepción lanzada al intentar acceder a posiciones fuera del rango válido.
   */
  class FueraDeRango : public std::exception {
  public:
    /**
     * @brief Proporciona el mensaje de la excepción.
     * @return Mensaje explicativo de la excepción.
     */
    virtual const char* what() const throw() override {
      return "La posición especificada está fuera del rango de la lista.";
    }
  };
};

/****************************************************************************************************************/

template<typename T>
ListaDoble<T>::Elemento::Elemento(T valor, Elemento *sig /* = nullptr*/,
                                  Elemento *ant /* = nullptr*/) {
  this->valor = valor;
  this->siguiente = sig;
  this->anterior = ant;
}

/****************************************************************************************************************/

template<typename T>
ListaDoble<T>::ListaDoble() {
  primero = nullptr;
  ultimo = nullptr;
  tam = 0;
}

/****************************************************************************************************************/

template<typename T>
ListaDoble<T>::ListaDoble(ListaDoble<T> &lista)
    : tam(0), ultimo(nullptr), primero(nullptr) {
  *this = lista;
}

/****************************************************************************************************************/

template<typename T>
ListaDoble<T> &ListaDoble<T>::operator=(const ListaDoble<T> &lista) {
  if (this == &lista) return *this;
  Vaciar();
  Elemento *porAgregar = lista.primero;
  while (porAgregar != NULL) {
    AgregarAlFinal(porAgregar->valor);
    porAgregar = porAgregar->siguiente;
  }
  return *this;
}

/****************************************************************************************************************/

template<typename T>
ListaDoble<T>::~ListaDoble() { Vaciar(); }

/****************************************************************************************************************/

template<typename T>
void ListaDoble<T>::AgregarAlInicio(T valor) {
  Elemento *nuevo =
      new Elemento(valor, primero, EstaVacia() ? nullptr : primero);
  primero = nuevo;
  ++tam;
}

/****************************************************************************************************************/

template<typename T>
void ListaDoble<T>::AgregarAlFinal(T valor) {
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

template<typename T>
void ListaDoble<T>::AgregarEnPos(T valor, int pos) {
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
    ant->siguiente->anterior = nuevo;
    ant->siguiente = nuevo;
    ++tam;
  }
}

/****************************************************************************************************************/

template<typename T>
void ListaDoble<T>::EliminarDelInicio() {
  if (EstaVacia())
    throw ListaVacia();
  Elemento *porBorrar = primero;
  primero = primero->siguiente;
  
  if (primero == nullptr) ultimo = nullptr;
  else primero->anterior = nullptr;
  
  delete porBorrar;
  --tam;
}

/****************************************************************************************************************/

template<typename T>
void ListaDoble<T>::EliminarDelFinal() {
  if (EstaVacia())
    throw ListaVacia();
  Elemento *porBorrar = ultimo;
  ultimo = ultimo->anterior;
  if (tam == 1) {
    primero = nullptr;
    ultimo = nullptr;
  } else {
    ultimo->siguiente = nullptr;
  }
  delete porBorrar;
  --tam;
}

/****************************************************************************************************************/

template<typename T>
void ListaDoble<T>::EliminarDePos(int pos) {
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

template<typename T>
void ListaDoble<T>::EliminarPorPuntero(Elemento *porBorrar) {
  if (porBorrar == primero)
    EliminarDelInicio();
  else if (porBorrar == ultimo)
    EliminarDelFinal();
  else {
    porBorrar->anterior->siguiente = porBorrar->siguiente;
    porBorrar->siguiente->anterior = porBorrar->anterior;
    delete porBorrar;
    --tam;
  }
}

/****************************************************************************************************************/

template<typename T>
void ListaDoble<T>::EliminarOcurrencia(T valor) {
  
  if (EstaVacia()) throw ListaVacia();
  
  Elemento *aux = primero;
  Elemento *auxSig = aux->siguiente;
  int pos = 0;
  
  while (aux != nullptr) {
    if (aux->valor == valor) {
      aux = aux->siguiente;
      EliminarDePos(pos);
    } else {
      pos++;
      aux = aux->siguiente;
    }
    aux = auxSig;
    if (auxSig != nullptr) auxSig = auxSig->siguiente;
  }
}

/****************************************************************************************************************/

template<typename T>
void ListaDoble<T>::EliminarRepetidos() {
  
  if (EstaVacia()) throw ListaVacia();
  
  ListaDoble<T> ListaSinRep;
  Elemento *actual = primero;
  
  for (int i = 0; i < tam; ++i) {
    if (!ListaSinRep.SeEncuentraValor(actual->valor)) ListaSinRep.AgregarAlFinal(actual->valor);
    actual = actual->siguiente;
  }
  *this = ListaSinRep;
  
}

/****************************************************************************************************************/

template<typename T>
bool ListaDoble<T>::SeEncuentraValor(T valor) const {
  Elemento *actual = primero;
  for (int i = 0; i < tam; ++i) {
    if (actual->valor == valor)
      return true;
    actual = actual->siguiente;
  }
  return false;
}

/****************************************************************************************************************/

template<typename T>
int ListaDoble<T>::BuscarPos(T valor) const {
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

template<typename T>
bool ListaDoble<T>::EstaVacia() const { return tam == 0; }

/****************************************************************************************************************/

template<typename T>
T ListaDoble<T>::ObtenerPrimero() const {
  if (EstaVacia())
    throw ListaVacia();
  return primero->valor;
}

/****************************************************************************************************************/

template<typename T>
T ListaDoble<T>::ObtenerUltimo() const {
  if (EstaVacia())
    throw ListaVacia();
  return ultimo->valor;
}

/****************************************************************************************************************/

// Para izquierda
template<typename T>
T &ListaDoble<T>::operator[](int pos) {
  
  if (pos < 0 || pos >= tam) throw FueraDeRango();
  
  Elemento *actual = primero;
  for (int i = 0; i < pos; ++i)
    actual = actual->siguiente;
  return actual->valor;
}

/****************************************************************************************************************/

// Para derecha
template<typename T>
const T &ListaDoble<T>::operator[](int pos) const {
  
  if (pos < 0 || pos >= tam) throw FueraDeRango();
  
  Elemento *actual = primero;
  for (int i = 0; i < pos; ++i)
    actual = actual->siguiente;
  return actual->valor;
}

/****************************************************************************************************************/

template<typename T>
T ListaDoble<T>::ObtenerEnPos(int pos) const {
  if (EstaVacia())
    throw ListaVacia();
  
  Elemento *actual = primero;
  for (int i = 0; i < pos; ++i)
    actual = actual->siguiente;
  return actual->valor;
}

/****************************************************************************************************************/

template<typename T>
void ListaDoble<T>::ModificarEnPos(int pos, T valor) {
  if (EstaVacia())
    throw ListaVacia();
  Elemento *ant = primero;
  for (int i = 1; i < pos; ++i)
    ant = ant->siguiente;
  ant->siguiente->valor = valor;
}

/****************************************************************************************************************/



/****************************************************************************************************************/

template<typename T>
void ListaDoble<T>::Intercambiar(ListaDoble<T> &lista) {
  Elemento* auxPrimero = primero;
  Elemento* auxUltimo = ultimo;
  int auxTam = tam;
  
  primero = lista.primero;
  ultimo = lista.ultimo;
  tam = lista.tam;
  lista.primero = auxPrimero;
  lista.ultimo = auxUltimo;
  lista.tam = auxTam;
}

/****************************************************************************************************************/

template<typename T>
void ListaDoble<T>::Transferir(ListaDoble<T> &lista) {
  if (!lista.EstaVacia()){
    Transferir(lista, 0, lista.ObtenerTam() - 1);
    lista.primero = lista.ultimo = nullptr;
  }
}

/****************************************************************************************************************/

template<typename T>
void ListaDoble<T>::Transferir(ListaDoble<T> &lista, int posInicial) {
  if (!lista.EstaVacia()) {
    if (posInicial >= tam) throw FueraDeRango();
    Transferir(lista, posInicial, lista.ObtenerTam() - 1);
  }
}

/****************************************************************************************************************/

template<typename T>
void ListaDoble<T>::Transferir(ListaDoble<T> &lista, int posInicial, int posFinal) {
  if (!lista.EstaVacia()) {
    if (posInicial < 0 || posFinal >= tam) throw FueraDeRango();
    Elemento *pI = lista.primero;
    for (int i = 0; i < posInicial; ++i) pI = pI->siguiente;
    Elemento *pF = pI;
    for (int i = 0; i < posFinal - posInicial; ++i) pF = pF->siguiente;
    (pI != lista.primero ? pI->anterior->siguiente : lista.primero) = pF->siguiente;
    (pF != lista.ultimo ? pF->siguiente->anterior : lista.ultimo) = pI->anterior;
    ultimo->siguiente = pI;
    pI->anterior = ultimo;
    lista.tam -= posFinal - posInicial + 1;
    ultimo = pF;
    pF->siguiente = nullptr;
  }
}

/****************************************************************************************************************/

template<typename T>
int ListaDoble<T>::ObtenerTam() const { return tam; }

/****************************************************************************************************************/

template<typename T>
void ListaDoble<T>::Vaciar() {
  while (!EstaVacia()) {
    EliminarDelFinal();
  }
}

/****************************************************************************************************************/

template<typename T>
void ListaDoble<T>::Imprimir() const {
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

template<typename T>
void ListaDoble<T>::ImprimirEnReversa() const {
  if (EstaVacia()) std::cout << "( )" << std::endl;
  else {
    std::cout << "( ";
    Elemento *actual = ultimo;
    for (int i = 0; i < tam; ++i) {
      std::cout << actual->valor << ", ";
      actual = actual->anterior;
    }
    std::cout << "\b\b  )";
  }
}

/****************************************************************************************************************/

template<typename T>
const char *ListaDoble<T>::ListaVacia::what() const throw() {
  return "Se intent\242 modificar una lista vac\241a...";
}

/****************************************************************************************************************/

template<typename T>
const char *ListaDoble<T>::FueraDeRango::what() const throw() {
  return "El \241ndice de posici\242n se encuentra fuera de rango...";
}

/****************************************************************************************************************/

template<typename T>
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

template<typename T>
void ListaDoble<T>::Ordenar() {
  if (!EstaVacia()) {
    Elemento *actual = primero->siguiente;
    while (actual != nullptr) {
      while (actual->anterior != nullptr && actual->anterior->valor > actual->valor) {
        Elemento *anteriorTemp = actual->anterior;
        actual->anterior = anteriorTemp->anterior;
        if (anteriorTemp->anterior != nullptr) {
          anteriorTemp->anterior->siguiente = actual;
        } else {
          primero = actual;
        }
        anteriorTemp->siguiente = actual->siguiente;
        if (actual->siguiente != nullptr) {
          actual->siguiente->anterior = anteriorTemp;
        } else {
          ultimo = anteriorTemp;
        }
        actual->siguiente = anteriorTemp;
        anteriorTemp->anterior = actual;
      }
      actual = actual->siguiente;
    }
  }
}

#endif // LISTADOBLE_HPP_INCLUDED
