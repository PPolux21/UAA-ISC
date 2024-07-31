;Espinoza Sanchez Jose Luis         al280676
;Martinez Hernandez Reyli Uvaldo    al350944
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
msjInf  DB  "Solo se aceptan numeros entre +65535.999 y -65535.999 . . . ",'$'
msj     DB  "Introduce el numero: ",'$'
auxBuff DW  0Ah ;auxiliar para pasar el buffer
auxBin  DW  2   ;auxiliar para pasar a binario
auxHex  DW  4   ;auxlilar para pasar a hexadecimal

opera   DB  "Elija la Operacion:",'$'
opera1  DB  "  1. Suma",'$'
opera2  DB  "  2. Resta",'$'
option  DB  "Elija el Formato:","$"
option1 DB  "  1. Decimal",'$'
option2 DB  "  2. Hexadecimal",'$'
salida  DB  "  3. Salir",'$'

signoOp DB  0

selOpt  DB  "Opcion: ","$"

signo1   DB  ?
entero1  DW  ?
frac1    DW  ?

signo2   DB  ?
entero2  DW  ?
frac2    DW  ?

infinitoBin DB  0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

binInt1  DB  16 DUP(0)
binFrac1 DB  40 DUP(0)
power1   DB  8  DUP(?)

binInt2  DB  16 DUP(0)
binFrac2 DB  40 DUP(0)
power2   DB  8  DUP(?)


point1   DB  0   ;posicion del punto
point2   DB  0   ;posicion del punto

ajust   DB  0

vecHex  DB  4  DUP(?)
valHex  DB  ?
cont    DB  0

binIEEE1 DB  32 DUP(?)
binIEEE2 DB  32 DUP(?)

auxOpera1 DB 30 DUP(0)  ;Almacenan la mantiza
auxOpera2 DB 30 DUP(0)
resOpera  DB 30 DUP(0)

resBin  DB  32 DUP(?)
resHEX  DB  8  DUP(?)
resDec  DB  '+',0,0,0,0,0,'.',0,0,0
resInt  DW  0
resFrac DW  0

buff1    DB  15,?,15 DUP(?)
buff2    DB  15,?,15 DUP(?)

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
    
errorInf:
    
    MOV AH,06
    MOV AL,00    ;Numero de lineas a desplazar
    MOV BH,0Ch  ;Atributo (color)(4b mas significativos para color de pantalla y 4b menos significativos para color texto)
    MOV CH,0   ;Linea donde comienza
    MOV CL,0   ;Columna donde comienza
    MOV DH,10    ;Linea donde termine
    MOV DL,60    ;Columna donde termina
    INT 10h
    
    MOV AH,0
    MOV AL,2
    INT 10h 
    
    print msjInf

    MOV AH,4Ch
    INT 21h    

inicio:

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

    print opera
    endl 
    print opera1
    endl
    print opera2
    endl
    print salida
    endl
    print selOpt
    
    MOV AH,01
    INT 21h
    
    CMP AL,31h
    JE  optSuma
    
    CMP AL,32h
    JE  optResta           
            
    CMP AL,33h
    JE  fin
    
    JMP inicio
    
optSuma:

    MOV signoOp,0
    JMP regisData

optResta:
    
    MOV signoOp,1
    JMP regisData               
    
regisData:

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

    print msj
    ;Entrada del primer numero
    MOV AH,0Ah
    MOV DX,OFFSET buff1
    INT 21h
    endl
    print msj
    ;Entrada del segundo numero
    MOV AH,0Ah
    MOV DX,OFFSET buff2
    INT 21h

;paso de buffer a dato numerico
;buff1
    
    MOV DI,2
    
    ;validaciones
    
    CMP buff1[DI],2Dh    ;igual a menos
    JE  negativo1
    
    CMP buff1[DI],2Bh    ;igual a mas
    JE  positivo1
    
    CMP buff1[DI],30h    ;menor que 30h
    JB  errorBuff
    
    CMP buff1[DI],39h    ;mayor que 39h
    JA  errorBuff
                    
    JMP sinSigno1       ;si esta en el rango de 30h y 39h
    
positivo1:
    INC DI
    
sinSigno1:    
    XOR AX,AX
    MOV signo1,0
    JMP finSigno1

negativo1:
    INC DI
    XOR AX,AX
    MOV signo1,1
    
finSigno1:
;Buffer al valor del numero entero
    
    XOR BX,BX       
    MUL auxBuff
    ;si se activa CF sale del programa
    JC  errorInf   ;error si es Infinito
    
    ;validaciones
    CMP buff1[DI],30h    ;menor que 30h
    JB  errorBuff
    
    CMP buff1[DI],39h    ;mayor que 39h
    JA  errorBuff
    
    SUB buff1[DI],30h
    
    MOV BL,buff1[DI]
    
    ADD AX,BX
    ;si se activa CF sale del programa
    JC  errorInf   ;error si es Infinito
    
    INC DI
    
    CMP buff1[DI],0Dh
    JE  sinFraccion1 
    
    CMP buff1[DI],2Eh
    JNE finSigno1
    
    MOV entero1,AX
    INC DI
    XOR AX,AX
    XOR SI,SI
    JMP buffFrac1
    
sinFraccion1:

    MOV entero1,AX
    XOR AX,AX
    JMP asignFrac1

buffFrac1:        
;Buffer a valor de la fraccion

    XOR BX,BX       
    MUL auxBuff
    
    ;validaciones
    CMP buff1[DI],30h    ;menor que 30h
    JB  errorBuff
    
    CMP buff1[DI],39h    ;mayor que 39h
    JA  errorBuff
    
    SUB buff1[DI],30h
    
    MOV BL,buff1[DI]
    
    ADD AX,BX
    
    INC DI
    INC SI
    
    CMP SI,3
    JAE asignFrac1
    
    CMP buff1[DI],0Dh
    JNE buffFrac1

confirmCeros1:
    
    CMP SI,3
    JAE asignFrac1
    
    MUL auxBuff
    INC SI
    JMP confirmCeros1
    
asignFrac1:    
    MOV frac1,AX

;comprueba que todo sea cero    
    CMP entero1,0
    JNE toBin1
    CMP frac1,0
    JNE toBin1
    
    XOR DI,DI
    
