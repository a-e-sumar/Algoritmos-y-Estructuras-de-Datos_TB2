#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Modulo.h"
#include "ModuloAVL.h"
using namespace std;

class Curso
{
private:
	int idCurso;
	int idProfesor;
	string nombre;
	vector<int> idsEstudiantes; //guarda id de estudiantes inscritos en el curso
	ModuloAVL<Modulo> modulos; //modulos del curso por su id

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
	ModuloAVL<Modulo>& getModulos() { return modulos; }
	Modulo* getModulo(int idModulo) { return modulos.getModulo(idModulo); }
	int getCantidadModulos() { return modulos.contarModulos(); }

	// Setters
	void setIdCurso(int pidCurso) { idCurso = pidCurso; }
	void setIdProfesor(int pidProfesor) { idProfesor = pidProfesor; }
	void setNombre(string pnombre) { nombre = pnombre; }
	void setIdsEstudiantes(vector<int> pidsEstudiantes) { idsEstudiantes = pidsEstudiantes; }

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
		return modulos.getModulo(idModulo) != nullptr;
	}

	//solo se usa para cargar o generar datos, los profesores NO modifican el contenido
	bool agregarModulo(Modulo modulo) { // Agrega un modulo al curso
		if (modulo.getIdCurso() != idCurso) {
			return false;
		}
		return modulos.insertar(modulo);
	}

	bool eliminarModulo(int idModulo) { // Elimina un modulo del curso
		return modulos.eliminar(idModulo);
	}

	void mostrarCurso() {
		cout << "\n=== Informacion del curso ===\n";
		cout << "ID: " << idCurso << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "ID Profesor: " << idProfesor << endl;
		cout << "Cantidad de estudiantes: " << idsEstudiantes.size() << endl;
		cout << "Cantidad de modulos: " << modulos.contarModulos() << endl;
	}
};