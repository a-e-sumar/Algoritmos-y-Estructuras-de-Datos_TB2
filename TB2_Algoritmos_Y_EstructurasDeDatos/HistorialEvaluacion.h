#pragma once
#include <iostream>
#include <vector>
#include "Modulo.h"
#include "ModuloAVL.h"
using namespace std;

struct RegistroEvaluacion {
    int idEvaluacion;
    int intentos;

    RegistroEvaluacion(int pidEvaluacion, int pintentos) {
        idEvaluacion = pidEvaluacion;
        intentos = pintentos;
    }
};

class HistorialEvaluacion
{
private:
    vector<RegistroEvaluacion> registros;

	int buscarPosicion(int pidEvaluacion) { // Busca la posicion de la evaluacion en el vector
        for (size_t i = 0; i < registros.size(); i++) {
            if (registros[i].idEvaluacion == pidEvaluacion) {
                return (int)i;
            }
        }
        return -1;
    }

public:
    HistorialEvaluacion() {}

    // Getters
    const vector<RegistroEvaluacion>& getRegistros() { return registros; }
    int getCantidad() { return (int)registros.size(); } // evaluaciones distintas registradas
    int getIntentos(int pidEvaluacion) {
        int posicion = buscarPosicion(pidEvaluacion);
        if (posicion == -1) {
            return 0;
        }
        return registros[posicion].intentos;
    }

    // Metodos
    bool existe(int pidEvaluacion) {
        return buscarPosicion(pidEvaluacion) != -1;
    }

    // Si la evaluacion ya estaba registrada suma los intentos
    bool registrar(int pidEvaluacion, int pintentos = 1) {
        if (pintentos <= 0) {
            return false;
        }
        int posicion = buscarPosicion(pidEvaluacion);
        if (posicion == -1) {
            registros.push_back(RegistroEvaluacion(pidEvaluacion, pintentos));
        }
        else {
            registros[posicion].intentos += pintentos;
        }
        return true;
    }

    // El historial solo guarda id, busca el modulo en el ModuloAVL global para saber su evaluacion
    int contarPorModulo(int pidModulo, ModuloAVL<Modulo>& modulos) {
        Modulo* modulo = modulos.getModulo(pidModulo);
        if (modulo == nullptr) {
            return 0;
        }
        int idEvaluacion = modulo->getEvaluacion().getIdEvaluacion();
        if (idEvaluacion != 0 && existe(idEvaluacion)) {
            return 1;
        }
        return 0;
    }

    void mostrarHistorial() {
        cout << "\n=== Evaluaciones realizadas: " << registros.size() << " ===\n";
        for (size_t i = 0; i < registros.size(); i++) {
            cout << "Evaluacion " << registros[i].idEvaluacion << " - intentos: " << registros[i].intentos << endl;
        }
    }
};