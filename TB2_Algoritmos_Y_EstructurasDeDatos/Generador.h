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
#include "Modulo.h"
#include "ModuloAVL.h"
#include "Evaluacion.h"
#include "Leccion.h"
#include "LeccionListaDoble.h"
#include "Ejercicio.h"
#include "EjercicioHashTable.h"

const int PROFESORES = 100;
const int ESTUDIANTES = 5000;
const int CURSOS = 100;
const int MODULOS = 1000;
const int LECCIONES = 1000;
const int EJERCICIOS = 20000;

const int ProfesorBASE = 10000;
const int EstudianteBASE = 20000;
const int CursoBASE = 30000;
const int ModuloBASE = 40000;
const int EvaluacionBASE = 50000;
const int LeccionBASE = 60000;
const int EjercicioBASE = 100000;

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
static string nombresModulos[] = {
    "Introduccion", "Conceptos Basicos", "Herramientas", "Fundamentos Teoricos",
    "Casos Practicos", "Resolucion de Problemas", "Buenas Practicas",
    "Aplicaciones", "Repaso Integral", "Proyecto Final"
};
static string nombresLecciones[] = {
    "Primeros Pasos", "Definiciones", "Ejemplos Guiados", "Taller",
    "Errores Comunes", "Practica Dirigida", "Casos de Uso", "Resumen",
    "Extra"
};
static string contenido[] = {
    "En esta lección aprenderás los conceptos fundamentales del tema.",
    "Se presenta una introducción teórica con ejemplos claros.",
    "Aquí se explican las definiciones básicas necesarias.",
    "Se muestran ejemplos guiados paso a paso para comprender mejor.",
    "Se detallan los errores más comunes y cómo evitarlos.",
    "Contiene una práctica dirigida con ejercicios resueltos.",
    "Se analizan casos de uso reales aplicados al tema.",
    "Resumen de los puntos clave vistos en la lección.",
    "Material extra para reforzar lo aprendido en clase.",
    "Se explica la importancia del tema en el contexto profesional.",
    "Incluye diagramas y esquemas explicativos del proceso.",
    "Se comparan diferentes enfoques y sus ventajas.",
    "Se presentan herramientas útiles para aplicar lo aprendido.",
    "Se describen los pasos para resolver un problema típico.",
    "Se introduce terminología técnica esencial del tema.",
    "Se muestran ejemplos de código comentado línea por línea.",
    "Se explican las buenas prácticas recomendadas.",
    "Se plantean preguntas de reflexión para el estudiante.",
    "Se incluye una tabla comparativa de conceptos.",
    "Se detalla el procedimiento para implementar la solución.",
    "Se explican los fundamentos teóricos con analogías simples.",
    "Se presenta un caso práctico desarrollado completamente.",
    "Se analizan las limitaciones y alcances del tema.",
    "Se ofrece una guía rápida de referencia para consulta.",
    "Se describen los componentes principales del sistema.",
    "Se explica cómo integrar los conceptos con temas previos.",
    "Se muestran ejemplos de aplicación en proyectos reales.",
    "Se resumen las ideas centrales con un mapa conceptual.",
    "Se proponen actividades para practicar lo aprendido.",
    "Se explican los criterios de evaluación de la lección.",
    "Se introduce un nuevo enfoque para resolver el problema.",
    "Se detallan los pasos de instalación y configuración.",
    "Se comparan las ventajas y desventajas de cada opción.",
    "Se presentan ejemplos de uso en distintos contextos.",
    "Se explican los conceptos avanzados de forma progresiva.",
    "Se incluye una sección de preguntas frecuentes.",
    "Se describen los errores típicos de implementación.",
    "Se muestra cómo depurar y corregir problemas comunes.",
    "Se explican las métricas para medir el rendimiento.",
    "Se presentan ejercicios de refuerzo con soluciones.",
    "Se introduce el tema mediante una situación cotidiana.",
    "Se detallan las estructuras de datos involucradas.",
    "Se explican los algoritmos principales con pseudocódigo.",
    "Se muestran ejemplos de entrada y salida esperados.",
    "Se describe el flujo de trabajo recomendado.",
    "Se explican las convenciones de nomenclatura usadas.",
    "Se presentan recomendaciones para optimizar el código.",
    "Se analizan casos límite y cómo manejarlos.",
    "Se incluye una lista de verificación antes de continuar.",
    "Se explican los principios de diseño aplicados.",
    "Se muestran ejemplos de pruebas unitarias básicas.",
    "Se describen los pasos para documentar la solución.",
    "Se introduce el concepto de modularidad en el tema.",
    "Se explican las diferencias entre enfoques iterativos y recursivos.",
    "Se presentan ejemplos de uso con datos reales.",
    "Se detallan las consideraciones de seguridad relevantes.",
    "Se explica cómo escalar la solución propuesta.",
    "Se muestran ejemplos de integración con otras herramientas.",
    "Se describen los patrones de diseño más usados.",
    "Se analiza el impacto del tema en el rendimiento global.",
    "Se incluye un glosario de términos clave.",
    "Se presentan ejemplos de refactorización de código.",
    "Se explican las técnicas de depuración más efectivas.",
    "Se muestran ejemplos de manejo de excepciones.",
    "Se describen las buenas prácticas de documentación.",
    "Se introducen los conceptos de concurrencia y paralelismo.",
    "Se explican las diferencias entre compilación e interpretación.",
    "Se presentan ejemplos de optimización de consultas.",
    "Se detallan los pasos para migrar datos existentes.",
    "Se explican las técnicas de validación de entrada.",
    "Se muestran ejemplos de pruebas de integración.",
    "Se describen los principios SOLID aplicados al tema.",
    "Se analiza la complejidad temporal de los algoritmos.",
    "Se incluye una comparación de rendimiento entre opciones.",
    "Se presentan ejemplos de uso en sistemas distribuidos.",
    "Se explican las estrategias de caché y su impacto.",
    "Se muestran ejemplos de configuración de entornos.",
    "Se detallan las técnicas de monitoreo y logging.",
    "Se explican los conceptos de tolerancia a fallos.",
    "Se presentan ejemplos de automatización de tareas.",
    "Se describen los pasos para realizar una revisión de código.",
    "Se analizan los riesgos y mitigaciones del tema.",
    "Se incluye una guía de estilo para el código fuente.",
    "Se explican las diferencias entre pruebas unitarias y funcionales.",
    "Se muestran ejemplos de uso de bibliotecas populares.",
    "Se detallan las consideraciones de accesibilidad.",
    "Se explican las técnicas de internacionalización.",
    "Se presentan ejemplos de manejo de archivos y directorios.",
    "Se describen los pasos para implementar un sistema de login.",
    "Se analiza el papel del tema en la arquitectura de software.",
    "Se incluyen ejemplos de despliegue en la nube.",
    "Se explican los conceptos de contenedores y virtualización.",
    "Se muestran ejemplos de uso de APIs externas.",
    "Se detallan las técnicas de control de versiones.",
    "Se explican las diferencias entre modelos relacionales y no relacionales.",
    "Se presentan ejemplos de normalización de datos.",
    "Se describen los pasos para diseñar un esquema eficiente.",
    "Se analizan los trade-offs entre consistencia y disponibilidad.",
    "Se incluye una introducción a los sistemas expertos.",
    "Se explican los fundamentos del aprendizaje automático.",
    "Se muestran ejemplos de clasificación y regresión.",
    "Se detallan las etapas de un proyecto de ciencia de datos.",
    "Se explican las técnicas de limpieza de datos.",
    "Se presentan ejemplos de visualización de información.",
    "Se describen los pasos para entrenar un modelo simple.",
    "Se analiza el sesgo en los algoritmos de IA.",
    "Se incluyen ejemplos de procesamiento de lenguaje natural.",
    "Se explican los conceptos de redes neuronales básicas.",
    "Se muestran ejemplos de uso de técnicas de clustering.",
    "Se detallan las métricas de evaluación de modelos.",
    "Se explican las diferencias entre supervisado y no supervisado.",
    "Se presentan ejemplos de recomendación personalizada.",
    "Se describen los pasos para implementar un chatbot simple.",
    "Se analiza el impacto ético de la inteligencia artificial.",
    "Se incluyen ejemplos de automatización de procesos.",
    "Se explican los conceptos de ciberseguridad defensiva.",
    "Se muestran ejemplos de ataques comunes y su prevención.",
    "Se detallan las técnicas de cifrado y hashing.",
    "Se explican las diferencias entre autenticación y autorización.",
    "Se presentan ejemplos de gestión de contraseñas seguras.",
    "Se describen los pasos para realizar una auditoría básica.",
    "Se analiza el papel de los firewalls y proxies.",
    "Se incluyen ejemplos de políticas de seguridad.",
    "Se explican los conceptos de redes TCP/IP.",
    "Se muestran ejemplos de configuración de subredes.",
    "Se detallan las técnicas de troubleshooting de red.",
    "Se explican las diferencias entre protocolos de transporte.",
    "Se presentan ejemplos de captura y análisis de tráfico.",
    "Se describen los pasos para montar un servidor web.",
    "Se analiza el funcionamiento del DNS y sus registros.",
    "Se incluyen ejemplos de despliegue con HTTPS.",
    "Se explican los conceptos de virtualización de redes.",
    "Se muestran ejemplos de balanceo de carga.",
    "Se detallan las técnicas de diseño responsivo.",
    "Se explican las diferencias entre frontend y backend.",
    "Se presentan ejemplos de uso de frameworks modernos.",
    "Se describen los pasos para crear una API REST.",
    "Se analiza el papel de los microservicios.",
    "Se incluyen ejemplos de consumo de servicios web.",
    "Se explican los conceptos de estado y sesión.",
    "Se muestran ejemplos de validación en el cliente y servidor.",
    "Se detallan las técnicas de optimización de consultas SQL.",
    "Se explican las diferencias entre procedimientos y funciones.",
    "Se presentan ejemplos de transacciones y bloqueos.",
    "Se describen los pasos para realizar copias de seguridad.",
    "Se analiza el papel de los índices en el rendimiento.",
    "Se incluyen ejemplos de migración de bases de datos.",
    "Se explican los conceptos de arquitectura limpia.",
    "Se muestran ejemplos de inyección de dependencias.",
    "Se detallan las técnicas de testing automatizado.",
    "Se explican las diferencias entre mocks y stubs.",
    "Se presentan ejemplos de integración continua.",
    "Se describen los pasos para desplegar con Docker.",
    "Se analiza el papel de Kubernetes en la orquestación.",
    "Se incluyen ejemplos de monitoreo con Prometheus.",
    "Se explican los conceptos de infraestructura como código.",
    "Se muestran ejemplos de pipelines CI/CD.",
    "Se detallan las técnicas de gestión de incidentes.",
    "Se explican las diferencias entre SLA, SLO y SLI.",
    "Se presentan ejemplos de postmortems efectivos."
};

