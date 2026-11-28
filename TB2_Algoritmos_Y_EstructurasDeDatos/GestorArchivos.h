#pragma once
#include <fstream>
#include <string> 
#include <vector>
#include "Profesor.h"
#include "ProfesorBST.h"
#include "Curso.h"
#include "CursoAVL.h"
#include "Estudiante.h" 
#include "EstudianteHashTable.h"
#include "Modulo.h"
#include "ModuloAVL.h"
#include "Leccion.h"
#include "LeccionListaDoble.h"
#include "Ejercicio.h"
#include "EjercicioHashTable.h" 
#include "HistorialEjercicio.h" 
#include "HistorialEvaluacion.h"

using namespace std;

//para archivos de texto
const string ArchivoProfesores = "profesores.txt";
const string ArchivoCursos = "cursos.txt";
const string ArchivoEstudiantes = "estudiantes.txt";
const string ArchivoModulos = "modulos.txt";
const string ArchivoLecciones = "lecciones.txt";
const string ArchivoEjercicios = "ejercicios.txt";

//para archivos binarios
const string ArchivoProgreso = "progreso.dat";
const string ArchivoHistorialEjercicios = "historialEjercicios.dat";
const string ArchivoHistorialEvaluaciones = "historialEvaluaciones.dat";

struct RegistroProgreso {
    int idEstudiante;
    int progresoCurso;
    int progresoModulo;
    int progresoLeccion;
    int progresoEjercicio;
};

struct RegistroHistorialEjercicio {
    int idEstudiante;
    int idEjercicio;
};

struct RegistroHistorialEvaluacion {
    int idEstudiante;
    int idEvaluacion;
    int intentos;
};

class GestorArchivos {
private:
	//los saltos de linea se codifican como \n y las barras como \\ para que no se confundan con los saltos de linea reales
    string codificarTexto(string ptexto) {
        string resultado = "";
        for (size_t i = 0; i < ptexto.length(); i++) {
            if (ptexto[i] == '\n') {
                resultado += "\\n";
            }
            else if (ptexto[i] == '\\') {
                resultado += "\\\\";
            }
            else {
                resultado += ptexto[i];
            }
        }
        return resultado;
    }

    string decodificarTexto(string ptexto) {
        string resultado = "";
        size_t i = 0;
        while (i < ptexto.length()) {
            if (ptexto[i] == '\\' && i + 1 < ptexto.length()) {
                if (ptexto[i + 1] == 'n') {
                    resultado += '\n';
                }
                else {
                    resultado += ptexto[i + 1];
                }
                i += 2;
            }
            else {
                resultado += ptexto[i];
                i++;
            }
        }
        return resultado;
    }

    //lee una linea completa y la decodifica
    bool leerTexto(ifstream& parchivo, string& ptexto) {
        string linea;
        getline(parchivo, linea);
        if (!parchivo) {
            return false;
        }
        ptexto = decodificarTexto(linea);
        return true;
    }

    //descarta los saltos de linea despues de leer los numeros con >>
    void saltarResto(ifstream& parchivo) {
        string resto;
        getline(parchivo, resto);
    }

    bool existeArchivo(string pnombre) {
        ifstream archivo;
        archivo.open(pnombre.c_str(), ios::in);
        if (archivo.is_open()) {
            archivo.close();
            return true;
        }
        return false;
    }

    void escribirProfesores(ofstream& parchivo, NodoProfesor<Profesor>* pnodo) {
        if (pnodo == nullptr) {
            return;
        }
        Profesor& p = pnodo->dato;
        parchivo << p.getId() << " " << p.getIdCurso() << "\n";
        parchivo << codificarTexto(p.getNombre()) << "\n";
        parchivo << codificarTexto(p.getApellido()) << "\n";
        parchivo << codificarTexto(p.getCorreo()) << "\n";
        parchivo << codificarTexto(p.getContrasena()) << "\n";
        escribirProfesores(parchivo, pnodo->izquierda);
        escribirProfesores(parchivo, pnodo->derecha);
    }

