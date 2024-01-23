#include <iostream>
#include <stdio.h>
#include <ctype.h>
using namespace std;

void verificarFile(FILE* archivo1);
void creaMatrizAdyacencia(int m, int numLetrasUnicas, char letrasUnicas[], char lets[][2]);
void dibujarGrafo(int numLetrasUnicas, char letrasUnicas[], int** matAdyacencia);
void encontrarRedMaximal(int numLetrasUnicas, char letrasUnicas[], int** matAdyacencia);
bool estaEnConjunto(string conjunto[], int tam, const string& subred);
void agregarAlConjunto(string conjunto[], int& tam, const string& subred);
void mostrarVertices();
void mostrarAristas();
void mostrar();
int **matAdyacencia;
int numLetrasUnicas = 0;

int main() {
    FILE* archivo1;
    verificarFile(archivo1);
    return 0;
}

void verificarFile(FILE* archivo1){
    int m;
    archivo1 = fopen("RED.DAT", "r");
    //si el archivo no existe
    if (archivo1 == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }
    //si no se puso el numero de conexiones
    if (fscanf(archivo1, "%d\n", &m) != 1) {
        cout << "Error al leer el numero de conexiones." << endl;
        fclose(archivo1);
        return;
    }
    
    // Mover el puntero al inicio de las conexiones
    fseek(archivo1, 0, SEEK_CUR);
    
    //si el numero de conexiones excede el limite
    if (m < 1 || m > 99) {
        cout << "Error: El numero de conexiones no esta en el rango valido (1 <= m <= 99)." << endl;
        fclose(archivo1);
        return;
    }
    char c1, c2; //para leer las letras de cada conexion
    char lets[m][2]; //matriz de m filas y 2 columnas
    
    for (int i = 0; i < m; ++i) {
        // Leer dos letras y verificar que no haya numeros en la conexion
        if (fscanf(archivo1, " %c %c\n", &c1, &c2) != 2 || (!isalpha(c1) || !isalpha(c2))) {
            cout << "Error en la conexion " << i + 1 << ": solo puede haber 2 letras y no debe tener numeros." << endl;
            fclose(archivo1);
            return;
        }
        lets[i][0] = c1;
        lets[i][1] = c2;
    }
    // Verificar que solo haya dos letras y un espacio en cada linea
    char buffer[3]; //para leer dos caracteres y un espacio
    while (fgets(buffer, sizeof(buffer), archivo1) != NULL) {
        if (sscanf(buffer, " %c %c", &c1, &c2) != 2 || !isspace(buffer[2])) //verifica que se hayan leido exactamente dos caracteres
		{
            cout << "Error: El formato de la conexion no es valido." << endl;
            fclose(archivo1);
            return;
        }
    }

    // Se mostrara el contenido solo si el archivo cumple con los requisitos
    cout << "Numero de conexiones: " << m << endl;
    for (int i = 0; i < m; ++i) {
        cout << lets[i][0] << " " << lets[i][1] << endl;
    }
    
    char letrasUnicas[26] = {0}; // Arreglo para almacenar letras unicas

    for (int i = 0; i < m; ++i) {
    	//Verifica si la letra de la conexion lets no ha sido encontrada antes
        if (!letrasUnicas[lets[i][0] - 65]) {
            letrasUnicas[lets[i][0] - 65] = 1;
            numLetrasUnicas++;
        }
        if (!letrasUnicas[lets[i][1] - 65]) {
            letrasUnicas[lets[i][1] - 65] = 1;
            numLetrasUnicas++;
        }
    }
	
    cout<<endl;
    cout << "Matriz de adyacencia orden " << numLetrasUnicas << endl;

    fclose(archivo1);
    
    creaMatrizAdyacencia(m, numLetrasUnicas, letrasUnicas, lets);
}


void creaMatrizAdyacencia(int m, int numLetrasUnicas, char letrasUnicas[], char lets[][2]) {
    // Crear la matriz de adyacencia con el n�mero de filas y columnas igual al numero de letras unicas
    matAdyacencia = new int*[numLetrasUnicas];
    for (int i = 0; i < numLetrasUnicas; i++) {
        matAdyacencia[i] = new int[numLetrasUnicas];
    }

    for (int i = 0; i < numLetrasUnicas; i++) {
        for (int j = 0; j < numLetrasUnicas; j++) {
            if (i != j) {
                matAdyacencia[i][j] = 8; // No hay conexion
            } else {
                matAdyacencia[i][j] = 0; // Conexion consigo mismas
            }
        }
    }
	
	//Calcula el indice correspondiente a la letra
    for (int i = 0; i < m; i++) {
        int indice1 = lets[i][0] - 65;
        int indice2 = lets[i][1] - 65;

        matAdyacencia[indice1][indice2] = 1;
        matAdyacencia[indice2][indice1] = 1;
    }

    cout << endl;
    for (int i = 0; i < numLetrasUnicas; i++) {
        for (int j = 0; j < numLetrasUnicas; j++) {
            cout << matAdyacencia[i][j] << " ";
        }
        cout << endl;
    }
    dibujarGrafo(numLetrasUnicas, letrasUnicas, matAdyacencia);
}

