	.file	"main.c"
	.text
	.globl	global_var
	.data
	.align 4
	.type	global_var, @object
	.size	global_var, 4
global_var:
	.long	42
	.section	.rodata
	.align 16
	.type	msg, @object
	.size	msg, 18
msg:
	.string	"Hello from rodata"
	.text
	.globl	sum
	.type	sum, @function
sum:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	addl	%edx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	sum, .-sum
	.section	.rodata
.LC0:
	.string	"%s: %d\n"
.LC1:
	.string	"sum=%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	global_var(%rip), %edx
	leaq	-48(%rbp), %rax
	movl	%edx, %r8d
	movl	$msg, %ecx
	movl	$.LC0, %edx
	movl	$32, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	puts
	movl	$20, %esi
	movl	$10, %edi
	call	sum
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 15.2.1 20250808 (Red Hat 15.2.1-1)"
	.section	.note.GNU-stack,"",@progbits
