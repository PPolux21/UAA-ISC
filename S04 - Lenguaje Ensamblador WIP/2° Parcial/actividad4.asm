print MACRO msj
    
    MOV AH,09h
    MOV DX,OFFSET msj
    INT 21h
    
ENDM    

endl MACRO
    MOV DX,OFFSET salto
    MOV AH,09
    INT 21h
ENDM

pixel MACRO
    
    MOV AH,0Ch
    MOV AL,color
    MOV BH,0
    MOV CX,row
    MOV DX,fil
    INT 10h
    
ENDM

.model small
     
;Segmento de Pila
.stack ;200h ;por defaulf es 100h
                 
;Segmento de Datos                 
.data

salto   DB  13,10,'$'

menu1   DB  "Que figura dibujar?","$" 
menu2   DB  "1) Cuadrado","$" 
menu3   DB  "2) Rectangulo","$" 
menu4   DB  "3) Triangulo","$" 
menu5   DB  "4) Rombo","$" 
menu6   DB  "5) Salir","$" 
menu7   DB  "Opcion: ","$" 

color   DB  ?                           
row     DW  ?                         
fil     DW  ?
tamMax  DW  ?
auxTam  DW  30  ;Variable del alto de la figura  
largo   DW  50  ;largo del rectangulo
auxTria DW  ?   ;auxiliar para el triangulo y rombo
auxRomb DW  ?   ;auxiliar para el rombo


;Segmento de codigo
.code              


;Esto recupera la direccion de memoria .data para el DS
MOV AX,@DATA
MOV DS,AX

inicio:
    
    MOV AH,0
    MOV AL,3 ;RES: 80x25, 16 colores, texto
    INT 10h
    
menu:

    print menu1
    endl
    print menu2
    endl
    print menu3
    endl
    print menu4
    endl
    print menu5
    endl
    print menu6
    endl
    print menu7

    MOV AH,01
    INT 21h
    
    
    CMP AL,31h
    JE cuadrado
    CMP AL,32h
    JE rectangulo
    CMP AL,33h
    JE triangulo
    CMP AL,34h
    JE rombo
    CMP AL,35h
    JE fin
    
    MOV AH,06
    MOV AL,10    ;Numero de lineas a desplazar
    MOV BH,07h  ;Atributo (color)(4b mas significativos para color de pantalla y 4b menos significativos para color texto)
    MOV CH,0   ;Linea donde comienza
    MOV CL,0   ;Columna donde comienza
    MOV DH,7    ;Linea donde termine
    MOV DL,20    ;Columna donde termina
    INT 10h
    
    MOV AH,02
    MOV BH,0  ;Pagina activa actual
    MOV DH,0 ;Linea
    MOV DL,0 ;Columna
    INT 10h
    
    JMP menu

cuadrado:
    MOV AH,0
    MOV AL,13h ;RES: 20x200, 256 colores, grafico
    INT 10h
    
    MOV color,1
    MOV row,30
    MOV fil,30
    
    MOV DX,auxTam
    ADD DX,fil
    MOV tamMax,DX
     
    XOR DX,DX
cicloCuad1:
    
    CMP DX, tamMax
    JE finDibujo
    
    MOV row,30
    
cicloCuad2:    
    pixel  
    
    INC row
    MOV CX,row
    
    CMP CX, tamMax
    JNE cicloCuad2
    
    INC fil
    MOV DX,fil
    JMP cicloCuad1
    
    
rectangulo:
    MOV AH,0
    MOV AL,13h ;RES: 20x200, 256 colores, grafico
    INT 10h
    
    MOV color,2
    MOV row,30
    MOV fil,30
    
    MOV DX,auxTam
    ADD DX,fil
    MOV tamMax,DX
    
    MOV DX,largo
    ADD DX,row
    MOV largo,DX
     
    XOR DX,DX
cicloRect1:
    
    CMP DX, tamMax
    JE finDibujo
    
    MOV row,30
    
cicloRect2:    
    pixel  
    
    INC row
    MOV CX,row
    
    CMP CX, largo
    JNE cicloRect2
    
    INC fil
    MOV DX,fil
    JMP cicloRect1
    
    
triangulo:
    MOV AH,0
    MOV AL,13h ;RES: 20x200, 256 colores, grafico
    INT 10h
    
    MOV color,3
    MOV row,150
    MOV fil,20
    
    MOV DX,auxTam
    ADD DX,fil
    MOV tamMax,DX
    
    MOV DX,row
    MOV auxTria,DX
    INC auxTria
    MOV DI,0
     
    XOR DX,DX
cicloTria1:
    
    CMP DX, tamMax
    JE finDibujo
    
    MOV BX,150
    SUB BX,DI
    MOV row,BX
    
cicloTria2:    
    pixel  
    
    INC row
    MOV CX,row
    
    CMP CX, auxTria
    JNE cicloTria2
    
    INC DI
    INC auxTria
    
    INC fil
    MOV DX,fil
    JMP cicloTria1
           
    
rombo:
    MOV AH,0
    MOV AL,13h ;RES: 20x200, 256 colores, grafico
    INT 10h
    
    MOV color,4
    MOV row,150
    MOV fil,20
    
    MOV DX,auxTam
    ADD DX,fil    
    MOV tamMax,DX
    ADD DX,auxTam 
    MOV auxRomb,DX
    
    MOV DX,row
    MOV auxTria,DX
    INC auxTria
    MOV DI,0
     
    XOR DX,DX
cicloRomb1:
    
    CMP DX, tamMax
    JE cicloRomb3
    
    MOV BX,150
    SUB BX,DI
    MOV row,BX
    
cicloRomb2:    
    pixel  
    
    INC row
    MOV CX,row
    
    CMP CX, auxTria
    JNE cicloRomb2
    
    INC DI
    INC auxTria
    
    INC fil
    MOV DX,fil
    JMP cicloRomb1

cicloRomb3:
    
    CMP DX,auxRomb
    JE finDibujo
    
    MOV BX,150
    SUB BX,DI
    MOV row,BX
    
cicloRomb4:    
    pixel  
    
    INC row
    MOV CX,row
    
    CMP CX, auxTria
    JNE cicloRomb4
    
    DEC DI
    DEC auxTria
    
    INC fil
    MOV DX,fil
    JMP cicloRomb3        
    

finDibujo:    

    MOV AH,08
    INT 21h
    
    JMP inicio

    
fin:           
    ;Terminador de programa          
    MOV AH,4Ch
    INT 21h                
    
END