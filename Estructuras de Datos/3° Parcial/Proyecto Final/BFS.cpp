#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

bool esCaminoHamiltoniano(int matrizAdyacencia[MAX_VERTICES][MAX_VERTICES], int camino[], int numVertices) {
    // Verificar si existe una arista entre el último vértice y el primero
    if (matrizAdyacencia[camino[numVertices - 1]][camino[0]] == 0)
        return false;

    // Verificar si hay una arista entre cada par consecutivo de vértices en el camino
    for (int i = 0; i < numVertices - 1; ++i) {
        if (matrizAdyacencia[camino[i]][camino[i + 1]] == 0)
            return false;
    }

    return true;
}

void mostrarCaminoHamiltoniano(int camino[], int numVertices) {
    printf("Camino Hamiltoniano encontrado: ");
    for (int i = 0; i < numVertices; ++i) {
        printf("%d ", camino[i]);
    }
    printf("%d\n", camino[0]);
}

void encontrarCaminoHamiltoniano(int matrizAdyacencia[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int camino[MAX_VERTICES];
    for (int i = 0; i < numVertices; ++i) {
        camino[i] = i;
    }

    do {
        if (esCaminoHamiltoniano(matrizAdyacencia, camino, numVertices)) {
            mostrarCaminoHamiltoniano(camino, numVertices);
            return;
        }
    } while (next_permutation(camino, camino + numVertices));
    
    printf("No se encontró camino hamiltoniano.\n");
}

int main() {
    int numVertices = 8; // Cambiar al número de vértices en tu grafo
    int matrizAdyacencia[MAX_VERTICES][MAX_VERTICES] = {
        // Inserta tu matriz de adyacencia aquí
        // Ejemplo: {{0, 1, 1, 0, 0, 1}, {1, 0, 0, 1, 1, 0}, ...}
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 1},
        {0, 0, 1, 0, 0, 0, 1, 1},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {0, 1, 0, 0, 1, 0, 1, 0},
        {0, 0, 1, 1, 1, 1, 0, 1},
        {0, 0, 1, 1, 0, 0, 1, 0 }
    };
    int inicio = 0; // Cambiar el vértice inicial según sea necesario

    encontrarCaminoHamiltoniano(matrizAdyacencia, numVertices);

    return 0;
}
