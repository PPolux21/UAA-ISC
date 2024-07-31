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
msjErr  DB  "Error en la entrada de los datos . . . ",'$'
msj     DB  "Introduce el numero: ",'$'
auxBuff DW  0Ah ;auxiliar para pasar el buffer
auxBin  DW  2   ;auxiliar para pasar a binario
auxHex  DW  4   ;auxlilar para pasar a hexadecimal
option  DB  "Elija el formato:",'$'
option1 DB  "  1. Binario",'$'
option2 DB  "  2. Hexadecimal",'$'
option3 DB  "  3. Salir",'$'
selOpt  DB  "Opcion: ","$"
msjBin  DB  "Binario IEEE: ",'$'
msjHex  DB  "Hexadecimal IEEE: ",'$'

signo   DB  ?
entero  DW  ?
frac    DW  ?

infinitoBin DB  0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
binInt  DB  16 DUP(0)
binFrac DB  40 DUP(0)

power   DB  8  DUP(?)
point   DB  0   ;posicion del punto
vecHex  DB  4  DUP(?)
valHex  DB  ?
cont    DB  0

binIEEE DB  32 DUP(?)
hexIEEE DB  8  DUP(?)

buff    DB  12,?,12 DUP(?)

;Segmento de codigo
.code              


;Esto recupera la direccion de memoria .data para el DS
MOV AX,@DATA
MOV DS,AX

    JMP inicio
    
errorBuff:
    
    MOV AH,06
    MOV AL,00    ;Numero de lineas a desplazar
    MOV BH,0Ch  ;Atributo (color)(4b mas significativos para color de pantalla y 4b menos significativos para color texto)
    MOV CH,0   ;Linea donde comienza
    MOV CL,0   ;Columna donde comienza
    MOV DH,10    ;Linea donde termine
    MOV DL,50    ;Columna donde termina
    INT 10h
    
    MOV AH,0
    MOV AL,2
    INT 10h 
    
    print msjErr

    MOV AH,4Ch
    INT 21h

inicio:

    print msj
    ;Entrada del numero
    MOV AH,0Ah
    MOV DX,OFFSET buff
    INT 21h
    
    MOV DI,2
    
    ;validaciones
    
    CMP buff[DI],2Dh    ;igual a menos
    JE  negativo
    
    CMP buff[DI],2Bh    ;igual a mas
    JE  positivo
    
    CMP buff[DI],30h    ;menor que 30h
    JB  errorBuff
    
    CMP buff[DI],39h    ;mayor que 39h
    JA  errorBuff
                    
    JMP  sinSigno       ;si esta en el rango de 30h y 39h
                
positivo:
    INC DI
    
sinSigno:    
    XOR AX,AX
    MOV signo,0
    JMP finSigno

negativo:
    INC DI
    XOR AX,AX
    MOV signo,1

finSigno:
;Buffer al valor del numero entero
    
    XOR BX,BX       
    MUL auxBuff
    ;si se activa CF sale del programa
    JC  esInfinito   ;saltar a infinito
    
    ;validaciones
    CMP buff[DI],30h    ;menor que 30h
    JB  errorBuff
    
    CMP buff[DI],39h    ;mayor que 39h
    JA  errorBuff
    
    SUB buff[DI],30h
    
    MOV BL,buff[DI]
    
    ADD AX,BX
    ;si se activa CF sale del programa
    JC  esInfinito   ;saltar a infinito
    
    INC DI
    
    CMP buff[DI],0Dh
    JE  sinFraccion 
    
    CMP buff[DI],2Eh
    JNE finSigno
    
    MOV entero,AX
    INC DI
    XOR AX,AX
    XOR SI,SI
    JMP buffFrac

sinFraccion:
    MOV entero,AX
    XOR AX,AX
    JMP asignFrac

buffFrac:        
;Buffer a valor de la fraccion

    XOR BX,BX       
    MUL auxBuff
    
    ;validaciones
    CMP buff[DI],30h    ;menor que 30h
    JB  errorBuff
    
    CMP buff[DI],39h    ;mayor que 39h
    JA  errorBuff
    
    SUB buff[DI],30h
    
    MOV BL,buff[DI]
    
    ADD AX,BX
    
    INC DI
    INC SI
    
    CMP SI,3
    JAE asignFrac
    
    CMP buff[DI],0Dh
    JNE buffFrac

confirmCeros:
    
    CMP SI,3
    JAE asignFrac
    
    MUL auxBuff
    INC SI
    JMP confirmCeros
    
asignFrac:    
    MOV frac,AX

;comprueba que todo sea cero    
    CMP entero,0
    JNE toBin
    CMP frac,0
    JNE toBin
    
    XOR DI,DI
    JMP vecCeros
    
