/* CODIGO DE UN MENU GENERICO PARA USAR EN CUALQUIER PROGRMAA -ADAPTAR SEGUN NECESIDADES- */

#include <stdio.h>


//Prototipo
void menu();


int main() {
    menu();   //llamada a la función
    return 0;
}

//Desarrollo de las funciones
void menu(){
    int opc=0;
    
    do{
        printf("TITULO DEL MENU \n");
        printf("OPCION 1 ....... 1\n");
        printf("OPCION 2 ....... 2\n");
        printf("OPCION 3 ....... 3\n");
        printf("OPCION 4 ....... 4\n");
        printf("OPCION 5 ....... 5\n");
        printf("Salir    ....... 6\n");
        printf("Selecciona una opcion: ");
        scanf("%d",&opc);
        switch (opc) {
                
        }//switch
        
        
    }while(opc != 6);
}//menu
