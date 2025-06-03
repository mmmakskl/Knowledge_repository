model tiny
codeseg
org 100h
start:
                ; запоминаем адоес предыдущего обработчика 09h
                mov     ax,3509h    ; ah=35h     al=номер прерывания
                int     21h         ; считываем адрес старого обработчика
                                    ; bx-смещение es-сегментный адресс
                mov     [oldintr],bx
                mov     [oldintr+2],es
                
                ; устанавливаем свой обработчик
                mov     ax,2509h    ; ah=25h     al=номер прерывания
                mov     dx, offset my_handler
                int     21h    

                call    wt

                                                                                                                           jmp     $       

exit:
                mov     sp,0fffeh      ; указатель на вершину стека

                mov     dx,[oldintr]    
                mov     ax,[oldintr+2]  
                mov     ds,ax          
                mov     ax,2509h       
                int     21h            ; восстанавливаем старый обработчик 

                mov     al,20h
                out     20h,al         ; конец прерывания
                ret
my_handler:
                in      al,60h
                                      ; замена скан-кодов Del на Ins
                cmp     al,53h        ; замена скан-кодов при нажатии
                je      repdelm
                cmp     al,52h
                je      repinsm
                cmp     al,0d3h       ; замена скан-кодов при отпускании
                je      repdelb
                cmp     al,0d2h
                je      repinsb
bck:            
                mov     bl,al
                test    bl,80h
                jz      sound
                
                cmp     bl,08eh       ; если отпущен backspace запускаем счетчик
                jne     counter
 
                inc     cl
                cmp     cl,2          ; 2 раза нажали на backspace 
                je      exit          ; возвращаем старый обработчик
                jmp     sound
counter:
                mov     cl,0
sound:
                
                push cx
                push ax
                ;push dx
                ;call beep
                in    al,61H		; включаем динамик
	        or    al,03H		
          	out   61H, al		
	        mov   cx,9000H		
delay:
	        loop  delay		; задержка
	        and   al,0fcH		; выключаем динамик
	        out   61H, al
                ;pop dx
                pop ax
                pop cx
                
                push    ax
                shr     al,4
                call    create

                pop     ax
                and     al,0fh
                call    create

                mov     dl,' '
                call    print
 
                mov     al,20h
                out     20h,al         ; конец прерывания
                iret
create:
                or      al,00110000b   ; преобразуем в ASCII
                cmp     al,'9'
                jbe     pr
                add     al,'A'-'9'-1
pr:
                mov     dl,al
print:
                mov     ah,6
                int     21h
                ret
wt:
                push    cx
                xor     cx,cx
wait_loop:
                in      al,64h          ; состояние процессора
                and     al,10b          ; флаг готовности
                                        ; проверяем состояние очереди команд процессора    
                loopnz  wait_loop
                pop     cx
                ret
repdelm:
                mov     al,52h
                jmp     bck
repinsm:           
                mov     al,53h
                jmp     bck  
repdelb:
                mov     al,0d2h
                jmp     bck
repinsb:        
                mov     al,0d3h
                jmp     bck                                                               
;beep    proc       near
;                mov     al,10110110b    ; канал 2, режим 3
;                out     43h,al
;                mov     al,0Dh          ; младший байт делителя частоты 11D0h
;                out     42h,al
;                mov     al,11h          ; старший байт делителя частоты
;                out     42h,al
;                in      al,61h               
;                or      al,00000011b    ; включаем динамик
;                out     61h,al          
;                mov     cx,0007h        ; задержка
;                mov     dx,0A120h            
;                mov     ah,86h           
;                int     15h              

;                in      al,61h          ; отключаем динамик
;                and     al,11111100b    
;                out     61h,al          
;                ret
;beep    endp

oldintr dw ?
end start