vecCeros1:

    MOV  binIEEE1[DI],0
    INC  DI
    CMP  DI,31
    JNAE vecCeros1

    JMP  labelBuff2
    
;paso de numero a binarios
;Primer numero    
    
toBin1:
    XOR DX,DX 
    MOV AX,entero1
    MOV DI,15
    
cicloBI1:    
    
    XOR DX,DX 
    DIV auxBin
    MOV binInt1[DI], DL   
    DEC DI
    CMP AX,0
    JNE cicloBI1

;Valor de fraccion a binario
    XOR DX,DX ;limpia de DX
    MOV AX,frac1
    XOR DI,DI
    
cicloBF1:;multiplicar el numerador hasta que sea mayor que el denominador    
    
    ;para cuando hay un 0 como resultado en AX
    CMP AX,0
    JE  finCicloBF1
    
    MUL auxBin
    
    CMP AX,1000
    JAE unoBinario1
    
    MOV binFrac1[DI], 0
    INC DI
    
    CMP DI,40
    JNE cicloBF1
    JMP finCicloBF1
         
unoBinario1:

    SUB AX,1000

    MOV binFrac1[DI], 1
    INC DI
    
    CMP DI,40
    JNE cicloBF1              
         
finCicloBF1:

    XOR DI,DI
    XOR SI,SI
    CMP entero1, 0
    JE  sinEntero1
    
;Parte entera > 0 
;(se suma el recorrido del punto 127 para binario)
    ;recorre el vector binario hasta que encuentre el 1 mas a la izq
    ;cuenta los espacios entre ese 1 y el tope de la derecha
recorreInt1:

    CMP binInt1[DI],1
    JE  finRecorreInt1
    
    INC DI
    JMP recorreInt1

finRecorreInt1:        

    MOV AX,DI
    MOV BL,10h
    SUB BL,AL
    MOV point1,BL
    DEC point1
    
    JMP binaryPowerPos1

;Parte entera = 0 
;(se resta el recorrido del punto a 127 para binario)
sinEntero1:
    ;recorre el vector binario hasta que encuentre el uno mas a la izq
    ;cuenta los espacios entre ese 1 y el tope de la izquierda
    
    CMP binFrac1[DI],1
    JE  finRecorreFrac1
    CMP DI,39
    JAE finRecorreFracZ1
    
    INC DI
    JMP sinEntero1
    
finRecorreFracZ1:
    MOV DI,0

finRecorreFrac1:        

    MOV AX,DI
    MOV point1,AL
    INC point1
    
    JMP binaryPowerNeg1
    
;Pasa a Binario el recorrido del punto
binaryPowerPos1:
    XOR DX,DX 
    MOV AL,127
    ADD AL,point1
    MOV DI,7
    JMP cicloBP1
    
binaryPowerNeg1:    
    XOR DX,DX 
    MOV AL,127
    SUB AL,point1
    MOV DI,7
    
cicloBP1:    
    
    XOR DX,DX 
    DIV auxBin
    MOV power1[DI], DL   
    DEC DI
    CMP AX,0
    JNE cicloBP1
    
;paso de buffer a dato numerico
labelBuff2:  
   
   MOV DI,2
    
    ;validaciones
    
    CMP buff2[DI],2Dh    ;igual a menos
    JE  negativo2
    
    CMP buff2[DI],2Bh    ;igual a mas
    JE  positivo2
    
    CMP buff2[DI],30h    ;menor que 30h
    JB  errorBuff
    
    CMP buff2[DI],39h    ;mayor que 39h
    JA  errorBuff
                    
    JMP sinSigno2       ;si esta en el rango de 30h y 39h
    
positivo2:
    INC DI
    
sinSigno2:    
    XOR AX,AX
    MOV signo2,0
    JMP finSigno2

negativo2:
    INC DI
    XOR AX,AX
    MOV signo2,1
    
finSigno2:
;Buffer al valor del numero entero
    
    XOR BX,BX       
    MUL auxBuff
    ;si se activa CF sale del programa
    JC  errorInf   ;error si es Infinito
    
    ;validaciones
    CMP buff2[DI],30h    ;menor que 30h
    JB  errorBuff
    
    CMP buff2[DI],39h    ;mayor que 39h
    JA  errorBuff
    
    SUB buff2[DI],30h
    
    MOV BL,buff2[DI]
    
    ADD AX,BX
    ;si se activa CF sale del programa
    JC  errorInf   ;error si es Infinito
    
    INC DI
    
    CMP buff2[DI],0Dh
    JE  sinFraccion2 
    
    CMP buff2[DI],2Eh
    JNE finSigno2
    
    MOV entero2,AX
    INC DI
    XOR AX,AX
    XOR SI,SI
    JMP buffFrac2
    
sinFraccion2:

    MOV entero2,AX
    XOR AX,AX
    JMP asignFrac2

buffFrac2:        
;Buffer a valor de la fraccion

    XOR BX,BX       
    MUL auxBuff
    
    ;validaciones
    CMP buff2[DI],30h    ;menor que 30h
    JB  errorBuff
    
    CMP buff2[DI],39h    ;mayor que 39h
    JA  errorBuff
    
    SUB buff2[DI],30h
    
    MOV BL,buff2[DI]
    
    ADD AX,BX
    
    INC DI
    INC SI
    
    CMP SI,3
    JAE asignFrac2
    
    CMP buff2[DI],0Dh
    JNE buffFrac2

confirmCeros2:
    
    CMP SI,3
    JAE asignFrac2
    
    MUL auxBuff
    INC SI
    JMP confirmCeros2
    
asignFrac2:    
    MOV frac2,AX

;comprueba que todo sea cero    
    CMP entero2,0
    JNE toBin2
    CMP frac2,0
    JNE toBin2
    
    XOR DI,DI

vecCeros2:

    MOV  binIEEE2[DI],0
    INC  DI
    CMP  DI,31
    JNAE vecCeros2

    JMP operacion
    
;paso de numero a binarios
;Segundo numero    
    
toBin2:
    XOR DX,DX 
    MOV AX,entero2
    MOV DI,15
    
cicloBI2:    
    
    XOR DX,DX 
    DIV auxBin
    MOV binInt2[DI], DL   
    DEC DI
    CMP AX,0
    JNE cicloBI2

;Valor de fraccion a binario
    XOR DX,DX ;limpia de DX
    MOV AX,frac2
    XOR DI,DI
    
