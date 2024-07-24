.model small
     
;Segmento de Pila
.stack ;200h ;por defaulf es 100h
                 
;Segmento de Datos                 
.data

num     DW  ?
numvec  DB  1,2,3
aux     DW  10
digit   DW  3        ;cantidad de digitos del numero
                     ;maximo 5, minimo 1

;Segmento de codigo
.code              


;Esto recupera la direccion de memoria .data para el DS
MOV AX,@DATA
MOV DS,AX

inicio:
    
    XOR AX,AX
    XOR DX,DX
    XOR DI,DI
    MOV AL,numvec[DI]
    DEC digit
    
ciclo:    
    
    MUL aux  
    INC DI
    ADD AL,numvec[DI]
    CMP DI, digit
    JNE ciclo
    
    MOV num,AX
           
    ;Terminador de programa          
    MOV AH,4Ch
    INT 21h                
    
END