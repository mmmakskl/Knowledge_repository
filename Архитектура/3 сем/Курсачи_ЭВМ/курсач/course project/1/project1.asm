DOSSEG
.MODEL TINY
.STACK 100h
.DATA

.CODE
mov ah,1
int 21h
mov ah,2
mov dl,'A'
int 21h


mov ah,4ch
int 21h
END