/*
Manejo de ciclos anidados
*/

#include <stdio.h>

int main(){
	char letra='a';
	
	for(int i=1;i<=5;i++){
		for(int j=1;j<=i;j++){
			printf("%d\t",letra++);
		}
		printf("\n");
	}	
}