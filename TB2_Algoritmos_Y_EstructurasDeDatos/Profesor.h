#pragma once
#include <string>
#include <iostream>
#include "Usuario.h"
using namespace std;

class Profesor : public Usuario
{
private:
    int idCurso;
public:
    Profesor() : Usuario() {
        idCurso = 0;
        id = 0;
        tipo = 1;
        nombre = "";
        apellido = "";
        correo = "";
        contrasena = "";
    }

    Profesor(int pid, string pnombre, string papellido, string pcorreo, string pcontrasena, int pidCurso)
        : Usuario(pid, 1, pnombre, papellido, pcorreo, pcontrasena) {
        idCurso = pidCurso;
        id = pid;
        tipo = 1;
        nombre = pnombre;
        apellido = papellido;
        correo = pcorreo;
        contrasena = pcontrasena;
    }

    // Getters
    int getIdCurso() { return idCurso; }

    // Setters
    void setIdCurso(int pidCurso) { idCurso = pidCurso; }
};

