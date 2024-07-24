print MACRO msj
    
    MOV AH,09h
    MOV DX,OFFSET msj
    INT 21h
    
ENDM

.model small
     
;Segmento de Pila
.stack ;200h ;por defaulf es 100h
                 
;Segmento de Datos                 
.data

msj1    DB "Hoy es ","$"
msj2    DB " de ","$"

auxdi   DB  ?
auxndi  DB  ?
auxmes  DB  ?
auxdiv  DW  10

lunes       DB  "lunes ","$"
martes      DB  "martes ","$"
miercoles   DB  "miercoles ","$"
jueves      DB  "jueves ","$"
viernes     DB  "veirnes ","$"
sabado      DB  "sabado ","$"
domingo     DB  "domingo ","$"

enero       DB  "enero","$"
febrero     DB  "febrero","$"
marzo       DB  "marzo","$"
abril       DB  "abril","$"
mayo        DB  "mayo","$"
junio       DB  "junio","$"
julio       DB  "julio","$"
agosto      DB  "agosto","$"
septiembre  DB  "septiembre","$"
octubre     DB  "octubre","$"
noviembre   DB  "noviembre","$"
diciembre   DB  "diciembre","$"


;Segmento de codigo
.code              


;Esto recupera la direccion de memoria .data para el DS
MOV AX,@DATA
MOV DS,AX

inicio:

    MOV AH,2Ah
    INT 21h
    
    MOV auxdi,AL
    MOV auxndi,DL
    MOV auxmes,DH
    
    print msj1

    ;Switch para imprimir el nombre del dia
    
    ;Lunes
    CMP auxdi,01
    JNE mar
    print lunes
    JMP findia
    
mar:
    CMP auxdi,02
    JNE mie
    print martes
    JMP findia

mie:
    CMP auxdi,03
    JNE jue
    print miercoles
    JMP findia
    
jue:
    CMP auxdi,04
    JNE vie
    print jueves
    JMP findia
    
vie:
    CMP auxdi,05
    JNE sab
    print viernes
    JMP findia
    
sab:
    CMP auxdi,06
    JNE dom
    print sabado
    JMP findia
    
dom:                    
    print domingo
    
findia:                      

    ;Impresion del numero de dia
    XOR AH,AH
    MOV AL,auxndi
    AAA
    ADD AH,30h        
    ADD AL,30h
    MOV DL,AH
    MOV BL,AL
    MOV AH,02h  ;Impresion de decenas
    INT 21h
    MOV DL,BL   ;Impresion de unidades
    INT 21h
    
    print msj2
    
    ;comienza mes
    
    CMP auxmes,01
    JNE feb
    print enero
    JMP finmes
    
feb:
    CMP auxmes,02
    JNE maz
    print febrero
    JMP finmes    

maz:
    CMP auxmes,03
    JNE abr
    print marzo
    JMP finmes

abr:
    CMP auxmes,04
    JNE may 
    print abril
    JMP finmes 

may:
    CMP auxmes,05
    JNE jun
    print mayo
    JMP finmes    
    
jun:
    CMP auxmes,06
    JNE jul
    print junio
    JMP finmes 
    
jul:
    CMP auxmes,07
    JNE ago
    print julio
    JMP finmes 
    
ago:
    CMP auxmes,08
    JNE sep
    print agosto
    JMP finmes       
    
sep:
    CMP auxmes,09
    JNE oct
    print septiembre
    JMP finmes
    
oct:
    CMP auxmes,0Ah
    JNE nov
    print octubre
    JMP finmes 
    
nov:
    CMP auxmes,0Bh
    JNE dic
    print noviembre
    JMP finmes       
    
dic:
    print diciembre
    
finmes:    

    print msj2
    
    MOV AX,CX
    XOR DX,DX
    DIV auxdiv
    ADD DL,30h
    PUSH DX
    XOR DX,DX
    DIV auxdiv
    ADD DL,30h
    PUSH DX 
    XOR DX,DX
    DIV auxdiv
    MOV BL,DL
    ;impresion
    MOV DL,AL
    ADD DL,30h
    
    MOV AH,02
    INT 21h
    
    MOV DL,BL
    ADD DL,30h
    INT 21h
    
    POP DX 
    INT 21h

    POP DX 
    INT 21h
               
    ;Terminador de programa          
    MOV AH,4Ch
    INT 21h                
    
END