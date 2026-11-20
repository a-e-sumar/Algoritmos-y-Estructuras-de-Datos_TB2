#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct NodoEjercicioCola {
    T dato;
    NodoEjercicioCola<T>* siguiente;

    NodoEjercicioCola(T valor) {
        dato = valor;
        siguiente = nullptr;
    }
};

// FIFO temporal con los IDs de los ejercicios pendientes
template<typename T>
class EjercicioCola
{
private:
    NodoEjercicioCola<T>* frente;
    NodoEjercicioCola<T>* fin;
    int cantidad;

    void copiarDesde(const EjercicioCola<T>& otra) {
        NodoEjercicioCola<T>* actual = otra.frente;
        while (actual != nullptr) {
            encolar(actual->dato);
            actual = actual->siguiente;
        }
    }

public:
    EjercicioCola() {
        frente = nullptr;
        fin = nullptr;
        cantidad = 0;
    }
    EjercicioCola(const EjercicioCola<T>& otra) {
        frente = nullptr;
        fin = nullptr;
        cantidad = 0;
        copiarDesde(otra);
    }
    EjercicioCola<T>& operator=(const EjercicioCola<T>& otra) {
        if (this != &otra) {
            vaciar();
            copiarDesde(otra);
        }
        return *this;
    }
    ~EjercicioCola() {
        vaciar();
    }

    // Getters
    int getCantidad() { return cantidad; }
    T* getFrente() { // Devuelve nullptr si la cola esta vacia
        if (frente == nullptr)
            return nullptr;
        return &frente->dato;
    }

    // Metodos
    bool estaVacia() {
        return frente == nullptr;
    }
    void encolar(T dato) {
        NodoEjercicioCola<T>* nuevo = new NodoEjercicioCola<T>(dato);
        if (frente == nullptr) {
            frente = nuevo;
            fin = nuevo;
        }
        else {
            fin->siguiente = nuevo;
            fin = nuevo;
        }
        cantidad++;
    }
    bool desencolar() {
        if (frente == nullptr) {
            return false;
        }
        NodoEjercicioCola<T>* temporal = frente;
        frente = frente->siguiente;
        if (frente == nullptr) {
            fin = nullptr;
        }
        delete temporal;
        cantidad--;
        return true;
    }
    void vaciar() {
        while (frente != nullptr) {
            desencolar();
        }
    }
    void mostrarCola() {
        cout << "\n=== Ejercicios pendientes: " << cantidad << " ===\n";
        NodoEjercicioCola<T>* actual = frente;
        while (actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << endl;
    }
};