    void escribirCursos(ofstream& parchivo, NodoCurso<Curso>* pnodo) {
        if (pnodo == nullptr) {
            return;
        }
        escribirCursos(parchivo, pnodo->izquierda);
        Curso& c = pnodo->dato;
        parchivo << c.getIdCurso() << " " << c.getIdProfesor() << "\n";
        parchivo << codificarTexto(c.getNombre()) << "\n";
        escribirCursos(parchivo, pnodo->derecha);
    }

    void escribirEstudiantesDeCursos(ofstream& parchivo, NodoCurso<Curso>* pnodo, EstudianteHashTable<Estudiante>& pestudiantes) {
        if (pnodo == nullptr) {
            return;
        }
        escribirEstudiantesDeCursos(parchivo, pnodo->izquierda, pestudiantes);
        const vector<int>& ids = pnodo->dato.getIdsEstudiantes();
        for (size_t i = 0; i < ids.size(); i++) {
            Estudiante* e = pestudiantes.getEstudiante(ids[i]);
            if (e != nullptr) {
                parchivo << e->getId() << " " << e->getIdProfesor() << " " << e->getIdCurso() << "\n";
                parchivo << codificarTexto(e->getNombre()) << "\n";
                parchivo << codificarTexto(e->getApellido()) << "\n";
                parchivo << codificarTexto(e->getCorreo()) << "\n";
                parchivo << codificarTexto(e->getContrasena()) << "\n";
            }
        }
        escribirEstudiantesDeCursos(parchivo, pnodo->derecha, pestudiantes);
    }

    void escribirModulos(ofstream& parchivo, NodoModulo<Modulo>* pnodo) {
        if (pnodo == nullptr) {
            return;
        }
        escribirModulos(parchivo, pnodo->izquierda);
        Modulo& m = pnodo->dato;
        Evaluacion& ev = m.getEvaluacion();
        parchivo << m.getIdModulo() << " " << m.getIdCurso() << " " << ev.getIdEvaluacion() << "\n";
        parchivo << codificarTexto(m.getNombre()) << "\n";
        parchivo << codificarTexto(ev.getPregunta1()) << "\n";
        parchivo << codificarTexto(ev.getPregunta2()) << "\n";
        parchivo << codificarTexto(ev.getRespuesta1()) << "\n";
        parchivo << codificarTexto(ev.getRespuesta2()) << "\n";
        escribirModulos(parchivo, pnodo->derecha);
    }

    //busca desde pinicio hasta el final, y si no lo encuentra, busca desde el principio hasta pinicio
    NodoLeccion<Leccion>* buscarNodoLeccion(LeccionListaDoble<Leccion>& plecciones, NodoLeccion<Leccion>* pinicio, int pidLeccion) {
        NodoLeccion<Leccion>* actual = pinicio;
        while (actual != nullptr) {
            if (actual->dato.getIdLeccion() == pidLeccion) {
                return actual;
            }
            actual = actual->siguiente;
        }
        actual = plecciones.getHead();
        while (actual != nullptr && actual != pinicio) {
            if (actual->dato.getIdLeccion() == pidLeccion) {
                return actual;
            }
            actual = actual->siguiente;
        }
        return nullptr;
    }

public:
    GestorArchivos() {}
    ~GestorArchivos() {}

	// ARCHIVOS DE TEXTO
    
    bool existeContenido() {
        return existeArchivo(ArchivoProfesores) && existeArchivo(ArchivoCursos) &&
            existeArchivo(ArchivoEstudiantes) && existeArchivo(ArchivoModulos) &&
            existeArchivo(ArchivoLecciones) && existeArchivo(ArchivoEjercicios);
    }

    // Guardar

    bool guardarProfesores(ProfesorBST<Profesor>& pprofesores) {
        ofstream archivo;
        archivo.open(ArchivoProfesores.c_str(), ios::out);
        if (!archivo.is_open()) {
            return false;
        }
        escribirProfesores(archivo, pprofesores.getRaiz());
        bool correcto = !(!archivo);
        archivo.close();
        return correcto;
    }

    bool guardarCursos(CursoAVL<Curso>& pcursos) {
        ofstream archivo;
        archivo.open(ArchivoCursos.c_str(), ios::out);
        if (!archivo.is_open()) {
            return false;
        }
        escribirCursos(archivo, pcursos.getRaiz());
        bool correcto = !(!archivo);
        archivo.close();
        return correcto;
    }

