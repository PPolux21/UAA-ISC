.model small
     
;Segmento de Pila
.stack ;200h ;por defaulf es 100h
                 
;Segmento de Datos                 
.data

var     DB 'z'
var1    DB ?
array   DB 1,2,3,4,5
var2    DW 0FEEDh
var3    DB 2

;Segmento de codigo
.code              


;Esto recupera la direccion de memoria .data para el DS
MOV AX,@DATA
MOV DS,AX

inicio:

    MOV AL,var
    
    ;Suma con carry
    
    ADC AL, 10h
    
    ;Resta
    ;Funciona con la misma sintaxis que la suma
    
    SUB AL, 1010b
    
    ;Resta con prestamo
    
    SBB AL,9
    
    
    ;Division
    ;Division de 8bits
    
    MOV AX,11
    DIV var3
    
    ;16bits
    MOV AX,0FF1h
    MOV BX,2
    XOR DX,DX
    DIV BX
    
    MOV AX,11
    XOR DX,DX
    MOV BL, 0FEh    ;-2 en complemento a 2
    IDIV BL
    
    ;Multiplicacion
    
    ;8bits
    
    MOV AX, 10h
    MUL var3
    
    ;16bits
    
    MOV AX, 0FFFFh
    XOR DX,DX
    MOV BX,02
    MUL BX
    
    ;8bits con un numero grande
    
    MOV AL,05h
    MOV AH,0FEh
    IMUL AH
    
    ;Terminador de programa          
    MOV AH,4Ch
    INT 21h                
    
END