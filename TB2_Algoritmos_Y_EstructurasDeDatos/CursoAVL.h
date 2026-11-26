#pragma once
#include "Curso.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

template<typename T>
struct NodoCurso {
    T dato;
    int altura;
    NodoCurso<T>* izquierda;
    NodoCurso<T>* derecha;

    NodoCurso(T valor) {
        dato = valor;
        altura = 0;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

template <typename T>
class CursoAVL {
private:
    NodoCurso<T>* raiz;
	int rotaciones;
    int obtenerAltura(NodoCurso<T>* nodo) {
        if (nodo == nullptr) {
            return -1;
        }
        return nodo->altura;
    }
    int obtenerFactorEquilibrio(NodoCurso<T>* nodo) {
        if (nodo == nullptr) {
            return 0;
        }
        return obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha);
    }
    void actualizarAltura(NodoCurso<T>* nodo) {
        nodo->altura = 1 + max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha));
    }

    // Rotacion simple a la derecha (caso LL)
    void rotacionDerecha(NodoCurso<T>*& desbalanceado) {
        NodoCurso<T>* nuevaRaiz = desbalanceado->izquierda;
        NodoCurso<T>* subarbol = nuevaRaiz->derecha;

        nuevaRaiz->derecha = desbalanceado;
        desbalanceado->izquierda = subarbol;

        actualizarAltura(desbalanceado);
        actualizarAltura(nuevaRaiz);

        desbalanceado = nuevaRaiz;
        rotaciones++;
    }
    // Rotacion simple a la izquierda (caso RR)
    void rotacionIzquierda(NodoCurso<T>*& desbalanceado) {
        NodoCurso<T>* nuevaRaiz = desbalanceado->derecha;
        NodoCurso<T>* subarbol = nuevaRaiz->izquierda;

        nuevaRaiz->izquierda = desbalanceado;
        desbalanceado->derecha = subarbol;

        actualizarAltura(desbalanceado);
        actualizarAltura(nuevaRaiz);

        desbalanceado = nuevaRaiz;
        rotaciones++;
    }
    // Actualiza la altura y aplica LL, LR, RR o RL
    void balancear(NodoCurso<T>*& nodo) {
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

    NodoCurso<T>* minimo(NodoCurso<T>* nodo) {
        if (nodo == nullptr)
            return nullptr;
        while (nodo->izquierda != nullptr) {
            nodo = nodo->izquierda;
        }
        return nodo;
    }

    bool insertar(NodoCurso<T>*& nodo, T dato) {
        if (nodo == nullptr) {
            nodo = new NodoCurso<T>(dato);
            return true;
        }
        bool insertado;
        if (dato.getIdCurso() < nodo->dato.getIdCurso()) {
            insertado = insertar(nodo->izquierda, dato);
        }
        else if (dato.getIdCurso() > nodo->dato.getIdCurso()) {
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
    NodoCurso<T>* buscar(NodoCurso<T>* nodo, int id) {
        if (nodo == nullptr || nodo->dato.getIdCurso() == id) {
            return nodo;
        }
        if (id < nodo->dato.getIdCurso()) {
            return buscar(nodo->izquierda, id);
        }
        return buscar(nodo->derecha, id);
    }
    bool eliminarNodo(NodoCurso<T>*& nodo, int id) {
        if (nodo == nullptr)
            return false;

        bool eliminado;
        if (id < nodo->dato.getIdCurso()) {
            eliminado = eliminarNodo(nodo->izquierda, id);
        }
        else if (id > nodo->dato.getIdCurso()) {
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
                NodoCurso<T>* auxiliar = nodo;
                nodo = nodo->derecha;
                delete auxiliar;
                return true;
            }
            // Caso 3: Solo tiene hijo izquierdo
            else if (nodo->derecha == nullptr) {
                NodoCurso<T>* auxiliar = nodo;
                nodo = nodo->izquierda;
                delete auxiliar;
                return true;
            }
            // Caso 4: Tiene dos hijos
            else {
                NodoCurso<T>* sucesor = minimo(nodo->derecha);
                nodo->dato = sucesor->dato;
                eliminado = eliminarNodo(nodo->derecha, sucesor->dato.getIdCurso());
            }
        }
        // Actualizar altura y balancear después de eliminarlo
        if (nodo != nullptr) {
            balancear(nodo);
        }
        return eliminado;
    }
    int contarNodos(NodoCurso<T>* nodo) {
        if (nodo == nullptr)
            return 0;
        return 1 + contarNodos(nodo->izquierda) + contarNodos(nodo->derecha);
    }
    bool verificarAVL(NodoCurso<T>* nodo) {
        if (nodo == nullptr)
            return true;
        int factor = obtenerFactorEquilibrio(nodo);
        if (factor < -1 || factor > 1)
            return false;
        return verificarAVL(nodo->izquierda) && verificarAVL(nodo->derecha);
    }
    void mostrarInOrden(NodoCurso<T>* nodo) {
        if (nodo == nullptr)
            return;
        mostrarInOrden(nodo->izquierda);
        cout << left << setw(10) << nodo->dato.getIdCurso() << "\t"
            << setw(45) << nodo->dato.getNombre()
            << setw(15) << nodo->dato.getIdProfesor()
            << setw(10) << "Estudiantes: " << nodo->dato.getCantidadEstudiantes() << endl;
        mostrarInOrden(nodo->derecha);
    }
    void mostrarArbol(NodoCurso<T>* nodo, int nivel) {
        if (nodo == nullptr)
            return;
        mostrarArbol(nodo->derecha, nivel + 1);
        for (int i = 0; i < nivel; i++)
            cout << "        ";
        cout << nodo->dato.getIdCurso()
            << " (FE: " << obtenerFactorEquilibrio(nodo) << ")" << endl;
        mostrarArbol(nodo->izquierda, nivel + 1);
    }
    void liberar(NodoCurso<T>* nodo) {
        if (nodo == nullptr)
            return;
        liberar(nodo->izquierda);
        liberar(nodo->derecha);
        delete nodo;
    }

public:
    CursoAVL() {
        raiz = nullptr;
        rotaciones = 0;
    }
    ~CursoAVL() {
        liberar(raiz);
    }

    // Getters
    NodoCurso<T>* getRaiz() {
        return raiz;
    }
    T* getCurso(int id) {
        NodoCurso<T>* resultado = buscar(raiz, id);
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
    int contarCursos() {
        return contarNodos(raiz);
    }
    bool estaBalanceado() {
        return verificarAVL(raiz);
    }
    void listarCursos() {
        cout << "\n\t\t\t\t=== Cursos ===\n\n";
        cout << "Id\tNombre del curso\t\t\tProfesor (ID)\t\tEstudiantes (Cantidad)\n";
        cout << "------------------------------------------------\n";
        mostrarInOrden(raiz);
        cout << endl;
    }
    void mostrarEstructura() {
        cout << "\nEstructura del arbol AVL de cursos\n";
        mostrarArbol(raiz, 0);
    }
};