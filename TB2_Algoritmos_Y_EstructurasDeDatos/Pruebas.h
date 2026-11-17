#pragma once
#include <iostream>
#include <string>

#include "Profesor.h"
#include "Estudiante.h"
#include "ProfesorBST.h"
#include "EstudianteHashTable.h"
#include "EstudianteGestor.h"
#include "Curso.h"
#include "CursoAVL.h"
using namespace std;

Profesor crearProfesor(int id, string nombre, int idCurso) {
    return Profesor(id, nombre, "Flores", nombre + "@uni.edu", "clave", idCurso);
}

Estudiante crearEstudiante(int id, string nombre, int idProf, int idCurso) {
    return Estudiante(id, nombre, "Sanchez", nombre + "@uni.edu", "clave", idProf, idCurso);
}

Curso crearCurso(int id, string nombre, int idProf) {
    return Curso(id, idProf, nombre);
}

void probarBST() {
    bool insertar = true;
    bool buscar = true;
    bool duplicado = true;
    bool eliminar = true;
    bool vaciar = true;

    ProfesorBST<Profesor> arbol;

    // Insertar
    if (arbol.insertar(crearProfesor(50, "Camila", 100)) == false) insertar = false;
    if (arbol.insertar(crearProfesor(30, "Ana", 101)) == false) insertar = false;
    if (arbol.insertar(crearProfesor(70, "Carla", 102)) == false) insertar = false;
    if (arbol.insertar(crearProfesor(20, "Daniel", 103)) == false) insertar = false;
    if (arbol.insertar(crearProfesor(40, "Ignacio", 104)) == false) insertar = false;
    if (arbol.insertar(crearProfesor(60, "Pedro", 105)) == false) insertar = false;
    if (arbol.insertar(crearProfesor(80, "Carlos", 106)) == false) insertar = false;

    if (arbol.contarProfesores() != 7) insertar = false;

    // Buscar
    if (arbol.getProfesor(50) == nullptr) buscar = false;
    if (arbol.getProfesor(20) == nullptr) buscar = false;
    if (arbol.getProfesor(80) == nullptr) buscar = false;
    if (arbol.getProfesor(1000) != nullptr) buscar = false;

    if (arbol.getProfesor(1) != nullptr) buscar = false;

    // Duplicado
    if (arbol.insertar(crearProfesor(50, "Duplicado", 1000)) == true) duplicado = false;

    if (arbol.contarProfesores() != 7) duplicado = false;

    // Eliminar
    if (arbol.eliminar(20) == false) eliminar = false;
    if (arbol.getProfesor(20) != nullptr) eliminar = false;
    if (arbol.eliminar(30) == false) eliminar = false;
    if (arbol.getProfesor(30) != nullptr) eliminar = false;
    if (arbol.eliminar(50) == false) eliminar = false;
    if (arbol.getProfesor(50) != nullptr) eliminar = false;
    if (arbol.eliminar(1000) == true) eliminar = false;

    if (arbol.contarProfesores() != 4) eliminar = false;

    // Vaciar
    arbol.eliminar(40);
    arbol.eliminar(60);
    arbol.eliminar(70);
    arbol.eliminar(80);
    if (arbol.getRaiz() != nullptr) vaciar = false;
    if (arbol.contarProfesores() != 0) vaciar = false;

    // Reporte
    cout << "\n========== REPORTE BST ==========\n";
    cout << "Insertar: " << insertar << "\n";
    cout << "Buscar: " << buscar<< "\n";
    cout << "Duplicado: " << duplicado << "\n";
    cout << "Eliminar: " << eliminar << "\n";
    cout << "Vaciar: " << vaciar << "\n";

    int total = insertar + buscar + duplicado + eliminar + vaciar;
    cout << "\nTotal: " << total << "/5\n\n";
}

