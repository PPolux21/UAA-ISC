# Proyecto: Buddy System y Round Robin

## Integrantes del Equipo

- [José Luis Espinoza Sánchez](https://github.com/PPolux21).
- Cindy Fabiola Hernández Muñoz.
- Reyli Uvaldo Martínez Hernández.
- Uriel Ezequiel Ortiz Rosales.

## Descripción

Implementacion de los argoritmos **Round Robin** (**`RR`**) y **Buddy System** (**`BS`**) para simular el comportamiento dinamico de un sistema computacional.

**Buddy System** se encarga de gestionar la asignación de memoria de manera eficiente. Este algoritmo divide la memoria en bloques de tamaño potencia de dos, manteniendo un árbol binario que refleja la disponibilidad de cada bloque.

**Round Robin** administra la ejecución de procesos. Asigna un tiempo de CPU fijo a cada proceso en secuencia, garantizando oportunidades equitativas de ejecución, además de usar una cola de procesos para determinar el siguiete a ejecutar.

## Entregables

- **Video**:  
    Demostrando y explicando el funcionamiento del programa.  
    *Mostrar 3 escenarios de condensación y también varios escenarios de `RR` (a elección personal) cuando un proceso no entra en memoria.*

- **Software**:  
    Paquete instalador del sistema simulador para windows.  
    *Carpeta con archivos fuente y/o proyecto.*

- **Manual de usuario**.

- **Reporte**:

   Estructura:

  - Portada.

  - Índice.

  - Introducción.

  - Contenido.

    - `BS` Implementación conceptual y codigo.

    - `RR` Implementación conceptual y codigo.

  - Conclusiones (Individuales y equipo).

  - Bibliografía.

  - Anexo A, instrucciones detalladas para la compilación del proyecto.

## Proyecto

### Interfaz

- De texto (**requerida**)
- Gráfica (**opcional**)
- Mostrar en TODO momento información de la lista de procesos (`RR`).
- Mostrar en TODO momento una representación de la memoria (`BS`).

### Configuración de parámetros

- Cuanto máximo de los procesos.
- Tamaño máximo de memoria de los procesos.
- Cuanto del sistema.

### Constantes (`BS`)

- Tamaño de la memoria principal (fijo a 1024, 4096 o 8192 KB)
- Tamaño mínimo de split (`BS`) 32 KB

### Procesos

- La generación debe de ser aleatoria y automática
- **SIEMPRE** debe de haber un proceso listo a entrar

### Estadísticas

- Posterior a la ejecución.  
    *Ej. Número total de procesos atendidos, porcentaje de memoria ocupada, etc.*

- Principales Indicadores  durante la ejecución (**opcional**).

### Velocidad

- El usuario deberá de controlar la velocidad de ejecución a la que se realiza la simulación.

### Condición de paro

- El usuario debe de controlar en qué momento se detiene la simulación.
