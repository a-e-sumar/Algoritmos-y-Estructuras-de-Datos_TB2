#pragma once
#include <iostream>
#include <vector>
#include "Ejercicio.h"
#include "EjercicioHashTable.h"
using namespace std;

struct NodoEjercicioCola {
    int idEjercicio;
    NodoEjercicioCola* siguiente;

    NodoEjercicioCola(int pidEjercicio) {
        idEjercicio = pidEjercicio;
        siguiente = nullptr;
    }
};

//cola temporal: se crea cuando el estudiante entra a una leccion
class EjercicioCola
{
private:
    NodoEjercicioCola* frente;
    NodoEjercicioCola* fin;
    int cantidad;

	EjercicioCola(const EjercicioCola&) = delete;
	EjercicioCola& operator=(const EjercicioCola&) = delete;

public:
    EjercicioCola() {
        frente = nullptr;
        fin = nullptr;
        cantidad = 0;
    }
    //pidsEjercicios: vector<int> de la Leccion
    //agregar despues de implementar HistorialEjercicio
    //para filtar los IDs de los ejercicios que ya estan completados
    EjercicioCola(const vector<int>& pidsEjercicios) {
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
    int getIdFrente() { //-1 si la cola esta vacia
        if (frente == nullptr)
            return -1;
        return frente->idEjercicio;
    }
    //buscar en la tabla hash el ejercicio que toca resolver
    Ejercicio* getEjercicioActual(EjercicioHashTable<Ejercicio>& ejercicios) {
        if (frente == nullptr)
			return nullptr; //null si la cola esta vacia
        return ejercicios.getEjercicio(frente->idEjercicio);
    }

    // Metodos
    bool estaVacia() {
        return frente == nullptr;
    }
    void encolar(int pidEjercicio) {
        NodoEjercicioCola* nuevo = new NodoEjercicioCola(pidEjercicio);
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
        NodoEjercicioCola* temporal = frente;
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
        NodoEjercicioCola* actual = frente;
        while (actual != nullptr) {
            cout << actual->idEjercicio << " ";
            actual = actual->siguiente;
        }
        cout << endl;
    }
};