cicloBF2:;multiplicar el numerador hasta que sea mayor que el denominador    
    
    ;para cuando hay un 0 como resultado en AX
    CMP AX,0
    JE  finCicloBF2
    
    MUL auxBin
    
    CMP AX,1000
    JAE unoBinario2
    
    MOV binFrac2[DI], 0
    INC DI
    
    CMP DI,40
    JNE cicloBF2
    JMP finCicloBF2
         
unoBinario2:

    SUB AX,1000

    MOV binFrac2[DI], 1
    INC DI
    
    CMP DI,40
    JNE cicloBF2              
         
finCicloBF2:

    XOR DI,DI
    XOR SI,SI
    CMP entero2, 0
    JE  sinEntero2
    
;Parte entera > 0 
;(se suma el recorrido del punto 127 para binario)
    ;recorre el vector binario hasta que encuentre el 1 mas a la izq
    ;cuenta los espacios entre ese 1 y el tope de la derecha
recorreInt2:

    CMP binInt2[DI],1
    JE  finRecorreInt2
    
    INC DI
    JMP recorreInt2

finRecorreInt2:        

    MOV AX,DI
    MOV BL,10h
    SUB BL,AL
    MOV point2,BL
    DEC point2
    
    JMP binaryPowerPos2

;Parte entera = 0 
;(se resta el recorrido del punto a 127 para binario)
sinEntero2:
    ;recorre el vector binario hasta que encuentre el uno mas a la izq
    ;cuenta los espacios entre ese 1 y el tope de la izquierda
    
    CMP binFrac2[DI],1
    JE  finRecorreFrac2
    CMP DI,39
    JAE finRecorreFracZ2
    
    INC DI
    JMP sinEntero2
    
finRecorreFracZ2:
    MOV DI,0

finRecorreFrac2:        

    MOV AX,DI
    MOV point2,AL
    INC point2
    
    JMP binaryPowerNeg2
    
;Pasa a Binario el recorrido del punto
binaryPowerPos2:
    XOR DX,DX 
    MOV AL,127
    ADD AL,point2
    MOV DI,7
    JMP cicloBP2
    
binaryPowerNeg2:    
    XOR DX,DX 
    MOV AL,127
    SUB AL,point2
    MOV DI,7
    
cicloBP2:    
    
    XOR DX,DX 
    DIV auxBin
    MOV power2[DI], DL   
    DEC DI
    CMP AX,0
    JNE cicloBP2
    
;Juntar valores al binario final
;Primer numero

    XOR DI,DI
    
    MOV AL,signo1 
    MOV binIEEE1[DI],AL
    
    XOR SI,SI 
    INC DI

movPower1:    
    CMP DI,8
    JA  finMovPower1

    MOV AL,power1[SI]    
    MOV binIEEE1[DI],AL
    
    INC DI
    INC SI
    JMP movPower1

finMovPower1:
    
    XOR AX,AX
    MOV AL,point1
    
    CMP entero1,0
    JE  movFracSinInt1
    
;movInt:
    MOV AL,point1
    MOV BX,10h
    SUB BL,AL
    MOV SI,BX
      
movInt1:    
    CMP SI,15
    JA  finMovInt1

    MOV AL,binInt1[SI]    
    MOV binIEEE1[DI],AL
    
    INC DI
    INC SI
    JMP movInt1    
finMovInt1:

    XOR SI,SI
    MOV AL,point1
    MOV BX,10h
    SUB BL,AL
    
movFrac1:
    CMP SI,39
    JA  segundoIEEE
    CMP DI,31
    JA  segundoIEEE

    MOV AL,binFrac1[SI]    
    MOV binIEEE1[DI],AL
    
    INC DI
    INC SI
    JMP movFrac1
     
movFracSinInt1:
    
    XOR AX,AX
    MOV AL,point1
    MOV SI,AX
    
cicloMovFracSI1:
    CMP SI,39
    JA  segundoIEEE
    CMP DI,31
    JA  segundoIEEE

    MOV AL,binFrac1[SI]    
    MOV binIEEE1[DI],AL
    
    INC DI
    INC SI
    JMP cicloMovFracSI1
    
;Juntar valores al binario final
;Segundo numero
segundoIEEE:

    XOR DI,DI
    
    MOV AL,signo2 
    MOV binIEEE2[DI],AL
    
    XOR SI,SI 
    INC DI

movPower2:    
    CMP DI,8
    JA  finMovPower2

    MOV AL,power2[SI]    
    MOV binIEEE2[DI],AL
    
    INC DI
    INC SI
    JMP movPower2

finMovPower2:
    
    XOR AX,AX
    MOV AL,point2
    
    CMP entero2,0
    JE  movFracSinInt2
    
;movInt:
    MOV AL,point2
    MOV BX,10h
    SUB BL,AL
    MOV SI,BX
      
movInt2:    
    CMP SI,15
    JA  finMovInt2

    MOV AL,binInt2[SI]    
    MOV binIEEE2[DI],AL
    
    INC DI
    INC SI
    JMP movInt2
finMovInt2:

    XOR SI,SI
    MOV AL,point2
    MOV BX,10h
    SUB BL,AL
    
movFrac2:
    CMP SI,39
    JA  operacion
    CMP DI,31
    JA  operacion

    MOV AL,binFrac2[SI]    
    MOV binIEEE2[DI],AL
    
    INC DI
    INC SI
    JMP movFrac2
     
movFracSinInt2:
    
    XOR AX,AX
    MOV AL,point2
    MOV SI,AX
    
cicloMovFracSI2:
    CMP SI,39
    JA  operacion
    CMP DI,31
    JA  operacion

    MOV AL,binFrac2[SI]    
    MOV binIEEE2[DI],AL
    
    INC DI
    INC SI
    JMP cicloMovFracSI2

operacion:
;Obtencion de los ajustes del punto para cada numero
;   convierte a decimal el binario que representa el ajuste del punto
    
    MOV point1,0
    XOR SI,SI
    INC SI
;bit8    
    CMP binIEEE1[SI],1
    JNE primeroBit7
    ADD point1,128
    
primeroBit7:
    
    INC SI
    CMP binIEEE1[SI],1
    JNE primeroBit6
    ADD point1,64

primeroBit6:
    
    INC SI
    CMP binIEEE1[SI],1
    JNE primeroBit5
    ADD point1,32
    
