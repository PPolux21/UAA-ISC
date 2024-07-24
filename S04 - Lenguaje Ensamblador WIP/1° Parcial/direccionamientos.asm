.model small
     
;Segmento de Pila
.stack ;200h ;por defaulf es 100h
                 
;Segmento de Datos                 
.data

var     DB 'z'
var1    DB ?
array   DB 1,2,3,4,5
var2    DW 0FEEDh

;Segmento de codigo
.code              


;Esto recupera la direccion de memoria .data para el DS
MOV AX,@DATA
MOV DS,AX

inicio:

    MOV AL,var
    
    ;Direccionamiento
    
    MOV BX, AX  ;16bits
    
    MOV CL, BH  ;8bits
    MOV CH, BL  ;8btis
    
    
    ;Direccionamiento inmediato
    
    MOV AX, 0BABEh      ;Hexadecimal
    MOV BX, 1500        ;Decimal
    MOV CX, 11100000b   ;Binario 
    
    ;Direccionamiento directo
    
    MOV DX, [500]
    
    MOV CL, [array]
    
    MOV CH, [array+1]
    
    
    
           
    ;Terminador de programa          
    MOV AH,4Ch
    INT 21h                
    
END