static string preguntas[] = {
    "¿Qué es un algoritmo?\nA) Un lenguaje de programación\nB) Un conjunto ordenado de pasos para resolver un problema\nC) Un tipo de hardware",
    "¿Cuál es la diferencia entre variable y constante?\nA) La variable puede cambiar su valor, la constante no\nB) Son exactamente iguales\nC) La constante se usa solo en bucles",
    "¿Qué es una estructura de datos?\nA) Un tipo de base de datos\nB) Una forma de organizar datos en memoria\nC) Un paradigma de programación",
    "¿Para qué sirve un bucle for?\nA) Para declarar variables\nB) Para repetir un bloque un número conocido de veces\nC) Para definir funciones",
    "¿Qué es la recursividad?\nA) Una técnica donde una función se llama a sí misma\nB) Un tipo de bucle infinito\nC) Una forma de declarar variables",
    "¿Qué es un arreglo unidimensional?\nA) Una colección de elementos del mismo tipo accesibles por índice\nB) Una tabla con filas y columnas\nC) Un puntero doble",
    "¿Qué diferencia hay entre pila y cola?\nA) La pila es FIFO y la cola LIFO\nB) La pila es LIFO y la cola FIFO\nC) Ambas son LIFO",
    "¿Qué es una lista enlazada?\nA) Un arreglo de tamaño fijo\nB) Una estructura de nodos enlazados por punteros\nC) Una tabla hash",
    "¿Qué es un árbol binario?\nA) Un árbol donde cada nodo tiene como máximo dos hijos\nB) Un árbol con exactamente tres hijos\nC) Una lista doblemente enlazada",
    "¿Qué es un árbol AVL?\nA) Un árbol binario desbalanceado\nB) Un árbol binario balanceado con alturas logarítmicas\nC) Un grafo dirigido",
    "¿Qué es una tabla hash?\nA) Una estructura que asocia claves a valores mediante una función hash\nB) Una lista ordenada\nC) Un árbol de búsqueda",
    "¿Qué es la complejidad temporal?\nA) El espacio en disco usado\nB) El tiempo que tarda un algoritmo en función de la entrada\nC) La cantidad de líneas de código",
    "¿Qué significa O(n)?\nA) El tiempo crece linealmente con la entrada\nB) El tiempo es constante\nC) El tiempo crece exponencialmente",
    "¿Qué significa O(log n)?\nA) El tiempo crece logarítmicamente con la entrada\nB) El tiempo crece cuadráticamente\nC) El tiempo es constante",
    "¿Qué es la búsqueda binaria?\nA) Recorrer elemento por elemento\nB) Buscar en un arreglo ordenado dividiendo el espacio a la mitad\nC) Ordenar el arreglo antes de buscar",
    "¿Qué es la búsqueda lineal?\nA) Recorrer elemento por elemento hasta encontrar el valor\nB) Dividir el arreglo a la mitad\nC) Usar una función hash",
    "¿Qué es un grafo?\nA) Una estructura compuesta por vértices y aristas\nB) Un árbol binario\nC) Una lista enlazada",
    "¿Qué es un recorrido BFS?\nA) Un recorrido en profundidad\nB) Un recorrido por niveles usando una cola\nC) Un recorrido aleatorio",
    "¿Qué es un recorrido DFS?\nA) Un recorrido por niveles\nB) Un recorrido en profundidad usando recursión o pila\nC) Un recorrido ordenado",
    "¿Qué es la programación orientada a objetos?\nA) Un paradigma basado en clases y objetos\nB) Un lenguaje de bajo nivel\nC) Un tipo de base de datos",
    "¿Qué es una clase?\nA) Una instancia de un objeto\nB) Una plantilla que define atributos y métodos\nC) Un tipo de variable",
    "¿Qué es un objeto?\nA) Una instancia de una clase\nB) Una plantilla de código\nC) Un método estático",
    "¿Qué es la encapsulación?\nA) Ocultar detalles internos y exponer solo lo necesario\nB) Heredar de otra clase\nC) Definir varios métodos con el mismo nombre",
    "¿Qué es la herencia?\nA) La capacidad de una clase de heredar de otra\nB) La capacidad de un objeto de tomar varias formas\nC) Ocultar atributos",
    "¿Qué es el polimorfismo?\nA) La capacidad de un objeto de tomar varias formas\nB) La creación de múltiples clases\nC) La sobrecarga de constructores",
    "¿Qué es una interfaz?\nA) Una clase concreta\nB) Un contrato que define métodos sin implementación\nC) Un tipo de variable",
    "¿Qué es una clase abstracta?\nA) Una clase que no puede instanciarse directamente\nB) Una clase con solo atributos públicos\nC) Una clase final",
    "¿Qué es un constructor?\nA) Un método que se ejecuta al crear un objeto\nB) Un método que destruye un objeto\nC) Un método estático",
    "¿Qué es un destructor?\nA) Un método que se ejecuta al crear un objeto\nB) Un método que se ejecuta al destruir un objeto\nC) Un constructor sobrecargado",
    "¿Qué es la sobrecarga de métodos?\nA) Definir varios métodos con el mismo nombre pero distinta firma\nB) Redefinir un método heredado\nC) Eliminar un método",
    "¿Qué es la sobreescritura de métodos?\nA) Definir varios métodos con el mismo nombre\nB) Redefinir un método heredado en una subclase\nC) Crear un método abstracto",
    "¿Qué es una excepción?\nA) Un evento anómalo que interrumpe el flujo normal del programa\nB) Un tipo de bucle\nC) Una variable global",
    "¿Qué es el manejo de excepciones?\nA) El mecanismo para capturar y manejar excepciones\nB) Un tipo de herencia\nC) Una técnica de ordenamiento",
    "¿Qué es un puntero?\nA) Una variable que almacena una dirección de memoria\nB) Un alias de una variable\nC) Un tipo de arreglo",
    "¿Qué es una referencia?\nA) Una variable que almacena una dirección de memoria\nB) Un alias de una variable existente\nC) Un puntero nulo",
    "¿Qué diferencia hay entre memoria estática y dinámica?\nA) La estática se asigna en compilación, la dinámica en ejecución\nB) Son iguales\nC) La dinámica se asigna en compilación",
    "¿Qué es la recursión de cola?\nA) Una recursión donde la llamada recursiva es la última operación\nB) Una recursión infinita\nC) Una recursión sin caso base",
    "¿Qué es un algoritmo de ordenamiento?\nA) Un procedimiento para ordenar elementos de una colección\nB) Un tipo de búsqueda\nC) Una estructura de datos",
    "¿Cómo funciona el ordenamiento burbuja?\nA) Compara pares adyacentes e intercambia hasta ordenar\nB) Divide el arreglo a la mitad\nC) Usa una función hash",
    "¿Cómo funciona quicksort?\nA) Elige un pivote y particiona el arreglo recursivamente\nB) Compara pares adyacentes\nC) Fusiona dos mitades ordenadas",
    "¿Cómo funciona mergesort?\nA) Divide el arreglo, ordena cada mitad y las fusiona\nB) Elige un pivote\nC) Compara pares adyacentes",
    "¿Qué es la búsqueda en profundidad?\nA) Un recorrido que explora lo más profundo posible antes de retroceder\nB) Un recorrido por niveles\nC) Una búsqueda binaria",
    "¿Qué es un árbol de búsqueda binario?\nA) Un árbol donde los menores van a la izquierda y los mayores a la derecha\nB) Un árbol desbalanceado\nC) Un grafo dirigido",
    "¿Qué es un heap?\nA) Un árbol binario completo que cumple la propiedad de montículo\nB) Una lista enlazada\nC) Una tabla hash",
    "¿Qué es una cola de prioridad?\nA) Una estructura que extrae el elemento de mayor prioridad\nB) Una cola FIFO\nC) Una pila LIFO",
    "¿Qué es la programación dinámica?\nA) Una técnica que resuelve problemas guardando subresultados\nB) Un paradigma orientado a objetos\nC) Un tipo de bucle",
    "¿Qué es la memoización?\nA) Almacenar resultados de subproblemas para evitar recalcularlos\nB) Un tipo de recursión\nC) Una técnica de ordenamiento",
    "¿Qué es un algoritmo greedy?\nA) Una estrategia que elige la mejor opción local en cada paso\nB) Un algoritmo que prueba todas las opciones\nC) Un algoritmo de búsqueda binaria",
    "¿Qué es la división y conquista?\nA) Dividir el problema en subproblemas, resolverlos y combinarlos\nB) Elegir la mejor opción local\nC) Guardar subresultados",
    "¿Qué es un problema NP?\nA) Un problema cuya solución se verifica en tiempo polinomial\nB) Un problema imposible de resolver\nC) Un problema lineal",
    "¿Qué es la notación Big-O?\nA) Una notación que describe el crecimiento asintótico de un algoritmo\nB) Un tipo de variable\nC) Una estructura de datos",
    "¿Qué es un test unitario?\nA) Una prueba que verifica una unidad pequeña de código\nB) Una prueba de integración\nC) Una prueba de carga",
    "¿Qué es el TDD?\nA) Desarrollo guiado por pruebas: primero la prueba, luego el código\nB) Un patrón de diseño\nC) Un tipo de base de datos",
    "¿Qué es la refactorización?\nA) Mejorar la estructura interna del código sin cambiar su comportamiento\nB) Agregar nuevas funcionalidades\nC) Eliminar código",
    "¿Qué es un patrón de diseño?\nA) Una solución reutilizable a un problema común de diseño\nB) Un tipo de variable\nC) Un lenguaje de programación",
    "¿Qué es el patrón Singleton?\nA) Un patrón que garantiza una única instancia de una clase\nB) Un patrón que crea múltiples objetos\nC) Un patrón de ordenamiento",
    "¿Qué es el patrón Factory?\nA) Un patrón que delega la creación de objetos a una fábrica\nB) Un patrón de herencia múltiple\nC) Un patrón de búsqueda",
    "¿Qué es el patrón Observer?\nA) Un patrón donde los observadores reciben notificaciones de cambios\nB) Un patrón de creación\nC) Un patrón de ordenamiento",
    "¿Qué es el principio SOLID?\nA) Cinco principios de diseño orientado a objetos\nB) Un tipo de base de datos\nC) Un algoritmo de ordenamiento",
    "¿Qué es la inyección de dependencias?\nA) Pasar dependencias a una clase en lugar de crearlas internamente\nB) Crear dependencias dentro de la clase\nC) Un tipo de herencia",
    "¿Qué es una API REST?\nA) Un estilo arquitectónico basado en recursos y métodos HTTP\nB) Un tipo de base de datos\nC) Un lenguaje de programación",
    "¿Qué es HTTP?\nA) El protocolo de transferencia de hipertexto\nB) Un lenguaje de marcado\nC) Un tipo de base de datos",
    "¿Qué es una petición GET?\nA) Una petición para obtener un recurso\nB) Una petición para crear datos\nC) Una petición para eliminar datos",
    "¿Qué es una petición POST?\nA) Una petición para obtener un recurso\nB) Una petición para crear o enviar datos\nC) Una petición para eliminar datos",
    "¿Qué es un código de estado HTTP?\nA) Un número que indica el resultado de una petición HTTP\nB) Un tipo de variable\nC) Un método de ordenamiento",
    "¿Qué es JSON?\nA) Un formato ligero de intercambio de datos basado en texto\nB) Un lenguaje de programación\nC) Un tipo de base de datos",
    "¿Qué es XML?\nA) Un formato de marcado extensible para estructurar datos\nB) Un protocolo de red\nC) Un lenguaje de programación",
    "¿Qué es un servidor web?\nA) Un programa que atiende peticiones de clientes\nB) Un cliente de base de datos\nC) Un tipo de variable",
    "¿Qué es un cliente?\nA) Un programa que solicita servicios a un servidor\nB) Un servidor de base de datos\nC) Un tipo de red",
    "¿Qué es un protocolo de red?\nA) Un conjunto de reglas para la comunicación entre sistemas\nB) Un tipo de hardware\nC) Un lenguaje de programación",
    "¿Qué es TCP?\nA) Un protocolo orientado a conexión y confiable\nB) Un protocolo no orientado a conexión\nC) Un tipo de base de datos",
    "¿Qué es UDP?\nA) Un protocolo orientado a conexión\nB) Un protocolo no orientado a conexión y rápido\nC) Un lenguaje de marcado",
    "¿Qué es una dirección IP?\nA) Un identificador numérico único de un dispositivo en una red\nB) Un tipo de variable\nC) Un protocolo de aplicación",
    "¿Qué es una máscara de subred?\nA) Un número que indica qué parte de la IP pertenece a la red\nB) Un tipo de firewall\nC) Un protocolo de red",
    "¿Qué es el DNS?\nA) El sistema que traduce nombres de dominio a direcciones IP\nB) Un protocolo de correo\nC) Un tipo de base de datos",
    "¿Qué es un firewall?\nA) Un dispositivo que filtra tráfico según reglas de seguridad\nB) Un tipo de servidor web\nC) Un lenguaje de programación",
    "¿Qué es HTTPS?\nA) HTTP sobre TLS, que cifra la comunicación\nB) Un protocolo sin cifrado\nC) Un tipo de base de datos",
    "¿Qué es un certificado SSL?\nA) Un certificado digital que autentica un servidor\nB) Un tipo de firewall\nC) Un protocolo de red",
    "¿Qué es un ataque de phishing?\nA) Un engaño que suplanta identidad para robar datos\nB) Un ataque de fuerza bruta\nC) Un tipo de firewall",
    "¿Qué es un ataque DDoS?\nA) Un ataque que satura un servicio con tráfico masivo\nB) Un ataque de inyección SQL\nC) Un tipo de cifrado",
    "¿Qué es el cifrado simétrico?\nA) Un cifrado que usa la misma clave para cifrar y descifrar\nB) Un cifrado con clave pública y privada\nC) Un tipo de hash",
    "¿Qué es el cifrado asimétrico?\nA) Un cifrado que usa la misma clave\nB) Un cifrado que usa una clave pública y otra privada\nC) Un tipo de firewall",
    "¿Qué es una función hash?\nA) Una función que transforma datos en un valor de longitud fija\nB) Un tipo de cifrado simétrico\nC) Un protocolo de red",
    "¿Qué es una base de datos relacional?\nA) Una base de datos organizada en tablas con relaciones\nB) Una base de datos NoSQL\nC) Un tipo de archivo",
    "¿Qué es una tabla?\nA) Una estructura de filas y columnas que almacena datos\nB) Un tipo de índice\nC) Una consulta SQL",
    "¿Qué es una clave primaria?\nA) Un campo que identifica de forma única cada fila\nB) Un campo que referencia otra tabla\nC) Un tipo de índice",
    "¿Qué es una clave foránea?\nA) Un campo que identifica de forma única cada fila\nB) Un campo que referencia la clave primaria de otra tabla\nC) Un tipo de consulta",
    "¿Qué es una consulta SQL?\nA) Una instrucción para consultar o modificar datos\nB) Un tipo de tabla\nC) Un lenguaje de programación",
    "¿Qué es un JOIN?\nA) Una operación que combina filas de dos o más tablas\nB) Un tipo de índice\nC) Una clave primaria",
    "¿Qué es la normalización?\nA) El proceso de organizar datos para reducir redundancia\nB) Un tipo de consulta\nC) Un algoritmo de ordenamiento",
    "¿Qué es una transacción?\nA) Un conjunto de operaciones que se ejecutan como una unidad\nB) Un tipo de tabla\nC) Una consulta SQL",
    "¿Qué es ACID?\nA) Propiedades de atomicidad, consistencia, aislamiento y durabilidad\nB) Un tipo de base de datos NoSQL\nC) Un lenguaje de consulta",
    "¿Qué es un índice?\nA) Una estructura que acelera la búsqueda de filas\nB) Una clave primaria\nC) Un tipo de tabla",
    "¿Qué es NoSQL?\nA) Un tipo de base de datos no relacional\nB) Un lenguaje de consulta\nC) Un tipo de índice",
    "¿Qué es MongoDB?\nA) Una base de datos NoSQL orientada a documentos\nB) Una base de datos relacional\nC) Un lenguaje de programación",
    "¿Qué es un documento en NoSQL?\nA) Una unidad de datos almacenada en formato similar a JSON\nB) Una tabla relacional\nC) Un tipo de índice",
    "¿Qué es la computación en la nube?\nA) El uso de recursos informáticos a través de internet\nB) Un tipo de red local\nC) Un lenguaje de programación",
    "¿Qué es IaaS?\nA) Infraestructura como servicio: máquinas virtuales y redes\nB) Software como servicio\nC) Plataforma como servicio",
    "¿Qué es PaaS?\nA) Infraestructura como servicio\nB) Plataforma como servicio: entornos de despliegue gestionados\nC) Software como servicio",
    "¿Qué es SaaS?\nA) Software como servicio: aplicaciones accesibles por internet\nB) Infraestructura como servicio\nC) Plataforma como servicio",
    "¿Qué es un contenedor?\nA) Una unidad ligera que empaqueta una aplicación y sus dependencias\nB) Una máquina virtual completa\nC) Un tipo de red",
    "¿Qué es Docker?\nA) Una plataforma para crear y ejecutar contenedores\nB) Un lenguaje de programación\nC) Un tipo de base de datos",
    "¿Qué es Kubernetes?\nA) Un orquestador de contenedores a gran escala\nB) Un tipo de base de datos\nC) Un protocolo de red",
    "¿Qué es la integración continua?\nA) Integrar cambios de código frecuentemente con pruebas automáticas\nB) Desplegar manualmente cada cambio\nC) Un tipo de base de datos",
    "¿Qué es el despliegue continuo?\nA) Desplegar automáticamente cada cambio que pasa las pruebas\nB) Integrar cambios manualmente\nC) Un tipo de red",
    "¿Qué es Git?\nA) Un sistema de control de versiones distribuido\nB) Un lenguaje de programación\nC) Un tipo de base de datos",
    "¿Qué es un commit?\nA) Un registro de cambios en el repositorio\nB) Una rama de Git\nC) Un tipo de merge",
    "¿Qué es una rama en Git?\nA) Una línea independiente de desarrollo\nB) Un commit\nC) Un repositorio remoto",
    "¿Qué es un merge?\nA) La integración de cambios de una rama en otra\nB) Un tipo de commit\nC) Una rama",
    "¿Qué es un pull request?\nA) Una solicitud para revisar e integrar cambios\nB) Un tipo de commit\nC) Una rama de Git",
    "¿Qué es un conflicto en Git?\nA) Un choque entre cambios incompatibles en Git\nB) Un tipo de commit\nC) Una rama",
    "¿Qué es la inteligencia artificial?\nA) La disciplina que busca crear sistemas que imiten la inteligencia humana\nB) Un tipo de base de datos\nC) Un lenguaje de programación",
    "¿Qué es el aprendizaje automático?\nA) El campo que estudia algoritmos que aprenden de datos\nB) Un tipo de red\nC) Un protocolo",
    "¿Qué es el aprendizaje supervisado?\nA) El aprendizaje con datos etiquetados\nB) El aprendizaje sin etiquetas\nC) Un tipo de red neuronal",
    "¿Qué es el aprendizaje no supervisado?\nA) El aprendizaje con datos etiquetados\nB) El aprendizaje con datos sin etiquetas\nC) Un tipo de cifrado",
    "¿Qué es una red neuronal?\nA) Un modelo inspirado en el cerebro con capas de neuronas\nB) Un tipo de base de datos\nC) Un protocolo de red",
    "¿Qué es el deep learning?\nA) El uso de redes neuronales con muchas capas\nB) Un tipo de base de datos\nC) Un protocolo de red",
    "¿Qué es el overfitting?\nA) Cuando un modelo se ajusta demasiado a los datos de entrenamiento\nB) Cuando un modelo no aprende nada\nC) Un tipo de red neuronal",
    "¿Qué es el underfitting?\nA) Cuando un modelo se ajusta demasiado a los datos\nB) Cuando un modelo no captura la complejidad de los datos\nC) Un tipo de cifrado",
    "¿Qué es un dataset?\nA) Una colección de datos usada para entrenar o evaluar\nB) Un tipo de red neuronal\nC) Un lenguaje de programación",
    "¿Qué es la validación cruzada?\nA) Una técnica para evaluar modelos dividiendo los datos en pliegues\nB) Un tipo de red neuronal\nC) Un protocolo de red",
    "¿Qué es una métrica de evaluación?\nA) Una medida para evaluar el desempeño de un modelo\nB) Un tipo de dataset\nC) Un algoritmo de ordenamiento",
    "¿Qué es la precisión?\nA) La proporción de predicciones positivas correctas\nB) La proporción de positivos reales detectados\nC) La media armónica entre precisión y recall",
    "¿Qué es el recall?\nA) La proporción de predicciones positivas correctas\nB) La proporción de positivos reales detectados\nC) Un tipo de red neuronal",
    "¿Qué es el F1-score?\nA) La media armónica entre precisión y recall\nB) Un tipo de dataset\nC) Un protocolo de red",
    "¿Qué es la matriz de confusión?\nA) Una tabla que compara predicciones con valores reales\nB) Un tipo de red neuronal\nC) Un algoritmo de ordenamiento",
    "¿Qué es el procesamiento de lenguaje natural?\nA) El campo que estudia la interacción entre computadoras y lenguaje humano\nB) Un tipo de base de datos\nC) Un protocolo de red",
    "¿Qué es un chatbot?\nA) Un programa que simula conversación con un usuario\nB) Un tipo de red neuronal\nC) Un lenguaje de programación",
    "¿Qué es la visión por computadora?\nA) El campo que permite a las máquinas interpretar imágenes\nB) Un tipo de base de datos\nC) Un protocolo de red",
    "¿Qué es el sesgo algorítmico?\nA) La tendencia de un modelo a favorecer ciertos grupos\nB) Un tipo de red neuronal\nC) Un algoritmo de ordenamiento",
    "¿Qué es la ética en IA?\nA) El estudio de los impactos morales de la IA\nB) Un tipo de red neuronal\nC) Un protocolo de red",
    "¿Qué es un sistema experto?\nA) Un sistema que emula la toma de decisiones de un experto\nB) Un tipo de base de datos\nC) Un lenguaje de programación",
    "¿Qué es un algoritmo genético?\nA) Un algoritmo inspirado en la evolución biológica\nB) Un tipo de red neuronal\nC) Un protocolo de red",
    "¿Qué es la lógica difusa?\nA) Una lógica que permite valores de verdad parciales\nB) Un tipo de base de datos\nC) Un algoritmo de ordenamiento",
    "¿Qué es un agente inteligente?\nA) Una entidad que percibe su entorno y actúa en él\nB) Un tipo de red neuronal\nC) Un protocolo de red",
    "¿Qué es el aprendizaje por refuerzo?\nA) El aprendizaje basado en recompensas y castigos\nB) El aprendizaje con datos etiquetados\nC) Un tipo de cifrado",
    "¿Qué es una función de recompensa?\nA) Una función que indica la utilidad de una acción\nB) Un tipo de red neuronal\nC) Un algoritmo de ordenamiento",
    "¿Qué es un entorno en RL?\nA) El contexto donde un agente actúa y recibe recompensas\nB) Un tipo de base de datos\nC) Un protocolo de red",
    "¿Qué es exploración vs explotación?\nA) El dilema entre probar acciones nuevas o usar las conocidas\nB) Un tipo de red neuronal\nC) Un algoritmo de ordenamiento",
    "¿Qué es un MDP?\nA) Un proceso de decisión de Markov\nB) Un tipo de base de datos\nC) Un protocolo de red",
    "¿Qué es la ingeniería de software?\nA) La disciplina que aplica ingeniería al desarrollo de software\nB) Un tipo de red neuronal\nC) Un protocolo de red",
    "¿Qué es el ciclo de vida del software?\nA) El conjunto de fases por las que pasa un software\nB) Un tipo de base de datos\nC) Un lenguaje de programación",
    "¿Qué es una metodología ágil?\nA) Un enfoque iterativo e incremental de desarrollo\nB) Un tipo de red neuronal\nC) Un protocolo de red",
    "¿Qué es Scrum?\nA) Un marco ágil con roles, eventos y artefactos\nB) Un tipo de base de datos\nC) Un lenguaje de programación",
    "¿Qué es un sprint?\nA) Un periodo fijo de trabajo en Scrum\nB) Un tipo de red neuronal\nC) Un protocolo de red",
    "¿Qué es un product backlog?\nA) La lista priorizada de requisitos del producto\nB) Un tipo de base de datos\nC) Un lenguaje de programación",
    "¿Qué es un daily standup?\nA) Una reunión diaria breve del equipo\nB) Un tipo de red neuronal\nC) Un protocolo de red",
    "¿Qué es una retrospectiva?\nA) Una reunión para reflexionar sobre el sprint\nB) Un tipo de base de datos\nC) Un lenguaje de programación",
    "¿Qué es Kanban?\nA) Un método visual de gestión de flujo de trabajo\nB) Un tipo de red neuronal\nC) Un protocolo de red",
    "¿Qué es un requisito funcional?\nA) Una función que el sistema debe cumplir\nB) Una restricción de calidad\nC) Un tipo de red",
    "¿Qué es un requisito no funcional?\nA) Una función que el sistema debe cumplir\nB) Una restricción de calidad como rendimiento o seguridad\nC) Un tipo de red",
    "¿Qué es un caso de uso?\nA) Una descripción de interacción entre actor y sistema\nB) Un tipo de red neuronal\nC) Un lenguaje de programación",
    "¿Qué es un diagrama UML?\nA) Un lenguaje de modelado visual de sistemas\nB) Un tipo de base de datos\nC) Un protocolo de red",
    "¿Qué es la arquitectura de software?\nA) La estructura de alto nivel de un sistema software\nB) Un tipo de red neuronal\nC) Un lenguaje de programación",
    "¿Qué es el patrón MVC?\nA) Un patrón que separa modelo, vista y controlador\nB) Un tipo de base de datos\nC) Un protocolo de red",
    "¿Qué es un microservicio?\nA) Un servicio pequeño e independiente desplegable\nB) Un tipo de red neuronal\nC) Un lenguaje de programación",
    "¿Qué es un monolito?\nA) Una aplicación construida como una sola unidad\nB) Un tipo de base de datos\nC) Un protocolo de red",
    "¿Qué es la deuda técnica?\nA) El costo acumulado de decisiones de diseño subóptimas\nB) Un tipo de red neuronal\nC) Un lenguaje de programación",
    "¿Qué es la cobertura de pruebas?\nA) El porcentaje de código cubierto por pruebas\nB) Un tipo de base de datos\nC) Un protocolo de red",
    "¿Qué es un bug?\nA) Un error en el software\nB) Un tipo de red neuronal\nC) Un lenguaje de programación",
    "¿Qué es la depuración?\nA) El proceso de encontrar y corregir errores\nB) Un tipo de base de datos\nC) Un protocolo de red",
    "¿Qué es un log?\nA) Un registro de eventos del sistema\nB) Un tipo de red neuronal\nC) Un lenguaje de programación",
    "¿Qué es el monitoreo?\nA) La observación continua del estado del sistema\nB) Un tipo de base de datos\nC) Un protocolo de red",
    "¿Qué es la observabilidad?\nA) La capacidad de entender el estado interno desde afuera\nB) Un tipo de red neuronal\nC) Un lenguaje de programación"
};