    bool guardarEstudiantes(CursoAVL<Curso>& pcursos, EstudianteHashTable<Estudiante>& pestudiantes) {
        ofstream archivo;
        archivo.open(ArchivoEstudiantes.c_str(), ios::out);
        if (!archivo.is_open()) {
            return false;
        }
        escribirEstudiantesDeCursos(archivo, pcursos.getRaiz(), pestudiantes);
        bool correcto = !(!archivo);
        archivo.close();
        return correcto;
    }

    bool guardarModulos(ModuloAVL<Modulo>& pmodulos) {
        ofstream archivo;
        archivo.open(ArchivoModulos.c_str(), ios::out);
        if (!archivo.is_open()) {
            return false;
        }
        escribirModulos(archivo, pmodulos.getRaiz());
        bool correcto = !(!archivo);
        archivo.close();
        return correcto;
    }

    bool guardarLecciones(LeccionListaDoble<Leccion>& plecciones) {
        ofstream archivo;
        archivo.open(ArchivoLecciones.c_str(), ios::out);
        if (!archivo.is_open()) {
            return false;
        }
        NodoLeccion<Leccion>* actual = plecciones.getHead();
        while (actual != nullptr) {
            Leccion& l = actual->dato;
            archivo << l.getIdLeccion() << " " << l.getIdModulo() << "\n";
            archivo << codificarTexto(l.getNombre()) << "\n";
            archivo << codificarTexto(l.getContenido()) << "\n";
            actual = actual->siguiente;
        }
        bool correcto = !(!archivo);
        archivo.close();
        return correcto;
    }

    bool guardarEjercicios(LeccionListaDoble<Leccion>& plecciones, EjercicioHashTable<Ejercicio>& pejercicios) {
        ofstream archivo;
        archivo.open(ArchivoEjercicios.c_str(), ios::out);
        if (!archivo.is_open()) {
            return false;
        }
        NodoLeccion<Leccion>* actual = plecciones.getHead();
        while (actual != nullptr) {
            const vector<int>& ids = actual->dato.getIdsEjercicios();
            for (size_t i = 0; i < ids.size(); i++) {
                Ejercicio* e = pejercicios.getEjercicio(ids[i]);
                if (e != nullptr) {
                    archivo << e->getIdEjercicio() << " " << e->getIdLeccion() << "\n";
                    archivo << codificarTexto(e->getEnunciado()) << "\n";
                    archivo << codificarTexto(e->getRespuesta()) << "\n";
                }
            }
            actual = actual->siguiente;
        }
        bool correcto = !(!archivo);
        archivo.close();
        return correcto;
    }

    bool guardarContenido(ProfesorBST<Profesor>& pprofesores, EstudianteHashTable<Estudiante>& pestudiantes,
        CursoAVL<Curso>& pcursos, ModuloAVL<Modulo>& pmodulos, LeccionListaDoble<Leccion>& plecciones,
        EjercicioHashTable<Ejercicio>& pejercicios) {
        bool correcto = true;
        correcto = guardarProfesores(pprofesores) && correcto;
        correcto = guardarCursos(pcursos) && correcto;
        correcto = guardarEstudiantes(pcursos, pestudiantes) && correcto;
        correcto = guardarModulos(pmodulos) && correcto;
        correcto = guardarLecciones(plecciones) && correcto;
        correcto = guardarEjercicios(plecciones, pejercicios) && correcto;
        return correcto;
    }

    // Cargar

	//caragan en el oden: profesores, cursos, estudiantes, modulos, lecciones, ejercicios porque dependen del anterior

    bool cargarProfesores(ProfesorBST<Profesor>& pprofesores) {
        ifstream archivo;
        archivo.open(ArchivoProfesores.c_str(), ios::in);
        if (!archivo.is_open()) {
            return false;
        }
        int id, idCurso;
        string nombre, apellido, correo, contrasena;
        bool completo = true;
        while (archivo >> id >> idCurso) {
            saltarResto(archivo);
            if (!leerTexto(archivo, nombre) || !leerTexto(archivo, apellido) ||
                !leerTexto(archivo, correo) || !leerTexto(archivo, contrasena)) {
                completo = false;
                break;
            }
            Profesor profesor(id, nombre, apellido, correo, contrasena, idCurso);
            pprofesores.insertar(profesor);
        }
        archivo.close();
        return completo;
    }

