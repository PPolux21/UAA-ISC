/*
Ejercicio 25
Espinoza Sánchez José Luis-280676-1°C
18/oct/2022
Números romanos
*/

#include <stdio.h>

int main(){
	
	int num=0,unid=0,dec=0,cen=0;
	
	printf("Introduce un numero: ");
	scanf("%d",&num);
	
	if(num>=100 && num<=999){
		
		unid=num%10;
		num/=10;
		dec=num%10;
		cen=num/10;
		
		switch(cen){
			case 1:
				printf("C");
				break;
			case 2:
				printf("CC");
				break;
			case 3:
				printf("CCC");
				break;
			case 4:
				printf("CD");
				break;
			case 5:
				printf("D");
				break;
			case 6:
				printf("DC");
				break;
			case 7:
				printf("DCC");
				break;
			case 8:
				printf("DCCC");
				break;
			case 9:
				printf("CM");
				break;
		}
		
		switch(dec){
			case 1:
				printf("X");
				break;
			case 2:
				printf("XX");
				break;
			case 3:
				printf("XXX");
				break;
			case 4:
				printf("XL");
				break;
			case 5:
				printf("L");
				break;
			case 6:
				printf("LX");
				break;
			case 7:
				printf("LXX");
				break;
			case 8:
				printf("LXXX");
				break;
			case 9:
				printf("XC");
				break;
		}
		
		switch(unid){
			case 1:
				printf("I");
				break;
			case 2:
				printf("II");
				break;
			case 3:
				printf("III");
				break;
			case 4:
				printf("IV");
				break;
			case 5:
				printf("V");
				break;
			case 6:
				printf("VI");
				break;
			case 7:
				printf("VII");
				break;
			case 8:
				printf("VIII");
				break;
			case 9:
				printf("IX");
				break;
		}
		
	}else{
		
		printf("El numero no es válido!");
		
	}
	
}
