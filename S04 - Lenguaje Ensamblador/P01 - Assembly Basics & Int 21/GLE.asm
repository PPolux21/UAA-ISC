print MACRO msj
    MOV AH,09h
    MOV DX, OFFSET msj
    INT 21h    
ENDM

.model small

;Segmento de pila
.stack ;Por default, el stack es 100h 

;Segmento de datos______________________________________________
.data
        msg1    DB  "Hoy es ","$"
        msg2    DB  " de ", "$"
        auxDia  DB  ?
        auxND   DB  ?
        auxMes  DB  ?
        lunes       DB  "lunes ","$"
        martes      DB  "martes ","$"
        miercoles   DB  "miercoles ","$"
        jueves      DB  "jueves ","$"
        viernes     DB  "viernes ","$"
        sabado      DB  "sabado ","$"
        domingo     DB  "domingo ","$"
        
        mes1        DB  "enero","$"
        mes2        DB  "febrero","$"
        mes3        DB  "marzo","$"
        mes4        DB  "abril","$"
        mes5        DB  "mayo","$"
        mes6        DB  "junio","$"
        mes7        DB  "julio","$"
        mes8        DB  "agosto","$"
        mes9        DB  "septiembre","$"
        mes10       DB  "octubre","$"
        mes11       DB  "noviembre","$"
        mes12       DB  "diciembre","$"
        
        auxDiv      DW  10
;_______________________________________________________________

;Segmento de codigo
.code

;Estas lineas recuperan la direccion de memoria .data para el DS
MOV AX,@DATA
MOV DS,AX

inicio:
XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX
;CODIGO DEL PROGRAMA____________________________________________________
    MOV AH, 2Ah
    INT 21h
    
    MOV auxDia, AL
    MOV auxND, DL
    MOV auxMes, DH
    
    print msg1
        
    ;Lunes
    CMP auxDia,1
    JNE mar
    print lunes
    JMP Fuera    
        
    mar:
        CMP auxDia,2
        JNE mier
        print martes
        JMP Fuera     
    
    mier:
        CMP auxDia,3
        JNE jue
        print miercoles
        JMP Fuera
    
    jue:
        CMP auxDia,4
        JNE vie
        print jueves
        JMP Fuera
    
    vie:
        CMP auxDia,5
        JNE sab
        print viernes
        JMP Fuera
    
    sab:
        CMP auxDia,6
        JNE dom
        print sabado
        JMP Fuera
    
    dom:    
        print domingo
        JMP Fuera
    
    Fuera:
    
    
    
    XOR AH,AH
    MOV AL,auxND
    AAA   
    
    ADD AL,30h
    ADD AH,30h
    ;Imprimir caracter de las decenas del # del dia del mes
    MOV DL,AH
    MOV BL,AL
    MOV AH,02
    INT 21h 
    ;Imprimir caracter de las unidades del # del dia del mes
    MOV DL,BL
    INT 21h                                                 
    
    print msg2
    
    ;Enero
    CMP auxMes,01
    JNE feb
    print mes1
    JMP fueraM
    
    feb:
        CMP auxMes,02
        JNE march
        print mes2
        JMP fueraM
    
    march:
        CMP auxMes,03
        JNE abr
        print mes3
        JMP fueraM
        
    abr:
        CMP auxMes,04
        JNE may
        print mes4
        JMP fueraM
    
    may:
        CMP auxMes,05
        JNE jun
        print mes5
        JMP fueraM
    
    jun:
        CMP auxMes,06
        JNE jul
        print mes6
        JMP fueraM
    
    jul:
        CMP auxMes,07
        JNE ago
        print mes7
        JMP fueraM
    
    ago:
        CMP auxMes,08
        JNE sep
        print mes8
        JMP fueraM
    
    sep:
        CMP auxMes,09
        JNE oct
        print mes9
        JMP fueraM
    
    oct:
        CMP auxMes,10
        JNE nov
        print mes10
        JMP fueraM
    
    nov:
        CMP auxMes,11
        JNE dic
        print mes11
        JMP fueraM
        
    dic:
        print mes12
    
    
    fueraM:
    print msg2
    
    MOV AX,CX
    XOR DX,DX
    DIV auxDiv
    
    ADD DL,30h
    PUSH DX
    XOR DX,DX
    
    DIV auxDiv
    ADD DL,30h
    PUSH DX
    XOR DX,DX
    
    DIV auxDiv
    MOV BL,DL
    
    ;Impresion
    MOV DL,AL
    ADD DL,30H
    MOV AH,02
    INT 21H
    MOV DL,BL
    ADD DL,30H
    INT 21H
    
    POP DX
    INT 21H
    
    POP DX
    INT 21H
    
    
                                       
