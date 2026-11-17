#pragma once
#include <string>
#include <vector>
#include <iostream>
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
    int getCantidadEstudiantes() { return (int)idsEstudiantes.size(); }

    // Setters
    void setIdCurso(int pidCurso) { idCurso = pidCurso; }
    void setIdProfesor(int pidProfesor) { idProfesor = pidProfesor; }
    void setNombre(string pnombre) { nombre = pnombre; }
    void setIdsEstudiantes(vector<int> pidsEstudiantes) { idsEstudiantes = pidsEstudiantes; }

	// Metodos
	bool existeEstudiante(int idEstudiante) { // Verifica si esta inscrito en el curso
		for (int i = 0; i < idsEstudiantes.size(); i++) {
			if (idsEstudiantes[i] == idEstudiante) {
				return true;
			}
		}
		return false;
	}

	bool agregarEstudiante(int idEstudiante) { // Agrega un estudiante al curso
		if (!existeEstudiante(idEstudiante)) {
			idsEstudiantes.push_back(idEstudiante);
			return true;
		}
		return false;
	}

	bool eliminarEstudiante(int idEstudiante) { // Elimina un estudiante del curso
		for (int i = 0; i < idsEstudiantes.size(); i++) {
			if (idsEstudiantes[i] == idEstudiante) {
				idsEstudiantes.erase(idsEstudiantes.begin() + i);
				return true;
			}
		}
		return false;
	}

	void mostrarCurso() {
		cout << "\n=== Informacion del curso ===\n";
		cout << "ID: " << idCurso << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "ID Profesor: " << idProfesor << endl;
		cout << "Cantidad de estudiantes: " << idsEstudiantes.size() << endl;
	}
};