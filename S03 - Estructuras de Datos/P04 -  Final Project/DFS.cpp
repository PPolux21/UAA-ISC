#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
using namespace std;

struct Camino
{
    Camino* ant;
    int id;
    Camino* sig;
};


void verificarFile(FILE* archivo1);
void creaMatrizAdyacencia(int m,char letrasUnicas[], char lets[][2]);
int obtieneNoCandidatos(int* noCandidatos);
Camino **obtieneRedes(int* noCandidatos,int cantNoCandidatos);
Camino *recorreCamino(Camino *camino,Camino *fin,int verticeActual, int verticeInicial,int &pos,int **matRedes);
int **llenaMatRedes(int **matRedes,int* noCandidatos,int cantNoCandidatos);
bool enCamino(int id,Camino *camino);
int **matAdyacencia;
int numLetrasUnicas = 0;


int main() {
    FILE* archivo1;
    int *noCandidatos;
    int cantNoCandidatos;
    Camino **caminos;
    verificarFile(archivo1);

    noCandidatos = new int [numLetrasUnicas];
    cantNoCandidatos = obtieneNoCandidatos(noCandidatos);
    caminos = obtieneRedes(noCandidatos, cantNoCandidatos);

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
    
    creaMatrizAdyacencia(m, letrasUnicas, lets);
}


void creaMatrizAdyacencia(int m, char letrasUnicas[], char lets[][2]) {
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
}

int obtieneNoCandidatos(int* noCandidatos)//se obtienen los vertices posibles a estar dentro de una red maximal
{
    int cantUnos;
    int numCandidato = 0;
    for (int i = 0; i < numLetrasUnicas; i++)
    {
        cantUnos = 0;
        for (int j = 0; j < numLetrasUnicas; j++)
        {
            if (matAdyacencia[i][j] == 1)
            {
                cantUnos++;
            }
        }
        
        if (cantUnos >= 2)//son todos aquillos que tienen una
        {
            noCandidatos[numCandidato++] = i;
            cout<< (char)(i+65)<< " ";
        }
        
    }
    //regresa la cantidad de vertices noCandidatos
    return numCandidato; 
}

Camino **obtieneRedes(int* noCandidatos,int cantNoCandidatos)
{
    //bool revisados[cantNoCandidatos];
    Camino **caminosTotales;
    int **matRedes;
    Camino *camino;
    int tam;

    caminosTotales = new Camino* [cantNoCandidatos];

    matRedes = llenaMatRedes(matRedes,noCandidatos,cantNoCandidatos);

    for (int i = 0; i < cantNoCandidatos; i++)
    {
        cout<< endl;

        camino = new Camino;
        camino->sig = NULL;
        
        /*for (int j = 0; j < cantNoCandidatos; j++)
        {
            revisados[j] = false;
        }*/
        
        tam = 0;
        camino = recorreCamino(camino,camino,i,i,tam,matRedes);
        
        
    
        
        caminosTotales[i] = camino;
        camino = NULL;
        
    }
    delete camino;
    return (caminosTotales);
}

Camino *recorreCamino(Camino *camino,Camino *fin,int verticeActual, int verticeInicial,int &pos, int **matRedes)
{
    Camino *nuevo = new Camino;
    fin->id = verticeActual;
    //int aux=pos;
    
    if (pos >= 2 && verticeInicial == verticeActual && !enCamino(verticeActual,camino)) 
    {
        nuevo->sig=camino;
        printf("Camino cerrado encontrado: ");
        for (int i = 0; i < pos; i++) 
        {
            printf("%d ", camino[i]);
        }
        printf("\n");
        return camino;
    }else{
        for (int i = 0; i < numLetrasUnicas; i++) 
        {
            if (matRedes[verticeActual][i] == 1 && !enCamino(i,camino)) 
            {
                nuevo->sig=NULL;
                fin->sig=nuevo;
                camino = recorreCamino(camino,nuevo,i,verticeInicial,pos,matRedes);
            }
        }
    }

    pos--;
    delete nuevo;
    return camino;
}

int **llenaMatRedes(int **matRedes, int* noCandidatos,int cantNoCandidatos)
{
    int fila = 0,columna = 0;
    matRedes = new int* [cantNoCandidatos];
    for (int i = 0; i < cantNoCandidatos; i++)
    {
        matRedes[i] = new int [cantNoCandidatos];
    }

    for (int j = 0; j < cantNoCandidatos; j++)
    {
        for (int k = 0; k < cantNoCandidatos; k++)
        {      

            matRedes[fila][columna++] = matAdyacencia[noCandidatos[j]][noCandidatos[k]];
        }

        if (columna >= (numLetrasUnicas - cantNoCandidatos))
        {
            columna = 0;
            fila++;
        }
        
    }

    cout<<endl;

    for (int i = 0; i < cantNoCandidatos; i++)
    {
        for (int j = 0; j < cantNoCandidatos; j++)
        {
            cout<< matRedes[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return matRedes;
}

bool enCamino(int id,Camino *camino)
{
    Camino* aux;
    aux=camino;
    while (aux != NULL)
    {
        if (aux->id==id)
        {
            return true;
        }
        aux=aux->sig;
    }
    return false;
}