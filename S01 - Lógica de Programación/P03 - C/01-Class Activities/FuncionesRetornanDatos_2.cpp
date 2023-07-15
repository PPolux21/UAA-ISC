/*
Funciones de retorno de valores
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int aleatorio();
void generaValores();

int main(){
	generaValores();
	return 0;
}

void generaValores(){
	int num;
	for(int i=1;i<=10;i++){
		num=aleatorio();
		printf("%d\n",num);
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