	.file	"convert.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC1:
	.ascii "Esta es la suma: %.3f\12\0"
	.align 4
LC2:
	.ascii "\12Y estos son el entero convertido: \12Integer: %i\12Floating: %.2f\12Double: %.3f\12Character: %c\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$48, %esp
	call	___main
	movl	$80, 44(%esp)
	flds	LC0
	fstps	40(%esp)
	fildl	44(%esp)
	fadds	40(%esp)
	fstps	36(%esp)
	flds	36(%esp)
	fstpl	4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	44(%esp), %eax
	movsbl	%al, %eax
	fildl	44(%esp)
	fildl	44(%esp)
	fxch	%st(1)
	movl	%eax, 24(%esp)
	fstpl	16(%esp)
	fstpl	8(%esp)
	movl	44(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.section .rdata,"dr"
	.align 4
LC0:
	.long	1110782771
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
