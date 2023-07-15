#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<unistd.h>

//Prototipos Principales
void menu(); 
//Prototipos del Sudoku
void sudoku(); //Metodo principal de Sudoku
void menuSudoku();	//Muestra el menu del sudoku
void reglasSudoku(); //Muestra las reglas del juego al usuario
void iniciaSudoku();	//Inicia el juego de sudoku
void generar(int mat[][9]); //Genera el tablero
int numTablero(); //Define el numero de tablero se usara para jugar
int ocultar(int mat[][9],int valor[],int posiI[],int posiJ[]); //Imprime el tablero con numeros ocultos
void llenado(int mat[][9],int valor[],int posiI[],int posiJ[],int lim); //Pide los datos necesarios para resolver una posición del sudoku
int posicionValida(int tablero[][9],int fila,int columna,int numero); //Valida los datos ingresados en el metodo void llenado
bool buscarEnSubcuadricula(int Matriz[ ][9], int fila, int columna, int numero); //
void mostrar(int mat[][9]);//Muestra el tablero resuelto
//Prototipos Da y Quita
void da_y_quita(); //Método principal Da y Quita
void menuDYQ(); //Muestra el menu del Da y Quita
void reglasDYQ(); //Muestra las reglas del Da y Quita
void inicioDYQ();	//Inicia el juego de Da y Quita
void tiraDados1(); //Comienza el jugador 1
void tiraDados2(); //Comienza el jugador 2


int main(){
	menu();//llamada a la funcion
}

//Desarrollo de void menu
void menu(){
	system("color E1"); //Determina el color del menu
	system("cls"); //Limplia la pantalla
	//declaración de variables
	int opc;
	//Ciclo que imprime el menu mientras no se ingrese una opción correcta
	do{
		printf("\tElija un juego \n");
		printf("Da y quita.................1 \n");
		printf("Sudoku.....................2 \n");
		printf("Salir......................3 \n");
		printf("Ingrese el numero de la opcion: ");
		scanf("%d",&opc);//Lee la opción que da el usuario
		//switch que actua según la opción ingresada
		switch(opc){
			//Si la opción es uno, nos llevara al metodo principal del Da y Quita
			case 1:
				da_y_quita();
				system("pause()"); //para pausar la pantalla
				system("cls"); //limpiar la pantalla
				break;
			//Si la opción es dos, nos llevara al metodo principal del Sudoku
			case 2:
				sudoku();
				system("pause()"); //para pausar la pantalla
				system("cls"); //limpiar la pantalla
				break;
			//Si la opción es tres, nos cerrará el programa
			case 3:
            	printf("Cerrando programa.");
            	abort();//cierre del programa
            	break;
		}//switch
	}while(opc!=3);
}//menu
//Metodo principal de Da y Quita, nos dirige al menú del juego
void da_y_quita(){
	system("color D7");//Se determina el color que llevara la pantalla durante el juego
	system("cls");
	printf("\n\t Da y quita \n");
	menuDYQ();
}//da y quita

//Metodo principal de Sudoku, nos dirige al menú del Juego
void sudoku(){
	system("color 71"); //Se determina el color que llevara la pantalla durante el juego 
	system("cls");
	printf("\n\t Sudoku \n");
	menuSudoku();
}//sudoku


//METODOS SUDOKU

//Desarrollo del Menu de Sudoku
void menuSudoku(){
	system("cls");//limpiamos pantalla
	//declaramos variables
	int opc=0;
    //ciclo que imprime el menú hasta que el usuario ngrese una opción válida
    do
	{
        printf("\t Sudoku \n");
        printf("Iniciar Juego   ............. 1\n");
        printf("Reglas          ............. 2\n");
        printf("Salir al menu inicial ....... 3\n");
        printf("Salir de la aplicacion ...... 4\n");
        printf("Selecciona una opcion: ");
        scanf("%d",&opc);//Leeemos la opción
        //switch que funciona en base a lo que el usuario ingresa
        switch (opc)
		{
			//Si la opción es uno, iniciaremos el juego
            case 1:
            	iniciaSudoku();
            	break;
            //Si la opción es dos, veremos las reglas del juego
            case 2:
            	reglasSudoku();
            	break;
            //Si la opción es tres, veremos el menu principal
            case 3:
            	menu();
            	break;
            //Si la opción es cuatro, se cerrará el programa
           	case 4:
            	printf("Cerrando programa.");
            	abort();
            	break;
            //Si la opción es distinta a las anteriores, cerraremos el programa
        	default:
        		printf("Opcion invalida, cerrando programa.");
            	abort();
        		break;
        }//Switch

    }while(opc!=4); //condición de las opciones ingresadas por el usuario
}

//Metodo del juego del Sudoku
void iniciaSudoku(){
	system("cls");//limpiamos pantalla
	//Declaramos Variables e iniciamos el srand
	int mat[9][9],valor[81],posiI[81],posiJ[81],lim=0;
	srand(time(NULL));
	
	generar(mat);//Llamado para generar el tablero resuelto
	system("pause"); //Pausamos la pantalla
	system("cls");
	printf("Ahora hay valores ocultos: \n");
	lim=ocultar(mat,valor,posiI,posiJ);//Llamada para ocultar valores del tablero y mostrar el nuevo tablero
	system("pause");//Pausamos la pantalla
	llenado(mat,valor,posiI,posiJ,lim);//Función que permite llenar el tablero incompleto
}

