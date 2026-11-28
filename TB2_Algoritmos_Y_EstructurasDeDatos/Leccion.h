#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Leccion
{
private:
    int idLeccion;
    int idModulo;
    string nombre;
    string contenido;
    vector<int> idsEjercicios;

public:
    Leccion()
    {
        idLeccion = 0;
        idModulo = 0;
        nombre = "";
        contenido = "";
    }

    Leccion(int pidLeccion, int pidModulo, string pnombre, string pcontenido, vector<int> pidsEjercicios = {})
    {
        idLeccion = pidLeccion;
        idModulo = pidModulo;
        nombre = pnombre;
        contenido = pcontenido;
        idsEjercicios = pidsEjercicios;
    }

    ~Leccion() {}

    // Getters
    int getIdLeccion() { return idLeccion; }
    int getIdModulo() { return idModulo; }
    string getNombre() { return nombre; }
    string getContenido() { return contenido; }
    const vector<int>& getIdsEjercicios() { return idsEjercicios; }
    
    // Setters
    void setIdLeccion(int pidLeccion) { idLeccion = pidLeccion; }
    void setIdModulo(int pidModulo) { idModulo = pidModulo; }
    void setNombre(string pnombre) { nombre = pnombre; }
    void setContenido(string pcontenido) { contenido = pcontenido; }

    // Metodos
    int getCanntidadEjercicios() { return (int)idsEjercicios.size(); }

    bool existeEjercicios(int pidEjercicio) {
        for (int i = 0; i < getCanntidadEjercicios(); i++) {
            if (idsEjercicios[i] == pidEjercicio) {
                return true;
            }
        }
        return false;
    }
    bool agregarEjercicio(int pidEjercicio) {
        if (!existeEjercicios(pidEjercicio)) {
            idsEjercicios.push_back(pidEjercicio);
            return true;
        }
        return false;
    }

};