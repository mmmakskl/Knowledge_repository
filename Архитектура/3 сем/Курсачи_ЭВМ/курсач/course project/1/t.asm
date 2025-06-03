.MODEL tiny 
.STACK 100h

.DATA
BUFF DB 20
strr db 20 dup ("$")

.CODE
START:
MOV AX, @DATA
MOV DS, AX
MOV AH, 0Ah          
MOV DX, OFFSET buff  
INT 21h

MOV AH, 9      
MOV DX, OFFSET strr +1

INT 21h

MOV AX, 4C00h      
INT 21h
END START