primeroBit5:
    
    INC SI
    CMP binIEEE1[SI],1
    JNE primeroBit4
    ADD point1,16

primeroBit4:
    
    INC SI
    CMP binIEEE1[SI],1
    JNE primeroBit3
    ADD point1,8
    
primeroBit3:
    
    INC SI
    CMP binIEEE1[SI],1
    JNE primeroBit2
    ADD point1,4

primeroBit2:
    
    INC SI
    CMP binIEEE1[SI],1
    JNE primeroBit1
    ADD point1,2
    
primeroBit1:
    
    INC SI
    CMP binIEEE1[SI],1
    JNE primeroBitFin
    ADD point1,1

primeroBitFin:    
    
;segundo    
    MOV point2,0
    XOR SI,SI
    INC SI
;bit8    
    CMP binIEEE2[SI],1
    JNE segundoBit7
    ADD point2,128
    
segundoBit7:
    
    INC SI
    CMP binIEEE2[SI],1
    JNE segundoBit6
    ADD point2,64

segundoBit6:
    
    INC SI
    CMP binIEEE2[SI],1
    JNE segundoBit5
    ADD point2,32
    
segundoBit5:
    
    INC SI
    CMP binIEEE2[SI],1
    JNE segundoBit4
    ADD point2,16

segundoBit4:
    
    INC SI
    CMP binIEEE2[SI],1
    JNE segundoBit3
    ADD point2,8
    
segundoBit3:
    
    INC SI
    CMP binIEEE2[SI],1
    JNE segundoBit2
    ADD point2,4

segundoBit2:
    
    INC SI
    CMP binIEEE2[SI],1
    JNE segundoBit1
    ADD point2,2
    
segundoBit1:
    
    INC SI
    CMP binIEEE2[SI],1
    JNE segundoBitFin
    ADD point2,1

segundoBitFin:


;Determina la Operacion a realizar entre los numeros
;   Esto determinado entre la eleccion inicial 
;   y los signos de los numeros 

    XOR DI,DI
    XOR DX,DX
    XOR AX,AX
    MOV AL,signoOp
    ADD AL,binIEEE1[DI]
    ADD AL,binIEEE2[DI]
    
    DIV auxBin
    
    CMP DX,1
    JE  restaOp
                                ;SUMA
sumaOp:

    MOV CX,0

    CMP point1,0
    JE  sCeros
    
    CMP point2,0
    JE  sCeros

    ;positivos
    CMP point1,127
    JB  sUnNeg1
    
    SUB point1,127
    
    CMP point2,127
    JB  sUnNeg2
    
    SUB point2,127
                 
    MOV AL,point2
    CMP point1,AL
    JA  sBothPos
    
    MOV AL,point2
    SUB AL,point1
    
    MOV ajust,AL 
    
    JMP sFinAjust

sBothPos:

    MOV AL,point1
    SUB AL,point2
    
    MOV ajust,AL
    
    JMP sFinAjust
    
    ;uno pos, uno neg
sUnNeg1:

    CMP point2,127
    JB  sDosNeg
    
    SUB point1,127
    SUB point2,127
    
    MOV AL,0FFh
    SUB AL,point1
    
    INC AL
    
    MOV point1,AL
    
    JMP sAjUnNeg
    
sUnNeg2:
        
    SUB point2,127
    
    MOV AL,0FFh
    SUB AL,point2
    
    INC AL
    
    MOV point2,AL
    
    
sAjUnNeg:

    MOV AL,point1
    ADD AL,point2
    MOV ajust,AL
    
    MOV CX,2
    
    JMP sFinAjust
    
    ;negativos
sDosNeg:

    SUB point1,127
    SUB point2,127
    
    MOV AL,0FFh
    SUB AL,point1
    
    INC AL
    
    MOV point1,AL
    
    MOV AL,0FFh
    SUB AL,point2
    
    INC AL
    
    MOV point2,AL
    
    MOV AL,point2
    CMP point1,AL
    JA  sBothNeg
    
    MOV AL,point2
    SUB AL,point1
    
    MOV ajust,AL 
    
    MOV CX,1
    
    JMP sFinAjust

sBothNeg:

    MOV AL,point1
    SUB AL,point2
    
    MOV ajust,AL
    
    MOV CX,1
    
    JMP sFinAjust
    
    ;ceros
    
sAjustEspecial:

    MOV DI,1
    
    CMP binIEEE1[DI],0
    JE  sPreAjust1
    
;   CMP binIEEE2[DI],0    
    JMP sAjust3
    
sCeros:
    MOV ajust,0    
    
sFinAjust:
    
    MOV BL,point2
    ADD BL,point1

    MOV AL,point2
    CMP point1,AL
    JA  sAjust3
    JE  sSinAjuste
    
    CMP CX,1
    JE  sAjust3IF
    JA  sAjustEspecial

    
;Iguala las potencias de los IEEE
    
sPreAjust1:

    MOV AL,point2
    MOV point1,AL
    
    XOR DI,DI
    
sAjust1:
    INC DI  
    
    CMP DI,9
    JE  sFinIEEEAjust1
    
    MOV AL,binIEEE2[DI]
    MOV binIEEE1[DI],AL
    
    JMP sAjust1

sFinIEEEAjust1:    
         
    XOR AX,AX
    MOV AL,31
    SUB AL,ajust
    MOV DI,AX
    MOV SI,31
    MOV CX,1
;Hace el ajuste en la mantiza    
sAjust2:

    CMP DI,8
    JE  sRellenaC1
    
    MOV AL,binIEEE1[DI]
    MOV binIEEE1[SI],AL
    
    DEC SI
    DEC DI
    
    JMP sAjust2
    
sRellenaC1:

    MOV binIEEE1[SI],1
    DEC SI    

sRellenaC2:

    CMP SI,8
    JE  sOpera
    
    MOV binIEEE1[SI],0    
    
    DEC SI
    JMP sRellenaC2

;Iguala las potencias de los IEEE
sAjust3:
    XOR DI,DI

    CMP CX,1
    JE  sAjust1
sAjust3IF:
    XOR DI,DI    
    
    MOV AL,point1
    MOV point2,AL
    
sCAjust3:
    INC DI  
    
    CMP DI,9
    JE  sFinIEEEAjust3
    
    MOV AL,binIEEE1[DI]
    MOV binIEEE2[DI],AL
    
    JMP sCAjust3
    
