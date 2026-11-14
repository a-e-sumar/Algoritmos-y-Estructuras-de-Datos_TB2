#pragma once
#include "Profesor.h"
#include <string>
#include <iostream>
using namespace std;

template<typename T>
struct NodoProfesor {
    T dato;
    NodoProfesor<T>* izquierda;
    NodoProfesor<T>* derecha;

    NodoProfesor(T valor) {
        dato = valor;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

template<typename T>
class ProfesorBST
{
private:
    NodoProfesor<T>* raiz;

    NodoProfesor<T>* minimo(NodoProfesor<T>* nodo) {
        if (nodo == nullptr)
            return nullptr;
        while (nodo->izquierda != nullptr) {
            nodo = nodo->izquierda;
        }
        return nodo;
    }
    NodoProfesor<T>* maximo(NodoProfesor<T>* nodo) {
        if (nodo == nullptr)
            return nullptr;
        while (nodo->derecha != nullptr) {
            nodo = nodo->derecha;
        }
        return nodo;
    }

    bool insertar(NodoProfesor<T>*& nodo, T dato) {
        if (nodo == nullptr) {
            nodo = new NodoProfesor<T>(dato);
            return true;
        }
        if (dato.getId() < nodo->dato.getId()) {
            return insertar(nodo->izquierda, dato);
        }
        else if (dato.getId() > nodo->dato.getId()) {
            return insertar(nodo->derecha, dato);
        }
        return false;
    }
    NodoProfesor<T>* buscar(NodoProfesor<T>* nodo, int id) {
        if (nodo == nullptr || nodo->dato.getId() == id) {
            return nodo;
        }
        if (id < nodo->dato.getId()) {
            return buscar(nodo->izquierda, id);
        }
        return buscar(nodo->derecha, id);
    }
    bool eliminarNodo(NodoProfesor<T>*& nodo, int id) {
        if (nodo == nullptr)
            return false;

        if (id < nodo->dato.getId()) {
            return eliminarNodo(nodo->izquierda, id);
        }
        if (id > nodo->dato.getId()) {
            return eliminarNodo(nodo->derecha, id);
        }

        // Caso 1: Nodo hoja
        if (nodo->izquierda == nullptr &&
            nodo->derecha == nullptr) {
            delete nodo;
            nodo = nullptr;
        }
        // Caso 2: Solo tiene hijo derecho
        else if (nodo->izquierda == nullptr) {
            NodoProfesor<T>* auxiliar = nodo;
            nodo = nodo->derecha;
            delete auxiliar;
        }
        // Caso 3: Solo tiene hijo izquierdo
        else if (nodo->derecha == nullptr) {
            NodoProfesor<T>* auxiliar = nodo;
            nodo = nodo->izquierda;
            delete auxiliar;
        }
        // Caso 4: Tiene dos hijos
        else {
            NodoProfesor<T>* sucesor = minimo(nodo->derecha);
            nodo->dato = sucesor->dato;
            eliminarNodo(nodo->derecha, sucesor->dato.getId());
        }
        return true;
    }
    int contarNodos(NodoProfesor<T>* nodo) {
        if (nodo == nullptr)
            return 0;
        return 1 + contarNodos(nodo->izquierda) + contarNodos(nodo->derecha);
    }

    void liberar(NodoProfesor<T>* nodo) {
        if (nodo == nullptr)
            return;
        liberar(nodo->izquierda);
        liberar(nodo->derecha);
        delete nodo;
    }

public:
    ProfesorBST() {
        raiz = nullptr;
    }
    ~ProfesorBST() {
        liberar(raiz);
    }

    // Getters
    NodoProfesor<T>* getRaiz() {
        return raiz;
    }
    T* getProfesor(int id) {
        NodoProfesor<T>* resultado = buscar(raiz, id);
        if (resultado == nullptr)
            return nullptr;
        return &resultado->dato;
    }

    // Metodos
    bool insertar(T dato) {
        return insertar(raiz, dato);
    }
    bool eliminar(int id) {
        return eliminarNodo(raiz, id);
    }
    int contarProfesores() {
        return contarNodos(raiz);
    }

};