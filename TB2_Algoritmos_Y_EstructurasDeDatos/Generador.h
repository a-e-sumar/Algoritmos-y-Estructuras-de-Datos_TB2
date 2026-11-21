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
    "Olivia", "Noe", "Eliana", "Liam", "Amelia", "Oliver", "Charlotte", "Elias", "Sofia", "Mateo",
    "Isabella", "Lucas", "Emma", "Adrian", "Aurora", "Levi", "Evelyn", "Ezra", "Mia", "Leo", "Ellie", "Asher",
    "Lily", "Luca", "Violeta", "Henry", "Valeria", "Hudson", "Hazel", "Theodore", "Ava", "James", "Aria", "Sebastian",
    "Luna", "Samuel", "Ella", "Waylon", "Willow", "Daniel", "Nova", "Josiah", "Harper", "Theo", "Eleanor", "Cooper",
    "Gianna", "Wyatt", "Scarlett", "Gabriel", "Layla", "Maverick", "Lucy", "Jack", "Isla", "Julian", "Elena", "Benjamin",
    "Iris", "Grayson", "Penelope", "Santiago", "Hiedra", "Michael", "Lainey", "Rowan", "Elizabeth", "Mason", "Nora", "Luke",
    "Dalila", "Muhammad", "Chloe", "Isaias", "Valentina", "Alexander", "Camila", "Romano", "Paisley", "Ethan", "Mila", "Weston",
    "Avery", "Carter", "Naomi", "William", "Leilani", "David", "Sadie", "Silas", "Zoe", "Ezequiel", "Emilia", "Thomas",
    "Stella", "Enzo", "Zoey", "Owen", "Adeline", "Juan", "Amara", "Atlas", "Ayla", "Bennett", "Riley", "Isaac", "Gracia", "Jose",
    "Abigail", "Bruno", "Sophie", "Kai", "Emily", "Beau", "Eden", "Nathan", "Millie", "Jackson", "Josie", "Jeremias",
    "Otono", "Miles", "Atenea", "Wesley", "Daisy", "Caleb", "Maya", "Anthony", "Melodia", "Adam", "Raelynn", "Nolan",
    "Victoria", "Eli", "Maria", "Micah", "Clara", "Everett", "Eloise", "Lincoln", "Kinsley", "Malaquias", "Alice", "Charlie",
    "Aaliyah", "Logan", "Hannah", "Walker", "Ruby", "Aiden", "Madison", "Alejandro", "Lyla", "Adriel", "Emery", "Amir",
    "Siena", "Sion", "Gabriella", "Joshua", "Vivian", "Xavier", "Lillian", "Myles", "Claire", "Arthur", "Liliana", "Jacob",
    "Oakley", "Luka", "Lydia", "Cameron", "Ember", "Rio", "Magnolia", "Jaxon", "Serenidad", "Milo", "Amira", "Christopher",
    "Josephine", "Colton", "Oaklynn", "Jayden", "Brielle", "Jaxson", "Everly", "Andrew", "Bella", "Stetson", "Orlando", "Archer",
    "Sarah", "Jasper", "Bean", "Axel", "Madelyn", "Brooks", "Juniper", "Dean"
};
static string apellidos[] = {
    "Quispe", "Flores", "Sanchez", "Garcia", "Rodriguez",
    "Huaman", "Rojas", "Vasquez", "Mamani", "Lopez",
    "Ramos", "Perez", "Torres", "Diaz", "Gonzales",
    "Ramirez", "Mendoza", "Chavez", "Espinoza", "Castillo",
    "Fernandez", "Vargas", "Gutierrez", "Cruz", "Ruiz",
    "Caro", "Romero", "Gomez", "Silva", "Cordova",
    "Condori", "Castor", "Martinez", "Reyes", "Rivera",
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
string generarCorreo(string nombre, string apellido, int id) { return nombre.substr(0, 1) + apellido.substr(0, 1) + to_string(id) + "@universidad.edu.pe"; }

string generarNombreCurso() { return nombresCursos[rand() % cantidadNombresCursos()] + " " + complementosCursos[rand() % cantidadComplementosCursos()]; }

void generarProfesor(ProfesorBST<Profesor>& profesores) {
    int insertados = 0;

    for (int i = 0; i < PROFESORES; i++)
    {
        int id = 10000 + i; // CORREGIR: si los ids son secuanciales el BST se vuelve desblanceado
        int idCurso = 30000 + i;
        string nombre = generarNombre();
        string apellido = generarApellido();
        string correo = generarCorreo(nombre, apellido, id);
        string clave = "password123";

        Profesor newProfesor(id, nombre, apellido, correo, clave, idCurso);
        if (profesores.insertar(newProfesor)) insertados++;
    }

    if (insertados != PROFESORES) {
        cout << "ADVERTENCIA: se insertaron " << insertados << " de " << PROFESORES << " profesores\n";
    }
}

void generarEstudiante(EstudianteHashTable<Estudiante>& estudiantes, ProfesorBST<Profesor>& profesores) {
    int insertados = 0;

    for (int i = 0; i < ESTUDIANTES; i++)
    {
        int id = 20000 + i;
        Profesor* prof = profesores.getProfesor(rand() % PROFESORES + 10000);
        if (prof == nullptr) continue;
        int idProfesor = prof->getId();
        int idCurso = prof->getIdCurso();
        string nombre = generarNombre();
        string apellido = generarApellido();
        string correo = generarCorreo(nombre, apellido, id);
        string clave = "password123";
        int progresoCurso = rand() % 101; // Cambiar despues de implementar ProgresoHashTable

        Estudiante newEstudiante(id, nombre, apellido, correo, clave, idProfesor, idCurso, progresoCurso);
        if (estudiantes.insertar(newEstudiante)) insertados++;
    }

    if (insertados != ESTUDIANTES) {
        cout << "ADVERTENCIA: se insertaron " << insertados << " de " << ESTUDIANTES << " estudiantes\n";
    }
}

void generarCursos(CursoAVL<Curso>& cursos, ProfesorBST<Profesor>& profesores, EstudianteHashTable<Estudiante>& estudiantes) {
    int insertados = 0;
    
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
        if (cursos.insertar(newCurso)) insertados++;
    }

    if (insertados != CURSOS) {
        cout << "ADVERTENCIA: se insertaron " << insertados << " de " << CURSOS << " cursos\n";
    }
}
