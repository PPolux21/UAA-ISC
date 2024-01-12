#include <iostream>
#include <stdio.h>
#include <ctype.h>
using namespace std;

struct ListaCaminos
{
    ListaCaminos* anterior;
    int id;
    ListaCaminos* siguiente;
};

int verificarFile(FILE* archivo1);
void creaMatrizAdyacencia(int m, int numLetrasUnicas, char letrasUnicas[], char lets[][2]);
//void redesInteresantes(int cantRedes); 
//bool nodoExistente(ListaCaminos* ,int);
void mostrarVertices();
void mostrarAristas();
void mostrar();

int **matAdyacencia;
int numLetrasUnicas = 0;

int main() {
    FILE* archivo1;

    int cantRedes = verificarFile(archivo1);
    //redesInteresantes(cantRedes);
    mostrar();
    return 0;
}

int verificarFile(FILE* archivo1){
    int m;
    archivo1 = fopen("RED.DAT", "r");
    //si el archivo no existe
    if (archivo1 == NULL) {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }
    //si no se puso el numero de conexiones
    if (fscanf(archivo1, "%d\n", &m) != 1) {
        cout << "Error al leer el numero de conexiones." << endl;
        fclose(archivo1);
        exit(1);
    }
    //si el numero de conexiones excede el limite
    if (m < 1 || m > 99) {
        cout << "Error: El numero de conexiones no esta en el rango valido (1 <= m <= 99)." << endl;
        fclose(archivo1);
        exit(1);
    }
    char lets[m][2]; //matriz de m filas y 2 columnas
    char c1, c2; //para leer las letras de cada conexion
    int tam = 0;
    
    for (int i = 0; i < m; ++i) {
        // Leer dos letras y verificar que no haya numeros en la conexion
        if (fscanf(archivo1, " %c %c\n", &c1, &c2) != 2 || (!isalpha(c1) || !isalpha(c2))) {
            cout << "Error en la conexion " << i + 1 << ": solo puede haber 2 letras y no debe tener numeros." << endl;
            fclose(archivo1);
            exit(1);
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
            exit(1);
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

    //  regiones = conexiones - vertices + 1;
    int cantRedes = m - numLetrasUnicas + 1;//se obtiene la cantidad total de redes posibles en el grafo

    return cantRedes; 
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
                matAdyacencia[i][j] = 0; // No hay conexion
            } else {
                matAdyacencia[i][j] = -1; // Conexion consigo mismas
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
}
/*
void redesInteresantes(int cantRedes)
{
    ListaCaminos **redes = new ListaCaminos* [cantRedes];//un vector de apuntadores a las redes interesantes
    ListaCaminos *aux = NULL, *raiz = NULL, *nuevo = NULL;//auxiliar que alamcenará temporalmente el camino encontrado, luego el vector loo hará
    int terminado = 0;
    int inicio;
    bool camino = true;

    while (terminado != cantRedes)
    {
        for (int i = 0; i < numLetrasUnicas; i++)
        {
            inicio = i;
            for (int j = 0; j < numLetrasUnicas; j++)
            {
                if (camino)
                {
                    camino = false;
                                
                    if (aux->anterior != NULL)
                    {
                        if (j != aux->anterior->id)
                        {
                            if (matAdyacencia[inicio][j] == 1)
                            {
                                inicio = j;
                                j = 0;
                                camino = true;
                                
                                if (inicio == raiz->id)
                                {
                                    raiz->anterior = aux;
                                    aux->siguiente = raiz;
                                    redes[terminado] = raiz;
                                    terminado++;
                                    raiz=NULL;
                                    aux=NULL;
                                    nuevo=NULL;
                                    break;
                                }
                                if (nodoExistente(raiz,inicio))
                                {
                                    camino = false;
                                    raiz=NULL;
                                    aux=NULL;
                                    nuevo=NULL;
                                    break;
                                }
                                

                                nuevo = new ListaCaminos;
                                aux->siguiente = nuevo;
                                nuevo->anterior = aux;
                                nuevo->siguiente = NULL;
                                nuevo->id = inicio;
                                aux = nuevo;
                                
                                

                            }
                        }
                        
                    }
                    
                }else{
                    raiz=NULL;
                    aux=NULL;
                    nuevo=NULL;
                    break;
                }
                
            }
            
        }
        
    }
       
}

bool nodoExistente(ListaCaminos* raiz,int indice)
{
    bool repetido = false;
    ListaCaminos* aux;
    if (raiz->siguiente == NULL)
    {
        repetido = raiz->id == indice;
    }else{
        aux = raiz;

        repetido = aux->id == indice;

        aux = aux->siguiente;

        while (aux != NULL)
        {
            repetido = aux->id == indice;

            aux = aux->siguiente;
        }
        
    }
    return repetido;
}
*/
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
