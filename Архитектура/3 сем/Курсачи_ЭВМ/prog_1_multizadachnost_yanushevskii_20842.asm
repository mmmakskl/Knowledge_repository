.MODEL Tiny
.386

.CODE
;=====структура дл€ сохранени€ значени€ регистров=====
thread_struct struc
     myax dw ?       
     mybx dw ?       
     mycx dw ?       
     mydx dw ?       
     myds dw ?       
     myes dw ?
thread_struct ends 

;=====” нас есть 3 задачи, поэтому 3 структуры используем=====   
thread1 thread_struct <>
thread2 thread_struct <>
thread3 thread_struct <>
current_thread dw 0 ;текуща€ задача

ORG 100h

old_handler dd 0 ;стьарый массив
rsi dw 1 ;счЄтчик
rdi dw 2 ;используем дл€ переключени€ между задачами

;=====«адача 1===== 
proc1 proc
;=====записываем в регистры наши регистры структуры=====
      mov ax,thread1.myax
      mov bx,thread1.mybx
      mov cx,thread1.mycx   
      mov dx,thread1.mydx
      mov ds,thread1.myds
      mov es,thread1.myes
      
      mov al,'1'
      
;=====после выполнени€ записали регистры в наши регистры структуры=====
      mov thread1.myax,ax
      mov thread1.mybx,bx
      mov thread1.mycx,cx   
      mov thread1.mydx,dx
      mov thread1.myds,ds
      mov thread1.myes,es
      ret
proc1 endp 

;=====«адача 2=====
proc2 proc
      mov ax,thread2.myax
      mov bx,thread2.mybx
      mov cx,thread2.mycx   
      mov dx,thread2.mydx
      mov ds,thread2.myds
      mov es,thread2.myes
      
      mov al,'2'
      
      mov thread2.myax,ax
      mov thread2.mybx,bx
      mov thread2.mycx,cx   
      mov thread2.mydx,dx
      mov thread2.myds,ds
      mov thread2.myes,es
      ret
proc2 endp 

;=====«адача 3=====
proc3 proc
      mov ax,thread3.myax
      mov bx,thread3.mybx
      mov cx,thread3.mycx   
      mov dx,thread3.mydx
      mov ds,thread3.myds
      mov es,thread3.myes
      
      mov al,'3'
      
      mov thread3.myax,ax
      mov thread3.mybx,bx
      mov thread3.mycx,cx   
      mov thread3.mydx,dx
      mov thread3.myds,ds
      mov thread3.myes,es
      ret
proc3 endp 
     
new_handler proc far
      mov si,rsi
      mov di,rdi
      add si,1  
      cmp di,0
      je lable_10
      cmp di,2 
      je lable_4 
      cmp si,2
      je lable_8
      cmp di,1
      je lable_7
      jmp lable_5
lable_4:
      sub si,2
      mov di,2
      cmp si,0
      je lable_9
      jmp lable_5
lable_7:
      mov si,1
      jmp lable_5
lable_8:
      mov si,3
      mov di,2
      jmp lable_5
lable_9:       
      mov si,1
      mov di,0                                                                                      
      jmp lable_5
lable_10:
      mov di,1
      jmp lable_5
lable_5:   
      mov rsi,si
      mov rdi,di
      mov current_thread,si

;=====выход после обработки cx=====
      add cx,-1
      cmp cx,0
      jle exit ;меньше или равно 
      jmp Repeat
Repeat:
      pusha
      cmp si,2
      je lable_1
      cmp si,1
      je lable_2
      cmp si,3
      je lable_6
lable_1:
      call proc2
      jmp lable_3
lable_2:
      call proc1
      jmp lable_3
lable_6:
      call proc3
      jmp lable_3
lable_3:
      int 29h ;вывод текущей задачи или вывод '1','2' или '3'
      popa
      mov al,20h
      out 20h,al       
      mov ah,1
      int 16h ;проверка нажати€ клавиши
      jz Repeat ;переходим на метку repeat, если не нажата 
      iret
new_handler endp

main:
      mov ah,35h
      mov al,09h
      int 21h
      mov word ptr old_handler+2,es
      mov word ptr old_handler,bx
      push cs
      pop ds
      mov dx,offset new_handler
      mov ah,25h
      mov al,09h
      int 21h    
      mov si,1
      mov di,2

      mov thread1.myax,ax
      mov thread1.mybx,bx
      mov thread1.mycx,cx   
      mov thread1.mydx,dx
      mov thread1.myds,ds
      mov thread1.myes,es

      mov thread2.myax,ax
      mov thread2.mybx,bx
      mov thread2.mycx,cx   
      mov thread2.mydx,dx
      mov thread2.myds,ds
      mov thread2.myes,es
	
      mov thread3.myax,ax
      mov thread3.mybx,bx
      mov thread3.mycx,cx   
      mov thread3.mydx,dx
      mov thread3.myds,ds
      mov thread3.myes,es
	
      mov current_thread,1
      mov cx,12
cx_loop:
      jmp cx_loop
exit: 
      lds DX,old_handler ;«аполнение DS:DX из old
      mov AH,25h ;‘ункци€ заполнени€ вектора
      mov AL,09h ;номер вектора
      int 21h
    
      mov ax,4c00h
      int 21h
end main