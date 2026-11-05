# TB2 2026-2 — Algoritmos y Estructuras de Datos (1ACC0182)

## 1. Datos generales

| Campo | Detalle |
|---|---|
| Curso | 1ACC0182 — Algoritmos y Estructuras de Datos |
| Trabajo | Trabajo 2 (TB2) — Trabajo Final 2026-2 |
| Entrega final | 29 de noviembre de 2026 |
| Ciclo | 2026-2 |
| Equipos | 3 integrantes |
| Entrega en plataforma | Individual |

---

## 2. Objetivo y logro del curso

**Objetivo:** aplicar conocimientos de análisis y diseño de tipos de datos abstractos y técnicas sistemáticas basadas en matemáticas para construir aplicaciones basadas en el procesamiento eficiente de grandes volúmenes de datos.

**Logro del curso:** al finalizar, el estudiante construye aplicaciones para el manejo de grandes cantidades de datos de manera ingeniosa.

**Contribución ABET:**
- **Ingeniería de Software — Student Outcome 2:** aplicar diseño de ingeniería para producir soluciones que satisfagan necesidades específicas considerando salud pública, seguridad, bienestar y factores globales, culturales, sociales, ambientales y económicos.
- **Ciencias de la Computación — Student Outcome 2:** diseñar, implementar y evaluar una solución basada en computación para cumplir requisitos computacionales en el contexto de la disciplina.

---

## 3. Enunciado del Trabajo 2

Implementar una **aplicación minimalista en consola** basada en el caso de estudio asignado a cada grupo, integrando los conceptos desarrollados en clase: POO, programación genérica, estructuras de datos, funciones hash, árboles balanceados, grafos, ordenamientos avanzados, recursividad, lambdas, archivos y generador de dataset.

### 3.1. Tabla de aplicaciones

| Aplicación | Ejemplo de referencia | Estructuras sugeridas |
|---|---|---|
| Red profesional y recomendaciones | LinkedIn |- Hash table (perfiles)<br>- Árbol binario balanceado (habilidades)<br>- Grafo de adyacencia (conexiones)<br>- Cola (solicitudes)<br>- Pila (acciones recientes)<br>- QuickSort (ordenar contactos)<br>- Recursividad (búsqueda de conexiones)<br>- Archivos (perfiles) |
| Gestión de alojamientos y reservas | Airbnb |- Árbol binario balanceado (propiedades)<br>- Hash table (disponibilidad por fechas)<br>- Cola de prioridad / montículo (alojamientos destacados)<br>- Lista doble (historial de cambios)<br>- MergeSort (ordenar precios)<br>- Recursividad (filtrado por criterios)<br>- Archivos (reservas) |
| Issues, commits y repositorios | GitHub |- Hash table (commits)<br>- Árbol binario balanceado (estructura de archivos)<br>- Grafo dirigido acíclico (ramas y merges)<br>- Cola (notificaciones)<br>- HeapSort (prioridad de PRs)<br>- Recursividad (recorrido de ramas)<br>- Archivos (repositorios) |
| Navegación colaborativa | Waze |- Grafo ponderado (red vial)<br>- Hash table (alertas de tráfico)<br>- Árbol binario balanceado (puntos de interés)<br>- Cola (reportes de tráfico)<br>- QuickSort (ordenar rutas por tiempo)<br>- Recursividad (búsqueda de rutas)<br>- Archivos (historial de tráfico) |
| Procesamiento de pagos | Stripe |- Hash table (transacciones)<br>- Árbol binario balanceado (historial histórico)<br>- Cola de prioridad / montículo (pagos pendientes)<br>- Pila (auditorías)<br>- MergeSort (ordenar montos)<br>- Recursividad (verificación de registros)<br>- Archivos (movimientos) |
| Base de datos de cine | IMDb |- Hash table (catálogo)<br>- Árbol binario balanceado (búsqueda por año/director)<br>- Grafo (relaciones actor-película)<br>- Cola (tendencias del día)<br>- HeapSort (popularidad)<br>- Recursividad (relaciones complejas)<br>- Archivos (catálogo) |
| **Plataforma educativa** | **Khan Academy** | **- Árbol binario balanceado (módulos y lecciones)<br>- Hash table (progreso de estudiantes)<br>- Grafo de dependencias (evaluación adaptativa)<br>- Cola (ejercicios pendientes)<br>- MergeSort (ordenar progreso)<br>- Recursividad (evaluación adaptativa)<br>- Archivos (historial)** |
| Seguimiento deportivo | Garmin Connect |- Hash table (telemetría)<br>- Árbol binario balanceado (sesiones de entrenamiento)<br>- Grafo (coordenadas de rutas GPS)<br>- Lista circular (actividades diarias)<br>- QuickSort (ordenar tiempos)<br>- Recursividad (patrones de entrenamiento)<br>- Archivos (registros) |
| Recomendación visual | Pinterest |- Hash table (tableros y colecciones)<br>- Árbol binario balanceado (categorías visuales)<br>- Grafo de similitud (afinidad de pines)<br>- Cola (recomendaciones)<br>- MergeSort (popularidad)<br>- Recursividad (similitud entre pines)<br>- Archivos (colecciones) |
| Mensajería colaborativa | Slack |- Hash table (canales y usuarios)<br>- Árbol binario balanceado (hilos de conversación)<br>- Grafo (menciones e interacciones)<br>- Lista doble (mensajes)<br>- Pila (ediciones)<br>- QuickSort (actividad de canales)<br>- Recursividad (hilos de conversación)<br>- Archivos (historial) |

