#pragma once
#include <string>
#include <iostream>
#include "Usuario.h"
using namespace std;

class Estudiante : public Usuario
{
private:
    int idProfesor;
    int idCurso;

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
    }

    Estudiante(int pid, string pnombre, string papellido, string pcorreo, string pcontrasena, int pidProfesor, int pidCurso)
        : Usuario(pid, 2, pnombre, papellido, pcorreo, pcontrasena) {

        idProfesor = pidProfesor;
        idCurso = pidCurso;
        id = pid;
        tipo = 2;
        nombre = pnombre;
        apellido = papellido;
        correo = pcorreo;
        contrasena = pcontrasena;
    }

    // Getters
    int getIdProfesor() { return idProfesor; }
    int getIdCurso() { return idCurso; }

    // Setters
    void setIdProfesor(int pidProfesor) { idProfesor = pidProfesor; }
    void setIdCurso(int pidCurso) { idCurso = pidCurso; }
};
