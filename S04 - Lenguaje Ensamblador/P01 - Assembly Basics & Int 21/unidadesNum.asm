.model small
     
;Segmento de Pila
.stack ;200h ;por defaulf es 100h
                 
;Segmento de Datos                 
.data

num     DW  4678
uni     DB  ?
dece    DB  ?
cen     DB  ?
mil     DB  ?
aux     DW  1000
aux2    DB  10

;Segmento de codigo
.code              


;Esto recupera la direccion de memoria .data para el DS
MOV AX,@DATA
MOV DS,AX

inicio:

    XOR DX,DX
    
    MOV AX,num
    DIV aux
    MOV mil,AL
    MOV BX,DX
             
    XOR DX,DX
    
    MOV AX,aux
    DIV aux2
    MOV aux,AX
    
    XOR DX,DX
    
    MOV AX,BX
    DIV aux
    MOV cen,AL
    MOV BX,DX
             
    XOR DX,DX
    
    MOV AX,aux
    DIV aux2
    MOV aux,AX
    
    XOR DX,DX
    
    MOV AX,BX
    DIV aux
    MOV dece,AL
    MOV uni,DL
           
    ;Terminador de programa          
    MOV AH,4Ch
    INT 21h                
    
END