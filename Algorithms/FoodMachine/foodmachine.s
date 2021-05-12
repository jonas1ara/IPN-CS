	.file	"foodmachine.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"Este programa te muestra 3 productos con sus respectivos precios y las monedas que puedes usar para pagar."
.LC1:
	.string	"\nProductos disponibles: "
.LC2:
	.string	"\nA = $27\t\t|\t\t"
.LC3:
	.string	"B = $34 \t|\t\t"
.LC4:
	.string	"C = $39 "
	.align 8
.LC5:
	.string	"\nLas \303\272nicas monedas que acepto son: $10, $5 y $1"
	.align 8
.LC6:
	.string	"\nPor favor, elige una opci\303\263n entre los productos A, B y C: "
.LC7:
	.string	"%c"
.LC8:
	.string	"\nIngrese el dinero: "
.LC9:
	.string	"%d"
.LC10:
	.string	"Ingrese el dinero: "
	.align 8
.LC11:
	.string	"Lo siento no acepto esa moneda, por favor introduce una moneda de $10, $5 o $1"
	.align 8
.LC12:
	.string	"\nEl dinero ingresado son: $%d\n"
.LC13:
	.string	"El cambio total son: $%d\n"
	.align 8
.LC14:
	.string	"\nTome su cambio: %d moneda(s) de $5, %d moneda(s) de $2 y 1 moneda(s) de $1\n"
	.align 8
.LC15:
	.string	"\nTome su cambio: %d moneda(s) de $5, %d moneda(s) de $2 y 0 moneda(s) de $1\n"
.LC16:
	.string	"Pago aceptado"
	.align 8
.LC17:
	.string	"Por favor entiende que las \303\272nicas monedas que acepto son $10, $5 y $1"
	.align 8
