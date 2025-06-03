.MODEL small 
.STACK 100h

.DATA
txt db "Hello there. Here is the key $"
txt_ascii db "ASCII: $"
txt_scan db "Scan: $"
buffer db 10 dup ('$')
bufferend db 0

new_line macro
  push ax
  push dx
  mov ah, 2
  mov dl,10
  int 21h
  mov dl,13
  int 21h
  pop dx
  pop ax
ENDM  

display_string macro string
  push ax
  push dx
  mov ah, 09h
  mov dx, offset string
  int 21h
  new_line
  pop dx
  pop ax
endm

display_char macro char
  push ax
  push dx
  mov ah, 2
  mov dl, char
  int 21h
  new_line
  pop dx
  pop ax
ENDM

read_key_codes macro
  xor ax,ax
  int 16h
ENDM 

to_decimal macro number
  push bx
  push dx
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
  new_line 
  pop dx
  pop bx
ENDM
  

.CODE
mov ax, @Data
mov ds,ax   
mainLoop:
read_key_codes

mov dx,ax

display_string txt

display_string txt_scan

to_decimal dh

display_string txt_ascii

display_char dl
cmp dh,01h
jz exit
jmp mainLoop
exit:
mov ah, 4ch
int 21h
END