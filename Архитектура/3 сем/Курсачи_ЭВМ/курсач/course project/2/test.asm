.MODEL tiny 
.STACK 100h

.DATA
txt db 10,13,"Hello there. Here is the key $",10,13
txt_ascii db 10,13,"ASCII: $",10,13
txt_scan db 10,13, "Scan: $", 10,13
;buffer db 2 dup ('$')
buffer db "lol $",10,13

to_decimal macro number
  local loop1
  local loop2
  push ax
  push bx
  push dx
  mov ah,0
  mov al,number
  lea si, buffer
  mov cx,0
  mov bx,10
  
  loop1:
    mov dx,0
    div bx
    add dl,30h
    push dx
    inc cx
    cmp ax,9
    jg loop1
    
    add al,30h
    mov [si],al
  loop2:
    pop ax
    inc si
    mov [si],al
    loop loop2
    
    pop dx
    pop bx
    pop ax
ENDM
.CODE
xor ax,ax
;mov ah, 41h
;to_decimal ah
;mov cl,ah
;mov dl,cl
;mov ah, 2
;int 21h

mov dx, offset txt
mov ah,09h
int 21h

mov ah, 4ch
int 21h

END