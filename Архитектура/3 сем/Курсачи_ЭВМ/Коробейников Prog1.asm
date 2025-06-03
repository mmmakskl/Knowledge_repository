DOSSEG
.model TINY                        
.data

array db "ABCD      ",10,13
      db "OIHVIOHVXI",10,13
      db "GDGDFGDFG ",10,13
      db "ALL       ",10,13
      db "ALL       ",10,13
      db "JACK      ",10,13
      db "JANE      ",10,13
      db "SMITH     ",10,13  
      db "BROWN     ",10,13
      db "BSGSGSDG  ",10,13   
      db "XCBVXFBXF ",10,13  
      db "DGDGDGDGDG",10,13  
      db "AATTT     ",10,13  
      db "WHITE     ",10,13 
      db "BLACK     ",10,13  
      db "YELLOW    ",10,13
      db "RED       ",10,13 
      db "BROWN     ",10,13
      db "FFF       ",10,13
      db "RGB       ",10,13        
      db "$"
array2 db "          ",10,13
      db "          ",10,13
      db "          ",10,13
      db "          ",10,13
      db "          ",10,13
      db "          ",10,13
      db "          ",10,13
      db "          ",10,13
      db "          ",10,13
      db "          ",10,13
      db "          ",10,13
      db "          ",10,13
      db "          ",10,13
      db "          ",10,13
      db "          ",10,13
      db "          ",10,13
      db "          ",10,13
      db "          ",10,13
      db "          ",10,13
      db "          ",10,13    
      db "$"

                                                                                          
string db "---------------------$",10,13
       db "$", 10, 13
.code


swap:
pop dx
pop bx 
push dx
mov cx, 12d 
for:
push bx
add bx, cx
dec bx
mov al, [bx] 
mov dl, [bx+12d]
mov [bx], dl
mov [bx+12d], al
pop bx
loop for
ret 


start:
mov ax, @data
mov ds, ax


 mov dx, offset array
 mov ah, 9h
 int 21h   

  mov dx, offset string
 mov ah, 9h
 int 21h   
 
mov cx, 19d
loop2:
push cx
mov bx, offset array

mov cx, 19d
mov di, offset array  
mov si,10
loop1:

mov al, [bx+12d]
mov ah, [bx]
cmp al, ah 
je m1      
cmp al, ah 
jb inc_str 
mov bx,di
push bx
push cx
push bx
call swap
pop cx
pop bx
mov di,bx
jmp inc_str  
  m1: 
  add bx,1d
  sub si,1
  cmp si,0
  jne loop1

  jmp inc_str
inc_str:
mov bx,di
add bx, 12d
mov di,bx
loop loop1

pop cx
loop loop2

 mov bx, offset array
 mov di, offset array2
 mov dx, offset array
 mov cx,20d
 jmp lfirs
lfirs:
  mov si,6
  jmp l1
  l1:
  mov al, [bx+12d]
  mov ah, [bx]
  cmp al, ah 
  je lsecond    
  mov bx,dx
  mov si,12
       ll:
         mov al,[bx]
         mov [di],al
         add di,1d
         add bx,1d
         sub si,1
         cmp si,0
       jne ll
       jmp next
   next:
   mov bx,dx
   add bx,12d
   mov dx,bx  
loop lfirs
jmp exit
lsecond: 
   add bx,1
   sub si,1
   cmp si,0                                                                                                         
   jne l1 
   jmp next
 
exit:
mov dx, offset array
mov ah, 9h
int 21h  
  
mov dx, offset string
 mov ah, 9h
 int 21h   

mov dx, offset array2
mov ah, 9h
int 21h   

mov ah, 4ch
int 21h

end start