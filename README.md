# Algoritmos-y-Estructuras-de-Datos_TB2
TB2 - Plataforma Educativa | Algoritmos y Estructuras de Datos | Grupo 2

Participantes:
- Jean Steven Melgarejo Velasquez
- Darrel Decker Ruiz Quiñonez
- Anelise Edda Sumar Congrains

## 1. Descripción del proyecto

El proyecto consiste en desarrollar una aplicación de consola basada en una plataforma educativa inspirada en Khan Academy.

El sistema estará diseñado para procesar grandes volúmenes de información mediante POO, programación genérica, estructuras de datos, algoritmos de ordenamiento, funciones hash, árboles balanceados, grafos, recursividad y persistencia mediante archivos.

## 2. Objetivos

- Administrar estudiantes y cursos.
- Organizar el contenido educativo mediante módulos, lecciones y ejercicios.
- Registrar el progreso individual de cada estudiante.
- Consultar el historial de ejercicios completados y evaluaciones realizadas.
- Permitir que los profesores visualicen y ordenen a sus estudiantes según su progreso general.
- Procesar grandes cantidades de registros de manera eficiente.
- Aplicar diferentes estructuras de datos y algoritmos.

## 3. Modelo general del sistema

### 3.1. Limitaciones (potencialmente a cambiar)

- Cada estudiante pertenece a un solo profesor.
- Cada estudiante está inscrito en un solo curso.
- Cada curso tiene un solo profesor.
- Cada profesor tiene un solo curso.
- Un profesor administra a sus estudiantes.
- Los profesores pueden consultar el progreso de sus estudiantes, NO pueden agregar, eliminar ni modificar módulos, lecciones o ejercicios.

### 3.2. Separación entre contenido y progreso

El contenido educativo esta separado del progreso individual.

El contenido de los cursos será compartido por todos los estudiantes. Aparte, cada estudiante tendrá sus propios registros de progreso y historial. De esta manera, al completar un ejercicio o una evaluación solo se modifica el progreso y el historial pero el curso se mantiene igual.

### 3.3. Entidades principales

- **Profesor:** administra estudiantes y consulta sus resultados.
- **Estudiante:** pertenece a un profesor, está inscrito en un curso y registra su progreso.
- **Curso:** contiene los módulos de un curso educativo.
- **Modulo:** agrupa lecciones y contiene su evaluación correspondiente.
- **Leccion:** contiene "ejercicios" que el estudiante debe resolver (por decidir pero potencialmente contenga un arreglo de los IDs de sus ejercicios).
- **Ejercicio:** almacena el enunciado y le respuesta correcta.
- **Evaluacion:** evalua los conocimientos adquiridos en un módulo (aka examen final del modulo).
- **Progreso:** administra y guarda el avance individual del estudiante.
- **HistorialEjercicios:** registra los ejercicios completados por el estudiante.
- **HistorialEvaluaciones:** registra el numero de intentos, el enunciado y respuesta correcta de las evaluaciones completadas.

## 4. Estructuras de datos y algoritmos

| Estructura o algoritmo | Entidad | Aplicación dentro del sistema |
|---|---|---|
| Árbol binario de búsqueda (BST) | Profesores | Almacenar y buscar profesores atraves de su ID |
| Árbol balanceado AVL | Cursos | Organizar los cursos mediante su ID |
| Árbol balanceado AVL | Modulos | Organizar los modulos de cada curso atraves de su ID |
| Vector | Estudiantes | Almacenar estudiantes, facilitar su administración y visualizar datos |
| MergeSort | Estudiantes | Ordenar estudiantes según su progreso general |
| Lista doblemente enlazada | Lecciones | Organizar las lecciones de cada modulo |
| Tabla hash | Ejercicios | Almacenar y consultar todos los ejercicios de la aplicacion mediante su ID |
| Cola | Ejercicios | Administrar temporalmente los ejercicios pendientes de un estudiante en una lección |
| Vector de historial | HistorialEjercicios | Registrar los ejercicios completados |
| Vector de historial | HistorialEvaluaciones | Registrar las evaluaciones realizadas |
| Grafo | TBD | TBD |

## 5. Generador de dataset

Cantidades preliminares:

| Entidad	| Cantidad inicial propuesta |
|---|---|
| Profesores	| 100
| Estudiantes	| 5 000
| Cursos	| 100
| Módulos	| 1 000
| Lecciones	| 5 000
| Ejercicios	| 20 000
| Registros de historial	| Miles de miles

## 6. Persistencia de información

Se usuara un gestor de archivos para conservar la información necesaria entre ejecuciones.

Informacion a consultar (lectura):

- Profesores
- Estudiantes
- Cursos y contenido educativo
- Ejercicios
- Progreso individual
- Historiales de ejercicios y evaluaciones

Informacion a guardar (escritura):
- Progreso individual
- Historiales de ejercicios y evaluaciones
