/*
Funciones de retorno de valores
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int aleatorio();
void generaValores();
void mostrar(int valor);

int main(){
	generaValores();
	return 0;
}

void generaValores(){
	int num;
	for(int i=1;i<=10;i++){
		num=aleatorio();
		mostrar(num);
	}
}

int aleatorio(){
	int limite,numero;
	srand(time(NULL));
	printf("Limite: ");
	scanf("%d",&limite);
	numero=rand()%(limite+1);
	return numero;
}

void mostrar(int valor){ // valor y num tienen el mismo valor
	printf("%d\n",valor);
}