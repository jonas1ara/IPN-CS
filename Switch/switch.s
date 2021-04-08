	.file	"switch.c"
	.text
	.section	.rodata
.LC0:
	.string	"Enter a number:"
.LC1:
	.string	"%i"
.LC2:
	.string	"You chose the case #1"
.LC3:
	.string	"You chose the case #2"
.LC4:
	.string	"You chose the case #3"
.LC5:
	.string	"You chose the case #4"
.LC6:
	.string	"You chose the case #5"
	.align 8
.LC7:
	.string	"We didn't find your case... :/"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$.LC0, %edi
	call	puts
	leaq	-4(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-4(%rbp), %eax
	cmpl	$5, %eax
	ja	.L2
	movl	%eax, %eax
	movq	.L4(,%rax,8), %rax
	jmp	*%rax
	.section	.rodata
	.align 8
	.align 4
.L4:
	.quad	.L2
	.quad	.L8
	.quad	.L7
	.quad	.L6
	.quad	.L5
	.quad	.L3
	.text
.L8:
	movl	$.LC2, %edi
	call	puts
	jmp	.L9
.L7:
	movl	$.LC3, %edi
	call	puts
	jmp	.L9
.L6:
	movl	$.LC4, %edi
	call	puts
	jmp	.L9
.L5:
	movl	$.LC5, %edi
	call	puts
	jmp	.L9
.L3:
	movl	$.LC6, %edi
	call	puts
	jmp	.L9
.L2:
	movl	$.LC7, %edi
	call	puts
	nop
.L9:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.0.1 20210324 (Red Hat 11.0.1-0)"
	.section	.note.GNU-stack,"",@progbits
