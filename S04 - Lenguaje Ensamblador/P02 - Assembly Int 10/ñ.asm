.model small
     
;Segmento de Pila
.stack ;200h ;por defaulf es 100h
                 
;Segmento de Datos                 
.data


;Segmento de codigo
.code              


;Esto recupera la direccion de memoria .data para el DS
MOV AX,@DATA
MOV DS,AX

inicio:

    CALL lecturaTecla
    MOV AH,0Eh
    INT 10h
    JMP inicio
    
lecturaTecla:
    
    XOR AX,AX
    INT 16h
    CMP AH,27h
    JE  cambiarTecla
    
    RET
    
cambiarTecla:
        
    MOV AL,0A4h
    RET
                
           
    ;Terminador de programa          
    MOV AH,4Ch
    INT 21h                
    
END