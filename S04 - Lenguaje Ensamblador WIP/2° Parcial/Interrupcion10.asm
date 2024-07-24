.model small

;segmento de pila
.stack ;por default el stack es de 100h 256 en decimal

;segmento de datos
.data                       
     
;segmento de codigo
.code


;Estas lineas recuperan la direccion de memoria .data
;para el DS
MOV AX,@DATA
MOV DS,AX

inicio:

    ;servicios de video de la INT 10h
    
    ;Servicio 0, Establecer modo de video

    MOV AH,0
    MOV AL,0 ;RES: 40x25, 16 colores, texto
    INT 10h
    
    MOV DL,'A'
    MOV AH,02
    INT 21h
    
    MOV AH,0
    MOV AL,1 ;RES: 40x25, 16 colores, texto
    INT 10h
    
    MOV DL,'A'
    MOV AH,02
    INT 21h
    
    MOV AH,0
    MOV AL,2 ;RES: 80x25, 16 colores, texto
    INT 10h
    
    MOV DL,'A'
    MOV AH,02
    INT 21h
    
    MOV AH,0
    MOV AL,3 ;RES: 80x25, 16 colores, texto
    INT 10h
    
    MOV DL,'A'
    MOV AH,02
    INT 21h
    
    MOV AH,0
    MOV AL,13h ;RES: 20x200, 256 colores, grafico
    INT 10h
    
    MOV DL,'A'
    MOV AH,02
    INT 21h
    
    MOV AH,0
    MOV AL,0 ;RES: 40x25, 16 colores, texto
    INT 10h
    
    ;servicio 01 de la INT 10h
    ;Cambio de tamanio del cursor
    MOV AH,01
    MOV CH,0
    MOV CL,7
    INT 10h
    
    MOV AH,01
    INT 21h
           
    ;Servicio 05 de la INT 10h
    ;Cambio de pagina de video
    
    MOV AH,05
    MOV AL,01
    INT 10h
    
    MOV AH,01
    INT 21h
    
    MOV AH,05
    MOV AL,0
    INT 10h
    
    MOV AH,01
    INT 21h
    
    ;Servicio 02 de la INT 21h
    ;Posicionar cursor
    
    MOV AH,02
    MOV BH,0  ;Pagina activa actual
    MOV DH,10 ;Linea
    MOV DL,10 ;Columna
    INT 10h
    
    MOV AH,01
    INT 21h
    
    ;Servicio 03 la INT 10h
    ;Buscar posicion del cursor
    MOV AH,03
    MOV BH,0
    INT 10h
    
    ;Servicio 06 de la INT 10h
    ;Scroll up
    
    MOV AH,06
    MOV AL,03    ;Numero de lineas a desplazar
    MOV BH,24h  ;Atributo (color)(4b mas significativos para color de pantalla y 4b menos significativos para color texto)
    MOV CH,0   ;Linea donde comienza
    MOV CL,0   ;Columna donde comienza
    MOV DH,10    ;Linea donde termine
    MOV DL,39    ;Columna donde termina
    INT 10h
    
    MOV AH,01
    INT 21h
    
    ;Servicio 07 de la INT 10h
    ;Scroll down
    
    MOV AH,07
    MOV AL,0    ;Numero de lineas a desplazar
    MOV BH,43h  ;Atributo (color)(4b mas significativos para color de pantalla y 4b menos significativos para color texto)
    MOV CH,0   ;Linea donde comienza
    MOV CL,0   ;Columna donde comienza
    MOV DH,24    ;Linea donde termine
    MOV DL,39    ;Columna donde termina
    INT 10h
    
    MOV AH,01
    INT 21h
    
    ;Servicio 08 de la INT 10h
    ;Leer caracter y atributo
    MOV AH,08
    MOV BH,0
    INT 10h
    
    MOV AH,03
    MOV BH,0
    INT 10h
    
    MOV AH,02
    MOV BH,0  ;Pagina activa actual
    MOV DH,10 ;Linea
    MOV DL,0Ch ;Columna
    INT 10h
    
    MOV AH,08
    MOV BH,0
    INT 10h
    
    ;Servicio 09 de la INT 10h
    ;Escribir caracter y atributo
    MOV AH,09
    MOV AL,'+'
    MOV BH,0
    MOV BL,89h
    MOV CX,10h
    INT 10h
    
    ;Servicio 0Ah de la INT 10h
    ;Escribir caracter y atributo
    MOV AH,0Ah
    MOV AL,'-'
    MOV BH,0
    MOV CX,10h
    INT 10h 
    
    ;Servicio 0Ch de la INT 10h
    ;Escribir un pixel grafico
    MOV AH,0
    MOV AL,13h ;RES: 20x200, 256 colores, grafico
    INT 10h
    
    MOV AH,0Ch
    MOV AL,2
    MOV BH,0
    MOV CX,10
    MOV DX,10
    INT 10h
    
    
    ;Terminador de programa
    MOV AH,4Ch
    INT 21h
    
END