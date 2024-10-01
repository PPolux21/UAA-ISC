endl MACRO
    MOV DX,OFFSET salto
    MOV AH,09
    INT 21h
ENDM

print MACRO msj
    
    MOV AH,09h
    MOV DX,OFFSET msj
    INT 21h
                                                     
ENDM

nota  MACRO frecuencia
    
    mov     al, 182         ; meaning that we're about to load
    out     43h, al         ; a new countdown value

    mov     ax, frecuencia  ; countdown value is stored in ax. It is calculated by 
                            ; dividing 1193180 by the desired frequency (with the
                            ; number being the frequency at which the main system
                            ; oscillator runs
    out     42h, al         ; Output low byte.
    mov     al, ah          ; Output high byte.
    out     42h, al               

    in      al, 61h         
                            ; to connect the speaker to timer 2
    or      al, 00000011b  
    out     61h, al         ; Send the new value
    
;    MOV     AL,3
;    OUT     61h,AL

    CALL    Tiempo
    
    MOV     AL,0
    OUT     61h,AL
    
ENDM   

.model small
     
;Segmento de Pila
.stack ;200h ;por defaulf es 100h
                 
;Segmento de Datos                 
.data

salto   DB  13,10,'$'

piano1 DB  "Presiona una tecla:  (ESC para salir)","$"
piano2  db  "     ___________________________  ","$"
piano3  db  "    |  | | | |  |  | | | | | |  | ","$"
piano4  db  "    |  | | | |  |  | | | | | |  | ","$"
piano5  db  "    |  |S| |D|  |  |G| |H| |J|  | ","$"
piano6  db  "    |  |_| |_|  |  |_| |_| |_|  | ","$"
piano7  db  "    |   |   |   |   |   |   |   | ","$"
piano8  db  "    | Z | X | C | V | B | N | M | ","$"
piano9  db  "    |___|___|___|___|___|___|___| ","$"

menu1    DB  "Selecciona una opcion","$"
opc1     DB  "Tocar piano ........ 1","$"
opc2     DB  "Canciones .......... 2","$"
opc3     DB  "Salir .............. 3","$"
opcG     DB  "Opcion: ","$"

menu2    DB  "Selecciona una Cancion","$"
opcc1    DB  "'Estrellita' ........ 1","$"
opcc2    DB  "'Cumple' ............ 2","$"
opcc3    DB  "'Lechuza' ........... 3","$"
opcc4    DB  "'Lost Woods'-Zelda... 4","$"
opcc5    DB  "Salir ............... 5","$"

frecDo   DW  4571
frecDoS  DW  4307
frecRe   DW  4072
frecReS  DW  3836
frecMi   DW  3626
frecFa   DW  3418
frecFaS  DW  3233
frecSol  DW  3051
frecSolS DW  2875
frecLa   DW  2711
frecLaS  DW  2560
frecSi   DW  2420

;Segmento de codigo
.code              


;Esto recupera la direccion de memoria .data para el DS
MOV AX,@DATA
MOV DS,AX

inicio:

    MOV AH,0
    MOV AL,3
    INT 10h
    
    print menu1
    endl
    print opc1
    endl
    print opc2
    endl
    print opc3
    endl
    print opcG

    MOV AH,01   
    INT 21h
        
    CMP AL,31h
    JNE notPiano
    CALL Piano
notPiano:
    CMP AL,32h
    JNE notMenu2
    CALL menus2
notMenu2:    
    CMP AL,33h
    JE  fin
    JMP inicio
    
fin:               
    ;Terminador de programa          
    MOV AH,4Ch
    INT 21h                    

menus2  proc    

    MOV AH,0
    MOV AL,3
    INT 10h
    
    print menu2
    endl
    print opcc1
    endl
    print opcc2
    endl
    print opcc3
    endl
    print opcc4
    endl
    print opcc5
    endl
    print opcG
    
menus2Opcion:

    MOV AH,02
    MOV BH,0  ;Pagina activa actual
    MOV DH,6 ;Linea
    MOV DL,7 ;Columna
    INT 10h
    
    MOV AH,0Ah
    MOV AL,' '
    MOV BH,0
    MOV CX,1
    INT 10h

    MOV AH,01   
    INT 21h
        
    CMP AL,31h
    JNE notCancion1
    CALL estrellitaProc
notCancion1:    
    CMP AL,32h
    JNE notCancion2
    CALL cumpleProc
    CALL cumpleProc
notCancion2:
    CMP AL,33h
    JNE notCancion3
    CALL lechuzaProc
notCancion3:
    CMP AL,34h
    JNE notCancion4
    CALL zeldaProc
notCancion4:
    CMP AL,35h
    JNE menus2Opcion
    
    RET 
    
menus2 endp

estrellitaProc proc
    nota frecDo
    CALL Tiempo
    nota frecDo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    nota frecLa
    CALL Tiempo
    nota frecLa
    CALL Tiempo
    nota frecSol
    
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    nota frecDo
    
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    nota frecRe
    
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    nota frecRe

    CALL Tiempo    
    CALL Tiempo
    CALL Tiempo
    nota frecDo
    CALL Tiempo
    nota frecDo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    nota frecLa
    CALL Tiempo
    nota frecLa
    CALL Tiempo
    nota frecSol
    
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    nota frecDo
    
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    nota frecDo
    CALL Tiempo
    nota frecDo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    nota frecLa
    CALL Tiempo
    nota frecLa
    CALL Tiempo
    nota frecSol
    
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    nota frecDo
    
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    nota frecRe
    
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    nota frecRe

    CALL Tiempo    
    CALL Tiempo
    CALL Tiempo
    nota frecDo
    CALL Tiempo
    nota frecDo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    nota frecLa
    CALL Tiempo
    nota frecLa
    CALL Tiempo
    nota frecSol
    
    CALL Tiempo
    CALL Tiempo   
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    nota frecRe
    CALL Tiempo 
    nota frecMi
    CALL Tiempo
    nota frecDo
    
    CALL Tiempo
    ;JE  menus2Proc 
    RET
estrellitaProc endp

cumpleProc proc
    nota frecRe
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    nota frecRe    
    CALL Tiempo
    CALL Tiempo
    nota frecSol    
    CALL Tiempo
    CALL Tiempo
    nota frecFaS
    
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    nota frecRe    
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    nota frecMi    
    CALL Tiempo
    nota frecRe    
    CALL Tiempo
    CALL Tiempo
    nota frecLa    
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    nota frecRe  
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    nota frecRe    
    CALL Tiempo  
    nota frecSi    
    CALL Tiempo
    CALL Tiempo
    nota frecSol    
    CALL Tiempo
    CALL Tiempo
    nota frecFaS    
    CALL Tiempo
    CALL Tiempo
    nota frecMi
    
    CALL Tiempo
    CALL Tiempo
    nota frecDo
    CALL Tiempo
    nota frecDo
    CALL Tiempo
    nota frecDo
    CALL Tiempo
    nota frecSi    
    CALL Tiempo
    CALL Tiempo
    nota frecSol    
    CALL Tiempo
    CALL Tiempo
    nota frecLa    
    CALL Tiempo
    CALL Tiempo
    nota frecSol

    CALL Tiempo 
    CALL Tiempo    
    nota frecRe
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    nota frecRe    
    CALL Tiempo
    CALL Tiempo
    nota frecSol    
    CALL Tiempo
    CALL Tiempo
    nota frecFaS
    
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    nota frecRe    
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    nota frecMi    
    CALL Tiempo
    nota frecRe    
    CALL Tiempo
    CALL Tiempo
    nota frecLa    
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    nota frecRe  
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    nota frecRe    
    CALL Tiempo  
    nota frecSi    
    CALL Tiempo
    CALL Tiempo
    nota frecSol    
    CALL Tiempo
    CALL Tiempo
    nota frecFaS    
    CALL Tiempo
    CALL Tiempo
    nota frecMi
    
    CALL Tiempo
    CALL Tiempo
    nota frecDo
    CALL Tiempo
    nota frecDo
    CALL Tiempo
    nota frecSi    
    CALL Tiempo
    CALL Tiempo
    nota frecSol    
    CALL Tiempo
    CALL Tiempo
    nota frecLa    
    CALL Tiempo
    CALL Tiempo
    nota frecSol
        
    CALL Tiempo 
    CALL Tiempo
    ;JE  menus2Proc 
    RET
cumpleProc endp

lechuzaProc proc
    nota frecDo
    CALL Tiempo
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    CALL Tiempo
    nota frecDo
    CALL Tiempo
    CALL Tiempo
    nota frecDo
    CALL Tiempo
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    CALL Tiempo
    nota frecDo
    CALL Tiempo
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    CALL Tiempo
    nota frecLa
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    CALL Tiempo 
    nota frecDo
    CALL Tiempo
    CALL Tiempo  
    nota frecSol 
    CALL Tiempo
    CALL Tiempo
    nota frecLa
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    CALL Tiempo 
    nota frecDo
    CALL Tiempo
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    CALL Tiempo
    nota frecDo
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    CALL Tiempo
    nota frecDo
    
    CALL Tiempo    
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    nota frecDo
    CALL Tiempo
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    CALL Tiempo
    nota frecDo
    CALL Tiempo
    CALL Tiempo
    nota frecDo
    CALL Tiempo
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    CALL Tiempo
    nota frecDo
    CALL Tiempo
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    CALL Tiempo
    nota frecLa
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    CALL Tiempo 
    nota frecDo
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    CALL Tiempo
    nota frecLa
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    CALL Tiempo 
    nota frecDo
    CALL Tiempo
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    CALL Tiempo
    nota frecDo
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    CALL Tiempo
    nota frecDo
    CALL Tiempo
    ;JE  menus2Proc 
    RET
lechuzaProc endp

zeldaProc   proc
    
    nota frecFa
    CALL Tiempo
    nota frecLa
    CALL Tiempo
    nota frecSi
    CALL Tiempo
    
    CALL Tiempo
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    nota frecLa
    CALL Tiempo
    nota frecSi
    
    CALL Tiempo
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    nota frecLa
    CALL Tiempo
    nota frecSi
    CALL Tiempo
    nota 1809    ;Mi5
    CALL Tiempo
    nota 2031    ;Re5
    CALL Tiempo
    
    CALL Tiempo
    CALL Tiempo
    nota frecSi
    CALL Tiempo
    nota 2280   ;Do5
    CALL Tiempo
    nota 1809   ;Mi5
    CALL Tiempo
    nota frecSi
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    
    CALL Tiempo
    CALL Tiempo
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    
    CALL Tiempo
    CALL Tiempo    
    nota frecFa
    CALL Tiempo
    nota frecLa
    CALL Tiempo
    nota frecSi
    CALL Tiempo
    
    CALL Tiempo
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    nota frecLa
    CALL Tiempo
    nota frecSi
    
    CALL Tiempo
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    nota frecLa
    CALL Tiempo
    nota frecSi
    CALL Tiempo
    nota 1809    ;Mi5
    CALL Tiempo
    nota 2031    ;Re5
    CALL Tiempo
    
    CALL Tiempo
    CALL Tiempo
    nota frecSi
    CALL Tiempo
    nota 2280   ;Do5
    CALL Tiempo
    nota 1809   ;Mi5
    CALL Tiempo
    nota frecSi
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    
    CALL Tiempo
    CALL Tiempo
    nota frecSi
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    
    CALL Tiempo
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    nota frecLa
    CALL Tiempo
    nota frecSi
    CALL Tiempo
    CALL Tiempo
    nota 2280   ;Do5
    CALL Tiempo
    nota frecSi
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    
    CALL Tiempo
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    nota frecLa
    CALL Tiempo
    CALL Tiempo
    nota frecSi
    CALL Tiempo
    nota 2280   ;Do5
    CALL Tiempo
    nota 2031   ;Re5
    CALL Tiempo
    CALL Tiempo
    nota 1809   ;Mi5
    CALL Tiempo
    nota 1708   ;Fa5
    CALL Tiempo
    nota 1521   ;Sol5
    CALL Tiempo
    
    CALL Tiempo
    CALL Tiempo
    nota frecRe
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    nota frecFa
    CALL Tiempo
    CALL Tiempo
    nota frecSol
    CALL Tiempo
    nota frecLa
    CALL Tiempo
    nota frecSi
    CALL Tiempo
    CALL Tiempo
    nota 2280   ;Do5
    CALL Tiempo
    nota frecSi
    CALL Tiempo
    nota frecMi
    CALL Tiempo
    
    CALL Tiempo
    CALL Tiempo
    nota frecFa
    CALL TiempoShort
    nota frecMi
    CALL TiempoShort
    nota frecLa
    CALL TiempoShort
    nota frecSol
    CALL Tiempo
    nota frecSi
    CALL TiempoShort
    nota frecLa
    CALL TiempoShort
    nota 2280   ;Do5
    CALL TiempoShort
    nota frecSi
    CALL Tiempo
    nota 2031   ;Re5
    CALL TiempoShort
    nota 2280
    CALL TiempoShort
    nota 1809   ;Mi5
    CALL TiempoShort
    nota 2031   ;Re5
    CALL Tiempo
    nota 1708   ;Fa5
    CALL TiempoShort
    nota 1809   ;Mi5
    CALL Tiempo
    nota frecSi
    nota 2280   ;Do5
    CALL TiempoShort
    nota frecLa
    nota frecSi
    
    CALL Tiempo
    CALL Tiempo
    
    
    RET
zeldaProc endp    
    
Piano proc

    MOV AH,0
    MOV AL,3
    INT 10h    

    print piano1
    endl
    print piano2
    endl
    print piano3
    endl
    print piano4
    endl
    print piano5
    endl
    print piano6
    endl
    print piano7
    endl
    print piano8
    endl
    print piano9
    endl
    
    
cicloAsk:

    ;nota 0

    MOV AH,08
    INT 21h
    
    CMP AL,7Ah      ;z
    JNE notDo
    nota    frecDo
notDo:    
    
    CMP AL,73h      ;s
    JNE notDoS
    nota    frecDoS
notDoS:    
    
    CMP AL,78h      ;x
    JNE notRe
    nota    frecRe
notRe:    
    
    CMP AL,64h      ;d
    JNE notReS
    nota    frecReS
notReS:    
               
    CMP AL,63h      ;c
    JNE notMi
    nota    frecMi
notMi:        
    
    CMP AL,76h      ;v
    JNE notFa
    nota    frecFa
notFa:
               
    CMP AL,67h      ;g
    JNE notFaS
    nota    frecFaS
notFaS:    
    
    CMP AL,62h      ;b
    JNE notSol
    nota    frecSol
notSol:    
               
    CMP AL,68h      ;h
    JNE notSolS
    nota    frecSolS
notSolS:    
    
    CMP AL,6Eh      ;n
    JNE notLa    
    nota    frecLa
notLa:    
    
    CMP AL,6Ah      ;j
    JNE notLaS   
    nota    frecLaS
notLaS:    
    
    CMP AL,6Dh      ;m
    JNE notSi    
    nota    frecSi
notSi:    
    
    CMP AL,1Bh    
    JE  finPiano
    
    JMP cicloAsk

finPiano:

    ret    
    
Piano endP    
    
Tiempo  proc
    
    MOV DX,0FFFFh
    
cicloTiempo1:    
    
    DEC DX
    JNE cicloTiempo1
    
    MOV DX,0FFFFh
    
cicloTiempo2:    
    
    DEC DX
    JNE cicloTiempo2
    
    MOV DX,0FFFFh
    
cicloTiempo3:    
    
    DEC DX
    JNE cicloTiempo3
    
    MOV DX,0FFFFh
    
cicloTiempo4:    
    
    DEC DX
    JNE cicloTiempo4
    
    RET
Tiempo  endp                        

TiempoShort proc
    
    MOV DX,0FFFFh
    
cicloTiempoS1:    
    
    DEC DX
    JNE cicloTiempoS1
    
    MOV DX,0FFFFh
    
cicloTiempoS2:    
    
    DEC DX
    JNE cicloTiempoS2
    
    RET
TiempoShort endp

END