;FIN DEL PROGRAMA________________________________________________________
    ;Terminador de programa
    MOV AH, 4Ch
    INT 21h  
    
 END     








































































Generaciones x86.
    8086:	Para la compatibilidad y la creacion de sistemas informaticos se disponen los siguientes coprocesadores:
	    8089: E/S
	    8087: Matemático Coma Flotante
        El 8086 y 8088 se dividen en dos sub-procesadores:
        -	Unidad de Ejecución (EU): Realiza todas las operaciones.
        -	Unidad de Interfaz con el Bus (BIU): Accede a datos e instrucciones del mundo exterior.
        -	Unidad Aritmético Lógica (ALU): Realiza operaciones aritméticas y lógicas.
        Aportaciones:
        1.	Gestion de Memoria.
        2.	Segmentacion de 2 etapas (Buscar Instruccion | Ejecutar)
        3.	Interrupciones sectorizadas multinivel.
    
    80286:	Poseen dos modos de funcionamiento:
        Modo Real: Comportamiento igual al 8086 pero mas veloz, conectado a la alimentacion.
	    Modo Protegido: Capacidad multitarea y memoria virtual, toda extension se pone en marcha, pierde compatibilidad.
    
    80386:	Primer procesador de 32bits. Tiene tres modos posibles de funcionamiento:
        1)	Modo Real: Compatible con 8086
        2)	Modo Protegido: Rompe la barrera de los tradicionales segmentos.
        3)	Modo Virtual 86: Puede emular el funcionamiento simultaneo de varios 8086.
        La BIU ofrece pipelining de direcciones, tamaño dinámico del ancho de bus y señales de habilitación de bytes.
    
    80486:	Integra un cache de 8kb y coprocesador matemático (la mitad de las instrucciones se ejecutan en un ciclo reloj en vez de dos). Esta compuesto por las siguientes unidades:
            1.	Interconexion con el Bus.
            2.	Pre-Busqueda
            3.	Decodificación.
            4.	Control
            5.	Enteros y Comas Flotantes
            6.	Segmentación Y paginación
            7.	Cache
    
    Pentium:	Super Segmentación de 14 etapas.
        		Arquitectura super escalar.
        		Aumento de Caché
                El chip se empaqueta formato PGA (Pin Gris Array) de 273 pines
    
    Itanium:	Nace de la colaboracion Intel y Hp, primer procesador de 64 bits, compatible con la familia x86.
                Su arquitectura se denomina EPIC.
	            Memoria Caché de 3 niveles.

_____________________________________________________________________________________________________________________________________________________________________________________________


Taxonomia de Flynn.
    Se basa en el numero de flujos de instrucciones y flujos de datos que posee cada sistema computador. Existen 4 categorías:
        1.	SISD:	 SIMPLE flujo de INSTRUCCIONES y SIMPLE flujo de DATOS.
        2.	MISD:	 MULTIPLE flujo de INSTRUCCIONES y SIMPLE flujo de DATOS.
        3.	SIMD:	 SIMPLE flujo de INSTRUCCIONES y MULTILPLES flujos de DATOS.
        4.	MIMD:	 MULTIPLE flujo de INSTRUCCIONES y DATOS.
        *.	MTMD:    MULTIPLE flujo de TAREAS y DATOS.
_____________________________________________________________________________________________________________________________________________________________________________________________

Microprocesadores CISC y RISC.
    CISC:
    -	Formato de Instrucción de Longitud Variable.
    -	Gran juego de Instrucciones para dar respuesta a las necesidades del programador.
    -	Numero elevado de modos de direccionamiento.
    -	La Unidad de Control es Microprogramada.
    -	Procesa Instrucciones largas y de tamaño variable.

    RISC:
    -	Instrucciones de tamanio fijo y corto
    -	Juego de Instrucciones básicas y simples.
    -	Número reducido de modos de direccionamiento.
    -	Arquitectura tipo load-store.
    -	Amplio banco de registros.
    -	Instrucciones ejecutadas en pocos ciclos de reloj
    -	Facilita la segmentacion del ciclo de ejecución permitiendo simultaneidad de instrucciones
    -	La Unidad de Control es Cableada y Micro Programada.

