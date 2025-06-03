.MODEL tiny 
.STACK 100h

.DATA
inputP db 7 
      db ? 
      db 7 dup(0)

inputD db 9 
      db ? 
      db 9 dup(0)
passed db "passed"
greetingsMsg db "Press 'p' to choose, which student has passed. Press 'd' to write the date. $"
inputPassMsg db "Write 'passed'.$"
inputDateMsg db "Write date like this: xx.xx.xx$"
choiceMsg db "Write number from 01 to 13 to choose student.$"

columnNames db "N  Full name       Record   Passed Date $" 
errorMessage db "error.$"
student01 db "01 Avikson S.A.    32427695",' ', 6 dup('x'), ' ', 8 dup('x'),0ah,'$'
student02 db "02 Borotskiy I.A.  14607899",' ', 6 dup('x'), ' ', 8 dup('x'),0ah,'$'
student03 db "03 Vetkin M.S.     35738839",' ', 6 dup('x'), ' ', 8 dup('x'),0ah,'$'
student04 db "04 Koba T.V.       94851874",' ', 6 dup('x'), ' ', 8 dup('x'),0ah,'$'
student05 db "05 Koltsov A.A.    04648339",' ', 6 dup('x'), ' ', 8 dup('x'),0ah,'$'
student06 db "06 Lashkov S.K.    83502426",' ', 6 dup('x'), ' ', 8 dup('x'),0ah,'$'
student07 db "07 Luneva A.V.     03440337",' ', 6 dup('x'), ' ', 8 dup('x'),0ah,'$'
student08 db "08 Savinkov K.R.   40111800",' ', 6 dup('x'), ' ', 8 dup('x'),0ah,'$'
student09 db "09 Sokolov D.D.    93356831",' ', 6 dup('x'), ' ', 8 dup('x'),0ah,'$'
student10 db "10 Filippova K.A.  90679506",' ', 6 dup('x'), ' ', 8 dup('x'),0ah,'$'
student11 db "11 Frolova A.U.    43164052",' ', 6 dup('x'), ' ', 8 dup('x'),0ah,'$'
student12 db "12 Shevtsov D.U.   48985359",' ', 6 dup('x'), ' ', 8 dup('x'),0ah,'$'
student13 db "13 Yanushenko M.U. 24433510",' ', 6 dup('x'), ' ', 8 dup('x'),0ah,'$'
students dw offset student01, offset student02, offset student03, offset student04, offset student05, offset student06, offset student07, offset student08, offset student09, offset student10, offset student11, offset student12, offset student13

tmpNum db ?
               
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
   
printChart macro
  LOCAL arrayLoop
  push bx
  push cx
  push ax  
  
  display_string columnNames
  mov bx, offset students
  mov cx,13  
  arrayLoop:
  mov dx,[bx]
  mov ah,9
  int 21h
  add bx,2
  loop arrayLoop
  
  pop ax
  pop cx
  pop bx
ENDM 

readString macro buffer,bufWidth
  push ax
  push dx
  push si
  push cx
  push bx
  
  mov ah, 0ah
  mov dx, offset buffer
  int 21h

  mov si, offset buffer
  add si, bufWidth+2
  mov al,'$'
  mov [si],al
  display_string buffer
    
  pop bx
  pop cx
  pop si
  pop dx
  pop ax
ENDM

chooseArrayElement macro array
LOCAL loopn, pname
  push ax
  push bx
  push cx
  
  display_string choiceMsg
  mov ah,01h
  int 21h
  sub al,30h

  mov bl,0ah
  mul bl

  mov tmpNum,al
  mov ah,01h
  int 21h
  sub al,30h

  add tmpNum,al
                    
  mov al, tmpNum
  
  mov dx,0
  mov ah,1
  mov cx,2
loopn:
  cmp ah,al
  je pname
  add dx,2
  
  inc ah
  cmp ah,0dh
  jne loopn

  pop cx
  pop bx
  pop ax
pname:
  
endm

replaceArrayString macro string,destArr,destOffset,charNumber
push si
push di
push cx

lea si, string
mov di, destArr 
add di,destOffset
mov cx, charNumber
rep movsb
new_line
pop cx
pop di
pop si
endm

place macro position,length,buffer
  push bx
  push dx
  
  readString buffer length 
  chooseArrayElement students
  mov bx, offset students
  add bx,dx
  replaceArrayString buffer+2 [bx] position length 
  printChart
  pop dx
  pop bx
endm

placePass macro position,length,string
  push bx
  push dx
  
  chooseArrayElement students
  mov bx, offset students
  add bx,dx
  replaceArrayString string [bx] position length
  printChart
  pop dx
  pop bx
endm

.CODE
mov ax, @Data
mov ds,ax  
mov es,ax 

mainLoop:
display_string greetingsMsg
new_line

printChart
xor ax,ax
mov ah,0
int 16h

cmp ah,19h ;19h - p
je skipPassedInput
jmp inputDate
skipPassedInput:

placePass 28 6 passed
jmp mainLoop

inputDate:
cmp ah,20h
je skipDateInput
jmp exit
skipDateInput:
display_string inputDateMsg
place 35 8 inputD
jmp mainLoop
cmp ah,01h
je exit
jmp mainLoop
exit:
mov ah, 4ch
int 21h
END