---

## 4. Requisitos técnicos obligatorios

1. **Paradigma y entidades**
   - Desarrollar bajo **POO** y **Programación Genérica**.
   - Al menos **5 entidades por cada integrante** del grupo, considerando relaciones.
   - Adjuntar **diagrama de clases UML** con atributos y métodos.
2. **Estructuras de datos**
   - Implementar al menos **3 estructuras de datos distintas**:
     - listas enlazadas simples, dobles, circulares,
     - pilas, colas,
     - hash tables,
     - árboles binarios de búsqueda.
   - Justificar su uso correcto.
   - Como mínimo **una estructura por integrante**.
3. **Funciones hash**
   - Crear una **función hash propia compleja**.
4. **Árboles balanceados**
   - Elaborar como mínimo **2 árboles balanceados**.
5. **Templates**
   - Todas las estructuras deben ser genéricas, implementadas con **templates**.
6. **Lambdas**
   - Usar mínimo **3 funciones lambda por integrante**.
7. **Métodos por estructura**
   - Cada estructura de datos debe tener al menos **3 métodos implementados por cada integrante**, diferentes a los vistos en clase.
   - Ejemplos: insertar, ordenar, buscar.
8. **Ordenamientos**
   - Implementar un algoritmo de ordenamiento avanzado por cada integrante:
     - MergeSort,
     - QuickSort,
     - HeapSort.

9. **Dataset**
   - Implementar un **generador de dataset propio** para alimentar la aplicación.

10. **Interfaz**
    - La aplicación debe presentarse en **consola**, cuidando usabilidad y estética para asemejarse a sistemas reales.

---

## 5. Hitos y fechas

### Hito 1 — Semana 13
**Fecha:** domingo 22 de noviembre de 2026  
**Puntaje:** 5 puntos

Incluye:
- Diagrama de clases UML con relaciones, atributos y métodos.
- Análisis Big O de **7 funciones principales** de la aplicación, explicado detalladamente.
- Uso de:
  - templates,
  - recursividad,
  - lambdas,
  - estructuras de datos,
  - ordenamientos avanzados,
  - implementación de Hash Table,
  - generador de dataset.

**Formato de entrega Hito 1:**
- Comprimir todos los archivos `*.h` y `*.cpp`.
- Nombre: `TB2_Hito1_Código_Apellidos_Nombres.zip`

