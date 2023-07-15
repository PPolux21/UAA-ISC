/*
Manejo de ciclos anidados, con dos ciclos internos
*/

#include <stdio.h>
#define REN 10



int main(){
	for(int i=REN;i>=1;i--){
		for(int k=0;k<=REN-i;k++){
			printf(" ");
		}
		for(int j=1;j<=i;j++){
			printf("* ");
		}
		printf("\n");	
	}	
}