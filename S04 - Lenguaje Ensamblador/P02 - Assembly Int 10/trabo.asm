MACRO drawpix aux
    MOV AH,0Ch
    MOV AL,aux
    MOV BH,0
    
    INT 10h
    
ENDM

.model small

;segmento de pila
.stack

;segmento de datos
.data       

;xold    DW  0
;yold    DW  0
msj     DB  "Elige un color entre 1-F: ","$"    
msjFin  DB  "Presiona calquier tecla para salir . . . ","$"
color   DB  ?

;segmento de codigo
.code

;estas lineas recuperan la direccion de memoria .data
MOV AX,@DATA
MOV DS,AX

inicio:
    MOV AH,05
    MOV BH,1
    INT 10h

    MOV AH,09
    LEA DX,msj
    ;MOV DX,OFFSET msj
    INT 21h
    
    MOV AH,01
    INT 21h
    
    CMP AL,31h
    JNAE inicio
    CMP AL,39h
    JA  letras
    SUB AL,30h
    MOV color,AL
    JMP continua
    
letras:
    CMP  AL,41h
    JNAE inicio
    CMP  AL,46h
    JA   inicio
    ADD  AL,-37h
    MOV  color,AL
    
continua:
    
    ;CAMBIAR A MODO GRAFICO 
    MOV AH,0
    MOV AL,13h
    INT 10h
    
    ;EJEMPLOS INT 33h
    
    
    ;RESET DEL DRIVER DEL RATON
    MOV AX,0
    INT 33h
    
click_mouse:
    MOV DL,0FFh
    MOV AH,06
    INT 21h
    CMP AL,1Bh
    JE salir 

    MOV AX,03
    INT 33h
    SHR CX,1    ;DIVISION ENTRE 2
    CMP BX,1
    JNE click_mouse
    drawpix color
    JMP click_mouse  
    
salir:  
    
    MOV AH,0
    MOV AL,03
    MOV BH,0
    INT 10h
    
    MOV AH,09
    MOV DX,OFFSET msjFin
    INT 21h
           
    MOV AH,08
    INT 21h
                      
    ;terminar programa
    MOV AH, 4Ch
    INT 21h
END          

;dia AL, anio