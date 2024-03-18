/****************************************************************************************************************/

template <typename T>
ListaDoble<T>::Elemento::Elemento(T valor, Elemento *sig /* = nullptr*/, Elemento *ant /* = nullptr*/)
{
    this -> valor = valor;
    this -> siguiente = sig;
    this -> anterior = ant;
}

/****************************************************************************************************************/

template <typename T>
ListaDoble<T>::ListaDoble()
{
    primero = nullptr;
    ultimo = nullptr;
    tam = 0;
}

/****************************************************************************************************************/

template <typename T>
ListaDoble<T>::ListaDoble(ListaDoble<T> &lista) : tam(0), ultimo(nullptr), primero(nullptr)
{
    *this = lista;
}

/****************************************************************************************************************/

template <typename T>
ListaDoble<T> & ListaDoble<T>::operator=(const ListaDoble<T>& lista)
{
    if(this == &lista) return *this;



}

/****************************************************************************************************************/

template <typename T>
ListaDoble<T>::~ListaDoble()
{
    Vaciar();
}

/****************************************************************************************************************/

template <typename T>
void ListaDoble<T>::AgregarAlInicio(T valor)
{
    Elemento *nuevo = new Elemento(valor, primero, EstaVacia() ? nullptr : primero);
    primero = nuevo;
    ++tam;
}

/****************************************************************************************************************/


template <typename T>
void ListaDoble<T>::AgregarAlFinal(T valor)
{
    Elemento *nuevo = new Elemento(valor, nullptr, ultimo);
    if(!EstaVacia()){
        ultimo -> siguiente = nuevo;
    }else{
        primero = nuevo;
        primero -> anterior = nullptr;
    }
    ultimo = nuevo;
    ++tam;
}

/****************************************************************************************************************/

template <typename T>
void ListaDoble<T>::AgregarEnPos(T valor, int pos)
{
    if(pos < 0 || pos > tam) throw FueraDeRango();
    if(pos == 0) AgregarAlInicio(valor);
    else if(pos == tam) AgregarAlFinal(valor);
    else{
        Elemento *ant = primero;
        //Buscar la pos para agregar en ese lugar el elemento
        for(int i = 1; i < pos; ++i) ant = ant -> siguiente;
        Elemento *nuevo = new Elemento(valor, ant -> siguiente, ant);
        ant -> siguiente = nuevo;
        ++tam;
    }
}

/****************************************************************************************************************/

template <typename T>
void ListaDoble<T>::EliminarDelInicio()
{
    if(EstaVacia()) throw EstaVacia();
    Elemento *porBorrar = primero;
    primero = primero -> siguiente;
    delete porBorrar;
    --tam;
}

/****************************************************************************************************************/


template <typename T>
void ListaDoble<T>::EliminarDelFinal()
{
    if(EstaVacia()) throw EstaVacia();
    Elemento *porBorrar = ultimo;
    ultimo = ultimo -> anterior;
    if(tam == 1){
        ultimo -> siguiente = nullptr;
    }
    delete porBorrar;
    --tam;
}

/****************************************************************************************************************/

template <typename T>
void ListaDoble<T>::EliminarDePos(int pos)
{
    if(pos < 0 || pos >= tam) throw FueraDeRango();
    if(pos == 0) EliminarDelInicio();
    else if(pos == tam - 1) EliminarDelFinal();
    else{
        Elemento *porBorrar = primero;
        //Buscar la pos
        for(int i = 0; i < pos; ++i) porBorrar = porBorrar -> siguiente;
        porBorrar -> anterior -> siguiente = porBorrar -> siguiente;
        porBorrar -> siguiente -> anterior = porBorrar -> anterior;
        delete porBorrar;
        --tam;
    }
}

/****************************************************************************************************************/

template <typename T>
bool ListaDoble<T>::SeEncuentraValor(T valor) const
{
    Elemento *actual = primero;
    for(int i = 0; i < tam; ++i){
        if(actual -> valor == valor) return true;
        actual = actual -> siguiente;
    }
    return false;
}

/****************************************************************************************************************/

template <typename T>
int ListaDoble<T>::BuscarPos(T valor) const
{
    Elemento *actual = primero;
    int pos;
    for(pos = 0; actual != nullptr && actual -> valor != valor; ++pos)
    actual = actual -> siguiente;
    if(actual != nullptr) return pos;
    else return NO_ENCONTRADO;
}

/****************************************************************************************************************/

template <typename T>
bool ListaDoble<T>::EstaVacia() const
{
    return tam == 0;
}

/****************************************************************************************************************/

template <typename T>
T ListaDoble<T>::ObtenerPrimero() const
{
    if(EstaVacia()) throw ListaVacia();
    return primero -> valor;
}

/****************************************************************************************************************/

template <typename T>
T ListaDoble<T>::ObtenerUltimo() const
{
    if(EstaVacia()) throw ListaVacia();
    return ultimo -> valor;
}

/****************************************************************************************************************/

template <typename T>
T ListaDoble<T>::ObtenerEnPos(int pos) const
{
    if(EstaVacia()) throw ListaVacia();

    Elemento *actual = primero;
    for(int i = 0; i < pos; ++i) actual = actual -> siguiente;
    return actual -> valor;
}

/****************************************************************************************************************/

template <typename T>
void ListaDoble<T>::ModificarEnPos(int pos, T valor)
{
    if(EstaVacia()) throw ListaVacia();
    Elemento *ant = primero;
    for(int i = 1; i < pos; ++i) ant = ant -> siguiente;
    ant -> siguiente -> valor = valor;
}

/****************************************************************************************************************/

template <typename T>
int ListaDoble<T>::ObtenerTam() const
{
    return tam;
}

/****************************************************************************************************************/

template <typename T>
void ListaDoble<T>::Vaciar()
{
    while(!EstaVacia()){
        EliminarDelInicio();
    }
}

/****************************************************************************************************************/

template <typename T>
void ListaDoble<T>::Imprimir() const
{
    if(EstaVacia()) std::cout <<"( )" << std::endl;
    else{
        std::cout << "( ";
        Elemento *actual = primero;
        for(int i = 0; i < tam; ++i){
            std::cout << actual -> valor << ", ";
            actual = actual -> siguiente;
        }
        std::cout << "\b\b  )";
    }

}

/****************************************************************************************************************/

template <typename T>
const char* ListaDoble<T>::ListaVacia::what() const throw()
{
    return "Se intent\242 modificar una lista vac\241a...";
}

/****************************************************************************************************************/

template <typename T>
const char* ListaDoble<T>::FueraDeRango::what() const throw()
{
    return "El \241ndice de posici\242n se encuentra fuera de rango...";
}



