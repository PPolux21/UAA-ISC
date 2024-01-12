#ifndef interfazConfiguracion_hpp
#define interfazConfiguracion_hpp

#include <ctype.h>

void interfazConfiguracion() {

    bool actualiza = true;// variable para actualizar pantalla
    bool escribiendo = false;//variable para determinar si se está escribiendo
    int escenario=1; //escenario que se va a mostrar
    while (true) {
        if(actualiza)//se muestra pantalla
        {
        
            system("cls");
            tipoEscenario(escenario, escribiendo);       
            
            cout << endl;

            actualiza = false;
        }

        if (_kbhit()) {//cuando se presiona una tecla evalua
            int key = _getch();

            if (key == 13) { // Verifica si se presionó la tecla "Enter" y luego evalua el escenario en el que está
				if(escenario == 4)//si está en el escenario 4 (salir)
				{
					exit(0);
				}else if (escenario == 5)//si está en el escenario 5 (iniciar)
				{
					if (maxTamProceso != 0 && maxCuantoProceso != 0 && cuantoSistema != 0)
					{
						break;				
					}
				}else if(escenario >=1 && escenario <=3)//si está en los escenarios 1 al 3 (configuraciones)
				{
					if (!escribiendo)//verifica para empezar o terminar de escribir
					{
						switch (escenario)
						{
						case 1:
							maxTamProceso = 0;
							break;
						case 2:
							maxCuantoProceso = 0;
							break;
						case 3:
							cuantoSistema = 0;
							break;
						}
						actualiza = true;
						escribiendo = true;
					}else
					{
						actualiza = true;
						escribiendo = false;
					}
				}
                
            }

            if (escribiendo)//cuando se está escribiendo evalua la tecla presionada
            {
				if (key >= 48 && key <= 57) { // Verifica si se presionó una tecla numérica (0-9) 0 = 48  9 = 57
					switch (escenario)
					{
					case 1:
						maxTamProceso *= 10;
						maxTamProceso += key - 48;
						if (maxTamProceso > TAM)
						{
							maxTamProceso = TAM;
						}
						
						break;
					case 2:
						maxCuantoProceso *= 10;
						maxCuantoProceso += key - 48;
						if(maxCuantoProceso > 999999999)
						{
							maxCuantoProceso = 999999999;
						}
						break;
					case 3:
						cuantoSistema *= 10;
						cuantoSistema += key - 48;
						if(cuantoSistema > 999999999)
						{
							cuantoSistema = 999999999;
						}
						break;
					}
					actualiza = true;
				} else if (key == 8) { // Verifica si se presionó la tecla de retroceso (borrar)
					switch (escenario)
					{
					case 1:
						maxTamProceso /= 10;
						break;
					case 2:
						maxCuantoProceso /= 10;
						break;
					case 3:
						cuantoSistema /= 10;
						break;
					}
					actualiza = true;
				} 
            }else//si no es está escribiendo (escribiendo==false)
            {
                if (key == 27) { // Verifica si se presionó la tecla "Escape"
                    exit(0);
                } else if (key == 0 || key == 224) { // Verifica si es una tecla especial
                    key = _getch(); // Obtiene la tecla real (para flechas)
                    switch (key) {
                        case 72://arriba
							if(escenario == 1)
							{
								escenario = 5;
							}else{
								escenario--;
							}
                            actualiza = true;
                            break;
                        case 80://abajo
							if(escenario == 5)
							{
								escenario = 1;
							}else{
								escenario++;
							}
                            actualiza = true;
                            break;
                        case 75://izquierda
                            if(escenario == 1)
							{
								escenario = 5;
							}else{
								escenario--;
							}
                            actualiza = true;
                            break;
                        case 77://derecha
                            if(escenario == 5)
							{
								escenario = 1;
							}else{
								escenario++;
							}
                            actualiza = true;
                            break;
                        default:
                            break;

                    }//switch

                }

            }//if escribiendo
            
        }//if tecla presionada

        Sleep(100); // Pequeño retraso para evitar altos consumos de CPU
    }

}

void tipoEscenario(int tp, bool escribiendo){
	
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	system("COLOR B0");
	cuadro(0,0,110,30);
	cuadro(1,1,109,3);
	
	gotoxy(45,2); 
	cout << "Configuracion y Controles";
	
	gotoxy(2,4); 
	cout << "CONFIGURACION";
	
	gotoxy(3,6); 
	cout << "Memoria: 1024";
	
	gotoxy(3,8);
	cout << "Tamano maximo de memoria del proceso: " << maxTamProceso;
	
	gotoxy(3,10);
	cout << "Cuanto maximo del proceso: " << maxCuantoProceso;
	
	gotoxy(3,12);
	cout << "Cuanto del sistema: " << cuantoSistema;
	
	gotoxy(2,14);
	cout << "CONTROLES";
	
	gotoxy(3,16);
	cout << "Para detener la simulacion presione \"S\" o ESC";
	
	gotoxy(3,18);
	cout << "Para aumentar la velocidad la simulacion presione \"+\" o Flecha derecha ";
	
	gotoxy(3,20);
	cout << "Para disminuir la velocidad la simulacion presione \"-\" o Flecha izquierda";
	
	gotoxy(33,22);
	cout << "Salir";
	
	gotoxy(66, 22);
	cout << "Iniciar";

	if (escribiendo)
	{
		SetConsoleTextAttribute(h,189);
	}
	switch(tp)
	{
		case 1:			
			cuadro(40, 7, 50, 9);
			break;
		case 2:

			cuadro(29, 9, 39, 11);
			break;
		case 3:
			cuadro(22, 11, 32, 13);
			break;
		case 4:
			cuadro(30, 21, 40, 23);
			break;
		case 5:
			cuadro(64, 21, 74, 23);
			break;
	}
	
	
}

//FUNCION GOTOXY
void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
 
 
 //FUNCION QUE DIBUJA EL CUADRO
void cuadro(int x1,int y1,int x2,int y2){
	int i;

    for (i=x1;i<x2;i++){
		gotoxy(i,y1); printf("\304"); //linea horizontal superior
		gotoxy(i,y2); printf("\304"); //linea horizontal inferior
    }

    for (i=y1;i<y2;i++){
		gotoxy(x1,i); printf("\263"); //linea vertical izquierda
		gotoxy(x2,i); printf("\263"); //linea vertical derecha
	}

    gotoxy(x1,y1); printf("\332");
    gotoxy(x1,y2); printf("\300");
    gotoxy(x2,y1); printf("\277");
    gotoxy(x2,y2); printf("\331");
}
 
#endif