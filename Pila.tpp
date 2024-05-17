#include <stdexcept>
#include <iostream>
#include "Pila.hpp"

using namespace std;

template<typename T>
Pila<T>::Pila() : tope(nullptr), tamano(0) {}
//*********************************************************************************************
template<typename T>
Pila<T>::~Pila() {
    while (tope != nullptr) {
        Nodo* temp = tope;
        tope = tope->siguiente;
        delete temp;
    }
}
//*********************************************************************************************
template<typename T>
void Pila<T>::push(const T& elemento) {
    Nodo* nuevo = new Nodo(elemento);
    nuevo->siguiente = tope;
    tope = nuevo;
    tamano++;
}
//*********************************************************************************************
template<typename T>
void Pila<T>::pop() {
    if (empty()) {
        throw out_of_range("Pila vacia");
    }
    Nodo* temp = tope;
    tope = tope->siguiente;
    delete temp;
    tamano--;
}
//*********************************************************************************************
template<typename T>
T& Pila<T>::peek() {
    if (empty()) {
        throw out_of_range("Pila vacia");
    }
    return tope->dato;
}
//*********************************************************************************************
template<typename T>
bool Pila<T>::empty() {
    return tamano == 0;
}
//*********************************************************************************************
template<typename T>
int Pila<T>::size() {
    return tamano;
}

