#pragma once
#include <string>
#include <iostream>
using namespace std;

class Usuario
{
protected:
	int id;
	int tipo; // Profesor 1, Estudiante 2
	string nombre;
	string apellido;
	string correo;
	string contrasena; //Potencialmente se eliminara
public:
	Usuario() {
		id = 0;
		tipo = 0;
		nombre = "";
		apellido = "";
		correo = "";
		contrasena = "";
	}
	Usuario(int pid, int ptipo, string pnombre, string papellido, string pcorreo, string pcontrasena) {
		id = pid;
		tipo = ptipo;
		nombre = pnombre;
		apellido = papellido;
		correo = pcorreo;
		contrasena = pcontrasena;
	}
	~Usuario() {}

	// Getters
	int getId() { return id; }
	int getTipo() { return tipo; }
	string getNombre() { return nombre; }
	string getApellido() { return apellido; }
	string getCorreo() { return correo; }
	string getContrasena() { return contrasena; }

	// Setters
	void setId(int pid) { id = pid; }
	void setTipo(int ptipo) { tipo = ptipo; }
	void setNombre(string pnombre) { nombre = pnombre; }
	void setApellido(string papellido) { apellido = papellido; }
	void setCorreo(string pcorreo) { correo = pcorreo; }
	void setContrasena(string pcontrasena) { contrasena = pcontrasena; }

};