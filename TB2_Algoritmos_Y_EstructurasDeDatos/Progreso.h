#pragma once
#include <string>
#include <iostream>
using namespace std;

class Progreso
{
private:
	int idEstudiante;
	int progresoCurso;
	int progresoModulo;
	int progresoLeccion;
	int progresoEjercicio;
	// Poner HistorialEjercicio
	// Poner HistorialEvaluacion

public:
	Progreso() {
		idEstudiante = 0;
		progresoCurso = 0;
		progresoModulo = 0;
		progresoLeccion = 0;
		progresoEjercicio = 0;
	}

	// Los progresos se reciben directamente porque todavia no estan los historiales
	// CAMBIAR
	Progreso(int pidEstudiante, int pprogresoCurso, int pprogresoModulo, int pprogresoLeccion, int pprogresoEjercicio) {

		idEstudiante = pidEstudiante;
		progresoCurso = pprogresoCurso;
		progresoModulo = pprogresoModulo;
		progresoLeccion = pprogresoLeccion;
		progresoEjercicio = pprogresoEjercicio;
	}
	~Progreso() {

	}

	// Getters
	int getProgresoCurso() { return progresoCurso; }
	int getProgresoModulo() { return progresoModulo; }
	int getProgresoLeccion() { return progresoLeccion; }
	int getProgresoEjercicio() { return progresoEjercicio; }

	// Setters
	// Se calculan con los historiales
	// progresoEjercicio = Ejercicios completados
	// progresoLeccion = (Ejercicios Completados / Ejercicios Totales) * 100
	// progresoModulo = (Lecciones Completados / Lecciones Totales) * 100
	// progresoCurso = (Evaluaciones Completadas / Evaluaciones Totales) * 100 -> modulo se completa al completar su evaluacion 

	// CAMBIAR
	void setProgresoCurso(int pprogresoCurso) { progresoCurso = pprogresoCurso; }
	void setProgresoModulo(int pprogresoModulo) { progresoModulo = pprogresoModulo; }
	void setProgresoLeccion(int pprogresoLeccion) { progresoLeccion = pprogresoLeccion; }
	void setProgresoEjercicio(int pprogresoEjercicio) { progresoEjercicio = pprogresoEjercicio; }
};