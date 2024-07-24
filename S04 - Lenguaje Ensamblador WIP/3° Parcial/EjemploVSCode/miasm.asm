;Secciones
;Datos,almacenamientos de memoria o codigo
section .text ;esta es la seccion de codigo
global _sumaASM

_sumaASM:
    PUSH EBP    

    MOV EBP, ESP
    MOV EAX,[EBP + 8];se pasa el parametro a de la funcion
    ADD EAX,[EBP + 12];se pasa el parametro b de la funcion

    POP EBP
    RET