sFinIEEEAjust3:    
         
    XOR AX,AX
    MOV AL,31
    SUB AL,ajust
    MOV DI,AX
    MOV SI,31
    MOV CX,2
    
;Hace el ajuste en la mantiza    
sAjust4:

    CMP DI,8
    JE  sRellenaC3
    
    MOV AL,binIEEE2[DI]
    MOV binIEEE2[SI],AL
    
    DEC SI
    DEC DI
    
    JMP sAjust4
    
sRellenaC3:

    MOV binIEEE2[SI],1
    DEC SI    

sRellenaC4:

    CMP SI,8
    JE  sOpera
    
    MOV binIEEE2[SI],0    
    
    DEC SI
    JMP sRellenaC4
    
sSinAjuste:

    CMP ajust,BL
    JE  sAjustEspecial
    
    MOV CX,3    
    
sOpera:

    MOV DI,31
    MOV SI,29
    
sCopyNum1:
    
    CMP DI,8
    JE  sFinCopyNum1
    
    MOV AL,binIEEE1[DI]
    MOV auxOpera1[SI],AL 
    
    DEC DI
    DEC SI
    
    JMP sCopyNum1
    
sFinCopyNum1:

    CMP CX,2
    JE  sAddUno1
    CMP CX,3
    JE  sAddUno1  
    
    JMP sNotAjust1
           
sAddUno1:           
    MOV auxOpera1[SI],1   

sNotAjust1:
    
    MOV DI,31
    MOV SI,29
    
sCopyNum2:
    
    CMP DI,8
    JE  sFinCopyNum2
    
    MOV AL,binIEEE2[DI]
    MOV auxOpera2[SI],AL 
    
    DEC DI
    DEC SI
    
    JMP sCopyNum2    
    
sFinCopyNum2:

    CMP CX,1
    JE  sAddUno2
    CMP CX,3
    JE  sAddUno2  
    
    JMP sNotAjust2
           
sAddUno2:
    
    MOV auxOpera2[SI],1   

sNotAjust2:
        
    MOV DI,29
    
sCicloSuma:    
    
    CMP DI,0
    JE  sFinSuma

    XOR AX,AX
    
    MOV AL,auxOpera1[DI]
    ADD AL,auxOpera2[DI]
                       
    CMP AL,2
    JE  sCarryCase1
    CMP AL,3
    JE  sCarryCase1                      
    
    MOV resOpera[DI],AL
    DEC DI
    
    JMP sCicloSuma
    
sCarryCase1:

    ADD auxOpera1[DI-1],1
    DEC AL
    DEC AL
    
    MOV resOpera[DI],AL
    DEC DI
    
    JMP sCicloSuma
    
sFinSuma:

;Comprobar si hubo cambio en la potencia

    ;MOV AH,01           ;;BORRAME
    ;INT 21h             ;;BORRAME

    XOR DI,DI

sCompruebaPunto:

    CMP resOpera[DI],1
    JE  sFinCompruebaPunto
    
    INC DI
    
    JMP sCompruebaPunto
    
sFinCompruebaPunto:

    XOR CX,CX

    MOV AX,DI
    MOV point2,AL   ;Guarda el valor donde inicia la mantisa en el resOpera

    CMP DI,6
    JE  sCopiaIEEE

sCorrigeAjuste:    

    MOV CX,1
    
    MOV ajust,0
    XOR SI,SI
    INC SI
;bit8    
    CMP binIEEE1[SI],1
    JNE sPrimeroBit7
    ADD ajust,128
    
sPrimeroBit7:
    
    INC SI
    CMP binIEEE1[SI],1
    JNE sPrimeroBit6
    ADD ajust,64

sPrimeroBit6:
    
    INC SI
    CMP binIEEE1[SI],1
    JNE sPrimeroBit5
    ADD ajust,32
    
sPrimeroBit5:
    
    INC SI
    CMP binIEEE1[SI],1
    JNE sPrimeroBit4
    ADD ajust,16

sPrimeroBit4:
    
    INC SI
    CMP binIEEE1[SI],1
    JNE sPrimeroBit3
    ADD ajust,8
    
sPrimeroBit3:
    
    INC SI
    CMP binIEEE1[SI],1
    JNE sPrimeroBit2
    ADD ajust,4

sPrimeroBit2:
    
    INC SI
    CMP binIEEE1[SI],1
    JNE sPrimeroBit1
    ADD ajust,2
    
sPrimeroBit1:
    
    INC SI
    CMP binIEEE1[SI],1
    JNE sPrimeroBitFin
    ADD ajust,1

sPrimeroBitFin:
    
    MOV AL,6
    SUB AL,point2
    ADD ajust,AL

    CMP ajust,143
    JAE sVecInfinito
    
    XOR AX,AX
    MOV AL,ajust
    MOV DI,8
    
sCicloBinP:    
    
    XOR DX,DX 
    DIV auxBin
    MOV resBin[DI], DL   
    DEC DI
    CMP AX,0
    JNE sCicloBinP    
            
    
;Acomodar la potencia y el numero en el resIEEE

sCopiaIEEE:

    XOR DI,DI
    
sCicloCopiaIEEE:

    CMP DI,9
    JE  sCopiaMant

    MOV AL,binIEEE1[DI]
    MOV resBin[DI],AL
    
    CMP CX,1
    JE  sCopiaMant
    
    INC DI
    
    JMP sCicloCopiaIEEE   
    
sCopiaMant:

    XOR AX,AX
    INC point2
    MOV AL,point2
    MOV SI,AX
    MOV DI,9
    
sCicloCopiaMant:

    CMP DI,32
    JE  sFinCopiaMant

    MOV AL,resOpera[SI]
    MOV resBin[DI],AL    
    
    INC DI
    INC SI
    
    JMP sCicloCopiaMant
    
    
sVecInfinito:

    XOR DI,DI
    MOV AL,binIEEE1[DI]
    MOV resBin[DI],AL
    INC DI
    
sCicloInfinitoBin:
    MOV  AL,infinitoBin[DI]
    MOV  resBin[DI],AL
    INC  DI
    CMP  DI,31
    JNAE sCicloInfinitoBin    
    
sFinCopiaMant:
;convertir en HEX y DEC