    bool cargarCursos(CursoAVL<Curso>& pcursos) {
        ifstream archivo;
        archivo.open(ArchivoCursos.c_str(), ios::in);
        if (!archivo.is_open()) {
            return false;
        }
        int idCurso, idProfesor;
        string nombre;
        bool completo = true;
        while (archivo >> idCurso >> idProfesor) {
            saltarResto(archivo);
            if (!leerTexto(archivo, nombre)) {
                completo = false;
                break;
            }
            Curso curso(idCurso, idProfesor, nombre);
            pcursos.insertar(curso);
        }
        archivo.close();
        return completo;
    }

    bool cargarEstudiantes(EstudianteHashTable<Estudiante>& pestudiantes, CursoAVL<Curso>& pcursos) {
        ifstream archivo;
        archivo.open(ArchivoEstudiantes.c_str(), ios::in);
        if (!archivo.is_open()) {
            return false;
        }
        int id, idProfesor, idCurso;
        string nombre, apellido, correo, contrasena;
        bool completo = true;
        while (archivo >> id >> idProfesor >> idCurso) {
            saltarResto(archivo);
            if (!leerTexto(archivo, nombre) || !leerTexto(archivo, apellido) ||
                !leerTexto(archivo, correo) || !leerTexto(archivo, contrasena)) {
                completo = false;
                break;
            }
            Estudiante estudiante(id, nombre, apellido, correo, contrasena, idProfesor, idCurso);
            if (pestudiantes.insertar(estudiante)) {
                Curso* curso = pcursos.getCurso(idCurso);
                if (curso != nullptr) {
                    curso->agregarEstudiante(id);
                }
            }
        }
        archivo.close();
        return completo;
    }

    bool cargarModulos(ModuloAVL<Modulo>& pmodulos, CursoAVL<Curso>& pcursos) {
        ifstream archivo;
        archivo.open(ArchivoModulos.c_str(), ios::in);
        if (!archivo.is_open()) {
            return false;
        }
        int idModulo, idCurso, idEvaluacion;
        string nombre, pregunta1, pregunta2, respuesta1, respuesta2;
        bool completo = true;
        while (archivo >> idModulo >> idCurso >> idEvaluacion) {
            saltarResto(archivo);
            if (!leerTexto(archivo, nombre) || !leerTexto(archivo, pregunta1) || !leerTexto(archivo, pregunta2) ||
                !leerTexto(archivo, respuesta1) || !leerTexto(archivo, respuesta2)) {
                completo = false;
                break;
            }
            Evaluacion evaluacion(idEvaluacion, idModulo, pregunta1, pregunta2, respuesta1, respuesta2);
            Modulo modulo(idModulo, idCurso, nombre, evaluacion);
            if (pmodulos.insertar(modulo)) {
                Curso* curso = pcursos.getCurso(idCurso);
                if (curso != nullptr) {
                    curso->agregarModulo(idModulo);
                }
            }
        }
        archivo.close();
        return completo;
    }

    bool cargarLecciones(LeccionListaDoble<Leccion>& plecciones, ModuloAVL<Modulo>& pmodulos) {
        ifstream archivo;
        archivo.open(ArchivoLecciones.c_str(), ios::in);
        if (!archivo.is_open()) {
            return false;
        }
        int idLeccion, idModulo;
        string nombre, contenido;
        bool completo = true;
        while (archivo >> idLeccion >> idModulo) {
            saltarResto(archivo);
            if (!leerTexto(archivo, nombre) || !leerTexto(archivo, contenido)) {
                completo = false;
                break;
            }
            Leccion leccion(idLeccion, idModulo, nombre, contenido);
            plecciones.insertar(leccion);
            Modulo* modulo = pmodulos.getModulo(idModulo);
            if (modulo != nullptr) {
                modulo->agregarLeccion(idLeccion);
            }
        }
        archivo.close();
        return completo;
    }

