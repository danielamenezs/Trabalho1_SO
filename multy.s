#código em assembly gerado pelo comando "gcc -S seu_arquivo.c -o seu_arquivo.s" no terminal do Linux
	.file	"multy.c"
	.text
	.globl	imprime_numero
	.type	imprime_numero, @function
imprime_numero:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	cmpl	$9, -20(%rbp)
	jle	.L2
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	imulq	$1717986919, %rdx, %rdx
	shrq	$32, %rdx
	movl	%edx, %ecx
	sarl	$2, %ecx
	cltd
	movl	%ecx, %eax
	subl	%edx, %eax
	movl	%eax, %edi
	call	imprime_numero
.L2:
	movl	-20(%rbp), %edx
	movslq	%edx, %rax
	imulq	$1717986919, %rax, %rax
	shrq	$32, %rax
	movl	%eax, %ecx
	sarl	$2, %ecx
	movl	%edx, %eax
	sarl	$31, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	sall	$2, %eax
	addl	%ecx, %eax
	addl	%eax, %eax
	subl	%eax, %edx
	movl	%edx, %ecx
	movl	%ecx, %eax
	addl	$48, %eax
	movb	%al, -9(%rbp)
	leaq	-9(%rbp), %rax
	movl	$1, %edx
	movq	%rax, %rsi
	movl	$1, %edi
	call	write@PLT
	nop
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	imprime_numero, .-imprime_numero
	.section	.rodata
.LC0:
	.string	"Primeiro numero: "
.LC1:
	.string	"Segundo numero: "
.LC2:
	.string	"\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
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
	movl	$0, -48(%rbp)
	movl	$0, -44(%rbp)
	movl	$17, %edx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	call	write@PLT
	leaq	-28(%rbp), %rax
	movl	$10, %edx
	movq	%rax, %rsi
	movl	$0, %edi
	call	read@PLT
	movl	$16, %edx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	call	write@PLT
	leaq	-18(%rbp), %rax
	movl	$10, %edx
	movq	%rax, %rsi
	movl	$0, %edi
	call	read@PLT
	movl	$0, -40(%rbp)
	jmp	.L5
.L7:
	movl	-48(%rbp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, %edx
	movl	-40(%rbp), %eax
	cltq
	movzbl	-28(%rbp,%rax), %eax
	movsbl	%al, %eax
	subl	$48, %eax
	addl	%edx, %eax
	movl	%eax, -48(%rbp)
	addl	$1, -40(%rbp)
.L5:
	movl	-40(%rbp), %eax
	cltq
	movzbl	-28(%rbp,%rax), %eax
	cmpb	$10, %al
	je	.L6
	cmpl	$2, -40(%rbp)
	jle	.L7
.L6:
	movl	$0, -36(%rbp)
	jmp	.L8
.L10:
	movl	-44(%rbp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, %edx
	movl	-36(%rbp), %eax
	cltq
	movzbl	-18(%rbp,%rax), %eax
	movsbl	%al, %eax
	subl	$48, %eax
	addl	%edx, %eax
	movl	%eax, -44(%rbp)
	addl	$1, -36(%rbp)
.L8:
	movl	-36(%rbp), %eax
	cltq
	movzbl	-18(%rbp,%rax), %eax
	cmpb	$10, %al
	je	.L9
	cmpl	$2, -36(%rbp)
	jle	.L10
.L9:
	movl	-48(%rbp), %eax
	imull	-44(%rbp), %eax
	movl	%eax, -32(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, %edi
	call	imprime_numero
	movl	$1, %edx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rsi
	movl	$1, %edi
	call	write@PLT
	movl	$0, %edi
	call	_exit@PLT
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