---

### Hito 2 — Semana 14
**Fecha:** domingo 29 de noviembre de 2026  
**Puntaje:** 15 puntos

Incluye:
- Uso de árboles binarios y grafos.
- Diseño de la aplicación en consola con estética mejorada.
- Tabla de autoevaluación de aportes:
  - nombres de integrantes,
  - descripción de tareas,
  - autovaloración en porcentaje.

**Nota del Trabajo Final = Nota Hito 1 + Nota Hito 2.**

---

## 6. Entregables obligatorios del Hito 2

| Entregable | Formato | Nombre del archivo |
|---|---|---|
| Código | ZIP con todos los `*.h` y `*.cpp` | `TB2_Código_Apellidos_Nombres.zip` |
| Informe | Word `.doc` o `.docx`, según modelo del aula virtual | `TB2 Informe_Apellidos_Nombre_Codigo.docx` |
| Código en texto | Bloc de notas con todo el código organizado | `TB2_TXT_Apellidos_Nombre_Codigo.txt` |

---

## 7. Tabla de autoevaluación

Debe incluirse en el Hito 2. Ejemplo de estructura:

| Nombre | Tareas | Autovaloración |
|---|---|---|
| Juan Perez | Implementación de los métodos insertar, ordenar y buscar en la lista enlazada circular | 100% |
| … | … | … |

---

## 8. Criterios de calificación

| Criterio | Requisitos | Puntos |
|---|---|---|
| Identificación de necesidades específicas del algoritmo | A. Planteamiento de nuevas funcionalidades del caso de estudio y diagrama de clases UML en Word | 3 |
| Diseño del algoritmo | B. Uso de estructuras de datos en la implementación y desarrollo de 3 métodos por integrante en las estructuras | 3 |
| Implementación del algoritmo | C. Aplicación de Hash Table e implementación de función hash propia | 3 |
| Justificación del algoritmo | D. Implementación de árbol binario (1.5) <br> E. Implementación de árbol binario balanceado (1.5) | 3 |
| Desarrollo de solución en computación | F. Generador de dataset (1.5) <br> G. Implementación de grafos con funcionalidades (1.5) | 3 |
| Mantenimiento del algoritmo | H. Ordenamientos avanzados, mínimo un par por integrante (1) <br> I. Justificación de cada estructura y complejidad Big O (1) <br> J. Exposición y argumentación individual (1) <br> K. Informe TB2 (1) <br> L. Código en TXT (1) | 5 |

---

## 9. Lineamientos de presentación y exposición

- La exposición del **Hito 2** se realiza en la **primera sesión de la semana 15**.
- Solo exponen los grupos que hayan realizado el **envío formal por Blackboard**.
- Si el grupo expone y no envió, o envió y no expuso: **nota CERO (0)**.
- Todos los integrantes deben conocer **toda la implementación**.
- El docente puede pedir a cualquier integrante demostrar dominio del código; si no lo hace, su nota será penalizada.

---

## 10. Uso de asistentes IA y probidad académica

### Uso de IA
- El uso de IA **no otorga puntaje adicional**.
- Si se usa IA, debe declararse explícitamente:
  - sección donde se aplicó,
  - respaldo con una **bitácora detallada**,
  - la bitácora será evaluada en la defensa oral.
- Omitir o encubrir su uso se considera **falta académica**.

### Probidad académica
Se considera falta grave:
- plagio total o parcial,
- copia entre grupos,
- falseamiento de datos,
- presentar trabajos ajenos sin atribución,
- presentar el mismo trabajo en otra asignatura sin consentimiento,
- suplantación de identidad,
- alterar o sustraer evaluaciones, registros o documentos académicos,
- vender, adquirir o divulgar contenidos de evaluaciones,
- mentir sobre grado, nivel académico o nivel de inglés,
- promover información para obtener ventaja en evaluaciones.

**Sanción:** nota **CERO (0)** para todos los involucrados, conforme a los reglamentos institucionales.