void dibujarGrafo(int numLetrasUnicas, char letrasUnicas[], int** matAdyacencia) {
	cout<<endl;
    cout << "Grafo" << endl;
    mostrar();
    cout<<endl;
    encontrarRedMaximal(numLetrasUnicas, letrasUnicas, matAdyacencia);
}


void encontrarRedMaximal(int numLetrasUnicas, char letrasUnicas[], int** matAdyacencia) {
    cout << endl << "Subredes Maximales:" << endl;
    FILE* res;
    
    res = fopen("RED.RES", "w");
    
    if(res == NULL){
    	cout << "No se pudo abrir el archivo";
    	return;
	}

    // Conjunto para almacenar subredes ya impresas
    const int MAX_SUBREDES = 100; // Puedes ajustar este valor seg�n sea necesario
    string subredesImpresas[MAX_SUBREDES];
    int tamConjunto = 0;

    for (int i = 0; i < numLetrasUnicas; i++) {
        bool inSubred = false;
        int onesBefore = 0;
        int onesAfter = 0;

        for (int j = 0; j < numLetrasUnicas; j++) {
            if (matAdyacencia[i][j] == 1) {
                // Verifica si hay 1 a la izquierda del -1
                if (j == 0 || (j > 0 && matAdyacencia[i][j - 1] == 8)) {
                    // Hay 0 o como m�ximo un 1 a la izquierda
                    onesBefore++;
                } else {
                    break;  // M�s de un 1 a la izquierda, no es una subred v�lida
                }
            } else if (matAdyacencia[i][j] == 0) {
                // Verifica si hay 2 o m�s 1 a la derecha del 0 hasta el fin del rengl�n
                for (int k = j + 1; k < numLetrasUnicas; k++) {
                    if (matAdyacencia[i][k] == 1) {
                        onesAfter++;
                        if (onesAfter >= 2) {
                            // Encontr� una subred m�xima con puros 0 o como m�ximo un 1 a la izquierda y 2 o m�s 1 a la derecha del 0
                            inSubred = true;
                            break;  // Sale del bucle interno al encontrar una subred
                        }
                    } else if (matAdyacencia[i][k] == 0) {
                        // Fin de la subred
                        break;
                    }
                }
            }
        }

        // Verificar si la subred ya fue impresa y si no es as�, imprimir y agregar al conjunto
        if (inSubred) {
            // Construir la cadena que representa la subred para comparaci�n
            string subredStr;
            for (int k = 0; k < numLetrasUnicas; k++) {
                if (matAdyacencia[i][k] == 1 || matAdyacencia[i][k] == 0) {
                    subredStr += static_cast<char>(k + 'A');
                    
                }
            }

            // Verificar si la subred ya fue impresa
            if (!estaEnConjunto(subredesImpresas, tamConjunto, subredStr)) {
                // Imprime la subred m�xima con todas las letras en el rengl�n
                cout << "Subred Maximal: ";
                for (int k = 1; k < numLetrasUnicas; k++) {
                    if (matAdyacencia[i][k] == 1 || matAdyacencia[i][k] == 0) {
                        cout << static_cast<char>(k + 'A') << " ";
                        fprintf(res, "%c ", static_cast<char>(k + 'A'));
                    }
                }
                fprintf(res, "%c", '\n');
                cout << endl;

                // Agregar la subred al conjunto
                agregarAlConjunto(subredesImpresas, tamConjunto, subredStr);
            }
        }
    }
}

bool estaEnConjunto(string conjunto[], int tam, const string& subred) {
    for (int i = 0; i < tam; i++) {
        if (conjunto[i] == subred) {
            return true;
        }
    }
    return false;
}

// Funci�n para agregar una cadena al conjunto
void agregarAlConjunto(string conjunto[], int& tam, const string& subred) {
    conjunto[tam++] = subred;
}


void mostrarVertices() {
    printf("Vértices del grafo:\n");
    for (int i = 0; i < numLetrasUnicas; ++i) {
        printf("%c ", i+65);
    }
    printf("\n");
}

void mostrarAristas() {
    printf("\nAristas del grafo:\n");
    for (int i = 0; i < numLetrasUnicas; ++i) {
        for (int j = i + 1; j < numLetrasUnicas; ++j) {
            if (matAdyacencia[i][j] == 1) {
                printf("(%c, %c) ", i+65, j+65);
            }
        }
    }
    printf("\n");
}

void mostrar() {
    // Matriz de adyacencia del grafo no dirigido
    mostrarVertices();
    mostrarAristas();
}