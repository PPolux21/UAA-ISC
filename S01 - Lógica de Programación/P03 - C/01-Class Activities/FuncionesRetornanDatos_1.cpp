/*
Funciones de retorno de valores
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int aleatorio();

int main(){
	
	int num;
	for(int i=1;i<=10;i++){
		num=aleatorio();
		printf("%d\n",num);
	}
	return 0;
}

int aleatorio(){
	int limite,numero;
	srand(time(NULL));
	printf("Limite: ");
	scanf("%d",&limite);
	numero=rand()%(limite+1);
	return numero;
}