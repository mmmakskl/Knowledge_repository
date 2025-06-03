.model small
.stack 2048

.data
buf db 259 dup(?) ;массив в который считаем строку максимальной длиной 255 из консоли,
                  ;так как мы это делаем по специальной функции с кодом 0Ah прерывания 21h то массив из 259 элементов
num_rep_sym db 52 dup(0) ;массив содержащий количество повторений символов
output_bufer db 259 dup(?) ;массив в который запишем букву,'|',а затем звездочки*кол_повт

.code
main:
     mov ax,@data
     mov ds,ax
     mov es,ax
;=====считывание в массив bufer строки из консоли=====
     mov buf,255
     lea dx,buf
     mov ah,0Ah   ;код функции прерывания 21h, которая считывает строку из консоли, надо обязательно в buf[0] указать макс длину строки             
     int 21h
;====перенос каретки консоли на новую строку дважды=====
     mov dl,10    ;10 ~ ENTER
     mov ah,2     ;код функци прерывания 21h вывода в консоль символа с кодом содержащимся в dl 
     int 21h
     mov dl,10
     mov ah,2
     int 21h
;=====подсчет символов=====
     mov bh,'a'-1 ;код символа перед a записываем в bh                       
     mov ah,0     ;номер элемента в массиве num_rep_sym
count_all_char:     
     lea si,buf[2] ;первый элемент исследуемой строки
     mov di,si
     cld
     add bh,1     ;код символа +1, то есть после первой итерации символ 'a'
     mov bl,0     ;запоминаем сюда количество повторений исследуемого символа
     xor cx,cx
     mov cl,buf[1] ;buf[1] - длина исследуемой нами строки
search_sym:
     lodsb ;считываем из массива в al
     cmp al,bh
     jne next_sym
     add bl,1 ;если находим искомый символ, то записываем в bl +1
next_sym:
     loop search_sym
     lea si,num_rep_sym[0] ;записываем si адрес нулевого элемента массива, в котором храним кол-во повторений символов
     mov di,si
     cld
     xor cx,cx
     mov cl,ah
mettn1:         ;прыгаем на элемнт массива num_rep_sym с количеством повторений нашего символа     
     inc di
     inc si
     loop mettn1
     lodsb
     mov al,bl
     stosb
     add ah,1
     cmp bh,'z'
     jne cmp_ah
     add bh,'A'-'z'-1
cmp_ah:
     cmp ah,53
     jne count_all_char
;=====конец подсчёта символов=====
;=====начало построения диаграммы=====
     mov bh,'a'-1
out_all_string:
;=====начало построения и вывода одной строки диаграммы=====
     add bh,1     
     xor cx,cx
     cmp bh,'Z'
     jna add1
     cmp bh,'z'
     jna add2
add1:
     add cl,bh
     add cl,26-'A'
     cmp cl,0
     jne diag
add2:
     add cl,bh
     add cl,-'a'
diag:
     lea si,num_rep_sym[0]
     mov di,si
     cld
mettn2:
     inc si
     loop mettn2
     lodsb
     mov bl,al ;записали в bl количество повторений нашего символа
     cmp bl,0
     je next_sym_out ;не выводим ничего, если символ ни разу не бфл введен в строке                
     lea si,output_bufer[0]
     mov di,si
     cld
     mov al,bh
     stosb
     mov al,'|'
     stosb
     xor cx,cx
     add cl,bl
write_star:
     mov al,'*'
     stosb
     loop write_star
     mov al,10
     stosb
     mov al,'$'
     stosb
     lea dx,output_bufer[0]
     mov ah,9
     int 21h
;=====конец построения и вывода одной строки диаграммы=====
;=====начало возвращения массив вывода к начальному состоянию=====
     lea si,output_bufer[0]
     mov di,si
     cld
     xor cx,cx
     mov cx,259
to_init_status:
     lodsb
     mov al,'?'
     stosb
     loop to_init_status
;=====конец возвращения массив вывода к начальному состоянию=====     
next_sym_out:
     cmp bh,'Z'
     jb out_all_string
     cmp bh,'Z'
     je end_out_diag
     cmp bh,'z'
     jb  out_all_string
     cmp bh,'z'
     je go_to_big_char2
go_to_big_char2:
     add bh,'A'-'z'-1
     cmp bh,'0'
     jne out_all_string
end_out_diag:     
;=====конец построения диаграммы=====
;=====выход из программы=====
     mov ax,4C00h
     int 21h
end main