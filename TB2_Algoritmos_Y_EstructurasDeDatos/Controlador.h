#pragma once
#include "Generador.h"
#include "Pantallas.h"
#include "GestorArchivos.h"

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
	GestorArchivos gestorArchivos;
public:
	Controlador() {
		corriendo = true;
		estudiante = nullptr;
		profesor = nullptr;
	}
	~Controlador() {

	}

	//PROVISONAL (usa Progreso como esta ahora)
	void guardarProgresoEstudiantes() {
		vector<RegistroProgreso> registros;
		for (int id = ESTUDIANTE_BASE; id <= ESTUDIANTE_LIMITE; id++) {
			Estudiante* e = estudiantesEstructura.getEstudiante(id);
			if (e != nullptr) {
				RegistroProgreso registro;
				registro.idEstudiante = id;
				registro.progresoCurso = e->getProgreso().getProgresoCurso();
				registro.progresoModulo = e->getProgreso().getProgresoModulo();
				registro.progresoLeccion = e->getProgreso().getProgresoLeccion();
				registro.progresoEjercicio = e->getProgreso().getProgresoEjercicio();
				registros.push_back(registro);
			}
		}
		gestorArchivos.guardarProgresos(registros);
	}

	//PROVISONAL x2

	void cargarProgresoEstudiantes() {
		vector<RegistroProgreso> registros;
		if (!gestorArchivos.cargarProgresos(registros)) {
			return;
		}
		for (size_t i = 0; i < registros.size(); i++) {
			Estudiante* e = estudiantesEstructura.getEstudiante(registros[i].idEstudiante);
			if (e != nullptr) {
				e->getProgreso().setProgresoCurso(registros[i].progresoCurso);
				e->getProgreso().setProgresoModulo(registros[i].progresoModulo);
				e->getProgreso().setProgresoLeccion(registros[i].progresoLeccion);
				e->getProgreso().setProgresoEjercicio(registros[i].progresoEjercicio);
			}
		}
	}

	void cargarDatos() {
		if (gestorArchivos.existeContenido()) {
			gestorArchivos.cargarContenido(profesoresEstructura, estudiantesEstructura, cursosEstructura, modulosEstructura, leccionesEstructura, ejerciciosEstructura);
			cargarProgresoEstudiantes();
		}
		else {
			generarTodo(profesoresEstructura, estudiantesEstructura, cursosEstructura, modulosEstructura, leccionesEstructura, ejerciciosEstructura);
			gestorArchivos.guardarContenido(profesoresEstructura, estudiantesEstructura, cursosEstructura, modulosEstructura, leccionesEstructura, ejerciciosEstructura);
			guardarProgresoEstudiantes();
		}
	}
	void adminLogica() {
		int op;
		do {
			op = pantallaAdmin();
			switch (op)
			{
			case 1:
			{
				estudiantesEstructura.mostrar();
				pausarPantalla();
				break;
			}
			case 2:
			{
				profesoresEstructura.mostrar();
				pausarPantalla();
				break;
			}
			case 3:
			{
				cursosEstructura.listarCursos();
				pausarPantalla();
				break;
			}
			case 4:
			{
				modulosEstructura.listarModulos();
				pausarPantalla();
				break;
			}
			case 5:
			{
				leccionesEstructura.mostrar();
				pausarPantalla();
				break;
			}
			case 6:
			{
				pantallaCierreSesion();
			}
			default:
				break;
			}
		} while (op != 6);
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
			}
			default:
				break;
			}
		} while (op != 11);
	}
	void programa() {
		cargarDatos();
		// Descomentar pause para ver si hay advertencias del generador
		// pausarPantalla();
		int op;
		int id;
		auto esProfesor = [](int id) { return id >= PROFESOR_BASE && id <= PROFESOR_LIMITE; };
		auto esEstudiante = [](int id) { return id >= ESTUDIANTE_BASE && id <= ESTUDIANTE_LIMITE; };
		do {
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
				else if (id == 1) {
					adminLogica();
				}
				else {
					cout << "ID invalido. Intentelo de nuevo" << endl;
				}
			}
			else {
				pantallaCierreSesion();
				corriendo = false;
			}
		} while (op != 2);
	}
};