void probarHash() {
    bool insertar = true;
    bool buscar = true;
    bool duplicado = true;
    bool eliminar = true;

    EstudianteHashTable<Estudiante>* tabla = new EstudianteHashTable<Estudiante>();

    // Insertar
    tabla->insertar(crearEstudiante(9, "Camila", 1, 10));
    tabla->insertar(crearEstudiante(4002, "Ana", 1, 10));
    tabla->insertar(crearEstudiante(8004, "Carla", 2, 20));
    tabla->insertar(crearEstudiante(5, "Daniel", 1, 10));
    tabla->insertar(crearEstudiante(6, "Ignacio", 1, 10));
    tabla->insertar(crearEstudiante(7, "Pedro", 1, 10));
    tabla->insertar(crearEstudiante(8, "Carlos", 1, 10));

    if (tabla->getCantidad() != 7) insertar = false;
    if (tabla->getCapacidad() != TAM_ESTUDIANTES) insertar = false;

    // Buscar
    if (tabla->buscar(9) == -1) buscar = false;
    if (tabla->buscar(4002) == -1) buscar = false;
    if (tabla->buscar(8004) == -1) buscar = false;
    if (tabla->buscar(5) == -1) buscar = false;
    if (tabla->buscar(6) == -1) buscar = false;
    if (tabla->buscar(8) == -1) buscar = false;
    if (tabla->buscar(100) != -1) buscar = false;

    // Duplicado
    if (tabla->duplicado(5) == false) duplicado = false;
    if (tabla->duplicado(100) == true) duplicado = false;

    tabla->insertar(crearEstudiante(5, "Duplicado", 1, 10));
    if (tabla->getCantidad() != 7) duplicado = false;

    // Eliminar
    tabla->eliminar(6);
    if (tabla->buscar(6) != -1) eliminar = false;

    tabla->eliminar(4002);
    if (tabla->buscar(4002) != -1) eliminar = false;

    tabla->eliminar(100); // Buscar "No se puedo eliminar" en el output

    tabla->insertar(crearEstudiante(6, "Ignacio", 1, 10));
    if (tabla->buscar(6) == -1) eliminar = false;
    if (tabla->getCantidad() != 6) eliminar = false;
    delete tabla;

    // Reporte
    cout << "\n========== REPORTE HASH ==========\n";
    cout << "Insertar: " << insertar << "\n";
    cout << "Buscar: " << buscar << "\n";
    cout << "Duplicado: " << duplicado << "\n";
    cout << "Eliminar: " << eliminar << "\n";

    int total = insertar + buscar + duplicado + eliminar;
    cout << "\nTotal: " << total << "/4\n\n";
}

void probarCurso() {
    bool constructor = true;
    bool agregar = true;
    bool duplicado = true;
    bool eliminar = true;

    Curso curso(1, 10, "Algoritmos");

    // Constructor
    if (curso.getIdCurso() != 1) constructor = false;
    if (curso.getIdProfesor() != 10) constructor = false;
    if (curso.getNombre() != "Algoritmos") constructor = false;
    if (curso.getCantidadEstudiantes() != 0) constructor = false;

    // Agregar
    if (curso.agregarEstudiante(100) == false) agregar = false;
    if (curso.agregarEstudiante(200) == false) agregar = false;
    if (curso.agregarEstudiante(300) == false) agregar = false;
    if (curso.getCantidadEstudiantes() != 3) agregar = false;
    if (curso.existeEstudiante(200) == false) agregar = false;
    if (curso.existeEstudiante(999) == true) agregar = false;

    // Duplicado
    if (curso.agregarEstudiante(200) == true) duplicado = false;
    if (curso.getCantidadEstudiantes() != 3) duplicado = false;

    // Eliminar
    if (curso.eliminarEstudiante(200) == false) eliminar = false;
    if (curso.existeEstudiante(200) == true) eliminar = false;
    if (curso.eliminarEstudiante(999) == true) eliminar = false;
    if (curso.getCantidadEstudiantes() != 2) eliminar = false;

    // Reporte
    cout << "\n========== REPORTE CURSO ==========\n";
    cout << "Constructor: " << constructor << "\n";
    cout << "Agregar: " << agregar << "\n";
    cout << "Duplicado: " << duplicado << "\n";
    cout << "Eliminar: " << eliminar << "\n";

    int total = constructor + agregar + duplicado + eliminar;
    cout << "\nTotal: " << total << "/4\n\n";
}