static string respuestas[] = {
    "B", "A", "B", "B", "A", "A", "B", "B", "A", "B",
    "A", "B", "A", "A", "B", "A", "A", "B", "B", "A",
    "B", "A", "A", "A", "A", "B", "A", "A", "B", "A",
    "B", "B", "A", "A", "A", "B", "A", "A", "A", "A",
    "A", "A", "A", "A", "A", "A", "B", "A", "A", "A",
    "A", "A", "A", "A", "A", "A", "A", "A", "A", "A",
    "A", "A", "A", "A", "B", "B", "B", "A", "B", "B",
    "A", "A", "A", "B", "A", "B", "A", "B", "A", "A",
    "A", "A", "A", "A", "B", "A", "B", "A", "A", "B",
    "B", "A", "B", "A", "A", "B", "A", "A", "A", "B",
    "B", "A", "A", "A", "A", "A", "A", "B", "A", "A",
    "B", "A", "A", "A", "A", "A", "B", "A", "A", "A",
    "A", "A", "B", "A", "A", "A", "A", "A", "A", "A",
    "A", "A", "A", "A", "A", "B", "A", "A", "A", "A",
    "A", "A", "A", "A", "A", "A", "A", "A", "A", "A",
    "A", "A", "A", "A", "A", "A", "A", "A", "A", "A"
};

