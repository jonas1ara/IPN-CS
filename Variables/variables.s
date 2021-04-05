	.file	"variables.c"
	.text
	.section	.rodata
	.align 8
.LC2:
	.string	"This is a variable of type character: %c\n"
	.align 8
.LC3:
	.string	"This is an integer type variable: %i\n"
	.align 8
.LC4:
	.string	"This is a short type variable: %i\n"
	.align 8
.LC5:
	.string	"This is a variable of type unsigned: %i\n"
	.align 8
.LC6:
	.string	"This is a long type variable: %li\n"
	.align 8
.LC7:
	.string	"This is a float type variable: %f\n"
	.align 8
.LC8:
	.string	"This is a double type variabe: %.2lf\n"
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
	subq	$48, %rsp
	movb	$89, -1(%rbp)
	movl	$20, -8(%rbp)
	movw	$-1, -10(%rbp)
	movl	$25, -16(%rbp)
	movq	$5932, -24(%rbp)
	movss	.LC0(%rip), %xmm0
	movss	%xmm0, -28(%rbp)
	movsd	.LC1(%rip), %xmm0
	movsd	%xmm0, -40(%rbp)
	movsbl	-1(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	-8(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movswl	-10(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movl	-16(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	pxor	%xmm1, %xmm1
	cvtss2sd	-28(%rbp), %xmm1
	movq	%xmm1, %rax
	movq	%rax, %xmm0
	movl	$.LC7, %edi
	movl	$1, %eax
	call	printf
	movq	-40(%rbp), %rax
	movq	%rax, %xmm0
	movl	$.LC8, %edi
	movl	$1, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC0:
	.long	1116803957
	.align 8
.LC1:
	.long	1592917471
	.long	1086853545
	.ident	"GCC: (GNU) 11.0.1 20210324 (Red Hat 11.0.1-0)"
	.section	.note.GNU-stack,"",@progbits
