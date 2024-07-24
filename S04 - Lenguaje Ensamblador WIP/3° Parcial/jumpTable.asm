.model small
     
;Segmento de Pila
.stack ;200h ;por defaulf es 100h
                 
;Segmento de Datos                 
.data

;saltos
jumptables  DW  suma, resta, multi, divi, default

aux     DW  2

;Segmento de codigo
.code              


;Esto recupera la direccion de memoria .data para el DS
MOV AX,@DATA
MOV DS,AX

inicio:

    MOV AX,2
    SHL AX,2
    SUB AX,2
    MOV BX,AX
    MOV AX, [jumptables + BX]
    JMP AX

suma:

    JMP fin

resta:     

    JMP fin

multi:

    JMP fin

divi:

    PUSHA
    DIV aux
    
    POPA

    JMP fin

default:



fin:

    
           
    ;Terminador de programa          
    MOV AH,4Ch
    INT 21h                
    
END