#pragma once
#include "Curso.h"
#include <string>
#include <iostream>
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