;Convertidor Hexadecimal
convierteHex: 
    XOR DI,DI

cicloConvierteHex:

    CMP DI,31
    JAE convierteDec
    
    XOR SI,SI

    MOV AL,resBin[DI]
    MOV vecHex[SI],AL
    INC DI
    INC SI
    MOV AL,resBin[DI]
    MOV vecHex[SI],AL
    INC DI
    INC SI
    MOV AL,resBin[DI]
    MOV vecHex[SI],AL
    INC DI
    INC SI
    MOV AL,resBin[DI]
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
    MOV resHEX[SI],AL
    MOV valHex,0
   
    JMP cicloConvierteHex
    
;Convertidor a Decimal    
convierteDec:

;    MOV AH,01           ;;BORRAME
;    INT 21h             ;;BORRAME

    XOR DI,DI
    XOR SI,SI

    CMP resBin[DI],1
    JNE decPositivo
    
    MOV resDec[SI],2Dh

decPositivo:

    INC DI
    XOR AX,AX
    
cicloBinPow:

    CMP DI,9
    JAE finCicloBinPow

    CMP resBin[DI],1
    JNE cicloBinPowC
    ADD AL,1
cicloBinPowC:    
    ROL AL,1

    INC DI
    JMP cicloBinPow
    
finCicloBinPow:    
    ROR AL,1
    MOV ajust,AL
    
    
    XOR AX,AX    
    MOV AL,ajust
    CMP AL,127
    JB  decSinEntero
    CMP ajust,255
    JE  resDecInf
    SUB AL,127
    ADD AL,8
    MOV BX,AX
   
decBinToInt:
    
    MOV DI,9
    XOR AX,AX
    ADD AX,1
    ROL AX,1
    
cicloBinDec:

    CMP DI,BX
    JA  finCicloBinDec

    CMP resBin[DI],1
    JNE cicloBinDecC
    ADD AX,1
cicloBinDecC:    
    ROL AX,1

    INC DI
    JMP cicloBinDec
    
finCicloBinDec:    
    ROR AX,1
    MOV resInt,AX
    MOV DI,5
    
binDec:
    
    XOR DX,DX
    DIV auxBuff
    MOV resDec[DI],DL
    ADD resDec[DI],30h
    
    DEC DI
    
    CMP AX,0
    JNE binDec
    
    MOV DI,BX
    INC DI
    XOR SI,SI
          
    JMP decParteFraccionaria
    
;parte fraccionaria    
decSinEntero:
        
    MOV SI,5
    MOV resDec[SI],30h
    
    CMP ajust,0
    JE  resDecCero
    
    XOR AX,AX
    MOV AL,127
    SUB AL,ajust
    MOV BX,AX
    MOV CX,AX
    MOV DI,9
    XOR SI,SI
    DEC BX
    CMP BX,0
    JE  finCicloRol       
    
cicloRol:
    ROL auxBin,1 
    INC SI
    
    DEC BX
    JNE cicloRol
finCicloRol:    
    
    XOR DX,DX
    MOV AX,10000
    DIV auxBin
    ADD resFrac,AX
    ROL auxBin,1
    INC SI
    
    MOV BX,CX
    MOV BH,08h    

decParteFraccionaria:;parte fraccionaria general    
    
cicloBinFrac:
    
    CMP DI,32
    JAE finCicloBinFrac

    XOR AX,AX
    XOR DX,DX

    CMP resBin[DI],1
    JNE cicloBinFracC
    MOV AX,10000
    DIV auxBin
cicloBinFracC:    
    ROL auxBin,1
    ADD resFrac,AX

    INC DI
    INC SI
    CMP SI,13
    JNAE cicloBinFrac

finCicloBinFrac:    
    
    MOV DI,9

    XOR DX,DX              
              
    MOV AX,resFrac
    DIV auxBuff
    
fracDec:
    
    XOR DX,DX
    DIV auxBuff
    MOV resDec[DI],DL
    ADD resDec[DI],30h
    
    DEC DI
    
    CMP DI,6
    JNE fracDec
    
;mandar a menu para mostrar
    
    JMP menuMostrar
    
resDecCero:

    INC SI
    INC SI
    MOV resDec[SI],30h
    INC SI
    MOV resDec[SI],30h
    INC SI
    MOV resDec[SI],30h
        
    JMP menuMostrar

resDecInf:
    
    MOV DI,1
    MOV resDec[DI],49h
    INC DI
    MOV resDec[DI],6Eh
    INC DI
    MOV resDec[DI],66h
    INC DI
    MOV resDec[DI],69h
    INC DI
    MOV resDec[DI],6Eh
    INC DI
    MOV resDec[DI],69h
    INC DI
    MOV resDec[DI],74h
    INC DI
    MOV resDec[DI],6Fh
    
    JMP menuMostrar
    
                                ;RESTA
restaOp:
    
    CMP binIEEE2[DI],0
    JE  rCambiaUno
    MOV binIEEE2[DI],0
    JMP rFinCambioSign
    
rCambiaUno:

    MOV binIEEE2[DI],1

rFinCambioSign:

    MOV CX,0

    CMP point1,0
    JE  rCeros
    
    CMP point2,0
    JE  rCeros

    ;positivos
    CMP point1,127
    JB  rUnNeg1
    
    SUB point1,127
    
    CMP point2,127
    JB  rUnNeg2
    
    SUB point2,127
                 
    MOV AL,point2
    CMP point1,AL
    JA  rBothPos
    
    MOV AL,point2
    SUB AL,point1
    
    MOV ajust,AL 
    
    JMP rFinAjust

rBothPos:

    MOV AL,point1
    SUB AL,point2
    
    MOV ajust,AL
    
    JMP rFinAjust
    
    ;uno pos, uno neg
rUnNeg1:

    CMP point2,127
    JB  rDosNeg
    
    SUB point1,127
    SUB point2,127
    
    MOV AL,0FFh
    SUB AL,point1
    
    INC AL
    
    MOV point1,AL
    
    JMP rAjUnNeg
    
rUnNeg2:
        
    SUB point2,127
    
    MOV AL,0FFh
    SUB AL,point2
    
    INC AL
    
    MOV point2,AL
    
    
rAjUnNeg:

    MOV AL,point1
    ADD AL,point2
    MOV ajust,AL
    
    MOV CX,2
    
    JMP rFinAjust
    
    ;negativos
