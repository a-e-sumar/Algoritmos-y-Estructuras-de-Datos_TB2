#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Evaluacion.h"
using namespace std;

class Modulo
{
private:
    int idModulo;
    int idCurso;
    string nombre;
    Evaluacion evaluacion; // examen final del modulo
    vector<int> idsLecciones; // guarda id de lecciones del modulo (las lecciones viven en la LeccionListaDoble global)

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

    Modulo(int pidModulo, int pidCurso, string pnombre, Evaluacion pevaluacion, vector<int> pidsLecciones) {
        idModulo = pidModulo;
        idCurso = pidCurso;
        nombre = pnombre;
        evaluacion = pevaluacion;
        idsLecciones = pidsLecciones;
    }

    // Getters
    int getIdModulo() { return idModulo; }
    int getIdCurso() { return idCurso; }
    string getNombre() { return nombre; }
    Evaluacion& getEvaluacion() { return evaluacion; }
    const vector<int>& getIdsLecciones() { return idsLecciones; }
    int getCantidadLecciones() { return (int)idsLecciones.size(); }

    // Setters
    void setIdModulo(int pidModulo) { idModulo = pidModulo; }
    void setIdCurso(int pidCurso) { idCurso = pidCurso; }
    void setNombre(string pnombre) { nombre = pnombre; }
    void setEvaluacion(Evaluacion pevaluacion) { evaluacion = pevaluacion; }
    void setIdsLecciones(vector<int> pidsLecciones) { idsLecciones = pidsLecciones; }

    // Metodos
    bool existeLeccion(int idLeccion) { // Verifica si la leccion pertenece al modulo
        for (size_t i = 0; i < idsLecciones.size(); i++) {
            if (idsLecciones[i] == idLeccion) {
                return true;
            }
        }
        return false;
    }

    //solo se usa para cargar o generar datos
    bool agregarLeccion(int idLeccion) { // Agrega el id de una leccion al modulo
        if (!existeLeccion(idLeccion)) {
            idsLecciones.push_back(idLeccion);
            return true;
        }
        return false;
    }

    bool eliminarLeccion(int idLeccion) { // Elimina el id de una leccion del modulo
        for (size_t i = 0; i < idsLecciones.size(); i++) {
            if (idsLecciones[i] == idLeccion) {
                idsLecciones.erase(idsLecciones.begin() + i);
                return true;
            }
        }
        return false;
    }

    void mostrarModulo() {
        cout << "\n=== Informacion del modulo ===\n";
        cout << "ID: " << idModulo << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "ID Curso: " << idCurso << endl;
        cout << "ID Evaluacion: " << evaluacion.getIdEvaluacion() << endl;
        cout << "Cantidad de lecciones: " << idsLecciones.size() << endl;
    }
};