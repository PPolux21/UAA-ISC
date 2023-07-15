/*
Ejercicio 1
Espinoza Sánchez José Luis-280676-1°C
25/11/2022
Escribir un programa con una función que calcule el cubo de un número real (float). El
valor del numero lo recibe como parámetro. El resultado deberá ser otro número real y
devolverse con un return
*/

#include <stdio.h>

float potencia(float base);

int main()
{
	float base,res=0;
	printf("Dame la base: ");
	scanf("%f",&base);
	res=potencia(base);
	printf("Resultado: %.3f",res);
	return 0;
}

float potencia(float base)
{
	float resultado=1;
	for(int i=0;i<3;i++)
	{
		resultado*=base;
	}
	return resultado;
}