rDosNeg:

    SUB point1,127
    SUB point2,127
    
    MOV AL,0FFh
    SUB AL,point1
    
    INC AL
    
    MOV point1,AL
    
    MOV AL,0FFh
    SUB AL,point2
    
    INC AL
    
    MOV point2,AL
    
    MOV AL,point2
    CMP point1,AL
    JA  rBothNeg
    
    MOV AL,point2
    SUB AL,point1
    
    MOV ajust,AL 
    
    MOV CX,1
    
    JMP rFinAjust

rBothNeg:

    MOV AL,point1
    SUB AL,point2
    
    MOV ajust,AL
    
    MOV CX,1
    
    JMP rFinAjust
    
    ;ceros
    
rAjustEspecial:

    MOV DI,1
    
    CMP binIEEE1[DI],0
    JE  rPreAjust1
    
;   CMP binIEEE2[DI],0    
    JMP rAjust3
    
rCeros:
    MOV ajust,0
    
rFinAjust:
    
    MOV BL,point2
    ADD BL,point1

    MOV AL,point2
    CMP point1,AL
    JA  rAjust3
    JE  rSinAjuste
    
    CMP CX,1
    JE  rAjust3IF
    JA  rAjustEspecial

    
;Iguala las potencias de los IEEE
    
rPreAjust1:

    MOV AL,point2
    MOV point1,AL
    
    XOR DI,DI
    
rAjust1:
    INC DI  
    
    CMP DI,9
    JE  rFinIEEEAjust1
    
    MOV AL,binIEEE2[DI]
    MOV binIEEE1[DI],AL
    
    JMP rAjust1

rFinIEEEAjust1:    
         
    XOR AX,AX
    MOV AL,31
    SUB AL,ajust
    MOV DI,AX
    MOV SI,31
    MOV CX,1
;Hace el ajuste en la mantiza    
rAjust2:

    CMP DI,8
    JE  rRellenaC1
    
    MOV AL,binIEEE1[DI]
    MOV binIEEE1[SI],AL
    
    DEC SI
    DEC DI
    
    JMP rAjust2
    
rRellenaC1:

    MOV binIEEE1[SI],1
    DEC SI    

rRellenaC2:

    CMP SI,8
    JE  rOpera
    
    MOV binIEEE1[SI],0    
    
    DEC SI
    JMP rRellenaC2

;Iguala las potencias de los IEEE
rAjust3:
    XOR DI,DI

    CMP CX,1
    JE  rAjust1
rAjust3IF:
    XOR DI,DI    
    
    MOV AL,point1
    MOV point2,AL
    
rCAjust3:
    INC DI  
    
    CMP DI,9
    JE  rFinIEEEAjust3
    
    MOV AL,binIEEE1[DI]
    MOV binIEEE2[DI],AL
    
    JMP rCAjust3
    
rFinIEEEAjust3:    
         
    XOR AX,AX
    MOV AL,31
    SUB AL,ajust
    MOV DI,AX
    MOV SI,31
    MOV CX,2
    
;Hace el ajuste en la mantiza    
rAjust4:

    CMP DI,8
    JE  rRellenaC3
    
    MOV AL,binIEEE2[DI]
    MOV binIEEE2[SI],AL
    
    DEC SI
    DEC DI
    
    JMP rAjust4
    
rRellenaC3:

    MOV binIEEE2[SI],1
    DEC SI    

rRellenaC4:

    CMP SI,8
    JE  rOpera
    
    MOV binIEEE2[SI],0    
    
    DEC SI
    JMP rRellenaC4
    
rSinAjuste:

    CMP ajust,BL
    JE  rAjustEspecial
    
    MOV CX,3
    
rOpera:

    MOV DI,31
    MOV SI,29
    
rCopyNum1:
    
    CMP DI,8
    JE  rFinCopyNum1
    
    MOV AL,binIEEE1[DI]
    MOV auxOpera1[SI],AL 
    
    DEC DI
    DEC SI
    
    JMP rCopyNum1
    
rFinCopyNum1:

    CMP CX,2
    JE  rAddUno1
    CMP CX,3
    JE  rAddUno1  
    
    JMP rNotAjust1
           
rAddUno1:           
    MOV auxOpera1[SI],1   

rNotAjust1:
    
    MOV DI,31
    MOV SI,29
    
rCopyNum2:
    
    CMP DI,8
    JE  rFinCopyNum2
    
    MOV AL,binIEEE2[DI]
    MOV auxOpera2[SI],AL 
    
    DEC DI
    DEC SI
    
    JMP rCopyNum2    
    
rFinCopyNum2:

    CMP CX,1
    JE  rAddUno2
    CMP CX,3
    JE  rAddUno2  
    
    JMP rNotAjust2
           
rAddUno2:
    
    MOV auxOpera2[SI],1   

rNotAjust2:
;Complemento al numero mas chico
        
    MOV DI,29 
    XOR SI,SI
    
    MOV AL,binIEEE1[SI]
    CMP binIEEE2[SI],AL
    JA  rUnoMasDer2
    
rUnoMasDer1:

    CMP auxOpera1[DI],1
    JE  rComplemento1
    
    DEC DI
    
    JMP rUnoMasDer1
    
rComplemento1:

    DEC DI
    
    CMP DI,4
    JE  rFinComplemento2
    
    CMP auxOpera1[DI],0
    JE  rComplementoUno1
    MOV auxOpera1[DI],0
    JMP rFinComplementoUno1
    
rComplementoUno1:

    MOV auxOpera1[DI],1
    
rFinComplementoUno1:    
    
    JMP rComplemento1    

rUnoMasDer2:

    CMP auxOpera2[DI],1
    JE  rComplemento2
    
    DEC DI
    
    JMP rUnoMasDer2
    
rComplemento2:

    DEC DI
    
    CMP DI,4
    JE  rFinComplemento2
    
    CMP auxOpera2[DI],0
    JE  rComplementoUno2
    MOV auxOpera2[DI],0
    JMP rFinComplementoUno2
    
rComplementoUno2:

    MOV auxOpera2[DI],1
    
rFinComplementoUno2:    
    
    JMP rComplemento2

rFinComplemento2:

    MOV DI,29

