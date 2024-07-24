.model small
     
;Segmento de Pila
.stack ;200h ;por defaulf es 100h
                 
;Segmento de Datos                 
.data

i       DB 0
control DB 1

;Segmento de codigo
.code              


;Esto recupera la direccion de memoria .data para el DS
MOV AX,@DATA
MOV DS,AX

inicio:
              
    
for:    
    
    CMP i,0Ah
    JAE while
    ;ADD i, 1
    INC i
    ;Instrucciones del ciclo For
    
    
    JMP for

;salirfor:                  

while:
    ;Intrucciones de un while
    DEC i
    JA while
    
while1:
    ;Intrucciones de un while
    CMP control,0
    MOV control,0
    JNE while1              
           
    ;Terminador de programa          
    MOV AH,4Ch
    INT 21h                
    
END