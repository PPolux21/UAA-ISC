/*
- Escribir el mismo programa pero ahora haciendo uso de memoria dinámica (puedes usar funciones malloc, calloc, free, new o delete, la que tu desees)
- Hacer un paso de parámetros considerando la memoria dinámica
- Hacer uso de la notación de punteros
- Incluir un menú que mande llamar a las funciones.

Ya incluí el menu 
*/

/* Escribir un pograma que:
	a) Almacene números aleatorios (menores o iguales a 10) en una matriz de 5 * 6.
	b) Recorra la matriz: mostrando sus elementos
	c) Imprima la suma de los números almacenados en la matriz.
	d) Imprima la suma de los números pares almacenados en la matriz
	e) Imprima la suma de los números impares almacenados en la matriz
	f) Imprima la suma de cada columnas
	g) Imprima la suma de cada fila
	h) Imprima la suma de los elementos de la diagonal principal
	i) Imprima la transpuesta de la matriz
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

#define MAX_VALOR 10

using namespace std;

void menu();
int **creaEspacio(int **,int,int);

void llenarMatriz(int **,int,int);
void mostrarMatriz(int **,int,int);
int sumarElementosMatriz(int **,int,int);
int sumarParesMatriz(int **,int,int);
int sumarImparesMatriz(int **,int,int);
void mostrarSumaColumnas(int **,int,int);
void mostrarSumaFilas(int **,int,int);
void mostrarMatrizTranspuesta(int **,int,int);

int sumarDiagonalMatriz(int **,int,int);

int main() {
    srand(time(NULL));
    
    //se llama al menu
    menu();
    
    return 0;
}

void menu()
{
	
    // Se declara la matriz
    int **matriz;
    int suma = 0;
    int sumaPares = 0;
    int sumaImpares = 0;
    int sumaDiagonalPrincipal = 0;
    int fila=0,columnas=0;
    char opc;
    
    cout<<"Dame la cantidad de filas: ";
    cin>>fila;
    cout<<"Dame la cantidad de columnas: ";
    cin>>columnas;
    
    do
    {
    	system("cls");
    	cout<<"\t  OPERACIONES CON MATRICES"<<endl;
    	cout<<"a) Almacene numeros aleatorios (menores o iguales a 10) en una matriz de 5 * 6"<<endl;
    	cout<<"b) Recorra la matriz: mostrando sus elementos"<<endl;
    	cout<<"c) Imprima la suma de los numeros almacenados en la matriz"<<endl;
    	cout<<"d) Imprima la suma de los numeros pares almacenados en la matriz"<<endl;
    	cout<<"e) Imprima la suma de los numeros impares almacenados en la matriz"<<endl;
    	cout<<"f) Imprima la suma de cada columnas"<<endl;
    	cout<<"g) Imprima la suma de cada fila"<<endl;
    	cout<<"h) Imprima la suma de los elementos de la diagonal principal"<<endl;
    	cout<<"i) Imprima la transpuesta de la matriz"<<endl;
    	cout<<"j) Salir"<<endl;
    	cout<<"\nElige tu opcion: ";
    	fflush(stdin);
    	cin>>opc;
    	
    	switch(opc)
    	{
    		case 'A':
    		case 'a':
    			// a) Almacene números aleatorios (menores que 10) en una matriz de 5 * 6.
    			matriz = creaEspacio(matriz,fila,columnas);
    			llenarMatriz(matriz,fila,columnas);
    			system("pause");
    			break;
    		case 'B':
    		case 'b':
    			// b) Recorra la matriz: mostrando sus elementos
    			mostrarMatriz(matriz,fila,columnas);
    			system("pause");
    			break;
    		case 'C':
    		case 'c':
    			// c) Imprima la suma de los números almacenados en la matriz
    			suma = sumarElementosMatriz(matriz,fila,columnas);
    			cout << "\nLa suma de los elementos de la matriz es: " << suma << endl;
    			system("pause");
    			break;
    		case 'D':
    		case 'd':
    			// d) Imprima la suma de los números pares almacenados en la matriz
    			sumaPares = sumarParesMatriz(matriz,fila,columnas);
    			cout << "\nLa suma de los numeros PARES de la matriz es: " << sumaPares << endl;
    			system("pause");
    			break;
    		case 'E':
    		case 'e':
    			// e) Imprima la suma de los números impares almacenados en la matriz
    			sumaImpares = sumarImparesMatriz(matriz,fila,columnas);
    			cout << "\nLa suma de los numeros IMPARES de la matriz es: " << sumaImpares << endl;
    			system("pause");
    			break;
    		case 'F':
    		case 'f':
    			// f) Imprima la suma de cada columnas
    			mostrarSumaColumnas(matriz,fila,columnas);
    			system("pause");
    			break;
    		case 'G':
    		case 'g':
    			// g) Imprima la suma de cada fila
    			mostrarSumaFilas(matriz,fila,columnas);
    			system("pause");
    			break;
    		case 'H':
    		case 'h':
    			// h) Imprima la suma de los elementos de la diagonal principal
    			sumaDiagonalPrincipal = sumarDiagonalMatriz(matriz,fila,columnas);
    			cout << "\nLa suma de la diagonal principal de la matriz es: " << sumaDiagonalPrincipal<< endl;
    			system("pause");
    			break;
    		case 'I':
    		case 'i':
			    // i) Imprima la transpuesta de la matriz
    			mostrarMatrizTranspuesta(matriz,fila,columnas);
    			system("pause");
    			break;
    		case 'J':
    			cout<<"Intenta ponerlo en minusculas ;)"<<endl;
    			break;
    		case 'j':
    			break;
    		default:
    			cout<<"Opcion no valida :c"<<endl;
    			system("pause");
    			break;
		}
    	
	}while(opc!='j');
    
}

// Crea el espacio en memoria de la matriz
int **creaEspacio(int **mat,int fila,int col) {
	
	mat = (int**) malloc(fila * sizeof(int*));
	
	for(int i=0;i<fila;i++)
		*(mat+i) = (int*) malloc(col * sizeof(int));
	
	return mat;
}

// a) Almacene números aleatorios (menores que 10) en una matriz de 5 * 6.
void llenarMatriz(int **matriz, int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            *(*(matriz+i)+j) = rand() % (MAX_VALOR + 1); // números aleatorios menores o iguales a MAX_VALOR
        }
    }
}

// b) Recorra la matriz: mostrando sus elementos
void mostrarMatriz(int **matriz, int filas, int columnas) {
    cout << "La matriz es: " << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << "\t" << *(*(matriz+i)+j);
        }
        cout << endl;
    }
}

// c) Imprima la suma de los números almacenados en la matriz
int sumarElementosMatriz(int **matriz, int filas, int columnas) {
    int suma = 0;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            suma += *(*(matriz+i)+j);
        }
    }
    
    return suma;
}

// d) Imprima la suma de los números pares almacenados en la matriz
int sumarParesMatriz(int **matriz, int filas, int columnas) {
    int suma = 0;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (*(*(matriz+i)+j) % 2 == 0) {
                suma += *(*(matriz+i)+j);
            }
        }
    }
    
    return suma;
}

// e) Imprima la suma de los números impares almacenados en la matriz
int sumarImparesMatriz(int **matriz, int filas, int columnas) {
    int suma = 0;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (*(*(matriz+i)+j) % 2 != 0) {
                suma += *(*(matriz+i)+j);
            }
        }
    }
    
    return suma;
}

// f) Imprima la suma de cada columnas
void mostrarSumaColumnas(int **matriz, int filas, int columnas) {
    int suma = 0;
    cout << "\n";
    for (int j = 0; j < columnas; ++j) {
        suma = 0;
        for (int i = 0; i < filas; ++i) {
            suma += *(*(matriz+i)+j);
        }
        cout << "La suma de la columna " << j << " es: " << suma << endl;
    }
}

// g) Imprima la suma de cada fila
void mostrarSumaFilas(int **matriz, int filas, int columnas) {
    int suma = 0;
    cout << "\n";
    for (int i = 0; i < filas; ++i) {
        suma = 0;
        for (int j = 0; j < columnas; ++j) {
            suma += *(*(matriz+i)+j);
        }
        cout << "La suma de la fila " << i << " es: " << suma << endl;
    }
}

// h) Imprima la suma de los elementos de la diagonal principal
int sumarDiagonalMatriz(int **matriz, int filas, int columnas) {
	int suma = 0;
	if(filas>columnas)
	{
		for(int i=0;i<columnas;i++)
		{
			suma += *(*(matriz+i)+i);
		}
	}
	else
	{
		for(int i=0;i<filas;i++)
		{
			suma += *(*(matriz+i)+i);
		}
	}
	return suma;
}

// i) Imprima la transpuesta de la matriz
void mostrarMatrizTranspuesta(int **matriz, int filas, int columnas) {
    cout << "\nLa matriz transpuesta es: " << endl;
    for (int j = 0; j < columnas; ++j) {
        for (int i = 0; i < filas; ++i) {
            cout << "\t" << *(*(matriz+i)+j);
        }
        cout << endl;
    }
}