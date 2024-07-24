.model small
     
;Segmento de Pila
.stack ;200h ;por defaulf es 100h
                 
;Segmento de Datos                 
.data

num     DW  24678
numvec  DB  6 DUP('0')
aux     DW  10

;Segmento de codigo
.code              


;Esto recupera la direccion de memoria .data para el DS
MOV AX,@DATA
MOV DS,AX

inicio:

    MOV AX,num
    XOR DX,DX
    MOV DI,5
    
ciclo:    
    
    DIV aux
    MOV numvec[DI], DL
    XOR DX,DX
    DEC DI   
    JNE ciclo
           
    ;Terminador de programa          
    MOV AH,4Ch
    INT 21h                
    
END