#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <iostream>
#include <exception>

#define NO_ENCONTRADO -1

template <typename T>
class ListaDoble{
public:
    ListaDoble();
    ListaDoble(ListaDoble<T> &lista);
    ListaDoble<T>& operator=(const ListaDoble<T>& lista);
    ~ListaDoble();

    void AgregarAlInicio(T valor);
    void AgregarAlFinal(T valor);
    void AgregarEnPos(T valor, int pos);

    void EliminarDelInicio();
    void EliminarDelFinal();
    void EliminarDePos(int pos);

    bool SeEncuentraValor(T valor) const;
    int BuscarPos(T valor) const;
    bool EstaVacia() const;
    T ObtenerPrimero() const;
    T ObtenerUltimo() const;
    T ObtenerEnPos(int pos) const;

    void ModificarEnPos(int pos, T valor);
    int ObtenerTam() const;
    void Vaciar();
    void Imprimir() const;

    class ListaVacia : public std::exception{
    public:
        virtual const char* what() const throw();
    };

    class FueraDeRango : public std::exception{
    public:
        virtual const char* what() const throw();
    };

private:

    int tam;

    struct Elemento{
        T valor;
        Elemento *siguiente;
        Elemento *anterior;
        Elemento(T valor, Elemento *sig = nullptr, Elemento *ant = nullptr);
    } * ultimo, *primero;

};

#include "ListaDoble.tpp"

#endif // LISTADOBLE_H_INCLUDED
