/*
Capturar un valor (tamaño) y hacer con eso un cuadrado (las filas y columnas del número de tamaño)
*/

#include <stdio.h>

int main(){
	
	int tam=0;
	
	printf("Introduce el tamano del cuadro: ");
	scanf("%d",&tam);
	
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
}