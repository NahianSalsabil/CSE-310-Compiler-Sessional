.MODEL small
.STACK 100h
.DATA
	print_var dw ?
	ret_temp dw ?
	a_1_1 dw ?
	k_1_1 dw ?
	t0 dw ?
	t1 dw ?
	t2 dw ?
	t3 dw ?
	t4 dw ?
	a_1_2 dw ?
	b_1_2 dw ?
	x_1_2 dw ?
	i_1_2 dw ?
	t5 dw ?
	t6 dw ?
	t7 dw ?
	t8 dw ?
	t9 dw ?
	t10 dw ?
	t11 dw ?
	t12 dw ?
	t13 dw ?
	a_1_3 dw ?
	b_1_3 dw ?
	i_1_3 dw ?
	t14 dw ?
	t15 dw ?
	t16 dw ?
	t17 dw ?
	t18 dw ?
	t19 dw ?
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
f PROC
	push ax
	push bx
	push cx
	push dx
	mov ax, 5
	mov k_1_1, ax
l2:
	mov ax, k_1_1
	cmp ax, 0
	jg l0
	mov t0, 0
	jmp l1
l0:
	mov t0, 1
l1:
	mov ax, t0
	cmp ax, 0
	je l3
	mov ax, a_1_1
	mov t1, ax
	inc a_1_1
	mov ax, k_1_1
	mov t2, ax
	dec k_1_1
	jmp l2
l3:
	mov ax, 3
	mov bx, a_1_1
	mul bx
	mov t3, ax
	mov ax, t3
	sub ax, 7
	mov t4, ax
	mov ax, t4
	mov ret_temp, ax
	mov ax, 9
	mov a_1_1, ax
	pop dx
	pop cx
	pop bx
	pop ax
	ret
f ENDP
g PROC
	push ax
	push bx
	push cx
	push dx
	push a_1_2
	mov ax, a_1_2
	mov a_1_1, ax
	call f
	mov ax, ret_temp
	mov t5, ax
	pop a_1_2
	mov ax, t5
	add ax, a_1_2
	mov t6, ax
	mov ax, t6
	add ax, b_1_2
	mov t7, ax
	mov ax, t7
	mov x_1_2, ax
	mov ax, 0
	mov i_1_2, ax
l10:
	mov ax, i_1_2
	cmp ax, 7
	jl l4
	mov t8, 0
	jmp l5
l4:
	mov t8, 1
l5:
	mov ax, t8
	cmp ax, 0
	je l11
	mov ax, i_1_2
	mov bx, 3
	xor dx, dx
	div bx
	mov t10, dx
	mov ax, t10
	cmp ax, 0
	je l6
	mov t11, 0
	jmp l7
l6:
	mov t11, 1
l7:
	mov ax, t11
	cmp ax, 0
	je l8
	mov ax, x_1_2
	add ax, 5
	mov t12, ax
	mov ax, t12
	mov x_1_2, ax
	jmp l9
l8:
	mov ax, x_1_2
	sub ax, 1
	mov t13, ax
	mov ax, t13
	mov x_1_2, ax
l9:
	mov ax, i_1_2
	mov t9, ax
	inc i_1_2
	jmp l10
l11:
	mov ax, x_1_2
	mov ret_temp, ax
	pop dx
	pop cx
	pop bx
	pop ax
	ret
g ENDP
main PROC
	mov ax, @data
	mov ds, ax
	mov ax, 1
	mov a_1_3, ax
	mov ax, 2
	mov b_1_3, ax
	push a_1_3
	push b_1_3
	mov ax, a_1_3
	mov a_1_2, ax
	mov ax, b_1_3
	mov b_1_2, ax
	call g
	mov ax, ret_temp
	mov t14, ax
	pop b_1_3
	pop a_1_3
	mov ax, t14
	mov a_1_3, ax
	mov ax, a_1_3
	mov print_var, ax
	call print
	mov ax, 0
	mov i_1_3, ax
l18:
	mov ax, i_1_3
	cmp ax, 4
	jl l12
	mov t15, 0
	jmp l13
l12:
	mov t15, 1
l13:
	mov ax, t15
	cmp ax, 0
	je l19
	mov ax, 3
	mov a_1_3, ax
l16:
	mov ax, a_1_3
	cmp ax, 0
	jg l14
	mov t17, 0
	jmp l15
l14:
	mov t17, 1
l15:
	mov ax, t17
	cmp ax, 0
	je l17
	mov ax, b_1_3
	mov t18, ax
	inc b_1_3
	mov ax, a_1_3
	mov t19, ax
	dec a_1_3
	jmp l16
l17:
	mov ax, i_1_3
	mov t16, ax
	inc i_1_3
	jmp l18
l19:
	mov ax, a_1_3
	mov print_var, ax
	call print
	mov ax, b_1_3
	mov print_var, ax
	call print
	mov ax, i_1_3
	mov print_var, ax
	call print
	mov ax, 0
	mov ret_temp, ax
main ENDP
END main
