#pragma once
#include <fstream>
#include <string>

#include "Profesor.h"
#include "ProfesorBST.h"
#include "Curso.h"
#include "CursoAVL.h"
#include "Estudiante.h"
#include "EstudianteHashTable.h"
#include "Modulo.h"
#include "ModuloAVL.h"
#include "Leccion.h"
#include "LeccionListaDoble.h"
#include "Ejercicio.h"
#include "EjercicioHashTable.h"
#include "Progreso.h"
#include "HistorialEjercicio.h"
#include "HistorialEvaluacion.h"

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//structs binarios para acceso directo
struct RegistroProgreso {
    int idEstudiante;
    int progresoCurso;
    int progresoModulo;
    int progresoLeccion;
    int progresoEjercicio;
};

struct RegistroHistorialEjercicio {
    int idEstudiante;
    int idEjercicio;
};

struct RegistroHistorialEvaluacion {
    int idEstudiante;
    int idEvaluacion;
    int intentos;
};

class GestorArchivos {
private:
    //para archivos de texto
    string archivoProfesores;
    string archivoCursos;
    string archivoEstudiantes;
    string archivoModulos;
    string archivoLecciones;
    string archivoEjercicios;

    //paa archivos binarios
    string archivoProgreso;
    string archivoHistorialEjercicios;
    string archivoHistorialEvaluaciones;

    //base de id de estudiantes
    int baseIdEstudiante;
    char marcadorSaltoLinea;

    //para restaurar \n
    string escaparSaltosLinea(const string& texto) {
        string resultado = "";
        for (size_t i = 0; i < texto.size(); i++) {
            if (texto[i] == '\n') {
                resultado += marcadorSaltoLinea;
            }
            else if (texto[i] != '\r') {
                resultado += texto[i];
            }
        }
        return resultado;
    }

    string restaurarSaltosLinea(const string& texto) {
        string resultado = "";
        for (size_t i = 0; i < texto.size(); i++) {
            if (texto[i] == marcadorSaltoLinea) {
                resultado += '\n';
            }
            else {
                resultado += texto[i];
            }
        }
        return resultado;
    }

    bool existeArchivo(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo.c_str(), ios::in);
        bool abierto = archivo.is_open();
        if (abierto) {
            archivo.close();
        }
        return abierto;
    }

public:
    GestorArchivos(int pbaseIdEstudiante = 20000, char pmarcadorSaltoLinea = '\x1F') {
        archivoProfesores = "profesores.txt";
        archivoCursos = "cursos.txt";
        archivoEstudiantes = "estudiantes.txt";
        archivoModulos = "modulos.txt";
        archivoLecciones = "lecciones.txt";
        archivoEjercicios = "ejercicios.txt";

        archivoProgreso = "progreso.dat";
        archivoHistorialEjercicios = "historialEjercicios.dat";
        archivoHistorialEvaluaciones = "historialEvaluaciones.dat";

        baseIdEstudiante = pbaseIdEstudiante;
        marcadorSaltoLinea = pmarcadorSaltoLinea;
    }

    ~GestorArchivos() {}

    bool existeContenido() {
        return existeArchivo(archivoProfesores) &&
               existeArchivo(archivoCursos) &&
               existeArchivo(archivoEstudiantes) &&
               existeArchivo(archivoModulos) &&
               existeArchivo(archivoLecciones) &&
               existeArchivo(archivoEjercicios);
    }

    bool guardarProfesores(ProfesorBST<Profesor>& profesores) { return false; }
    bool cargarProfesores(ProfesorBST<Profesor>& profesores) { return false; }

    bool guardarCursos(CursoAVL<Curso>& cursos) { return false; }
    bool cargarCursos(CursoAVL<Curso>& cursos) { return false; }

    bool guardarEstudiantes(EstudianteHashTable<Estudiante>& estudiantes) { return false; }
    bool cargarEstudiantes(EstudianteHashTable<Estudiante>& estudiantes, CursoAVL<Curso>& cursos) { return false; }

    bool guardarModulos(ModuloAVL<Modulo>& modulos) { return false; }
    bool cargarModulos(ModuloAVL<Modulo>& modulos, CursoAVL<Curso>& cursos) { return false; }

    bool guardarLecciones(LeccionListaDoble<Leccion>& lecciones) { return false; }
    bool cargarLecciones(LeccionListaDoble<Leccion>& lecciones, ModuloAVL<Modulo>& modulos) { return false; }

    bool guardarEjercicios(EjercicioHashTable<Ejercicio>& ejercicios) { return false; }
    bool cargarEjercicios(EjercicioHashTable<Ejercicio>& ejercicios, LeccionListaDoble<Leccion>& lecciones) { return false; }

    bool guardarProgreso(int idEstudiante, const Progreso& progreso) { return false; }
    bool cargarProgreso(int idEstudiante, Progreso& progreso) { return false; }

    bool agregarEjercicioCompletado(int idEstudiante, int idEjercicio) { return false; }
    bool registrarIntentoEvaluacion(int idEstudiante, int idEvaluacion, int intentos = 1) { return false; }

    bool cargarHistorialEjercicio(int idEstudiante, HistorialEjercicio& historial) { return false; }
    bool cargarHistorialEvaluacion(int idEstudiante, HistorialEvaluacion& historial) { return false; }
};