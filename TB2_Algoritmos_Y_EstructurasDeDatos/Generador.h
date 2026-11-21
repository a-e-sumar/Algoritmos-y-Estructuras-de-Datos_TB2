#pragma once
#include <string>
#include <iostream>
using namespace std;

#include "Profesor.h"
#include "Estudiante.h"
#include "ProfesorBST.h"
#include "EstudianteHashTable.h"
#include "EstudianteGestor.h"
#include "Curso.h"
#include "CursoAVL.h"

const int PROFESORES = 100;
const int ESTUDIANTES = 5000;
const int CURSOS = 100;
const int MODULOS = 1000;
const int LECCIONES = 1000;
const int EJERCICIOS = 20000;

static string nombres[] = {
    "Olivia", "Noé", "Eliana", "Liam", "Amelia", "Oliver", "Charlotte", "Elías", "Sofía", "Mateo",
    "Isabella", "Lucas", "Emma", "Elías", "Aurora", "Levi", "Evelyn", "Ezra", "Mia", "Leo", "Ellie", "Asher",
    "Lily", "Luca", "Violeta", "Henry", "Sofía", "Hudson", "Hazel", "Theodore", "Ava", "James", "Aria", "Sebastián",
    "Luna", "Samuel", "Ella", "Waylon", "Willow", "Daniel", "Nova", "Josiah", "Harper", "Theo", "Eleanor", "Cooper",
    "Gianna", "Wyatt", "Scarlett", "Gabriel", "Layla", "Maverick", "Lucy", "Jack", "Isla", "Julian", "Elena", "Benjamín",
    "Iris", "Grayson", "Penélope", "Santiago", "Hiedra", "Michael", "Lainey", "Rowan", "Elizabeth", "Mason", "Nora", "Luke",
    "Dalila", "Muhammad", "Chloe", "Isaías", "Valentina", "Alexander", "Camila", "Romano", "Paisley", "Ethan", "Mila", "Weston",
    "Avery", "Carter", "Naomi", "William", "Leilani", "David", "Sadie", "Silas", "Zoe", "Ezequiel", "Emilia", "Thomas",
    "Stella", "Enzo", "Zoey", "Owen", "Adeline", "Juan", "Amara", "Atlas", "Ayla", "Bennett", "Riley", "Isaac", "Gracia", "José",
    "Abigail", "Mateo", "Sophie", "Kai", "Emily", "Beau", "Edén", "Nathan", "Millie", "Jackson", "Josie", "Jeremías",
    "Otoño", "Miles", "Atenea", "Wesley", "Daisy", "Caleb", "Maya", "Anthony", "Melodía", "Adam", "Raelynn", "Nolan",
    "Victoria", "Eli", "María", "Micah", "Clara", "Everett", "Eloise", "Lincoln", "Kinsley", "Malaquías", "Alice", "Charlie",
    "Aaliyah", "Logan", "Hannah", "Walker", "Ruby", "Aiden", "Madison", "Adrián", "Lyla", "Adriel", "Emery", "Amir",
    "Siena", "Sión", "Gabriella", "Joshua", "Vivian", "Xavier", "Lillian", "Myles", "Claire", "Arthur", "Liliana", "Jacob",
    "Oakley", "Luka", "Lydia", "Cameron", "Ember", "Río", "Magnolia", "Jaxon", "Serenidad", "Milo", "Amira", "Christopher",
    "Josephine", "Colton", "Oaklynn", "Jayden", "Brielle", "Jaxson", "Everly", "Andrew", "Bella", "Stetson", "Charlie", "Archer",
    "Sarah", "Jasper", "Bean", "Axel", "Madelyn", "Brooks", "Juniper", "Dean"
};
static string apellidos[] = {
    "Quispe", "Flores", "Sánchez", "García", "Rodríguez",
    "Huamán", "Rojas", "Vásquez", "Mamani", "López",
    "Ramos", "Pérez", "Torres", "Díaz", "Gonzales",
    "Ramírez", "Mendoza", "Chávez", "Espinoza", "Castillo",
    "Fernández", "Vargas", "Gutiérrez", "Cruz", "Ruiz",
    "De la Cruz", "Romero", "Gómez", "Silva", "Córdova",
    "Condori", "Catro", "Martínez", "Reyes", "Rivera",
    "Salazar", "Medina", "Aguilar", "Morales", "Paredes"
};
static string nombresCursos[] = {
    "Programacion", "Matematica", "Fisica", "Algoritmos",
    "Estructuras de Datos", "Bases de Datos", "Redes",
    "Inteligencia Artificial", "Desarrollo Web", "Estadistica",
    "Sistemas Operativos", "Computacion", "Ingenieria de Software",
    "Analisis de Datos", "Ciberseguridad", "Calculo",
    "Logica", "Arquitectura de Computadoras",
    "Gestion de Proyectos", "Diseno de Sistemas"
};
static string complementosCursos[] = {
    "I", "II", "III", "IV", "Avanzado", "Basico",
    "Fundamentos", "Aplicado", "Practico", "Integral"
};

