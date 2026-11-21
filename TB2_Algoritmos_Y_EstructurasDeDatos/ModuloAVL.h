#pragma once
#include "Modulo.h"
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
struct NodoModulo {
    T dato;
    int altura;
    NodoModulo<T>* izquierda;
    NodoModulo<T>* derecha;

    NodoModulo(T valor) {
        dato = valor;
        altura = 0;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

template <typename T>
class ModuloAVL {
private:
    NodoModulo<T>* raiz;
    int rotaciones;

    int obtenerAltura(NodoModulo<T>* nodo) {
        if (nodo == nullptr) {
            return -1;
        }
        return nodo->altura;
    }
    int obtenerFactorEquilibrio(NodoModulo<T>* nodo) {
        if (nodo == nullptr) {
            return 0;
        }
        return obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha);
    }
    void actualizarAltura(NodoModulo<T>* nodo) {
        nodo->altura = 1 + max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha));
    }

    // Rotacion simple a la derecha (caso LL)
    void rotacionDerecha(NodoModulo<T>*& desbalanceado) {
        NodoModulo<T>* nuevaRaiz = desbalanceado->izquierda;
        NodoModulo<T>* subarbol = nuevaRaiz->derecha;

        nuevaRaiz->derecha = desbalanceado;
        desbalanceado->izquierda = subarbol;

        actualizarAltura(desbalanceado);
        actualizarAltura(nuevaRaiz);

        desbalanceado = nuevaRaiz;
        rotaciones++;
    }
    // Rotacion simple a la izquierda (caso RR)
    void rotacionIzquierda(NodoModulo<T>*& desbalanceado) {
        NodoModulo<T>* nuevaRaiz = desbalanceado->derecha;
        NodoModulo<T>* subarbol = nuevaRaiz->izquierda;

        nuevaRaiz->izquierda = desbalanceado;
        desbalanceado->derecha = subarbol;

        actualizarAltura(desbalanceado);
        actualizarAltura(nuevaRaiz);

        desbalanceado = nuevaRaiz;
        rotaciones++;
    }
    // Actualiza la altura y aplica LL, LR, RR o RL
    void balancear(NodoModulo<T>*& nodo) {
        actualizarAltura(nodo);
        int factor = obtenerFactorEquilibrio(nodo);

        if (factor > 1) {
            // Caso LR
            if (obtenerFactorEquilibrio(nodo->izquierda) < 0) {
                rotacionIzquierda(nodo->izquierda);
            }
            // Caso LL
            rotacionDerecha(nodo);
        }
        else if (factor < -1) {
            // Caso RL
            if (obtenerFactorEquilibrio(nodo->derecha) > 0) {
                rotacionDerecha(nodo->derecha);
            }
            // Caso RR
            rotacionIzquierda(nodo);
        }
    }

    NodoModulo<T>* minimo(NodoModulo<T>* nodo) {
        if (nodo == nullptr)
            return nullptr;
        while (nodo->izquierda != nullptr) {
            nodo = nodo->izquierda;
        }
        return nodo;
    }

    bool insertar(NodoModulo<T>*& nodo, T dato) {
        if (nodo == nullptr) {
            nodo = new NodoModulo<T>(dato);
            return true;
        }
        bool insertado;
        if (dato.getIdModulo() < nodo->dato.getIdModulo()) {
            insertado = insertar(nodo->izquierda, dato);
        }
        else if (dato.getIdModulo() > nodo->dato.getIdModulo()) {
            insertado = insertar(nodo->derecha, dato);
        }
        else {
            return false; // ID duplicado
        }
        if (insertado) {
            balancear(nodo);
        }
        return insertado;
    }
    NodoModulo<T>* buscar(NodoModulo<T>* nodo, int id) {
        if (nodo == nullptr || nodo->dato.getIdModulo() == id) {
            return nodo;
        }
        if (id < nodo->dato.getIdModulo()) {
            return buscar(nodo->izquierda, id);
        }
        return buscar(nodo->derecha, id);
    }
    bool eliminarNodo(NodoModulo<T>*& nodo, int id) {
        if (nodo == nullptr)
            return false;

        bool eliminado;
        if (id < nodo->dato.getIdModulo()) {
            eliminado = eliminarNodo(nodo->izquierda, id);
        }
        else if (id > nodo->dato.getIdModulo()) {
            eliminado = eliminarNodo(nodo->derecha, id);
        }
        else {
            // Caso 1: Nodo hoja
            if (nodo->izquierda == nullptr && nodo->derecha == nullptr) {
                delete nodo;
                nodo = nullptr;
                return true;
            }
            // Caso 2: Solo tiene hijo derecho
            else if (nodo->izquierda == nullptr) {
                NodoModulo<T>* auxiliar = nodo;
                nodo = nodo->derecha;
                delete auxiliar;
                return true;
            }
            // Caso 3: Solo tiene hijo izquierdo
            else if (nodo->derecha == nullptr) {
                NodoModulo<T>* auxiliar = nodo;
                nodo = nodo->izquierda;
                delete auxiliar;
                return true;
            }
            // Caso 4: Tiene dos hijos
            else {
                NodoModulo<T>* sucesor = minimo(nodo->derecha);
                nodo->dato = sucesor->dato;
                eliminado = eliminarNodo(nodo->derecha, sucesor->dato.getIdModulo());
            }
        }
        // Actualizar altura y balancear despues de eliminarlo
        if (nodo != nullptr) {
            balancear(nodo);
        }
        return eliminado;
    }
    int contarNodos(NodoModulo<T>* nodo) {
        if (nodo == nullptr)
            return 0;
        return 1 + contarNodos(nodo->izquierda) + contarNodos(nodo->derecha);
    }
    bool verificarAVL(NodoModulo<T>* nodo) {
        if (nodo == nullptr)
            return true;
        int factor = obtenerFactorEquilibrio(nodo);
        if (factor < -1 || factor > 1)
            return false;
        return verificarAVL(nodo->izquierda) && verificarAVL(nodo->derecha);
    }
    void mostrarInOrden(NodoModulo<T>* nodo) {
        if (nodo == nullptr)
            return;
        mostrarInOrden(nodo->izquierda);
        cout << nodo->dato.getIdModulo() << "\t" << nodo->dato.getNombre() << "\t"
            << "Curso: " << nodo->dato.getIdCurso() << endl;
        mostrarInOrden(nodo->derecha);
    }
    void mostrarArbol(NodoModulo<T>* nodo, int nivel) {
        if (nodo == nullptr)
            return;
        mostrarArbol(nodo->derecha, nivel + 1);
        for (int i = 0; i < nivel; i++)
            cout << "        ";
        cout << nodo->dato.getIdModulo()
            << " (FE: " << obtenerFactorEquilibrio(nodo) << ")" << endl;
        mostrarArbol(nodo->izquierda, nivel + 1);
    }
    void liberar(NodoModulo<T>* nodo) {
        if (nodo == nullptr)
            return;
        liberar(nodo->izquierda);
        liberar(nodo->derecha);
        delete nodo;
    }
    // Copia profunda de un subarbol (mantiene alturas y estructura)
    NodoModulo<T>* copiar(NodoModulo<T>* nodo) {
        if (nodo == nullptr)
            return nullptr;
        NodoModulo<T>* nuevo = new NodoModulo<T>(nodo->dato);
        nuevo->altura = nodo->altura;
        nuevo->izquierda = copiar(nodo->izquierda);
        nuevo->derecha = copiar(nodo->derecha);
        return nuevo;
    }

