.model small

.STACK

.DATA

vecDes  DB  0,15,99,10,56,98,01,02,03,54,63,21,99,14,0,0,1,2,3,4 ;20 elementos
conti   DW  1
contj   DW  0
aux     DB  0

.CODE
inicio:     

     MOV  AX,@DATA
     MOV  DS,AX
     

for1:
    
    CMP conti,13h
    JAE fin
    
    XOR AX,AX
    MOV contj,0
    
    for2:
        MOV AX,14h
        SUB AX,conti
    
        CMP AX,contj
        JBE finfor2
        
        MOV DI,contj
        MOV SI,DI
        INC SI
        
        MOV BL,vecDes[DI]        
        
        CMP BL,vecDes[SI]
        JA esmenor
        
        finmenor:
        
        INC contj
        
        JMP for2
    
    finfor2:
    
    INC conti
    
    JMP for1
    
esmenor:
    MOV BH,vecDes[SI]
    MOV vecDes[DI],BH
    MOV vecDes[SI],BL
    
    JMP finmenor
        
    
fin:

                  

     MOV  AH,4Ch            
     INT  21h                 

END