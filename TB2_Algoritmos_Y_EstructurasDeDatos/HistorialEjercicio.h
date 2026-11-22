#pragma once
#include <iostream>
#include <vector>
#include "Ejercicio.h"
#include "EjercicioHashTable.h"
using namespace std;

class HistorialEjercicio
{
private:
    vector<int> idsEjercicios;

public:
    HistorialEjercicio() {}

    // Getters
    const vector<int>& getIdsEjercicios() { return idsEjercicios; }
    int getCantidad() { return (int)idsEjercicios.size(); }

    // Metodos
    bool existe(int pidEjercicio) { // Verifica si el ejercicio ya fue completado
        for (size_t i = 0; i < idsEjercicios.size(); i++) {
            if (idsEjercicios[i] == pidEjercicio) {
                return true;
            }
        }
        return false;
    }

    bool agregar(int pidEjercicio) { // Registra un ejercicio completado
        if (!existe(pidEjercicio)) {
            idsEjercicios.push_back(pidEjercicio);
            return true;
        }
        return false;
    }

    // El historial solo guarda id, busca cada ejercicio en la tabla hash para saber su leccion
    int contarPorLeccion(int pidLeccion, EjercicioHashTable<Ejercicio>& ejercicios) {
        int contador = 0;
        for (size_t i = 0; i < idsEjercicios.size(); i++) {
            Ejercicio* ejercicio = ejercicios.getEjercicio(idsEjercicios[i]);
            if (ejercicio != nullptr && ejercicio->getIdLeccion() == pidLeccion) {
                contador++;
            }
        }
        return contador;
    }

    void mostrarHistorial() {
        cout << "\n=== Ejercicios completados: " << idsEjercicios.size() << " ===\n";
        for (size_t i = 0; i < idsEjercicios.size(); i++) {
            cout << idsEjercicios[i] << " ";
        }
        cout << endl;
    }
};