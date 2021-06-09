	.file	"for.c"
	.text
	.section	.rodata
.LC0:
	.string	"%i\n"
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
	movl	$1, -4(%rbp)
	jmp	.L2
.L3:
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -4(%rbp)
.L2:
	cmpl	$10, -4(%rbp)
	jle	.L3
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 11.0.1 20210324 (Red Hat 11.0.1-0)"
	.section	.note.GNU-stack,"",@progbits
