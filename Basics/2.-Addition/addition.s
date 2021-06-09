	.file	"addition.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "Ingresa un n\303\272mero entero:\0"
LC1:
	.ascii "%d\0"
LC2:
	.ascii "Ingresa otro n\303\272mero entero:\0"
	.align 4
LC3:
	.ascii "El resultado de la suma es: %d\12\0"
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
	subl	$32, %esp
	call	___main
	movl	$LC0, (%esp)
	call	_puts
	leal	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_scanf
	movl	$LC2, (%esp)
	call	_puts
	leal	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_scanf
	movl	24(%esp), %edx
	movl	20(%esp), %eax
	addl	%edx, %eax
	movl	%eax, 28(%esp)
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
