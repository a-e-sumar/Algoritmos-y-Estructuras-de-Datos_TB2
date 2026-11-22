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
	vector<int> idsEstudiantes; //guarda id de estudiantes inscritos en el curso
	vector<int> idsModulos; //guarda id de modulos del curso (los modulos viven en el ModuloAVL global)

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

	Curso(int pidCurso, int pidProfesor, string pnombre, vector<int> pidsEstudiantes, vector<int> pidsModulos) {
		idCurso = pidCurso;
		idProfesor = pidProfesor;
		nombre = pnombre;
		idsEstudiantes = pidsEstudiantes;
		idsModulos = pidsModulos;
	}

	// Getters
	int getIdCurso() { return idCurso; }
	int getIdProfesor() { return idProfesor; }
	string getNombre() { return nombre; }
	const vector<int>& getIdsEstudiantes() { return idsEstudiantes; }
	int getCantidadEstudiantes() { return (int)idsEstudiantes.size(); }
	const vector<int>& getIdsModulos() { return idsModulos; }
	int getCantidadModulos() { return (int)idsModulos.size(); }

	// Setters
	void setIdCurso(int pidCurso) { idCurso = pidCurso; }
	void setIdProfesor(int pidProfesor) { idProfesor = pidProfesor; }
	void setNombre(string pnombre) { nombre = pnombre; }
	void setIdsEstudiantes(vector<int> pidsEstudiantes) { idsEstudiantes = pidsEstudiantes; }
	void setIdsModulos(vector<int> pidsModulos) { idsModulos = pidsModulos; }

	// Metodos
	bool existeEstudiante(int idEstudiante) { // Verifica si esta inscrito en el curso
		for (size_t i = 0; i < idsEstudiantes.size(); i++) {
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
		for (size_t i = 0; i < idsEstudiantes.size(); i++) {
			if (idsEstudiantes[i] == idEstudiante) {
				idsEstudiantes.erase(idsEstudiantes.begin() + i);
				return true;
			}
		}
		return false;
	}

	bool existeModulo(int idModulo) { // Verifica si el modulo pertenece al curso
		for (size_t i = 0; i < idsModulos.size(); i++) {
			if (idsModulos[i] == idModulo) {
				return true;
			}
		}
		return false;
	}

	//solo se usa para cargar o generar datos, los profesores NO modifican el contenido
	bool agregarModulo(int idModulo) { // Agrega el id de un modulo al curso
		if (!existeModulo(idModulo)) {
			idsModulos.push_back(idModulo);
			return true;
		}
		return false;
	}

	bool eliminarModulo(int idModulo) { // Elimina el id de un modulo del curso
		for (size_t i = 0; i < idsModulos.size(); i++) {
			if (idsModulos[i] == idModulo) {
				idsModulos.erase(idsModulos.begin() + i);
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
		cout << "Cantidad de modulos: " << idsModulos.size() << endl;
	}
};