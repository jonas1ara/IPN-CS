	.file	"unidi.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii "Ingrese el tama\303\261o del arreglo: \0"
LC1:
	.ascii "%i\0"
LC2:
	.ascii "Ingresa el valor %i:\12\0"
LC3:
	.ascii "Los valores del arreglo son: \0"
LC4:
	.ascii "%i-\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB10:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x78,0x6
	.cfi_escape 0x10,0x3,0x2,0x75,0x7c
	subl	$48, %esp
	call	___main
	movl	%esp, %eax
	movl	%eax, %ebx
	movl	$LC0, (%esp)
	call	_puts
	leal	-28(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_scanf
	movl	-28(%ebp), %eax
	leal	-1(%eax), %edx
	movl	%edx, -20(%ebp)
	sall	$2, %eax
	leal	3(%eax), %edx
	movl	$16, %eax
	subl	$1, %eax
	addl	%edx, %eax
	movl	$16, %ecx
	movl	$0, %edx
	divl	%ecx
	imull	$16, %eax, %eax
	call	___chkstk_ms
	subl	%eax, %esp
	leal	8(%esp), %eax
	addl	$3, %eax
	shrl	$2, %eax
	sall	$2, %eax
	movl	%eax, -24(%ebp)
	movl	$0, -12(%ebp)
	jmp	L2
L3:
	movl	-12(%ebp), %eax
	addl	$1, %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-24(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_scanf
	addl	$1, -12(%ebp)
L2:
	movl	-28(%ebp), %eax
	cmpl	%eax, -12(%ebp)
	jl	L3
	movl	$LC3, (%esp)
	call	_puts
	movl	$0, -16(%ebp)
	jmp	L4
L5:
	movl	-24(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	(%eax,%edx,4), %eax
	movl	%eax, 4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	addl	$1, -16(%ebp)
L4:
	movl	-28(%ebp), %eax
	cmpl	%eax, -16(%ebp)
	jl	L5
	movl	$10, (%esp)
	call	_putchar
	movl	$0, %eax
	movl	%ebx, %esp
	leal	-8(%ebp), %esp
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