void probarCursoAVL() {
    bool insertar = true;
    bool buscar = true;
    bool duplicado = true;
    bool rotaciones = true;
    bool eliminar = true;
    bool carga = true;
    bool vaciar = true;

    // Insertar y rotaciones (LL, RR, LR, RL)
    CursoAVL<Curso> ll;
    ll.insertar(crearCurso(30, "A", 1));
    ll.insertar(crearCurso(20, "B", 2));
    ll.insertar(crearCurso(10, "C", 3)); // LL
    if (ll.getRaiz()->dato.getIdCurso() != 20) rotaciones = false;

    CursoAVL<Curso> rr;
    rr.insertar(crearCurso(10, "A", 1));
    rr.insertar(crearCurso(20, "B", 2));
    rr.insertar(crearCurso(30, "C", 3)); // RR
    if (rr.getRaiz()->dato.getIdCurso() != 20) rotaciones = false;

    CursoAVL<Curso> lr;
    lr.insertar(crearCurso(30, "A", 1));
    lr.insertar(crearCurso(10, "B", 2));
    lr.insertar(crearCurso(20, "C", 3)); // LR
    if (lr.getRaiz()->dato.getIdCurso() != 20) rotaciones = false;
    if (lr.getRotaciones() != 2) rotaciones = false;

    CursoAVL<Curso> rl;
    rl.insertar(crearCurso(10, "A", 1));
    rl.insertar(crearCurso(30, "B", 2));
    rl.insertar(crearCurso(20, "C", 3)); // RL
    if (rl.getRaiz()->dato.getIdCurso() != 20) rotaciones = false;
    if (rl.getRotaciones() != 2) rotaciones = false;

    CursoAVL<Curso> arbol;
    int ids[] = { 50, 30, 70, 20, 40, 60, 80 };
    for (int i = 0; i < 7; i++) {
        if (arbol.insertar(crearCurso(ids[i], "Curso" + to_string(ids[i]), ids[i] + 1000)) == false) insertar = false;
    }
    if (arbol.contarCursos() != 7) insertar = false;
    if (arbol.getAltura() != 2) insertar = false;
    if (arbol.estaBalanceado() == false) insertar = false;

    // Buscar
    if (arbol.getCurso(50) == nullptr) buscar = false;
    if (arbol.getCurso(20) == nullptr) buscar = false;
    if (arbol.getCurso(80) == nullptr) buscar = false;
    if (arbol.getCurso(1000) != nullptr) buscar = false;
    if (arbol.getCurso(1) != nullptr) buscar = false;
    if (arbol.getCurso(40) != nullptr && arbol.getCurso(40)->getNombre() != "Curso40") buscar = false;

    // Duplicado
    if (arbol.insertar(crearCurso(50, "Duplicado", 1)) == true) duplicado = false;
    if (arbol.contarCursos() != 7) duplicado = false;
    if (arbol.getCurso(50)->getNombre() == "Duplicado") duplicado = false;

    // Eliminar (hoja, un hijo, dos hijos, raiz, inexistente)
    if (arbol.eliminar(20) == false) eliminar = false;
    if (arbol.getCurso(20) != nullptr) eliminar = false;
    if (arbol.eliminar(30) == false) eliminar = false;
    if (arbol.getCurso(30) != nullptr) eliminar = false;
    if (arbol.eliminar(50) == false) eliminar = false;
    if (arbol.getCurso(50) != nullptr) eliminar = false;
    if (arbol.eliminar(1000) == true) eliminar = false;
    if (arbol.contarCursos() != 4) eliminar = false;
    if (arbol.estaBalanceado() == false) eliminar = false;

    // Eliminar que fuerza rotacion: 10 -> 5, 20, 3 y se quita 20 (LL)
    CursoAVL<Curso> forzado;
    int forz[] = { 10, 5, 20, 3 };
    for (int i = 0; i < 4; i++) forzado.insertar(crearCurso(forz[i], "F", 1));
    int antes = forzado.getRotaciones();
    forzado.eliminar(20);
    if (forzado.getRotaciones() != antes + 1) eliminar = false;
    if (forzado.estaBalanceado() == false) eliminar = false;
    if (forzado.getRaiz()->dato.getIdCurso() != 5) eliminar = false;

    // Carga: 100 cursos en orden ascendente (peor caso de un BST)
    CursoAVL<Curso> grande;
    for (int i = 1; i <= 100; i++) {
        if (grande.insertar(crearCurso(i, "Curso" + to_string(i), i)) == false) carga = false;
    }
    if (grande.contarCursos() != 100) carga = false;
    if (grande.getAltura() > 7) carga = false; // un BST sin balancear tendria altura 99
    if (grande.estaBalanceado() == false) carga = false;

    // Carga: 1000 cursos y se eliminan 500
    CursoAVL<Curso> masivo;
    for (int i = 1; i <= 1000; i++) masivo.insertar(crearCurso(i, "C", i));
    for (int i = 1; i <= 1000; i += 2) masivo.eliminar(i);
    if (masivo.contarCursos() != 500) carga = false;
    if (masivo.estaBalanceado() == false) carga = false;
    if (masivo.getCurso(2) == nullptr || masivo.getCurso(3) != nullptr) carga = false;

    // Vaciar
    arbol.eliminar(40);
    arbol.eliminar(60);
    arbol.eliminar(70);
    arbol.eliminar(80);
    if (arbol.getRaiz() != nullptr) vaciar = false;
    if (arbol.contarCursos() != 0) vaciar = false;
    if (arbol.getAltura() != -1) vaciar = false;

    // Reporte
    cout << "\n========== REPORTE CURSO AVL ==========\n";
    cout << "Insertar: " << insertar << "\n";
    cout << "Buscar: " << buscar << "\n";
    cout << "Duplicado: " << duplicado << "\n";
    cout << "Rotaciones: " << rotaciones << "\n";
    cout << "Eliminar: " << eliminar << "\n";
    cout << "Carga: " << carga << "\n";
    cout << "Vaciar: " << vaciar << "\n";

    int total = insertar + buscar + duplicado + rotaciones + eliminar + carga + vaciar;
    cout << "\nTotal: " << total << "/7\n\n";
}

void ejecutarPruebas() {
    cout << "\tINICIO DE PRUEBAS\n\n";
    cout << "\nBST:\n";
    probarBST();
    cout << "\nHash:\n";
    probarHash();
    cout << "\nCurso:\n";
    probarCurso();
	cout << "\nCurso AVL:\n";
	probarCursoAVL();
    cout << "\n\tFIN DE PRUEBAS\n";
}