int cantidadNombres() { return sizeof(nombres) / sizeof(nombres[0]); }
int cantidadApellidos() { return sizeof(apellidos) / sizeof(apellidos[0]); }
int cantidadNombresCursos() { return sizeof(nombresCursos) / sizeof(nombresCursos[0]); }
int cantidadComplementosCursos() { return sizeof(complementosCursos) / sizeof(complementosCursos[0]); }
int cantidadNombresModulos() { return sizeof(nombresModulos) / sizeof(nombresModulos[0]); }
int cantidadNombresLecciones() { return sizeof(nombresLecciones) / sizeof(nombresLecciones[0]); }
int cantidadContenido() { return sizeof(contenido) / sizeof(contenido[0]); }
int cantidadPreguntas() { return sizeof(preguntas) / sizeof(preguntas[0]); }
int cantidadRespuestas() { return sizeof(respuestas) / sizeof(respuestas[0]); }

string generarNombre() { return nombres[rand() % cantidadNombres()]; }
string generarApellido() { return apellidos[rand() % cantidadApellidos()]; }
string generarCorreo(string nombre, string apellido, int id) { return nombre.substr(0, 1) + apellido.substr(0, 1) + to_string(id) + "@universidad.edu.pe"; }

string generarNombreCurso() { return nombresCursos[rand() % cantidadNombresCursos()] + " " + complementosCursos[rand() % cantidadComplementosCursos()]; }
string generarNombreModulo() { return nombresModulos[rand() % cantidadNombresModulos()]; }
string generarNombreLeccion() { return nombresLecciones[rand() % cantidadNombresLecciones()]; }

