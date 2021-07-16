.MODEL small 
.STACK 100h 
.DATA
	print_var dw ?
	ret_temp dw ?
	a_1 dw ?
	b_1 dw ?
	c_1 dw 3 dup(?)
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
main_proc PROC
	mov ax, @data
	mov ds, ax
	mov ax, 1
	mov a_1, ax
	mov ax, 3
	mov b_1, ax
	mov ax, 0
	mov ret_temp, ax
main_proc ENDP
END main_proc
