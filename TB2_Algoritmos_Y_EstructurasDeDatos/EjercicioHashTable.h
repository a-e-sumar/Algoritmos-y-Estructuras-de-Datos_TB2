#pragma once
#pragma once
#include "Ejercicio.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

// Hash abierto:Se espera insertar 20000 ejercicios con 4001 posiciones cada lista tiene aprox 5 ejercicios
const int TAM_EJERCICIOS = 4001;
// Constante del método de multiplicación de Knuth: (raiz(5) - 1) / 2
const double A_HASH_EJERCICIOS = 0.6180339887498949;

template<typename T>
struct NodoEjercicioHash {
    T dato;
    NodoEjercicioHash<T>* siguiente;

    NodoEjercicioHash(T valor) {
        dato = valor;
        siguiente = nullptr;
    }
};

template<typename T>
class EjercicioHashTable
{
private:
    NodoEjercicioHash<T>* tabla[TAM_EJERCICIOS];
    int cantidad;
	int colisiones; // indice de colisiones: cantidad de elementos que se insertaron en una lista enlazada

    // método de multiplicación de Knuth
    int funcionHash(int clave) {
        double producto = clave * A_HASH_EJERCICIOS;
        double fraccion = producto - floor(producto);
        return (int)(TAM_EJERCICIOS * fraccion);
    }

    NodoEjercicioHash<T>* buscarNodo(int clave) {
        NodoEjercicioHash<T>* actual = tabla[funcionHash(clave)];
        while (actual != nullptr) {
            if (actual->dato.getIdEjercicio() == clave) {
                return actual;
            }
            actual = actual->siguiente;
        }
        return nullptr;
    }

public:
    EjercicioHashTable() {
        for (int i = 0; i < TAM_EJERCICIOS; i++) {
            tabla[i] = nullptr;
        }
        cantidad = 0;
        colisiones = 0;
    }

    ~EjercicioHashTable() {
        for (int i = 0; i < TAM_EJERCICIOS; i++) {
            NodoEjercicioHash<T>* actual = tabla[i];
            while (actual != nullptr) {
                NodoEjercicioHash<T>* auxiliar = actual;
                actual = actual->siguiente;
                delete auxiliar;
            }
        }
    }

    // Getters
    int getCantidad() { return cantidad; }
    int getColisiones() { return colisiones; }
    int getCapacidad() { return TAM_EJERCICIOS; }
    double getFactorCarga() { return (double)cantidad / TAM_EJERCICIOS; }
    int getMaxCadena() { // Longitud de la lista mas larga
        int maximo = 0;
        for (int i = 0; i < TAM_EJERCICIOS; i++) {
            int largo = 0;
            NodoEjercicioHash<T>* actual = tabla[i];
            while (actual != nullptr) {
                largo++;
                actual = actual->siguiente;
            }
            if (largo > maximo) maximo = largo;
        }
        return maximo;
    }

    // Metodos
    // No imprime mensajes porque se insertan miles de ejercicios (dataset y archivos)
    bool insertar(T dato) {
        int clave = dato.getIdEjercicio();
        if (duplicado(clave)) {
            return false; // ID duplicado
        }
        int posicion = funcionHash(clave);
        NodoEjercicioHash<T>* nuevo = new NodoEjercicioHash<T>(dato);
        if (tabla[posicion] != nullptr) {
            colisiones++;
        }
        // Insertar al inicio de la lista
        nuevo->siguiente = tabla[posicion];
        tabla[posicion] = nuevo;
        cantidad++;
        return true;
    }
    bool eliminar(int clave) {
        int posicion = funcionHash(clave);
        NodoEjercicioHash<T>* actual = tabla[posicion];
        NodoEjercicioHash<T>* anterior = nullptr;
        while (actual != nullptr) {
            if (actual->dato.getIdEjercicio() == clave) {
                if (anterior == nullptr) {
                    tabla[posicion] = actual->siguiente; // era el primero de la lista
                }
                else {
                    anterior->siguiente = actual->siguiente;
                }
                delete actual;
                cantidad--;
                return true;
            }
            anterior = actual;
            actual = actual->siguiente;
        }
        return false;
    }
    T* getEjercicio(int clave) {
        NodoEjercicioHash<T>* nodo = buscarNodo(clave);
        if (nodo == nullptr) {
            return nullptr;
        }
        return &nodo->dato;
    }
    bool duplicado(int clave) {
        return buscarNodo(clave) != nullptr;
    }
};