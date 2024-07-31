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

    ;Logicos
    
    ;AND
    
    ;XOR AL,AL
    MOV AL,0FFh
    AND AL,07Eh
    
    NOT AL
      
    MOV AL,01Dh
    
        
    ;Desplazamiento y Rotaciones
    
    MOV AL,1Fh 
    SHL AL,4
    SHR AL,4
    
    MOV AH,0F1h
    SAR AH,2
    
    SAL AH,6
    
    ROR AL,2
    ROL AL,2
    
    RCR AL,2
           
    ;Terminador de programa          
    MOV AH,4Ch
    INT 21h                
    
END