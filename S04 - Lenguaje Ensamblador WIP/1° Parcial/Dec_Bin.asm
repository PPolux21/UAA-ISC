.model small
     
;Segmento de Pila
.stack ;200h ;por defaulf es 100h
                 
;Segmento de Datos                 
.data

numdec  DW  555
divisor DW  2    
binario DB  16 DUP(?) ;Reserva en memoria 16 espacios vacios

;Segmento de codigo
.code              


;Esto recupera la direccion de memoria .data para el DS
MOV AX,@DATA
MOV DS,AX

inicio:

    XOR DX,DX ;limpia de DX
    MOV AX,numdec 
    MOV DI,15
    
ciclow:    

    XOR DX,DX 
    DIV divisor
    MOV binario[DI], DL   
    DEC DI
    CMP AX,0
    JNE ciclow
           
    ;Terminador de programa          
    MOV AH,4Ch
    INT 21h                
    
END