static vector<int> listaIdCursos;

int cantidadNombres() { return sizeof(nombres) / sizeof(nombres[0]); }
int cantidadApellidos() { return sizeof(apellidos) / sizeof(apellidos[0]); }
int cantidadNombresCursos() { return sizeof(nombresCursos) / sizeof(nombresCursos[0]); }
int cantidadComplementosCursos() { return sizeof(complementosCursos) / sizeof(complementosCursos[0]); }

string generarNombre() { return nombres[rand() % cantidadNombres()]; }
string generarApellido() { return apellidos[rand() % cantidadApellidos()]; }
string generarCorreo(string nombre, string apellido) { return nombre + apellido + "@universidad.edu.pe"; }

string generarNombreCurso() { return nombresCursos[rand() % cantidadNombresCursos()] + " " + complementosCursos[rand() % cantidadComplementosCursos()]; }

void generarProfesor(ProfesorBST<Profesor>& profesores) {
    for (int i = 0; i < PROFESORES; i++)
    {
        int id = 10000 + i; // CORREGIR: si los ids son secuanciales el BST se vuelve desblanceado
        int idCurso = 30000 + i;
        string nombre = generarNombre();
        string apellido = generarApellido();
        string correo = generarCorreo(nombre, apellido);
        string clave = "password123";

        Profesor newProfesor(id, nombre, apellido, correo, clave, idCurso);
        profesores.insertar(newProfesor);
    }
}

void generarEstudiante(EstudianteHashTable<Estudiante>& estudiantes, ProfesorBST<Profesor>& profesores) {
    for (int i = 0; i < ESTUDIANTES; i++)
    {
        int id = 20000 + i;
        Profesor* prof = profesores.getProfesor(rand() % PROFESORES + 10000);
        if (prof == nullptr) continue;
        int idProfesor = prof->getId();
        int idCurso = prof->getIdCurso();
        string nombre = generarNombre();
        string apellido = generarApellido();
        string correo = generarCorreo(nombre, apellido);
        string clave = "password123";
        int progresoCurso = rand() % 100; // Cambiar despues de implementar ProgresoHashTable

        Estudiante newEstudiante(id, nombre, apellido, correo, clave, idProfesor, idCurso, progresoCurso);
        estudiantes.insertar(newEstudiante);
    }
}

void generarCursos(CursoAVL<Curso>& cursos, ProfesorBST<Profesor>& profesores, EstudianteHashTable<Estudiante>& estudiantes) {
    for (int i = 0; i < CURSOS; i++)
    {
        vector<int> listaEstudiantes;
        int idCurso = 30000 + i;
        int idProfesor = 10000 + i;
        string nombre = generarNombreCurso();
        for (int j = 0; j < ESTUDIANTES; j++)
        {
            Estudiante* temp = estudiantes.getEstudiante(20000 + j);
            if (temp != nullptr && temp->getIdCurso() == idCurso)
                listaEstudiantes.push_back(temp->getId());
        }

        Curso newCurso(idCurso, idProfesor, nombre, listaEstudiantes);
        cursos.insertar(newCurso);
    }
}