rCicloSuma:    
    
    CMP DI,0
    JE  rFinSuma

    XOR AX,AX
    
    MOV AL,auxOpera1[DI]
    ADD AL,auxOpera2[DI]
                       
    CMP AL,2
    JE  rCarryCase1
    CMP AL,3
    JE  rCarryCase1                      
    
    MOV resOpera[DI],AL
    DEC DI
    
    JMP rCicloSuma
    
rCarryCase1:

    ADD auxOpera1[DI-1],1
    DEC AL
    DEC AL
    
    MOV resOpera[DI],AL
    DEC DI
    
    JMP rCicloSuma
    
rFinSuma:

;resOpera[DI] donde DI = 6
;Para pasar a la mantisa de resIEEE

    MOV DI,4
    
    MOV resOpera[DI],0
    INC DI

    CMP resOpera[DI],1
    JNE rSinComplementoRes
    
;rComplementoRes:

    MOV DI,0
    MOV resBin[DI],1
    MOV DI,29

rUnoMasDerRes:

    CMP resOpera[DI],1
    JE  rComplementoRes
    
    DEC DI
    
    JMP rUnoMasDerRes
    
rComplementoRes:

    DEC DI
    
    CMP DI,4
    JE  rSinComplementoRes
    
    CMP resOpera[DI],0
    JE  rComplementoUnoRes
    MOV resOpera[DI],0
    JMP rFinComplementoUnoRes
    
rComplementoUnoRes:

    MOV resOpera[DI],1
    
rFinComplementoUnoRes:    
    
    JMP rComplementoRes

rSinComplementoRes:
    MOV resOpera[DI],0
    
    DEC DI

    CMP DI,0
    JNE rSinComplementoRes

;cmoprueba el cambio del ajuste del punto

;    MOV AH,01           ;;BORRAME
;    INT 21h             ;;BORRAME

    MOV DI,5
    MOV resOpera[DI],0


    XOR DI,DI

rCompruebaPunto:

    CMP resOpera[DI],1
    JE  rFinCompruebaPunto
    CMP DI,30
    JAE rVecCeros
    
    INC DI
    
    JMP rCompruebaPunto
    
rFinCompruebaPunto:

    XOR CX,CX

    MOV AX,DI
    MOV point2,AL   ;Guarda el valor donde inicia la mantisa en el resOpera

    CMP DI,6
    JE  rCopiaIEEE

rCorrigeAjuste:    

    MOV CX,1
    
    MOV ajust,0
    XOR SI,SI
    INC SI
;bit8    
    CMP binIEEE1[SI],1
    JNE rPrimeroBit7
    ADD ajust,128
    
rPrimeroBit7:
    
    INC SI
    CMP binIEEE1[SI],1
    JNE rPrimeroBit6
    ADD ajust,64

rPrimeroBit6:
    
    INC SI
    CMP binIEEE1[SI],1
    JNE rPrimeroBit5
    ADD ajust,32
    
rPrimeroBit5:
    
    INC SI
    CMP binIEEE1[SI],1
    JNE rPrimeroBit4
    ADD ajust,16

rPrimeroBit4:
    
    INC SI
    CMP binIEEE1[SI],1
    JNE rPrimeroBit3
    ADD ajust,8
    
rPrimeroBit3:
    
    INC SI
    CMP binIEEE1[SI],1
    JNE rPrimeroBit2
    ADD ajust,4

rPrimeroBit2:
    
    INC SI
    CMP binIEEE1[SI],1
    JNE rPrimeroBit1
    ADD ajust,2
    
rPrimeroBit1:
    
    INC SI
    CMP binIEEE1[SI],1
    JNE rPrimeroBitFin
    ADD ajust,1

rPrimeroBitFin:
    
    MOV AL,point2
    SUB AL,6
    SUB ajust,AL

    CMP ajust,116
    JBE rVecCeros
    
    XOR AX,AX
    MOV AL,ajust
    MOV DI,8
    
rCicloBinP:    
    
    XOR DX,DX 
    DIV auxBin
    MOV resBin[DI], DL   
    DEC DI
    CMP AX,0
    JNE rCicloBinP    
            
    
;Acomodar la potencia y el numero en el resIEEE

rCopiaIEEE:

    MOV DI,1
    
rCicloCopiaIEEE:

    CMP DI,9
    JE  rCopiaMant
    
    CMP CX,1
    JE  rCopiaMant

    MOV AL,binIEEE1[DI]
    MOV resBin[DI],AL
    
    INC DI
    
    JMP rCicloCopiaIEEE   
    
rCopiaMant:

    XOR AX,AX
    INC point2
    MOV AL,point2
    MOV SI,AX
    MOV DI,9
    
rCicloCopiaMant:

    CMP DI,32
    JE  convierteHex

    MOV AL,resOpera[SI]
    MOV resBin[DI],AL    
    
    INC DI
    INC SI
    
    JMP rCicloCopiaMant

rVecCeros:

    MOV  resBin[DI],0
    INC  DI
    CMP  DI,31
    JNAE rVecCeros
    
    JMP  convierteHex
       
    

pausa:
    MOV AH,08h
    INT 21h

;Preguntar en que formato mostrarlo
menuMostrar:

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
    print salida
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
    JE  mostrarDec
    
    CMP AL,32h
    JE  mostrarHex
    
    CMP AL,33h
    JE  fin
    
    JMP menuMostrar    
    
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
    
    MOV BL,resHEX[DI]
    
    CMP resHEX[DI],0Ah
    JAE esLetra
    ADD BL,30h
    JMP imprime
    
esLetra:
    ADD BL,37h
    
imprime:    
    printCh BL
    INC DI
    JMP cicloMuestraHex    
    
mostrarDec:

    MOV AH,06
    MOV AL,00    ;Numero de lineas a desplazar
    MOV BH,02h  ;Atributo (color)(4b mas significativos para color de pantalla y 4b menos significativos para color texto)
    MOV CH,0   ;Linea donde comienza
    MOV CL,0   ;Columna donde comienza
    MOV DH,10    ;Linea donde termine
    MOV DL,50    ;Columna donde termina
    INT 10h
    
    XOR DI,DI
    
cicloMuestraDec:
        
    CMP DI,9
    JA  pausa
    
    printCh resDec[DI]    
    
    INC DI
    JMP cicloMuestraDec
    
fin:           
    ;Terminador de programa          
    MOV AH,4Ch
    INT 21h                
    
END