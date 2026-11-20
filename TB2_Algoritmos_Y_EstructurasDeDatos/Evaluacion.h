#pragma once
#include <string>
#include <iostream>
using namespace std;

class Evaluacion
{
private:
    int idEvaluacion;
    int idModulo;
    string pregunta1;
    string pregunta2;
    string respuesta1;
    string respuesta2;

public:

    Evaluacion() {
        idModulo = 0;
        idEvaluacion = 0;
        pregunta1 = "";
        pregunta2 = "";
        respuesta1 = "";
        respuesta2 = "";
    }

    Evaluacion(int pidEvaluacion, int pidModulo, string ppregunta1, string ppregunta2, string prespuesta1, string prespuesta2) {
        idEvaluacion = pidEvaluacion;
        idModulo = pidModulo;
        pregunta1 = ppregunta1;
        pregunta2 = ppregunta2;
        respuesta1 = prespuesta1;
        respuesta2 = prespuesta2;
    }

    // Getters
    int getIdModulo() { return idModulo; }
    int getIdEvaluacion() { return idEvaluacion; }
    string getPregunta1() { return pregunta1; }
    string getPregunta2() { return pregunta2; }
    string getRespuesta1() { return respuesta1; }
    string getRespuesta2() { return respuesta2; }

    // Setters
    void setIdModulo(int pidModulo) { idModulo = pidModulo; }
    void setIdEvaluacion(int pidEvaluacion) { idEvaluacion = pidEvaluacion; }
    void setPregunta1(string ppregunta1) { pregunta1 = ppregunta1; }
    void setPregunta2(string ppregunta2) { pregunta2 = ppregunta2; }
    void setRespuesta1(string prespuesta1) { respuesta1 = prespuesta1; }
    void setRespuesta2(string prespuesta2) { respuesta2 = prespuesta2; }

    // Metodos
    void mostrarEvaluacion() {
        cout << "\n\t=== Evaluacion ===\n\n";
        cout << "Pregunta 1:\n" << pregunta1 << endl;
        cout << "Respuesta: " << respuesta1 << endl << endl;
        cout << "Pregunta 2:\n" << pregunta2 << endl;
        cout << "Respuesta: " << respuesta2 << endl;
    }
};