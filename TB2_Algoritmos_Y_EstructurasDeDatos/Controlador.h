#pragma once
#include "Generador.h"
#include "Pantallas.h"

class Controlador
{
private:
	bool corriendo;
	Estudiante* estudiante;
	Profesor* profesor;
	Curso curso;
	Evaluacion evaluacion;
	ProfesorBST<Profesor> profesoresEstructura;
	EstudianteHashTable<Estudiante> estudiantesEstructura;
	CursoAVL<Curso> cursosEstructura;
	ModuloAVL<Modulo> modulosEstructura;
	LeccionListaDoble<Leccion> leccionesEstructura;
	EjercicioHashTable<Ejercicio> ejerciciosEstructura;
	EstudianteGestor gestor;
public:
	Controlador() {
		corriendo = true;
		estudiante = nullptr;
		profesor = nullptr;
	}
	~Controlador() {

	}
	void cargarDatos() {
		generarTodo(profesoresEstructura, estudiantesEstructura, cursosEstructura, modulosEstructura, leccionesEstructura, ejerciciosEstructura);
	}
	void profesorLogica() {
		int op;
		int idCurso = profesor->getIdCurso();
		vector<int> estu = cursosEstructura.getCurso(idCurso)->getIdsEstudiantes();
		EstudianteGestor gestor(estu, &estudiantesEstructura);
		do {
			op = pantallaProfesor(profesor->getNombre());
			switch (op)
			{
			case 1: {
				gestor.listarEstudiantes();
				pausarPantalla();
				break;
			}
			case 2: { // IMPLEMENTAR
				cout << "Por implementar..." << endl;
				pausarPantalla();
				break;
			}
			case 3: { // IMPLEMENTAR
				cout << "Por implementar..." << endl;
				pausarPantalla();
				break;
			}
			case 4: {
				int idBuscado;
				cout << "Ingrese el ID del estudiante a buscar: ";
				cin >> idBuscado;
				gestor.buscarEstudiante(idBuscado);
				pausarPantalla();
				break;
			}
			case 5: {
				gestor.mayorProgreso();
				pausarPantalla();
				break;
			}
			case 6: {
				gestor.menorProgreso();
				pausarPantalla();
				break;
			}
			case 7: {
				gestor.ordenarProgreso();
				pausarPantalla();
				break;
			}
			case 8: {
				gestor.ordenarID();
				pausarPantalla();
				break;
			}
			case 9: {
				gestor.ordenarNombre();
				pausarPantalla();
				break;
			}
			case 10: {
				cursosEstructura.getCurso(idCurso)->mostrarCurso();
				pausarPantalla();
				break;
			}
			case 11: {
				pantallaCierreSesion();
				pausarPantalla();
			}
			default:
				break;
			}
		} while (op != 11);
	}
	void programa() {
		cargarDatos();
		int op;
		int id;
		auto esProfesor = [](int id) { return id >= PROFESOR_BASE && id <= PROFESOR_LIMITE; };
		auto esEstudiante = [](int id) { return id >= ESTUDIANTE_BASE && id <= ESTUDIANTE_LIMITE; };
		op = pantallaInicio();
		if (op == 1) {
			id = pantallaInicioSesion();
			if (esProfesor(id)) {
				//Buscar profesor
				profesor = profesoresEstructura.getProfesor(id);
				if (profesor == nullptr) {
					cout << "NO se encontro el ID. Intentelo de nuevo" << endl;
				}
				else {
					profesorLogica();
				}
			}
			else if (esEstudiante(id)) {
				//Buscar estudiante
				estudiante = estudiantesEstructura.getEstudiante(id);
				if (estudiante == nullptr) {
					cout << "NO se encontro el ID. Intentelo de nuevo" << endl;
				}
			}
			else {
				cout << "ID invalido. Intentelo de nuevo" << endl;
			}
		}
		else {
			pantallaCierreSesion();
			corriendo = false;
		}

	}
};