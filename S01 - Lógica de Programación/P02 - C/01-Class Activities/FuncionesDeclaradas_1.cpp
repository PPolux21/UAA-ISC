/*
Ejemplo de uso de funciones
*/

#include <stdio.h>
#include <stdlib.h>

// Aquí va la declaración de funciones

void menu();
void mostrarCuadro();
void mostrarTriangulo();
void ciclo();

// main
int main(){
	
	menu();	// Esto es una llamada a la función
	
}

// Implementación de funciones

void menu(){
	
	int opc;
	do{
		system("cls");
		printf("MENU DE OPCIONES \n");
		printf("Mostrar cuadro- - - 1\n");
		printf("Mostrar triangulo - 2\n");
		printf("Obtener promedios - 3\n");
		printf("Salir - - - - - - - 4\n");
		printf("\nTu opcion: ");
		scanf("%d",&opc);
		
		switch(opc){
			
			// Dependiendo de la opción seleccionada se llama a la función correspondiente
			
			case 1: mostrarCuadro();
				break;
			case 2: mostrarTriangulo();
				break;
			case 3: ciclo();
				break;
		}
	}while(opc!=4);
	
}

void mostrarCuadro(){
	
	int tam=0;
	
	printf("\nCUADRO\n");
	printf("Tamano del cuadro: ");
	scanf("%d",&tam);
	printf("\n");
	
	for(int i=1;i<=tam;i++){
		
		if(i==1 || i==tam){
			
			for(int k=1;k<=tam;k++){
				printf("* ");
			}
			printf("\n");
			
		}else{//if i
		
			for(int j=1;j<=tam;j++){				
				if(j==1 || j==tam){				
					printf("* ");					
				}else{								
					printf("  ");	
				}				
			}		
			printf("\n");		
			
		}//if i
		
	}//for renglón
	
	system("pause");
		
}

void mostrarTriangulo(){
	int ren=0;
	
	printf("\nTRIANGULO\n");
	printf("Tamano del triangulo: ");
	scanf("%d",&ren);
	printf("\n");
	
	for(int i=ren;i>=1;i--){
		for(int k=0;k<=ren-i;k++){
			printf(" ");
		}
		for(int j=1;j<=i;j++){
			printf("* ");
		}
		printf("\n");	
	}	
	system("pause");
}

void ciclo(){
	// Obtrener promedios
	int totAlu=0,totCalif=0;
	float calif,suma,prom,promGpo;
	
	printf("\nCICLO\n");
	printf("Total de alumnos: ");
	scanf("%d",&totAlu);
	printf("Total de calificaciones: ");
	scanf("%d",&totCalif);
	
	for(int i=1;i<=totAlu;i++){
		suma=0;
		for(int j=1;j<=totCalif;j++){
			printf("Dame la calificacion: ");
			scanf("%f",&calif);
			suma+=calif;
		}
		prom=0;
		prom=suma/totCalif;
		promGpo+=prom;
		printf("El promedio es: %.2f\n",prom);
	}
	promGpo/=totAlu;
	printf("El promedio del grupo es: %.2f\n",promGpo);
	
	system("pause");
}