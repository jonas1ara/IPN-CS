	.file	"arithmetic.c"
	.text
	.section	.rodata
.LC0:
	.string	"Enter a number:"
.LC1:
	.string	"%d"
.LC2:
	.string	"Enter the second number:"
	.align 8
.LC3:
	.string	"The result of the operation is: %d\n"
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
	subq	$32, %rsp
	movl	$2, -4(%rbp)
	movl	$3, -8(%rbp)
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-16(%rbp), %edx
	movl	-20(%rbp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	-4(%rbp), %eax
	cltd
	idivl	-8(%rbp)
	movl	%eax, %ecx
	movl	-16(%rbp), %edx
	movl	-20(%rbp), %eax
	addl	%edx, %eax
	imull	%ecx, %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Debian 8.3.0-6) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
