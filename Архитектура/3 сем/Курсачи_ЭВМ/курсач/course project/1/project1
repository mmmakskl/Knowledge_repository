DOSSEG
.MODEL TINY
.STACK 100h
.DATA
  buff db 20
  readMessage db 13,10,'Enter test string: ',13,10,'$'
  outputMessage db 13,10,'The string is: ',13,10 , '$'
  writeMessage db 20 dup ("$")
  db "$"
.CODE
mov ax, @Data
mov ds,ax   

mov dx, offset readMessage
mov ah, 09h
int 21h

mov ah, 0ah
mov dx, offset buff
int 21h
                            
mov ah,09h
mov dx, offset writeMessage
;mov si,ax
;mov writeMessage+si, '$'
;mov dx, offset writeMessage 
int 21h



mov ah,4ch
int 21h
END