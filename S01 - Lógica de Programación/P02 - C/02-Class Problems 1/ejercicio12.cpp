/*
Ejercicio 12
Espinoza Sánchez José Luis-280676-1°C
08/oct/2022
Construya un programa para el siguiente diagrama de flujo
*/

#include <stdio.h>

int main(){
	
	int tra=0,eda=0,dia=0,cos=0;
	
	printf("Introduce tu clave de trabajo: ");
	scanf("%d",&tra);
	printf("Introduce edad: ");
	scanf("%d",&eda);
	printf("Introduce los dias que se ha trabajado: ");
	scanf("%d",&dia);
	
	switch(tra){
		case 1:	cos=dia*2800;
			break;
		case 2:	cos=dia*1950;
			break;
		case 3:	cos=dia*2500;
			break;
		case 4:	cos=dia*1150;
			break;
		default:cos=-1;
			break; 		
	}
	
	if(cos!=-1){
		if(eda>=60){
			
			cos*=0.75;
						
		}else{
			
			if(eda<=25){
				
				cos*=0.85;
				
			}
			
		}
		
		/*
		Aquí el diagrama pedía mostrar otras dos variables que no se usaron en el programa,
		así que solo puse la que sí se usó, asdemás de que no me acuerdo cómo lo hicimos en clase
		*/
		
		printf("El monto a pagar es %d",cos);
		
	}else{
		
		printf("La clave es incorrecta");
		
	}
}