;Valor de entero a binario
toBin:
    XOR DX,DX 
    MOV AX,entero
    MOV DI,15
    
cicloBI:    
    
    XOR DX,DX 
    DIV auxBin
    MOV binInt[DI], DL   
    DEC DI
    CMP AX,0
    JNE cicloBI

;Valor de fraccion a binario
    XOR DX,DX ;limpia de DX
    MOV AX,frac
    XOR DI,DI
    
cicloBF:;multiplicar el numerador hasta que sea mayor que el denominador    
    
    ;para cuando hay un 0 como resultado en AX
    CMP AX,0
    JE  finCicloBF
    
    MUL auxBin
    
    CMP AX,1000
    JAE unoBinario
    
    MOV binFrac[DI], 0
    INC DI
    
    CMP DI,40
    JNE cicloBF
    JMP finCicloBF
         
unoBinario:

    SUB AX,1000

    MOV binFrac[DI], 1
    INC DI
    
    CMP DI,40
    JNE cicloBF              
         
finCicloBF:

    XOR DI,DI
    XOR SI,SI
    CMP entero, 0
    JE  sinEntero
    
;Parte entera > 0 
;(se suma el recorrido del punto 127 para binario)
    ;recorre el vector binario hasta que encuentre el 1 mas a la izq
    ;cuenta los espacios entre ese 1 y el tope de la derecha
recorreInt:

    CMP binInt[DI],1
    JE  finRecorreInt
    
    INC DI
    JMP recorreInt

finRecorreInt:        

    MOV AX,DI
    MOV BL,10h
    SUB BL,AL
    MOV point,BL
    DEC point
    
    JMP binaryPowerPos

;Parte entera = 0 
;(se resta el recorrido del punto a 127 para binario)
sinEntero:
    ;recorre el vector binario hasta que encuentre el uno mas a la izq
    ;cuenta los espacios entre ese 1 y el tope de la izquierda
    
    CMP binFrac[DI],1
    JE  finRecorreFrac
    CMP DI,39
    JAE finRecorreFracZ
    
    INC DI
    JMP sinEntero
    
finRecorreFracZ:
    MOV DI,0

finRecorreFrac:        

    MOV AX,DI
    MOV point,AL
    INC point
    
    JMP binaryPowerNeg
    
;Pasa a Binario el recorrido del punto
binaryPowerPos:
    XOR DX,DX 
    MOV AL,127
    ADD AL,point
    MOV DI,7
    JMP cicloBP
    
binaryPowerNeg:    
    XOR DX,DX 
    MOV AL,127
    SUB AL,point
    MOV DI,7
    
cicloBP:    
    
    XOR DX,DX 
    DIV auxBin
    MOV power[DI], DL   
    DEC DI
    CMP AX,0
    JNE cicloBP        
    
;Juntar valores al binario final

    XOR DI,DI
    
    MOV AL,signo 
    MOV binIEEE[DI],AL
    
    XOR SI,SI 
    INC DI

movPower:    
    CMP DI,8
    JA  finMovPower

    MOV AL,power[SI]    
    MOV binIEEE[DI],AL
    
    INC DI
    INC SI
    JMP movPower

finMovPower:
    
    XOR AX,AX
    MOV AL,point
    
    CMP entero,0
    JE  movFracSinInt
    
;movInt:
    MOV AL,point
    MOV BX,10h
    SUB BL,AL
    MOV SI,BX
    
movInt:    
    CMP SI,15
    JA  finMovInt

    MOV AL,binInt[SI]    
    MOV binIEEE[DI],AL
    
    INC DI
    INC SI
    JMP movInt    
finMovInt:

    XOR SI,SI
    MOV AL,point
    MOV BX,10h
    SUB BL,AL
    
movFrac:
    CMP SI,39
    JA  redondeo
    CMP DI,31
    JA  redondeo

    MOV AL,binFrac[SI]    
    MOV binIEEE[DI],AL
    
    INC DI
    INC SI
    JMP movFrac
     
movFracSinInt:
    
    XOR AX,AX
    MOV AL,point
    MOV SI,AX
    
cicloMovFracSI:
    CMP SI,39
    JA  redondeo
    CMP DI,31
    JA  redondeo

    MOV AL,binFrac[SI]    
    MOV binIEEE[DI],AL
    
    INC DI
    INC SI
    JMP cicloMovFracSI

redondeo:
    MOV DI,31
    CMP SI,39
    JA  convierteHex
    CMP binFrac[SI],1
    JNE convierteHex
    MOV binIEEE[DI],1
    JMP convierteHex
    
esInfinito:
    XOR DI,DI
    MOV AL,signo
    MOV binIEEE[DI],AL
    INC DI
    