public:
    ModuloAVL() {
        raiz = nullptr;
        rotaciones = 0;
    }
    // Constructor de copia y asignacion (para qeu no se libere dos veces el mismo nodo)
    ModuloAVL(const ModuloAVL<T>& otro) {
        raiz = copiar(otro.raiz);
        rotaciones = otro.rotaciones;
    }
    ModuloAVL<T>& operator=(const ModuloAVL<T>& otro) {
        if (this != &otro) {
            liberar(raiz);
            raiz = copiar(otro.raiz);
            rotaciones = otro.rotaciones;
        }
        return *this;
    }
    ~ModuloAVL() {
        liberar(raiz);
    }

    // Getters
    NodoModulo<T>* getRaiz() {
        return raiz;
    }
    T* getModulo(int id) {
        NodoModulo<T>* resultado = buscar(raiz, id);
        if (resultado == nullptr)
            return nullptr;
        return &resultado->dato;
    }
    int getAltura() {
        return obtenerAltura(raiz);
    }
    int getRotaciones() {
        return rotaciones;
    }

    // Metodos
    bool insertar(T dato) {
        return insertar(raiz, dato);
    }
    bool eliminar(int id) {
        return eliminarNodo(raiz, id);
    }
    int contarModulos() {
        return contarNodos(raiz);
    }
    bool estaBalanceado() {
        return verificarAVL(raiz);
    }
    void listarModulos() {
        cout << "\n\t\t=== Modulos ===\n";
        cout << "Id\tNombre\tCurso\n";
        cout << "------------------------------------------------\n";
        mostrarInOrden(raiz);
        cout << endl;
    }
    void mostrarEstructura() {
        cout << "\nEstructura del arbol AVL de modulos\n";
        mostrarArbol(raiz, 0);
    }
};