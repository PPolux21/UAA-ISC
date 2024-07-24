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
    
printCh MACRO char
    
    MOV AH,02h
    MOV DL,char
    INT 21h
    
ENDM    
    
.model small
     
;Segmento de Pila
.stack ;200h ;por defaulf es 100h
                 
;Segmento de Datos                 
.data

salto   DB  13,10,'$'                   
msj     DB  "Introduce el numero: ",'$'
buff    DB  12,?,12 DUP(?)

msjSign DB  "Signo: ",'$'
msjInt  DB  "Entero: ",'$'
msjFrac DB  "Fraccion: ",'$'

signo   DB  ?
entero  DW  ?
frac    DW  ?

vecInt  DB  6 DUP('0')
vecFrac DB  4 DUP('0')

auxOp   DW  0Ah

;Segmento de codigo
.code              


;Esto recupera la direccion de memoria .data para el DS
MOV AX,@DATA
MOV DS,AX

inicio:

    print msj
    ;Entrada del numero
    MOV AH,0Ah
    MOV DX,OFFSET buff
    INT 21h
    
    MOV DI,2
    
    CMP buff[DI],2Dh
    JE  negativo
                
    CMP buff[DI],2Bh
    JNE sinSigno
                
;positivo
    INC DI
    
sinSigno:    
    XOR AX,AX
    MOV signo,0
    ADD signo,30h
    JMP finSigno

negativo:
    INC DI
    XOR AX,AX
    MOV signo,1
    ADD signo,30h

finSigno:
;Buffer al valor del numero entero
    
    XOR BX,BX       
    MUL auxOp
    
    SUB buff[DI],30h
    
    MOV BL,buff[DI]
    
    ADD AX,BX
    
    INC DI
    
    CMP buff[DI],0Dh
    JE  sinFraccion
    
    CMP buff[DI],2Eh
    JNE finSigno
    
    MOV entero,AX
    INC DI
    XOR AX,AX
    XOR SI,SI

buffFrac:        
;Buffer a valor de la fraccion

    XOR BX,BX       
    MUL auxOp
    
    SUB buff[DI],30h
    
    MOV BL,buff[DI]
    
    ADD AX,BX
    
    INC DI
    INC SI
    
    CMP buff[DI],0Dh
    JNE buffFrac

confirmCeros:
    
    CMP SI,3
    JAE asignFrac
    
    MUL auxOp
    INC SI
    JMP confirmCeros
    
asignFrac:    
    MOV frac,AX
    
;Valor del numero entero a vector (para salida)
intVec:
    MOV AX,entero
    XOR DX,DX
    MOV DI,5
    
cicloInt:    
    DIV auxOp 
    ADD DL,30h
    MOV vecInt[DI], DL
    XOR DX,DX
    DEC DI   
    JNE cicloInt
    
;Valor del numero fraccional a vector (para salida)        
    MOV AX,frac
    XOR DX,DX
    MOV DI,3
    
cicloFrac:   
    DIV auxOp 
    ADD DL,30h
    MOV vecFrac[DI], DL
    XOR DX,DX
    DEC DI   
    JNE cicloFrac
    
;Mostrar informacion en consola
   
printSign:    
    endl
    endl
    print msjSign
    printCh signo 
    
printInt:
    endl
    print msjInt
    MOV DI,1

cicloPI:
    
    printCh vecInt[DI]
    
    INC DI
    
    CMP DI,5
    JBE cicloPI
    
    
printFrac:    
    endl
    print msjFrac
    MOV DI,1
    
cicloPF:    
    printCh vecFrac[DI]
    
    INC DI
    
    CMP DI,3
    JBE cicloPF
    
    JMP fin
    
sinFraccion:
    MOV entero,AX
    MOV frac,0
    JMP intVec

fin:           
    ;Terminador de programa          
    MOV AH,4Ch
    INT 21h                
    
END