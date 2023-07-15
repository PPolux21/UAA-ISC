/*
Ejercicio 17
Espinoza Sánchez José Luis-280676-1°C
31/oct/2022
Leer un valor entero, positivo y comprobar si contiene la cifra 3.
*/

#include <stdio.h>

int main()
{
	int numero,digito=0,existe=0;
	
	printf("Dame un numero: ");
	scanf("%d",&numero);
	
	while(numero>0){
		
		digito=numero%10;
		numero/=10;
		
		if(digito==3)
		{
			printf("Contiene al numero 3");
			existe=1;
			break;
		}
		
	}
	
	if(existe==0)
	{
		printf("No contiene al numero 3");
	}
}