.LC18:
	.string	"Por favor, introduce un CAR\303\201CTER entre los productos A, B y C"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -32(%rbp)
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
	leaq	.LC5(%rip), %rdi
	call	puts@PLT
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-41(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movzbl	-41(%rbp), %eax
	movsbl	%al, %eax
	subl	$65, %eax
	cmpl	$34, %eax
	ja	.L2
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L4(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L4(%rip), %rdx
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L4:
	.long	.L6-.L4
	.long	.L5-.L4
	.long	.L3-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L6-.L4
	.long	.L5-.L4
	.long	.L3-.L4
	.text
.L6:
	movl	$27, -28(%rbp)
	leaq	.LC8(%rip), %rdi
	call	puts@PLT
	leaq	-40(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC9(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-40(%rbp), %eax
	cmpl	$1, %eax
	je	.L7
	movl	-40(%rbp), %eax
	cmpl	$5, %eax
	je	.L7
	movl	-40(%rbp), %eax
	cmpl	$10, %eax
	jne	.L8
.L7:
	movl	-40(%rbp), %eax
	movl	%eax, -36(%rbp)
	jmp	.L9
.L12:
	leaq	.LC10(%rip), %rdi
	call	puts@PLT
	leaq	-40(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC9(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-40(%rbp), %eax
	cmpl	$1, %eax
	je	.L10
	movl	-40(%rbp), %eax
	cmpl	$5, %eax
	je	.L10
	movl	-40(%rbp), %eax
	cmpl	$10, %eax
	jne	.L11
.L10:
	movl	-40(%rbp), %eax
	addl	%eax, -36(%rbp)
	jmp	.L9
.L11:
	leaq	.LC11(%rip), %rdi
	call	puts@PLT
.L9:
	cmpl	$26, -36(%rbp)
	jle	.L12
	movl	-36(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC12(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	cmpl	$27, -36(%rbp)
	jle	.L13
	movl	-36(%rbp), %eax
	subl	$27, %eax
	movl	%eax, -24(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC13(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-24(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1717986919, %rdx, %rdx
	shrq	$32, %rdx
	sarl	%edx
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -20(%rbp)
	movl	-24(%rbp), %edx
	movslq	%edx, %rax
	imulq	$1717986919, %rax, %rax
	shrq	$32, %rax
	movl	%eax, %ecx
	sarl	%ecx
	movl	%edx, %eax
	sarl	$31, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -16(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -12(%rbp)
	cmpl	$1, -12(%rbp)
	je	.L14
	cmpl	$1, -16(%rbp)
	jne	.L15
.L14:
	movl	-12(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC14(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L18
.L15:
	movl	-12(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC15(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L18
.L13:
	leaq	.LC16(%rip), %rdi
	call	puts@PLT
	jmp	.L18
.L8:
	leaq	.LC17(%rip), %rdi
	call	puts@PLT
	jmp	.L19
.L18:
	jmp	.L19
.L5:
	movl	$34, -28(%rbp)
	leaq	.LC8(%rip), %rdi
	call	puts@PLT
	leaq	-40(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC9(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-40(%rbp), %eax
	cmpl	$1, %eax
	je	.L20
	movl	-40(%rbp), %eax
	cmpl	$5, %eax
	je	.L20
	movl	-40(%rbp), %eax
	cmpl	$10, %eax
	jne	.L21
.L20:
	movl	-40(%rbp), %eax
	movl	%eax, -36(%rbp)
	jmp	.L22
.L25:
	leaq	.LC10(%rip), %rdi
	call	puts@PLT
	leaq	-40(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC9(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-40(%rbp), %eax
	cmpl	$1, %eax
	je	.L23
	movl	-40(%rbp), %eax
	cmpl	$5, %eax
	je	.L23
	movl	-40(%rbp), %eax
	cmpl	$10, %eax
	jne	.L24
.L23:
	movl	-40(%rbp), %eax
	addl	%eax, -36(%rbp)
	jmp	.L22
.L24:
	leaq	.LC11(%rip), %rdi
	call	puts@PLT
.L22:
	cmpl	$33, -36(%rbp)
	jle	.L25
	movl	-36(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC12(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	cmpl	$34, -36(%rbp)
	jle	.L26
	movl	-36(%rbp), %eax
	subl	$34, %eax
	movl	%eax, -24(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC13(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-24(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1717986919, %rdx, %rdx
	shrq	$32, %rdx
	sarl	%edx
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -20(%rbp)
	movl	-24(%rbp), %edx
	movslq	%edx, %rax
	imulq	$1717986919, %rax, %rax
	shrq	$32, %rax
	movl	%eax, %ecx
	sarl	%ecx
	movl	%edx, %eax
	sarl	$31, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -16(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -12(%rbp)
	cmpl	$1, -12(%rbp)
	je	.L27
	cmpl	$1, -16(%rbp)
	jne	.L28
.L27:
	movl	-12(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC14(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L31
.L28:
	movl	-12(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC15(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L31
.L26:
	leaq	.LC16(%rip), %rdi
	call	puts@PLT
	jmp	.L31
.L21:
	leaq	.LC17(%rip), %rdi
	call	puts@PLT
	jmp	.L19
.L31:
	jmp	.L19
.L3:
	movl	$39, -28(%rbp)
	leaq	.LC8(%rip), %rdi
	call	puts@PLT
	leaq	-40(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC9(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-40(%rbp), %eax
	cmpl	$1, %eax
	je	.L32
	movl	-40(%rbp), %eax
	cmpl	$5, %eax
	je	.L32
	movl	-40(%rbp), %eax
	cmpl	$10, %eax
	jne	.L33
.L32:
	movl	-40(%rbp), %eax
	movl	%eax, -36(%rbp)
	jmp	.L34
.L37:
	leaq	.LC10(%rip), %rdi
	call	puts@PLT
	leaq	-40(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC9(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-40(%rbp), %eax
	cmpl	$1, %eax
	je	.L35
	movl	-40(%rbp), %eax
	cmpl	$5, %eax
	je	.L35
	movl	-40(%rbp), %eax
	cmpl	$10, %eax
	jne	.L36
.L35:
	movl	-40(%rbp), %eax
	addl	%eax, -36(%rbp)
	jmp	.L34
.L36:
	leaq	.LC11(%rip), %rdi
	call	puts@PLT
.L34:
	cmpl	$38, -36(%rbp)
	jle	.L37
	movl	-36(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC12(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	cmpl	$39, -36(%rbp)
	jle	.L38
	movl	-36(%rbp), %eax
	subl	$39, %eax
	movl	%eax, -24(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC13(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-24(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1717986919, %rdx, %rdx
	shrq	$32, %rdx
	sarl	%edx
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -20(%rbp)
	movl	-24(%rbp), %edx
	movslq	%edx, %rax
	imulq	$1717986919, %rax, %rax
	shrq	$32, %rax
	movl	%eax, %ecx
	sarl	%ecx
	movl	%edx, %eax
	sarl	$31, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -16(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -12(%rbp)
	cmpl	$1, -12(%rbp)
	je	.L39
	cmpl	$1, -16(%rbp)
	jne	.L40
.L39:
	movl	-12(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC14(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L43
.L40:
	movl	-12(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC15(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L43
.L38:
	leaq	.LC16(%rip), %rdi
	call	puts@PLT
	jmp	.L43
.L33:
	leaq	.LC17(%rip), %rdi
	call	puts@PLT
	jmp	.L19
.L43:
	jmp	.L19
.L2:
	leaq	.LC18(%rip), %rdi
	call	puts@PLT
	nop
.L19:
	movl	$0, %eax
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L45
	call	__stack_chk_fail@PLT
.L45:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
