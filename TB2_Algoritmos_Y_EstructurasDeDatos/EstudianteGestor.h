#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

    void heapify(vector<Estudiante>& lista, int n, int indicePadre)
    {
        int mayor = indicePadre;
        int izquierdo = 2 * indicePadre + 1;
        int derecho = 2 * indicePadre + 2;
        if (izquierdo < n && lista[izquierdo].getId() > lista[mayor].getId()) {
            mayor = izquierdo;
        }
        if (derecho < n && lista[derecho].getId() > lista[mayor].getId()) {
            mayor = derecho;
        }
        if (mayor != indicePadre) {
            swap(lista[indicePadre], lista[mayor]);
            heapify(lista, n, mayor);
        }
    }
    void heapSort(vector<Estudiante>& lista, int n)
    {
        // 1. Construir Max-Heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(lista, n, i);
        }

        // 2. Extraer elementos uno por uno
        for (int i = n - 1; i > 0; i--) {
            // Mover el máximo al final
            swap(lista[0], lista[i]);
            // Reconstruir el Heap
            heapify(lista, i, 0);
        }
    }

    string aMinuscula(string texto) {
        for (size_t i = 0; i < texto.size(); i++) {
            texto[i] = (char)tolower((unsigned char)texto[i]);
        }
        return texto;
    }

    // primero por nombre, si empatan por apellido y luego por id
    bool nombreMenorIgual(Estudiante& a, Estudiante& b) {
        string nombreA = aMinuscula(a.getNombre());
        string nombreB = aMinuscula(b.getNombre());
        if (nombreA != nombreB) return nombreA < nombreB;

        string apellidoA = aMinuscula(a.getApellido());
        string apellidoB = aMinuscula(b.getApellido());
        if (apellidoA != apellidoB) return apellidoA < apellidoB;

        return a.getId() <= b.getId();
    }

    // Particionar
    int particionarNombre(int inicio, int fin) {
        // Elegimos el elemento del medio como pivote y lo movemos al final
        int medio = inicio + (fin - inicio) / 2;
        swap(estudiantes[medio], estudiantes[fin]);

        Estudiante pivote = estudiantes[fin];
        int i = inicio - 1;

        for (int j = inicio; j < fin; j++) {
            // Si el estudiante va antes o igual que el pivote
            if (nombreMenorIgual(estudiantes[j], pivote)) {
                i++;
                swap(estudiantes[i], estudiantes[j]);
            }
        }
        // Colocar el pivote en su posicion correcta
        swap(estudiantes[i + 1], estudiantes[fin]);
        return i + 1;
    }

    // QuickSort por nombre (A-Z)
    void quickSort(int inicio, int fin) {
        // Caso base
        if (inicio >= fin)
            return;

        int posicionPivote = particionarNombre(inicio, fin);
        // Ordenar lado izquierdo
        quickSort(inicio, posicionPivote - 1);
        // Ordenar lado derecho
        quickSort(posicionPivote + 1, fin);
    }

    void liberar() {
        estudiantes.clear();
        ordenadoID = false;
    }

public:
    EstudianteGestor() {
        ordenadoID = false;
    }
    EstudianteGestor(const vector<int>& idsEstudiantes, EstudianteHashTable<Estudiante>* tabla) {
        ordenadoID = false;

        for (size_t i = 0; i < idsEstudiantes.size(); i++) {
            Estudiante* estudiante = tabla->getEstudiante(idsEstudiantes[i]);

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
        cout << "\n\t=== Estudiantes ===\n\n";
        cout << "#\tId\tNombre\t\tProgreso\n";
        cout << "------------------------------------------------\n";

        for (size_t i = 0; i < estudiantes.size(); i++) {
            cout << i << ".\t" << estudiantes[i].getId() << "\t"
                << estudiantes[i].getNombre() << " " << estudiantes[i].getApellido() << "\t\t"
                << estudiantes[i].getProgreso().getProgresoCurso() << "%" << endl;
        }
        cout << endl;
    }


    void buscarEstudiante(int idBuscado) {
        if (!ordenadoID) {
            heapSort(estudiantes, estudiantes.size());
            ordenadoID = true;
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
    void ordenarID() { 
        if (estudiantes.size() <= 1) {
            cout << "No hay suficientes estudiantes para ordenar\n";
            return;
        }

        heapSort(estudiantes, estudiantes.size());
        ordenadoID = true;
        cout << "\n=== Estudiantes ordenados por id ===\n";
        listarEstudiantes();
    }
    void ordenarNombre() {
        if (estudiantes.size() <= 1) {
            cout << "No hay suficientes estudiantes para ordenar\n";
            return;
        }

        quickSort(0, (int)estudiantes.size() - 1);
        ordenadoID = false;
        cout << "\n=== Estudiantes ordenados por nombre ===\n";
        listarEstudiantes();
    }
};