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

piano1 DB  "Presiona una tecla: ","$"
piano2  db  "    ___________________________  ","$"
piano3  db  "   |  | | | |  |  | | | | | |  | ","$"
piano4  db  "   |  | | | |  |  | | | | | |  | ","$"
piano5  db  "   |  |S| |D|  |  |G| |H| |J|  | ","$"
piano6  db  "   |  |_| |_|  |  |_| |_| |_|  | ","$"
piano7  db  "   |   |   |   |   |   |   |   | ","$"
piano8  db  "   | Z | X | C | V | B | N | M | ","$"
piano9  db  "   |___|___|___|___|___|___|___| ","$"

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
    JE  fin
    
    JMP cicloAsk    
    
fin:
           
    ;Terminador de programa          
    MOV AH,4Ch
    INT 21h
    
Tiempo  proc
    
    MOV DX,0FFFFh
    
cicloTiempo1:    
    
    DEC DX
    JNE cicloTiempo1
    
    MOV DX,0FFFFh
    
cicloTiempo2:    
    
    DEC DX
    JNE cicloTiempo2
    
    MOV DX,0FFh
    
cicloTiempo3:    
    
    DEC DX
    JNE cicloTiempo3
    
    RET
Tiempo  endp                        
    
END