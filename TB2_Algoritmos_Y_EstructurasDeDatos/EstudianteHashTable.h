#pragma once
#include "Estudiante.h"
#include <string>
#include <iostream>
using namespace std;

// se espera insertar 5000 estudiantes
// en el caso de insertar mas estudiantes se utiliza el numero primo mas cercano a la cantidad * 2
const int TAM_ESTUDIANTES = 10007;
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
		return 9973 - (clave % 9973);
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
	void insertar(T dato) {
		int clave = dato.getId();
		int hashInicial = funcionHash(clave);
		int salto = funcionHash2(clave);

		if (cantidad >= TAM_ESTUDIANTES) {
			cout << "ERROR: No se puede insertar mas estudiantes\n";
			return;
		}
		if (duplicado(clave)) {
			cout << "ERROR: El estudiante ya existe\n";
			return;
		}

		for (int i = 0; i < TAM_ESTUDIANTES; i++) {
			int posicion = calcularPosicion(hashInicial, salto, i);

			if (tabla[posicion].estado == VACIA || tabla[posicion].estado == ELIMINADA) {
				tabla[posicion].dato = dato;
				tabla[posicion].estado = OCUPADA;
				cantidad++;
				cout << "Estudiante insertado correctamente\n";
				return;
			}

			colisiones++;
		}
		cout << "No se pudo insertar " << clave << endl;
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
};