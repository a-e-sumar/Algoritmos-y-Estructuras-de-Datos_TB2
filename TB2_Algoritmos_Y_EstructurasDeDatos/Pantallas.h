#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

const int PROFESOR_BASE = 10000;
const int PROFESOR_LIMITE = 10099;   // 100 profesores
const int ESTUDIANTE_BASE = 20000;
const int ESTUDIANTE_LIMITE = 23999;   // 4000 estudiantes

static void limpiarPantalla() { system("cls"); }

static void encabezadoPantalla(string subtitlo = "Plataforma Educativa") {
    cout << endl << endl;
    cout << "=================================" << endl;
    cout << "      " << subtitlo << endl;
    cout << "=================================" << endl;
    cout << endl;
}

static void pausarPantalla() {
    cout << endl << "Presione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

int pantallaInicio() {
    int opcion;
    do {
        limpiarPantalla();
        encabezadoPantalla();
        cout << "1. Iniciar sesion" << endl;
        cout << "2. Salir" << endl << endl;
        cout << "Seleccione: ";
        cin >> opcion;
    } while (opcion != 1 && opcion != 2);
    return opcion;
}

int pantallaInicioSesion() {
    limpiarPantalla();
    encabezadoPantalla();
    cout << "Bienvenido/a al sistema." << endl;
    cout << "Ingrese su ID para iniciar sesion." << endl << endl;
    cout << "Rango de IDs validos:" << endl;
    cout << "  Profesor  : " << PROFESOR_BASE << " - " << PROFESOR_LIMITE << endl;
    cout << "  Estudiante: " << ESTUDIANTE_BASE << " - " << ESTUDIANTE_LIMITE << endl << endl;
    cout << "ID: ";
    int id;
    cin >> id;
    return id;
}

int pantallaProfesor(string nombre) {
    int opcion;
    do {
        limpiarPantalla();
        encabezadoPantalla();
        cout << "Bienvenido/a, " << nombre << endl << endl;
        cout << "1. Ver lista de estudiantes" << endl;
        cout << "2. Agregar estudiante" << endl;
        cout << "3. Eliminar estudiante" << endl;
        cout << "4. Buscar estudiante por ID" << endl;
        cout << "5. Ver estudiante con mayor progreso" << endl;
        cout << "6. Ver estudiante con menor progreso" << endl;
        cout << "7. Ordenar estudiantes por progreso" << endl;
        cout << "8. Ordenar estudiantes por ID" << endl;
        cout << "9. Ordenar estudiantes por nombre" << endl;
        cout << "10. Ver informacion del curso" << endl;
        cout << "11. Cerrar sesion" << endl << endl;
        cout << "Seleccione: ";
        cin >> opcion;
    } while (opcion < 1 || opcion > 11);
    return opcion;
}

int pantallaEstudiante(string nombre) {
    int opcion;
    do {
        limpiarPantalla();
        encabezadoPantalla();
        cout << "Bienvenido/a, " << nombre << endl << endl;
        cout << "1. Continuar curso" << endl;
        cout << "2. Ver progreso" << endl;
        cout << "3. Ver historial de ejercicios" << endl;
        cout << "4. Ver historial de evaluaciones" << endl;
        cout << "5. Cerrar sesion" << endl << endl;
        cout << "Seleccione: ";
        cin >> opcion;
    } while (opcion < 1 || opcion > 5);
    return opcion;
}

string pantallaEjercicio(string pregunta) {
    limpiarPantalla();
    encabezadoPantalla("EJERCICIOS");
    cout << pregunta << endl << endl;
    cout << "Respuesta (A, B o C): ";
    string opcion;
    cin >> opcion;
    return opcion;
}

int pantallaLeccion(string leccion, string contenido) {
    int opcion;
    do {
        limpiarPantalla();
        encabezadoPantalla(leccion);
        cout << contenido << endl << endl;
        cout << "1. Ejercicios" << endl;
        cout << "2. Siguiente leccion" << endl;
        cout << "3. Leccion anterior" << endl;
        cout << "4. Salir de la leccion" << endl;
        cout << "5. Cerrar sesion" << endl << endl;
        cout << "Selecciona: ";
        cin >> opcion;
    } while (opcion < 1 || opcion > 5);
    return opcion;
}

bool pantallaEvaluacion(string pregunta1, string pregunta2, string respuestaCorrecta1, string respuestaCorrecta2) {
    limpiarPantalla();
    encabezadoPantalla("EVALUACION");

    string respuesta;
    int correctas = 0;

    cout << "Pregunta 1:" << endl << pregunta1 << endl << endl;
    cout << "Respuesta: ";
    cin >> respuesta;
    if (respuesta == respuestaCorrecta1) correctas++;

    limpiarPantalla();
    encabezadoPantalla("EVALUACION");
    cout << "Pregunta 2:" << endl << pregunta2 << endl << endl;
    cout << "Respuesta: ";
    cin >> respuesta;
    if (respuesta == respuestaCorrecta2) correctas++;

    limpiarPantalla();
    encabezadoPantalla("RESULTADO");
    cout << "Respuestas correctas: " << correctas << " / 2" << endl << endl;

    bool aprobado = (correctas == 2);
    if (aprobado) cout << "Evaluacion APROBADA." << endl;
    else          cout << "Evaluacion NO aprobada." << endl;

    pausarPantalla();
    return aprobado;
}

void pantallaProgreso(int progresoCurso, int progresoModulo, int progresoLeccion, int progresoEjercicio) {
    limpiarPantalla();
    encabezadoPantalla("MI PROGRESO");
    cout << "Curso     : " << progresoCurso << " %" << endl;
    cout << "Modulo    : " << progresoModulo << " %" << endl;
    cout << "Leccion   : " << progresoLeccion << " %" << endl;
    cout << "Ejercicio : " << progresoEjercicio << " %" << endl;
    pausarPantalla();
}

void pantallaCierreSesion() {
    limpiarPantalla();
    encabezadoPantalla();
    cout << "Cerrando sesion..." << endl << endl;
    cout << "Presione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

void pantallaMensajeError(string mensaje) {
    cout << "\n[ERROR] " << mensaje << endl;
    pausarPantalla();
}