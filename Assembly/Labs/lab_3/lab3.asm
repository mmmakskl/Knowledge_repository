%macro putchar 1 
    push eax
    push ebx
		push ecx
    push edx
    push %1         
    mov   eax, 4      ; системный вызов write
    mov   ebx, 1      ; stdout 
    mov   ecx, esp    ; ecx указывает на символ
    mov   edx, 1      ; edx количество символов для вывода
    int   80h         ; при необходимости sys_writ восстановит esp(1, "A", 1)
    ; возвращает значение в EAX = 1 (записанный байт) или ошибку (-errno)
		add esp, 2        ; востановление esp при необходимости	
    pop edx
    pop ecx
    pop ebx
    pop eax
%endmacro

global _start

section .data
B dw 1, 2, 0, -5, 12, -45, 123, -1234, 30001
A dw 0 dup(9)

section .text
_start:

mov esi, B            ; загружаем адрес массива B в регистр ESI
mov edi, A            ; загружаем адрес массива A в регистр EDI
mov ecx, 9            ; количество элементов массива

copy_loop:
	mov ax, [esi]      ; загружаем элемент из массива B в регистр AX
	mov [edi], ax      ; копируем значение из AX в массив A
	add esi, 2         ; перемещаем указатель ESI к следующему элементу (размер слова - 2 байта)
	add edi, 2         ; перемещаем указатель EDI к следующему элементу
	dec ecx            ; уменьшаем счетчик элементов
jnz copy_loop          ; повторяем цикл, пока не скопируем все 9 элементов

mov esi, A            ; устанавливаем указатель на массив A
mov ecx, 9            ; размер массива (количество элементов)

array_loop:
    mov eax, [esi]    ; загружаем элемент из массива A в EAX
    test ax, ax       ; проверяем, является ли число отрицательным
    jns if_unsigned   ; если положительное (флаг знака не установлен), переходим к if_unsigned
        mov bx, '-'   ; если число отрицательное, выводим знак минус
        putchar bx    ; выводим символ '-'
        neg ax        ; инвертируем знак числа

		if_unsigned:
				mov bx, 10        ; делим на 10 для получения цифр
				xor di, di        ; DI — счетчик цифр

		div_loop:
				xor dx, dx        ; очищаем старшую часть для деления 32-разрядного числа
				div bx            ; делим AX на 10 (остаток в DX, результат в AX)
				push dx           ; сохраняем цифру (остаток от деления) в стек
				inc di            ; увеличиваем счетчик цифр
				cmp ax, 0         ; если AX не равен 0, продолжаем делить
		jnz div_loop
		
		print_digits_loop:
				pop ax            ; извлекаем цифру из стека
				add ax, '0'       ; преобразуем цифру в ASCII
				putchar ax        ; выводим цифру
				dec di            ; уменьшаем счетчик
		jnz print_digits_loop ; повторяем, пока все цифры не будут выведены

    mov bx, ' '       ; вывод пробела
    putchar bx

		add esi, 2            ; переходим к следующему элементу массива (на 2 байта вперед)
dec ecx               ; уменьшаем счетчик
		jnz array_loop        ; повторяем цикл для каждого элемента массива

mov bx, 10
putchar bx

; system exit
mov eax,1            
mov ebx,0            
int 80h
