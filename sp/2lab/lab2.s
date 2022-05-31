.section .data
print_format:
.string "%d "
mas:
.long 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
mas_end:

.section .text
.global main
.type main, @function

main:
	movl $mas, %ebx

edit:
	movl (%ebx), %eax
	shl $1, %eax
	movl %eax, (%ebx)
	cmpl $mas_end, %ebx
	je new_mas
	addl $4, %ebx
	movl (%ebx), %eax
	sar $1, %eax
	movl %eax, (%ebx)
	cmpl $mas_end, %ebx
	je new_mas
	addl $4, %ebx
	jmp edit

new_mas:
	addl $-40, %ebx

print:
	push (%ebx)
	push $print_format
	call printf
	addl $8, %esp
	addl $4, %ebx
	cmp $mas_end, %ebx
	jne print
	ret