_____________________________________________________________________________________________________________________________________________________________________________________________

Banderas de Registro Status.
    OF: Bit de OverFlow o Desbordamiento. (Indica desbordamiento de un bit de orden alto después de una operación)
    DF: Bit de Dirección (Designa la dirección [Creciente|Decreciente] [0|1] en operaciones con cadenas)
    IF Bit de Interrupción (Interrupción externa [Entrada de Teclado])
    TF: Bit Trap ó Desvío (Procesa o ignora la interrupción interna de trace)
    SF: Bit Signo (Indica el valor del bit más significativo del registro después de una operación aritmética o de desplazamiento)
    ZF: Bit Cero ( 1: resultado es cero, 0: resultado no es cero)
    AF: Bit Carry Auxiliar (1: se produce un acarreo del bit 3 al 4 en una operación aritmética)
    PF: Bit de Paridad (Se activa si el resultado de una operación aritmética tiene paridad par)
    CF: Bit Acarreo (Contiene el acarreo de una operación aritmética o de desplazamiento de bits)
_____________________________________________________________________________________________________________________________________________________________________________________________

Organizacion de la Memoria.
    Registros de Datos ó Generales:
    	AX: Acumulador principal, implicado en gran parte de las operaciones aritméticas y E/S.
    	BX: Registro de propósito general, se usa como índice en el direccionamiento indexado.
    	CX: Registro contador, ya que puede contener un valor para controlar el número de veces de una operación.
    	DX: Registro Datos, algunas operaciones E/S requieren su uso, MUL & DIV suponen su uso.
    
    Registros Punteros:
    	IP: Puntero de Instrucciones, contador del programa, contiene un valor de 16bits.
    	SP: Registro de la Pila.
    	BP: Base de la dirección de la pila.
    	SI: Indice fuerte requerido en algunas operaciones con cadenas, asociado con DS.
    	Di: Indice de Destino requerido en operaciones con cadenas, asociado con DS ó ES.
    
    Registros de Segmento:
    	CS: Segmento de Código, establece el area de memoria donde esta el programa en ejecución.
    	DS: Segmento de Datos, especifica la zona donde los programas leen y escriben sus datos.
    	SS: Segmento de Pila, permite la colocacion en memoria de una pila, para almacenamiento temporal de direcciones y datos.
    	ES: Segmento Extra, se suele utilizar en algunas operaciones con cadenas de caracteres para direccionar la memoria.
_____________________________________________________________________________________________________________________________________________________________________________________________

Modos de Direccion.
    Direccionamiento de Registro: Ambos operandos son registros			               [MOV AX, BX]
	Direcc Inmediato: El operando ORIGEN es constante				                   [MOV AX,500]
	Direcc Directo: Cuando el operando es una DIRECCION de memoria			           [MOV BX, [1000] ]
	Direcc Indirecto mediante Registro: Operando es una posición en registro		   [MOV AX,[BX] ]
	Direcc por Registro de Base: Operando en una posición apuntada por BX o BP	       [MOV AX,[BX +1]]
	Direcc Indexado: Operando obtenido como suma de un desplazamiento más índice	   [MOV AX, TABLA[DI]]
	Direcc Indexado respecto a Base: Obtenido de registro base + un índice		       [MOV AX, TABLA[BX][DI]]
	 
_____________________________________________________________________________________________________________________________________________________________________________________________

Estructura del Programa.
    MODEL: Directiva que define el modelo de memoria que debe usarse.
    	TINY: Programa para un solo segmento para datos y código.	
    	SMALL: Programa con un solo segmento de datos (64k, pila incluida) y otro código (64k)
    	LARGE: Varios segmentos de datos y código (1MB c/u)
    	MEDIUM: Varios Segmentos de código, 1 de datos.
    	COMPACT: Varios Segmentos de Datos, 1 de código.
    .STACK: Fija un tamaño en el segmento de pila, por defecto: 1k
    .DATA: Abre el segmento de datos.
    .CODE: Abre segmento de código (END al terminar).

    MACRO: Conjunto de sentencias de ensamblador, formado por: Cabecera, Cuerpo, Terminador.
   