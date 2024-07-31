.model small
     
;Segmento de Pila
.stack ;200h ;por defaulf es 100h
                 
;Segmento de Datos                 
.data

numdec  DW  1         ;en relacion 0.000 a 0.999
multip  DW  2    
binario DB  32 DUP(?) ;Reserva en memoria 32 espacios vacios

;Segmento de codigo
.code              


;Esto recupera la direccion de memoria .data para el DS
MOV AX,@DATA
MOV DS,AX

inicio:

    XOR DX,DX ;limpia de DX
    MOV AX,numdec
    XOR DI,DI     
    
ciclo:;multiplicar el numerador hasta que sea mayor que el denominador    
    
    ;para cuando hay un 0 como resultado en AX
    ;CMP AX,0
    ;JE  finciclo
    
    MUL multip
    
    CMP AX,1000
    JAE unobinario
    
    MOV binario[DI], 0
    INC DI
    
    CMP DI,32
    JNE ciclo 
    JMP finciclo
         
unobinario:

    SUB AX,1000

    MOV binario[DI], 1
    INC DI
    
    CMP DI,32
    JNE ciclo              
         
finciclo:    
    
           
    ;Terminador de programa          
    MOV AH,4Ch
    INT 21h                
    
END