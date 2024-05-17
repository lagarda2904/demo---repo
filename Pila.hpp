/**
 * \file Pila.hpp
 * \brief Aplicaci&oacute;n de Pila
 * \author Romero Lagarda Jose Pablo, Martinez Lopez Sergio Eduardo
 * \date 07/03/2024
 */

#ifndef PILA_HPP
#define PILA_HPP

#include <iostream>

using namespace std;

/**
 * @class Pila
 * @brief Clase template para representar una estructura de datos tipo pila.
 *
 * Esta clase gestiona una colecci&oacute;n de elementos organizados de acuerdo al
 * principio LIFO (Last In, First Out - &Uacute;ltimo en Entrar, Primero en Salir).
 * Permite operaciones t&iacute;picas como insertar, eliminar y observar el elemento en el tope.
 */
template<typename T>
class Pila {
private:
    /**
     * @struct Nodo
     * @brief Estructura interna de la pila que almacena los elementos y la referencia al siguiente nodo.
     */
    struct Nodo {
        T dato; ///< Elemento de datos almacenado en el nodo.
        Nodo* siguiente; ///< Puntero al siguiente nodo en la pila.

        /**
         * @brief Constructor del nodo que inicializa el dato y el puntero al siguiente nodo.
         * @param d Elemento de datos a almacenar en el nodo.
         */
        Nodo(const T& d) : dato(d), siguiente(nullptr) {}
    };

    Nodo* tope; ///< Puntero al nodo en el tope de la pila.
    int tamano; ///< N&uacute;mero actual de elementos en la pila.

public:
    /**
     * @brief Constructor por defecto de la pila.
     */
    Pila();

    /**
     * @brief Destructor de la pila que libera todos los nodos.
     */
    ~Pila();

    /**
     * @brief Inserta un nuevo elemento en el tope de la pila.
     * @param elemento Elemento a insertar en la pila.
     */
    void push(const T& elemento);

    /**
     * @brief Elimina el elemento en el tope de la pila.
     * Lanza una excepci&oacute;n si la pila est&aacute; vac&iacute;a.
     */
    void pop();

    /**
     * @brief Devuelve una referencia al elemento en el tope de la pila.
     * @return Referencia al elemento en el tope de la pila.
     * Lanza una excepci&oacute;n si la pila est&aacute; vac&iacute;a.
     */
    T& peek();

    /**
     * @brief Comprueba si la pila est&aacute; vac&iacute;a.
     * @return Verdadero si la pila no tiene elementos, falso en caso contrario.
     */
    bool empty();

    /**
     * @brief Devuelve el n&uacute;mero de elementos en la pila.
     * @return Tama&ntilde;o actual de la pila.
     */
    int size();
};

#include "Pila.tpp"

#endif // PILA_HPP
