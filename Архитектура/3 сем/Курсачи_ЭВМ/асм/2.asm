DOSSEG
.MODEL tiny
.386
.STACK 100h
.DATA

 context_struct struc ;структура для хранения регистров
   rax  DW  ?
   rbx  DW  ?
   rcx  DW  ?
   rdx  DW  ?
   rds  DW  ?
   res  DW  ?
 context_struct ends

 context1 context_struct <> ;контекст 1-й задачи
 context2 context_struct <> ;контекст 2-й задачи
 context3 context_struct <> ;контекст 3-й задачи

 p1  DW  3 ;приоритет 1-й задачи
 p2  DW  2 ;приоритет 2-й задачи
 p3  DW  1 ;приоритет 3-й задачи
   
 handling_number  DW  32 ;количество обработок
 msg DB 'Press any key to change procedure',10,13,'$'

ORG 100h ;увеличивает смещение последующих команд на 256

 old_handler  DD  0 ;старый вектор

.CODE

proc1 proc
    ;загружаем регистры из контекста
    mov ax, context1.rax
    mov bx, context1.rbx
    mov cx, context1.rcx
    mov dx, context1.rdx
    mov ds, context1.rds
    mov es, context1.res

    mov al,'1' ;для вывода '1' с помощью int 29h

    ;после работы сохраняем регистры в контекст
    mov context1.rax, ax
    mov context1.rbx, bx
    mov context1.rcx, cx
    mov context1.rdx, dx
    mov context1.rds, ds
    mov context1.res, es
ret
proc1 endp

proc2 proc
    ;загружаем регистры из контекста
    mov ax, context2.rax
    mov bx, context2.rbx
    mov cx, context2.rcx
    mov dx, context2.rdx
    mov ds, context2.rds
    mov es, context2.res

    mov al,'2' ;для вывода '2' с помощью int 29h

    ;после работы сохраняем регистры в контекст
    mov context2.rax, ax
    mov context2.rbx, bx
    mov context2.rcx, cx
    mov context2.rdx, dx
    mov context2.rds, ds
    mov context2.res, es
ret
proc2 endp

proc3 proc
    ;загружаем регистры из контекста
    mov ax, context3.rax
    mov bx, context3.rbx
    mov cx, context3.rcx
    mov dx, context3.rdx
    mov ds, context3.rds
    mov es, context3.res

    mov al,'3' ;для вывода '3' с помощью int 29h

    ;после работы сохраняем регистры в контекст
    mov context3.rax, ax
    mov context3.rbx, bx
    mov context3.rcx, cx
    mov context3.rdx, dx
    mov context3.rds, ds
    mov context3.res, es
ret
proc3 endp
     
new_handler proc far
;алгоритм адаптивного планирования

;если приоритет 1-й задачи равен 0, то устанавливаем стандартные значения
    mov di,p1
    cmp di,0
    jne again
    mov di,3
    mov p1,di
    mov di,2
    mov p2,di
    mov di,1
    mov p3,di

;находим задачу с наибольшим приоритетом
again:
    mov si,p1
    mov di,p2
    cmp si,di
    jb m1
      ;p1 > p2
      mov dx,si
      jmp m2
    m1:
      ;p1 < p2 
      mov dx,di
    m2:
      mov si,p3
      cmp si,dx
      jb m3
        ;p3 > (p1|p2)
        mov dx,si
      m3:
        ;p3 < (p1|p2)

;после выбора задачи уменьшаем ее приоритет на 1
    cmp dx,si
      je l3
    cmp dx,di
      je l2
    mov si,p1
    cmp dx,si
      je l1
           
    l1: mov si,1
        mov di,p1
        dec di 
        mov p1,di
        jmp l4
    l2: mov si,2
        mov di,p2
        dec di
        mov p2,di
        jmp l4
    l3: mov si,3
        mov di,p3
        dec di
        mov p3,di
    l4:

;выход после handling_number обработок
    mov cx,handling_number
    dec cx
    mov handling_number,cx
    cmp cx,0
      jl exit ;<

repeat:
;выполняем процедуру с наивысшим приоритетом
    pusha ;загружаем в стек регистры общего назначения
    cmp si,1
      je t1
    cmp si,2
      je t2
    cmp si,3
      je t3
      
    t1: call proc1
        jmp print_task
    t2: call proc2
        jmp print_task
    t3: call proc3

 
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

