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

color   DB  0
row     DW  0
fil     DW  0

;Segmento de codigo
.code              


;Esto recupera la direccion de memoria .data para el DS
MOV AX,@DATA
MOV DS,AX

inicio:

    MOV AH,0
    MOV AL,13h ;RES: 20x200, 256 colores, grafico
    INT 10h
    
ciclo:
    pixel        
    INC color
    INC row
    INC fil
    CMP row,200
    JNAE ciclo
           
    ;Terminador de programa          
    MOV AH,4Ch
    INT 21h                
    
END