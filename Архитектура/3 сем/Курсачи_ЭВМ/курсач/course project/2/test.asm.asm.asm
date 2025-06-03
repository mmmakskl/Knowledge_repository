.MODEL tiny 
.STACK 100h

.DATA
txt db 10,13,"Hello there. Here is the key $",10,13
txt_ascii db 10,13,"ASCII: $",10,13
txt_scan db 10,13, "Scan: $", 10,13
buffer db 2 dup ('$')
number db 12
;buffer db "lol $",10,13

.CODE
mov ax, @Data
mov ds,ax 

xor ah,ah
mov al, number
mov bh, 0ah
div bh
mov bx,ax
mov dl,bl
add dl,'0'
mov ah,02h
int 21h
mov dl,bh
add dl,'0'
mov ah,02h
int 21h

mov ah, 4ch
int 21h

END