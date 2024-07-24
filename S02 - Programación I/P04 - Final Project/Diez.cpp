/*
    Ejercicio 10. Parejas

    Basado en el tradicional juego de encontrar la pareja se dispone de un tablero de 6X6 
    donde se tienen parejas de letras (Desde la A hasta la R) ocultas y ubicadas de manera 
    aleatoria. Los asteriscos denotan los casilleros que han sido adivinados mientras que 
    los espacios ocultan a las letras que deben ser adivinadas.
*/
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
using namespace std;

struct Letras{
	char letra;
	int usos;
};

//Prototipos
void generar(char **mat, FILE *Tablero);
int numTablero();
void imprimirTablero(char **mat);
void resuelveTablero(char **mat);
int esParejaValida(char **mat, int fila1, int col1, int fila2, int col2);
void llenaLetras(Letras *vec);
void llenarTablero(char **tablero);
void encontrarCasillaVacia(char **tablero,int *f, int *c);

int main(){
    //inicializamos los valores que vamos a estar utilizando en todas las funciones
    char **mat;
    FILE *Tablero;
    srand(time(NULL));
    generar(mat,Tablero);//Llamada a la función que genera el tablero que se va a imprimir
}

void generar(char **mat, FILE *Tablero){
    int i=0, j=0; //contador de las filas y columnas de los tableros de los archivos que vamos a leer
//    int num=numTablero();//Llamada a numTablero, retorna un numero del 1 al 4
    //Generamos una matriz dinámica que guardara un tablero de letras
    mat = new char*[6]; //Inicializamos las filas de nuestra matriz

    for (int k = 0; k < 6; k++){
        mat[i] = new char [6];  //inicializamos las columnas de la matriz
    }

    llenarTablero(mat);
    
	Tablero= fopen("resuelto.txt","w");
	/*
	//Switch que funciona en base al valor de num y de los tableros establecidos
    //de los archivos de texto T1, T2, T3 o T4 en la matriz inicial
	switch(num){
		case 1:
			Tablero= fopen("T1.txt","r");
		break;
		case 2:
            Tablero= fopen("T2.txt","r");
		break;
		case 3:
            Tablero= fopen("T3.txt","r");
		break;
		case 4:
            Tablero= fopen("T4.txt","r");
		break;
	}*/
	
    //While que llena los valores de una linea de texto del archivo con un renglon de la matriz
    while (!feof(Tablero)){
        fprintf(Tablero,"%c\t%c\t%c\t%c\t%c\t%c\n",mat[i][0],mat[i][1],mat[i][2],mat[i][3],mat[i][4],mat[i][5]);
        i++;
    }
    //Cerramos el archivo
    fclose(Tablero);
    imprimirTablero(mat);//Llamada a la función que imprime el tablero
}

/*
int numTablero(){
	//Inicializamos variable, le damos un valor random entre cero y tres y sumamos 1
	int numTablero=1+rand()%4;
	return numTablero;//retornamos la variable
}*/

void imprimirTablero(char **mat){
    cout<<"Hora de resolver el tablero (renglones y casillas se cuentan del 0 al 5)\n";
    //Ciclos para imprimir el tablero electo
	for(int i=0; i<6; i++){
		for(int j=0; j<6; j++){
			printf("%c \t", mat[i][j]);
		}
		printf("\n");
	}
    resuelveTablero(mat); 
}
//Función que permite solucionar el tablero
void resuelveTablero(char **mat){
    //Inicializamos los valores en los que guardaremos los valores de las filas y columnas
    //de las casillas a resolver ren y col para la primera y ren2 y col2 para la segunda
    int ren=0, col=0, ren2=0, col2=0;

    do{
        cout<<"Hora de encontrar parejas\n";
        cout<<"Cual es la fila de la letra que quieres revelar? \n";
        cin>>col;//Entrada de la columna de la primer casilla
        cout<<"Cual es el renglon de la letra que quieres revelar? \n";
        cin>>ren;//Entrada de la fila de la primer casilla
        cout<<"La letra es :"<<mat[ren][col]<<"\n";//Mostramos la casilla elegida
        //Comprobamos que no haya sido resuelta antes, de ser así mostramos un mensaje que lo diga
        if(mat[ren][col]=='*'){ 
            cout<<"Casilla resuelta, favor de ingresar los datos de nuevo.\n";
        }
    }while (mat[ren][col]=='*');//Hacemos todo lo anterior hazta que se elija una casilla sin resolver
    

    do
    {
        cout<<"¿Cual es la fila de la pareja que quieres revelar? \n";
        cin>>col2;//Entrada de la columna de la segunda casilla
        cout<<"¿Cual es el renglon de la pareja que quieres revelar? \n";
        cin>>ren2;//Entrada de la fila de la segunda casilla
        cout<<"La letra es :"<<mat[ren2][col2]<<"\n";//Mostramos la casilla elegida
        //Comprobamos que no haya sido resuelta antes o sea la casilla que se eligio primero
        // de ser así mostramos un mensaje que lo diga
        if((col==col2 && ren==ren2) || (mat[ren2][col2]=='*')){
            cout<<"Casilla resuelta o repetida, favor de ingresar los datos de nuevo.\n";
        }
        //Hacemos todo lo anterior hazta que se elija una casilla sin resolver 
        //o con posiciones distintas a la de la primer casilla
    } while ((col==col2 && ren==ren2) || (mat[ren2][col2]=='*'));
    //if que evalua si el valor retornado por esParejaValida es 1
    if(esParejaValida(mat,ren,col,ren2,col2)==1){
        cout<<"Pareja encontrada!!";
        system("pause"); //Pausa para que el usuario decida cuando continuar
        system("cls");  //Limpiamos pantalla
        imprimirTablero(mat); //Imprimimos el tablero nuevamente
    }
}

int esParejaValida(char **mat, int fila1, int col1, int fila2, int col2){
    // Verificar si las letras en las posiciones dadas son una pareja válida
    // Devolver 1 si son pareja válida, 0 en caso contrario
    if (mat[fila1][col1] == mat[fila2][col2]) {
        mat[fila1][col1]='*';
        mat[fila2][col2]='*';
        return 1;
    }else{
        return 0;
    }
}



void llenarTablero(char **tablero){
	Letras *vec;
	int pos;
	
	vec = new Letras [18];
	
	llenaLetras(vec);
	
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			do{
				pos = rand()%18;
			}while(vec[pos].usos<=0);
			tablero[i][j] = vec[pos].letra;
			cout<<tablero[i][j]<<"\t";
			vec[pos].usos--;
		}
		cout<<endl;
	}
	cout<<"wenas";
}

void llenaLetras(Letras *vec){
	char letra='A';
	for(int i = 0; i < 18; i++){
		vec[i].letra = letra++;
		vec[i].usos = 2;
	}
}