    bool cargarEjercicios(EjercicioHashTable<Ejercicio>& pejercicios, LeccionListaDoble<Leccion>& plecciones) {
        ifstream archivo;
        archivo.open(ArchivoEjercicios.c_str(), ios::in);
        if (!archivo.is_open()) {
            return false;
        }
        int idEjercicio, idLeccion;
        string enunciado, respuesta;
        bool completo = true;
        NodoLeccion<Leccion>* nodoActual = plecciones.getHead();
        while (archivo >> idEjercicio >> idLeccion) {
            saltarResto(archivo);
            if (!leerTexto(archivo, enunciado) || !leerTexto(archivo, respuesta)) {
                completo = false;
                break;
            }
            Ejercicio ejercicio(idEjercicio, idLeccion, enunciado, respuesta);
            if (pejercicios.insertar(ejercicio)) {
                NodoLeccion<Leccion>* nodo = buscarNodoLeccion(plecciones, nodoActual, idLeccion);
                if (nodo != nullptr) {
                    nodo->dato.agregarEjercicio(idEjercicio);
                    nodoActual = nodo;
                }
            }
        }
        archivo.close();
        return completo;
    }

    bool cargarContenido(ProfesorBST<Profesor>& pprofesores, EstudianteHashTable<Estudiante>& pestudiantes,
        CursoAVL<Curso>& pcursos, ModuloAVL<Modulo>& pmodulos, LeccionListaDoble<Leccion>& plecciones,
        EjercicioHashTable<Ejercicio>& pejercicios) {
        return cargarProfesores(pprofesores) &&
            cargarCursos(pcursos) &&
            cargarEstudiantes(pestudiantes, pcursos) &&
            cargarModulos(pmodulos, pcursos) &&
            cargarLecciones(plecciones, pmodulos) &&
            cargarEjercicios(pejercicios, plecciones);
    }

	// ARCHIVOS BINARIOS

    // Progreso

    bool guardarProgresos(const vector<RegistroProgreso>& pregistros) {
        ofstream archivo;
        archivo.open(ArchivoProgreso.c_str(), ios::out | ios::binary);
        if (!archivo.is_open()) {
            return false;
        }
        for (size_t i = 0; i < pregistros.size(); i++) {
            RegistroProgreso registro = pregistros[i];
            archivo.write((char*)&registro, sizeof(RegistroProgreso));
        }
        bool correcto = !(!archivo);
        archivo.close();
        return correcto;
    }

    bool cargarProgresos(vector<RegistroProgreso>& pregistros) {
        ifstream archivo;
        archivo.open(ArchivoProgreso.c_str(), ios::in | ios::binary);
        if (!archivo.is_open()) {
            return false;
        }
        RegistroProgreso registro;
        while (archivo.read((char*)&registro, sizeof(RegistroProgreso))) {
            pregistros.push_back(registro);
        }
        archivo.close();
        return true;
    }

    bool guardarProgreso(int pidEstudiante, int pprogresoCurso, int pprogresoModulo, int pprogresoLeccion, int pprogresoEjercicio) {
        RegistroProgreso nuevo;
        nuevo.idEstudiante = pidEstudiante;
        nuevo.progresoCurso = pprogresoCurso;
        nuevo.progresoModulo = pprogresoModulo;
        nuevo.progresoLeccion = pprogresoLeccion;
        nuevo.progresoEjercicio = pprogresoEjercicio;

        fstream archivo;
        archivo.open(ArchivoProgreso.c_str(), ios::in | ios::out | ios::binary);
        if (archivo.is_open()) {
            RegistroProgreso registro;
            int posicion = 0;
            while (archivo.read((char*)&registro, sizeof(RegistroProgreso))) {
                if (registro.idEstudiante == pidEstudiante) {
                    archivo.seekp(posicion * sizeof(RegistroProgreso), ios::beg);
                    archivo.write((char*)&nuevo, sizeof(RegistroProgreso));
                    bool correcto = !(!archivo);
                    archivo.close();
                    return correcto;
                }
                posicion++;
            }
            archivo.close();
        }

        ofstream salida;
        salida.open(ArchivoProgreso.c_str(), ios::out | ios::app | ios::binary);
        if (!salida.is_open()) {
            return false;
        }
        salida.write((char*)&nuevo, sizeof(RegistroProgreso));
        bool correcto = !(!salida);
        salida.close();
        return correcto;
    }

