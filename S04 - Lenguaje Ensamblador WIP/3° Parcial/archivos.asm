;FCB    File Control Block
;Handles o FIle Handler

.model small
     
;Segmento de Pila
.stack ;200h ;por defaulf es 100h
                 
;Segmento de Datos                 
.data

dir1    DB  "b:\4CSys",0
file1   DB  "b:\4CSys\prueba.txt",0
handler DW  ?

msj     DB  "Wenas o/",'$'
msjTam = $ - OFFSET msj     ;constante
msjErr  DB  "Error, mejor no debiste nacer :)",'$'


;Segmento de codigo
.code              


;Esto recupera la direccion de memoria .data para el DS
MOV AX,@DATA
MOV DS,AX

inicio:

    ;manejar directorios
    ;Funcion 39h de la INT 21h
    MOV AX,39h
    MOV DX,OFFSET dir1
    INT 21h

    ;Manejador de archivos
    ;funcion 3Ch de la INT 21h
    ;Crea archivo
    MOV AH,3Ch
    MOV CX,0    ;Atributo del archivo
                ;0=Normal, 2=Oculto, 4=Sistema, 6=Oculto y de sistema
    MOV DX,OFFSET file1
    INT 21h
    
    ;Cuando todo OK
    ;en CF=0, AX=Handler del archivo
    
    ;Cuando no OK
    ;en CF=1, AX=Codigo de error
                ;3=ruta no encontrada
                ;4=no hubo handler para asignar
                ;5=acceso denegado
    JC error
    MOV handler,AX
    
    ;funcion 40h de la INT 21h
    ;escribir en el archivo
    MOV AH,40h
    MOV BX,handler
    MOV CX,msjTam
    MOV DX,OFFSET msj
    INT 21h
    
    ;Cuando todo OK
    ;en CF=0, AX=bites escritos

    ;Cuando no OK
    ;en CF=1, AX=cosigo de error
                ;5=acceso nagado
                ;6=handler erroneo
    
    ;Funcion 3Eh de la INT 21h
    ;cerrar archivo
    MOV AH,3Eh
    MOV BX,handler
    INT 21h
    
    ;Funcion 41h dela INT 21h
    ;eliminar archivo
    MOV AH,41h
    MOV BX,OFFSET file1
    INT 21h

    ;Funcion 41h dela INT 21h
    ;Elimina Directorio    
    MOV AH,3Ah
    MOV BX,OFFSET dir1
    INT 21h
    
error:

    MOV AH,09
    MOV DX,OFFSET msjErr
    INT 21h
    JMP fin
    
fin:    
           
    ;Terminador de programa          
    MOV AH,4Ch
    INT 21h                
    
END