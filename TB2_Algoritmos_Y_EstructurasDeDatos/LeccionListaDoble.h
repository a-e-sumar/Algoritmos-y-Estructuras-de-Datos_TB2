#pragma once
#include <iostream>
#include "Leccion.h"
using namespace std;

template <typename T>
struct NodoLeccion {
	T dato;
	NodoLeccion<T>* siguiente;
	NodoLeccion<T>* anterior;

	NodoLeccion(T valor) {
		dato = valor;
		siguiente = nullptr;
		anterior = nullptr;
	}
};

template <typename T>
class LeccionListaDoble
{
private:
	NodoLeccion* head;
	NodoLeccion* tail;
	int cantidad;

public:
    LeccionListaDoble() {
        head = nullptr;
        tail = nullptr;
        cantidad = 0;
    }
    ~LeccionListaDoble() {
        vaciar();
    }

	// Getters
	NodoLeccion<T>* getHead() { return head; }
	NodoLeccion<T>* getTail() { return tail; }
	int getCantidad() { return cantidad; }
	bool estaVacia() { return head == nullptr; }
	
	T getLeccion() {
		if (head != nullptr) return head->dato;
		return T();
	}

	// Metodos
    bool insertar(T valor) {
        NodoLeccion<T>* nuevo = new NodoLeccion<T>(valor);
        nuevo->anterior = tail;

        if (tail != nullptr) {
            tail->siguiente = nuevo;
        }
        else {
            head = nuevo;
        }
        tail = nuevo;
        cantidad++;
        return true;
    }

    bool eliminar(int idLeccion) {
        NodoLeccion<T>* actual = head;

        while (actual != nullptr && actual->dato.getIdLeccion() != idLeccion) {
            actual = actual->siguiente;
        }

        if (actual == nullptr) return false;

        if (actual == head) {
            head = head->siguiente;
            if (head != nullptr) head->anterior = nullptr;
            else tail = nullptr;
        }
        else if (actual == tail) {
            tail = tail->anterior;
            tail->siguiente = nullptr;
        }
        else {
            actual->anterior->siguiente = actual->siguiente;
            actual->siguiente->anterior = actual->anterior;
        }

        delete actual;
        cantidad--;
        return true;
    }

    void vaciar() {
        NodoLeccion<T>* actual = head;
        while (actual != nullptr) {
            NodoLeccion<T>* temporal = actual;
            actual = actual->siguiente;
            delete temporal;
        }
        head = nullptr;
        tail = nullptr;
        cantidad = 0;
    }

};