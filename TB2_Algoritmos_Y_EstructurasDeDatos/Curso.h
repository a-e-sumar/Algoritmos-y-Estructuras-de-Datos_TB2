
#pragma once
#include <string>
#include <vector>
using namespace std;

class Curso
{
private:
    int idCurso;
    int idProfesor;
    string nombre;
    vector<int> idsEstudiantes; // guarda SOLO los ids para saber que estudiantes estan inscritos en el curso

public:
    Curso() {
        idCurso = 0;
        idProfesor = 0;
        nombre = "";
    }

    Curso(int pidCurso, int pidProfesor, string pnombre, vector<int> pidsEstudiantes = {}) {
        idCurso = pidCurso;
        idProfesor = pidProfesor;
        nombre = pnombre;
        idsEstudiantes = pidsEstudiantes;
    }

    // Getters
    int getIdCurso() { return idCurso; }
    int getIdProfesor() { return idProfesor; }
    string getNombre() { return nombre; }
    const vector<int>& getIdsEstudiantes() { return idsEstudiantes; }

    // Setters
    void setIdCurso(int pidCurso) { idCurso = pidCurso; }
    void setIdProfesor(int pidProfesor) { idProfesor = pidProfesor; }
    void setNombre(string pnombre) { nombre = pnombre; }
    void setIdsEstudiantes(vector<int> pidsEstudiantes) { idsEstudiantes = pidsEstudiantes; }
};
