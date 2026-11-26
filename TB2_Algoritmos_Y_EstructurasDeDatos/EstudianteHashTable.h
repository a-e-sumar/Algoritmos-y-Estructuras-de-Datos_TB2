#pragma once
#include "Estudiante.h"
#include <string>
#include <iostream>
using namespace std;

// se espera insertar 4000 estudiantes
// en el caso de que se inserten mas estudiantes se utiliza un numero primo 500 + cantidad
const int TAM_ESTUDIANTES = 4507;
const int VACIA = 0;
const int OCUPADA = 1;
const int ELIMINADA = 2;

template<typename T>
struct HashEntidad {
	T dato;
	int estado;

	HashEntidad() {
		estado = VACIA;
	}
};

template<typename T>
class EstudianteHashTable
{
private:
	HashEntidad<T> tabla[TAM_ESTUDIANTES];
	int cantidad;
	int colisiones;

	int funcionHash(int clave) {
		return clave % TAM_ESTUDIANTES;
	}
	int funcionHash2(int clave) {
		return 5483 - (clave % 4483);
	}
	int calcularPosicion(int hashInicial, int salto, int colisiones) {
		return (hashInicial + colisiones * salto) % TAM_ESTUDIANTES;
	}

public:
	EstudianteHashTable() {
		cantidad = 0;
		colisiones = 0;
	}

	~EstudianteHashTable() { }

	// Getters
	int getCantidad() { return cantidad; }
	int getColisiones() { return colisiones; }
	int getCapacidad() { return TAM_ESTUDIANTES; }

	// Metodos
	bool insertar(T dato) {
		int clave = dato.getId();
		int hashInicial = funcionHash(clave);
		int salto = funcionHash2(clave);

		if (cantidad >= TAM_ESTUDIANTES) {
			cout << "ERROR: No se puede insertar mas estudiantes\n";
			return false;
		}
		if (duplicado(clave)) {
			cout << "ERROR: El estudiante ya existe\n";
			return false;
		}

		for (int i = 0; i < TAM_ESTUDIANTES; i++) {
			int posicion = calcularPosicion(hashInicial, salto, i);

			if (tabla[posicion].estado == VACIA || tabla[posicion].estado == ELIMINADA) {
				tabla[posicion].dato = dato;
				tabla[posicion].estado = OCUPADA;
				cantidad++;
				cout << "Estudiante insertado correctamente\n";
				return true;
			}

			colisiones++;
		}
		cout << "No se pudo insertar " << clave << endl;
		return false;
	}
	int buscar(int clave) {
		int hashInicial = funcionHash(clave);
		int salto = funcionHash2(clave);

		for (int i = 0; i < TAM_ESTUDIANTES; i++) {
			int posicion = calcularPosicion(hashInicial, salto, i);
			if (tabla[posicion].estado == VACIA) {
				return -1;
			}
			if (tabla[posicion].estado == OCUPADA && tabla[posicion].dato.getId() == clave) {
				return posicion;
			}
		}
		return -1;
	}
	void eliminar(int clave) {
		int posicion = buscar(clave);
		if (posicion == -1) {
			cout << "El estudiante no existe\nNo se puedo eliminar\n";
		}
		else {
			tabla[posicion].estado = ELIMINADA;
			cantidad--;
			cout << "Estudiante eliminado correctamente\n";
		}
	}
	T* getEstudiante(int clave) {
		int posicion = buscar(clave);
		if (posicion == -1) {
			cout << "El estudiante no existe\n";
			return nullptr;
		}
		return &tabla[posicion].dato;
	}
	bool duplicado(int clave) {
		return buscar(clave) != -1;
	}
	void mostrar() {
		cout << "\n\t\t\t=== Estudiantes ===\n";
		cout << "\nPosicion\tEstado\t\tNombre\t\t\tId" << endl;
		for (int i = 0; i < TAM_ESTUDIANTES; i++)
		{
			cout << i << ".\t\t";
			if (tabla[i].estado == 1) {
				cout << "Ocupado\t\t";
			}
			else {
				cout << "Vacio\t\t";
			}
			cout << tabla[i].dato.getNombre() << " " << tabla[i].dato.getApellido() << "\t\t" << tabla[i].dato.getId();
			cout << endl;
		}
	}
};