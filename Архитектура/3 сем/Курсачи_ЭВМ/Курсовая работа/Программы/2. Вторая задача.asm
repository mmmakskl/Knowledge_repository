.model large
code segment
assume cs:code, ds:code, es:code, ss:code
org 100h
start:
 
 ;Перейти на начало
 jmp beg
 
 print_symbol:
 ;Распечатать символ
  push ax
  push dx
  mov ah, 02h
  mov dl, dh
  cmp dl, 0
  je t2
  int 21h
  t2:
  pop dx
  int 21h
  pop ax
  ret
 
 print_number:
  ;Распечатать число, base = 10 
  push ax
  push bx
  push cx
  push dx
  mov ax, dx
  mov bx, 10
  mov cx, 0
  getdigits:
   mov dx, 0
   div bx
   inc cx
   add dx, 30h
   push dx
   cmp ax, 0
   jnz getdigits
  mov ah, 02h
  printdigits:
   pop dx
   int 21h
   loop printdigits
  pop dx
  pop cx
  pop bx
  pop ax
  ret
 
 debug:
  ;Сохранить регистры, запретить прерывания
  cli
  push bp
  mov bp, sp
  push ax
  push bx
  push cx
  push dx
  push si
  ;Вывести ip и ax
  mov dx, '['
  call print_symbol
  mov dx, [bp+2]
  call print_number
  mov dx, ','
  call print_symbol
  mov dx, [bp-2]
  call print_number
  mov dx, ']'
  call print_symbol
  mov dx, etr
  call print_symbol 
  ;Ожидать нажатие клавиши
  xor ax, ax
  int 16h
  ;Восстановить регистры, разрешить прерывания
  pop si
  pop dx
  pop cx
  pop bx
  pop ax
  pop bp
  sti
  iret
 
 ;Отлаживаемая программа
 thread:
  mov ax, 1
  mov cx, 10
  t1:
   add ax, ax
   loop t1
  ret
 
 beg:
  ;Сохранить старый обработчик
  mov ax, 3501h
  int 21h
  mov int1, bx
  mov int1+2, es
  ;Установить новый обработчик
  push cs
  pop ds
  mov dx, offset debug
  mov ax, 2501h
  int 21h
  ;Сохранить парамеры для возврата
  pushf
  push offset exit
  ;Установит TF флаг
  pushf
  pop ax
  or ax, 100h
  push ax
  push cs
  push offset thread
  iret
  
 exit:
  popf
  ;Установить старый обработчик
  lea dx, int1 
  mov ax, 2501h
  int 21h
  ;Выход после нажатия клавиши
  mov ah, 01h
  int 21h
  int 20h

int1 dw 0h, 0h
etr dw 0Ah, 0Dh
 
code ends
end start
print_task:
;вывод слова 'task'
    push ax
    mov al,'t'
    int 29h
    mov al,'a'
    int 29h
    mov al,'s'
    int 29h
    mov al,'k'
    int 29h
    mov al,' '
    int 29h
    pop ax

    int 29h ;вывод '1', '2' или '3' из регистра al
    mov al,10 ;перенос строки
    int 29h
    popa ;выгружаем из стека регистры общего назначения

;сброс контроллера прерываний
    mov al,20h 
    out 20h,al

;проверка нажата ли клавиша
    mov ah,1
    int 16h
    jz repeat ;повторяем, если не нажали

iret
new_handler endp

main:
;вывод приветсвенного собщения
    mov dx,offset msg
    add dx,100h
    mov ah,9
    int 21h

;сохраним текущий вектор прерывания с помощью int 21h 
;вход: AH = 35h, AL = номер вектора прерывания
;выход: ES:BX = адрес программы обработки прерывания
;в BX заносится содержимое адреса 0:(4*AL), в ES - 0:(4*AL+2)
    mov ah,35h
    mov al,09h
    int 21h
    mov word ptr old_handler+2,es
    mov word ptr old_handler,bx

;установим новый вектор прерывания с помощью int 21h 
;вход: AH = 25H, AL = номер прерывания (от клавиатуры 09h)
;DS:DX = вектор прерывания: адрес программы обработки прерывания
    push cs
    pop ds
    mov dx,offset new_handler
    mov ah,25h
    mov al,09h
    int 21h
 
;сохраняем регистры во все контексты
    mov context1.rax, ax
    mov context1.rbx, bx
    mov context1.rcx, cx
    mov context1.rdx, dx
    mov context1.rds, ds
    mov context1.res, es

    mov context2.rax, ax
    mov context2.rbx, bx
    mov context2.rcx, cx
    mov context2.rdx, dx
    mov context2.rds, ds
    mov context2.res, es

    mov context3.rax, ax
    mov context3.rbx, bx
    mov context3.rcx, cx
    mov context3.rdx, dx
    mov context3.rds, ds
    mov context3.res, es

    infinity: jmp infinity ;бесконечный цикл

exit:
;вернуться к старому обработчику прерывания (заполнение DS:DX из old)
    lds dx,old_handler
    mov ah,25h ;функция заполнения вектора
    mov al,09h ;номер вектора
    int 21h

    mov ah,4ch ;функция DOS завершения программы
    int 21h ;завершить программу

END main