//Metodo de las reglas de Sudoku
void reglasSudoku(){
	system("cls");//limpiamos la pantalla
	//imprimimos las reglas
	printf("Reglas Sudoku \n");
	printf("\n1.El juego se desarrolla sobre un tablero incompleto de Sudoku de 9x9 casillas. \n");
	printf("2.El objetivo del juego es llenar los 81 casilleros con cifras del 1 al 9 sin repetir ninguna cifra en una misma fila,  columna");
	printf(" o subcuadricula.\n");
	
	system("pause()"); //para pausar la pantalla
	system("cls"); //limpiar la pantalla
	menuSudoku();	//Regresamos al menu del juego
}
//Metodo para generar el tablero de sudoku
void generar(int mat[][9]){
	//Inicializamos tableros resueltos en matrices distintas
	int mat1[9][9]={{5,3,4,6,7,8,9,1,2},
					{6,7,2,1,9,5,3,4,8},
					{1,9,8,3,4,2,5,6,7},
					{8,5,9,7,6,1,4,2,3},
					{4,2,6,8,5,3,7,9,1},
					{7,1,3,9,2,4,8,5,6},
					{9,6,1,5,3,7,2,8,4},
					{2,8,7,4,1,9,6,3,5},
					{3,4,5,2,8,6,1,7,9}};
	
	int mat2[9][9]={{3,2,9,7,4,8,1,6,5},
					{4,8,6,1,2,5,9,7,3},
					{5,7,1,3,6,9,8,2,4},
					{2,4,5,9,8,7,3,1,6},
					{8,1,3,2,5,6,4,9,7},
					{6,9,7,4,3,1,2,5,8},
					{1,6,2,8,7,4,5,3,9},
					{7,3,8,5,9,2,6,4,1},
					{9,5,4,6,1,3,7,8,2}};
					
	int mat3[9][9]={{9,7,1,6,8,2,5,4,3},
					{5,3,6,9,1,4,7,8,2},
					{4,8,2,7,3,5,1,6,9},
					{6,5,8,4,2,9,3,1,7},
					{1,9,7,3,5,8,6,2,4},
					{3,2,4,1,6,7,9,5,8},
					{7,6,5,2,4,3,8,9,1},
					{8,4,3,5,9,1,2,7,6},
					{2,1,9,8,7,6,4,3,5}};
					
	int mat4[9][9]={{2,8,7,3,1,6,4,5,9},
					{1,4,6,2,9,5,8,3,7},
					{9,3,5,4,7,8,2,6,1},
					{8,5,2,1,3,4,7,9,6},
					{7,9,4,6,5,2,3,1,8},
					{6,1,3,7,8,9,5,4,2},
					{4,2,8,9,6,3,1,7,5},
					{3,7,9,5,2,1,6,8,4},
					{5,6,1,8,4,7,9,2,3}};				
	//Switch que funciona en base al valor que retorna la función de numTablero vacia uno de los tableros establecidos en la matriz inicial
	switch(numTablero()){
		case 1:
			for(int i=0; i<9; i++){
				for(int j=0; j<9; j++){
					mat[i][j]=mat1[i][j];
				}
			}
		break;
		case 2:
			for(int i=0; i<9; i++){
				for(int j=0; j<9; j++){
					mat[i][j]=mat2[i][j];
				}
			}
		break;
		case 3:
			for(int i=0; i<9; i++){
				for(int j=0; j<9; j++){
					mat[i][j]=mat3[i][j];
				}
			}
		break;
		case 4:
			for(int i=0; i<9; i++){
				for(int j=0; j<9; j++){
					mat[i][j]=mat4[i][j];
				}
			}
		break;
	}
	
	//Ciclos para imprimir el tablero electo
	for(int i=0; i<9; i++){
		if(i==3||i==6){
			for(int j=0;j<11;j++){
				if(j==0){
					printf("   ");
				}	
				if(j==3||j==7){
					printf("+ ");
				}else{
					printf("%c ",196);
				}
			}
			printf("\n");
		}
		for(int j=0; j<9; j++){
			if(j==0){
				printf("   ");
			}
			if(j==3||j==6){
				printf("| ");
			}
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}
//funcion que obtiene un numero aleatorio entre 1 y cuatro
int numTablero(){
	//Inicializamos variable, le damos un valor random entre cero y tres y sumamos 1
	int numTablero=1+rand()%4;
	return numTablero;//retornamos la variable
}

//funcion que oculta de manera aleatoria los numeros del tablero
int ocultar(int mat[][9],int valor[],int posiI[],int posiJ[]){
	int num=1,ocultos=0;
	//ciclo que recorre todo el tablero (filas)
	for(int i=0; i<9; i++){
		//condicion para agregar una columna de separación cada 3 filas
		if(i==3||i==6){
			for(int j=0;j<11;j++){
				if(j==0){
					printf("   ");
				}
				if(j==3||j==7){
					printf("+ ");
				}else{
					printf("%c ",196);
				}
			}
			printf("\n");
		}
		//ciclo que recorre todo el tablero (columnas)
		for(int j=0; j<9; j++){
			if(j==0){
				printf("   ");
			}
			//condicional que agrega un separador cada 3 columnas
			if(j==3||j==6){
				printf("| ");
			}
			//numero aleatorio que determina si el numero será ocultado o no, si es 0 no se oculta
			num=rand()%2;
			if(num==0){
				printf("%d ", mat[i][j]);//muestra el numero
			}else{
				printf("- ");//muestra un guion en caso de haber ocultado el numero
				valor[ocultos]=mat[i][j];//asigna el valor del oculto en un vector, que se usará después
				posiI[ocultos]=i;//asigna la posicion de la fila en un vector, que se usará después
				posiJ[ocultos]=j;//asigna la posicion de la columna en un vector, que se usará después
				mat[i][j]=0;//asigna el valor 0 al valor que se oculto en el tablero
				ocultos++;//contador de numeros que se han ocultado
			}
		}
		printf("\n");
	}
	//regresa el numero de numeros ocultos en el tablero
	return ocultos;
}

//funcion que permite al jugador llenar el tablero
void llenado(int mat[][9],int valor[],int posiI[],int posiJ[],int lim){
	int col=0,fila=0,numero=0,cont=0;
	bool correcto;
	//ciclo que se repite hasta que se halla llenado el tablero
	while(cont<lim){
		system("cls");
		mostrar(mat);//muestra el tablero
		printf("\n");
		printf("***Las posiciones se dan de 1 a 9***\n\n");
		printf("Dame la fila que se quiere llenar: ");
		scanf("%d",&fila);//pide la coordena de la fila
		fila--;//disminuye 1 el numero de la fila
		printf("Dame la columna que se quiere llenar: ");
		scanf("%d",&col);//pide la coordenada de la columna
		col--;//disminuye 1 el numero de la columna
		printf("Dame el numero: ");
		scanf("%d",&numero);//pide el numero a introducir en el tablero
		//condicion que valida que todos los datos esten en su rango de utilidad
		if(numero>=1&&numero<=9&&col>=0&&col<=8&&fila>=0&&fila<=8){
			//switch que llama la función posicionValida para determinar si se puede utilizar el numero y la casilla
			switch(posicionValida(mat,fila,col,numero)){
				case 0:
					printf("La casilla ya esta ocupada\n");
					break;
				case 1:
					printf("La posicion es valida\n");
					//ciclo que desde 0 hasta la cantidad de numeros ocultos
					for(int i=0;i<lim;i++){
						correcto=true;//se queda en verdadero si no hay coincidencias
						//condicion que evalua coincidencias entre los valores introducidos y los guardados en los vectores
						if(posiI[i]==fila&&posiJ[i]==col&&valor[i]==numero){
							printf("Numero correcto\n");
							cont++;//cuenta un valor correcto añadido al tablero
							mat[fila][col]=numero;//asigna el valor al tablero en la posicion asignada
							correcto=false;//cambia a false tras encontrar una coincidencia
							break;//sale del ciclo
						}
					}
					//se usa el valor del bool anterior para mostrar un mensaje, tras no encontrar coincidencias
					if(correcto){
						printf("Numero no correcto\n");
					}
					break;
				case 2:
					printf("El numero se encuentra en la fila\n");
					break;
				case 3:
					printf("El numero se encuentra en la columna\n");
					break;
				case 4:
					printf("El numero se encuentra en la subcuadricula\n");
					break;
			}
		}else{
			//si los valores se pasan del rango correspondiente sale el siguiente mensaje
			printf("Valores no validos\n");
		}
		system("pause");
	}
	//tras completar el sudoku se muestra se limpia la pantalla y se muestra el mensaje con al tablero completo
	system("cls");
	printf("Sudoku completado!!!\n");
	mostrar(mat);
	system("pause");
}

//funcion que evalua la existencia del numero en la casilla, fila, columna y subcuadricula correspondiente
int posicionValida(int tablero[][9],int fila,int columna,int numero){
	//si la casilla esta ocupada por un valor diferente de 0 (1 a 9), se regresa 0
	if(tablero[fila][columna]!=0){
		return 0;
	}
	//ciclo que recorre la columna 
	for(int i=0;i<9;i++){
		//si se encuentra el numero en la columna, se regresa 3
		if(i!=fila){
			if(tablero[i][columna]==numero){
				return 3;
			}
		}
	}
	//ciclo que recorre la fila
	for(int i=0;i<9;i++){
		//si se encuentra el numero en la fila, se regresa 2
		if(i!=columna){
			if(tablero[fila][i]==numero){
				return 2;
			}
		}
	}
	//se recurre a la funcion buscarEnSubcuadricula para determinar si se encuentra el numero en la subcuadricula
	if(buscarEnSubcuadricula(tablero,fila,columna,numero)){
		//de ser true, se regresa 4
		return 4;
	}
	//si las conduciones anteriores no se cumplen y el valor en la posicion es 0, se regresa 1
	if(tablero[fila][columna]==0){
		return 1;
	}
}

//funcion que determina si se encuentra el numero en la subcuadricula (muchas conduciones y ciclos)
bool buscarEnSubcuadricula(int matriz[ ][9], int fila, int columna, int numero){
	//condicion que evalua si la fila se encuentra entre 0 y 2
	if(fila>=0&&fila<=2){
		//condicion que evalua si la columna se encuentra entre 0 y 2
		if(columna>=0&&columna<=2){
			//ciclos que recorren la subcuadricula
			for(int i=0;i<=2;i++){
				for(int j=0;j<=2;j++){
					//condicion que evita evaluar en la misma posicion de los valores introducidos
					if(i!=fila&&j!=columna){
						//si encuentra una coincidencia regresa true
						if(matriz[i][j]==numero){
							return true;
						}//matriz[i][j]==numero
					}//i!=fila y j!=columna
				}//j
			}//i
		}//if columna 0 a 2
		//condicion que evalua si la columna se encuentra entre 3 y 5
		if(columna>=3&&columna<=5){
			//ciclos que recorren la subcuadricula
			for(int i=0;i<=2;i++){
				for(int j=3;j<=5;j++){
					//condicion que evita evaluar en la misma posicion de los valores introducidos
					if(i!=fila&&j!=columna){
						//si encuentra una coincidencia regresa true
						if(matriz[i][j]==numero){
							return true;
						}//matriz[i][j]==numero
					}//i!=fila y j!=columna
				}//j
			}//i
		}//if columna 3 a 5
		//condicion que evalua si la columna se encuentra entre 6 y 8
		if(columna>=6&&columna<=8){
			//ciclos que recorren la subcuadricula
			for(int i=0;i<=2;i++){
				for(int j=6;j<=8;j++){
					//condicion que evita evaluar en la misma posicion de los valores introducidos
					if(i!=fila&&j!=columna){
						//si encuentra una coincidencia regresa true
						if(matriz[i][j]==numero){
							return true;
						}//matriz[i][j]==numero
					}//i!=fila y j!=columna
				}//j
			}//i
		}// if columna 6 a 8
	}//if fila 0 a 2
	
	//condicion que evalua si la fila se encuentra entre 3 y 5
	if(fila>=3&&fila<=5){
		//condicion que evalua si la columna se encuentra entre 0 y 2
		if(columna>=0&&columna<=2){
			//ciclos que recorren la subcuadricula
			for(int i=3;i<=5;i++){
				for(int j=0;j<=2;j++){
					//condicion que evita evaluar en la misma posicion de los valores introducidos
					if(i!=fila&&j!=columna){
						//si encuentra una coincidencia regresa true
						if(matriz[i][j]==numero){
							return true;
						}//matriz[i][j]==numero
					}//i!=fila y j!=columna
				}//j
			}//i
		}//if columna 0 a 2
		//condicion que evalua si la columna se encuentra entre 3 y 5
		if(columna>=3&&columna<=5){
			//ciclos que recorren la subcuadricula
			for(int i=3;i<=5;i++){
				for(int j=3;j<=5;j++){
					//condicion que evita evaluar en la misma posicion de los valores introducidos
					if(i!=fila&&j!=columna){
						//si encuentra una coincidencia regresa true
						if(matriz[i][j]==numero){
							return true;
						}//matriz[i][j]==numero
					}//i!=fila y j!=columna
				}//j
			}//i
		}//if columna 3 a 5
		//condicion que evalua si la columna se encuentra entre 6 y 8
		if(columna>=6&&columna<=8){
			//ciclos que recorren la subcuadricula
			for(int i=3;i<=5;i++){
				for(int j=6;j<=8;j++){
					//condicion que evita evaluar en la misma posicion de los valores introducidos
					if(i!=fila&&j!=columna){
						//si encuentra una coincidencia regresa true
						if(matriz[i][j]==numero){
							return true;
						}//matriz[i][j]==numero
					}//i!=fila y j!=columna
				}//j
			}//i
		}// if columna 6 a 8
	}//if fila 3 a 5
	
	//condicion que evalua si la fila se encuentra entre 6 y 8
	if(fila>=6&&fila<=8){
		//condicion que evalua si la columna se encuentra entre 0 y 2
		if(columna>=0&&columna<=2){
			//ciclos que recorren la subcuadricula
			for(int i=6;i<=8;i++){
				for(int j=0;j<=2;j++){
					//condicion que evita evaluar en la misma posicion de los valores introducidos
					if(i!=fila&&j!=columna){
						//si encuentra una coincidencia regresa true
						if(matriz[i][j]==numero){
							return true;
						}//matriz[i][j]==numero
					}//i!=fila y j!=columna
				}//j
			}//i
		}//if columna 0 a 2
		//condicion que evalua si la columna se encuentra entre 3 y 5
		if(columna>=3&&columna<=5){
			//ciclos que recorren la subcuadricula
			for(int i=6;i<=8;i++){
				for(int j=3;j<=5;j++){
					//condicion que evita evaluar en la misma posicion de los valores introducidos
					if(i!=fila&&j!=columna){
						//si encuentra una coincidencia regresa true
						if(matriz[i][j]==numero){
							return true;
						}//matriz[i][j]==numero
					}//i!=fila y j!=columna
				}//j
			}//i
		}//if columna 3 a 5
		//condicion que evalua si la columna se encuentra entre 6 y 8
		if(columna>=6&&columna<=8){
			//ciclos que recorren la subcuadricula
			for(int i=6;i<=8;i++){
				for(int j=6;j<=8;j++){
					//condicion que evita evaluar en la misma posicion de los valores introducidos
					if(i!=fila&&j!=columna){
						//si encuentra una coincidencia regresa true
						if(matriz[i][j]==numero){
							return true;
						}//matriz[i][j]==numero
					}//i!=fila y j!=columna
				}//j
			}//i
		}// if columna 6 a 8
	}//if fila 6 a 8
	return false;// si no hay coincidencias regresa false
}

//funcion que muestra el tablero
void mostrar(int mat[][9]){
	printf("\n");
	//ciclo que recorre todo el tablero (filas)
	for(int i=0;i<9;i++){
		//condicional que añade una fila de separadores en antes de las filas 3 y 6
		if(i==3||i==6){
			for(int j=0;j<11;j++){
				if(j==0){
					printf("   ");
				}
				if(j==3||j==7){
					printf("+ ");
				}else{
					printf("%c ",196);//─
				}
			}
			printf("\n");
		}
		//ciclo que recorre todo el tablero (columnas)
		for(int j=0;j<9;j++){
			if(j==0){
				printf("   ");
			}
			//añade separadores en las columnas antes de las colunas 3 y 6
			if(j==3||j==6){
				printf("| ");
			}
			//condicional que detecta 0's en el tablero
			if(mat[i][j]==0){
				//para evitar mostrar los 0's se muestra un guion
				printf("- ");
			}else{
				//muestra el numero cuando este no es 0
				printf("%d ",mat[i][j]);
			}
		}
		printf("\n");
	}
}


//METODOS DA Y QUITA

//Desarrollo del menu de Da y Quita
void menuDYQ(){
	system("cls");//limpiamos la pantalla
	//Declaramos variables
    int opc=0;
    
    //ciclo que imprime el menu hasta que el ususario de una opción valida
    do{
        printf("\tDa y Quita \n");
        printf("Empezar el Juego .......... 1\n"); //Se lanzara el dado para ver que jugador va primero
        printf("Reglas/instrucciones ...... 2\n"); //mostrara la pantalla de intrucciones
        printf("Salir al menu principal.... 3 \n"); //Saldra del juego al menu principal
        printf("Salir de la aplicación   .. 4 \n"); //Saldra de la aplicación
        printf("Selecciona una opcion: ");
        scanf("%d",&opc);
        switch (opc) {
            case 1: 
            	inicioDYQ();
            break;
            case 2: 
            	reglasDYQ();
            break;
            case 3: 
            	menu();
            break;
            case 4: 
            	printf("Cerrando programa.");
            	abort();
            break;
            default: 
            	printf("Opcion invalida, cerrando programa.");
            	abort();
            break;
        }//switch       
    }while(opc != 3);
}//menu

//Metodo que imprime las reglas del da y quita
void reglasDYQ(){
	system("cls");//limpiamos la pantalla
	//imprimimos las reglas
	printf("Reglas Da y Quita \n");
	printf("\n1.Este juego utiliza un dado especial de cuatro lados y 50 fichas repartidas en partes iguales para cada jugador. \n A lasfichas de cada jugador se les denomina monton. \n \n");
	printf("2.Para iniciar el juego, ambos jugadores lanzan el dado y el jugador con el valor más alto iniciará el juego. \n El juego se desarrolla en turnos de la siguiente forma: \n \n");
	printf("3.Cada jugador coloca una de sus fichas en la mesa y lanza el dado. El valor que obtenga el jugador en el dado, sucede lo siguiente:\n\n");
	printf("\t 1.Todo: Quita todas las fichas de la mesa y las agrega a su monton. \n");
	printf("\t 2.Pone: Coloca una de sus fichas en la mesa \n");
	printf("\t 3.Quita: Toma una de las fichas del otro jugador y las agrega a su monton \n");
	printf("\t 4.Mitad: Coloca la mitad de sus fichas en la mesa \n \n");
	printf("Cada vez que la mesa se quede sin fichas, ambos jugadores deben colocar una ficha de su monton como al inicio del juego, y continuar jugando en turnos.\n");
	printf("El juego termina cuando sucede alguno de los siguientes eventos:\n");
	printf("Uno de los jugadores resulta ganador. En este juego, hay un ganador cuando su oponente se queda sin fichas.\n");
	printf("Se ha cumplido el limite de 25 lanzamientos.\n \n");
	
	system("pause()"); //para pausar la pantalla
	system("cls"); //limpiar la pantalla
	menuDYQ();//Regresamos al menú de Da y Quita
}

void inicioDYQ(){
	system("cls"); //limpiar la pantalla
	int dado1, dado2; //dados de los jugadores
    //dado 1
    dado1=1+rand()%4; //para generar valores solo del 1 al 4
    printf("Tirando dado...\n");
    sleep(2); //Tiempo de espera
    printf("Valor de la tirada del jugador 1: %i\n",dado1);
	printf("\n");
	sleep(2);//Tiempo de espera
	//dado 2
	dado2=1+rand()%4;//para generar valores solo del 1 al 4
    printf("Tirando dado...\n");
    sleep(2); //Tiempo de espera
    printf("Valor de la tirada del jugador 2: %i\n",dado2);
    printf("\n");
    sleep(2);//Tiempo de espera
    
    //si el valor del dado 1 fue mayor
    if(dado1>dado2){
    	printf("El jugador 1 comienza! \n");
    	system("pause()"); //para pausar la pantalla
		system("cls"); //limpiar la pantalla
    	tiraDados1();//llamar a la funcion para que comience el jugador 1
	}//if
	else{
		//si el valor del dado 2 fue mayor
		if(dado1<dado2){
			printf("El jugador 2 comienza! \n");
			system("pause()"); //para pausar la pantalla
			system("cls"); //limpiar la pantalla
			tiraDados2();//llamar a la funcion para que comience el jugador 2
		}//if
		if(dado1==dado2){
			printf("Vuelvan a tirar los dados! \n");
			system("pause()"); //para pausar la pantalla
			system("cls"); //limpiar la pantalla
			inicioDYQ();//llamar a la funcion para volver a tirar los dados
		}//if
	}//else
}// inicial



void tiraDados1(){
    int dado, fichas1=24, fichas2=24, fichasm1=1, fichasm2=1;
    printf("Da y quita \n \n");
	printf("\t \t \t \t %d \t \t \t \t \t %d \n",fichasm1,fichasm2);//fichas que hay en la mesa
	printf("\t \t Fichas del jugador 1 \t \t \t Fichas del jugador 2 \n");
	printf("\n");
    srand(time(NULL));
    
    //repetir hasta que sean 25 turnos
    for(int i=1; i<=25; i++){//i son los turnos
    	//los turnos de numero par seran los del jugador 2
    	if(i%2==0){ //turno jugador 2
    		printf("Turno %d \n \n",i);//muestra el turno que es
    		sleep(2);//Tiempo de espera
		    dado=1+rand()%4;//para generar numeros solo del 1 al 4
			printf("Tirando dado...\n");
		    sleep(2); //Tiempo de espera
		    printf("Valor de la tirada del jugador 2: %i\n \n",dado);//muestra el valor del dado
		    switch(dado){
	    		//si en el dado cae 1
				case 1:
					printf("Todo \n \n");
					printf("\t \t \t %d \t \t \t \t \t %d \n\n", fichasm1, fichasm2);//fichas en la mesa
					printf("\t \t Fichas del jugador 1 \t \t \t Fichas del jugador 2 \n");
					printf("Fichas del monton del jugador 1: %d \n \n",fichas1);//fichas del monton del jugador 1
					fichas2=fichas2+(fichasm1+fichasm2);//a las fichas del jugador 2 se le suman las de la mesa
					printf("Fichas del monton del jugador 2: %d \n \n",fichas2);//fichas del monton del jugador 2
					//la mesa se queda sin fichas
					fichasm1=0;
					fichasm2=0;
					printf("\t \t \t 0 \t \t \t \t \t 0 \n\n");
					
					//pedir un ficha a cada jugador
					if(fichasm1==0&&fichasm2==0){
						printf("Ambos pongan una ficha: \n");
						sleep(2);//tiempo de espera
						printf("\t \t \t \t 1 \t \t \t \t \t \t 1 \n");
						printf("\t \t Fichas del jugador 1 \t \t \t Fichas del jugador 2 \n");
						printf("\n");
						fichas1=fichas1-1;// a las fichas del jugador 1 se le resta 1
						fichas2=fichas2-1;// a las fichas del jugador 2 se le resta 1
						//las fichas en la mesa ahora son 1
						fichasm1=1;
						fichasm2=1;
					}//if
					system("pause()"); //para pausar la pantalla
					system("cls"); //limpiar la pantalla
					break;
				//si en el dado cae 2
				case 2:
					printf("Pone \n \n");
					fichasm2=fichasm2+1;//a las fichas en la mesa del jugador 2 se le suma 1
					printf("\t \t \t %d \t \t \t \t \t %d \n\n", fichasm1, fichasm2);//fichas en la mesa
					printf("\t \t Fichas del jugador 1 \t \t \t Fichas del jugador 2 \n");
					printf("Fichas del monton del jugador 1: %d \n \n",fichas1);//monton del jugador 1
					fichas2=fichas2-1;//a las fichas del jugador 2 se le resta 1
					printf("Fichas del monton del jugador 2: %d \n \n",fichas2);//monton del jugador 1
					system("pause()"); //para pausar la pantalla
					system("cls"); //limpiar la pantalla
					break;
				//si en el dado cae 3
				case 3:
					printf("Quita \n \n");
					printf("\t \t \t %d \t \t \t \t \t %d \n\n", fichasm1, fichasm2);//fichas en la mesa
					printf("\t \t Fichas del jugador 1 \t \t \t Fichas del jugador 2 \n");
					fichas2=fichas2+1;//a las fichas del jugador 2 se le suma 1
					fichas1=fichas1-1;//a las fichas del jugador 1 se le resta 1
					printf("Fichas del monton del jugador 1: %d \n \n",fichas1);//monton del jugador 1
					printf("Fichas del monton del jugador 2: %d \n \n",fichas2);//monton del jugador 2
					system("pause()"); //para pausar la pantalla
					system("cls"); //limpiar la pantalla
					break;
				case 4:
					printf("Mitad \n \n");
					fichas2=fichas2/2;//las fichas del jugador 2 se dividen entre 2
					fichasm2=fichasm2+fichas2;//a las fichas en la mesa del jugador 2 se le suman la mitad de su monton
					printf("\t \t \t %d \t \t \t \t \t %d \n\n", fichasm1, fichasm2);//fichas en la mesa
					printf("\t \t Fichas del jugador 1 \t \t \t Fichas del jugador 2 \n");
					printf("Fichas del monton del jugador 1: %d \n \n",fichas1);//monton del jugador 1
					printf("Fichas del monton del jugador 2: %d \n \n",fichas2);//monton del jugador 2
					system("pause()"); //para pausar la pantalla
					system("cls"); //limpiar la pantalla
					break;
				default: printf("Lanza otra vez \n \n");
			}//switch
		}//if
		else{//turno jugador 1
			printf("Turno %d \n \n",i);//turno
			sleep(2); //Tiempo de espera
		    dado=1+rand()%4;//para generar numeros del 1 al 4
			printf("Tirando dado...\n");
		    sleep(2); //Tiempo de espera
		    printf("Valor de la tirada del jugador 1: %i\n \n",dado);//valor que cayo en el dado
		    switch(dado){
		    	//si en el dado cae 1
				case 1:
					printf("Todo \n \n");
					printf("\t \t \t %d \t \t \t \t \t %d \n\n", fichasm1, fichasm2);//fichas en la mesa
					printf("\t \t Fichas del jugador 1 \t \t \t Fichas del jugador 2 \n");
					fichas1=fichas1+(fichasm1+fichasm2);//al monton del jugador 1 se le suman las fichas que hay en la mesa
					printf("Fichas del monton del jugador 1: %d \n \n",fichas1);//monton del jugador 1
					printf("Fichas del monton del jugador 2: %d \n \n",fichas2);//monton del jugador 2
					//la mesa se queda sin fichas
					fichasm1=0;
					fichasm2=0;
					printf("\t \t \t 0 \t \t \t \t \t 0 \n\n");
				
					//pedir fichas
					if(fichasm1==0&&fichasm2==0){
						printf("Ambos pongan una ficha: \n");
						sleep(2);//tiempo de espera
						printf("\t \t \t \t 1 \t \t \t \t \t \t 1 \n");
						printf("\t \t Fichas del jugador 1 \t \t \t Fichas del jugador 2 \n");
						printf("\n");
						fichas1=fichas1-1;//al monton del jugador 1 se le resta 1
						fichas2=fichas2-1;//al monton del jugador 2 se le resta 1
						//las fichas en la mesa son 1 por jugador
						fichasm1=1;
						fichasm2=1;
					}//if
					system("pause()"); //para pausar la pantalla
					system("cls"); //limpiar la pantalla
					break;
				//si en el dado cae 1
				case 2:
					printf("Pone \n \n");
					fichasm1=fichasm1+1;//a las fichas en la mesa del jugador 1 se le suma 1
					printf("\t \t \t %d \t \t \t \t \t \t \t %d \n\n", fichasm1, fichasm2);//fichas en la mesa
					printf("\t \t Fichas del jugador 1 \t \t \t Fichas del jugador 2 \n");
					fichas1=fichas1-1;//al monton del jugador 1 se le resta 1
					printf("Fichas del monton del jugador 1: %d \n \n",fichas1);//monton del jugador 1
					printf("Fichas del monton del jugador 2: %d \n \n",fichas2);//monton del jugador 2
					system("pause()"); //para pausar la pantalla
					system("cls"); //limpiar la pantalla
					break;
				case 3:
					printf("Quita \n \n");
					printf("\t \t \t %d \t \t \t \t \t %d \n\n", fichasm1, fichasm2);//fichas en la mesa
					printf("\t \t Fichas del jugador 1 \t \t \t Fichas del jugador 2 \n");
					fichas1=fichas1+1;//a las fichas del jugador 1 se le suma 1
					fichas2=fichas2-1;//a las fichas del jugador 2 se le resta 1
					printf("Fichas del monton del jugador 1: %d \n \n",fichas1);//monton del jugador 1
					printf("Fichas del monton del jugador 2: %d \n \n",fichas2);//monton del jugador 2
					system("pause()"); //para pausar la pantalla
					system("cls"); //limpiar la pantalla
					break;
				case 4:
					printf("Mitad \n \n");
					fichas1=fichas1/2;//las fichas del jugador 1 se dividen entre 2
					fichasm1=fichasm1+fichas1;//a las fichas en la mesa del jugador 1 se le suman la mitad de su monton
					printf("\t \t \t %d \t \t \t \t \t %d \n\n", fichasm1, fichasm2);//fichas en la mesa
					printf("\t \t Fichas del jugador 1 \t \t \t Fichas del jugador 2 \n");
					printf("Cartas del monton del jugador 1: %d \n \n",fichas1);//monton del jugador 1
					printf("Cartas del monton del jugador 2: %d \n \n",fichas2);//monton del jugador 2
					system("pause()"); //para pausar la pantalla
					system("cls"); //limpiar la pantalla
					break;
				default: printf("Lanza otra vez \n");
			}//switch
		}//else
		//si las fichas del jugador 2 se acaban		
		if(fichas2==0){
			printf("El jugador 1 es el ganador!!!");
			break;
		}//if
		//si las fichas del jugador 1 se acaban	
		if(fichas1==0){
			printf("El jugador 2 es el ganador!!!\n");
			break;
		}//if
		//si se cumple el numero maximo de lanzamiento
		if(i==25){
			printf("El juego termino!!\n");
			printf("Se ha cumplido el numero maximo de 25 lanzamientos\n");
		}//if
	}//for
}//tira dados 1

void tiraDados2(){
	int dado, fichas1=24, fichas2=24, fichasm1=1, fichasm2=1;
    printf("Da y quita \n \n");
	printf("\t \t \t \t 1 \t \t \t \t \t 1 \n");
    srand(time(NULL));
    
    //repetir hasta que sean 25 turnos
    for(int i=1; i<=25; i++){//i son los turnos
    	if(i%2==0){ //turno jugador 1
    		printf("Turno %d \n \n",i);//turno
			sleep(2);//Tiempo de espera
		    dado=1+rand()%4;//para generar valores solo del 1 al 4
			printf("Tirando dado...\n");
		    sleep(2); //Tiempo de espera
		    printf("Valor de la tirada del jugador 1: %i\n \n",dado);//valor del dado
		    switch(dado){
				//si en el dado cae 1
				case 1:
					printf("Todo \n \n");
					printf("\t \t \t %d \t \t \t \t \t %d \n\n", fichasm1, fichasm2);//fichas en la mesa
					printf("\t \t Fichas del jugador 1 \t \t \t Fichas del jugador 2 \n");
					fichas1=fichas1+(fichasm1+fichasm2);//al monton del jugador 1 se le suman las fichas que hay en la mesa
					printf("Fichas del monton del jugador 1: %d \n \n",fichas1);//monton del jugador 1
					printf("Fichas del monton del jugador 2: %d \n \n",fichas2);//monton del jugador 2
					//la mesa se queda sin fichas
					fichasm1=0;
					fichasm2=0;
					printf("\t \t \t 0 \t \t \t \t \t 0 \n\n");
					
					//pedir fichas
					if(fichasm1==0&&fichasm2==0){
						printf("Ambos pongan una ficha: \n");
						sleep(2);//tiempo de espera
						printf("\t \t \t \t 1 \t \t \t \t \t \t 1 \n");
						printf("\t \t Fichas del jugador 1 \t \t \t Fichas del jugador 2 \n");
						printf("\n");
						fichas1=fichas1-1;//al monton del jugador 1 se le resta 1
						fichas2=fichas2-1;//al monton del jugador 2 se le resta 1
						//las fichas en la mesa son 1 por jugador
						fichasm1=1;
						fichasm2=1;
					}//if
					system("pause()"); //para pausar la pantalla
					system("cls"); //limpiar la pantalla
					break;
				//si en el dado cae 1
				case 2:
					printf("Pone \n \n");
					fichasm1=fichasm1+1;//a las fichas en la mesa del jugador 1 se le suma 1
					printf("\t \t \t %d \t \t \t \t \t \t \t %d \n\n", fichasm1, fichasm2);//fichas en la mesa
					printf("\t \t Fichas del jugador 1 \t \t \t Fichas del jugador 2 \n");
					fichas1=fichas1-1;//al monton del jugador 1 se le resta 1
					printf("Fichas del monton del jugador 1: %d \n \n",fichas1);//monton del jugador 1
					printf("Fichas del monton del jugador 2: %d \n \n",fichas2);//monton del jugador 2
					system("pause()"); //para pausar la pantalla
					system("cls"); //limpiar la pantalla
					break;
				case 3:
					printf("Quita \n \n");
					printf("\t \t \t %d \t \t \t \t \t %d \n\n", fichasm1, fichasm2);//fichas en la mesa
					printf("\t \t Fichas del jugador 1 \t \t \t Fichas del jugador 2 \n");
					fichas1=fichas1+1;//a las fichas del jugador 1 se le suma 1
					fichas2=fichas2-1;//a las fichas del jugador 2 se le resta 1
					printf("Fichas del monton del jugador 1: %d \n \n",fichas1);//monton del jugador 1
					printf("Fichas del monton del jugador 2: %d \n \n",fichas2);//monton del jugador 2
					system("pause()"); //para pausar la pantalla
					system("cls"); //limpiar la pantalla
					break;
				case 4:
					printf("Mitad \n \n");
					fichas1=fichas1/2;//las fichas del jugador 1 se dividen entre 2
					fichasm1=fichasm1+fichas1;//a las fichas en la mesa del jugador 1 se le suman la mitad de su monton
					printf("\t \t \t %d \t \t \t \t \t %d \n\n", fichasm1, fichasm2);//fichas en la mesa
					printf("\t \t Fichas del jugador 1 \t \t \t Fichas del jugador 2 \n");
					printf("Cartas del monton del jugador 1: %d \n \n",fichas1);//monton del jugador 1
					printf("Cartas del monton del jugador 2: %d \n \n",fichas2);//monton del jugador 2
					system("pause()"); //para pausar la pantalla
					system("cls"); //limpiar la pantalla
					break;
				default: printf("Lanza otra vez \n");
			}//switch
		}//if
		else{//turno jugador 2
			printf("Turno %d \n \n",i);//turno
			sleep(2);//Tiempo de espera
		    dado=1+rand()%4;//para generar valores solo del 1 al 4
			printf("Tirando dado...\n");
		    sleep(2); //Tiempo de espera
		    printf("Valor de la tirada del jugador 2: %i\n \n",dado);//valor del dado
		    switch(dado){
				//si en el dado cae 1
				case 1:
					printf("Todo \n \n");
					printf("\t \t \t %d \t \t \t \t \t %d \n\n", fichasm1, fichasm2);//fichas en la mesa
					printf("\t \t Fichas del jugador 1 \t \t \t Fichas del jugador 2 \n");
					printf("Fichas del monton del jugador 1: %d \n \n",fichas1);//fichas del monton del jugador 1
					fichas2=fichas2+(fichasm1+fichasm2);//a las fichas del jugador 2 se le suman las de la mesa
					printf("Fichas del monton del jugador 2: %d \n \n",fichas2);//fichas del monton del jugador 2
					//la mesa se queda sin fichas
					fichasm1=0;
					fichasm2=0;
					printf("\t \t \t 0 \t \t \t \t \t 0 \n\n");
					
					//pedir un ficha a cada jugador
					if(fichasm1==0&&fichasm2==0){
						printf("Ambos pongan una ficha: \n");
						sleep(2);//tiempo de espera
						printf("\t \t \t \t 1 \t \t \t \t \t \t 1 \n");
						printf("\t \t Fichas del jugador 1 \t \t \t Fichas del jugador 2 \n");
						printf("\n");
						fichas1=fichas1-1;// a las fichas del jugador 1 se le resta 1
						fichas2=fichas2-1;// a las fichas del jugador 2 se le resta 1
						//las fichas en la mesa ahora son 1
						fichasm1=1;
						fichasm2=1;
					}//if
					system("pause()"); //para pausar la pantalla
					system("cls"); //limpiar la pantalla
					break;
				//si en el dado cae 2
				case 2:
					printf("Pone \n \n");
					fichasm2=fichasm2+1;//a las fichas en la mesa del jugador 2 se le suma 1
					printf("\t \t \t %d \t \t \t \t \t %d \n\n", fichasm1, fichasm2);//fichas en la mesa
					printf("\t \t Fichas del jugador 1 \t \t \t Fichas del jugador 2 \n");
					printf("Fichas del monton del jugador 1: %d \n \n",fichas1);//monton del jugador 1
					fichas2=fichas2-1;//a las fichas del jugador 2 se le resta 1
					printf("Fichas del monton del jugador 2: %d \n \n",fichas2);//monton del jugador 1
					system("pause()"); //para pausar la pantalla
					system("cls"); //limpiar la pantalla
					break;
				//si en el dado cae 3
				case 3:
					printf("Quita \n \n");
					printf("\t \t \t %d \t \t \t \t \t %d \n\n", fichasm1, fichasm2);//fichas en la mesa
					printf("\t \t Fichas del jugador 1 \t \t \t Fichas del jugador 2 \n");
					fichas2=fichas2+1;//a las fichas del jugador 2 se le suma 1
					fichas1=fichas1-1;//a las fichas del jugador 1 se le resta 1
					printf("Fichas del monton del jugador 1: %d \n \n",fichas1);//monton del jugador 1
					printf("Fichas del monton del jugador 2: %d \n \n",fichas2);//monton del jugador 2
					system("pause()"); //para pausar la pantalla
					system("cls"); //limpiar la pantalla
					break;
				case 4:
					printf("Mitad \n \n");
					fichas2=fichas2/2;//las fichas del jugador 2 se dividen entre 2
					fichasm2=fichasm2+fichas2;//a las fichas en la mesa del jugador 2 se le suman la mitad de su monton
					printf("\t \t \t %d \t \t \t \t \t %d \n\n", fichasm1, fichasm2);//fichas en la mesa
					printf("\t \t Fichas del jugador 1 \t \t \t Fichas del jugador 2 \n");
					printf("Fichas del monton del jugador 1: %d \n \n",fichas1);//monton del jugador 1
					printf("Fichas del monton del jugador 2: %d \n \n",fichas2);//monton del jugador 2
					system("pause()"); //para pausar la pantalla
					system("cls"); //limpiar la pantalla
					break;
				default: printf("Lanza otra vez \n \n");
			}//switch
		}//else
		//si las fichas del jugador 2 se acaban
		if(fichas2==0){
			printf("El jugador 1 es el ganador!!!\n");
			break;
		}//if
		//si las fichas del jugador 1 se acaban
		if(fichas1==0){
			printf("El jugador 2 es el ganador!!!\n");
			break;
		}//if
		if(i==25){
			printf("El juego termino!!\n");
			printf("Se ha cumplido el numero maximo de 25 lanzamientos\n");
		}//if
	}//for
}//tira dados 2