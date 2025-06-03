.MODEL Tiny
.386
.CODE

 thread_struct struc
   _ax      dw   ?       ;0
   _bx      dw   ?       ;2
   _cx      dw   ?       ;4
   _dx      dw   ?       ;6
   _ds      dw   ?       ;18
   _es      dw   ?       ;20
   thread_struct ends 
   
   thread1 thread_struct <>
   thread2 thread_struct <>
   thread3 thread_struct <>
   current_thread dw 0 ; current task

ORG	100h

  old_handler dd 0   
  rsi         dw    1   
  rdi         dw    2  

 
proc1 proc

      mov ax,thread1._ax
      mov bx,thread1._bx
      mov cx, thread1._cx   
      mov dx, thread1._dx
      mov ds, thread1._ds
      mov es, thread1._es
      
      mov al,'1'       
      

      mov thread1._ax, ax
      mov thread1._bx, bx
      mov thread1._cx, cx   
      mov thread1._dx, dx
      mov thread1._ds, ds
      mov thread1._es, es
ret
proc1 endp 

proc2 proc

      mov ax,thread2._ax
      mov bx,thread2._bx
      mov cx, thread2._cx   
      mov dx, thread2._dx
      mov ds, thread2._ds
      mov es, thread2._es
      
      mov al,'2'     
      

      mov thread2._ax, ax
      mov thread2._bx, bx
      mov thread2._cx, cx   
      mov thread2._dx, dx
      mov thread2._ds, ds
      mov thread2._es, es
ret
proc2 endp 

proc3 proc

      mov ax,thread3._ax
      mov bx,thread3._bx
      mov cx, thread3._cx   
      mov dx, thread3._dx
      mov ds, thread3._ds
      mov es, thread3._es
      
      mov al,'3'      
      

      mov thread3._ax, ax
      mov thread3._bx, bx
      mov thread3._cx, cx   
      mov thread3._dx, dx
      mov thread3._ds, ds
      mov thread3._es, es
ret
proc3 endp 
     
new_handler proc far
           
           
              mov si,rsi
              mov di,rdi
              
                add si,1  
 	        cmp di,0
 	        je m10
                cmp di,2 
 	        je m4 
                cmp si,2
 	        je m8
                cmp di,1
 	        je m7
                jmp m5
 	        m4:    sub si,2
         	       mov di,2
         	       cmp si,0
         	       je m9
                       jmp m5
                m7:
                        mov si,1
                        jmp m5
                m8:
                        mov si,3
                       	mov di,2
                        jmp m5
                m9:       
                        mov si,1
                        mov di,0                                                                                      
                        jmp m5
                m10:
                        mov di,1
                        jmp m5
 	        m5:
 	        
                mov rsi,si
                mov rdi,di
                mov current_thread,si
                ; print number of task
;            mov ax,si
;            mov dx,ax
; 	    add dx,30h            
;             mov ah,2h
;             int 21h

              ;vihod posle cx obrabotak
                add cx,-1
                cmp cx,0
                jle exit    ;< or = 
                
               jmp Repeat
                 
Repeat:
                pusha
                cmp si,2
                je   m1
                cmp si,1
                je m2
                cmp si,3
                je m6
                m1:
                     call proc2
      	            jmp m3
                m2:
                      call proc1
                	jmp m3
               	m6:
                	call proc3
                	jmp m3
                m3:
		int	29h            ; Vivodim '1' or '2' or '3'
                popa
	 mov al,20h
         out 20h,al       
		
         mov	ah,1
         int	16h       ; Check nashata li key
      jz	Repeat         ; repeat, if not pressed 
          
        iret
new_handler endp

Start:

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

       	mov thread1._ax, ax
      	mov thread1._bx, bx
	mov thread1._cx, cx   
	mov thread1._dx, dx
	mov thread1._ds, ds
	mov thread1._es, es
	
	mov thread2._ax, ax
      	mov thread2._bx, bx
	mov thread2._cx, cx   
	mov thread2._dx, dx
	mov thread2._ds, ds
	mov thread2._es, es
	
	mov thread3._ax, ax
      	mov thread3._bx, bx
	mov thread3._cx, cx   
	mov thread3._dx, dx
	mov thread3._ds, ds
	mov thread3._es, es
	
	mov current_thread,1

        mov cx,12       ; 6 paz smenit obrabotchik
        p:
       jmp p
       
    exit: 
    lds DX,old_handler ;Заполнение DS:DX из old
    mov AH, 25h ;Функция заполнения вектора
    mov AL,09h ;номер вектора
    int 21h
    
    mov	ax,4c00h
    int	21h
    

END		Start