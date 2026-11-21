#pragma once
#include <string>
#include <iostream>
#include "Evaluacion.h"
// #include "LeccionListaDoble.h"
using namespace std;

class Modulo
{
private:
    int idModulo;
    int idCurso;
    string nombre;
    Evaluacion evaluacion; // examen final del modulo
    // LeccionListaDoble lecciones;

public:
    Modulo() {
        idModulo = 0;
        idCurso = 0;
        nombre = "";
        evaluacion = Evaluacion();
    }

    Modulo(int pidModulo, int pidCurso, string pnombre, Evaluacion pevaluacion = Evaluacion()) {
        idModulo = pidModulo;
        idCurso = pidCurso;
        nombre = pnombre;
        evaluacion = pevaluacion;
    }

    // Getters
    int getIdModulo() { return idModulo; }
    int getIdCurso() { return idCurso; }
    string getNombre() { return nombre; }
    Evaluacion& getEvaluacion() { return evaluacion; }
    // LeccionListaDoble& getLecciones()

    // Setters
    void setIdModulo(int pidModulo) { idModulo = pidModulo; }
    void setIdCurso(int pidCurso) { idCurso = pidCurso; }
    void setNombre(string pnombre) { nombre = pnombre; }
    void setEvaluacion(Evaluacion pevaluacion) { evaluacion = pevaluacion; }

    // Metodos
    void mostrarModulo() {
        cout << "\n=== Informacion del modulo ===\n";
        cout << "ID: " << idModulo << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "ID Curso: " << idCurso << endl;
        cout << "ID Evaluacion: " << evaluacion.getIdEvaluacion() << endl;
        // Poner cantidad de lecciones
    }
};