	.file	"structures.c"
	.text
	.globl	dog1
	.data
	.align 32
	.type	dog1, @object
	.size	dog1, 40
dog1:
	.string	"Pikachu"
	.zero	22
	.zero	2
	.long	10
	.long	1080033280
	.globl	dog2
	.align 32
	.type	dog2, @object
	.size	dog2, 40
dog2:
	.string	"Arduino"
	.zero	22
	.zero	2
	.long	4
	.long	1075000115
	.section	.rodata
	.align 8
.LC0:
	.string	"The weight of %s is: %.2f Kg and it\302\264s %i months old\n "
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
	movl	32+dog2(%rip), %eax
	movss	36+dog2(%rip), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movl	%eax, %edx
	leaq	dog2(%rip), %rsi
	leaq	.LC0(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Debian 8.3.0-6) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
