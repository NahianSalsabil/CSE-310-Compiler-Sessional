.MODEL small 
.STACK 100h 
.DATA
	print_var dw ?
	ret_temp dw ?
	a_1 dw ?
	t0 dw ?
	a_2 dw ?
	b_2 dw ?
	x_2 dw ?
	t1 dw ?
	t2 dw ?
	t3 dw ?
	a_3 dw ?
	b_3 dw ?
	t4 dw ?
.CODE
print PROC
	push ax
	push bx 
	push cx
	push dx
	mov ax, print_var
	mov bx, 10
	mov cx, 0
printLabel1:
	mov dx, 0
	div bx
	push dx
	inc cx
	cmp ax, 0
	jne printLabel1
printLabel2:
	mov ah, 2
	pop dx
	add dl, '0'
	int 21h
	dec cx
	cmp cx, 0
	jne printLabel2
	mov dl, 0Ah
	int 21h
	mov dl, 0Dh
	int 21h
	pop dx
	pop cx
	pop bx
	pop ax
	ret
print endp
f_proc PROC
	push ax
	push bx
	push cx
	push dx
	push di
	mov ax, 2
	mov bx, a_1
	mul bx
	mov t0, ax
	mov ax, t0
	mov ret_temp, ax
	pop di
	pop dx
	pop cx
	pop bx
	pop ax
	ret
	mov ax, 9
	mov a_1, ax
f_proc ENDP
g_proc PROC
	push ax
	push bx
	push cx
	push dx
	push di
	push a_2
	push b_2
	push t0
	mov ax, a_2
	mov a_1, ax
	call f_proc 
	mov ax, ret_temp
	mov t1, ax
	pop t0
	pop b_2
	pop a_2
	mov ax, t1
	add ax, a_2
	mov t2, ax
	mov ax, t2
	add ax, b_2
	mov t3, ax
	mov ax, t3
	mov x_2, ax
	mov ax, x_2
	mov ret_temp, ax
	pop di
	pop dx
	pop cx
	pop bx
	pop ax
	ret
g_proc ENDP
main_proc PROC
	mov ax, @data
	mov ds, ax
	mov ax, 1
	mov a_3, ax
	mov ax, 2
	mov b_3, ax
	push t0
	push t1
	push t2
	push t3
	mov ax, a_3
	mov a_2, ax
	mov ax, b_3
	mov b_2, ax
	call g_proc 
	mov ax, ret_temp
	mov t4, ax
	pop t3
	pop t2
	pop t1
	pop t0
	mov ax, t4
	mov a_3, ax
	mov ax, a_3
	mov print_var, ax
	call print
	mov ax, 0
	mov ret_temp, ax
main_proc ENDP
END main_proc
