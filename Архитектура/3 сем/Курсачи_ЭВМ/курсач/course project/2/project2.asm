.MODEL tiny 
.STACK 100h

.DATA
txt db 10,13,"Hello there. Here is the key $",10,13
txt_ascii db 10,13,"ASCII: $",10,13
txt_scan db 10,13, "Scan: $", 10,13
buffer db 10 dup ('$')
bufferend db 0

display_string macro string
  push ax
  push dx
  mov ah, 09h
  mov dx, offset string
  int 21h
  pop dx
  pop ax
endm

display_char macro char
  push ax
  push dx
  mov ah, 2
  mov dl, char
  int 21h
  pop dx
  pop ax
ENDM

read_key_codes macro
  xor ax,ax
  int 16h
ENDM 

to_decimal macro number
  local loop1
  local loop2
  ;push ax
  push bx
  push dx
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
   ; pop ax
ENDM
  

.CODE
mov ax, @Data
mov ds,ax   

read_key_codes

mov cx,ax

display_string txt

display_string txt_scan
to_decimal cx
display_char ch

display_string txt_ascii

display_char cl

mov ah, 4ch
int 21h
END