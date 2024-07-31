endl MACRO
    MOV DX,OFFSET salto
    MOV AH,09
    INT 21h
ENDM    

.model small
     
;Segmento de Pila
.stack ;200h ;por defaulf es 100h
                 
;Segmento de Datos                 
.data

msj     DB  "Es el peor Febrero D:",'$'
salto   DB  13,10,'$'
buff    DB  20,?,20 DUP(?)


;Segmento de codigo
.code              


;Esto recupera la direccion de memoria .data para el DS
MOV AX,@DATA
MOV DS,AX

inicio:

    ;servicio 02h Salida de caracter
    MOV AH,02
    MOV DL,'B' 
    INT 21h
    
    ;servicio 09h Salida de caracteres en pantalla
    endl
    MOV AH,09
    MOV DX,OFFSET msj
    INT 21h    
    
    ;servicio 01h Entrada de caracter con eco
    endl
    MOV AH,01
    INT 21h
     
    ;servicio 08h Entrada de caracter sin eco
    MOV AH,08
    INT 21h   
    
    ;servicio 0Ah Entrada de un buffer de caracteres
    endl
    MOV AH,0Ah
    MOV DX,OFFSET buff
    INT 21h
    
    ;servicio 05h Printer output
    MOV AH,05h
    MOV DL,"C"        
    INT 21h
    
    ;servicio 2Ah lectura del reloj en tiempo real
    MOV AH,2Ah
    INT 21h
                                                        
    ;Terminador de programa          
    MOV AH,4Ch
    INT 21h                
    
END