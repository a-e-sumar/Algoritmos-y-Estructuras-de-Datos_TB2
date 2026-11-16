#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "EstudianteHashTable.h"
#include "Estudiante.h"
#include "Curso.h"

// Implementar agregar y eliminar estudiante despues de finalizar Curso.h
class EstudianteGestor
{
private:
	vector<Estudiante> estudiantes;
    bool ordenadoID;

    int binarySearch(int buscado) {
        int inicio = 0;
        int fin = estudiantes.size() - 1;
        int posicion = -1;

        while (inicio <= fin) {
            int medio = inicio + (fin - inicio) / 2;

            if (estudiantes[medio].getId() == buscado) {
                posicion = medio;
                break;
            }
            else if (buscado < estudiantes[medio].getId()) {
                fin = medio - 1;
            }
            else {
                inicio = medio + 1;
            }
        }
        return posicion;
    }
    void merge(vector<Estudiante>& lista, int inicio, int medio, int fin) {
        int izquierda = inicio;
        int derecha = medio + 1;
        int posicion = 0;

        vector<Estudiante> temporal(fin - inicio + 1);

        while (izquierda <= medio && derecha <= fin) {
            if (lista[izquierda].getProgreso().getProgresoCurso() >= lista[derecha].getProgreso().getProgresoCurso()) {
                temporal[posicion] = lista[izquierda];
                izquierda++;
            }
            else {
                temporal[posicion] = lista[derecha];
                derecha++;
            }
            posicion++;
        }

        while (izquierda <= medio) {
            temporal[posicion] = lista[izquierda];
            izquierda++;
            posicion++;
        }

        while (derecha <= fin) {
            temporal[posicion] = lista[derecha];
            derecha++;
            posicion++;
        }

        for (int i = 0; i < posicion; i++) {
            lista[inicio + i] = temporal[i];
        }
    }
    void mergeSort(vector<Estudiante>& lista, int inicio, int fin) {
        if (inicio >= fin)
            return;

        int medio = inicio + (fin - inicio) / 2;

        mergeSort(lista, inicio, medio);
        mergeSort(lista, medio + 1, fin);

        merge(lista, inicio, medio, fin);
    }

    void heapSort() { } // Implementar ordenamiento por ID ascendente
    void quickSort(int inicio, int fin) { } // Implementar ordenamiento por nombre

    void liberar() {
        estudiantes.clear();
        ordenadoID = false;
    }

public:
    EstudianteGestor() {
        ordenadoID = false;
    }
    EstudianteGestor(const vector<int>& idsEstudiantes, EstudianteHashTable<Estudiante>& tabla) {
        ordenadoID = false;

        for (size_t i = 0; i < idsEstudiantes.size(); i++) {
            Estudiante* estudiante = tabla.getEstudiante(idsEstudiantes[i]);

            if (estudiante != nullptr) {
                estudiantes.push_back(*estudiante);
            }
        }
    }

	~EstudianteGestor() {
        liberar();
	}

    // Metodos
    void listarEstudiantes() {
        cout << "\n\t\t=== Estudiantes ===\n";
        cout << "#\tId\tNombre\tProgreso\n";
        cout << "------------------------------------------------\n";

        for (size_t i = 0; i < estudiantes.size(); i++) {
            cout << i << ".\t" << estudiantes[i].getId() << "\t"
                << estudiantes[i].getNombre() << " " << estudiantes[i].getApellido() << "\t"
                << estudiantes[i].getProgreso().getProgresoCurso() << "%" << endl;
        }
        cout << endl;
    }
    void buscarEstudiante(int idBuscado) {
        if (!ordenadoID) {
            heapSort();
        }

        int posicion = binarySearch(idBuscado);

        if (posicion == -1) {
            cout << "No se encontro estudiante con ID " << idBuscado << endl;
        }
        else {
            estudiantes[posicion].mostrarEstudiante();
        }
    }
    void mayorProgreso() {
        auto compararMayor = [](Estudiante& a, Estudiante& b) {
            return a.getProgreso().getProgresoCurso() > b.getProgreso().getProgresoCurso();
            };

        int indiceMayor = 0;
        for (size_t i = 1; i < estudiantes.size(); i++) {
            if (compararMayor(estudiantes[i], estudiantes[indiceMayor])) {
                indiceMayor = (int)i;
            }
        }

        cout << "\n=== Estudiante con MAYOR progreso ===\n";
        estudiantes[indiceMayor].mostrarEstudiante();
    }
    void menorProgreso() {
        auto compararMenor = [](Estudiante& a, Estudiante& b) {
            return a.getProgreso().getProgresoCurso() < b.getProgreso().getProgresoCurso();
            };

        int indiceMenor = 0;
        for (size_t i = 1; i < estudiantes.size(); i++) {
            if (compararMenor(estudiantes[i], estudiantes[indiceMenor])) {
                indiceMenor = (int)i;
            }
        }

        cout << "\n=== Estudiante con MENOR progreso ===\n";
        estudiantes[indiceMenor].mostrarEstudiante();
    }
    void ordenarProgreso() {
        if (estudiantes.size() <= 1) {
            cout << "No hay suficientes estudiantes para ordenar\n";
            return;
        }

        mergeSort(estudiantes, 0, (int)estudiantes.size() - 1);
        ordenadoID = false;
        cout << "\n=== Estudiantes ordenados por progreso ===\n";
        listarEstudiantes();
    }
    void ordenarID() { }
    void ordenarNombre() { }


};


