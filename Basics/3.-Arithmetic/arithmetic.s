	.file	"arithmetic.c"
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
	.ascii "El resultado de la operaci\303\263n es: %d\12\0"
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
	movl	$2, 44(%esp)
	movl	$3, 40(%esp)
	movl	$LC0, (%esp)
	call	_puts
	leal	32(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_scanf
	movl	$LC2, (%esp)
	call	_puts
	leal	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_scanf
	movl	32(%esp), %edx
	movl	28(%esp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	44(%esp), %eax
	cltd
	idivl	40(%esp)
	movl	%eax, %ecx
	movl	32(%esp), %edx
	movl	28(%esp), %eax
	addl	%edx, %eax
	imull	%ecx, %eax
	movl	%eax, 36(%esp)
	movl	36(%esp), %eax
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
