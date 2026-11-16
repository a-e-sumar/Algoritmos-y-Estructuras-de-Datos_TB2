#pragma once
#include <string>
#include <iostream>
#include "Usuario.h"
#include "Progreso.h" // Cambiar despues de implementar ProgresoHashTable
using namespace std;

class Estudiante : public Usuario
{
private:
    int idProfesor;
    int idCurso;

    Progreso progreso; // Cambiar despues de implementar ProgresoHashTable

public:
    Estudiante() : Usuario() {
        idProfesor = 0;
        idCurso = 0;
        id = 0;
        tipo = 2;
        nombre = "";
        apellido = "";
        correo = "";
        contrasena = "";
        progreso = Progreso(); // Cambiar despues de implementar ProgresoHashTable
    }

    Estudiante(int pid, string pnombre, string papellido, string pcorreo, string pcontrasena, int pidProfesor, int pidCurso,
        int pprogresoCurso = 0, int pprogresoModulo = 0, int pprogresoLeccion = 0, int pprogresoEjercicio = 0 ) // Cambiar despues de implementar ProgresoHashTable
        : Usuario(pid, 2, pnombre, papellido, pcorreo, pcontrasena) {

        idProfesor = pidProfesor;
        idCurso = pidCurso;
        id = pid;
        tipo = 2;
        nombre = pnombre;
        apellido = papellido;
        correo = pcorreo;
        contrasena = pcontrasena;
        progreso = Progreso(pid, pprogresoCurso, pprogresoModulo, pprogresoLeccion, pprogresoEjercicio); // Cambiar despues de implementar ProgresoHashTable
    }

    // Getters
    int getIdProfesor() { return idProfesor; }
    int getIdCurso() { return idCurso; }
    Progreso& getProgreso() { return progreso; }  // Cambiar despues de implementar ProgresoHashTable

    // Setters
    void setIdProfesor(int pidProfesor) { idProfesor = pidProfesor; }
    void setIdCurso(int pidCurso) { idCurso = pidCurso; }
};