    bool cargarProgreso(int pidEstudiante, RegistroProgreso& pregistro) {
        ifstream archivo;
        archivo.open(ArchivoProgreso.c_str(), ios::in | ios::binary);
        if (!archivo.is_open()) {
            return false;
        }
        RegistroProgreso registro;
        while (archivo.read((char*)&registro, sizeof(RegistroProgreso))) {
            if (registro.idEstudiante == pidEstudiante) {
                pregistro = registro;
                archivo.close();
                return true;
            }
        }
        archivo.close();
        return false;
    }

    // Historial de ejercicios

    bool agregarEjercicioCompletado(int pidEstudiante, int pidEjercicio) {
        ofstream archivo;
        archivo.open(ArchivoHistorialEjercicios.c_str(), ios::out | ios::app | ios::binary);
        if (!archivo.is_open()) {
            return false;
        }
        RegistroHistorialEjercicio registro;
        registro.idEstudiante = pidEstudiante;
        registro.idEjercicio = pidEjercicio;
        archivo.write((char*)&registro, sizeof(RegistroHistorialEjercicio));
        bool correcto = !(!archivo);
        archivo.close();
        return correcto;
    }

    bool cargarHistorialEjercicio(int pidEstudiante, HistorialEjercicio& phistorial) {
        ifstream archivo;
        archivo.open(ArchivoHistorialEjercicios.c_str(), ios::in | ios::binary);
        if (!archivo.is_open()) {
            return false;
        }
        RegistroHistorialEjercicio registro;
        while (archivo.read((char*)&registro, sizeof(RegistroHistorialEjercicio))) {
            if (registro.idEstudiante == pidEstudiante) {
                phistorial.agregar(registro.idEjercicio);
            }
        }
        archivo.close();
        return true;
    }

    // Historial de evaluaciones

    bool registrarIntentoEvaluacion(int pidEstudiante, int pidEvaluacion, int pintentos = 1) {
        if (pintentos <= 0) {
            return false;
        }
        fstream archivo;
        archivo.open(ArchivoHistorialEvaluaciones.c_str(), ios::in | ios::out | ios::binary);
        if (archivo.is_open()) {
            RegistroHistorialEvaluacion registro;
            int posicion = 0;
            while (archivo.read((char*)&registro, sizeof(RegistroHistorialEvaluacion))) {
                if (registro.idEstudiante == pidEstudiante && registro.idEvaluacion == pidEvaluacion) {
                    registro.intentos += pintentos;
                    archivo.seekp(posicion * sizeof(RegistroHistorialEvaluacion), ios::beg);
                    archivo.write((char*)&registro, sizeof(RegistroHistorialEvaluacion));
                    bool correcto = !(!archivo);
                    archivo.close();
                    return correcto;
                }
                posicion++;
            }
            archivo.close();
        }

        ofstream salida;
        salida.open(ArchivoHistorialEvaluaciones.c_str(), ios::out | ios::app | ios::binary);
        if (!salida.is_open()) {
            return false;
        }
        RegistroHistorialEvaluacion nuevo;
        nuevo.idEstudiante = pidEstudiante;
        nuevo.idEvaluacion = pidEvaluacion;
        nuevo.intentos = pintentos;
        salida.write((char*)&nuevo, sizeof(RegistroHistorialEvaluacion));
        bool correcto = !(!salida);
        salida.close();
        return correcto;
    }

    bool cargarHistorialEvaluacion(int pidEstudiante, HistorialEvaluacion& phistorial) {
        ifstream archivo;
        archivo.open(ArchivoHistorialEvaluaciones.c_str(), ios::in | ios::binary);
        if (!archivo.is_open()) {
            return false;
        }
        RegistroHistorialEvaluacion registro;
        while (archivo.read((char*)&registro, sizeof(RegistroHistorialEvaluacion))) {
            if (registro.idEstudiante == pidEstudiante) {
                phistorial.registrar(registro.idEvaluacion, registro.intentos);
            }
        }
        archivo.close();
        return true;
    }
};