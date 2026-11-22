#pragma once
#include <iostream>
#include <vector>
#include "Ejercicio.h"
#include "EjercicioHashTable.h"
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

//cola temporal: se crea cuando el estudiante entra a una leccion
template<typename T>
class EjercicioCola
{
private:
    NodoEjercicioCola<T>* frente;
    NodoEjercicioCola<T>* fin;
    int cantidad;

public:
    EjercicioCola() {
        frente = nullptr;
        fin = nullptr;
        cantidad = 0;
    }
    //pidsEjercicios: vector<int> de la Leccion
    //agregar despues de implementar HistorialEjercicio
    //para filtar los IDs de los ejercicios que ya estan completados
    EjercicioCola(const vector<T>& pidsEjercicios) {
        frente = nullptr;
        fin = nullptr;
        cantidad = 0;
        for (int i = 0; i < (int)pidsEjercicios.size(); i++) {
            // if (historial.estaCompletado(pidsEjercicios[i])) continue;
            encolar(pidsEjercicios[i]);
        }
    }
    ~EjercicioCola() {
        vaciar();
    }

    // Getters
    int getCantidad() { return cantidad; }
    T* getFrente() { //nullptr si la cola esta vacia
        if (frente == nullptr)
            return nullptr;
        return &frente->dato;
    }
    //buscar en la tabla hash el ejercicio que toca resolver (solo para EjercicioCola<int>)
    Ejercicio* getEjercicioActual(EjercicioHashTable<Ejercicio>& ejercicios) {
        if (frente == nullptr)
            return nullptr; //null si la cola esta vacia
        return ejercicios.getEjercicio(frente->dato);
    }

    // Metodos
    bool estaVacia() {
        return frente == nullptr;
    }
    void encolar(T pdato) {
        NodoEjercicioCola<T>* nuevo = new NodoEjercicioCola<T>(pdato);
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
    bool desencolar() { //despues de resolver un ejercicio
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