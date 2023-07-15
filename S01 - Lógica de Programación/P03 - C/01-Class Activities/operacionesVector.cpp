/* Captura de elementos en un arreglo entero */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 20

void captura(int vector[]);
void mostrar(int vector[]);
int sumatoria(int vector[]);
void llenado(int datos[]);
int mostrarPares(int datos[]);
int busca(int datoB,int datos[]);

int main(int argc, const char * argv[]) {
    int vector[TAM],suma,datos[TAM],total,datoB,encontrado=0;
    srand(time(NULL));
  /*captura(vector);
	mostrar(vector);
	suma=sumatoria(vector);
	printf("Sumatoria: %d",suma);*/
	llenado(datos);
	mostrar(datos);
	total=mostrarPares(datos);
	printf("\nTotal de valores par: %d",total);
	printf("\nDato a buscar: ");
	scanf("%d",&datoB);
	encontrado=busca(datoB,datos);
	if(encontrado==1){
		printf("\nEl valor fue localizado");
	}else{
		printf("\nEl valor no existe");
	}
    return 0;
}

void captura(int vector[]){
    for(int i=0; i<TAM; i++){
        printf("Dame valor [%d]: ",i);
        scanf("%d",&vector[i]);
    }//i
}//captura

void mostrar(int vector[]){
    for(int i=0; i<TAM; i++){
        printf("%d \t",vector[i]);
    }//i
    printf("\n");
}//mostrar

int sumatoria(int vector[]){
	int suma=0;
	for(int i=0; i<TAM; i++){
		suma+=vector[i];
	}
	return suma;
}

void llenado(int datos[]){
	for(int i=0;i<TAM;i++){
		datos[i]=rand()%101;
	}
}

int mostrarPares(int datos[]){
	int par=0;
	for(int i=0;i<TAM;i++){
		if(datos[i]%2==0){
			par++;
			printf("%d\t",datos[i]);
		}
	}
	return par;
}

int busca(int datoB,int datos[]){
	int enc=0;
	for(int i=0;i<TAM;i++){
		if(datos[i]==datoB){
			enc=1;
			break;
		}
	}
	return enc;
}