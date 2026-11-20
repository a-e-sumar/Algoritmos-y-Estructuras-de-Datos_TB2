#pragma once
#include <string>
#include <iostream>
using namespace std;

class Ejercicio
{
private:
    int idEjercicio;
    int idLeccion;
    string enunciado;
    string respuesta; // respuesta correcta

public:
    Ejercicio() {
        idEjercicio = 0;
        idLeccion = 0;
        enunciado = "";
        respuesta = "";
    }

    Ejercicio(int pidEjercicio, int pidLeccion, string penunciado, string prespuesta) {
        idEjercicio = pidEjercicio;
        idLeccion = pidLeccion;
        enunciado = penunciado;
        respuesta = prespuesta;
    }

    // Getters
    int getIdEjercicio() { return idEjercicio; }
    int getIdLeccion() { return idLeccion; }
    string getEnunciado() { return enunciado; }
    string getRespuesta() { return respuesta; }

    // Setters
    void setIdEjercicio(int pidEjercicio) { idEjercicio = pidEjercicio; }
    void setIdLeccion(int pidLeccion) { idLeccion = pidLeccion; }
    void setEnunciado(string penunciado) { enunciado = penunciado; }
    void setRespuesta(string prespuesta) { respuesta = prespuesta; }

    // Metodos
    bool verificarRespuesta(string prespuestaEstudiante) { // Compara la respuesta del estudiante con la correcta
        return prespuestaEstudiante == respuesta;
    }

    void mostrarEjercicio() {
        cout << "\n\t=== Ejercicio " << idEjercicio << " ===\n\n";
        cout << "Enunciado:\n" << enunciado << endl;
    }
};