string generarContenido() { return contenido[rand() % cantidadContenido()]; }
string generarPreguntas() { return preguntas[rand() % cantidadPreguntas()]; }
string generarRespuestas() { return respuestas[rand() % cantidadRespuestas()]; }

void generarProfesor(ProfesorBST<Profesor>& profesores) {
    int insertados = 0;

    for (int i = 0; i < PROFESORES; i++)
    {
        int id = ProfesorBASE + i; // CORREGIR: si los ids son secuanciales el BST se vuelve desblanceado
        int idCurso = CursoBASE + i;
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

void generarCursos(CursoAVL<Curso>& cursos) {
    int insertados = 0;
    
    for (int i = 0; i < CURSOS; i++)
    {
        vector<int> listaEstudiantes;
        int idCurso = CursoBASE + i;
        int idProfesor = ProfesorBASE + i;
        string nombre = generarNombreCurso();

        Curso newCurso(idCurso, idProfesor, nombre, listaEstudiantes);
        if (cursos.insertar(newCurso)) insertados++;
    }

    if (insertados != CURSOS) {
        cout << "ADVERTENCIA: se insertaron " << insertados << " de " << CURSOS << " cursos\n";
    }
}

void generarEstudiantes(EstudianteHashTable<Estudiante>& estudiantes, ProfesorBST<Profesor>& profesores, CursoAVL<Curso>& cursos) {
    int insertados = 0;
    Curso* curso;
    for (int i = 0; i < ESTUDIANTES; i++)
    {
        int id = EstudianteBASE + i;
        int intentos = 0;
        do {
            curso = cursos.getCurso(rand() % CURSOS + CursoBASE);
            intentos++;
        } while (curso == nullptr && intentos < CURSOS);

        int idCurso = curso->getIdCurso();
        int idProfesor = curso->getIdProfesor();
        cursos.getCurso(idCurso)->agregarEstudiante(id);

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

void generarModulosEvaluaciones(ModuloAVL<Modulo>& modulos, CursoAVL<Curso>& cursos) { //Tambien generar evaluaciones
    int insertados = 0;
    Curso* curso;
    for (int i = 0; i < MODULOS; i++)
    {
        int idModulo = ModuloBASE + i;
        int intentos = 0;
        do {
            curso = cursos.getCurso(rand() % CURSOS + CursoBASE);
            intentos++;
        } while (curso == nullptr && intentos < CURSOS);

        int idCurso = curso->getIdCurso();
        cursos.getCurso(idCurso)->agregarModulo(idModulo);
        string nombre = generarNombreModulo();
        vector<int> listaLecciones;

        int idEvaluacion = EvaluacionBASE + i;
        int idx1 = rand() % cantidadPreguntas();
        int idx2 = rand() % cantidadPreguntas();
        Evaluacion newEvaluacion(idEvaluacion, idModulo, preguntas[idx1], preguntas[idx2], respuestas[idx1], respuestas[idx2]);
        Modulo newModulo(idModulo, idCurso, nombre, newEvaluacion, listaLecciones);
        if (modulos.insertar(newModulo)) insertados++;
    }
    if (insertados != MODULOS) {
        cout << "ADVERTENCIA: se insertaron " << insertados << " de " << MODULOS << " modulos\n";
    }
}

void generarLeccionesEjercicios(LeccionListaDoble<Leccion>& lecciones, EjercicioHashTable<Ejercicio>& ejercicios, ModuloAVL<Modulo>& modulos) {
    int leccionesInsertadas = 0;
    int ejerciciosInsertados = 0;
    Modulo* modulo;

    for (int i = 0; i < LECCIONES; i++)
    {
        int idLeccion = LeccionBASE + i;
        int intentos = 0;
        do {
            modulo = modulos.getModulo(rand() % MODULOS + ModuloBASE);
            intentos++;
        } while (modulo == nullptr && intentos < MODULOS);

        int idModulo = modulo->getIdModulo();
        modulos.getModulo(idModulo)->agregarLeccion(idLeccion);
        string nombre = generarNombreLeccion();
        string contenidoLeccion = generarContenido();
        vector<int> idsEjercicios;

        for (int j = 0; j < 2; j++)
        {
            int idEjercicio = EjercicioBASE + j + (i * 2);

            int idxPregunta = rand() % cantidadPreguntas();
            string enunciado = preguntas[idxPregunta];
            string respuesta = respuestas[idxPregunta];

            Ejercicio newEjercicio(idEjercicio, idLeccion, enunciado, respuesta);
            if (ejercicios.insertar(newEjercicio)) ejerciciosInsertados++;
            idsEjercicios.push_back(idEjercicio);
        }

        Leccion newLeccion(idLeccion, idModulo, nombre, contenidoLeccion, idsEjercicios);
        if (lecciones.insertar(newLeccion)) leccionesInsertadas++;
    }
    if (leccionesInsertadas != LECCIONES) {
        cout << "ADVERTENCIA: se insertaron " << leccionesInsertadas << " de " << LECCIONES << " lecciones\n";
    }
    if (ejerciciosInsertados != EJERCICIOS) {
        cout << "ADVERTENCIA: se insertaron " << ejerciciosInsertados << " de " << EJERCICIOS << " ejercicios\n";
    }

}