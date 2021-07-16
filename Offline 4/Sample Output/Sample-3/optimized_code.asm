.MODEL small
.stack 100H
.DATA
a2 dw ?
b2 dw ?
c2 dw 3 dup ($)
t0 dw ?
t1 dw ?
t2 dw ?

.CODE
main proc
mov ax,@data
mov ds,ax

mov t0,1
mov ax,t0
mov a2,ax
mov t1,3
mov ax,t1
mov b2,ax
mov t2,0
mov cx,t2
jmp L0
L0:

mov ah,4ch
int 21h
main endp
end main