cicloInfinitoBin:
    MOV  AL,infinitoBin[DI]
    MOV  binIEEE[DI],AL
    INC  DI
    CMP  DI,31
    JNAE cicloInfinitoBin
    JMP  convierteHex
    
vecCeros:

    MOV  binIEEE[DI],0
    INC  DI
    CMP  DI,31
    JNAE vecCeros
    JMP  convierteHex
    
;Convertidor Hexadecimal
convierteHex: 
    XOR DI,DI

cicloConvierteHex:

    CMP DI,31
    JAE opcionMuestra
    
    XOR SI,SI

    MOV AL,binIEEE[DI]
    MOV vecHex[SI],AL
    INC DI
    INC SI
    MOV AL,binIEEE[DI]
    MOV vecHex[SI],AL
    INC DI
    INC SI
    MOV AL,binIEEE[DI]
    MOV vecHex[SI],AL
    INC DI
    INC SI
    MOV AL,binIEEE[DI]
    MOV vecHex[SI],AL
    INC DI

;binToHex:
    XOR SI,SI
    
;bit4
    CMP vecHex[SI],1
    JNE bit3
    ADD valHex,8
    
bit3:
    INC SI
    CMP vecHex[SI],1
    JNE bit2
    ADD valHex,4
    
bit2:
    INC SI    
    CMP vecHex[SI],1
    JNE bit1
    ADD valHex,2
    
bit1:    
    INC SI
    CMP vecHex[SI],1
    JNE finBit1
    ADD valHex,1
    
finBit1:    
    
    XOR AX,AX
    MOV AL,cont
    MOV SI,AX
    INC cont
    MOV AL,valHex
    MOV hexIEEE[SI],AL
    MOV valHex,0
   
    JMP cicloConvierteHex    
    
;pausa para despues de mostrar IEEE    
pausa:
    MOV AH,08h
    INT 21h

;Preguntar en que formato mostrarlo
opcionMuestra:
    MOV AH,06
    MOV AL,00    ;Numero de lineas a desplazar
    MOV BH,07h  ;Atributo (color)(4b mas significativos para color de pantalla y 4b menos significativos para color texto)
    MOV CH,0   ;Linea donde comienza
    MOV CL,0   ;Columna donde comienza
    MOV DH,10    ;Linea donde termine
    MOV DL,50    ;Columna donde termina
    INT 10h

    MOV AH,0
    MOV AL,2
    INT 10h 
    print option
    endl 
    print option1
    endl
    print option2
    endl
    print option3
    endl
    print selOpt
    
    MOV AH,01
    INT 21h
    
    MOV BL,AL
    
    MOV AH,0
    MOV AL,2
    INT 10h
    
    MOV AL,BL
    
    XOR DI,DI
    
    CMP AL,31h
    JE  muestraBin
    
    CMP AL,32h
    JE  mostrarHex
    
    CMP AL,33h
    JE  fin
    
    JMP opcionMuestra
;Muestra el binario    
muestraBin:    

    MOV AH,06
    MOV AL,00    ;Numero de lineas a desplazar
    MOV BH,02h  ;Atributo (color)(4b mas significativos para color de pantalla y 4b menos significativos para color texto)
    MOV CH,0   ;Linea donde comienza
    MOV CL,0   ;Columna donde comienza
    MOV DH,10    ;Linea donde termine
    MOV DL,50    ;Columna donde termina
    INT 10h

cicloMuestraBin:
                
    CMP DI,31
    JA  pausa
    
    CMP DI,1
    JE  prEspacio
    CMP DI,9
    JE  prEspacio
    JMP sinSalto
    
prEspacio:    
    printCh " "
    
sinSalto:
    MOV BL,binIEEE[DI]    
    ADD BL,30h
    
    printCh BL
    INC DI
    JMP cicloMuestraBin
            
;Muestra el hexadedimal
mostrarHex:
    
    MOV AH,06
    MOV AL,00    ;Numero de lineas a desplazar
    MOV BH,02h  ;Atributo (color)(4b mas significativos para color de pantalla y 4b menos significativos para color texto)
    MOV CH,0   ;Linea donde comienza
    MOV CL,0   ;Columna donde comienza
    MOV DH,10    ;Linea donde termine
    MOV DL,50    ;Columna donde termina
    INT 10h

cicloMuestraHex:

    CMP DI,7
    JA  pausa
    
    MOV BL,hexIEEE[DI]
    
    CMP hexIEEE[DI],0Ah
    JAE esLetra
    ADD BL,30h
    JMP imprime
    
esLetra:
    ADD BL,37h
    
imprime:    
    printCh BL
    INC DI
    JMP cicloMuestraHex

fin:
               
    ;Terminador de programa          
    MOV AH,4Ch
    INT 21h                
    
END